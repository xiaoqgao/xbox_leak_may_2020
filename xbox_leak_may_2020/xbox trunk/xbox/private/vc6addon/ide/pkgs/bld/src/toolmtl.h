//
// mktyplib.h
//
// Definition of CMkTypLibTool class
//

#ifndef _MKTYPLIB_H_
#define _MKTYPLIB_H_

#include "projtool.h"	// where base classes are defined
#include "optnmtl.h"	// our MkTypLib tool 

///////////////////////////////////////////////////////////////////////////////
//
// CBuildTool ----> CMkTypLibTool
//
////////////////////////////////////////////////////////////////////////////////
class CMkTypLibTool : public CBuildTool
{
	DECLARE_DYNAMIC (CMkTypLibTool)

public:
	CMkTypLibTool();

	// -> from CBuildTool
	virtual UINT PerformBuildActions(UINT type, UINT stage, CActionSlobList & lstActions,
						     		 DWORD attrib, CErrorContext & EC);

 	// Scans .odl files for includes.
	virtual BOOL GenerateDependencies(CActionSlob * pAction, FileRegHandle frhFile, CErrorContext & EC);
	virtual BOOL DontWriteDependencies( ConfigurationRecord* pcr) { return TRUE; }

	// Return the files generated by the compiler tool
	virtual BOOL GenerateOutput(UINT type, CActionSlobList & actions, CErrorContext & EC);

	// Affects our output?
	virtual BOOL AffectsOutput(UINT idProp);

 	// generate command lines for MkTypLib, doing all the good ordering things
	virtual BOOL GetCommandLines(CActionSlobList &, CPtrList &, DWORD, CErrorContext &);

	// <- from CBuildTool

	virtual BOOL IsScannable() {return TRUE;}	// is it scannable ? 

	virtual void GetIncludePaths(CProjItem *pItem, CString& str);

	// MkTypLib is a prepass tool
	virtual BOOL IsPrePassTool() {return TRUE;}

protected:
	virtual void WriteInferenceRuleMacro(CActionSlob * pAction);
};

#endif // _MKTYPLIB_H_
