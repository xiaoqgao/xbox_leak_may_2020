/*
    db2oledb.h
    Constant values for the Microsoft OLE DB Provider for DB2
    Version 05.00 (DBPROP_PROVIDERVER)
    Copyright (c) Microsoft Corporation.  All rights reserved.
*/

#ifndef __db2oledb_h__
#define __db2oledb_h__

#ifdef _DB2OLEDB_

extern const OLEDBDECLSPEC  CLSID CLSID_DB2ErrorLookup = {0x0DC5D5B6,0x21CB,0x11d2,{0x9C,0x5B,0x00,0x60,0xB0,0x3C,0x55,0x95}};;

extern const OLEDBDECLSPEC CLSID CLSID_DB2OLEDB = {0x0DC5D5B5,0x21CB,0x11d2,{0x9C,0x5B,0x00,0x60,0xB0,0x3C,0x55,0x95}};

extern const OLEDBDECLSPEC IID DB2OLEDB_DBPROPSET_DBINIT = { 0xd5a7c608, 0x37f8, 0x11d2, { 0x84, 0xf3, 0x0, 0x0, 0xf8, 0x7a, 0x53, 0xf8 }};

extern const OLEDBDECLSPEC CLSID CLSID_ConnPage = {0xD518F731,0x1EA9,0x11D3,{0xA6,0xE7,0x00,0x80,0xC7,0x1B,0x80,0x71}};

extern const OLEDBDECLSPEC CLSID CLSID_AdvPage = {0xF859C891,0x1EA9,0x11D3,{0xA6,0xE7,0x00,0x80,0xC7,0x1B,0x80,0x71}};

#endif
////////////////////////////////////////////////////////////////////////////////
// DB2OLEDB_DBPROPSET_DBINIT property enumeration


enum SNAOLEDB_DBPROPENUM
{
	DBPROP_DB2OLEDB_REMOTELU	= 0x02,         /* APPC Remote LU Alias. For SNA NETTYPE. */
	DBPROP_DB2OLEDB_LOCALLU		= 0x03,         /* APPC Local LU Alias. For SNA NETTYPE. */
	DBPROP_DB2OLEDB_APPCMODE	= 0x04,         /* APPC Mode Name. For SNA NETTYPE. */
	DBPROP_DB2OLEDB_NETTYPE		= 0x05,         /* Network Transport Library "SNA" or "TCPIP" */
	DBPROP_DB2OLEDB_HOSTCCSID	= 0x06,         /* Host CCSID. See Host Integration Server docs for supported values. */
	DBPROP_DB2OLEDB_PCCODEPAGE	= 0x07,         /* PC Code Page. See Host Integration Server docs for supported values. */
    DBPROP_DB2OLEDB_NETADDRESS  = 0x08,         /* Network Address. For TCPIP NETTYPE.  IP address or hostname */
    DBPROP_DB2OLEDB_NETPORT     = 0x09,         /* Network Port. For TCPIP NETTYPE. */

	DBPROP_DB2OLEDB_PACKAGECOL	= 0x30,         /* Package Collection */
	DBPROP_DB2OLEDB_CATALOGCOL	= 0x31,         /* Default Schema */
	DBPROP_DB2OLEDB_TPNAME		= 0x33,         /* Alternate TP Name. For SNA NETTYPE. */
	DBPROP_DB2OLEDB_UNITSOFWORK	= 0x36,         /* Units of Work */

	DBPROP_DB2OLEDB_BINASCHAR	= 0xa1,         /* Process Binary as Character */
};

