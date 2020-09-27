/**********************************************************************
 *<
	FILE: matte.cpp

	DESCRIPTION:  A Matte material

	CREATED BY: Dan Silva

	HISTORY:  1/13/98 Updated to Param2 by Peter Watje

 *>	Copyright (c) 1994, All Rights Reserved.
 **********************************************************************/

#include "mtlhdr.h"
#include "mtlres.h"
#include "notify.h"
#include "iparamm2.h"

extern HINSTANCE hInstance;

static Class_ID matteClassID(MATTE_CLASS_ID,0);

class Matte;
/*
class MatteDlg : public ParamDlg {
	public:		
		HWND hwmedit;
		IMtlParams *ip;
		Matte *theMtl;
		HWND hPanel; 
		BOOL valid;
		BOOL isActive;
		ISpinnerControl *iAmb;		
		ISpinnerControl *iReflAmt;		
		IColorSwatch *cs;		
		BOOL creating;
		TexDADMgr dadMgr;
		ICustButton *iReflBut;

		MatteDlg(HWND hwMtlEdit, IMtlParams *imp, Matte *m); 
		~MatteDlg();
		
		void EnableAlpha(HWND hWnd);
		BOOL WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);				
		void Invalidate();		
		void UpdateSubTexNames();
		void SetDepthRadios();
		void UpdateMtlDisplay() { ip->MtlChanged();  	}
		
		// methods inherited from ParamDlg:		
		void ReloadDialog();
		Class_ID ClassID() {return matteClassID;}
		BOOL KeyAtCurTime(int id); 
		void SetThing(ReferenceTarget *m);
		ReferenceTarget* GetThing() { return (ReferenceTarget *)theMtl; }
		void DeleteThis() { delete this;  }	
		void SetTime(TimeValue t) {Invalidate();}
		void ActivateDlg(BOOL onOff) { cs->Activate(onOff); }
		int FindSubTexFromHWND(HWND hw) {
			return  (hw == iReflBut->GetHwnd())? 0: -1;
			}
	};
*/

#define PB_REF		0
#define REFLMAP_REF		1

//#define PB_AMB	0
//#define PB_COL	1
//#define PB_REFLAMT	2


enum { matte_params, };  // pblock ID
// grad_params param IDs
enum 
{ 
	matte_opaque_alpha,
	matte_apply_atmosphere, matte_atmosphere_depth,
	matte_receive_shadows, matte_affect_alpha,
	matte_shadow_brightness, matte_color,
	matte_reflection_amount, matte_reflection_map,
	matte_use_reflection_map
};



static Color black(0,0,0);
static Color white(1,1,1);

class Matte : public Mtl {	
	public:
//		MatteDlg *dlg;
		IParamBlock2 *pblock; 	// ref #0
		Texmap *reflmap; 	// ref #1
		IParamBlock *savepb;   // for saving pblock when saving Max R2 files
		Interval ivalid;
		float amblev,reflAmt;
		Color col;
		BOOL fogBG;
		BOOL useReflMap;
		BOOL shadowBG;
		BOOL opaque;
		BOOL shadowAlpha;
		BOOL fogObjDepth;
		int version;

		Matte(BOOL loading);
			void NotifyChanged() {NotifyDependents(FOREVER, PART_ALL, REFMSG_CHANGE);}
		~Matte();
		void SetAmbLev(float v, TimeValue t);
		void SetReflAmt(float v, TimeValue t);
		void SetShadColor(Color c, TimeValue t){  col= c;	pblock->SetValue(matte_color, t, c); }
					
	
		// From MtlBase and Mtl
		void SetAmbient(Color c, TimeValue t) {}		
		void SetDiffuse(Color c, TimeValue t) {}		
		void SetSpecular(Color c, TimeValue t) {}
		void SetShininess(float v, TimeValue t) {}				
		
		Color GetAmbient(int mtlNum=0, BOOL backFace=FALSE) { return black; }
	    Color GetDiffuse(int mtlNum=0, BOOL backFace=FALSE) { return white; }
		Color GetSpecular(int mtlNum=0, BOOL backFace=FALSE) { return black; }
		float GetXParency(int mtlNum=0, BOOL backFace=FALSE){ return 0.0f; }
		float GetShininess(int mtlNum=0, BOOL backFace=FALSE){ return 0.0f; }		
		float GetShinStr(int mtlNum=0, BOOL backFace=FALSE){ return 1.0f; }
				
		void EnableStuff();
		ParamDlg* CreateParamDlg(HWND hwMtlEdit, IMtlParams *imp);
		
		void Shade(ShadeContext& sc);
		void Update(TimeValue t, Interval& valid);
		void Init();
		void Reset();
		Interval Validity(TimeValue t);
		
