/////////////////////////////////////////////////////////////////////////////
//	SRCGUID.H
//		Source package interface ids.

//	Interface ID for source package
DEFINE_GUID(IID_ISourceQuery, 
	0xA8A111D0,0x54D7,0x11CE,0xA5,0x55,0x00,0xAA,0x00,0x42,0x54,0xC4);

//	Interface ID for source package editing
DEFINE_GUID(IID_ISourceEdit, 
	0xE831F200,0x54DA,0x11CE,0xA5,0x55,0x00,0xAA,0x00,0x42,0x54,0xC4);

// Interface ID for ParserDataBase {CCE64B71-1F6E-11cf-B24F-00AA0057AFF3}
DEFINE_GUID(IID_IParserDataBase,
	0xcce64b71, 0x1f6e, 0x11cf, 0xb2, 0x4f, 0x0, 0xaa, 0x0, 0x57, 0xaf, 0xf3);

// Interface ID for EditDebugStatus {7161AE01-2901-11cf-B250-00AA0057AFF3}
DEFINE_GUID(IID_IEditDebugStatus, 
	0x7161ae01, 0x2901, 0x11cf, 0xb2, 0x50, 0x0, 0xaa, 0x0, 0x57, 0xaf, 0xf3);

// Interface ID for ParserAssist {90D1AE81-29DC-11cf-B250-00AA0057AFF3}
DEFINE_GUID(IID_IParserAssist, 
	0x90d1ae81, 0x29dc, 0x11cf, 0xb2, 0x50, 0x0, 0xaa, 0x0, 0x57, 0xaf, 0xf3);

// Interface ID for OutputWindow {1A26E5E1-2905-11cf-B250-00AA0057AFF3}
DEFINE_GUID(IID_IOutputWindow, 
	0x1a26e5e1, 0x2905, 0x11cf, 0xb2, 0x50, 0x0, 0xaa, 0x0, 0x57, 0xaf, 0xf3);

// Interface ID for IFileAccess {51CF0451-4F97-11cf-B257-00AA0057AFF3}
DEFINE_GUID(IID_IFileAccess, 
	0x51cf0451, 0x4f97, 0x11cf, 0xb2, 0x57, 0x0, 0xaa, 0x0, 0x57, 0xaf, 0xf3);

// Class ID for text document {3486698D-49EB-11cf-BF46-00AA004C12E2}
DEFINE_GUID(CLSID_TextDoc, // was CLSID_TextDocument
	0x3486698d, 0x49eb, 0x11cf, 0xbf, 0x46, 0x0, 0xaa, 0x0, 0x4c, 0x12, 0xe2);

// Class ID for external text document {EF383AB0-4BF7-11d1-996F-00A0C91BC8E5}
DEFINE_GUID(CLSID_ExtTextDoc, 
0xef383ab0, 0x4bf7, 0x11d1, 0x99, 0x6f, 0x0, 0xa0, 0xc9, 0x1b, 0xc8, 0xe5);

// Class ID for browse document {3486698E-49EB-11cf-BF46-00AA004C12E2}
DEFINE_GUID(CLSID_BrowseDocument, 
	0x3486698e, 0x49eb, 0x11cf, 0xbf, 0x46, 0x0, 0xaa, 0x0, 0x4c, 0x12, 0xe2);

// Interface ID for lang/lexer based custom context menu
DEFINE_GUID(IID_ICustomContextMenu, 
0xe882e260, 0x709c, 0x11cf, 0x89, 0xc0, 0x0, 0xaa, 0x0, 0xbf, 0x5, 0x6);


#ifdef _SQLDBG

// Interface ID for SQL Execution control

DEFINE_GUID(IID_ISqlExec, 
0xfbca3ca2, 0x6abe, 0x11cf, 0x92, 0x81, 0x0, 0xa0, 0xc9, 0x3, 0x49, 0x10);

// Interface ID for debugging

DEFINE_GUID(IID_ISrcDebug, 
0x1c3d3480, 0x6ad9, 0x11cf, 0x92, 0x81, 0x0, 0xa0, 0xc9, 0x3, 0x49, 0x10);

#endif // _SQLDBG
