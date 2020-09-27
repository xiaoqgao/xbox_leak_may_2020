; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "$$root$$.h"
$$IF(AUTOMATION)
ODLFile=$$root$$.odl
$$ENDIF
LastPage=0

ClassCount=9
Class1=$$APP_CLASS$$
$$IF(!NODOCVIEW)
Class2=$$DOC_CLASS$$
Class3=$$VIEW_CLASS$$
$$ELSE
Class3=$$WNDVIEW_CLASS$$
$$ENDIF
Class4=$$FRAME_CLASS$$
$$IF(FULL_SERVER || MINI_SERVER || CONTAINER_SERVER)
Class5=$$IPFRAME_CLASS$$
$$ENDIF
$$IF(CRecordView || CDaoRecordView )
Class6=$$RECSET_CLASS$$
$$ENDIF
$$IF(MDICHILD)
Class7=$$CHILD_FRAME_CLASS$$
$$ENDIF //MDICHILD
$$IF(PROJTYPE_EXPLORER)
Class8=$$TREEVIEW_CLASS$$
$$ENDIF //MDICHILD
Class9=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
$$IF(PROJTYPE_MDI)
Resource3=IDR_$$DOC$$TYPE
$$ENDIF
$$IF(PROJTYPE_MDI)
$$IF(CONTAINER || CONTAINER_SERVER)
Resource4=IDR_$$DOC$$TYPE_CNTR_IP
$$ENDIF //CONTAINERS
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
Resource5=IDR_$$DOC$$TYPE_SRVR_IP
Resource6=IDR_$$DOC$$TYPE_SRVR_EMB
$$ENDIF //SERVERS
$$ELSE //SDI
$$IF(CONTAINER || CONTAINER_SERVER)
Resource4=IDR_CNTR_INPLACE
$$ENDIF //CONTAINERS
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
Resource5=IDR_SRVR_INPLACE
Resource6=IDR_SRVR_EMBEDDED
$$ENDIF //SERVERS
$$ENDIF //MDI/SDI
$$IF(CRecordView || CFormView || CDaoRecordView || COleDBRecordView )
Resource7=IDD_$$SAFE_ROOT$$_FORM
$$ENDIF //CRecordView || CFormView || CDaoRecordView

[CLS:$$APP_CLASS$$]
Type=0
HeaderFile=$$root$$.h
ImplementationFile=$$root$$.cpp
Filter=N

$$IF(!NODOCVIEW)
[CLS:$$DOC_CLASS$$]
Type=0
HeaderFile=$$doc_hfile$$.h
ImplementationFile=$$doc_ifile$$.cpp
Filter=N

[CLS:$$VIEW_CLASS$$]
Type=0
HeaderFile=$$view_hfile$$.h
ImplementationFile=$$view_ifile$$.cpp
$$IF(CRecordView || CFormView || CDaoRecordView || COleDBRecordView )
Filter=D
$$ELSE
Filter=C
$$ENDIF

$$ELSE
[CLS:$$WNDVIEW_CLASS$$]
Type=0
HeaderFile=$$wndview_hfile$$.h
ImplementationFile=$$wndview_ifile$$.cpp
Filter=N
$$ENDIF

$$IF(CRecordView || CDaoRecordView )
[CLS:$$RECSET_CLASS$$]
Type=0
HeaderFile=$$recset_hfile$$.h
ImplementationFile=$$recset_ifile$$.cpp
Filter=N

[DB:$$RECSET_CLASS$$]
DB=1
$$IF(CDaoRecordView)
DBType=DAO
$$ELSE
DBType=ODBC
$$ENDIF
ColumnCount=$$DB_NUMCOLS$$
$$DB_COLSINFO$$

$$ENDIF //CRecordView || CDaoRecordView
[CLS:$$FRAME_CLASS$$]
Type=0
HeaderFile=$$frame_hfile$$.h
ImplementationFile=$$frame_ifile$$.cpp
Filter=T

$$IF(FULL_SERVER || MINI_SERVER || CONTAINER_SERVER)
[CLS:$$IPFRAME_CLASS$$]
Type=0
HeaderFile=$$ipframe_hfile$$.h
ImplementationFile=$$ipframe_ifile$$.cpp
Filter=T
$$ENDIF //FULL,MINI,CONTAINER _SERVERS