		Class_ID ClassID() {return matteClassID; }
		SClass_ID SuperClassID() {return MATERIAL_CLASS_ID;}
		void GetClassName(TSTR& s) {s=GetString(IDS_DS_MATTE_SHADOW);}  

		void DeleteThis() {delete this;}	

		ULONG LocalRequirements(int subMtlNum) {  
			return fogBG ?(fogObjDepth?0:MTLREQ_NOATMOS):MTLREQ_NOATMOS; 
			}


		// Methods to access texture maps of material
		int NumSubTexmaps() { return 1; }
		Texmap* GetSubTexmap(int i) { return reflmap; }
		void SetSubTexmap(int i, Texmap *m) {
			ReplaceReference(REFLMAP_REF,m);
//			if (dlg) dlg->UpdateSubTexNames();
			}
		TSTR GetSubTexmapSlotName(int i) {
			return TSTR(GetString(IDS_DS_MAP)); 
			}
		int NumSubs() {return 2;} 
		Animatable* SubAnim(int i);
		TSTR SubAnimName(int i);
		int SubNumToRefNum(int subNum) {return subNum;}

		// From ref
 		int NumRefs() {return GetSavingVersion()==2000?1:2;}
		RefTargetHandle GetReference(int i);
		void SetReference(int i, RefTargetHandle rtarg);

		IOResult Save(ISave *isave); 
		IOResult Load(ILoad *iload);
		 
		RefTargetHandle Clone(RemapDir &remap = NoRemap());
		RefResult NotifyRefChanged(Interval changeInt, RefTargetHandle hTarget, 
		   PartID& partID, RefMessage message);

// JBW: direct ParamBlock access is added
		int	NumParamBlocks() { return 1; }					// return number of ParamBlocks in this instance
		IParamBlock2* GetParamBlock(int i) { return pblock; } // return i'th ParamBlock
		IParamBlock2* GetParamBlockByID(BlockID id) { return (pblock->ID() == id) ? pblock : NULL; } // return id'd ParamBlock

	};

class MatteClassDesc:public ClassDesc2 {
	public:
	int 			IsPublic() {return 1;}
	void *			Create(BOOL loading) {return new Matte(loading);}
	const TCHAR *	ClassName() {return GetString(IDS_DS_MATTE_SHADOW_CDESC); } // mjm - 2.3.99
	SClass_ID		SuperClassID() {return MATERIAL_CLASS_ID;}
	Class_ID 		ClassID() {return matteClassID;}
	const TCHAR* 	Category() {return _T("");}
// JBW: new descriptor data accessors added.  Note that the 
//      internal name is hardwired since it must not be localized.
	const TCHAR*	InternalName() { return _T("Matte"); }	// returns fixed parsable name (scripter-visible name)
	HINSTANCE		HInstance() { return hInstance; }			// returns owning module handle
	};
static MatteClassDesc matteCD;
ClassDesc* GetMatteDesc() {return &matteCD;}