/* Native Error Codes: */
#define DB2OLEDB_ERROR                      -1
#define DB2OLEDB_ERROR_SEND                 -2
#define DB2OLEDB_ERROR_RECEIVE              -3
#define DB2OLEDB_INVALID_POINTER            -4
#define DB2OLEDB_INVALID_PARAM              -5
#define DB2OLEDB_INVALID_DATA               -6
#define DB2OLEDB_INVALID_CONVERSION         -7
#define DB2OLEDB_INVALID_USER               -8
#define DB2OLEDB_ERROR_WRITE                -9
#define DB2OLEDB_ERROR_READ                 -10
#define DB2OLEDB_FILE_NOT_FOUND             -11
#define DB2OLEDB_INDEX_NOT_FOUND            -12
#define DB2OLEDB_RECORD_NOT_FOUND           -13
#define DB2OLEDB_KEY_NOT_FOUND              -14
#define DB2OLEDB_INVALID_FORMAT             -15
#define DB2OLEDB_MAX_CONNECTIONS            -16
#define DB2OLEDB_NOT_CONNECTED              -17
#define DB2OLEDB_NETWORK_ERROR              -18
#define DB2OLEDB_INVALID_DATASOURCE         -19
#define DB2OLEDB_ACCESS_DENIED              -20
#define DB2OLEDB_FILE_NOT_OPENED            -21
#define DB2OLEDB_MEMORY_ALLOC               -22
#define DB2OLEDB_DATA_NOT_FOUND             -23
#define DB2OLEDB_INDEX_EXISTS               -24
#define DB2OLEDB_FUNCTION_NOT_SUPPORTED     -25
#define DB2OLEDB_NO_CACHE                   -26
#define DB2OLEDB_FILE_LENGTH                -27
#define DB2OLEDB_INVALID_CONN_ID            -28
#define DB2OLEDB_INVALID_FILE_ID            -29
#define DB2OLEDB_INVALID_FILENAME           -30
#define DB2OLEDB_LOCAL_FILE_ERROR           -31
#define DB2OLEDB_INVALID_VIEW_ID            -32
#define DB2OLEDB_INVALID_VIEW               -33
#define DB2OLEDB_DISK_FULL                  -34
#define DB2OLEDB_DEST_FILE_CHANGED          -35
#define DB2OLEDB_FTX_FAILED                 -36
#define DB2OLEDB_FTX_ABORTED_BY_HOST        -37
#define DB2OLEDB_CONNECTION_LOST            -38
#define DB2OLEDB_CONNECTION_BUSY            -39
#define DB2OLEDB_HOST_NOT_RESPONDING        -40
#define DB2OLEDB_INVALID_DATA_CONV          -41
#define DB2OLEDB_DATA_TYPE_NOT_SUPPORTED    -42
#define DB2OLEDB_TIMEOUT                    -43
#define DB2OLEDB_DDMAGENT_NOT_LOADED        -44
#define DB2OLEDB_COMPONENT_MISSING          -45
#define DB2OLEDB_DCONV_DLL_NOT_FOUND        -46
#define DB2OLEDB_INVALID_STMT_HANDLE        -47
#define DB2OLEDB_VALUE_NOT_SUPPORTED        -48
#define DB2OLEDB_INTERNAL_ERROR             -50
#define DB2OLEDB_TOO_MANY_STATEMENTS        -51
#define DB2OLEDB_ENLIST_NO_XLN              -52  /* DTC hr = 0x8004D108 */
#define DB2OLEDB_ENLIST_DUP_TRAN            -53  /* DTC hr = 0x8004D10B */
#define DB2OLEDB_ENLIST_LU_BUSY             -54  /* DTC hr = 0x8004D10C */
#define DB2OLEDB_ENLIST_NO_RESYNCSVC        -55  /* DTC hr = 0x8004D10D */
#define DB2OLEDB_ENLIST_LU_DOWN             -56  /* DTC hr = 0x8004D10E, or D10A */
#define DB2OLEDB_ENLIST_LU_RECOVERING       -57  /* DTC hr = 0x8004D10F */
#define DB2OLEDB_ENLIST_XLN_MISMATCH        -58  /* DTC hr = 0x8004D110 */
#define DB2OLEDB_DTC_INIT_FAIL              -59  /* TP_START prc = AP_CANT_CONTACT_DTC */
#define DB2OLEDB_DUW_UNPROTECTED            -60  /* cfg = DUW, but no Enlist */
#define DB2OLEDB_SQL_ERROR                  -99
/* 
    DDM originated error codes
    The last segment of the constant identifier is the DDM Code Point name returned from the host
    Refer to IBM Publication: SC21-9526 DDM Architecture Reference
*/
#define DB2OLEDB_DDM_ERROR_START    -256
#define DB2OLEDB_DDM_ABNUOWRM    	(DB2OLEDB_DDM_ERROR_START-0)        /* -256 */
#define DB2OLEDB_DDM_ACCATHRM    	(DB2OLEDB_DDM_ERROR_START-1) 
#define DB2OLEDB_DDM_ACCINTRM    	(DB2OLEDB_DDM_ERROR_START-2) 
#define DB2OLEDB_DDM_ACCMTHRM    	(DB2OLEDB_DDM_ERROR_START-3) 
#define DB2OLEDB_DDM_ACCRDBRM    	(DB2OLEDB_DDM_ERROR_START-4) 
#define DB2OLEDB_DDM_AGNPRMRM    	(DB2OLEDB_DDM_ERROR_START-5) 
#define DB2OLEDB_DDM_BASNAMRM    	(DB2OLEDB_DDM_ERROR_START-6) 
#define DB2OLEDB_DDM_BGNBNDRM    	(DB2OLEDB_DDM_ERROR_START-7) 
#define DB2OLEDB_DDM_CHGFATRM    	(DB2OLEDB_DDM_ERROR_START-8) 
#define DB2OLEDB_DDM_CLSDMGRM    	(DB2OLEDB_DDM_ERROR_START-9) 
#define DB2OLEDB_DDM_CMBACCAM    	(DB2OLEDB_DDM_ERROR_START-10)       /* -266 */
#define DB2OLEDB_DDM_CMBKEYAM    	(DB2OLEDB_DDM_ERROR_START-11) 
#define DB2OLEDB_DDM_CMBRNBAM    	(DB2OLEDB_DDM_ERROR_START-12) 
#define DB2OLEDB_DDM_CMDATHRM    	(DB2OLEDB_DDM_ERROR_START-13) 
#define DB2OLEDB_DDM_CMDCHKRM    	(DB2OLEDB_DDM_ERROR_START-14) 
#define DB2OLEDB_DDM_CMDCMPRM    	(DB2OLEDB_DDM_ERROR_START-15) 
#define DB2OLEDB_DDM_CMDNSPRM    	(DB2OLEDB_DDM_ERROR_START-16) 
#define DB2OLEDB_DDM_CMDVLTRM    	(DB2OLEDB_DDM_ERROR_START-17) 
#define DB2OLEDB_DDM_CMMRQSRM    	(DB2OLEDB_DDM_ERROR_START-18) 
#define DB2OLEDB_DDM_CSRNSARM    	(DB2OLEDB_DDM_ERROR_START-19) 
#define DB2OLEDB_DDM_DCLCNFRM    	(DB2OLEDB_DDM_ERROR_START-20)       /* -276 */
#define DB2OLEDB_DDM_DCLNAMRM    	(DB2OLEDB_DDM_ERROR_START-21) 
#define DB2OLEDB_DDM_DCLNFNRM    	(DB2OLEDB_DDM_ERROR_START-22) 
#define DB2OLEDB_DDM_DRCATHRM    	(DB2OLEDB_DDM_ERROR_START-23) 
#define DB2OLEDB_DDM_DRCDMGRM    	(DB2OLEDB_DDM_ERROR_START-24) 
#define DB2OLEDB_DDM_DRCENTRM    	(DB2OLEDB_DDM_ERROR_START-25) 
#define DB2OLEDB_DDM_DRCFULRM    	(DB2OLEDB_DDM_ERROR_START-26) 
#define DB2OLEDB_DDM_DRCIUSRM    	(DB2OLEDB_DDM_ERROR_START-27) 
#define DB2OLEDB_DDM_DRCNAMRM    	(DB2OLEDB_DDM_ERROR_START-28) 
#define DB2OLEDB_DDM_DRCNEMRM    	(DB2OLEDB_DDM_ERROR_START-29) 
#define DB2OLEDB_DDM_DRCNFNRM    	(DB2OLEDB_DDM_ERROR_START-30)       /* -286 */
#define DB2OLEDB_DDM_DRCSNARM    	(DB2OLEDB_DDM_ERROR_START-31) 
#define DB2OLEDB_DDM_DRCSUBRM    	(DB2OLEDB_DDM_ERROR_START-32) 
#define DB2OLEDB_DDM_DRCTNARM    	(DB2OLEDB_DDM_ERROR_START-33) 
#define DB2OLEDB_DDM_DSCINVRM    	(DB2OLEDB_DDM_ERROR_START-34) 
#define DB2OLEDB_DDM_DTAMAPRM    	(DB2OLEDB_DDM_ERROR_START-35) 
#define DB2OLEDB_DDM_DTAMCHRM    	(DB2OLEDB_DDM_ERROR_START-36) 
#define DB2OLEDB_DDM_DTANFNRM    	(DB2OLEDB_DDM_ERROR_START-37) 
#define DB2OLEDB_DDM_DTARECRM    	(DB2OLEDB_DDM_ERROR_START-38) 
#define DB2OLEDB_DDM_DUPDCLRM    	(DB2OLEDB_DDM_ERROR_START-39) 
#define DB2OLEDB_DDM_DUPDRCRM    	(DB2OLEDB_DDM_ERROR_START-40)       /* -296 */
#define DB2OLEDB_DDM_DUPFILRM    	(DB2OLEDB_DDM_ERROR_START-41) 
#define DB2OLEDB_DDM_DUPKDIRM    	(DB2OLEDB_DDM_ERROR_START-42) 
#define DB2OLEDB_DDM_DUPKSIRM    	(DB2OLEDB_DDM_ERROR_START-43) 
#define DB2OLEDB_DDM_DUPQUERM    	(DB2OLEDB_DDM_ERROR_START-44) 
#define DB2OLEDB_DDM_DUPRNBRM    	(DB2OLEDB_DDM_ERROR_START-45) 
#define DB2OLEDB_DDM_ENDFILRM    	(DB2OLEDB_DDM_ERROR_START-46) 
#define DB2OLEDB_DDM_ENDQRYRM    	(DB2OLEDB_DDM_ERROR_START-47) 
#define DB2OLEDB_DDM_ENDUOWRM    	(DB2OLEDB_DDM_ERROR_START-48) 
#define DB2OLEDB_DDM_EXSCNDRM    	(DB2OLEDB_DDM_ERROR_START-49) 
#define DB2OLEDB_DDM_FILATHRM    	(DB2OLEDB_DDM_ERROR_START-50)       /* -306 */
#define DB2OLEDB_DDM_FILDMGRM    	(DB2OLEDB_DDM_ERROR_START-51) 
#define DB2OLEDB_DDM_FILFULRM    	(DB2OLEDB_DDM_ERROR_START-52) 
#define DB2OLEDB_DDM_FILIUSRM    	(DB2OLEDB_DDM_ERROR_START-53) 
#define DB2OLEDB_DDM_FILNAMRM    	(DB2OLEDB_DDM_ERROR_START-54) 
#define DB2OLEDB_DDM_FILNFNRM    	(DB2OLEDB_DDM_ERROR_START-55) 
#define DB2OLEDB_DDM_FILNOPRM    	(DB2OLEDB_DDM_ERROR_START-56) 
#define DB2OLEDB_DDM_FILOLORM    	(DB2OLEDB_DDM_ERROR_START-57) 
#define DB2OLEDB_DDM_FILSNARM    	(DB2OLEDB_DDM_ERROR_START-58) 
#define DB2OLEDB_DDM_FILTNARM    	(DB2OLEDB_DDM_ERROR_START-59) 
#define DB2OLEDB_DDM_INTATHRM    	(DB2OLEDB_DDM_ERROR_START-60)       /* -316 */
#define DB2OLEDB_DDM_INTTKNRM    	(DB2OLEDB_DDM_ERROR_START-61) 
#define DB2OLEDB_DDM_INVRQSRM    	(DB2OLEDB_DDM_ERROR_START-62) 
#define DB2OLEDB_DDM_INVUSRRM    	(DB2OLEDB_DDM_ERROR_START-63) 
#define DB2OLEDB_DDM_KEYDEFRM    	(DB2OLEDB_DDM_ERROR_START-64) 
#define DB2OLEDB_DDM_KEYLENRM    	(DB2OLEDB_DDM_ERROR_START-65) 
#define DB2OLEDB_DDM_KEYMODRM    	(DB2OLEDB_DDM_ERROR_START-66) 
#define DB2OLEDB_DDM_KEYUDIRM    	(DB2OLEDB_DDM_ERROR_START-67) 
#define DB2OLEDB_DDM_KEYUSIRM    	(DB2OLEDB_DDM_ERROR_START-68) 
#define DB2OLEDB_DDM_KEYVALRM    	(DB2OLEDB_DDM_ERROR_START-69) 
#define DB2OLEDB_DDM_LODSTRRM    	(DB2OLEDB_DDM_ERROR_START-70)       /* -326 */
#define DB2OLEDB_DDM_MGMATHRM    	(DB2OLEDB_DDM_ERROR_START-71) 
#define DB2OLEDB_DDM_MGMCLSNM    	(DB2OLEDB_DDM_ERROR_START-72) 
#define DB2OLEDB_DDM_MGMCNFRM    	(DB2OLEDB_DDM_ERROR_START-73) 
#define DB2OLEDB_DDM_MGMNFNRM    	(DB2OLEDB_DDM_ERROR_START-74) 
#define DB2OLEDB_DDM_MGRDEPRM    	(DB2OLEDB_DDM_ERROR_START-75) 
#define DB2OLEDB_DDM_MGRLVLRM    	(DB2OLEDB_DDM_ERROR_START-76) 
#define DB2OLEDB_DDM_NEWDRNRM    	(DB2OLEDB_DDM_ERROR_START-77) 
#define DB2OLEDB_DDM_NEWNAMRM    	(DB2OLEDB_DDM_ERROR_START-78) 
#define DB2OLEDB_DDM_OBJNSPRM    	(DB2OLEDB_DDM_ERROR_START-79) 
#define DB2OLEDB_DDM_OPNCNFRM    	(DB2OLEDB_DDM_ERROR_START-80)       /* -336 */
#define DB2OLEDB_DDM_OPNEXCRM    	(DB2OLEDB_DDM_ERROR_START-81) 
#define DB2OLEDB_DDM_OPNMAXRM    	(DB2OLEDB_DDM_ERROR_START-82) 
#define DB2OLEDB_DDM_OPNQFLRM    	(DB2OLEDB_DDM_ERROR_START-83) 
#define DB2OLEDB_DDM_OPNQRYRM    	(DB2OLEDB_DDM_ERROR_START-84) 
#define DB2OLEDB_DDM_PKGBNARM    	(DB2OLEDB_DDM_ERROR_START-85) 
#define DB2OLEDB_DDM_PKGBPARM    	(DB2OLEDB_DDM_ERROR_START-86) 
#define DB2OLEDB_DDM_PRCCNVRM    	(DB2OLEDB_DDM_ERROR_START-87) 
#define DB2OLEDB_DDM_PRMNSPRM    	(DB2OLEDB_DDM_ERROR_START-88) 
#define DB2OLEDB_DDM_QRYNOPRM    	(DB2OLEDB_DDM_ERROR_START-89) 
#define DB2OLEDB_DDM_QRYPOPRM    	(DB2OLEDB_DDM_ERROR_START-90)       /* -346 */
#define DB2OLEDB_DDM_QUEATHRM    	(DB2OLEDB_DDM_ERROR_START-91) 
#define DB2OLEDB_DDM_QUEDMGRM    	(DB2OLEDB_DDM_ERROR_START-92) 
#define DB2OLEDB_DDM_QUEFULRM    	(DB2OLEDB_DDM_ERROR_START-93) 
#define DB2OLEDB_DDM_QUEIUSRM    	(DB2OLEDB_DDM_ERROR_START-94) 
#define DB2OLEDB_DDM_QUELENRM    	(DB2OLEDB_DDM_ERROR_START-95) 
#define DB2OLEDB_DDM_QUENAMRM    	(DB2OLEDB_DDM_ERROR_START-96) 
#define DB2OLEDB_DDM_QUENFNRM    	(DB2OLEDB_DDM_ERROR_START-97) 
#define DB2OLEDB_DDM_QUETNARM    	(DB2OLEDB_DDM_ERROR_START-98) 
#define DB2OLEDB_DDM_QUEVANRM    	(DB2OLEDB_DDM_ERROR_START-99) 
#define DB2OLEDB_DDM_RDBACCRM    	(DB2OLEDB_DDM_ERROR_START-100)      /* -356 */
#define DB2OLEDB_DDM_RDBAFLRM    	(DB2OLEDB_DDM_ERROR_START-101) 
#define DB2OLEDB_DDM_RDBATHRM    	(DB2OLEDB_DDM_ERROR_START-102) 
#define DB2OLEDB_DDM_RDBNACRM    	(DB2OLEDB_DDM_ERROR_START-103) 
#define DB2OLEDB_DDM_RDBNFNRM    	(DB2OLEDB_DDM_ERROR_START-104) 
#define DB2OLEDB_DDM_RDBUPDRM    	(DB2OLEDB_DDM_ERROR_START-105) 
#define DB2OLEDB_DDM_RECCNTRM    	(DB2OLEDB_DDM_ERROR_START-106) 
#define DB2OLEDB_DDM_RECDMGRM    	(DB2OLEDB_DDM_ERROR_START-107) 
#define DB2OLEDB_DDM_RECINARM    	(DB2OLEDB_DDM_ERROR_START-108) 
#define DB2OLEDB_DDM_RECIUSRM    	(DB2OLEDB_DDM_ERROR_START-109) 
#define DB2OLEDB_DDM_RECLENRM    	(DB2OLEDB_DDM_ERROR_START-110)      /* -366 */
#define DB2OLEDB_DDM_RECNAVRM    	(DB2OLEDB_DDM_ERROR_START-111) 
#define DB2OLEDB_DDM_RECNBRRM    	(DB2OLEDB_DDM_ERROR_START-112) 
#define DB2OLEDB_DDM_RECNFNRM    	(DB2OLEDB_DDM_ERROR_START-113) 
#define DB2OLEDB_DDM_RSCLMTRM    	(DB2OLEDB_DDM_ERROR_START-114) 
#define DB2OLEDB_DDM_SHDEXSRM    	(DB2OLEDB_DDM_ERROR_START-115) 
#define DB2OLEDB_DDM_SQLERRRM    	(DB2OLEDB_DDM_ERROR_START-116) 
#define DB2OLEDB_DDM_STGATHRM    	(DB2OLEDB_DDM_ERROR_START-117) 
#define DB2OLEDB_DDM_STGNFNRM    	(DB2OLEDB_DDM_ERROR_START-118) 
#define DB2OLEDB_DDM_STPCMPRM    	(DB2OLEDB_DDM_ERROR_START-119) 
#define DB2OLEDB_DDM_STRDMGRM    	(DB2OLEDB_DDM_ERROR_START-120)      /* -376 */
#define DB2OLEDB_DDM_STRIUSRM    	(DB2OLEDB_DDM_ERROR_START-121) 
#define DB2OLEDB_DDM_SUBSTRRM    	(DB2OLEDB_DDM_ERROR_START-122) 
#define DB2OLEDB_DDM_SYNTAXRM    	(DB2OLEDB_DDM_ERROR_START-123) 
#define DB2OLEDB_DDM_SYSCMDRM    	(DB2OLEDB_DDM_ERROR_START-124) 
#define DB2OLEDB_DDM_TRGNSPRM    	(DB2OLEDB_DDM_ERROR_START-125) 
#define DB2OLEDB_DDM_UPDCSRRM    	(DB2OLEDB_DDM_ERROR_START-126) 
#define DB2OLEDB_DDM_UPDINTRM    	(DB2OLEDB_DDM_ERROR_START-127) 
#define DB2OLEDB_DDM_USRATTRM    	(DB2OLEDB_DDM_ERROR_START-128) 
#define DB2OLEDB_DDM_VALNSPRM    	(DB2OLEDB_DDM_ERROR_START-129) 
#define DB2OLEDB_DDM_DFTRECRM       (DB2OLEDB_DDM_ERROR_START-130)      /* -386 */
#define DB2OLEDB_DDM_STGCNFRM       (DB2OLEDB_DDM_ERROR_START-131)

