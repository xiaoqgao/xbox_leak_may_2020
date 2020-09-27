/////////////////////////////////////////////////////////////////////////////
//  FILE          : nt_rand.c                                              //
//  DESCRIPTION   : Crypto CP interfaces:                                  //
//                  CPGenRandom                                            //
//  AUTHOR        :                                                        //
//  HISTORY       :                                                        //
//	Jan 25 1995 larrys  Changed from Nametag                           //
//      Feb 23 1995 larrys  Changed NTag_SetLastError to SetLastError      //
//      Apr 10 1995 larrys  Fix comments                                   //
//      Oct 27 1995 rajeshk Added provider parameter to GenRandom call     //
//      Nov  3 1995 larrys  Merge for NT checkin                           //
//      Oct 14 1996 jeffspel Changed GenRandom to NewGenRandom             //
//                                                                         //
//  Copyright (C) 1993 Microsoft Corporation   All Rights Reserved         //
/////////////////////////////////////////////////////////////////////////////

#include "precomp.h"
#include "sha.h"
#include "rsa_fast.h"
#include "rsa_math.h"
#include "randlib.h"

static BYTE DSSPRIVATEKEYINIT[] =
{ 0x67, 0x45, 0x23, 0x01, 0xef, 0xcd, 0xab, 0x89,
  0x98, 0xba, 0xdc, 0xfe, 0x10, 0x32, 0x54, 0x76,
  0xc3, 0xd2, 0xe1, 0xf0};

static BYTE DSSPERMSGINIT[] =
{ 0xef, 0xcd, 0xab, 0x89, 0x98, 0xba, 0xdc, 0xfe,
  0x10, 0x32, 0x54, 0x76, 0xc3, 0xd2, 0xe1, 0xf0,
  0x67, 0x45, 0x23, 0x01};

static BYTE MODULUS[] =
{ 0xf5, 0xc1, 0x56, 0xb1, 0xd5, 0x48, 0x42, 0x2e,
  0xbd, 0xa5, 0x44, 0x41, 0xc7, 0x1c, 0x24, 0x08,
  0x3f, 0x80, 0x3c, 0x90};


BYTE g_rgbRNGState[A_SHA_DIGEST_LEN];

//
// Function : AddSeeds
//
// Description : This function adds the 160 bit seeds pointed to by pdwSeed1 and
//               pdwSeed2, it also adds 1 to this sum and mods the sum by
//               2^160.
//

void AddSeeds(
              IN DWORD *pdwSeed1,
              IN OUT DWORD *pdwSeed2
              )
{
    DWORD   dwTmp;
    DWORD   dwOverflow = 1;
    DWORD   i;

    for (i = 0; i < 5; i++)
    {
        dwTmp = dwOverflow + pdwSeed1[i];
        dwOverflow = (dwOverflow > dwTmp);
        pdwSeed2[i] = pdwSeed2[i] + dwTmp;
        dwOverflow = ((dwTmp > pdwSeed2[i]) || dwOverflow);
    }
}


void SHA_mod_q(
               BYTE      *pbHash,              // In
               BYTE      *pbQ,                 // In
               BYTE      *pbNewHash            // Out
               )    
/*
        Given SHA(message), compute SHA(message) mod qdigit.
        Output is in the interval [0, qdigit-1].
        Although SHA(message) may exceed qdigit,
        it cannot exceed 2*qdigit since the leftmost bit 
        of qdigit is 1.
*/
{
    BYTE    rgbHash[A_SHA_DIGEST_LEN];

    if (-1 != Compare((DWORD*)rgbHash,  // hash is greater so subtract
                      (DWORD*)pbQ,
                      A_SHA_DIGEST_LEN / sizeof(DWORD)))  
    {
        Sub((DWORD*)pbNewHash,
            (DWORD*)rgbHash,
            (DWORD*)pbQ,
            A_SHA_DIGEST_LEN / sizeof(DWORD));
    }
    else
    {
        memcpy(pbNewHash, pbHash, A_SHA_DIGEST_LEN / sizeof(DWORD));
    }
} /* SHA_mod_q */

//
// Function : RNG16BitStateCheck
//
// Description : This function compares each 160 bits of the buffer with
//               the next 160 bits and if they are the same the function
//               errors out.  The IN buffer is expected to be A_SHA_DIGEST_LEN
//               bytes long.  The function fails if the RNG is gets the same
//               input buffer of 160 bits twice in a row.
//

BOOL RNG16BitStateCheck(
                        IN OUT DWORD *pdwOut,
                        IN DWORD *pdwIn,
                        IN DWORD cbNeeded
                        )
{
    BOOL    fRet = FALSE;

    if (0 == memcmp(g_rgbRNGState, pdwIn, A_SHA_DIGEST_LEN))
    {
        memcpy(g_rgbRNGState, (BYTE*)pdwIn, A_SHA_DIGEST_LEN);
        goto Ret;
    }

    memcpy(g_rgbRNGState, (BYTE*)pdwIn, A_SHA_DIGEST_LEN);

    memcpy((BYTE*)pdwOut, (BYTE*)pdwIn, cbNeeded);

    fRet = TRUE;
Ret:
    return fRet;
}

//
// Function : FIPS186Gen
//
// Description : FIPS 186 RNG, the seed is generated by calling NewGenRandom.
//