//--- MatteDlg ------------------------------------------------------
/*
static BOOL CALLBACK PanelDlgProc(
		HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
	MatteDlg *dlg;
	if (msg==WM_INITDIALOG) {
		dlg = (MatteDlg*)lParam;
		SetWindowLong(hWnd,GWL_USERDATA,lParam);
		}
	else {
	    if ( (dlg = (MatteDlg *)GetWindowLong(hWnd, GWL_USERDATA) ) == NULL )
			return FALSE; 
		}
	dlg->isActive = TRUE;
	int	res = dlg->WndProc(hWnd,msg,wParam,lParam);
	dlg->isActive = FALSE;
	return res;
	}


MatteDlg::MatteDlg(HWND hwMtlEdit, IMtlParams *imp, Matte *m)
	{
	dadMgr.Init(this);
	hwmedit = hwMtlEdit;
	ip      = imp;
	theMtl  = m;
	valid   = FALSE;
	iAmb  = NULL;
	iReflAmt  = NULL;
	creating = TRUE;
	iReflBut = NULL;
	hPanel = ip->AddRollupPage( 
		hInstance,
		MAKEINTRESOURCE(IDD_MATTE),
		PanelDlgProc,
		GetString(IDS_DS_MATTE_SHADOW_PAR),
		(LPARAM)this);
	creating = FALSE;
	}

MatteDlg::~MatteDlg()
	{
	theMtl->dlg = NULL;	
	ReleaseISpinner(iAmb);
	ReleaseISpinner(iReflAmt);
	ReleaseIColorSwatch(cs);
	ReleaseICustButton(iReflBut);
	iReflBut = NULL;
	SetWindowLong(hPanel, GWL_USERDATA, NULL);
	}

void MatteDlg::EnableAlpha(HWND hWnd) {
	EnableWindow(GetDlgItem(hWnd,IDC_MATTE_SHADALPHA), !theMtl->opaque);
	}

BOOL MatteDlg::WndProc(
		HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
	switch (msg) {
		case WM_INITDIALOG:
			iAmb= SetupFloatSpinner(hWnd, IDC_MATTE_AMB_SPIN, IDC_MATTE_AMB_EDIT, 0.0f,1.0f, 0.5f,.01f);
			SetCheckBox(hWnd,IDC_MATTE_FOGBG, theMtl->fogBG);
			SetCheckBox(hWnd,IDC_MATTE_SHADOW, theMtl->shadowBG);
			SetCheckBox(hWnd,IDC_MATTE_OPAQUE, theMtl->opaque);
			SetCheckBox(hWnd,IDC_MATTE_SHADALPHA, theMtl->shadowAlpha);
			SetDepthRadios();
			EnableAlpha(hWnd);
			iReflBut = GetICustButton(GetDlgItem(hWnd,IDC_MATTE_REFL_MAP));
			iReflBut->SetDADMgr(&dadMgr);
			iReflAmt= SetupFloatSpinner(hWnd, IDC_MATTE_REFLAMT_SPIN, IDC_MATTE_REFLAMT_EDIT, 0.0f, 9999.0f, 1.0f,.01f);
			cs = GetIColorSwatch(GetDlgItem(hWnd, IDC_SHAD_COLOR),
   					theMtl->col, GetString(IDS_DS_SHAD_COLOR));
			iReflAmt->Enable(theMtl->reflmap?1:0);
			break;			

		case WM_PAINT:
			if (!valid) {
				valid = TRUE;
				ReloadDialog();
				}
			return FALSE;

		case WM_COMMAND:
			if (creating) break;
			switch (LOWORD(wParam)) {
				case IDC_MATTE_FOGBG:
					theMtl->fogBG = GetCheckBox(hWnd,IDC_MATTE_FOGBG);
					break;
				case IDC_MATTE_SHADOW:
					theMtl->shadowBG = GetCheckBox(hWnd,IDC_MATTE_SHADOW);
					break;
				case IDC_MATTE_SHADALPHA:
					theMtl->shadowAlpha = GetCheckBox(hWnd,IDC_MATTE_SHADALPHA);
					break;
				case IDC_MATTE_OPAQUE:
					theMtl->opaque = GetCheckBox(hWnd,IDC_MATTE_OPAQUE);
					EnableAlpha(hWnd);
					break;
				case IDC_MATTE_FOG_BGDEPTH:
					theMtl->fogObjDepth = 0;
					SetDepthRadios();
					break;
				case IDC_MATTE_FOG_OBJDEPTH:
					theMtl->fogObjDepth = 1;
					SetDepthRadios();
					break;
				case IDC_MATTE_REFL_MAP: 	
					PostMessage(hwmedit,WM_TEXMAP_BUTTON, 0 ,(LPARAM)theMtl);	
					break;
				}
			break;
		

		case CC_COLOR_BUTTONDOWN:
			theHold.Begin();
			break;
		case CC_COLOR_BUTTONUP:
			if (HIWORD(wParam)) theHold.Accept(GetString(IDS_DS_PARAMCHG));
			else theHold.Cancel();
			break;

		case CC_COLOR_CHANGE: {
			int id = LOWORD(wParam);
			int buttonUp = HIWORD(wParam); 
			if (buttonUp) theHold.Begin();
			theMtl->SetShadColor(cs->GetColor(),ip->GetTime());
			cs->SetKeyBrackets(KeyAtCurTime(PB_COL));
			if (buttonUp) {
				theHold.Accept(GetString(IDS_DS_PARAMCHG));
				UpdateMtlDisplay();
				theMtl->NotifyChanged();
				}
			break;
			}


		case CC_SPINNER_CHANGE: 
			if (!theHold.Holding()) theHold.Begin();
			switch (LOWORD(wParam)) {
				case IDC_MATTE_AMB_SPIN: {
					ISpinnerControl *spin = (ISpinnerControl*)lParam;
					theMtl->SetAmbLev(spin->GetFVal(),ip->GetTime());
					spin->SetKeyBrackets(KeyAtCurTime(PB_AMB));
 					break; 
					}
				case IDC_MATTE_REFLAMT_SPIN: {
					ISpinnerControl *spin = (ISpinnerControl*)lParam;
					theMtl->SetReflAmt(spin->GetFVal(),ip->GetTime());
					spin->SetKeyBrackets(KeyAtCurTime(PB_REFLAMT));
 					break; 
					}
				}
			break; // DS 4/11/96
		case CC_SPINNER_BUTTONDOWN:
			theHold.Begin();
			break;
		case WM_CUSTEDIT_ENTER:
		case CC_SPINNER_BUTTONUP: 
			if (HIWORD(wParam) || msg==WM_CUSTEDIT_ENTER) theHold.Accept(GetString(IDS_DS_PARAMCHG));
			else theHold.Cancel();			
			break;

		default:
			return FALSE;
		}
	return TRUE;
	}

void MatteDlg::Invalidate()
	{
	valid = FALSE;
	isActive = FALSE;
	Rect rect;	
	rect.left = rect.top = 0;
	rect.right = rect.bottom = 10;
	InvalidateRect(hPanel,&rect,FALSE);	
	}

void MatteDlg::UpdateSubTexNames() {
	TSTR nm;
	if (theMtl->reflmap)  nm = theMtl->reflmap->GetFullName();
	else nm = GetString(IDS_DS_NONE);
	iReflBut->SetText(nm.data());
	}

void MatteDlg::SetDepthRadios() {
	int id = theMtl->fogObjDepth?IDC_MATTE_FOG_OBJDEPTH:IDC_MATTE_FOG_BGDEPTH; 
	CheckRadioButton(hPanel,IDC_MATTE_FOG_BGDEPTH,IDC_MATTE_FOG_OBJDEPTH,id); 
	}
			
void MatteDlg::SetThing(ReferenceTarget *m) {
	theMtl = (Matte*)m;
	if (theMtl) theMtl->dlg = this;
	ReloadDialog();   //DS 11/9/96
	}

BOOL MatteDlg::KeyAtCurTime(int id) { 
	return theMtl->pblock->KeyFrameAtTime(id,ip->GetTime()); 
	}

void MatteDlg::ReloadDialog()
	{
	Interval valid;
	theMtl->Update(ip->GetTime(), valid);
	iAmb->SetValue(theMtl->amblev,FALSE);
	iReflAmt->SetValue(theMtl->reflAmt,FALSE);
	cs->SetColor(theMtl->col);
	SetCheckBox(hPanel,IDC_MATTE_FOGBG, theMtl->fogBG);
	SetCheckBox(hPanel,IDC_MATTE_SHADOW, theMtl->shadowBG);
	SetCheckBox(hPanel,IDC_MATTE_SHADALPHA, theMtl->shadowAlpha);
	SetCheckBox(hPanel,IDC_MATTE_OPAQUE, theMtl->opaque);
	cs->SetKeyBrackets(KeyAtCurTime(PB_COL));
	iAmb->SetKeyBrackets(KeyAtCurTime(PB_AMB));
	iReflAmt->SetKeyBrackets(KeyAtCurTime(PB_REFLAMT));
	iReflAmt->Enable(theMtl->reflmap?1:0);

	SetDepthRadios();
	UpdateSubTexNames();
	}
*/


