// owdlist.cpp : Ownerdraw listbox 

#include "stdafx.h"

#ifndef _CUSTOMLISTBOX_
#define _CUSTOMLISTBOX_

class OwnerDrawLB : public CListBox
{
public:
// Implementation
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMIS);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCIS);
};

#endif // _CUSTOMLISTBOX_
