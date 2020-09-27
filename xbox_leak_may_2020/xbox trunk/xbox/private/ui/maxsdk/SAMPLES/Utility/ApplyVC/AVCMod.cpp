/**********************************************************************
 *<
	FILE:			AVCMod.cpp
	DESCRIPTION:	Vertex Color Modifier
	CREATED BY:		Christer Janson
	HISTORY:		Created Monday, June 02, 1997

	This modifier is the keeper of vertex colors generated by the
	"Apply Vertex Colors" Utility plug-in.

 *>	Copyright (c) 1997 Kinetix, All Rights Reserved.
 **********************************************************************/

#include "ApplyVC.h"

//--- ClassDescriptor and class vars ---------------------------------

IObjParam*			ApplyVCMod::ip =	NULL;

class AVCClassDesc:public ClassDesc {
	public:
	int 			IsPublic() { return 0; }
	void *			Create(BOOL loading = FALSE) { return new ApplyVCMod(!loading);}
	const TCHAR *	ClassName() { return GetString(IDS_AVCM_CNAME); }
	SClass_ID		SuperClassID() { return OSM_CLASS_ID; }
	Class_ID		ClassID() { return APPLYVC_MOD_CLASS_ID; }
	const TCHAR* 	Category() { return _T("");}
};

static AVCClassDesc vcmodDesc;
extern ClassDesc* GetApplyVCModDesc() {return &vcmodDesc;}


//--- ApplyVCMod methods -------------------------------


ApplyVCMod::ApplyVCMod(BOOL create)
{	
	iValid.SetEmpty();
}

void ApplyVCMod::DeleteThis()
{
	delete this;
}

void ApplyVCMod::GetClassName(TSTR& s)
{
	s= GetString(IDS_AVCM_CNAME);
}

Class_ID ApplyVCMod::ClassID()
{
	return APPLYVC_MOD_CLASS_ID;
}

TCHAR* ApplyVCMod::GetObjectName()
{
	return GetString(IDS_AVCM_ONAME);
}

CreateMouseCallBack* ApplyVCMod::GetCreateMouseCallBack()
{
	return NULL;
}

// Prevent us from being copied in TrackView/ModifierStack.
BOOL ApplyVCMod::CanCopyAnim()
{
	return FALSE;
}

ChannelMask ApplyVCMod::ChannelsUsed()
{
	return VERTCOLOR_CHANNEL | TOPO_CHANNEL;
}

ChannelMask ApplyVCMod::ChannelsChanged()
{
	return VERTCOLOR_CHANNEL | TOPO_CHANNEL;
}

BOOL ApplyVCMod::DependOnTopology(ModContext &mc)
{
	return TRUE;
}

Class_ID ApplyVCMod::InputType()
{
	return triObjectClassID;
}

int ApplyVCMod::NumRefs()
{
	return 0;
}

int ApplyVCMod::NumSubs()
{
	return 0;
}

#define MIX_COLOR_CHUNK		0x110
#define VX_COLOR_CHUNK		0x120

IOResult ApplyVCMod::Load(ILoad *iload)
{
	IOResult res;
	ULONG nb;

	ResetColTab();

	Modifier::Load(iload);	
	while (IO_OK==(res=iload->OpenChunk())) {
		switch(iload->CurChunkID())  {
			case MIX_COLOR_CHUNK: {
				Color* col = new Color();
				res=iload->Read(col,sizeof(Color),&nb);
				mixedVertexColors.Append(1, &col, 25);
				break;
			}

			case VX_COLOR_CHUNK: {
				FaceColor* faceCol = new FaceColor;
				for (int j=0; j<3; j++) {
					iload->Read(&faceCol->colors[j],sizeof(Color),&nb);
				}
				faceColors.Append(1, &faceCol, 25);
				break;
			}
			default:
				break; 
		}
		iload->CloseChunk();
		if (res!=IO_OK) 
			return res;
	}
	return IO_OK;
}

IOResult ApplyVCMod::Save(ISave *isave)
{
	IOResult res;
	ULONG nb;
	int i, j;

	Modifier::Save(isave);

	for (i=0; i<mixedVertexColors.Count(); i++) {
		isave->BeginChunk(MIX_COLOR_CHUNK);
		res = isave->Write(mixedVertexColors[i], sizeof(Color), &nb);
		isave->EndChunk();
	}

	for (i=0; i<faceColors.Count(); i++) {
		isave->BeginChunk(VX_COLOR_CHUNK);
		for (j=0; j<3; j++) {
			res = isave->Write(faceColors[i]->colors[j], sizeof(Color), &nb);
		}
		isave->EndChunk();
	}

	return IO_OK;
}

static BOOL CALLBACK panelDlgProc(
		HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_MOUSEMOVE:
			GetCOREInterface()->RollupMouseMessage(hWnd,msg,wParam,lParam); 
			break;
		default:
			return FALSE;
	}
	return TRUE;
}	

void ApplyVCMod::BeginEditParams(IObjParam *ip, ULONG flags,Animatable *prev)
{
	this->ip = ip;

	TimeValue t = ip->GetTime();
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_BEGIN_EDIT);
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_MOD_DISPLAY_ON);
	SetAFlag(A_MOD_BEING_EDITED);

	hPanel = ip->AddRollupPage(
		hInstance,
		MAKEINTRESOURCE(IDD_VCMOD_PANEL),
		panelDlgProc,
		GetString(IDS_AVCM_PANELTITLE),
		0);

	iValid.SetEmpty();
}
		