// shader rollout dialog proc
class MatteDlgProc : public ParamMap2UserDlgProc 
	{
	public:
		BOOL DlgProc(TimeValue t, IParamMap2 *map, HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) { return FALSE; }
		void SetThing(ReferenceTarget *m) {	
			Matte *mtl = (Matte *)m;
			if (mtl) mtl->EnableStuff();
			}
		void DeleteThis() { }
	};

static MatteDlgProc matteDlgProc;

class MattePBAccessor : public PBAccessor
{
public:
	void Set(PB2Value& v, ReferenceMaker* owner, ParamID id, int tabIndex, TimeValue t)    // set from v
	{
		Matte* p = (Matte*)owner;
		if (p!=NULL) {
			IParamMap2 *map = p->pblock->GetMap();
			if (map) {
				switch (id)	{
					case matte_opaque_alpha:
						map->Enable(matte_affect_alpha, v.i? FALSE: TRUE);
						break;
					case matte_reflection_map:
				   		map->Enable(matte_reflection_amount, v.r?TRUE: FALSE);
						break;
					}
				}
			}

	}
};

static MattePBAccessor matte_accessor;



static ParamBlockDesc2 matte_param_blk ( matte_params, _T("parameters"),  0, &matteCD, P_AUTO_CONSTRUCT + P_AUTO_UI, PB_REF, 
	//rollout
	IDD_MATTE, IDS_DS_MATTE_SHADOW_PAR, 0, 0, &matteDlgProc, 
	// params
	matte_opaque_alpha,	_T("opaqueAlpha"), TYPE_BOOL,			0,				IDS_PW_OALPHA,
		p_default,		TRUE,
		p_ui,			TYPE_SINGLECHEKBOX, IDC_MATTE_OPAQUE,
		p_accessor,		&matte_accessor,
		end,

	matte_apply_atmosphere,	_T("applyAtmosphere"), TYPE_BOOL,			0,				IDS_PW_APPLYATMOS,
		p_default,		FALSE,
		p_ui,			TYPE_SINGLECHEKBOX, IDC_MATTE_FOGBG,
		end,
	matte_atmosphere_depth, _T("atmosphereDepth"), TYPE_INT,				0,				IDS_PW_ATMOSDEPTH,
		p_default,		0,
		p_range,		0,	1,
		p_ui,			TYPE_RADIO, 2, IDC_MATTE_FOG_BGDEPTH, IDC_MATTE_FOG_OBJDEPTH,
		end,
	matte_receive_shadows,	_T("receiveShadows"), TYPE_BOOL,			0,				IDS_PW_RECEIVESHADOWS,
		p_default,		FALSE,
		p_ui,			TYPE_SINGLECHEKBOX, IDC_MATTE_SHADOW,
		end,
	matte_affect_alpha,	_T("affectAlpha"), TYPE_BOOL,			0,				IDS_PW_AFFECTALPHA,
		p_default,		FALSE,
		p_ui,			TYPE_SINGLECHEKBOX, IDC_MATTE_SHADALPHA,
		p_enabled,		FALSE,
		end,
	matte_shadow_brightness,	_T("shadowBrightness"), TYPE_FLOAT,			P_ANIMATABLE,	IDS_DS_SHADOW_BRITE,
		p_default,		0.0,
		p_range,		0.0, 1.0,
		p_ui, 			TYPE_SPINNER, EDITTYPE_FLOAT, IDC_MATTE_AMB_EDIT, IDC_MATTE_AMB_SPIN, 0.1, 
		end, 
	matte_color, _T("color"),	TYPE_RGBA,				P_ANIMATABLE,	IDS_DS_SHAD_COLOR,	
		p_default,		Color(0,0,0), 
		p_ui,			TYPE_COLORSWATCH, IDC_SHAD_COLOR, 
		end,
	matte_reflection_amount,	_T("amount"), TYPE_PCNT_FRAC,	P_ANIMATABLE,	IDS_DS_REFLAMT,
		p_default,		0.5,
		p_range,		0.0, 100.0,
		p_ui, 			TYPE_SPINNER, EDITTYPE_FLOAT, IDC_MATTE_REFLAMT_EDIT, IDC_MATTE_REFLAMT_SPIN, 0.1, 

		end,  
	matte_reflection_map, _T("map"),		TYPE_TEXMAP,			P_OWNERS_REF,	IDS_DS_MAP,
		p_refno,		REFLMAP_REF,
		p_subtexno,		0,		
		p_ui,			TYPE_TEXMAPBUTTON, IDC_MATTE_REFL_MAP,
		p_accessor,		&matte_accessor,

		end,
	matte_use_reflection_map,	_T("useReflMap"), TYPE_BOOL, 		0,	 IDS_DS_USEREFL,
		p_default,		TRUE,
		p_ui,			TYPE_SINGLECHEKBOX, IDC_MATTE_USEREFL,
		end,

	end
	);