/*
    DB2OLEDB Communications Error Codes.
    Refer to Microsoft Host Integration Server SDK Documentation: APPC Programmer's Guide.
    Some error codes are related to TCP/IP communications.
*/ 
#define DB2OLEDB_COMM_ERROR_START                   -512
#define DB2OLEDB_COMM_PARAMETER_CHECK               (DB2OLEDB_COMM_ERROR_START)         /* APPC Errors: */
#define DB2OLEDB_COMM_BAD_TP_ID                     (DB2OLEDB_COMM_ERROR_START-1)
#define DB2OLEDB_COMM_BAD_CONV_ID                   (DB2OLEDB_COMM_ERROR_START-2)
#define DB2OLEDB_COMM_BAD_LU_ALIAS                  (DB2OLEDB_COMM_ERROR_START-3)
#define DB2OLEDB_COMM_INVALID_DATA_SEGMENT          (DB2OLEDB_COMM_ERROR_START-4)
#define DB2OLEDB_COMM_BAD_CONV_TYPE                 (DB2OLEDB_COMM_ERROR_START-5)
#define DB2OLEDB_COMM_BAD_SYNC_LEVEL                (DB2OLEDB_COMM_ERROR_START-6)
#define DB2OLEDB_COMM_BAD_SECURITY                  (DB2OLEDB_COMM_ERROR_START-7)
#define DB2OLEDB_COMM_BAD_RETURN_CONTROL            (DB2OLEDB_COMM_ERROR_START-8)       /* -520 */
#define DB2OLEDB_COMM_PIP_LEN_INCORRECT             (DB2OLEDB_COMM_ERROR_START-9)
#define DB2OLEDB_COMM_NO_USE_OF_SNASVCMG            (DB2OLEDB_COMM_ERROR_START-10)
#define DB2OLEDB_COMM_UNKNOWN_PARTNER_MODE          (DB2OLEDB_COMM_ERROR_START-11)
#define DB2OLEDB_COMM_CONFIRM_ON_SYNC_LEVEL_NONE    (DB2OLEDB_COMM_ERROR_START-12)
#define DB2OLEDB_COMM_DEALLOC_BAD_TYPE              (DB2OLEDB_COMM_ERROR_START-13)
#define DB2OLEDB_COMM_DEALLOC_LOG_LL_WRONG          (DB2OLEDB_COMM_ERROR_START-14)
#define DB2OLEDB_COMM_P_TO_R_INVALID_TYPE           (DB2OLEDB_COMM_ERROR_START-15)
#define DB2OLEDB_COMM_RCV_AND_WAIT_BAD_FILL         (DB2OLEDB_COMM_ERROR_START-16)
#define DB2OLEDB_COMM_RCV_IMMD_BAD_FILL             (DB2OLEDB_COMM_ERROR_START-17)
#define DB2OLEDB_COMM_RCV_AND_POST_BAD_FILL         (DB2OLEDB_COMM_ERROR_START-18)      /* -530 */
#define DB2OLEDB_COMM_INVALID_SEMAPHORE_HANDLE      (DB2OLEDB_COMM_ERROR_START-19)
#define DB2OLEDB_COMM_BAD_RETURN_STATUS_WITH_DATA   (DB2OLEDB_COMM_ERROR_START-20)
#define DB2OLEDB_COMM_BAD_LL                        (DB2OLEDB_COMM_ERROR_START-21)
#define DB2OLEDB_COMM_SEND_DATA_INVALID_TYPE        (DB2OLEDB_COMM_ERROR_START-22)
#define DB2OLEDB_COMM_INVALID_SESSION_ID            (DB2OLEDB_COMM_ERROR_START-23)
#define DB2OLEDB_COMM_SEND_DATA_CONFIRM_SYNC_NONE   (DB2OLEDB_COMM_ERROR_START-24)
#define DB2OLEDB_COMM_BAD_PARTNER_LU_ALIAS          (DB2OLEDB_COMM_ERROR_START-25) 
#define DB2OLEDB_COMM_SEND_ERROR_LOG_LL_WRONG       (DB2OLEDB_COMM_ERROR_START-26)
#define DB2OLEDB_COMM_SEND_ERROR_BAD_TYPE           (DB2OLEDB_COMM_ERROR_START-27) 
#define DB2OLEDB_COMM_BAD_ERROR_DIRECTION           (DB2OLEDB_COMM_ERROR_START-28)      /* -540 */
#define DB2OLEDB_COMM_TOO_MANY_TPS                  (DB2OLEDB_COMM_ERROR_START-29) 
#define DB2OLEDB_COMM_BAD_TYPE                      (DB2OLEDB_COMM_ERROR_START-30) 
#define DB2OLEDB_COMM_UNDEFINED_TP_NAME             (DB2OLEDB_COMM_ERROR_START-31) 

