/*==========================================================================
 *
 *  Copyright (C) 2000 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       addcore.h
 *  Content:    DIRECTPLAY8ADDRESS CORE HEADER FILE
 *@@BEGIN_MSINTERNAL
 *  History:
 *   Date       By      Reason
 *   ====       ==      ======
 *  02/04/2000	rmt		Created
 *  02/17/2000	rmt		Added new defines for 
 *  02/17/2000	rmt		Parameter validation work 
 *  02/21/2000	rmt		Updated to make core Unicode and remove ANSI calls 
 *  07/09/2000	rmt		Added signature bytes to start of address objects
 *  07/13/2000	rmt		Bug #39274 - INT 3 during voice run
 *  07/21/2000	rmt		Bug #39940 - Addressing library doesn't properly parse stopbits in URLs
 *   7/31/2000  RichGr  IA64: FPM_Release() overwrites first 8 bytes of chunk of memory on IA64.
 *                      Rearrange positions of members of affected structs so that's OK.  
 *@@END_MSINTERNAL
 *
 ***************************************************************************/

#ifndef	__ADDCORE_H
#define	__ADDCORE_H

void GlobalInitialize(void);
HRESULT GlobalCleanup(void);

extern DWORD g_dwGlobalObjectCount;
extern BOOL g_fGlobalObjectInit;

// Length of a single byte of userdata 
#define DNURL_LENGTH_USERDATA_BYTE	1

// Header length (14 chars + null terminator)
#define DNURL_LENGTH_HEADER			15

// Includes escaped brackets
#define DNURL_LENGTH_GUID			42

// Just the number, in decimal
#define DNURL_LENGTH_DWORD			10

// The length of the seperator for user data
#define DNURL_LENGTH_USERDATA_SEPERATOR	1

// The right length for one byte of escaped data
#define DNURL_LENGTH_BINARY_BYTE	3


#define DP8A_ENTERLEVEL			2
#define DP8A_INFOLEVEL			7
#define DP8A_ERRORLEVEL			0
#define DP8A_WARNINGLEVEL		1
#define DP8A_PARAMLEVEL			3

extern const WCHAR *szBaseStrings[];
extern const DWORD dwBaseRequiredTypes[];
extern const DWORD c_dwNumBaseStrings;

#if defined(DEBUG) || defined(DBG)

extern BOOL IsValidDP8AObject( LPVOID lpvObject );

#define DP8A_VALID(a) 	IsValidDP8AObject( a )
#else
#define DP8A_VALID(a)  TRUE
#endif




#define DP8A_RETURN( x ) 	DPF( DP8A_ENTERLEVEL, "Function returning hr=0x%x", x ); \
							return x;

extern LPFPOOL fpmAddressElements;
extern CRITICAL_SECTION g_csFPMElements;

extern CStringCache *g_pcstrKeyCache;

#define DP8ADDRESS_ELEMENT_HEAP	0x00000001

#define DPASIGNATURE_ELEMENT		'LEAD'
#define DPASIGNATURE_ELEMENT_FREE	'LEA_'

#define DPASIGNATURE_ADDRESS		'BOAD'
#define DPASIGNATURE_ADDRESS_FREE	'BOA_'

// DP8ADDRESSELEMENT
//
// This structure contains all the information about a single element of the 
// address.  These address elements are allocated from a central, fixed
//
//  7/31/2000(RichGr) - IA64: FPM_Release() overwrites first 8 bytes.  Rearrange position of dwSignature so that's OK.  
typedef struct _DP8ADDRESSELEMENT
{
	DWORD dwTagSize;			// Size of the tag
	DWORD dwType;				// Element type DNADDRESS8_DATATYPE_XXXXXX
	DWORD dwDataSize;			// Size of the data
	DWORD dwStringSize;
	DWORD dwSignature;          // Element debug signature
	WCHAR *pszTag;	            // Tag for the element.  
	DWORD dwFlags;				// Flags DNADDRESSELEMENT_XXXX
	union {
		GUID guidData;
		DWORD dwData;
		WCHAR szData[sizeof(GUID)];
		PVOID pvData;
	} uData;					// Union 
	CBilink blAddressElements;	// Bilink of address elements
} DP8ADDRESSELEMENT, *PDP8ADDRESSELEMENT;