//--- Matte Material -------------------------------------------------


static ParamBlockDescID pbdesc0[] = {
	{TYPE_FLOAT, NULL, TRUE,matte_shadow_brightness }};   // ambient light level


static ParamBlockDescID pbdesc1[] = {
	{TYPE_FLOAT, NULL, TRUE,matte_shadow_brightness },
	{TYPE_RGBA, NULL, TRUE ,matte_color }
	};   

static ParamBlockDescID pbdesc[] = {
	{TYPE_FLOAT, NULL, TRUE,matte_shadow_brightness },
	{TYPE_RGBA,  NULL, TRUE,matte_color },
	{TYPE_FLOAT, NULL, TRUE,matte_reflection_amount }
	};   

#define MATTE_VERSION 3
#define NUM_OLDVERSIONS	3
#define NPARAMS 3

// Array of old versions
static ParamVersionDesc versions[NUM_OLDVERSIONS] = {
	ParamVersionDesc(pbdesc0,1,0),	
	ParamVersionDesc(pbdesc1,2,1),
	ParamVersionDesc(pbdesc,3,2)	
	};


//static ParamVersionDesc curVersion(pbdesc,NPARAMS,MATTE_VERSION);

// Code for saving Max R2 files -------------------
/*
static void NotifyPreSaveOld(void *param, NotifyInfo *info) {
	Matte *mt = (Matte *)param;
	if (GetSavingVersion()==2000) {
		mt->savepb = mt->pblock;
		mt->pblock = UpdateParameterBlock(pbdesc,3,mt->savepb,pbdesc1,2,1);
		}
	}

static void NotifyPostSaveOld(void *param, NotifyInfo *info) {
	Matte *mt = (Matte *)param;
	if (mt->savepb) {
		mt->pblock->DeleteThis();
		mt->pblock = mt->savepb;
		mt->savepb = NULL;
		}
	}
	*/
