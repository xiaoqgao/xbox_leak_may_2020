// **************************************************************************
//
//       Copyright 1993-1999 NVIDIA, Corporation.  All rights reserved.
//
//     NOTICE TO USER:   The source code  is copyrighted under  U.S. and
//     international laws.  Users and possessors of this source code are
//     hereby granted a nonexclusive,  royalty-free copyright license to
//     use this code in individual and commercial software.
//
//     Any use of this source code must include,  in the user documenta-
//     tion and  internal comments to the code,  notices to the end user
//     as follows:
//
//       Copyright 1993-1999 NVIDIA, Corporation.  All rights reserved.
//
//     NVIDIA, CORPORATION MAKES NO REPRESENTATION ABOUT THE SUITABILITY
//     OF  THIS SOURCE  CODE  FOR ANY PURPOSE.  IT IS  PROVIDED  "AS IS"
//     WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  NVIDIA, CORPOR-
//     ATION DISCLAIMS ALL WARRANTIES  WITH REGARD  TO THIS SOURCE CODE,
//     INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGE-
//     MENT,  AND FITNESS  FOR A PARTICULAR PURPOSE.   IN NO EVENT SHALL
//     NVIDIA, CORPORATION  BE LIABLE FOR ANY SPECIAL,  INDIRECT,  INCI-
//     DENTAL, OR CONSEQUENTIAL DAMAGES,  OR ANY DAMAGES  WHATSOEVER RE-
//     SULTING FROM LOSS OF USE,  DATA OR PROFITS,  WHETHER IN AN ACTION
//     OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,  ARISING OUT OF
//     OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOURCE CODE.
//
//     U.S. Government  End  Users.   This source code  is a "commercial
//     item,"  as that  term is  defined at  48 C.F.R. 2.101 (OCT 1995),
//     consisting  of "commercial  computer  software"  and  "commercial
//     computer  software  documentation,"  as such  terms  are  used in
//     48 C.F.R. 12.212 (SEPT 1995)  and is provided to the U.S. Govern-
//     ment only as  a commercial end item.   Consistent with  48 C.F.R.
//     12.212 and  48 C.F.R. 227.7202-1 through  227.7202-4 (JUNE 1995),
//     all U.S. Government End Users  acquire the source code  with only
//     those rights set forth herein.
//
// ********************************* Direct 3D ******************************
//
//  Module: nvDP2Help.h
//      helper routines for DP2 operations
//
// **************************************************************************
//
//  History:
//      Craig Duttweiler        08Nov00         created
//
// **************************************************************************

// definitions
#define NV_NUM_UNIQUE_STREAMS(count) (((count) & 0x0000ffff) >>  0)
#define NV_NUM_SYSTEM_STREAMS(count) (((count) & 0xffff0000) >> 16)

// prototypes
void __stdcall  nvWireframeIndexedTriangle      (NV_INNERLOOP_ARGLIST);
void __stdcall  nvPointIndexedTriangle          (NV_INNERLOOP_ARGLIST);
void __stdcall  nvWireframeNonIndexedTriangle   (NV_INNERLOOP_ARGLIST);
void __stdcall  nvPointNonIndexedTriangle       (NV_INNERLOOP_ARGLIST);

void            nvCalcRWFar                     (PNVD3DCONTEXT pContext);

BOOL            nvPaletteBlt                    (CNvObject *pSrcObj, CTexture *pDstTexture);
BOOL            nvUnpalettize                   (CNvObject *pDstObj);
void            nvAutoPaletteCheckAndRevert     (CTexture* pTexture, BOOL bFullSurface);

DWORD           nvCountStreamDMAs               (PNVD3DCONTEXT pContext, DWORD dwStreamCount);

