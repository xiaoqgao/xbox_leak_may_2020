#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IDMUSProdTimelineDataObject = {0xD7D8A772,0x3171,0x11d2,{0x89,0x00,0x00,0xC0,0x4F,0xBF,0x8D,0x15}};

const IID IID_IDMUSProdTimeline = {0x22B5869D,0x523E,0x11d2,{0x89,0x13,0x00,0xC0,0x4F,0xBF,0x8D,0x15}};

const CLSID CLSID_TimelineCtl = {0xDB838A7C,0xB4F5,0x11D0,{0xA9,0x7F,0x00,0xA0,0xC9,0x22,0xE6,0xEB}};

const IID IID_IDMUSProdTimelineCallback = {0x8FE7E6D5,0xF331,0x11d0,{0xBC,0x09,0x00,0xA0,0xC9,0x22,0xE6,0xEB}};

const IID IID_IDMUSProdTimelineEdit = {0x8640F4B2,0x2B01,0x11d2,{0x88,0xF9,0x00,0xC0,0x4F,0xBF,0x8D,0x15}};

const IID IID_IDMUSProdStrip = {0x893EE17A,0x04A3,0x11d3,{0x89,0x4C,0x00,0xC0,0x4F,0xBF,0x8D,0x15}};

const IID IID_IDMUSProdStripFunctionBar = {0x86D596CC,0xB302,0x11d1,{0x88,0x8F,0x00,0xC0,0x4F,0xBF,0x8D,0x15}};

const IID IID_IDMUSProdStripMgr = {0x893EE17B,0x04A3,0x11d3,{0x89,0x4C,0x00,0xC0,0x4F,0xBF,0x8D,0x15}};


#ifdef __cplusplus
}
#endif