//----------------------------------------------------------------

Matte::Matte(BOOL loading)
	{	
//	dlg = NULL;
	pblock = NULL;
	savepb = NULL;  // for saving pblock when saving Max R2 files
	reflmap = NULL;
	ivalid.SetEmpty();
	fogBG = FALSE;    // DS 11/9/96
	shadowBG = FALSE;
	shadowAlpha = FALSE;
	opaque = FALSE;
	fogObjDepth = FALSE;
	
//	RegisterNotification(NotifyPreSaveOld, (void *)this, NOTIFY_FILE_PRE_SAVE_OLD);
//	RegisterNotification(NotifyPostSaveOld, (void *)this, NOTIFY_FILE_POST_SAVE_OLD);

	matteCD.MakeAutoParamBlocks(this);	// make and intialize paramblock2
	Init();
	}

Matte::~Matte() {
//  UnRegisterNotification(NotifyPreSaveOld, (void *)this, NOTIFY_FILE_PRE_SAVE_OLD);
//	InRegisterNotification(NotifyPostSaveOld, (void *)this, NOTIFY_FILE_POST_SAVE_OLD);
	}

void Matte::Init()
	{
	SetAmbLev(0.0f,0);
	SetShadColor(Color(0.0f,0.0f,0.0f), TimeValue(0));
	fogBG = FALSE;
	shadowBG = FALSE;
	shadowAlpha = FALSE;
	opaque = TRUE;
	fogObjDepth = FALSE;
	}
		
void Matte::Reset()
	{
	matteCD.Reset(this, TRUE);	// reset all pb2's
	Init();
	}
		
void Matte::SetAmbLev(float v, TimeValue t) {
    amblev= v;
	pblock->SetValue( matte_shadow_brightness, t, v);
	}

void Matte::SetReflAmt(float v, TimeValue t) {
    reflAmt= v;
	pblock->SetValue( matte_reflection_amount, t, v);
	}


void Matte::EnableStuff() {
	if (pblock) {
		IParamMap2 *map = pblock->GetMap();
		if (map) {
			map->Enable(matte_reflection_amount, reflmap?TRUE:FALSE);
			map->Enable(matte_affect_alpha, opaque?FALSE:TRUE);
			}
		}
	}

ParamDlg* Matte::CreateParamDlg(HWND hwMtlEdit, IMtlParams *imp)
	{
	// create the rollout dialogs
	IAutoMParamDlg* masterDlg = matteCD.CreateParamDlgs(hwMtlEdit, imp, this);

	EnableStuff();

	return masterDlg;

//	dlg = new MatteDlg(hwMtlEdit, imp, this);
//	return dlg;     
	}


Color DiffuseIllum(ShadeContext &sc) { 
	Point3 N = sc.Normal();
	Point3 P = sc.P();
	Color diffwk(0,0,0);
	Color lightCol;
	for (int i = 0; i<sc.nLights; i++) {
		LightDesc* l = sc.Light(i);
		register float dot_nl,diffCoef;
		Point3 L;
		if (!l->Illuminate(sc, N, lightCol, L, dot_nl,diffCoef))
			continue;
		if (dot_nl>0.0f)	  
			diffwk += diffCoef*lightCol;
		}
	return diffwk;
	}


static Color blackCol(0.0f,0.0f,0.0f);

#define CLAMP(x) (((x)>1.0f)?1.0f:((x)<0.0f)?0.0f:(x))

static inline void Clamp(Color &c) {
	c.r = CLAMP(c.r);
	c.g = CLAMP(c.g);
	c.b = CLAMP(c.b);
	}

void Matte::Shade(ShadeContext& sc)
	{
	Color c,t;
	float atten;
	if (gbufID) sc.SetGBufferID(gbufID);
	
	if (!opaque) sc.Execute(0x1000); // DS: 6/24/99:use black bg when AA filtering (#192348)
	sc.GetBGColor(c,t,fogBG&&(!fogObjDepth));
	if (!opaque) sc.Execute(0x1001); // DS: 6/24/99:use black bg when AA filtering (#192348)


	if (shadowBG&&sc.shadow) {
		sc.shadow = 0;
		Color col0 = DiffuseIllum(sc);
		sc.shadow = 1;
		Color scol = DiffuseIllum(sc);
		float f = Intens(col0);
		atten = (f>0.0f)?Intens(scol)/f:1.0f;
		if (atten>1.0f) atten = 1.0f/atten;
		atten = amblev+(1.0f-amblev)*atten;
		sc.out.c = c*atten + (1.0f-atten)*col;
		if (shadowAlpha)
			t *= atten;
		}
	else 
		sc.out.c  = c;
	sc.out.t = opaque? black: t ; 
	if (reflmap&&useReflMap) {
		AColor rcol;
		if (reflmap->HandleOwnViewPerturb()) {
			sc.TossCache(reflmap);
			rcol = reflmap->EvalColor(sc);
			}
		else 
			rcol = sc.EvalEnvironMap(reflmap, sc.ReflectVector());
		Color rc;
		rc = Color(rcol.r,rcol.g,rcol.b)*reflAmt;
		sc.out.c += rc;
		}
	Clamp(sc.out.t);
	}

