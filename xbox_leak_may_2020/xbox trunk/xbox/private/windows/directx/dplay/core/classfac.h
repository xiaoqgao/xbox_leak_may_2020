/*==========================================================================
 *
 *  Copyright (C) 2000 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       ClassFac.h
 *  Content:    DirectNet class factory header file
 *@@BEGIN_MSINTERNAL
 *  History:
 *   Date       By      Reason
 *   ====       ==      ======
 *	10/08/99	jtk		Created
 *	05/04/00	mjn		Cleaned up functions
 *  06/09/00    rmt     Updates to split CLSID and allow whistler compat and support external create funcs 
 *@@END_MSINTERNAL
 *
 ***************************************************************************/

#ifndef	__CLASSFAC_H__
#define	__CLASSFAC_H__

//**********************************************************************
// Constant definitions
//**********************************************************************

//**********************************************************************
// Macro definitions
//**********************************************************************

//**********************************************************************
// Structure definitions
//**********************************************************************

//
// COM interface for class factory
//
#undef INTERFACE				// External COM Implementation
#define INTERFACE IDirectNetClassFact
DECLARE_INTERFACE_(IDirectNetClassFact,IUnknown)
{
	STDMETHOD(QueryInterface)	(THIS_ REFIID riid, LPVOID *ppvObj) PURE;
	STDMETHOD_(ULONG,AddRef)	(THIS) PURE;
	STDMETHOD_(ULONG,Release)	(THIS) PURE;
	STDMETHOD(CreateInstance)	(THIS_ LPUNKNOWN lpUnkOuter, REFIID riid, LPVOID *ppvObj) PURE;
	STDMETHOD(LockServer)		(THIS_ BOOL bLock) PURE;
};


typedef struct _IDirectNetClassFact {	// Internal Implementation (overlay's external imp.)
	IDirectNetClassFactVtbl	*lpVtbl;		// lpVtbl Must be first element (to match external imp.)
	DWORD					dwRefCount;
	DWORD					dwLocks;
	GUID                    clsid;
} _IDirectNetClassFact, *_LPIDirectNetClassFact;

//**********************************************************************
// Variable definitions
//**********************************************************************

//**********************************************************************
// Function prototypes
//**********************************************************************

//
//	DirectNet - IUnknown
//
STDMETHODIMP DN_QueryInterface(void *pInterface,
							   REFIID riid,
							   void **ppv);

STDMETHODIMP_(ULONG) DN_AddRef(void *pInterface);

STDMETHODIMP_(ULONG) DN_Release(void *pInterface);

static	HRESULT DN_CreateInterface(OBJECT_DATA *pObject,
								   REFIID riid,
								   INTERFACE_LIST **const ppv);

INTERFACE_LIST *DN_FindInterface(void *pInterface,
								 REFIID riid);


#endif	// __CLASSFAC_H__
