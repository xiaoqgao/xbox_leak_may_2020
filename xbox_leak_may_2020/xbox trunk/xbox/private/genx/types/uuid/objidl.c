
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0347 */
/* at Sun May 05 19:07:27 2002
 */
/* Compiler settings for objidl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

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

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMarshal,0x00000003,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMarshal2,0x000001cf,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMalloc,0x00000002,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMallocSpy,0x0000001d,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IStdMarshalInfo,0x00000018,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IExternalConnection,0x00000019,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMultiQI,0x00000020,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_AsyncIMultiQI,0x000e0020,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IInternalUnknown,0x00000021,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumUnknown,0x00000100,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IBindCtx,0x0000000e,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumMoniker,0x00000102,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRunnableObject,0x00000126,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRunningObjectTable,0x00000010,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPersist,0x0000010c,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPersistStream,0x00000109,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMoniker,0x0000000f,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IROTData,0xf29f6bc0,0x5021,0x11ce,0xaa,0x15,0x00,0x00,0x69,0x01,0x29,0x3f);


MIDL_DEFINE_GUID(IID, IID_IEnumString,0x00000101,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISequentialStream,0x0c733a30,0x2a1c,0x11ce,0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d);


MIDL_DEFINE_GUID(IID, IID_IStream,0x0000000c,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumSTATSTG,0x0000000d,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IStorage,0x0000000b,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPersistFile,0x0000010b,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPersistStorage,0x0000010a,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ILockBytes,0x0000000a,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumFORMATETC,0x00000103,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumSTATDATA,0x00000105,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRootStorage,0x00000012,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IAdviseSink,0x0000010f,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_AsyncIAdviseSink,0x00000150,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IAdviseSink2,0x00000125,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_AsyncIAdviseSink2,0x00000151,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IDataObject,0x0000010e,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IDataAdviseHolder,0x00000110,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMessageFilter,0x00000016,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRpcChannelBuffer,0xD5F56B60,0x593B,0x101A,0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A);


MIDL_DEFINE_GUID(IID, IID_IRpcChannelBuffer2,0x594f31d0,0x7f19,0x11d0,0xb1,0x94,0x00,0xa0,0xc9,0x0d,0xc8,0xbf);


MIDL_DEFINE_GUID(IID, IID_IAsyncRpcChannelBuffer,0xa5029fb6,0x3c34,0x11d1,0x9c,0x99,0x00,0xc0,0x4f,0xb9,0x98,0xaa);


MIDL_DEFINE_GUID(IID, IID_IRpcChannelBuffer3,0x25B15600,0x0115,0x11d0,0xBF,0x0D,0x00,0xAA,0x00,0xB8,0xDF,0xD2);


MIDL_DEFINE_GUID(IID, IID_IRpcProxyBuffer,0xD5F56A34,0x593B,0x101A,0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A);


MIDL_DEFINE_GUID(IID, IID_IRpcStubBuffer,0xD5F56AFC,0x593B,0x101A,0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A);


MIDL_DEFINE_GUID(IID, IID_IPSFactoryBuffer,0xD5F569D0,0x593B,0x101A,0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A);


MIDL_DEFINE_GUID(IID, IID_IChannelHook,0x1008c4a0,0x7613,0x11cf,0x9a,0xf1,0x00,0x20,0xaf,0x6e,0x72,0xf4);


MIDL_DEFINE_GUID(IID, IID_IClientSecurity,0x0000013D,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IServerSecurity,0x0000013E,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IClassActivator,0x00000140,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRpcOptions,0x00000144,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IFillLockBytes,0x99caf010,0x415e,0x11cf,0x88,0x14,0x00,0xaa,0x00,0xb5,0x69,0xf5);


MIDL_DEFINE_GUID(IID, IID_IProgressNotify,0xa9d758a0,0x4617,0x11cf,0x95,0xfc,0x00,0xaa,0x00,0x68,0x0d,0xb4);


MIDL_DEFINE_GUID(IID, IID_ILayoutStorage,0x0e6d4d90,0x6738,0x11cf,0x96,0x08,0x00,0xaa,0x00,0x68,0x0d,0xb4);


MIDL_DEFINE_GUID(IID, IID_IBlockingLock,0x30f3d47a,0x6447,0x11d1,0x8e,0x3c,0x00,0xc0,0x4f,0xb9,0x38,0x6d);


MIDL_DEFINE_GUID(IID, IID_ITimeAndNoticeControl,0xbc0bf6ae,0x8878,0x11d1,0x83,0xe9,0x00,0xc0,0x4f,0xc2,0xc6,0xd4);


MIDL_DEFINE_GUID(IID, IID_IOplockStorage,0x8d19c834,0x8879,0x11d1,0x83,0xe9,0x00,0xc0,0x4f,0xc2,0xc6,0xd4);


MIDL_DEFINE_GUID(IID, IID_ISurrogate,0x00000022,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IGlobalInterfaceTable,0x00000146,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IDirectWriterLock,0x0e6d4d92,0x6738,0x11cf,0x96,0x08,0x00,0xaa,0x00,0x68,0x0d,0xb4);


MIDL_DEFINE_GUID(IID, IID_ISynchronize,0x00000030,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISynchronizeHandle,0x00000031,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISynchronizeEvent,0x00000032,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISynchronizeContainer,0x00000033,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISynchronizeMutex,0x00000025,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ICancelMethodCalls,0x00000029,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IAsyncManager,0x0000002A,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ICallFactory,0x1c733a30,0x2a1c,0x11ce,0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d);


MIDL_DEFINE_GUID(IID, IID_IRpcHelper,0x00000149,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IReleaseMarshalBuffers,0xeb0cb9e8,0x7996,0x11d2,0x87,0x2e,0x00,0x00,0xf8,0x08,0x08,0x59);


MIDL_DEFINE_GUID(IID, IID_IWaitMultiple,0x0000002B,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IUrlMon,0x00000026,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IForegroundTransfer,0x00000145,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPipeByte,0xDB2F3ACA,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_AsyncIPipeByte,0xDB2F3ACB,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_IPipeLong,0xDB2F3ACC,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_AsyncIPipeLong,0xDB2F3ACD,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_IPipeDouble,0xDB2F3ACE,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_AsyncIPipeDouble,0xDB2F3ACF,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_IThumbnailExtractor,0x969dc708,0x5c76,0x11d1,0x8d,0x86,0x00,0x00,0xf8,0x04,0xb0,0x57);


MIDL_DEFINE_GUID(IID, IID_IDummyHICONIncluder,0x947990de,0xcc28,0x11d2,0xa0,0xf7,0x00,0x80,0x5f,0x85,0x8f,0xb1);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/


#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0347 */
/* at Sun May 05 19:07:27 2002
 */