$$IF(MDICHILD)
[CLS:$$CHILD_FRAME_CLASS$$]
Type=0
HeaderFile=$$child_frame_hfile$$.h
ImplementationFile=$$child_frame_ifile$$.cpp
Filter=M
$$ENDIF //MDICHILD

$$IF(PROJTYPE_EXPLORER)
[CLS:$$TREEVIEW_CLASS$$]
Type=0
HeaderFile=$$treeview_hfile$$.h
ImplementationFile=$$treeview_ifile$$.cpp
Filter=T
$$ENDIF //MDICHILD

[CLS:CAboutDlg]
Type=0
HeaderFile=$$root$$.cpp
ImplementationFile=$$root$$.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

$$IF(PROJTYPE_MDI)
[MNU:IDR_MAINFRAME]
Type=1
Class=$$FRAME_CLASS$$
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
$$IF(PRINT)
Command3=ID_FILE_PRINT_SETUP
$$ENDIF
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
$$IF(TOOLBAR)
Command6=ID_VIEW_TOOLBAR
$$ENDIF //TOOLBAR
$$IF(STATUSBAR)
Command7=ID_VIEW_STATUS_BAR
$$ENDIF //STATUSBAR
$$IF(HELP)
Command8=ID_HELP_FINDER
$$ENDIF //HELP
Command9=ID_APP_ABOUT
CommandCount=9

$$IF(TOOLBAR)
[TB:IDR_MAINFRAME]
Type=1
Class=$$FRAME_CLASS$$
$$IF(!DB_NO_FILE)
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
$$ENDIF
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command8=ID_RECORD_FIRST
Command9=ID_RECORD_PREV
Command10=ID_RECORD_NEXT
Command11=ID_RECORD_LAST
$$ENDIF
Command12=ID_APP_ABOUT
$$IF(HELP)
Command13=ID_CONTEXT_HELP
$$ENDIF
$$ENDIF
CommandCount=13

[MNU:IDR_$$DOC$$TYPE]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
$$IF(PRINT)
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
$$ENDIF //PRINT
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
$$IF(CONTAINER || CONTAINER_SERVER)
Command15=ID_EDIT_PASTE_SPECIAL
Command16=ID_OLE_INSERT_NEW
Command17=ID_OLE_EDIT_LINKS
$$IF(CRichEditView)
Command18=ID_EDIT_SELECT_ALL
Command19=ID_EDIT_FIND
Command20=ID_EDIT_REPEAT
Command21=ID_EDIT_REPLACE
Command22=ID_OLE_EDIT_PROPERTIES
$$ENDIF //CRichEditView
$$ENDIF //CONTAINERS
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command25=ID_RECORD_FIRST
Command26=ID_RECORD_PREV
Command27=ID_RECORD_NEXT
Command28=ID_RECORD_LAST
$$ENDIF //CRecordView || CDaoRecordView
$$IF(TOOLBAR)
Command29=ID_VIEW_TOOLBAR
$$ENDIF //TOOLBAR
$$IF(STATUSBAR)
Command30=ID_VIEW_STATUS_BAR
$$ENDIF //STATUSBAR
Command31=ID_WINDOW_NEW
Command32=ID_WINDOW_CASCADE
Command33=ID_WINDOW_TILE_HORZ
Command34=ID_WINDOW_ARRANGE
$$IF(HELP)
Command35=ID_HELP_FINDER
$$ENDIF //HELP
Command36=ID_APP_ABOUT
CommandCount=36

$$IF(CONTAINER || CONTAINER_SERVER)
[MNU:IDR_$$DOC$$TYPE_CNTR_IP]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
$$IF(PRINT)
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
$$ENDIF //PRINT
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_WINDOW_NEW
Command12=ID_WINDOW_CASCADE
Command13=ID_WINDOW_TILE_HORZ
Command14=ID_WINDOW_ARRANGE
CommandCount=14