void Matte::Update(TimeValue t, Interval& valid)
	{	
	ivalid = FOREVER;
	pblock->GetValue(matte_shadow_brightness,t,amblev,ivalid);
	pblock->GetValue(matte_color,t,col,ivalid);
	pblock->GetValue(matte_reflection_amount,t,reflAmt,ivalid);


	pblock->GetValue(matte_opaque_alpha,t,opaque,ivalid);
	pblock->GetValue(matte_apply_atmosphere,t,fogBG,ivalid);
	pblock->GetValue(matte_receive_shadows,t,shadowBG,ivalid);
	pblock->GetValue(matte_affect_alpha,t,shadowAlpha,ivalid);
	pblock->GetValue(matte_atmosphere_depth,t,fogObjDepth,ivalid);
	pblock->GetValue( matte_use_reflection_map,t, useReflMap, ivalid);
	if (reflmap&&useReflMap)
		reflmap->Update(t,ivalid);
	EnableStuff();

	valid &= ivalid;
	}

Interval Matte::Validity(TimeValue t)
	{
	Interval valid = FOREVER;	
	Update(t,valid);
	return valid;
	}

Animatable* Matte::SubAnim(int i)
	{
	switch (i) {
		case 0: return pblock;
		case 1: return reflmap;
		default: return NULL;
		}
	}

TSTR Matte::SubAnimName(int i)
	{
	switch (i) {
		case 0: return GetString(IDS_DS_PARAMETERS);
		case 1: return GetString(IDS_DS_MAP);
		default: return _T("");
		}
	}

RefTargetHandle Matte::GetReference(int i)
	{
	switch (i) {
		case 0: return pblock;
		case 1: return reflmap;
		default: return NULL;
		}
	}

void Matte::SetReference(int i, RefTargetHandle rtarg)
	{
	switch (i) {
		case 0: pblock = (IParamBlock2*)rtarg; break;
		case 1: reflmap = (Texmap*)rtarg; 
//			matte_param_blk.InvalidateUI();

			break;
		}
	}

RefTargetHandle Matte::Clone(RemapDir &remap)
	{
	Matte *mtl = new Matte(FALSE);
	*((MtlBase*)mtl) = *((MtlBase*)this);  // copy superclass stuff
	mtl->ReplaceReference(PB_REF,remap.CloneRef(pblock));
	mtl->fogBG = fogBG;
	mtl->shadowBG = shadowBG;
	mtl->shadowAlpha = shadowAlpha;
	mtl->opaque = opaque;
	mtl->fogObjDepth = fogObjDepth;
	mtl->useReflMap = useReflMap;
	if (reflmap)
		mtl->ReplaceReference(REFLMAP_REF,remap.CloneRef(reflmap));
	return mtl;
	}

RefResult Matte::NotifyRefChanged(
		Interval changeInt, 
		RefTargetHandle hTarget, 
		PartID& partID, 
		RefMessage message)
	{
	switch (message) {
		case REFMSG_CHANGE:
			if (hTarget = pblock)
				{
				ivalid.SetEmpty();
			// see if this message came from a changing parameter in the pblock,
			// if so, limit rollout update to the changing item and update any active viewport texture
				ParamID changing_param = pblock->LastNotifyParamID();
				matte_param_blk.InvalidateUI(changing_param);
			// notify our dependents that we've changed
				// NotifyChanged();  //DS this is redundant
				}

//			if (hTarget==pblock) ivalid.SetEmpty();
//			if (dlg && dlg->theMtl==this&& !dlg->isActive) dlg->Invalidate();
//			if (dlg && dlg->iReflAmt)
//				dlg->iReflAmt->Enable(reflmap?1:0);
			break;
		
/*
		case REFMSG_GET_PARAM_DIM: {
			GetParamDim *gpd = (GetParamDim*)partID;
			switch (gpd->index) {
				case PB_AMB: 
				case PB_REFLAMT: gpd->dim = defaultDim; break;
				case PB_COL: gpd->dim = stdColor255Dim; break;
				}
			return REF_STOP; 
			}

		case REFMSG_GET_PARAM_NAME: {
			GetParamName *gpn = (GetParamName*)partID;
			switch (gpn->index) {
				case PB_AMB: gpn->name = TSTR(GetString(IDS_DS_SHADOW_BRITE)); break;
				case PB_REFLAMT: gpn->name = TSTR(GetString(IDS_DS_REFLAMT)); break;
				case PB_COL: gpn->name= GetString(IDS_DS_SHAD_COLOR); break;
					 break;
				}
			return REF_STOP; 
			}
*/
		}
	return REF_SUCCEED;
	}