#define DB2OLEDB_COMM_STATE_CHECK                   (DB2OLEDB_COMM_ERROR_START-32)
#define DB2OLEDB_COMM_CONFIRM_BAD_STATE             (DB2OLEDB_COMM_ERROR_START-33)
#define DB2OLEDB_COMM_CONFIRM_NOT_LL_BDY            (DB2OLEDB_COMM_ERROR_START-34)
#define DB2OLEDB_COMM_CONFIRMED_BAD_STATE           (DB2OLEDB_COMM_ERROR_START-35)
#define DB2OLEDB_COMM_DEALLOC_FLUSH_BAD_STATE       (DB2OLEDB_COMM_ERROR_START-36)
#define DB2OLEDB_COMM_DEALLOC_CONFIRM_BAD_STATE     (DB2OLEDB_COMM_ERROR_START-37)
#define DB2OLEDB_COMM_DEALLOC_NOT_LL_BDY            (DB2OLEDB_COMM_ERROR_START-38)      /* -550 */
#define DB2OLEDB_COMM_FLUSH_NOT_SEND_STATE          (DB2OLEDB_COMM_ERROR_START-39)
#define DB2OLEDB_COMM_P_TO_R_NOT_LL_BDY             (DB2OLEDB_COMM_ERROR_START-40)
#define DB2OLEDB_COMM_P_TO_R_NOT_SEND_STATE         (DB2OLEDB_COMM_ERROR_START-41)
#define DB2OLEDB_COMM_RCV_AND_WAIT_BAD_STATE        (DB2OLEDB_COMM_ERROR_START-42)
#define DB2OLEDB_COMM_RCV_AND_WAIT_NOT_LL_BDY       (DB2OLEDB_COMM_ERROR_START-43)
#define DB2OLEDB_COMM_RCV_IMMD_BAD_STATE            (DB2OLEDB_COMM_ERROR_START-44)
#define DB2OLEDB_COMM_RCV_AND_POST_BAD_STATE        (DB2OLEDB_COMM_ERROR_START-45)
#define DB2OLEDB_COMM_RCV_AND_POST_NOT_LL_BDY       (DB2OLEDB_COMM_ERROR_START-46)
#define DB2OLEDB_COMM_R_T_S_BAD_STATE               (DB2OLEDB_COMM_ERROR_START-47)
#define DB2OLEDB_COMM_SEND_DATA_NOT_SEND_STATE      (DB2OLEDB_COMM_ERROR_START-48)      /* -560 */
#define DB2OLEDB_COMM_SEND_DATA_NOT_LL_BDY          (DB2OLEDB_COMM_ERROR_START-49)
#define DB2OLEDB_COMM_ATTACH_MANAGER_INACTIVE       (DB2OLEDB_COMM_ERROR_START-50)
#define DB2OLEDB_COMM_ALLOCATE_NOT_PENDING          (DB2OLEDB_COMM_ERROR_START-51)
#define DB2OLEDB_COMM_INVALID_PROCESS               (DB2OLEDB_COMM_ERROR_START-52)