void ApplyVCMod::EndEditParams( IObjParam *ip, ULONG flags,Animatable *next )
{	
	this->ip = NULL;

	TimeValue t = ip->GetTime();
	ip->DeleteRollupPage(hPanel);
	hPanel = NULL;
	ClearAFlag(A_MOD_BEING_EDITED);
 	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_END_EDIT);
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_MOD_DISPLAY_OFF);
}

Interval ApplyVCMod::LocalValidity(TimeValue t)
{	
	return iValid;
}

RefTargetHandle ApplyVCMod::Clone(RemapDir& remap) 
{
	ApplyVCMod* newmod = new ApplyVCMod(FALSE);	

	for (int i=0; i<mixedVertexColors.Count(); i++) {
		Color* c = new Color(*mixedVertexColors[i]);
		newmod->mixedVertexColors.Append(1, &c, 25);
	}
	return newmod;
}


void ApplyVCMod::ModifyObject(TimeValue t, ModContext &mc, ObjectState *os, INode *node)
{
	static int calls = 0;
	iValid = FOREVER;
	Interval valid = LocalValidity(t);

	assert(os->obj->IsSubClassOf(triObjectClassID));
	TriObject *obj = (TriObject*)os->obj;
	Mesh &mesh = obj->GetMesh();	

	if (mixedVertexColors.Count() > 0) {
		mesh.setNumVertCol(mesh.numVerts);
		mesh.setNumVCFaces(mesh.numFaces);

		for (int i=0; i<mesh.numVerts; i++) {
			mesh.vertCol[i] = i<mixedVertexColors.Count() ?
				Point3(mixedVertexColors[i]->r, mixedVertexColors[i]->g, mixedVertexColors[i]->b) :
				Point3(1.0f, 1.0f, 1.0f);
			}

		for (i=0; i<mesh.numFaces; i++) {
			mesh.vcFace[i].t[0] = mesh.faces[i].v[0];
			mesh.vcFace[i].t[1] = mesh.faces[i].v[1];
			mesh.vcFace[i].t[2] = mesh.faces[i].v[2];
			}
		}
	else if (faceColors.Count() > 0) {
		int numVCVerts = mesh.numFaces*3;
		mesh.setNumVCFaces(mesh.numFaces);
		mesh.setNumVertCol(numVCVerts);

		int faceVert = 0;
		for (int i=0; i<mesh.numFaces; i++) {
			for (int j=0; j<3; j++) {
				mesh.vertCol[faceVert] = i<faceColors.Count() ? 
					Point3(faceColors[i]->colors[j].r, faceColors[i]->colors[j].g, faceColors[i]->colors[j].b) :
					Point3(1.0f, 1.0f, 1.0f);
				faceVert++;
				}
			}

		faceVert = 0;
		for (i=0; i<mesh.numFaces; i++) {
			mesh.vcFace[i].t[0] = faceVert++;
			mesh.vcFace[i].t[1] = faceVert++;
			mesh.vcFace[i].t[2] = faceVert++;
			}
		}

	NotifyDependents(Interval(t,t), PART_VERTCOLOR, REFMSG_CHANGE);
	NotifyDependents(Interval(t,t), PART_TOPO, REFMSG_CHANGE);
	obj->UpdateValidity(VERT_COLOR_CHAN_NUM, valid);
}


RefTargetHandle ApplyVCMod::GetReference(int i)
{
	return NULL;
}

void ApplyVCMod::SetReference(int i, RefTargetHandle rtarg)
{
}

Animatable* ApplyVCMod::SubAnim(int i)
{
	return NULL;
}

TSTR ApplyVCMod::SubAnimName(int i)
{
	return TSTR(_T(""));
}

RefResult ApplyVCMod::NotifyRefChanged(
		Interval changeInt, 
		RefTargetHandle hTarget, 
   		PartID& partID, 
   		RefMessage message) 
{
	return REF_SUCCEED;
}

void ApplyVCMod::ResetColTab()
{
	int i;
	// Reset table of mixed colors
	for (i=0; i<mixedVertexColors.Count(); i++) {
		delete mixedVertexColors[i];
	}
	mixedVertexColors.ZeroCount();
	mixedVertexColors.Shrink();

	// Reset table of vertex colors
	for (i=0; i<faceColors.Count(); i++) {
		delete faceColors[i];
	}
	faceColors.ZeroCount();
	faceColors.Shrink();

	iValid.SetEmpty();
}

// Public access function.
// Please note that multiple vertex colors are not implemetned yet.
// Please use SetMixedColors() for now.
void ApplyVCMod::SetColors(FaceColorTab& colorTab)
	{
	ResetColTab();

	for (int i=0; i<colorTab.Count(); i++) {
		FaceColor* faceCol = new FaceColor;

		for (int j=0; j<3; j++) {
			faceCol->colors[j] = colorTab[i]->colors[j];
		}
		faceColors.Append(1, &faceCol, 25);
	}

	NotifyDependents(FOREVER, PART_VERTCOLOR, REFMSG_CHANGE);
	}


// Public access function.
void ApplyVCMod::SetMixedColors(ColorTab& colorTab)
{
	ResetColTab();

	for (int i=0; i<colorTab.Count(); i++) {
		Color* col = new Color(*colorTab[i]);
		mixedVertexColors.Append(1, &col, 25);
	}

	NotifyDependents(FOREVER, PART_VERTCOLOR, REFMSG_CHANGE);
}
