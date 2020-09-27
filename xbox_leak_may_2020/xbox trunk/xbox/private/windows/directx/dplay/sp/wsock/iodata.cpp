/*==========================================================================
 *
 *  Copyright (C) 1999-2000 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       IOData.cpp
 *  Content:	Functions for IO structures
 *
 *
 *  History:
 *   Date		By		Reason
 *   ====		==		======
 *	11/25/98	jtk		Created
 *	02/11/2000	jtk		Derived from IODAta.h
 ***************************************************************************/

#include "wsockspi.h"

#undef DPF_SUBCOMP
#define DPF_SUBCOMP DN_SUBCOMP_WSOCK

//**********************************************************************
// Constant definitions
//**********************************************************************

//**********************************************************************
// Macro definitions
//**********************************************************************

//**********************************************************************
// Structure definitions
//**********************************************************************

//**********************************************************************
// Variable definitions
//**********************************************************************

//**********************************************************************
// Function prototypes
//**********************************************************************

//**********************************************************************
// ------------------------------
// CIOData::CIOData - constructor
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CIOData::CIOData"

CIOData::CIOData():
	m_pSocketPort( NULL )
{
	memset( &m_Overlap, 0x00, sizeof( m_Overlap ) );
	memset( &m_Flags, 0x00, sizeof( m_Flags ) );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CIOData::~CIOData - destructor
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CIOData::~CIOData"

CIOData::~CIOData()
{
	DNASSERT( OverlapEvent() == NULL );
	DNASSERT( SocketPort() == NULL );
	DNASSERT( Win9xOperationPending() == FALSE );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CReadIOData::CReadIOData - constructor
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CReadIOData::CReadIOData"

CReadIOData::CReadIOData():
    m_iSocketAddressSize( 0 ),
    m_pSourceSocketAddress( NULL ),
	m_Win9xReceiveWSAReturn( ERROR_SUCCESS ),
    m_dwOverlappedBytesReceived( 0 ),
	m_dwBytesRead( 0 ),
	m_dwReadFlags( 0 ),
	m_lRefCount( 0 ),
	m_pThreadPool( NULL )
{
	m_OutstandingReadListLinkage.Initialize();
	DEBUG_ONLY( memset( &m_ReceivedData, 0x00, sizeof( m_ReceivedData ) ) );
	DEBUG_ONLY( m_fRetainedByHigherLayer = FALSE );
	DNASSERT( IsReadOperation() != FALSE );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CReadIOData::~CReadIOData - destructor
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CReadIOData::~CReadIOData"

CReadIOData::~CReadIOData()
{
	DNASSERT( m_OutstandingReadListLinkage.IsEmpty() != FALSE );
	DNASSERT( m_iSocketAddressSize == 0 );
	DNASSERT( m_pSourceSocketAddress == NULL );
	
	//
	// don't bother looking at the WSA error or bytes received
	//

	DNASSERT( m_lRefCount == 0 );
	DNASSERT( m_pThreadPool == NULL );
	DEBUG_ONLY( DNASSERT( m_fRetainedByHigherLayer ==  FALSE ) );
	DNASSERT( IsReadOperation() != FALSE );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CReadIOData::ReadIOData_Alloc - called when new CReadIOData is allocated
//
// Entry:		Pointer to context
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CReadIOData::ReadIOData_Alloc"

BOOL	CReadIOData::ReadIOData_Alloc( READ_IO_DATA_POOL_CONTEXT *const pContext )
{
	BOOL			fReturn;
	CSocketAddress	*pSocketAddress;


	DNASSERT( pContext != NULL );

	//
	// initialize
	//
	fReturn = TRUE;
	pSocketAddress = NULL;

	DNASSERT( IsReadOperation() != FALSE );
	DNASSERT( m_OutstandingReadListLinkage.IsEmpty() != FALSE );
	DNASSERT( m_iSocketAddressSize == 0 );
	DNASSERT( m_pSourceSocketAddress == NULL );
	DEBUG_ONLY( DNASSERT( m_fRetainedByHigherLayer == FALSE ) );

	//
	// attempt to get a socket address for this item
	//
	pSocketAddress = CreateIPAddress();

	if ( pSocketAddress == NULL )
	{
		DPF( 0, "Problem allocating a new socket address when creating ReadIOData pool item" );
		fReturn = FALSE;
		goto Exit;
	}

	pSocketAddress->SetAddressType( SP_ADDRESS_TYPE_READ_HOST );
	m_pSourceSocketAddress = pSocketAddress;
	m_iSocketAddressSize = pSocketAddress->GetAddressSize();

   	DNASSERT( OverlapEvent() == NULL );
	DNASSERT( m_pThreadPool == NULL );
	DNASSERT( m_lRefCount == 0 );

Exit:
	return	fReturn;
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CReadIOData::ReadIOData_Get - called when new CReadIOData is removed from pool
//
// Entry:		Pointer to context
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CReadIOData::ReadIOData_Get"

void	CReadIOData::ReadIOData_Get( READ_IO_DATA_POOL_CONTEXT *const pContext )
{
	DNASSERT( pContext != NULL );

	DNASSERT( IsReadOperation() != FALSE );
	DNASSERT( m_OutstandingReadListLinkage.IsEmpty() != FALSE );
	DNASSERT( m_pSourceSocketAddress != NULL );
	DNASSERT( m_iSocketAddressSize == m_pSourceSocketAddress->GetAddressSize() );
	DNASSERT( SocketPort() == NULL );
	DNASSERT( Win9xOperationPending() == FALSE );

	DNASSERT( pContext->pThreadPool != NULL );
	DEBUG_ONLY( DNASSERT( m_fRetainedByHigherLayer == FALSE ) );

	m_pSourceSocketAddress->Reset();
	m_pThreadPool = pContext->pThreadPool;
	SetOverlapEvent( pContext->pThreadPool->GetWinsock2ReceiveCompleteEvent() );

	DNASSERT( m_lRefCount == 0 );
	
	//
	// Initialize internal SPRECEIVEDDATA.  When data is received, it's possible
	// that the pointers in the SPRECEIVEDDATA block were manipulated.  Reset
	// them to reflect that the entire buffer is available.
	//
	m_SPReceivedBuffer.BufferDesc.pBufferData = m_ReceivedData;
	m_SPReceivedBuffer.BufferDesc.dwBufferSize = sizeof( m_ReceivedData );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CReadIOData::ReadIOData_Release - called when CReadIOData is returned to pool
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CReadIOData::ReadIOData_Release"

void	CReadIOData::ReadIOData_Release( void )
{
	DNASSERT( IsReadOperation() != FALSE );
	DNASSERT( m_lRefCount == 0 );
	DNASSERT( m_OutstandingReadListLinkage.IsEmpty() != FALSE );
	DNASSERT( m_pSourceSocketAddress != NULL );
	DNASSERT( Win9xOperationPending() == FALSE );
	DEBUG_ONLY( DNASSERT( m_fRetainedByHigherLayer == FALSE ) );

	DNASSERT( m_dwOverlappedBytesReceived == 0 );
	m_pThreadPool = NULL;
	SetOverlapEvent( NULL );
	SetSocketPort( NULL );

	DEBUG_ONLY( memset( &m_ReceivedData, 0x00, sizeof( m_ReceivedData ) ) );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CReadIOData::ReadIOData_Dealloc - called when CReadIOData is deallocated
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CReadIOData::ReadIOData_Dealloc"

void	CReadIOData::ReadIOData_Dealloc( void )
{
#pragma	TODO( johnkan, "Make SPAddresses have a ref count!" )
	DNASSERT( IsReadOperation() != FALSE );
	DNASSERT( m_lRefCount == 0 );
	DNASSERT( m_pSourceSocketAddress != NULL );
	DEBUG_ONLY( DNASSERT( m_fRetainedByHigherLayer == FALSE ) );
	ReturnIPAddress( static_cast<CIPAddress*>( m_pSourceSocketAddress ) );
	m_pSourceSocketAddress = NULL;
	m_iSocketAddressSize = 0;

	DNASSERT( m_OutstandingReadListLinkage.IsEmpty() != FALSE );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CReadIOData::ReturnSelfToPool - return this item to the pool
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CReadIOData::ReturnSelfToPool"

void	CReadIOData::ReturnSelfToPool( void )
{
	CThreadPool	*pThreadPool;


	DNASSERT( m_lRefCount == 0 );
	DNASSERT( m_pThreadPool != NULL );

	pThreadPool = m_pThreadPool;
	pThreadPool->ReturnReadIOData( this );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CWriteIOData::CWriteIOData - constructor
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CWriteIOData::CWriteIOData"

CWriteIOData::CWriteIOData():
	m_pNext( NULL ),
	m_pDestinationSocketAddress( NULL ),
	m_pBuffers( NULL ),
	m_uBufferCount( 0 ),
	m_pCommand( NULL ),
	m_SendCompleteAction( SEND_COMPLETE_ACTION_UNKNOWN ),
	m_Win9xSendHResult( DPN_OK ),
	m_dwOverlappedBytesSent( 0 ),
	m_dwBytesSent( 0 ),
	m_pProxiedEnumReceiveBuffer( NULL )
{
	m_OutstandingWriteListLinkage.Initialize();
	memset( &m_PrependBuffer, 0x00, sizeof( m_PrependBuffer ) );
	SetWriteOperation();
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CWriteIOData::~CWriteIOData - destructor
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CWriteIOData::~CWriteIOData"

CWriteIOData::~CWriteIOData()
{
	DNASSERT( m_pNext == NULL );
	DNASSERT( m_pDestinationSocketAddress == NULL );
	DNASSERT( m_pBuffers == NULL );
	DNASSERT( m_uBufferCount == 0 );
	DNASSERT( m_pCommand == NULL );
	DNASSERT( m_SendCompleteAction == SEND_COMPLETE_ACTION_UNKNOWN );
	DNASSERT( m_OutstandingWriteListLinkage.IsEmpty() != FALSE );
	DNASSERT( m_pProxiedEnumReceiveBuffer == NULL );
	DNASSERT( IsWriteOperation() != FALSE );

	//
	// don't bother checking the send hResult or the count of byes sent
	//
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CWriteIOData::WriteIOData_Alloc - called when new CWriteIOData is allocated
//
// Entry:		Pointer to context
//
// Exit:		Boolean indicating success
//				TRUE = allocation succeeded
//				FALSE = allocation failed
//
// Note:	We always want a command structure associated with CWriteIOData
//			so we don't need to grab a new command from the command pool each
//			time a CWriteIOData entry is removed from its pool.  This is done
//			for speed.
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CWriteIOData::WriteIOData_Alloc"

BOOL	CWriteIOData::WriteIOData_Alloc( WRITE_IO_DATA_POOL_CONTEXT *const pContext )
{
	BOOL	fReturn;
	CCommandData	*pCommand;


	DNASSERT( IsWriteOperation() != FALSE );
	DNASSERT( pContext != NULL );
	DNASSERT( m_pNext == NULL );
	DNASSERT( m_pDestinationSocketAddress == NULL );
	DNASSERT( m_pBuffers == NULL );
	DNASSERT( m_uBufferCount == 0 );
	DNASSERT( m_pCommand == NULL );
	DNASSERT( m_SendCompleteAction == SEND_COMPLETE_ACTION_UNKNOWN );
	DNASSERT( m_OutstandingWriteListLinkage.IsEmpty() != FALSE );

	//
	// initialize
	//
	fReturn = TRUE;

	pCommand = CreateCommand();
	if ( pCommand == NULL )
	{
		DPF( 0, "Could not get command when allocating new CWriteIOData!" );
		fReturn = FALSE;
		goto Exit;
	}

	//
	// associate this command with the WriteData, clear the command descriptor
	// because the command isn't really being used yet, and it'll
	// cause an ASSERT when it's removed from the WriteIOData pool.
	//
	m_pCommand = pCommand;
	DNASSERT( OverlapEvent() == NULL );

Exit:
	return	fReturn;
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CWriteIOData::WriteIOData_Get - called when new CWriteIOData is removed from pool
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CWriteIOData::WriteIOData_Get"

void	CWriteIOData::WriteIOData_Get( WRITE_IO_DATA_POOL_CONTEXT *const pContext )
{
	DNASSERT( pContext != NULL );

	DNASSERT( IsWriteOperation() != FALSE );
	DNASSERT( m_pNext == NULL );
	DNASSERT( m_pBuffers == NULL );
	DNASSERT( m_uBufferCount == 0 );

	DNASSERT( m_pCommand != NULL );
	m_pCommand->SetDescriptor();

	DNASSERT( m_pCommand->GetDescriptor() != NULL_DESCRIPTOR );
	DNASSERT( m_pCommand->GetUserContext() == NULL );
	
	DNASSERT( m_SendCompleteAction == SEND_COMPLETE_ACTION_UNKNOWN );
	DNASSERT( m_pDestinationSocketAddress == NULL );
	DNASSERT( m_OutstandingWriteListLinkage.IsEmpty() != FALSE );
	DNASSERT( SocketPort() == NULL );
	DNASSERT( Win9xOperationPending() == FALSE );

	DNASSERT( m_PrependBuffer.GenericHeader.bSPLeadByte == SP_HEADER_LEAD_BYTE );
	SetOverlapEvent( pContext->hOverlapEvent );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CWriteIOData::WriteIOData_Release - called when CWriteIOData is returned to pool
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CWriteIOData::WriteIOData_Release"

void	CWriteIOData::WriteIOData_Release( void )
{
	DNASSERT( m_pCommand != NULL );
	m_pCommand->Reset();

	DNASSERT( IsWriteOperation() != FALSE );
	DNASSERT( m_OutstandingWriteListLinkage.IsEmpty() != FALSE );
	DNASSERT( Win9xOperationPending() == FALSE );

	SetOverlapEvent( NULL );

	m_pBuffers = NULL;
	m_uBufferCount = 0;
	m_pDestinationSocketAddress = NULL;
	m_pNext = NULL;
	SetSocketPort( NULL );
	m_SendCompleteAction = SEND_COMPLETE_ACTION_UNKNOWN;

	DEBUG_ONLY( memset( &m_PrependBuffer, 0x00, sizeof( m_PrependBuffer ) ) );
}
//**********************************************************************


//**********************************************************************
// ------------------------------
// CWriteIOData::WriteIOData_Dealloc - called when new CWriteIOData is deallocated
//
// Entry:		Nothing
//
// Exit:		Nothing
// ------------------------------
#undef DPF_MODNAME
#define	DPF_MODNAME "CWriteIOData::WriteIOData_Dealloc"

void	CWriteIOData::WriteIOData_Dealloc( void )
{
	DNASSERT( m_pCommand != NULL );
	m_pCommand->DecRef();
	m_pCommand = NULL;

	DNASSERT( IsWriteOperation() != FALSE );
	DNASSERT( m_OutstandingWriteListLinkage.IsEmpty() != FALSE );

	DNASSERT( m_pDestinationSocketAddress == NULL );
	DNASSERT( m_pBuffers == NULL );
	DNASSERT( m_uBufferCount == 0 );
	DNASSERT( m_pCommand == NULL );
	SetOverlapEvent( NULL );
}
//**********************************************************************