$$ENDIF//CONTAINER || CONTAINER_SERVER
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
[MNU:IDR_$$DOC$$TYPE_SRVR_EMB]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_UPDATE
$$IF(MINI_SERVER)
$$ELSE		
Command5=ID_FILE_SAVE_COPY_AS
$$ENDIF		
$$IF(PRINT)
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
$$ENDIF //PRINT
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
$$IF(CONTAINER || CONTAINER_SERVER)
Command15=ID_EDIT_PASTE_SPECIAL
Command16=ID_OLE_INSERT_NEW
Command17=ID_OLE_EDIT_LINKS
$$IF(CRichEditView)
Command18=ID_EDIT_SELECT_ALL
Command19=ID_EDIT_FIND
Command20=ID_EDIT_REPEAT
Command21=ID_EDIT_REPLACE
Command22=ID_OLE_EDIT_PROPERTIES
$$ENDIF //CRichEditView
$$ENDIF //CONTAINERS
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command25=ID_RECORD_FIRST
Command26=ID_RECORD_PREV
Command27=ID_RECORD_NEXT
Command28=ID_RECORD_LAST
$$ENDIF //CRecordView || CDaoRecordView
$$IF(TOOLBAR)
Command29=ID_VIEW_TOOLBAR
$$ENDIF //TOOLBAR
$$IF(STATUSBAR)
Command30=ID_VIEW_STATUS_BAR
$$ENDIF //STATUSBAR
Command31=ID_WINDOW_NEW
Command32=ID_WINDOW_CASCADE
Command33=ID_WINDOW_TILE_HORZ
Command34=ID_WINDOW_ARRANGE
$$IF(HELP)
Command35=ID_HELP_FINDER
$$ENDIF //HELP
Command36=ID_APP_ABOUT
CommandCount=36

[MNU:IDR_$$DOC$$TYPE_SRVR_IP]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
$$IF(CONTAINER || CONTAINER_SERVER)
Command15=ID_EDIT_PASTE_SPECIAL
Command16=ID_OLE_INSERT_NEW
Command17=ID_OLE_EDIT_LINKS
$$IF(CRichEditView)
Command18=ID_EDIT_SELECT_ALL
Command19=ID_EDIT_FIND
Command20=ID_EDIT_REPEAT
Command21=ID_EDIT_REPLACE
Command22=ID_OLE_EDIT_PROPERTIES
$$ENDIF //CRichEditView
$$ENDIF //CONTAINERS
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command25=ID_RECORD_FIRST
Command26=ID_RECORD_PREV
Command27=ID_RECORD_NEXT
Command28=ID_RECORD_LAST
$$ENDIF //CRecordView || CDaoRecordView
$$IF(HELP)
Command29=ID_HELP_FINDER
$$ENDIF //HELP
Command30=ID_APP_ABOUT
CommandCount=30

$$IF(TOOLBAR)
[TB:IDR_$$DOC$$TYPE_SRVR_IP]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
$$IF(!DB_NO_FILE)
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command4=ID_RECORD_FIRST
Command5=ID_RECORD_PREV
Command6=ID_RECORD_NEXT
Command7=ID_RECORD_LAST
$$ENDIF // (CRecordView || CDaoRecordView)
$$ENDIF	// (!DB_NO_FILE)
Command8=ID_APP_ABOUT
$$IF(HELP)
Command9=ID_CONTEXT_HELP
$$ENDIF // (HELP)
CommandCount=9

$$ENDIF // (TOOLBAR)
$$ENDIF//MINI_SERVER || FULL_SERVER || CONTAINER_SERVER
$$ELSE //SDI
[MNU:IDR_MAINFRAME]
Type=1
Class=$$FRAME_CLASS$$
$$IF(MINI_SERVER)
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
$$ELSE
$$IF(!DB_NO_FILE)
Command3=ID_FILE_NEW
Command4=ID_FILE_OPEN
Command5=ID_FILE_SAVE
Command6=ID_FILE_SAVE_AS
$$ENDIF //!DB_NO_FILE
$$IF(PRINT)
Command7=ID_FILE_PRINT
Command8=ID_FILE_PRINT_PREVIEW
Command9=ID_FILE_PRINT_SETUP
$$ENDIF //PRINT
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
$$IF(CONTAINER || CONTAINER_SERVER)
Command16=ID_EDIT_PASTE_SPECIAL
Command17=ID_OLE_INSERT_NEW
Command18=ID_OLE_EDIT_LINKS
$$IF(CRichEditView)
Command19=ID_EDIT_SELECT_ALL
Command20=ID_EDIT_FIND
Command21=ID_EDIT_REPEAT
Command22=ID_EDIT_REPLACE
Command23=ID_OLE_EDIT_PROPERTIES
$$ENDIF //CRichEditView
$$ENDIF //CONTAINERS
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command25=ID_RECORD_FIRST
Command26=ID_RECORD_PREV
Command27=ID_RECORD_NEXT
Command28=ID_RECORD_LAST
$$ENDIF //CRecordView || CDaoRecordView
$$IF(TOOLBAR)
Command29=ID_VIEW_TOOLBAR
$$ENDIF //TOOLBAR
$$IF(STATUSBAR)
Command30=ID_VIEW_STATUS_BAR
$$ENDIF //STATUSBAR
$$IF(HELP)
Command31=ID_HELP_FINDER
$$ENDIF //HELP
Command32=ID_APP_ABOUT
$$ENDIF//!MINI_SERVER
CommandCount=32