#define DB2OLEDB_COMM_ALLOCATION_ERROR              (DB2OLEDB_COMM_ERROR_START-53)
#define DB2OLEDB_COMM_ALLOCATION_FAILURE_NO_RETRY   (DB2OLEDB_COMM_ERROR_START-54)
#define DB2OLEDB_COMM_ALLOCATION_FAILURE_RETRY      (DB2OLEDB_COMM_ERROR_START-55)
#define DB2OLEDB_COMM_SECURITY_NOT_VALID            (DB2OLEDB_COMM_ERROR_START-56)
#define DB2OLEDB_COMM_TRANS_PGM_NOT_AVAIL_RETRY     (DB2OLEDB_COMM_ERROR_START-57)
#define DB2OLEDB_COMM_TRANS_PGM_NOT_AVAIL_NO_RETRY  (DB2OLEDB_COMM_ERROR_START-58)      /* -570 */
#define DB2OLEDB_COMM_TP_NAME_NOT_RECOGNIZED        (DB2OLEDB_COMM_ERROR_START-59)
#define DB2OLEDB_COMM_PIP_NOT_ALLOWED               (DB2OLEDB_COMM_ERROR_START-60)
#define DB2OLEDB_COMM_PIP_NOT_SPECIFIED_CORRECTLY   (DB2OLEDB_COMM_ERROR_START-61)
#define DB2OLEDB_COMM_CONVERSATION_TYPE_MISMATCH    (DB2OLEDB_COMM_ERROR_START-62)
#define DB2OLEDB_COMM_SYNC_LEVEL_NOT_SUPPORTED      (DB2OLEDB_COMM_ERROR_START-63)

