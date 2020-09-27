// --attrname.h----------------------------------------------------------------- 
// 
// Names of directory attributes. 
// 
// Copyright 1986 - 1998 Microsoft Corporation. All Rights Reserved. 
// ----------------------------------------------------------------------------- 

#ifndef _ATTRNAME_H 
#define _ATTRNAME_H 

#define PS_EXCHANGE_DIRECTORY \
    "\x08\x2A\x86\x48\x86\xF7\x14\x01\x02\x00\x00\x00\x00\x00\x00\x00"

#define NM_ACCESS_CATEGORY                       0x0001000CU
#define NM_ACTIVATION_SCHEDULE                   0x00025581U
#define NM_ACTIVATION_STYLE                      0x00010049U
#define NM_ADDRESS                               0x00020082U
#define NM_ADDRESS_ENTRY_DISPLAY_TABLE           0x00024482U
#define NM_ADDRESS_ENTRY_DISPLAY_TABLE_MSDOS     0x00021083U
#define NM_ADDRESS_SYNTAX                        0x00027F81U
#define NM_ADDRESS_TYPE                          0x00025E82U
#define NM_ADMD                                  0x00026881U
#define NM_ADMIN_DESCRIPTION                     0x00026281U
#define NM_ADMIN_DISPLAY_NAME                    0x00024281U
#define NM_ADMIN_EXTENSION_DLL                   0x0001005FU
#define NM_ALT_RECIPIENT                         0x0001007EU
#define NM_ALT_RECIPIENT_BL                      0x00022682U
#define NM_ANCESTOR_ID                           0x00020582U
#define NM_ASSISTANT_NAME                        0x00023C83U
#define NM_ASSOC_NT_ACCOUNT                      0x00025481U
#define NM_ASSOC_REMOTE_DXA                      0x00022B82U
#define NM_ASSOCIATION_LIFETIME                  0x00021581U
#define NM_ATTRIBUTE_ID                          0x0001001EU
#define NM_ATTRIBUTE_SYNTAX                      0x00010020U
#define NM_AUTH_ORIG                             0x00020181U
#define NM_AUTH_ORIG_BL                          0x00022282U
#define NM_AUTHORIZED_DOMAIN                     0x00024A81U
#define NM_AUTHORIZED_PASSWORD                   0x00024181U
#define NM_AUTHORIZED_USER                       0x00021482U
#define NM_AUTOREPLY                             0x00021E82U
#define NM_AUTOREPLY_MESSAGE                     0x00021F82U
#define NM_AUTOREPLY_SUBJECT                     0x00023A83U
#define NM_AUXILIARY_CLASS                       0x00025F82U
#define NM_BRIDGEHEAD_SERVERS                    0x00024F83U
#define NM_BUSINESS_ROLES                        0x00010069U
#define NM_CAN_CREATE_PF                         0x0001000BU
#define NM_CAN_CREATE_PF_BL                      0x00025382U
#define NM_CAN_CREATE_PF_DL                      0x0001003EU
#define NM_CAN_CREATE_PF_DL_BL                   0x00025482U
#define NM_CAN_NOT_CREATE_PF                     0x0001003FU
#define NM_CAN_NOT_CREATE_PF_BL                  0x00025582U
#define NM_CAN_NOT_CREATE_PF_DL                  0x00022C82U
#define NM_CAN_NOT_CREATE_PF_DL_BL               0x00025682U
#define NM_CAN_PRESERVE_DNS                      0x00024783U
#define NM_CLOCK_ALERT_OFFSET                    0x00022581U
#define NM_CLOCK_ALERT_REPAIR                    0x00022481U
#define NM_CLOCK_WARNING_OFFSET                  0x00023181U
#define NM_CLOCK_WARNING_REPAIR                  0x00022681U
#define NM_COMMENT                               0x00010051U
#define NM_COMPANY                               0x00021281U
#define NM_COMPUTER_NAME                         0x00010014U
#define NM_CONNECTED_DOMAINS                     0x00025381U
#define NM_CONTAINER_INFO                        0x00022882U
#define NM_COST                                  0x00020781U
#define NM_DELIV_CONT_LENGTH                     0x00020A81U
#define NM_DELIV_EITS                            0x00020B81U
#define NM_DELIV_EXT_CONT_TYPES                  0x00020C81U
#define NM_DELIVER_AND_REDIRECT                  0x00023E81U
#define NM_DELIVERY_MECHANISM                    0x00027181U
#define NM_DEPARTMENT                            0x00020D81U
#define NM_DIAGNOSTIC_REG_KEY                    0x00023D81U
#define NM_DISPLAY_NAME                          0x0001000DU
#define NM_DISPLAY_NAME_OVERRIDE                 0x00024082U
#define NM_DISPLAY_NAME_PRINTABLE                0x00026182U
#define NM_DL_MEM_REJECT_PERMS                   0x0001002FU
#define NM_DL_MEM_REJECT_PERMS_BL                0x00022582U
#define NM_DL_MEM_SUBMIT_PERMS                   0x00021081U
#define NM_DL_MEM_SUBMIT_PERMS_BL                0x00022382U
#define NM_DL_MEMBER_RULE                        0x00024A82U
#define NM_DMD_LOCATION                          0x00010024U
#define NM_DOMAIN_DEF_ALT_RECIP                  0x00021181U
#define NM_DOMAIN_NAME                           0x00021381U
#define NM_DSA_SIGNATURE                         0x0001004AU
#define NM_DXA_ADMIN_COPY                        0x00027A82U
#define NM_DXA_ADMIN_FORWARD                     0x00027B82U
#define NM_DXA_ADMIN_UPDATE                      0x00027D82U
#define NM_DXA_APPEND_REQCN                      0x00022E81U
#define NM_DXA_CONF_CONTAINER_LIST               0x00023481U
#define NM_DXA_CONF_REQ_TIME                     0x0001007AU
#define NM_DXA_CONF_SEQ                          0x00023881U
#define NM_DXA_CONF_SEQ_USN                      0x0001002DU
#define NM_DXA_EXCHANGE_OPTIONS                  0x00026782U
#define NM_DXA_EXPORT_NOW                        0x00027982U
#define NM_DXA_FLAGS                             0x0001006AU
#define NM_DXA_IMP_SEQ                           0x00010074U
#define NM_DXA_IMP_SEQ_TIME                      0x00010075U
#define NM_DXA_IMP_SEQ_USN                       0x00010056U
#define NM_DXA_IMPORT_NOW                        0x00027882U
#define NM_DXA_IN_TEMPLATE_MAP                   0x00026B82U
#define NM_DXA_LOCAL_ADMIN                       0x00010071U
#define NM_DXA_LOGGING_LEVEL                     0x00027E82U
#define NM_DXA_NATIVE_ADDRESS_TYPE               0x00024B82U
#define NM_DXA_OUT_TEMPLATE_MAP                  0x00026C82U
#define NM_DXA_PASSWORD                          0x00023182U
#define NM_DXA_PREV_EXCHANGE_OPTIONS             0x00025881U
#define NM_DXA_PREV_EXPORT_NATIVE_ONLY           0x00024B81U
#define NM_DXA_PREV_IN_EXCHANGE_SENSITIVITY      0x0001005AU
#define NM_DXA_PREV_REMOTE_ENTRIES               0x00020982U
#define NM_DXA_PREV_REPLICATION_SENSITIVITY      0x00025781U
#define NM_DXA_PREV_TEMPLATE_OPTIONS             0x00020B83U
#define NM_DXA_PREV_TYPES                        0x00025981U
#define NM_DXA_RECIPIENT_CP                      0x00020083U
#define NM_DXA_REMOTE_CLIENT                     0x00010070U
#define NM_DXA_REQ_SEQ                           0x00010065U
#define NM_DXA_REQ_SEQ_TIME                      0x00010072U
#define NM_DXA_REQ_SEQ_USN                       0x00023681U
#define NM_DXA_REQNAME                           0x00023E83U
#define NM_DXA_SVR_SEQ                           0x00026882U
#define NM_DXA_SVR_SEQ_TIME                      0x00026982U
#define NM_DXA_SVR_SEQ_USN                       0x0001007CU
#define NM_DXA_TASK                              0x00010064U
#define NM_DXA_TEMPLATE_OPTIONS                  0x00026682U
#define NM_DXA_TEMPLATE_TIMESTAMP                0x00026D82U
#define NM_DXA_TYPES                             0x00010077U
#define NM_DXA_UNCONF_CONTAINER_LIST             0x00023581U
#define NM_ENABLED_PROTOCOLS                     0x00025A83U
#define NM_ENCAPSULATION_METHOD                  0x00024083U
#define NM_ENCRYPT                               0x00026C81U
#define NM_ENCRYPT_ALG_LIST_NA                   0x00020281U
#define NM_ENCRYPT_ALG_LIST_OTHER                0x00020F83U
#define NM_ENCRYPT_ALG_SELECTED_NA               0x00021183U
#define NM_ENCRYPT_ALG_SELECTED_OTHER            0x00020D83U
#define NM_EXPAND_DLS_LOCALLY                    0x00024981U
#define NM_EXPIRATION_TIME                       0x00020A83U
#define NM_EXPORT_CONTAINERS                     0x0001006FU
#define NM_EXPORT_CUSTOM_RECIPIENTS              0x00023382U
#define NM_EXTENDED_CHARS_ALLOWED                0x00027C82U
#define NM_EXTENSION_ATTRIBUTE_1                 0x00022783U
#define NM_EXTENSION_ATTRIBUTE_10                0x00023083U
#define NM_EXTENSION_ATTRIBUTE_2                 0x00022883U
#define NM_EXTENSION_ATTRIBUTE_3                 0x00022983U
#define NM_EXTENSION_ATTRIBUTE_4                 0x00022A83U
#define NM_EXTENSION_ATTRIBUTE_5                 0x00022B83U
#define NM_EXTENSION_ATTRIBUTE_6                 0x00022C83U
#define NM_EXTENSION_ATTRIBUTE_7                 0x00022D83U
#define NM_EXTENSION_ATTRIBUTE_8                 0x00022E83U
#define NM_EXTENSION_ATTRIBUTE_9                 0x00022F83U
#define NM_EXTENSION_DATA                        0x00026481U
#define NM_EXTENSION_NAME                        0x00026381U
#define NM_EXTENSION_NAME_INHERITED              0x00010061U
#define NM_FILE_VERSION                          0x00023281U
#define NM_FILTER_LOCAL_ADDRESSES                0x0001002CU
#define NM_FOLDER_PATHNAME                       0x00025182U
#define NM_FOLDERS_CONTAINER                     0x00026B81U
#define NM_FOREIGN_DSAS                          0x00010044U
#define NM_GARBAGE_COLL_PERIOD                   0x00022D82U
#define NM_GATEWAY_LOCAL_CRED                    0x00010025U
#define NM_GATEWAY_LOCAL_DESIG                   0x0001001DU
#define NM_GATEWAY_PROXY                         0x00022E82U
#define NM_GATEWAY_ROUTING_TREE                  0x00022781U
#define NM_GIVEN_NAME                            0x00010029U
#define NM_GOVERNS_ID                            0x00010016U
#define NM_GWART_LAST_MODIFIED                   0x00020482U
#define NM_HAS_FULL_REPLICA_NCS                  0x0001000FU
#define NM_HAS_MASTER_NCS                        0x0001000EU
#define NM_HELP_DATA16                           0x00021283U
#define NM_HELP_DATA32                           0x00010009U
#define NM_HELP_FILE_NAME                        0x00024782U
#define NM_HEURISTICS                            0x00024483U
#define NM_HIDE_DL_MEMBERSHIP                    0x00022982U
#define NM_HIDE_FROM_ADDRESS_BOOK                0x00022981U
#define NM_HOME_MDB                              0x00027481U
#define NM_HOME_MDB_BL                           0x00020983U
#define NM_HOME_MTA                              0x00022B81U
#define NM_HOME_PUBLIC_SERVER                    0x00023983U
#define NM_IMPORT_CONTAINER                      0x0001006EU
#define NM_IMPORT_SENSITIVITY                    0x00027F82U
#define NM_IMPORTED_FROM                         0x00020782U
#define NM_INBOUND_SITES                         0x00010047U
#define NM_INITIALS                              0x00020E83U
#define NM_INSTANCE_TYPE                         0x00010001U
#define NM_INVOCATION_ID                         0x00010073U
#define NM_IS_DELETED                            0x00010030U
#define NM_IS_MEMBER_OF_DL                       0x00010066U
#define NM_IS_SINGLE_VALUED                      0x00010021U
#define NM_KCC_STATUS                            0x00026D81U
#define NM_KM_SERVER                             0x00023883U
#define NM_LANGUAGE                              0x00025383U
#define NM_LDAP_DISPLAY_NAME                     0x00024C83U
#define NM_LINE_WRAP                             0x00024183U
#define NM_LINK_ID                               0x00010032U
#define NM_LOCAL_BRIDGE_HEAD                     0x00023782U
#define NM_LOCAL_BRIDGE_HEAD_ADDRESS             0x00026181U
#define NM_LOCAL_INITIAL_TURN                    0x00010027U
#define NM_LOCAL_SCOPE                           0x00010011U
#define NM_LOG_FILENAME                          0x00024081U
#define NM_LOG_ROLLOVER_INTERVAL                 0x00025C82U
#define NM_MAIL_NICKNAME                         0x00023F83U
#define NM_MAINTAIN_AUTOREPLY_HISTORY            0x00025181U
#define NM_MANAGER                               0x00024F82U
#define NM_MAPI_DISPLAY_TYPE                     0x00010037U
#define NM_MAPI_ID                               0x00010031U
#define NM_MAPI_RECIPIENT                        0x00027382U
#define NM_MASTER_DSA                            0x00010006U
#define NM_MAXIMUM_OBJECT_ID                     0x00024A83U
#define NM_MAY_CONTAIN                           0x00010019U
#define NM_MDB_BACKOFF_INTERVAL                  0x00010048U
#define NM_MDB_MSG_TIME_OUT_PERIOD               0x00010040U
#define NM_MDB_OVER_QUOTA_LIMIT                  0x00021082U
#define NM_MDB_STORAGE_QUOTA                     0x00020A82U
#define NM_MDB_UNREAD_LIMIT                      0x00010045U
#define NM_MDB_USE_DEFAULTS                      0x00023582U
#define NM_MESSAGE_TRACKING_ENABLED              0x00024583U
#define NM_MONITOR_CLOCK                         0x00022381U
#define NM_MONITOR_SERVERS                       0x00021C81U
#define NM_MONITOR_SERVICES                      0x00022081U
#define NM_MONITORED_CONFIGURATIONS              0x00024681U
#define NM_MONITORED_SERVERS                     0x00023381U
#define NM_MONITORED_SERVICES                    0x00024781U
#define NM_MONITORING_ALERT_DELAY                0x00021E81U
#define NM_MONITORING_ALERT_UNITS                0x00010039U
#define NM_MONITORING_AVAILABILITY_STYLE         0x00024283U
#define NM_MONITORING_AVAILABILITY_WINDOW        0x00024881U
#define NM_MONITORING_CACHED_VIA_MAIL            0x00024481U
#define NM_MONITORING_CACHED_VIA_RPC             0x00024581U
#define NM_MONITORING_ESCALATION_PROCEDURE       0x00023C81U
#define NM_MONITORING_HOTSITE_POLL_INTERVAL      0x00023A81U
#define NM_MONITORING_HOTSITE_POLL_UNITS         0x00010057U
#define NM_MONITORING_MAIL_UPDATE_INTERVAL       0x00024381U
#define NM_MONITORING_MAIL_UPDATE_UNITS          0x0001005DU
#define NM_MONITORING_NORMAL_POLL_INTERVAL       0x00023B81U
#define NM_MONITORING_NORMAL_POLL_UNITS          0x00010058U
#define NM_MONITORING_RECIPIENTS                 0x00021F81U
#define NM_MONITORING_RECIPIENTS_NDR             0x00020383U
#define NM_MONITORING_RPC_UPDATE_INTERVAL        0x0001005CU
#define NM_MONITORING_RPC_UPDATE_UNITS           0x00010059U
#define NM_MONITORING_WARNING_DELAY              0x00021D81U
#define NM_MONITORING_WARNING_UNITS              0x00010038U
#define NM_MTA_LOCAL_CRED                        0x00020E82U
#define NM_MTA_LOCAL_DESIG                       0x00020F82U
#define NM_MUST_CONTAIN                          0x00010018U
#define NM_N_ADDRESS                             0x00021A82U
#define NM_N_ADDRESS_TYPE                        0x00025E81U
#define NM_NETWORK_ADDRESS                       0x00024B83U
#define NM_NNTP_CHARACTER_SET                    0x00025883U
#define NM_NNTP_CONTENT_FORMAT                   0x00025183U
#define NM_NT_MACHINE_NAME                       0x00024683U
#define NM_NT_SECURITY_DESCRIPTOR                0x00021982U
#define NM_NUM_OF_OPEN_RETRIES                   0x00021481U
#define NM_NUM_OF_TRANSFER_RETRIES               0x00020681U
#define NM_OBJ_DIST_NAME                         0x00010033U
#define NM_OBJECT_CLASS_CATEGORY                 0x00027282U
#define NM_OBJECT_VERSION                        0x0001004CU
#define NM_OFF_LINE_AB_CONTAINERS                0x00020783U
#define NM_OFF_LINE_AB_SCHEDULE                  0x00020583U
#define NM_OFF_LINE_AB_SERVER                    0x00020883U
#define NM_OFF_LINE_AB_STYLE                     0x00020683U
#define NM_OID_TYPE                              0x00024282U
#define NM_OM_OBJECT_CLASS                       0x00025A81U
#define NM_OM_SYNTAX                             0x00026781U
#define NM_OOF_REPLY_TO_ORIGINATOR               0x00023683U
#define NM_OPEN_RETRY_INTERVAL                   0x00020F81U
#define NM_ORIGINAL_DISPLAY_TABLE                0x00023D83U
#define NM_ORIGINAL_DISPLAY_TABLE_MSDOS          0x00025681U
#define NM_OUTBOUND_SITES                        0x00010000U
#define NM_OWNER_BL                              0x00010068U
#define NM_P_SELECTOR                            0x00021D82U
#define NM_P_SELECTOR_INBOUND                    0x00010034U
#define NM_PER_MSG_DIALOG_DISPLAY_TABLE          0x00024582U
#define NM_PER_RECIP_DIALOG_DISPLAY_TABLE        0x00024682U
#define NM_PERIOD_REP_SYNC_TIMES                 0x00020C82U
#define NM_PERIOD_REPL_STAGGER                   0x00020882U
#define NM_PF_CONTACTS                           0x0001004BU
#define NM_POP_CHARACTER_SET                     0x00025483U
#define NM_POP_CONTENT_FORMAT                    0x00025283U
#define NM_POSS_SUPERIORS                        0x00010008U
#define NM_PRMD                                  0x00026081U
#define NM_PROXY_ADDRESSES                       0x00025281U
#define NM_PROXY_GENERATOR_DLL                   0x00024882U
#define NM_PUBLIC_DELEGATES                      0x00026E81U
#define NM_PUBLIC_DELEGATES_BL                   0x00022782U
#define NM_QUOTA_NOTIFICATION_SCHEDULE           0x00010062U
#define NM_QUOTA_NOTIFICATION_STYLE              0x00020483U
#define NM_RANGE_LOWER                           0x00010022U
#define NM_RANGE_UPPER                           0x00010023U
#define NM_RAS_CALLBACK_NUMBER                   0x00023B82U
#define NM_RAS_PHONE_NUMBER                      0x00023A82U
#define NM_RAS_PHONEBOOK_ENTRY_NAME              0x00023982U
#define NM_RAS_REMOTE_SRVR_NAME                  0x0001004EU
#define NM_RDN_ATT_ID                            0x0001001AU
#define NM_REF_FULL_REPLICAS                     0x00010041U
#define NM_REF_MASTER_DSA                        0x00010042U
#define NM_REMOTE_BRIDGE_HEAD                    0x00023F81U
#define NM_REMOTE_BRIDGE_HEAD_ADDRESS            0x0001005EU
#define NM_REMOTE_OUT_BH_SERVER                  0x00023682U
#define NM_REMOTE_SITE                           0x0001001BU
#define NM_REPLICATION_MAIL_MSG_SIZE             0x00010067U
#define NM_REPLICATION_SENSITIVITY               0x00025F81U
#define NM_REPLICATION_STAGGER                   0x00025D82U
#define NM_REPORT_TO_ORIGINATOR                  0x00024E81U
#define NM_REPORT_TO_OWNER                       0x00024F81U
#define NM_REPORTS                               0x00023483U
#define NM_REPS_FROM                             0x0001005BU
#define NM_REPS_TO                               0x00010053U
#define NM_REPS_TO_EXT                           0x0001002BU
#define NM_REQ_SEQ                               0x00022D81U
#define NM_RESPONSIBLE_LOCAL_DXA                 0x00022A82U
#define NM_RID_SERVER                            0x00025A82U
#define NM_ROUTING_LIST                          0x00026282U
#define NM_RTS_CHECKPOINT_SIZE                   0x00021881U
#define NM_RTS_RECOVERY_TIMEOUT                  0x00021781U
#define NM_RTS_WINDOW_SIZE                       0x00021981U
#define NM_RUNS_ON                               0x00023981U
#define NM_S_SELECTOR                            0x00021C82U
#define NM_S_SELECTOR_INBOUND                    0x0001002EU
#define NM_SCHEMA_FLAGS                          0x00024E83U
#define NM_SCHEMA_VERSION                        0x00025783U
#define NM_SEARCH_FLAGS                          0x00024E82U
#define NM_SECURITY_PROTOCOL                     0x00010052U
#define NM_SERVICE_ACTION_FIRST                  0x00022181U
#define NM_SERVICE_ACTION_OTHER                  0x0001003BU
#define NM_SERVICE_ACTION_SECOND                 0x0001003CU
#define NM_SERVICE_RESTART_DELAY                 0x00022281U
#define NM_SERVICE_RESTART_MESSAGE               0x0001003AU
#define NM_SESSION_DISCONNECT_TIMER              0x00021A81U
#define NM_SITE_AFFINITY                         0x00023283U
#define NM_SITE_FOLDER_GUID                      0x00024883U
#define NM_SITE_FOLDER_SERVER                    0x00024983U
#define NM_SITE_PROXY_SPACE                      0x00020183U
#define NM_SPACE_LAST_COMPUTED                   0x00020283U
#define NM_SUB_CLASS_OF                          0x00010015U
#define NM_SUB_REFS                              0x00010007U
#define NM_SUB_SITE                              0x00025683U
#define NM_SUBMISSION_CONT_LENGTH                0x00021882U
#define NM_SUPPORTING_STACK                      0x0001001CU
#define NM_SUPPORTING_STACK_BL                   0x00026582U
#define NM_T_SELECTOR                            0x00021B82U
#define NM_T_SELECTOR_INBOUND                    0x00010005U
#define NM_TARGET_ADDRESS                        0x00026082U
#define NM_TARGET_MTAS                           0x00020382U
#define NM_TELEPHONE_ASSISTANT                   0x0001004FU
#define NM_TELEPHONE_FAX                         0x0001002AU
#define NM_TELEPHONE_HOME                        0x0001004DU
#define NM_TELEPHONE_HOME2                       0x00021582U
#define NM_TELEPHONE_MOBILE                      0x00010004U
#define NM_TELEPHONE_OFFICE1                     0x00010076U
#define NM_TELEPHONE_OFFICE2                     0x00010012U
#define NM_TELEPHONE_PAGER                       0x00020682U
#define NM_TEMP_ASSOC_THRESHOLD                  0x00024982U
#define NM_TEXT_COUNTRY                          0x00020381U
#define NM_TOMBSTONE_LIFETIME                    0x00010036U
#define NM_TRACKING_LOG_PATH_NAME                0x00025B82U
#define NM_TRANS_RETRY_MINS                      0x00025B81U
#define NM_TRANS_TIMEOUT_MINS                    0x00025C81U
#define NM_TRANSFER_RETRY_INTERVAL               0x00020581U
#define NM_TRANSFER_TIMEOUT_NON_URGENT           0x00020881U
#define NM_TRANSFER_TIMEOUT_NORMAL               0x00020981U
#define NM_TRANSFER_TIMEOUT_URGENT               0x00020E81U
#define NM_TRANSLATION_TABLE_USED                0x00020C83U
#define NM_TRANSPORT_EXPEDITED_DATA              0x00021681U
#define NM_TRUST_LEVEL                           0x00010046U
#define NM_TURN_REQUEST_THRESHOLD                0x00010026U
#define NM_TWO_WAY_ALTERNATE_FACILITY            0x00010028U
#define NM_UNAUTH_ORIG                           0x00025D81U
#define NM_UNAUTH_ORIG_BL                        0x00022482U
#define NM_USE_SERVER_VALUES                     0x00025983U
#define NM_USN_CHANGED                           0x00010078U
#define NM_USN_CREATED                           0x00010013U
#define NM_USN_DSA_LAST_OBJ_REMOVED              0x00020B82U
#define NM_USN_INTERSITE                         0x00025583U
#define NM_USN_LAST_OBJ_REM                      0x00010079U
#define NM_USN_SOURCE                            0x00027682U
#define NM_WHEN_CHANGED                          0x00010003U
#define NM_WHEN_CREATED                          0x00010002U
#define NM_WWW_HOME_PAGE                         0x00025083U
#define NM_X25_CALL_USER_DATA_INCOMING           0x00023C82U
#define NM_X25_CALL_USER_DATA_OUTGOING           0x00023D82U
#define NM_X25_FACILITIES_DATA_INCOMING          0x00023E82U
#define NM_X25_FACILITIES_DATA_OUTGOING          0x00023F82U
#define NM_X25_LEASED_LINE_PORT                  0x00024182U
#define NM_X25_LEASED_OR_SWITCHED                0x00027482U
#define NM_X25_REMOTE_MTA_PHONE                  0x00027582U
#define NM_X400_ATTACHMENT_TYPE                  0x00010063U
#define NM_X400_SELECTOR_SYNTAX                  0x00023B83U
#define NM_X500_ACCESS_CONTROL_LIST              0x00023183U
#define NM_X509_CERT                             0x00024D83U
#define NM_XMIT_TIMEOUT_NON_URGENT               0x00010054U
#define NM_XMIT_TIMEOUT_NORMAL                   0x00010043U
#define NM_XMIT_TIMEOUT_URGENT                   0x00010035U

