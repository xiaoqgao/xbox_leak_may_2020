//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by $$ROOT$$.RC
//
$$IF(PROJTYPE_MDI)
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
#define IDR_$$DOC$$TYPE_SRVR_IP		4
#define IDR_$$DOC$$TYPE_SRVR_EMB		5
$$ENDIF//MINI_SERVER || FULL_SERVER || CONTAINER_SERVER
$$IF(CONTAINER || CONTAINER_SERVER)
#define IDR_$$DOC$$TYPE_CNTR_IP		6
$$ENDIF//CONTAINER || CONTAINER_SERVER
$$ELSE //MDI
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
#define IDR_SRVR_INPLACE			4
#define IDR_SRVR_EMBEDDED			5
$$ENDIF//MINI_SERVER || FULL_SERVER || CONTAINER_SERVER
$$IF(CONTAINER || CONTAINER_SERVER)
#define IDR_CNTR_INPLACE			6
$$ENDIF//CONTAINER || CONTAINER_SERVER
$$ENDIF//!MDI
#define IDD_ABOUTBOX				100
$$IF(CFormView || CRecordView || CDaoRecordView || COleDBRecordView)
#define IDD_$$SAFE_ROOT$$_FORM			101
$$ENDIF
$$IF(CONTAINER || MINI_SERVER || FULL_SERVER || CONTAINER_SERVER || AUTOMATION)
#define IDP_OLE_INIT_FAILED			100
$$IF(MINI_SERVER)
#define IDP_USE_INSERT_OBJECT		101
$$ENDIF
$$IF(CONTAINER || CONTAINER_SERVER)
#define IDP_FAILED_TO_CREATE		102
#define ID_CANCEL_EDIT_CNTR			32768
$$ENDIF
$$IF(MINI_SERVER || FULL_SERVER || CONTAINER_SERVER)
#define ID_CANCEL_EDIT_SRVR			32769
$$ENDIF
$$ENDIF
$$IF(CRecordView || CDaoRecordView || COleDBRecordView)
#define IDP_FAILED_OPEN_DATABASE	103
$$ENDIF
$$IF(SOCKETS)
#define IDP_SOCKETS_INIT_FAILED		104
$$ENDIF //SOCKETS
$$IF(PROJTYPE_EXPLORER)
$$IF(CListView)
#define ID_VIEW_ARRANGE				127
$$ENDIF 
$$ENDIF 
#define IDR_MAINFRAME				128
#define IDR_$$DOC$$TYPE				129

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
$$IF(3D)
#define _APS_3D_CONTROLS			1
$$ENDIF //3D
$$IF(PROJTYPE_DLL || PROJTYPE_OCX)
#define _APS_NEXT_RESOURCE_VALUE	$$START_RES$$
#define _APS_NEXT_CONTROL_VALUE		$$START_RES$$
#define _APS_NEXT_SYMED_VALUE		$$START_RES$$
$$ELSE
#define _APS_NEXT_RESOURCE_VALUE	130
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		101
$$ENDIF //(PROJTYPE_DLL || PROJTYPE_OCX)
#define _APS_NEXT_COMMAND_VALUE		32771
#endif
#endif