#define DB2OLEDB_COMM_DEALLOC_ABEND                 (DB2OLEDB_COMM_ERROR_START-64)
#define DB2OLEDB_COMM_DEALLOC_ABEND_PROG            (DB2OLEDB_COMM_ERROR_START-65)
#define DB2OLEDB_COMM_DEALLOC_ABEND_SVC             (DB2OLEDB_COMM_ERROR_START-66)
#define DB2OLEDB_COMM_DEALLOC_ABEND_TIMER           (DB2OLEDB_COMM_ERROR_START-67)
#define DB2OLEDB_COMM_DEALLOC_NORMAL                (DB2OLEDB_COMM_ERROR_START-68)      /* -580 */
#define DB2OLEDB_COMM_PROG_ERROR_NO_TRUNC           (DB2OLEDB_COMM_ERROR_START-69)
#define DB2OLEDB_COMM_PROG_ERROR_TRUNC              (DB2OLEDB_COMM_ERROR_START-70)
#define DB2OLEDB_COMM_PROG_ERROR_PURGING            (DB2OLEDB_COMM_ERROR_START-71)
#define DB2OLEDB_COMM_CONV_FAILURE_RETRY            (DB2OLEDB_COMM_ERROR_START-72)
#define DB2OLEDB_COMM_CONV_FAILURE_NO_RETRY         (DB2OLEDB_COMM_ERROR_START-73)
#define DB2OLEDB_COMM_SVC_ERROR_NO_TRUNC            (DB2OLEDB_COMM_ERROR_START-74)
#define DB2OLEDB_COMM_SVC_ERROR_TRUNC               (DB2OLEDB_COMM_ERROR_START-75)
#define DB2OLEDB_COMM_SVC_ERROR_PURGING             (DB2OLEDB_COMM_ERROR_START-76)
#define DB2OLEDB_COMM_UNSUCCESSFUL                  (DB2OLEDB_COMM_ERROR_START-77)
#define DB2OLEDB_COMM_CONVERSATION_TYPE_MIXED       (DB2OLEDB_COMM_ERROR_START-78)      /* -590 */
#define DB2OLEDB_COMM_CANCELLED                     (DB2OLEDB_COMM_ERROR_START-79)
#define DB2OLEDB_COMM_SECURITY_REQ_NOT_SUPPORTED    (DB2OLEDB_COMM_ERROR_START-80)
#define DB2OLEDB_COMM_TP_BUSY                       (DB2OLEDB_COMM_ERROR_START-81)      
#define DB2OLEDB_COMM_COMM_SUBSYSTEM_ABENDED        (DB2OLEDB_COMM_ERROR_START-82)      
#define DB2OLEDB_COMM_COMM_SUBSYSTEM_NOT_LOADED     (DB2OLEDB_COMM_ERROR_START-83)      
#define DB2OLEDB_COMM_CONV_BUSY                     (DB2OLEDB_COMM_ERROR_START-84)     
#define DB2OLEDB_COMM_THREAD_BLOCKING               (DB2OLEDB_COMM_ERROR_START-85)     
#define DB2OLEDB_COMM_INVALID_VERB_SEGMENT          (DB2OLEDB_COMM_ERROR_START-86)      
#define DB2OLEDB_COMM_UNEXPECTED_DOS_ERROR          (DB2OLEDB_COMM_ERROR_START-87)      
#define DB2OLEDB_COMM_STACK_TOO_SMALL               (DB2OLEDB_COMM_ERROR_START-88)      /* -600 */
#define DB2OLEDB_COMM_INVALID_VERB                  (DB2OLEDB_COMM_ERROR_START-89)
#define DB2OLEDB_COMM_HOST_NAMERESOLV_FAILED        (DB2OLEDB_COMM_ERROR_START-90)      /* TCP/IP Errors: */
#define DB2OLEDB_COMM_HOST_CONNECT_FAILED           (DB2OLEDB_COMM_ERROR_START-91)
#define DB2OLEDB_COMM_SOCKET_ALLOC_FAILED           (DB2OLEDB_COMM_ERROR_START-92)


#endif
