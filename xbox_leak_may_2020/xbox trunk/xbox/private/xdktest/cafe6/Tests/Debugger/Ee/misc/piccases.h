///////////////////////////////////////////////////////////////////////////////
//  PICCASES.H
//
//  Created by :            Date :
//      MichMa                  1/25/94
//
//  Description :
//      Declaration of the CPreIncCases class
//

#ifndef __PICCASES_H__
#define __PICCASES_H__

#ifndef __STDAFX_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "..\..\core\dbgset.h"
#include "miscsub.h"

///////////////////////////////////////////////////////////////////////////////
//  CPreIncCases class

class CPreIncCases : public CDebugTestSet

    {
	DECLARE_TEST(CPreIncCases, CMiscSubSuite)

	// Operations
	public:
		virtual void PreRun(void);
		virtual void Run(void);
    };

#endif //__PICCASES_H__
