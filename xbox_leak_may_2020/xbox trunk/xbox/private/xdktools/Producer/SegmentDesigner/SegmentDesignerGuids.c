// SegmentDesignerGuids.c : Contains GUIDs not found in MIDL generated SegmentDesigner_i.c
//

#ifdef __cplusplus
extern "C"{
#endif 

#ifndef GUID_DEFINED
#define GUID_DEFINED

typedef struct _GUID
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;

#endif /* GUID_DEFINED */


	const GUID GUID_SegmentNode = { 0xdfce8609, 0xa6fa, 0x11d1, { 0x88, 0x81, 0x0, 0xc0, 0x4f, 0xbf, 0x8d, 0x15 } };

	const GUID GUID_SegmentRefNode = { 0xdfce860a, 0xa6fa, 0x11d1, { 0x88, 0x81, 0x0, 0xc0, 0x4f, 0xbf, 0x8d, 0x15 } };

	const GUID CLSID_SegmentComponent = { 0xdfce860b, 0xa6fa, 0x11d1, { 0x88, 0x81, 0x0, 0xc0, 0x4f, 0xbf, 0x8d, 0x15 } };

	const GUID CLSID_UnknownStripMgr = { 0x853baf7b, 0xd3c8, 0x11d1, { 0x88, 0xbc, 0x0, 0xc0, 0x4f, 0xbf, 0x8d, 0x15 } };

#ifdef __cplusplus
}
#endif

