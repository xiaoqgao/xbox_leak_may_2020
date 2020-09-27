// TabInfo.cpp : implementation file
//

#include "stdafx.h"
#include "TabInfo.h"
#include "SongDesignerDll.h"
#include "Song.h"
#include <guiddlg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabInfo property page

CTabInfo::CTabInfo( CSongPropPageManager* pSongPropPageManager ) : CPropertyPage(CTabInfo::IDD)
{
	//{{AFX_DATA_INIT(CTabInfo)
	//}}AFX_DATA_INIT
	
	ASSERT( pSongPropPageManager != NULL );

	m_pSong = NULL;
	m_pPageManager = pSongPropPageManager;
	m_fNeedToDetach = FALSE;
}

CTabInfo::~CTabInfo()
{
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::SetSong

void CTabInfo::SetSong( CDirectMusicSong* pSong )
{
	m_pSong = pSong;

	UpdateControls();
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::EnableControls

void CTabInfo::EnableControls( BOOL fEnable ) 
{
	m_editAuthor.EnableWindow( fEnable );
	m_editCopyright.EnableWindow( fEnable );
	m_editSubject.EnableWindow( fEnable );
	m_editInfo.EnableWindow( fEnable );
	m_editVersion_1.EnableWindow( fEnable );
	m_editVersion_2.EnableWindow( fEnable );
	m_editVersion_3.EnableWindow( fEnable );
	m_editVersion_4.EnableWindow( fEnable );
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::UpdateControls

void CTabInfo::UpdateControls() 
{
	// Make sure controls have been created
	if( ::IsWindow(m_editVersion_1.m_hWnd) == FALSE )
	{
		return;
	}
	
	// Update controls
	m_editVersion_1.LimitText( 4 );
	m_editVersion_2.LimitText( 4 );
	m_editVersion_3.LimitText( 4 );
	m_editVersion_4.LimitText( 4 );

	if( m_pSong )
	{
		CString strText;

		EnableControls( TRUE );

		m_editAuthor.SetWindowText( m_pSong->m_strAuthor );
		m_editCopyright.SetWindowText( m_pSong->m_strCopyright );
		m_editSubject.SetWindowText( m_pSong->m_strSubject );
		m_editInfo.SetWindowText( m_pSong->m_strInfo );
		
		strText.Format( "%u", ((m_pSong->m_vVersion.dwVersionMS & 0xFFFF0000) >> 16) );
		m_editVersion_1.SetWindowText( strText );
		
		strText.Format( "%u", (m_pSong->m_vVersion.dwVersionMS & 0x0000FFFF) );
		m_editVersion_2.SetWindowText( strText );
		
		strText.Format( "%u", ((m_pSong->m_vVersion.dwVersionLS & 0xFFFF0000) >> 16) );
		m_editVersion_3.SetWindowText( strText );
		
		strText.Format( "%u", (m_pSong->m_vVersion.dwVersionLS & 0x0000FFFF) );
		m_editVersion_4.SetWindowText( strText );
	}
	else
	{
		m_editAuthor.SetWindowText( _T("") );
		m_editCopyright.SetWindowText( _T("") );
		m_editSubject.SetWindowText( _T(""));
		m_editInfo.SetWindowText( _T(""));
		m_editVersion_1.SetWindowText( _T("") );
		m_editVersion_2.SetWindowText( _T("") );
		m_editVersion_3.SetWindowText( _T("") );
		m_editVersion_4.SetWindowText( _T("") );

		EnableControls( FALSE );
	}
}


void CTabInfo::DoDataExchange(CDataExchange* pDX)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabInfo)
	DDX_Control(pDX, IDC_EDIT_GUID, m_btnGUID);
	DDX_Control(pDX, IDC_VERSION_4, m_editVersion_4);
	DDX_Control(pDX, IDC_VERSION_3, m_editVersion_3);
	DDX_Control(pDX, IDC_VERSION_2, m_editVersion_2);
	DDX_Control(pDX, IDC_VERSION_1, m_editVersion_1);
	DDX_Control(pDX, IDC_SUBJECT, m_editSubject);
	DDX_Control(pDX, IDC_INFO, m_editInfo);
	DDX_Control(pDX, IDC_COPYRIGHT, m_editCopyright);
	DDX_Control(pDX, IDC_AUTHOR, m_editAuthor);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTabInfo, CPropertyPage)
	//{{AFX_MSG_MAP(CTabInfo)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_EN_KILLFOCUS(IDC_AUTHOR, OnKillFocusAuthor)
	ON_EN_KILLFOCUS(IDC_COPYRIGHT, OnKillFocusCopyright)
	ON_EN_KILLFOCUS(IDC_SUBJECT, OnKillFocusSubject)
	ON_EN_KILLFOCUS(IDC_INFO, OnKillFocusInfo)
	ON_EN_KILLFOCUS(IDC_VERSION_1, OnKillFocusVersion_1)
	ON_EN_KILLFOCUS(IDC_VERSION_2, OnKillFocusVersion_2)
	ON_EN_KILLFOCUS(IDC_VERSION_3, OnKillFocusVersion_3)
	ON_EN_KILLFOCUS(IDC_VERSION_4, OnKillFocusVersion_4)
	ON_BN_CLICKED(IDC_EDIT_GUID, OnEditGuid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTabInfo message handlers

/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnSetActive

BOOL CTabInfo::OnSetActive() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	UpdateControls();

	// Store active tab
	m_pPageManager->m_pIPropSheet->GetActivePage( &CSongPropPageManager::sm_nActiveTab );

	return CPropertyPage::OnSetActive();
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnCreate

int CTabInfo::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	// Attach the window to the property page structure.
	// This has been done once already in the main application
	// since the main application owns the property sheet.
	// It needs to be done here so that the window handle can
	// be found in the DLLs handle map.
	if( !FromHandlePermanent( m_hWnd ) )
	{
		HWND hWnd = m_hWnd;
		m_hWnd = NULL;
		Attach( hWnd );
		m_fNeedToDetach = TRUE;
	}

	if( CPropertyPage::OnCreate(lpCreateStruct) == -1 )
	{
		return -1;
	}
	
	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnDestroy

void CTabInfo::OnDestroy() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	// Detach the window from the property page structure.
	// This will be done again by the main application since
	// it owns the property sheet.  It needs o be done here
	// so that the window handle can be removed from the
	// DLLs handle map.
	if( m_fNeedToDetach && m_hWnd )
	{
		HWND hWnd = m_hWnd;
		Detach();
		m_hWnd = hWnd;
	}

	CPropertyPage::OnDestroy();
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnKillFocusAuthor

void CTabInfo::OnKillFocusAuthor() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CString strAuthor;

		m_editAuthor.GetWindowText( strAuthor );

		// Strip leading and trailing spaces
		strAuthor.TrimRight();
		strAuthor.TrimLeft();

		if( strAuthor.Compare( m_pSong->m_strAuthor ) != 0 )
		{
			m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_AUTHOR );
			m_pSong->m_strAuthor = strAuthor;
			m_pSong->SetModified( TRUE );
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnKillFocusCopyright

void CTabInfo::OnKillFocusCopyright() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CString strCopyright;

		m_editCopyright.GetWindowText( strCopyright );

		// Strip leading and trailing spaces
		strCopyright.TrimRight();
		strCopyright.TrimLeft();

		if( strCopyright.Compare( m_pSong->m_strCopyright ) != 0 )
		{
			m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_COPYRIGHT );
			m_pSong->m_strCopyright = strCopyright;
			m_pSong->SetModified( TRUE );
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnKillFocusSubject

void CTabInfo::OnKillFocusSubject() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CString strSubject;

		m_editSubject.GetWindowText( strSubject );

		// Strip leading and trailing spaces
		strSubject.TrimRight();
		strSubject.TrimLeft();

		if( strSubject.Compare( m_pSong->m_strSubject ) != 0 )
		{
			m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_SUBJECT );
			m_pSong->m_strSubject = strSubject;
			m_pSong->SetModified( TRUE );
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnKillFocusInfo

void CTabInfo::OnKillFocusInfo() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CString strInfo;

		m_editInfo.GetWindowText( strInfo );

		// Strip leading and trailing spaces
		strInfo.TrimRight();
		strInfo.TrimLeft();

		if( strInfo.Compare( m_pSong->m_strInfo ) != 0 )
		{
			m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_INFO );
			m_pSong->m_strInfo = strInfo;
			m_pSong->SetModified( TRUE );
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnKillFocusVersion_1

void CTabInfo::OnKillFocusVersion_1() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CString strVersion_1;
		CString strSongVersion_1;

		m_editVersion_1.GetWindowText( strVersion_1 );

		// Strip leading and trailing spaces
		strVersion_1.TrimRight();
		strVersion_1.TrimLeft();

		if( strVersion_1.IsEmpty() )
		{
			CString strText;

			strText.Format( "%u", ((m_pSong->m_vVersion.dwVersionMS & 0xFFFF0000) >> 16) );
			m_editVersion_1.SetWindowText( strText );
		}
		else
		{
			strSongVersion_1.Format( "%u", ((m_pSong->m_vVersion.dwVersionMS & 0xFFFF0000) >> 16) );
			
			if( strVersion_1.Compare( strSongVersion_1 ) != 0 )
			{
				DWORD dwVersion_1 = _ttoi( strVersion_1 );
				dwVersion_1 = (dwVersion_1 & 0x0000FFFF) << 16;

				m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_VERSION );
				m_pSong->m_vVersion.dwVersionMS &= 0x0000FFFF;
				m_pSong->m_vVersion.dwVersionMS |= dwVersion_1;

				// Sync changes
				m_pSong->SetModified( TRUE );
				m_pSong->SyncChanges( SC_DIRECTMUSIC, 0, NULL );
			}
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnKillFocusVersion_2

void CTabInfo::OnKillFocusVersion_2() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CString strVersion_2;
		CString strSongVersion_2;

		m_editVersion_2.GetWindowText( strVersion_2 );

		// Strip leading and trailing spaces
		strVersion_2.TrimRight();
		strVersion_2.TrimLeft();

		if( strVersion_2.IsEmpty() )
		{
			CString strText;

			strText.Format( "%u", (m_pSong->m_vVersion.dwVersionMS & 0x0000FFFF) );
			m_editVersion_2.SetWindowText( strText );
		}
		else
		{
			strSongVersion_2.Format( "%u", (m_pSong->m_vVersion.dwVersionMS & 0x0000FFFF) );
			
			if( strVersion_2.Compare( strSongVersion_2 ) != 0 )
			{
				DWORD dwVersion_2 = _ttoi( strVersion_2 );
				dwVersion_2 &= 0x0000FFFF;

				m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_VERSION );
				m_pSong->m_vVersion.dwVersionMS &= 0xFFFF0000;
				m_pSong->m_vVersion.dwVersionMS |= dwVersion_2;

				// Sync changes
				m_pSong->SetModified( TRUE );
				m_pSong->SyncChanges( SC_DIRECTMUSIC, 0, NULL );
			}
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnKillFocusVersion_3

void CTabInfo::OnKillFocusVersion_3() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CString strVersion_3;
		CString strSongVersion_3;

		m_editVersion_3.GetWindowText( strVersion_3 );

		// Strip leading and trailing spaces
		strVersion_3.TrimRight();
		strVersion_3.TrimLeft();

		if( strVersion_3.IsEmpty() )
		{
			CString strText;

			strText.Format( "%u", ((m_pSong->m_vVersion.dwVersionLS & 0xFFFF0000) >> 16) );
			m_editVersion_3.SetWindowText( strText );
		}
		else
		{
			strSongVersion_3.Format( "%u", ((m_pSong->m_vVersion.dwVersionLS & 0xFFFF0000) >> 16) );
			
			if( strVersion_3.Compare( strSongVersion_3 ) != 0 )
			{
				DWORD dwVersion_3 = _ttoi( strVersion_3 );
				dwVersion_3 = (dwVersion_3 & 0x0000FFFF) << 16;

				m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_VERSION );
				m_pSong->m_vVersion.dwVersionLS &= 0x0000FFFF;
				m_pSong->m_vVersion.dwVersionLS |= dwVersion_3;

				// Sync changes
				m_pSong->SetModified( TRUE );
				m_pSong->SyncChanges( SC_DIRECTMUSIC, 0, NULL );
			}
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnKillFocusVersion_4

void CTabInfo::OnKillFocusVersion_4() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CString strVersion_4;
		CString strSongVersion_4;

		m_editVersion_4.GetWindowText( strVersion_4 );

		// Strip leading and trailing spaces
		strVersion_4.TrimRight();
		strVersion_4.TrimLeft();

		if( strVersion_4.IsEmpty() )
		{
			CString strText;

			strText.Format( "%u", (m_pSong->m_vVersion.dwVersionLS & 0x0000FFFF) );
			m_editVersion_4.SetWindowText( strText );
		}
		else
		{
			strSongVersion_4.Format( "%u", (m_pSong->m_vVersion.dwVersionLS & 0x0000FFFF) );
			
			if( strVersion_4.Compare( strSongVersion_4 ) != 0 )
			{
				DWORD dwVersion_4 = _ttoi( strVersion_4 );
				dwVersion_4 &= 0x0000FFFF;

				m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_VERSION );
				m_pSong->m_vVersion.dwVersionLS &= 0xFFFF0000;
				m_pSong->m_vVersion.dwVersionLS |= dwVersion_4;

				// Sync changes
				m_pSong->SetModified( TRUE );
				m_pSong->SyncChanges( SC_DIRECTMUSIC, 0, NULL );
			}
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTabInfo::OnEditGUID

void CTabInfo::OnEditGuid() 
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if( m_pSong )
	{
		CGuidDlg dlg;

		memcpy( &dlg.m_guid, &m_pSong->m_guidSong, sizeof(GUID) );

		if( dlg.DoModal() == IDOK )
		{
			m_pSong->m_pUndoMgr->SaveState( m_pSong, theApp.m_hInstance, IDS_UNDO_SONG_GUID );
			memcpy( &m_pSong->m_guidSong, &dlg.m_guid, sizeof(GUID) );

			// Sync changes
			m_pSong->SetModified( TRUE );
			m_pSong->SyncChanges( SC_DIRECTMUSIC, 0, NULL );

			// Notify connected nodes that Song GUID has changed
			theApp.m_pSongComponent->m_pIFramework8->NotifyNodes( m_pSong, DOCROOT_GuidChange, NULL );
		}

		m_btnGUID.SetFocus();
	}
}