/* Compiler settings for objidl.idl:
    Oicf, W1, Zp8, env=Win64 (32b run,appending)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AMD64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

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

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMarshal,0x00000003,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMarshal2,0x000001cf,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMalloc,0x00000002,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMallocSpy,0x0000001d,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IStdMarshalInfo,0x00000018,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IExternalConnection,0x00000019,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMultiQI,0x00000020,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_AsyncIMultiQI,0x000e0020,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IInternalUnknown,0x00000021,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumUnknown,0x00000100,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IBindCtx,0x0000000e,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumMoniker,0x00000102,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRunnableObject,0x00000126,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRunningObjectTable,0x00000010,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPersist,0x0000010c,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPersistStream,0x00000109,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMoniker,0x0000000f,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IROTData,0xf29f6bc0,0x5021,0x11ce,0xaa,0x15,0x00,0x00,0x69,0x01,0x29,0x3f);


MIDL_DEFINE_GUID(IID, IID_IEnumString,0x00000101,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISequentialStream,0x0c733a30,0x2a1c,0x11ce,0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d);


MIDL_DEFINE_GUID(IID, IID_IStream,0x0000000c,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumSTATSTG,0x0000000d,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IStorage,0x0000000b,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPersistFile,0x0000010b,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPersistStorage,0x0000010a,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ILockBytes,0x0000000a,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumFORMATETC,0x00000103,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IEnumSTATDATA,0x00000105,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRootStorage,0x00000012,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IAdviseSink,0x0000010f,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_AsyncIAdviseSink,0x00000150,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IAdviseSink2,0x00000125,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_AsyncIAdviseSink2,0x00000151,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IDataObject,0x0000010e,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IDataAdviseHolder,0x00000110,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IMessageFilter,0x00000016,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRpcChannelBuffer,0xD5F56B60,0x593B,0x101A,0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A);


MIDL_DEFINE_GUID(IID, IID_IRpcChannelBuffer2,0x594f31d0,0x7f19,0x11d0,0xb1,0x94,0x00,0xa0,0xc9,0x0d,0xc8,0xbf);


MIDL_DEFINE_GUID(IID, IID_IAsyncRpcChannelBuffer,0xa5029fb6,0x3c34,0x11d1,0x9c,0x99,0x00,0xc0,0x4f,0xb9,0x98,0xaa);


MIDL_DEFINE_GUID(IID, IID_IRpcChannelBuffer3,0x25B15600,0x0115,0x11d0,0xBF,0x0D,0x00,0xAA,0x00,0xB8,0xDF,0xD2);


MIDL_DEFINE_GUID(IID, IID_IRpcProxyBuffer,0xD5F56A34,0x593B,0x101A,0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A);


MIDL_DEFINE_GUID(IID, IID_IRpcStubBuffer,0xD5F56AFC,0x593B,0x101A,0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A);


MIDL_DEFINE_GUID(IID, IID_IPSFactoryBuffer,0xD5F569D0,0x593B,0x101A,0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A);


MIDL_DEFINE_GUID(IID, IID_IChannelHook,0x1008c4a0,0x7613,0x11cf,0x9a,0xf1,0x00,0x20,0xaf,0x6e,0x72,0xf4);


MIDL_DEFINE_GUID(IID, IID_IClientSecurity,0x0000013D,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IServerSecurity,0x0000013E,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IClassActivator,0x00000140,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IRpcOptions,0x00000144,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IFillLockBytes,0x99caf010,0x415e,0x11cf,0x88,0x14,0x00,0xaa,0x00,0xb5,0x69,0xf5);


MIDL_DEFINE_GUID(IID, IID_IProgressNotify,0xa9d758a0,0x4617,0x11cf,0x95,0xfc,0x00,0xaa,0x00,0x68,0x0d,0xb4);


MIDL_DEFINE_GUID(IID, IID_ILayoutStorage,0x0e6d4d90,0x6738,0x11cf,0x96,0x08,0x00,0xaa,0x00,0x68,0x0d,0xb4);


MIDL_DEFINE_GUID(IID, IID_IBlockingLock,0x30f3d47a,0x6447,0x11d1,0x8e,0x3c,0x00,0xc0,0x4f,0xb9,0x38,0x6d);


MIDL_DEFINE_GUID(IID, IID_ITimeAndNoticeControl,0xbc0bf6ae,0x8878,0x11d1,0x83,0xe9,0x00,0xc0,0x4f,0xc2,0xc6,0xd4);


MIDL_DEFINE_GUID(IID, IID_IOplockStorage,0x8d19c834,0x8879,0x11d1,0x83,0xe9,0x00,0xc0,0x4f,0xc2,0xc6,0xd4);


MIDL_DEFINE_GUID(IID, IID_ISurrogate,0x00000022,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IGlobalInterfaceTable,0x00000146,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IDirectWriterLock,0x0e6d4d92,0x6738,0x11cf,0x96,0x08,0x00,0xaa,0x00,0x68,0x0d,0xb4);


MIDL_DEFINE_GUID(IID, IID_ISynchronize,0x00000030,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISynchronizeHandle,0x00000031,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISynchronizeEvent,0x00000032,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISynchronizeContainer,0x00000033,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ISynchronizeMutex,0x00000025,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ICancelMethodCalls,0x00000029,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IAsyncManager,0x0000002A,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_ICallFactory,0x1c733a30,0x2a1c,0x11ce,0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d);


MIDL_DEFINE_GUID(IID, IID_IRpcHelper,0x00000149,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IReleaseMarshalBuffers,0xeb0cb9e8,0x7996,0x11d2,0x87,0x2e,0x00,0x00,0xf8,0x08,0x08,0x59);


MIDL_DEFINE_GUID(IID, IID_IWaitMultiple,0x0000002B,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IUrlMon,0x00000026,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IForegroundTransfer,0x00000145,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);


MIDL_DEFINE_GUID(IID, IID_IPipeByte,0xDB2F3ACA,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_AsyncIPipeByte,0xDB2F3ACB,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_IPipeLong,0xDB2F3ACC,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_AsyncIPipeLong,0xDB2F3ACD,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_IPipeDouble,0xDB2F3ACE,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_AsyncIPipeDouble,0xDB2F3ACF,0x2F86,0x11d1,0x8E,0x04,0x00,0xC0,0x4F,0xB9,0x98,0x9A);


MIDL_DEFINE_GUID(IID, IID_IThumbnailExtractor,0x969dc708,0x5c76,0x11d1,0x8d,0x86,0x00,0x00,0xf8,0x04,0xb0,0x57);


MIDL_DEFINE_GUID(IID, IID_IDummyHICONIncluder,0x947990de,0xcc28,0x11d2,0xa0,0xf7,0x00,0x80,0x5f,0x85,0x8f,0xb1);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