$$IF(CONTAINER || CONTAINER_SERVER)
[MNU:IDR_CNTR_INPLACE]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
$$IF(PRINT)
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
$$ENDIF //PRINT
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
CommandCount=9

$$ENDIF//CONTAINER || CONTAINER_SERVER
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
[MNU:IDR_SRVR_INPLACE]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
$$IF(CONTAINER || CONTAINER_SERVER)
Command16=ID_EDIT_PASTE_SPECIAL
Command17=ID_OLE_INSERT_NEW
Command18=ID_OLE_EDIT_LINKS
$$IF(CRichEditView)
Command19=ID_EDIT_SELECT_ALL
Command20=ID_EDIT_FIND
Command21=ID_EDIT_REPEAT
Command22=ID_EDIT_REPLACE
Command23=ID_OLE_EDIT_PROPERTIES
$$ENDIF //CRichEditView
$$ENDIF //CONTAINERS
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command24=ID_RECORD_FIRST
Command25=ID_RECORD_PREV
Command26=ID_RECORD_NEXT
Command27=ID_RECORD_LAST
$$ENDIF //CRecordView || CDaoRecordView
$$IF(HELP)
Command28=ID_HELP_FINDER
$$ENDIF //HELP
Command29=ID_APP_ABOUT
CommandCount=29

$$IF(TOOLBAR)
[TB:IDR_SRVR_INPLACE]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
$$IF(!DB_NO_FILE)
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command4=ID_RECORD_FIRST
Command5=ID_RECORD_PREV
Command6=ID_RECORD_NEXT
Command7=ID_RECORD_LAST
$$ENDIF // (CRecordView || CDaoRecordView)
$$ENDIF	// (!DB_NO_FILE)
Command8=ID_APP_ABOUT
$$IF(HELP)
Command9=ID_CONTEXT_HELP
$$ENDIF // (HELP)
CommandCount=9

$$ENDIF // (TOOLBAR)
[MNU:IDR_SRVR_EMBEDDED]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_UPDATE
$$IF(!MINI_SERVER)
Command2=ID_FILE_SAVE_COPY_AS
$$ENDIF		
$$IF(PRINT)
Command3=ID_FILE_PRINT
Command4=ID_FILE_PRINT_PREVIEW
Command5=ID_FILE_PRINT_SETUP
$$ENDIF //PRINT
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
$$IF(CONTAINER || CONTAINER_SERVER)
Command16=ID_EDIT_PASTE_SPECIAL
Command17=ID_OLE_INSERT_NEW
Command18=ID_OLE_EDIT_LINKS
$$IF(CRichEditView)
Command19=ID_EDIT_SELECT_ALL
Command20=ID_EDIT_FIND
Command21=ID_EDIT_REPEAT
Command22=ID_EDIT_REPLACE
Command23=ID_OLE_EDIT_PROPERTIES
$$ENDIF //CRichEditView
$$ENDIF //CONTAINERS
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
Command24=ID_RECORD_FIRST
Command25=ID_RECORD_PREV
Command26=ID_RECORD_NEXT
Command27=ID_RECORD_LAST
$$ENDIF //CRecordView || CDaoRecordView
$$IF(TOOLBAR)
Command28=ID_VIEW_TOOLBAR
$$ENDIF //TOOLBAR
$$IF(STATUSBAR)
Command29=ID_VIEW_STATUS_BAR
$$ENDIF //STATUSBAR
$$IF(HELP)
Command30=ID_HELP_FINDER
$$ENDIF //HELP
Command31=ID_APP_ABOUT
CommandCount=31