// DP8ADDRESSELEMENT
// 
// Data structure representing the address itself
class DP8ADDRESSOBJECT
    : public IDirectPlay8Address
{
	STDNEWDELETE

protected:
	ULONG	m_ulRefCount;	// object reference count

public:
	DP8ADDRESSOBJECT(void);
	~DP8ADDRESSOBJECT(void);

	// IUnknown interface
	ULONG STDMETHODCALLTYPE AddRef(void);
	ULONG STDMETHODCALLTYPE Release(void);

	HRESULT DP8A_BuildFromURLW( IDirectPlay8Address *pInterface, WCHAR * pwszAddress );
	HRESULT DP8A_BuildFromURLA( IDirectPlay8Address *pInterface, CHAR * pszAddress );
	HRESULT DP8A_Duplicate( IDirectPlay8Address *pInterface, PDIRECTPLAY8ADDRESS *ppInterface );
	HRESULT DP8A_Clear( IDirectPlay8Address *pInterface );
	HRESULT DP8A_GetURLW( IDirectPlay8Address *pInterface, WCHAR * pwszAddress, PDWORD pdwAddressSize );
	HRESULT DP8A_GetURLA( IDirectPlay8Address *pInterface, CHAR * pszAddress, PDWORD pdwAddressSize );
	HRESULT DP8A_GetSP( IDirectPlay8Address *pInterface, GUID * pguidSP );
	HRESULT DP8A_GetDevice( IDirectPlay8Address *pInterface, GUID * pguidSP );
	HRESULT DP8A_GetUserData( IDirectPlay8Address *pInterface, void * pvUserData, PDWORD pdwBufferSize );
	HRESULT DP8A_SetDevice( IDirectPlay8Address *pInterface, const GUID * const pguidSP );
	HRESULT DP8A_SetSP( IDirectPlay8Address *pInterface, const GUID * const pguidSP );
	HRESULT DP8A_SetUserData( IDirectPlay8Address *pInterface, const void * const pBuffer, const DWORD dwBufferSize );
	HRESULT DP8A_GetNumComponents( IDirectPlay8Address *pInterface, PDWORD pdwNumComponents );
	HRESULT DP8A_GetComponentByIndexW( IDirectPlay8Address *pInterface, const DWORD dwComponentID, WCHAR * pwszTag, PDWORD pdwNameLen, void * pComponentBuffer, PDWORD pdwComponentSize, PDWORD pdwDataType );
	HRESULT DP8A_GetComponentByNameW( IDirectPlay8Address *pInterface, const WCHAR * const pwszTag, void * pComponentBuffer, PDWORD pdwComponentSize, PDWORD pdwDataType );
	HRESULT DP8A_AddComponentW( IDirectPlay8Address *pInterface, const WCHAR * const pwszTag, const void * const pComponentData, const DWORD dwComponentSize, const DWORD dwDataType );
	HRESULT DP8A_BuildFromDirectPlay4Address( IDirectPlay8Address *pInterface, void * pvDataBuffer, DWORD dwDataSize );
	HRESULT DP8A_SetEqual( IDirectPlay8Address *pInterface, PDIRECTPLAY8ADDRESS pdp8Address );
	HRESULT DP8A_IsEqual( IDirectPlay8Address *pInterface, PDIRECTPLAY8ADDRESS pdp8Address );

	HRESULT DP8ATCP_BuildFromSockAddr( IDirectPlay8Address *pInterface, const SOCKADDR * const pSockAddr );
	HRESULT DP8ATCP_BuildAddressW( IDirectPlay8Address *pInterface, const WCHAR * const pwszAddress, const USHORT usPort );
	HRESULT DP8ATCP_GetSockAddress( IDirectPlay8Address *pInterface, SOCKADDR *pSockAddr, PDWORD pdwBufferSize );
	HRESULT DP8ATCP_GetLocalAddress( IDirectPlay8Address *pInterface, GUID * pguidAdapter, USHORT *psPort );
	HRESULT DP8ATCP_GetAddressW( IDirectPlay8Address *pInterface, WCHAR * pwszAddress, PDWORD pdwAddressLength, USHORT *psPort );
	HRESULT DP8ATCP_BuildLocalAddress( IDirectPlay8Address *pInterface, const GUID * const pguidAdapter, const USHORT psPort );

	// Typecast
	static DP8ADDRESSOBJECT *STDMETHODCALLTYPE GetDirectPlay8Address(IDirectPlay8Address *pBuffer);

	HRESULT Cleanup();
	HRESULT Clear();
	HRESULT Init();
	HRESULT SetElement( const WCHAR * const pszTag, const void * const pvData, const DWORD dwDataSize, const DWORD dwDataType );
	HRESULT GetElement( DWORD dwIndex, WCHAR * pszTag, PDWORD pdwTagSize, void * pvDataBuffer, PDWORD pdwDataSize, PDWORD pdwDataType );
	HRESULT GetElement( const WCHAR * const pszTag, void * pvDataBuffer, PDWORD pdwDataSize, PDWORD pdwDataType );
	HRESULT GetSP( GUID * pGuid );
	HRESULT SetSP( LPCGUID const pGuid );
	HRESULT GetDevice( GUID * pGuid );
	HRESULT SetDevice( LPCGUID const pGuid );
	HRESULT SetUserData( const void * const pvData, const DWORD dwDataSize );
	HRESULT GetUserData( void * pvDataBuffer, PDWORD pdwDataSize );

	HRESULT BuildURL( WCHAR * szURL, PDWORD pdwRequiredSize )	;
	HRESULT SetURL( WCHAR * szURL );

	HRESULT GetElementType( const WCHAR * pszTag, PDWORD pdwType );

	HRESULT Lock();
	HRESULT UnLock();

	inline GetNumComponents() { return m_dwElements; };

	inline void ENTERLOCK() { DNEnterCriticalSection( &m_csAddressLock ); };
	inline void LEAVELOCK() { DNLeaveCriticalSection( &m_csAddressLock ); };

	static void FPM_Element_BlockInit( void *pvItem );
	static void FPM_Element_BlockRelease( void *pvItem );
	
protected:

	inline BOOL IsLocked() { return (m_iLockCount>0); };

	HRESULT BuildURL_AddElements( WCHAR *szElements );
	HRESULT BuildURL_AddHeader( WCHAR *szWorking );
	HRESULT BuildURL_AddUserData( WCHAR *szWorking );
	void BuildURL_AddString( WCHAR *szElements, WCHAR *szSource );
	HRESULT BuildURL_AddBinaryData( WCHAR *szSource, BYTE *bData, DWORD dwDataLen );

	HRESULT InternalGetElement( const WCHAR * const pszTag, PDP8ADDRESSELEMENT *ppaElement );
	HRESULT InternalGetElement( const DWORD dwIndex, PDP8ADDRESSELEMENT *ppaElement );
	HRESULT CalcComponentStringSize( PDP8ADDRESSELEMENT paddElement, PDWORD pdwSize );
	DWORD CalcExpandedStringSize( WCHAR *szString );
	DWORD CalcExpandedBinarySize( PBYTE pbData, DWORD dwDataSize );
	BOOL IsEscapeChar( WCHAR ch );
	BOOL IsValid();

	DWORD m_dwSignature;
	DNCRITICAL_SECTION m_csAddressLock;
	DWORD m_dwStringSize;
	DWORD m_dwElements;
	PDP8ADDRESSELEMENT m_pSP;
	PDP8ADDRESSELEMENT m_pAdapter;
	PVOID m_pvUserData;
	DWORD m_dwUserDataSize;
	DWORD m_dwUserDataStringSize;
	int m_iLockCount;
	BOOL m_fValid;
	CBilink  m_blAddressElements;

};

__inline DP8ADDRESSOBJECT *DP8ADDRESSOBJECT::GetDirectPlay8Address(IDirectPlay8Address *pBuffer)
{
    return (DP8ADDRESSOBJECT *)pBuffer;
}

typedef DP8ADDRESSOBJECT *PDP8ADDRESSOBJECT;

HRESULT DP8A_STRCACHE_Init();
void DP8A_STRCACHE_Free();
 
#undef DPF_SUBCOMP
#define DPF_SUBCOMP DN_SUBCOMP_ADDR


#endif