#define PS_BASIC_DIRECTORY \
    "\x02\x55\x4\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"

#define NM_ALIASED_OBJECT_NAME                   0x00010001U
#define NM_BUSINESS_CATEGORY                     0x0001000FU
#define NM_COMMON_NAME                           0x00010003U
#define NM_COUNTRY_NAME                          0x00010006U
#define NM_DESCRIPTION                           0x0001000DU
#define NM_DEST_INDICATOR                        0x0001001BU
#define NM_FACSIMILE_PHONE_NBR                   0x00010017U
#define NM_INTERNAT_ISDN_NBR                     0x00010019U
#define NM_KNOWLEDGE_INFO                        0x00010002U
#define NM_LOCALITY_NAME                         0x00010007U
#define NM_MEMBER                                0x0001001FU
#define NM_OBJECT_CLASS                          0x00010000U
#define NM_ORG_NAME                              0x0001000AU
#define NM_ORG_UNIT_NAME                         0x0001000BU
#define NM_OWNER                                 0x00010020U
#define NM_PHYS_DELIV_OFF_NAME                   0x00010013U
#define NM_POST_OFFICE_BOX                       0x00010012U
#define NM_POSTAL_ADDRESS                        0x00010010U
#define NM_POSTAL_CODE                           0x00010011U
#define NM_PREF_DELIV_METHOD                     0x0001001CU
#define NM_PRESENTATION_ADDRESS                  0x0001001DU
#define NM_REGISTERED_ADDRESS                    0x0001001AU
#define NM_ROLE_OCCUPANT                         0x00010021U
#define NM_SEARCH_GUIDE                          0x0001000EU
#define NM_SEE_ALSO                              0x00010022U
#define NM_SERIAL_NBR                            0x00010005U
#define NM_STATE_OR_PROV_NAME                    0x00010008U
#define NM_STREET_ADDRESS                        0x00010009U
#define NM_SUPPORT_APPL_CONTEXT                  0x0001001EU
#define NM_SURNAME                               0x00010004U
#define NM_PHONE_NBR                             0x00010014U
#define NM_TELETEX_TERM_IDENT                    0x00010016U
#define NM_TELEX_NBR                             0x00010015U
#define NM_TITLE                                 0x0001000CU
#define NM_USER_PASSWORD                         0x00010023U
#define NM_X121_ADDRESS                          0x00010018U

#define PS_SECURITY_DIRECTORY \
    "\x02\x55\x4\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"

#define NM_AUTHORITY_REVOC_LIST                  0x00010026U
#define NM_CA_CERT                               0x00010025U
#define NM_CERT_REVOC_LIST                       0x00010027U
#define NM_CROSS_CERT_PAIR                       0x00010028U
#define NM_USER_CERT                             0x00010024U

#endif 