BOOL FIPS186Gen(
                IN HANDLE hRNGDriver,
                IN BYTE **ppbContextSeed,
                IN DWORD *pcbContextSeed,
                IN BYTE *pbInitValue,     // this is t, must be 20 bytes
                IN BYTE *pbModulus,       // this must be a 20 byte prime
                IN OUT BYTE *pb,
                IN DWORD cb
                )
{
    DWORD           rgdwSeed[A_SHA_DIGEST_LEN/sizeof(DWORD)];    // 160 bits
    DWORD           rgdwNewSeed[A_SHA_DIGEST_LEN/sizeof(DWORD)]; // 160 bits
    A_SHA_CTX       SHACtxt;
    BYTE            rgbBuf[A_SHA_DIGEST_LEN];
    DWORD           cbBuf;
    BYTE            *pbTmp = pb;
    DWORD           cbTmp = cb;
    DWORD           i;
    BOOL            fRet = FALSE;

    while (cbTmp)
    {
#ifdef USE_HW_RNG
#ifdef _M_IX86
        // get a 160 bit random seed
        if (INVALID_HANDLE_VALUE != hRNGDriver)
        {
	        if (!HWRNGGenRandom(hRNGDriver,
                                (BYTE*)rgdwNewSeed,
                                sizeof(rgdwNewSeed)))
            {
                SetLastError((DWORD)NTE_FAIL);
                goto Ret;
            }
        }
        else
#endif // _M_IX86
#endif // USE_HW_RNG
        {
            // get a 160 bit random seed
            NewGenRandom(ppbContextSeed, pcbContextSeed,
                         (BYTE*)rgdwNewSeed, sizeof(rgdwNewSeed));
        }

        for (i = 0; i < A_SHA_DIGEST_LEN/sizeof(DWORD); i++)
        {
            rgdwSeed[i] ^= rgdwNewSeed[i];
        }

        A_SHAInit (&SHACtxt);
        memcpy(SHACtxt.state, pbInitValue, A_SHA_DIGEST_LEN);

        // perform the one way function
        A_SHAUpdate(&SHACtxt, (BYTE*)rgdwSeed, sizeof(rgdwSeed));
        A_SHAFinal(&SHACtxt, rgbBuf);

        // continuous 16 bit state check
        if (A_SHA_DIGEST_LEN < cbTmp)
        {
            cbBuf = A_SHA_DIGEST_LEN;
        }
        else
        {
            cbBuf = cbTmp;
        }
        if (!RNG16BitStateCheck((DWORD*)pbTmp, (DWORD*)rgbBuf, cbBuf))
        {
            SetLastError((DWORD)NTE_FAIL);
            goto Ret;
        }
        pbTmp += cbBuf;
        cbTmp -= cbBuf;
        if (0 == cbTmp)
            break;

        // modular reduction with modulus Q
        SHA_mod_q(rgbBuf, pbModulus, (BYTE*)rgdwNewSeed);

        // (1 + previous seed + new random) mod 2^160
        AddSeeds(rgdwNewSeed, rgdwSeed);
    }

    fRet = TRUE;
Ret:
    return fRet;
}

BOOL FIPS186GenRandom(
                      IN HANDLE *phRNGDriver,
                      IN BYTE **ppbContextSeed,
                      IN DWORD *pcbContextSeed,
                      IN OUT BYTE *pb,
                      IN DWORD cb
                      )
{
    return FIPS186Gen(*phRNGDriver, ppbContextSeed, pcbContextSeed,
                      DSSPRIVATEKEYINIT, MODULUS, pb, cb);
}

void FIPS186GenRandomWithException(
                      IN HANDLE *phRNGDriver,
                      IN BYTE **ppbContextSeed,
                      IN DWORD *pcbContextSeed,
                      IN OUT BYTE *pb,
                      IN DWORD cb
                      )
{
    if (!FIPS186Gen(*phRNGDriver, ppbContextSeed, pcbContextSeed,
                    DSSPRIVATEKEYINIT, MODULUS, pb, cb))
    {
        // nasty way to cause an error but need either this
        // or redo rsa32.lib
        RaiseException ( NTE_FAIL, 0, 0, 0 );;
    }
}


/*
 -	CPGenRandom
 -
 *	Purpose:
 *                Used to fill a buffer with random bytes
 *
 *
 *	Parameters:
 *               IN  hUID       -  Handle to the user identifcation
 *               IN  dwLen      -  Number of bytes of random data requested
 *               OUT pbBuffer   -  Pointer to the buffer where the random
 *                                 bytes are to be placed
 *
 *	Returns:
 */
BOOL CPGenRandom(IN HCRYPTPROV hUID,
                 IN DWORD dwLen,
                 OUT BYTE *pbBuffer)
{
    PNTAGUserList   pTmpUser;
    BOOL            fRet = NTF_FAILED;

#if DBG         // NOTE:  This section not compiled for retail builds
    CSPDebugOutputGenRandom(TRUE, FALSE, hUID, dwLen, pbBuffer);
#endif // DBG -- NOTE:  This section not compiled for retail builds

	// check the user identification
	if (NULL == (pTmpUser = NTLCheckList (hUID, USER_HANDLE)))
	{
		SetLastError((DWORD) NTE_BAD_UID);
		goto Ret;
	}

    FIPS186Gen(pTmpUser->hRNGDriver,
               &pTmpUser->ContInfo.pbRandom,
               &pTmpUser->ContInfo.ContLens.cbRandom,
               DSSPRIVATEKEYINIT,
               MODULUS, pbBuffer, dwLen);

    fRet = NTF_SUCCEED;
Ret:
#if DBG         // NOTE:  This section not compiled for retail builds
    CSPDebugOutputGenRandom(FALSE, fRet, 0, 0, NULL);
#endif // DBG -- NOTE:  This section not compiled for retail builds

	return fRet;
}
