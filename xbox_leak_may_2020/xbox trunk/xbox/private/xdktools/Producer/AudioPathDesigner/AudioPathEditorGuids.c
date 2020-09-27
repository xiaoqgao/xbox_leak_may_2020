// StyleEditorGuids.c : Contains GUIDs not found in MIDL generated StyleEditor_i.c
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

const GUID CLSID_AudioPathComponent = { 0x4adc2ad, 0x7ea5, 0x4260, { 0xa4, 0x5b, 0x75, 0xa6, 0xef, 0x85, 0x6e, 0x99 } };

const GUID GUID_AudioPathNode = { 0x2a2620e2, 0x2622, 0x4c12, { 0xaa, 0x77, 0xb3, 0xf3, 0x43, 0xd3, 0x3a, 0xa0 } };
const GUID GUID_AudioPathRefNode = { 0xa9ecf224, 0x7863, 0x4f41, { 0xaa, 0xc1, 0x22, 0x1a, 0x85, 0x6e, 0xee, 0x22 } };

const GUID AUDIOPATH_NameChange = { 0xc662f3ad, 0x423a, 0x417a, { 0xb8, 0xcc, 0x68, 0xa7, 0x46, 0x82, 0x84, 0x8e } };

#ifdef __cplusplus
}
#endif

