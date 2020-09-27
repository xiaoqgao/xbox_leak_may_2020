#include "bldsetup.h"

#include "wmadecS_api.h"
#include "macros.h"
#include "msaudio.h"
#include "msaudiodec.h"

typedef struct WMARawDecStruct
{
    CAudioObjectDecoder *pAudDecoder;
} WMARawDecStruct;

//#define WMAMEM_SIZE 27280 // for high bitrate
//#define WMAMEM_SIZE 27840 // for all rates
//U8_WMARawDec rgWMAMem [WMAMEM_SIZE];

WMARESULT WMARawDecInit (
    WMARawDecHandle* phWMARawDec,
    U32_WMARawDec dwUserData,
    U16_WMARawDec iVersionNumber,
    U16_WMARawDec cSamplesPerBlock, 
    U16_WMARawDec cSamplesPerSecond, 
    U16_WMARawDec cChannel, 
    U16_WMARawDec cBytePerSec, 
    U16_WMARawDec cPacketLength,
    U16_WMARawDec cEncodeOpt,
    U16_WMARawDec cPlayerOpt
) {
    WMARESULT hr;
    WMARawDecStruct* pWMARawDec;

//    phWMARawDec = NULL; // initialize as NULL for later checking
    pWMARawDec = (WMARawDecStruct*) wmvalloc (sizeof (WMARawDecStruct));
    if (pWMARawDec == NULL)
        return WMA_E_OUTOFMEMORY;


    pWMARawDec->pAudDecoder = audecNew (NULL, 0);
//    pWMARawDec->pAudDecoder = audecNew (rgWMAMem, WMAMEM_SIZE);
    if (pWMARawDec->pAudDecoder == NULL)
        return WMA_E_OUTOFMEMORY;

    hr = audecInit (
        pWMARawDec->pAudDecoder,
        (Int) iVersionNumber,
        cSamplesPerBlock,
        cSamplesPerSecond,
        cChannel,
        cBytePerSec,
        cPacketLength,
        cEncodeOpt,
        cPlayerOpt,
        WMARawDecCBGetData, 
        dwUserData,
        NULL
    );
// for unsupported formats

	if (hr == 0x80040000)
		return WMA_E_NOTSUPPORTED;
    
	if (WMA_FAILED (hr))
        return WMA_E_FAIL;

    *phWMARawDec = (WMARawDecHandle) pWMARawDec;
    return WMA_OK;
}
    
WMARESULT WMARawDecClose (WMARawDecHandle* phWMARawDec)
{
    WMARawDecStruct* pWMARawDec;

    pWMARawDec = (WMARawDecStruct*) (*phWMARawDec);
    if (pWMARawDec != NULL) {
        if (pWMARawDec->pAudDecoder != NULL) {
            audecDelete (pWMARawDec->pAudDecoder);
            pWMARawDec->pAudDecoder = NULL;
        }
        wmvfree (pWMARawDec);
        *phWMARawDec = NULL;
    }
    phWMARawDec = NULL;
    return WMA_OK;
}

WMARESULT WMARawDecReset (WMARawDecHandle hWMARawDec)
{
    WMARawDecStruct* pWMARawDec;
    pWMARawDec = (WMARawDecStruct*) hWMARawDec;

    if (pWMARawDec == NULL || pWMARawDec->pAudDecoder == NULL)
        return WMA_E_INVALIDARG;
    else
        return (audecReset (pWMARawDec->pAudDecoder));
}

WMARESULT WMARawDecStatus (WMARawDecHandle hWMARawDec)
{
    WMARawDecStruct* pWMARawDec;
    pWMARawDec = (WMARawDecStruct*) hWMARawDec;

    if (pWMARawDec == NULL || pWMARawDec->pAudDecoder == NULL)
        return WMA_E_INVALIDARG;
    else
        return (audecDecodeInfo (pWMARawDec->pAudDecoder));
}

WMARESULT WMARawDecDecodeData (WMARawDecHandle hWMARawDec, U32_WMARawDec *pnDecodedSamples)
{
    WMARawDecStruct* pWMARawDec;
    pWMARawDec = (WMARawDecStruct*) hWMARawDec;

    if (pWMARawDec == NULL || pWMARawDec->pAudDecoder == NULL)
        return WMA_E_INVALIDARG;
    else
        return (audecDecodeData (pWMARawDec->pAudDecoder, (U16_WMARawDec*) pnDecodedSamples));
}

WMARESULT WMARawDecGetPCM (WMARawDecHandle hWMARawDec, U16_WMARawDec* pcSampleReady, U8_WMARawDec* pbDst, U32_WMARawDec cbDstBufferLength)
{
    WMARawDecStruct* pWMARawDec;
    pWMARawDec = (WMARawDecStruct*) hWMARawDec;
    if (pWMARawDec == NULL || pWMARawDec->pAudDecoder == NULL)
        return WMA_E_INVALIDARG;
    else 
        return (audecGetPCM (pWMARawDec->pAudDecoder, pcSampleReady, pbDst, cbDstBufferLength));
}