#define MTL_HDR_CHUNK 0x4000
#define FOGBG_CHUNK 0x0001
#define SHADOWBG_CHUNK 0x0002
#define MATTE_VERSION_CHUNK 0003
#define OPAQUE_CHUNK 0x0004
#define FOG_OBJDEPTH_CHUNK 0x0005
#define SHADALPHA_CHUNK 0x0010

IOResult Matte::Save(ISave *isave) { 
	ULONG nb;
	isave->BeginChunk(MTL_HDR_CHUNK);
	IOResult res = MtlBase::Save(isave);
	if (res!=IO_OK) return res;
	isave->EndChunk();
/*
	if (fogBG) {
		isave->BeginChunk(FOGBG_CHUNK);
		isave->EndChunk();
		}
	if (shadowBG) {
		isave->BeginChunk(SHADOWBG_CHUNK);
		isave->EndChunk();
		}
	if (shadowAlpha) {
		isave->BeginChunk(SHADALPHA_CHUNK);
		isave->EndChunk();
		}
	if (opaque) {
		isave->BeginChunk(OPAQUE_CHUNK);
		isave->EndChunk();
		}
	if (fogObjDepth) {
		isave->BeginChunk(FOG_OBJDEPTH_CHUNK);
		isave->EndChunk();
		}
*/
	int vers = 2;

	isave->BeginChunk(MATTE_VERSION_CHUNK);
	isave->Write(&vers, sizeof(vers), &nb);
	isave->EndChunk();

	return IO_OK;
	}

//watje
class MattePostLoadCallback:public  PostLoadCallback
{
public:
	Matte      *s;
	MattePostLoadCallback(Matte *r) {s=r;}
	void proc(ILoad *iload);
};


void MattePostLoadCallback::proc(ILoad *iload)
{

	s->pblock->SetValue(matte_opaque_alpha,0,s->opaque);
	s->pblock->SetValue(matte_apply_atmosphere,0,s->fogBG);
	s->pblock->SetValue(matte_receive_shadows,0,s->shadowBG);
	s->pblock->SetValue(matte_affect_alpha,0,s->shadowAlpha);
	s->pblock->SetValue(matte_atmosphere_depth,0,s->fogObjDepth);

	delete this;

}
 


IOResult Matte::Load(ILoad *iload) { 
	ULONG nb;
	int id;
	version = 0;
	IOResult res;
	
	opaque = FALSE;

	while (IO_OK==(res=iload->OpenChunk())) {
		switch(id = iload->CurChunkID())  {
			case MTL_HDR_CHUNK:
				res = MtlBase::Load(iload);
				ivalid.SetEmpty();
				break;
			case FOGBG_CHUNK:
				fogBG = TRUE;
				break;
			case SHADOWBG_CHUNK:
				shadowBG = TRUE;
				break;
			case SHADALPHA_CHUNK:
				shadowAlpha = TRUE;
				break;
			case OPAQUE_CHUNK:
				opaque = TRUE;
				break;
			case FOG_OBJDEPTH_CHUNK:
				fogObjDepth = TRUE;
				break;
			case MATTE_VERSION_CHUNK:
				iload->Read(&version,sizeof(int), &nb);
				break;
			}
		iload->CloseChunk();
		if (res!=IO_OK) 
			return res;
		}

	if (version  < 2)
		{

	// JBW: register old version ParamBlock to ParamBlock2 converter
		ParamBlock2PLCB* plcb = new ParamBlock2PLCB(versions, NUM_OLDVERSIONS, &matte_param_blk, this, PB_REF);
		iload->RegisterPostLoadCallback(plcb);

		MattePostLoadCallback* matteplcb = new MattePostLoadCallback(this);
		iload->RegisterPostLoadCallback(matteplcb);
		}


//	iload->RegisterPostLoadCallback(
//		new ParamBlockPLCB(versions,NUM_OLDVERSIONS,&curVersion,this,PB_REF));
	return IO_OK;
                                                      
	}

//-----------------------------------------------------------------------------
