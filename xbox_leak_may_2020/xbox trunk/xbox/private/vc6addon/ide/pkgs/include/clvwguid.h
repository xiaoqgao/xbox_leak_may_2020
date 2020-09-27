/////////////////////////////////////////////////////////////////////////////
//	CLVWGUID.H
//		ClassView package interface ids.

// Interface ID for Class View
DEFINE_GUID(IID_IClassView, 
	0xee099ce0, 0x9c05, 0x11ce, 0xbb, 0x53, 0x0, 0xaa, 0x0, 0x3d, 0xa7, 0xad);

DEFINE_GUID(IID_IClassProvider, 
	0xca4423c0, 0x2fd0, 0x11cf, 0x81, 0xf2, 0x0, 0xaa, 0x0, 0x6c, 0x1d, 0x8);

DEFINE_GUID(IID_IClassProviderFactory, 
	0xddcf7f20, 0x2fd0, 0x11cf, 0x81, 0xf2, 0x0, 0xaa, 0x0, 0x6c, 0x1d, 0x8);

DEFINE_GUID(IID_IWizardNode,
	0xa7d23560, 0x5d01, 0x11cf, 0xb1, 0x1b, 0x0, 0xaa, 0x0, 0x6c, 0x28, 0xb3);

DEFINE_GUID(IID_IWizardStrings, 
	0xc1925605, 0xdf6a, 0x11cf, 0xa8, 0xe7, 0x0, 0xa0, 0xc9, 0x15, 0x7, 0xc);

DEFINE_GUID(IID_IWizardBar, 
0x1909ad40, 0x5fce, 0x11cf, 0xb4, 0x15, 0x0, 0xaa, 0x0, 0xa4, 0x80, 0x1a);

DEFINE_GUID(IID_IWizBarClntLang, 
0xcc552ba2, 0xa29e, 0x11cf, 0xb4, 0x15, 0x0, 0xaa, 0x0, 0xa4, 0x80, 0x1a);

DEFINE_GUID(IID_IWizBarClntEditor, 
0xcc552ba1, 0xa29e, 0x11cf, 0xb4, 0x15, 0x0, 0xaa, 0x0, 0xa4, 0x80, 0x1a);

// guid for collection of wiz bar client editor interfaces
DEFINE_GUID(IID_IWizBarClntEditors, 
0x42d8fdc0, 0xb946, 0x11cf, 0xb4, 0x15, 0x0, 0xaa, 0x0, 0xa4, 0x80, 0x1a);

// guid for provider of wiz bar client language interface
DEFINE_GUID(IID_IWizBarClntLangProvider, 
0x92a40220, 0xde47, 0x11cf, 0xb4, 0x15, 0x0, 0xaa, 0x0, 0xa4, 0x80, 0x1a);