$$ENDIF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
$$ENDIF //SDI
$$IF(!MINI_SERVER)
[ACL:IDR_MAINFRAME]
Type=1
Class=$$FRAME_CLASS$$
$$IF(!DB_NO_FILE)
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
$$ENDIF //!DB_NO_FILE
$$IF(PRINT)
Command4=ID_FILE_PRINT
$$ENDIF //PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
$$IF(CRichEditView)
Command13=ID_EDIT_SELECT_ALL
Command14=ID_EDIT_FIND
Command15=ID_EDIT_REPEAT
Command16=ID_EDIT_REPLACE
$$ENDIF //CRichEditView
Command17=ID_NEXT_PANE
Command18=ID_PREV_PANE
$$IF(HELP)
Command19=ID_CONTEXT_HELP
Command20=ID_HELP
$$ENDIF //HELP
CommandCount=21

$$ENDIF //!MINI_SERVER
$$IF(PROJTYPE_MDI)
$$IF(CONTAINER || CONTAINER_SERVER)
[ACL:IDR_$$DOC$$TYPE_CNTR_IP]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
$$IF(PRINT)
Command4=ID_FILE_PRINT
$$ENDIF //PRINT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
$$IF(HELP)
Command7=ID_CONTEXT_HELP
Command8=ID_HELP
$$ENDIF //HELP
CommandCount=9

$$ENDIF //CONTAINERS
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
[ACL:IDR_$$DOC$$TYPE_SRVR_IP]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
$$IF(CRichEditView)
Command13=ID_EDIT_SELECT_ALL
Command14=ID_EDIT_FIND
Command15=ID_EDIT_REPEAT
Command16=ID_EDIT_REPLACE
$$ENDIF //CRichEditView
$$IF(HELP)
Command17=ID_CONTEXT_HELP
Command18=ID_HELP
$$ENDIF //HELP
CommandCount=18

[ACL:IDR_$$DOC$$TYPE_SRVR_EMB]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_UPDATE
$$IF(PRINT)
Command4=ID_FILE_PRINT
$$ENDIF //PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
$$IF(CRichEditView)
Command13=ID_EDIT_SELECT_ALL
Command14=ID_EDIT_FIND
Command15=ID_EDIT_REPEAT
Command16=ID_EDIT_REPLACE
$$ENDIF //CRichEditView
Command17=ID_EDIT_PASTE
Command18=ID_NEXT_PANE
Command19=ID_PREV_PANE
$$IF(HELP)
Command20=ID_CONTEXT_HELP
Command21=ID_HELP
$$ENDIF //HELP
CommandCount=22

$$ENDIF //SERVERS
$$ELSE //SDI
$$IF(CONTAINER || CONTAINER_SERVER)
[ACL:IDR_CNTR_INPLACE]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
$$IF(PRINT)
Command4=ID_FILE_PRINT
$$ENDIF //PRINT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
$$IF(HELP)
Command7=ID_CONTEXT_HELP
Command8=ID_HELP
$$ENDIF //HELP
CommandCount=9

$$ENDIF //CONTAINERS
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
[ACL:IDR_SRVR_INPLACE]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
$$IF(CRichEditView)
Command13=ID_EDIT_SELECT_ALL
Command14=ID_EDIT_FIND
Command15=ID_EDIT_REPEAT
Command16=ID_EDIT_REPLACE
$$ENDIF //CRichEditView
$$IF(HELP)
Command17=ID_CONTEXT_HELP
Command18=ID_HELP
$$ENDIF //HELP
CommandCount=18

[ACL:IDR_SRVR_EMBEDDED]
Type=1
Class=$$VIEW_CLASS$$
Command1=ID_FILE_UPDATE
$$IF(PRINT)
Command2=ID_FILE_PRINT
$$ENDIF //PRINT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
$$IF(CRichEditView)
Command13=ID_EDIT_SELECT_ALL
Command14=ID_EDIT_FIND
Command15=ID_EDIT_REPEAT
Command16=ID_EDIT_REPLACE
$$ENDIF //CRichEditView
Command17=ID_NEXT_PANE
Command18=ID_PREV_PANE
$$IF(HELP)
Command19=ID_CONTEXT_HELP
Command20=ID_HELP
$$ENDIF //HELP
CommandCount=21

$$ENDIF //SERVERS
$$ENDIF //SDI
$$IF(CFormView || CRecordView || CDaoRecordView || COleDBRecordView)
[DLG:IDD_$$SAFE_ROOT$$_FORM]
Type=1
Class=$$VIEW_CLASS$$
$$ENDIF

