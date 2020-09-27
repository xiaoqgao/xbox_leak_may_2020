/*-----------------------------------------------------------------------------
* Copyright (C) Microsoft Corporation, 1995 - 1996.
* All rights reserved.
*
* This file is part of the Microsoft Private Communication Technology
* reference implementation, version 1.0
*
* The Private Communication Technology reference implementation, version 1.0
* ("PCTRef"), is being provided by Microsoft to encourage the development and
* enhancement of an open standard for secure general-purpose business and
* personal communications on open networks.  Microsoft is distributing PCTRef
* at no charge irrespective of whether you use PCTRef for non-commercial or
* commercial use.
*
* Microsoft expressly disclaims any warranty for PCTRef and all derivatives of
* it.  PCTRef and any related documentation is provided "as is" without
* warranty of any kind, either express or implied, including, without
* limitation, the implied warranties or merchantability, fitness for a
* particular purpose, or noninfringement.  Microsoft shall have no obligation
* to provide maintenance, support, upgrades or new releases to you or to anyone
* receiving from you PCTRef or your modifications.  The entire risk arising out
* of use or performance of PCTRef remains with you.
*
* Please see the file LICENSE.txt,
* or http://pct.microsoft.com/pct/pctlicen.txt
* for more information on licensing.
*
* Please see http://pct.microsoft.com/pct/pct.htm for The Private
* Communication Technology Specification version 1.0 ("PCT Specification")
*
* 1/23/96
*----------------------------------------------------------------------------*/


#include <spbase.h>
#include <defkeys.h>

static SP_STATUS
LoadRegKeys(
    LPDWORD lpiTrustedCAs,
    DWORD   cSubkeys
    );

static SP_STATUS
LoadKnownKeys(
    LPDWORD lpiTrustedCAs
    );

static BOOL
DeleteCACache();

//Didn't want to include whole bunch of include files ...
#define LSBOF(x)    ((UCHAR) (x & 0xFF))
#define MSBOF(x)    ((UCHAR) ((x >> 8) & 0xFF) )

#define PRIVATE_KEY_TEXT    "private-key"

#ifndef XBOX

extern CRITICAL_SECTION csSsl;
#if DBG
extern  DWORD   csSslOwner;
#define LockSsl(x)  EnterCriticalSection(&csSsl); csSslOwner = x
#define UnlockSsl() csSslOwner = 0; LeaveCriticalSection(&csSsl)
#else
#define LockSsl(x)  EnterCriticalSection(&csSsl)
#define UnlockSsl() LeaveCriticalSection(&csSsl)
#endif

#endif

#define SSL_INIT_CIPHER_CACHE   1
#define SSL_ADD_KEY_TO_CA_LIST  2
#define SSL_FIND_ISSUER         3


//
// SHolden -- hack hack hack...this defined in sspi\hack.c. When we build
// schannel.dll it will link properly.
//

int __cdecl stricmp(const char *, const char *);
#define lstrcmpiA stricmp

//
// TODO: this is the ntdev Certificate. Need to change this before we ship
//
BYTE g_RootCert[] = {
    0x30, 0x82, 0x03, 0xc9, 0x30, 0x82, 0x03, 0x32, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x0a,
    0x68, 0x8c, 0x6e, 0xc9, 0xb7, 0xf5, 0xb8, 0x4f, 0x09, 0x12, 0x96, 0x6d, 0xbf, 0x50, 0x9d, 0x30,
    0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 0x30, 0x81,
    0x8a, 0x31, 0x17, 0x30, 0x15, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01,
    0x16, 0x08, 0x74, 0x6f, 0x6e, 0x79, 0x63, 0x68, 0x65, 0x6e, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03,
    0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x08,
    0x13, 0x0a, 0x57, 0x61, 0x73, 0x68, 0x69, 0x6e, 0x67, 0x74, 0x6f, 0x6e, 0x31, 0x10, 0x30, 0x0e,
    0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x52, 0x65, 0x64, 0x6d, 0x6f, 0x6e, 0x64, 0x31, 0x0b,
    0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x02, 0x4d, 0x53, 0x31, 0x0d, 0x30, 0x0b, 0x06,
    0x03, 0x55, 0x04, 0x0b, 0x13, 0x04, 0x58, 0x62, 0x6f, 0x78, 0x31, 0x1f, 0x30, 0x1d, 0x06, 0x03,
    0x55, 0x04, 0x03, 0x13, 0x16, 0x54, 0x6f, 0x6e, 0x79, 0x20, 0x43, 0x68, 0x65, 0x6e, 0x20, 0x54,
    0x65, 0x73, 0x74, 0x20, 0x43, 0x41, 0x20, 0x52, 0x6f, 0x6f, 0x74, 0x30, 0x1e, 0x17, 0x0d, 0x30,
    0x30, 0x31, 0x30, 0x32, 0x37, 0x31, 0x36, 0x33, 0x34, 0x32, 0x35, 0x5a, 0x17, 0x0d, 0x30, 0x32,
    0x31, 0x30, 0x32, 0x37, 0x31, 0x36, 0x34, 0x32, 0x34, 0x33, 0x5a, 0x30, 0x81, 0x8a, 0x31, 0x17,
    0x30, 0x15, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01, 0x16, 0x08, 0x74,
    0x6f, 0x6e, 0x79, 0x63, 0x68, 0x65, 0x6e, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
    0x13, 0x02, 0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x0a, 0x57,
    0x61, 0x73, 0x68, 0x69, 0x6e, 0x67, 0x74, 0x6f, 0x6e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55,
    0x04, 0x07, 0x13, 0x07, 0x52, 0x65, 0x64, 0x6d, 0x6f, 0x6e, 0x64, 0x31, 0x0b, 0x30, 0x09, 0x06,
    0x03, 0x55, 0x04, 0x0a, 0x13, 0x02, 0x4d, 0x53, 0x31, 0x0d, 0x30, 0x0b, 0x06, 0x03, 0x55, 0x04,
    0x0b, 0x13, 0x04, 0x58, 0x62, 0x6f, 0x78, 0x31, 0x1f, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x04, 0x03,
    0x13, 0x16, 0x54, 0x6f, 0x6e, 0x79, 0x20, 0x43, 0x68, 0x65, 0x6e, 0x20, 0x54, 0x65, 0x73, 0x74,
    0x20, 0x43, 0x41, 0x20, 0x52, 0x6f, 0x6f, 0x74, 0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a,
    0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d, 0x00, 0x30, 0x81,
    0x89, 0x02, 0x81, 0x81, 0x00, 0xa7, 0x21, 0xc7, 0x4d, 0x92, 0x1e, 0xef, 0x48, 0xb5, 0x73, 0xbf,
    0x9f, 0x55, 0xcd, 0x67, 0xdd, 0x12, 0xef, 0xe2, 0xe8, 0x71, 0x44, 0x64, 0x16, 0x5d, 0xd8, 0x05,
    0x61, 0xde, 0xf6, 0x4a, 0x22, 0x81, 0x9a, 0xf9, 0x1f, 0x97, 0x37, 0xe1, 0xe1, 0x42, 0x25, 0x69,
    0x15, 0xd4, 0x33, 0x76, 0xd4, 0xc8, 0x68, 0x4a, 0x18, 0xdc, 0x1c, 0x89, 0x82, 0xc3, 0x2e, 0x67,
    0x26, 0xa1, 0xb1, 0xa9, 0x4f, 0x02, 0x3d, 0x06, 0x15, 0xf2, 0x4f, 0xc7, 0xdf, 0x84, 0xeb, 0xce,
    0x78, 0x12, 0x66, 0x5a, 0xac, 0xe2, 0xde, 0xea, 0xfd, 0x23, 0x74, 0x92, 0x20, 0x97, 0x41, 0xc1,
    0x90, 0x09, 0x50, 0x6c, 0x4e, 0x89, 0x38, 0x55, 0xea, 0x37, 0x50, 0x66, 0x42, 0xfd, 0xa5, 0xf6,
    0xc6, 0x5a, 0xbb, 0x31, 0x77, 0xf0, 0x10, 0x14, 0x93, 0x5f, 0x7c, 0xb5, 0xef, 0x46, 0x6e, 0x06,
    0xb5, 0x57, 0x4c, 0xcd, 0x45, 0x02, 0x03, 0x01, 0x00, 0x01, 0xa3, 0x82, 0x01, 0x2c, 0x30, 0x82,
    0x01, 0x28, 0x30, 0x13, 0x06, 0x09, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x82, 0x37, 0x14, 0x02, 0x04,
    0x06, 0x1e, 0x04, 0x00, 0x43, 0x00, 0x41, 0x30, 0x0b, 0x06, 0x03, 0x55, 0x1d, 0x0f, 0x04, 0x04,
    0x03, 0x02, 0x01, 0x46, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x05,
    0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14,
    0xad, 0x61, 0x48, 0x60, 0x2d, 0xfe, 0x31, 0xa3, 0xfa, 0x51, 0x88, 0x9b, 0xc4, 0x38, 0x9b, 0xa1,
    0x07, 0xde, 0xd7, 0xe6, 0x30, 0x81, 0xc1, 0x06, 0x03, 0x55, 0x1d, 0x1f, 0x04, 0x81, 0xb9, 0x30,
    0x81, 0xb6, 0x30, 0x58, 0xa0, 0x56, 0xa0, 0x54, 0x86, 0x52, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f,
    0x2f, 0x74, 0x6f, 0x6e, 0x79, 0x63, 0x68, 0x65, 0x6e, 0x32, 0x2e, 0x6e, 0x74, 0x64, 0x65, 0x76,
    0x2e, 0x6d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x43,
    0x65, 0x72, 0x74, 0x45, 0x6e, 0x72, 0x6f, 0x6c, 0x6c, 0x2f, 0x54, 0x6f, 0x6e, 0x79, 0x25, 0x32,
    0x30, 0x43, 0x68, 0x65, 0x6e, 0x25, 0x32, 0x30, 0x54, 0x65, 0x73, 0x74, 0x25, 0x32, 0x30, 0x43,
    0x41, 0x25, 0x32, 0x30, 0x52, 0x6f, 0x6f, 0x74, 0x2e, 0x63, 0x72, 0x6c, 0x30, 0x5a, 0xa0, 0x58,
    0xa0, 0x56, 0x86, 0x54, 0x66, 0x69, 0x6c, 0x65, 0x3a, 0x2f, 0x2f, 0x5c, 0x5c, 0x74, 0x6f, 0x6e,
    0x79, 0x63, 0x68, 0x65, 0x6e, 0x32, 0x2e, 0x6e, 0x74, 0x64, 0x65, 0x76, 0x2e, 0x6d, 0x69, 0x63,
    0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x5c, 0x43, 0x65, 0x72, 0x74, 0x45,
    0x6e, 0x72, 0x6f, 0x6c, 0x6c, 0x5c, 0x54, 0x6f, 0x6e, 0x79, 0x25, 0x32, 0x30, 0x43, 0x68, 0x65,
    0x6e, 0x25, 0x32, 0x30, 0x54, 0x65, 0x73, 0x74, 0x25, 0x32, 0x30, 0x43, 0x41, 0x25, 0x32, 0x30,
    0x52, 0x6f, 0x6f, 0x74, 0x2e, 0x63, 0x72, 0x6c, 0x30, 0x10, 0x06, 0x09, 0x2b, 0x06, 0x01, 0x04,
    0x01, 0x82, 0x37, 0x15, 0x01, 0x04, 0x03, 0x02, 0x01, 0x00, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 0x03, 0x81, 0x81, 0x00, 0x34, 0xe6, 0x4b,
    0x82, 0xcb, 0xb6, 0x72, 0xf5, 0xc5, 0x61, 0x7a, 0xd5, 0x79, 0x48, 0x7a, 0xb2, 0xfe, 0x27, 0x37,
    0x9f, 0x28, 0x80, 0x65, 0x69, 0x6d, 0xf4, 0xc2, 0xba, 0x1e, 0x65, 0xf0, 0x75, 0x58, 0xd6, 0xf7,
    0x48, 0xaf, 0x15, 0xa5, 0xa5, 0x97, 0x32, 0x68, 0x49, 0x78, 0xfb, 0x15, 0x2f, 0x22, 0x42, 0x8f,
    0x3f, 0x4e, 0x35, 0x61, 0xa6, 0xd1, 0xc8, 0xc3, 0x61, 0xb4, 0x33, 0xf1, 0x48, 0xc9, 0x1e, 0xe0,
    0xbf, 0x1b, 0x99, 0xc5, 0x22, 0x1e, 0x1a, 0x4a, 0x2e, 0x9c, 0x99, 0x78, 0xd4, 0x9d, 0x4c, 0x18,
    0x5d, 0x3e, 0xcb, 0xeb, 0x7f, 0xf3, 0xe2, 0x6d, 0x79, 0x19, 0x96, 0xe7, 0xf2, 0x09, 0x54, 0xc6,
    0x44, 0x47, 0x3d, 0xc7, 0x96, 0x8f, 0xba, 0xea, 0xaf, 0xac, 0x6d, 0xda, 0x47, 0xbe, 0x01, 0xf3,
    0x9a, 0x60, 0x78, 0xdf, 0x0d, 0x50, 0x4f, 0x42, 0xdf, 0x14, 0x1d, 0xe2, 0x95
/*
// ntdev 4
	0x30, 0x82, 0x05, 0x2f, 0x30, 0x82, 0x04, 0xef, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x0a, 0x61,
	0x73, 0x07, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x30, 0x09, 0x06, 0x07, 0x2a, 0x86, 0x48,
	0xce, 0x38, 0x04, 0x03, 0x30, 0x61, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x55, 0x53, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x09, 0x4d, 0x69,
	0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x31, 0x0e, 0x30, 0x0c, 0x06, 0x03, 0x55, 0x04, 0x0b,
	0x13, 0x05, 0x4e, 0x74, 0x64, 0x65, 0x76, 0x31, 0x2e, 0x30, 0x2c, 0x06, 0x03, 0x55, 0x04, 0x03,
	0x13, 0x25, 0x4e, 0x54, 0x44, 0x45, 0x56, 0x20, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6d, 0x65, 0x64,
	0x69, 0x61, 0x74, 0x65, 0x20, 0x53, 0x75, 0x62, 0x6f, 0x72, 0x64, 0x69, 0x6e, 0x61, 0x74, 0x65,
	0x20, 0x57, 0x68, 0x69, 0x63, 0x61, 0x32, 0x30, 0x1e, 0x17, 0x0d, 0x30, 0x30, 0x30, 0x39, 0x32,
	0x35, 0x32, 0x33, 0x33, 0x30, 0x35, 0x32, 0x5a, 0x17, 0x0d, 0x30, 0x31, 0x30, 0x39, 0x32, 0x35,
	0x32, 0x33, 0x33, 0x34, 0x31, 0x36, 0x5a, 0x30, 0x4b, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55,
	0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13,
	0x09, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x31, 0x0e, 0x30, 0x0c, 0x06, 0x03,
	0x55, 0x04, 0x0b, 0x13, 0x05, 0x4e, 0x74, 0x64, 0x65, 0x76, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03,
	0x55, 0x04, 0x03, 0x13, 0x0f, 0x4e, 0x54, 0x44, 0x45, 0x56, 0x20, 0x49, 0x73, 0x73, 0x75, 0x65,
	0x34, 0x20, 0x43, 0x41, 0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
	0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81,
	0x00, 0xd8, 0x76, 0xd7, 0x9b, 0x84, 0x30, 0xa2, 0xdc, 0x16, 0x4d, 0xe1, 0xe5, 0xdf, 0xf1, 0x3b,
	0x11, 0x5e, 0x9e, 0xf5, 0xd4, 0x16, 0x73, 0x67, 0xc3, 0x8b, 0x44, 0x1f, 0xf9, 0xe7, 0xa3, 0x52,
	0x0a, 0xb4, 0x1e, 0x2a, 0x4a, 0x81, 0x16, 0x97, 0xb9, 0x72, 0x2f, 0xed, 0x3a, 0xa9, 0x3f, 0xac,
	0xd7, 0xe5, 0x1e, 0x98, 0xf5, 0x47, 0x1c, 0x16, 0x95, 0x3e, 0xa4, 0xb8, 0x21, 0xbf, 0xe1, 0xa7,
	0x01, 0xac, 0x70, 0x62, 0x77, 0xb1, 0xd8, 0x16, 0xba, 0xcf, 0x5b, 0x30, 0x6d, 0xff, 0x85, 0x89,
	0x12, 0x43, 0x66, 0xb9, 0x45, 0xb2, 0x82, 0xe8, 0x39, 0x03, 0xe6, 0x4d, 0x06, 0x7b, 0x5a, 0xd1,
	0x7a, 0x3f, 0x9f, 0xe7, 0x1a, 0x96, 0x97, 0x2f, 0x3d, 0xc8, 0x1d, 0xbd, 0x24, 0x00, 0x93, 0x07,
	0x79, 0x62, 0x00, 0xa6, 0x07, 0xdf, 0x8f, 0x52, 0x0c, 0xbf, 0x4f, 0x21, 0x49, 0x4f, 0x4c, 0x13,
	0x71, 0x02, 0x03, 0x01, 0x00, 0x01, 0xa3, 0x82, 0x03, 0x5d, 0x30, 0x82, 0x03, 0x59, 0x30, 0x10,
	0x06, 0x09, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x82, 0x37, 0x15, 0x01, 0x04, 0x03, 0x02, 0x01, 0x00,
	0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x33, 0xa8, 0x66, 0x48, 0xbb,
	0x04, 0x1a, 0x7a, 0x93, 0x3a, 0x82, 0x4f, 0x15, 0xfa, 0xd0, 0x63, 0xc2, 0x12, 0xff, 0xb8, 0x30,
	0x19, 0x06, 0x09, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x82, 0x37, 0x14, 0x02, 0x04, 0x0c, 0x1e, 0x0a,
	0x00, 0x53, 0x00, 0x75, 0x00, 0x62, 0x00, 0x43, 0x00, 0x41, 0x30, 0x0b, 0x06, 0x03, 0x55, 0x1d,
	0x0f, 0x04, 0x04, 0x03, 0x02, 0x01, 0x46, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01,
	0xff, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04,
	0x18, 0x30, 0x16, 0x80, 0x14, 0x79, 0x20, 0x8e, 0xde, 0xa4, 0xdf, 0x24, 0x57, 0x22, 0x82, 0xbe,
	0x6d, 0xce, 0x0b, 0x98, 0xfc, 0x14, 0xce, 0x41, 0x42, 0x30, 0x82, 0x01, 0x56, 0x06, 0x03, 0x55,
	0x1d, 0x1f, 0x04, 0x82, 0x01, 0x4d, 0x30, 0x82, 0x01, 0x49, 0x30, 0x82, 0x01, 0x45, 0xa0, 0x82,
	0x01, 0x41, 0xa0, 0x82, 0x01, 0x3d, 0x86, 0x5c, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77,
	0x68, 0x69, 0x63, 0x61, 0x32, 0x2e, 0x6e, 0x74, 0x64, 0x65, 0x76, 0x2e, 0x6d, 0x69, 0x63, 0x72,
	0x6f, 0x73, 0x6f, 0x66, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x43, 0x65, 0x72, 0x74, 0x45, 0x6e,
	0x72, 0x6f, 0x6c, 0x6c, 0x2f, 0x4e, 0x54, 0x44, 0x45, 0x56, 0x25, 0x32, 0x30, 0x49, 0x6e, 0x74,
	0x65, 0x72, 0x6d, 0x65, 0x64, 0x69, 0x61, 0x74, 0x65, 0x25, 0x32, 0x30, 0x53, 0x75, 0x62, 0x6f,
	0x72, 0x64, 0x69, 0x6e, 0x61, 0x74, 0x65, 0x25, 0x32, 0x30, 0x57, 0x68, 0x69, 0x63, 0x61, 0x32,
	0x2e, 0x63, 0x72, 0x6c, 0x86, 0x81, 0xdc, 0x6c, 0x64, 0x61, 0x70, 0x3a, 0x2f, 0x2f, 0x2f, 0x43,
	0x4e, 0x3d, 0x4e, 0x54, 0x44, 0x45, 0x56, 0x25, 0x32, 0x30, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6d,
	0x65, 0x64, 0x69, 0x61, 0x74, 0x65, 0x25, 0x32, 0x30, 0x53, 0x75, 0x62, 0x6f, 0x72, 0x64, 0x69,
	0x6e, 0x61, 0x74, 0x65, 0x25, 0x32, 0x30, 0x57, 0x68, 0x69, 0x63, 0x61, 0x32, 0x2c, 0x43, 0x4e,
	0x3d, 0x77, 0x68, 0x69, 0x63, 0x61, 0x32, 0x2c, 0x43, 0x4e, 0x3d, 0x43, 0x44, 0x50, 0x2c, 0x43,
	0x4e, 0x3d, 0x50, 0x75, 0x62, 0x6c, 0x69, 0x63, 0x25, 0x32, 0x30, 0x4b, 0x65, 0x79, 0x25, 0x32,
	0x30, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x73, 0x2c, 0x43, 0x4e, 0x3d, 0x53, 0x65, 0x72,
	0x76, 0x69, 0x63, 0x65, 0x73, 0x2c, 0x43, 0x4e, 0x3d, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x75,
	0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x2c, 0x44, 0x43, 0x3d, 0x6e, 0x74, 0x64, 0x65, 0x76, 0x2c,
	0x44, 0x43, 0x3d, 0x6d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x2c, 0x44, 0x43, 0x3d,
	0x63, 0x6f, 0x6d, 0x3f, 0x63, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x65, 0x52,
	0x65, 0x76, 0x6f, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x4c, 0x69, 0x73, 0x74, 0x3f, 0x62, 0x61,
	0x73, 0x65, 0x3f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x63, 0x6c, 0x61, 0x73, 0x73, 0x3d, 0x63,
	0x52, 0x4c, 0x44, 0x69, 0x73, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x6f,
	0x69, 0x6e, 0x74, 0x30, 0x82, 0x01, 0x70, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x01,
	0x01, 0x04, 0x82, 0x01, 0x62, 0x30, 0x82, 0x01, 0x5e, 0x30, 0x81, 0x83, 0x06, 0x08, 0x2b, 0x06,
	0x01, 0x05, 0x05, 0x07, 0x30, 0x02, 0x86, 0x77, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77,
	0x68, 0x69, 0x63, 0x61, 0x32, 0x2e, 0x6e, 0x74, 0x64, 0x65, 0x76, 0x2e, 0x6d, 0x69, 0x63, 0x72,
	0x6f, 0x73, 0x6f, 0x66, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x43, 0x65, 0x72, 0x74, 0x45, 0x6e,
	0x72, 0x6f, 0x6c, 0x6c, 0x2f, 0x77, 0x68, 0x69, 0x63, 0x61, 0x32, 0x2e, 0x6e, 0x74, 0x64, 0x65,
	0x76, 0x2e, 0x6d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x5f,
	0x4e, 0x54, 0x44, 0x45, 0x56, 0x25, 0x32, 0x30, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6d, 0x65, 0x64,
	0x69, 0x61, 0x74, 0x65, 0x25, 0x32, 0x30, 0x53, 0x75, 0x62, 0x6f, 0x72, 0x64, 0x69, 0x6e, 0x61,
	0x74, 0x65, 0x25, 0x32, 0x30, 0x57, 0x68, 0x69, 0x63, 0x61, 0x32, 0x2e, 0x63, 0x72, 0x74, 0x30,
	0x81, 0xd5, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x30, 0x02, 0x86, 0x81, 0xc8, 0x6c,
	0x64, 0x61, 0x70, 0x3a, 0x2f, 0x2f, 0x2f, 0x43, 0x4e, 0x3d, 0x4e, 0x54, 0x44, 0x45, 0x56, 0x25,
	0x32, 0x30, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6d, 0x65, 0x64, 0x69, 0x61, 0x74, 0x65, 0x25, 0x32,
	0x30, 0x53, 0x75, 0x62, 0x6f, 0x72, 0x64, 0x69, 0x6e, 0x61, 0x74, 0x65, 0x25, 0x32, 0x30, 0x57,
	0x68, 0x69, 0x63, 0x61, 0x32, 0x2c, 0x43, 0x4e, 0x3d, 0x41, 0x49, 0x41, 0x2c, 0x43, 0x4e, 0x3d,
	0x50, 0x75, 0x62, 0x6c, 0x69, 0x63, 0x25, 0x32, 0x30, 0x4b, 0x65, 0x79, 0x25, 0x32, 0x30, 0x53,
	0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x73, 0x2c, 0x43, 0x4e, 0x3d, 0x53, 0x65, 0x72, 0x76, 0x69,
	0x63, 0x65, 0x73, 0x2c, 0x43, 0x4e, 0x3d, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x75, 0x72, 0x61,
	0x74, 0x69, 0x6f, 0x6e, 0x2c, 0x44, 0x43, 0x3d, 0x6e, 0x74, 0x64, 0x65, 0x76, 0x2c, 0x44, 0x43,
	0x3d, 0x6d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x2c, 0x44, 0x43, 0x3d, 0x63, 0x6f,
	0x6d, 0x3f, 0x63, 0x41, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x65, 0x3f,
	0x62, 0x61, 0x73, 0x65, 0x3f, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x63, 0x6c, 0x61, 0x73, 0x73,
	0x3d, 0x63, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x41, 0x75,
	0x74, 0x68, 0x6f, 0x72, 0x69, 0x74, 0x79, 0x30, 0x09, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x38,
	0x04, 0x03, 0x03, 0x2f, 0x00, 0x30, 0x2c, 0x02, 0x14, 0x48, 0x07, 0xb8, 0x80, 0xce, 0x47, 0x7c,
	0xcf, 0xcd, 0xa0, 0xea, 0x8a, 0x33, 0x9f, 0x6a, 0xc5, 0xb6, 0x0d, 0xdc, 0x96, 0x02, 0x14, 0x78,
	0x35, 0xe3, 0x09, 0xac, 0x76, 0x8f, 0x2a, 0x06, 0x90, 0x79, 0xd1, 0xd8, 0x74, 0x44, 0xef, 0xef,
	0x8f, 0x0b, 0x45
*/
/*
// ntdev root
    0x30, 0x82, 0x03, 0x40, 0x30, 0x82, 0x02, 0xa9, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x21,
    0x25, 0x66, 0xf7, 0x5e, 0x75, 0x84, 0xb8, 0x47, 0x8f, 0x7b, 0x59, 0xb4, 0xa9, 0xe2, 0x12, 0x30,
    0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 0x30, 0x4c,
    0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x12, 0x30,
    0x10, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x09, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66,
    0x74, 0x31, 0x0e, 0x30, 0x0c, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x05, 0x4e, 0x74, 0x64, 0x65,
    0x76, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x10, 0x4e, 0x54, 0x44, 0x45,
    0x56, 0x20, 0x53, 0x41, 0x20, 0x52, 0x6f, 0x6f, 0x74, 0x20, 0x43, 0x41, 0x30, 0x1e, 0x17, 0x0d,
    0x30, 0x30, 0x30, 0x39, 0x32, 0x30, 0x32, 0x31, 0x32, 0x34, 0x34, 0x35, 0x5a, 0x17, 0x0d, 0x30,
    0x32, 0x30, 0x39, 0x32, 0x30, 0x32, 0x31, 0x33, 0x33, 0x32, 0x38, 0x5a, 0x30, 0x4c, 0x31, 0x0b,
    0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x12, 0x30, 0x10, 0x06,
    0x03, 0x55, 0x04, 0x0a, 0x13, 0x09, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x31,
    0x0e, 0x30, 0x0c, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x05, 0x4e, 0x74, 0x64, 0x65, 0x76, 0x31,
    0x19, 0x30, 0x17, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x10, 0x4e, 0x54, 0x44, 0x45, 0x56, 0x20,
    0x53, 0x41, 0x20, 0x52, 0x6f, 0x6f, 0x74, 0x20, 0x43, 0x41, 0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06,
    0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d, 0x00,
    0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xc7, 0x29, 0xb7, 0x6c, 0x1b, 0x49, 0xf7, 0x77, 0xa9,
    0xf5, 0x83, 0x3d, 0x78, 0x5b, 0x6b, 0x25, 0x29, 0x85, 0x03, 0xc3, 0x46, 0xe8, 0xeb, 0x71, 0x4c,
    0xa4, 0x4b, 0x2f, 0x2a, 0x2b, 0x5c, 0xc6, 0x0d, 0x53, 0x32, 0xec, 0x76, 0x8c, 0xef, 0x19, 0x67,
    0x52, 0x67, 0x09, 0x73, 0x6e, 0xf0, 0x13, 0x6a, 0x4c, 0xeb, 0xce, 0xb8, 0xae, 0xaa, 0xae, 0xd0,
    0x81, 0xa0, 0x73, 0x26, 0xf4, 0xb4, 0x3a, 0xaf, 0x32, 0x03, 0x3b, 0x61, 0xa9, 0xfd, 0x23, 0x05,
    0x0c, 0xac, 0x1a, 0xf4, 0xc7, 0xd4, 0xb1, 0xe2, 0x7a, 0x8d, 0xdb, 0x98, 0x21, 0x45, 0x38, 0xe5,
    0x2d, 0x1a, 0xf7, 0xdd, 0x24, 0x66, 0xc4, 0x32, 0xf4, 0xdb, 0xf1, 0xc4, 0xf4, 0xcb, 0x10, 0x20,
    0x3c, 0x9e, 0xce, 0xaf, 0x45, 0x99, 0xb5, 0xae, 0xfb, 0x7f, 0xf0, 0x11, 0x50, 0xd5, 0x96, 0xbf,
    0xa8, 0x3b, 0x4c, 0xd5, 0x14, 0x85, 0xed, 0x02, 0x03, 0x01, 0x00, 0x01, 0xa3, 0x82, 0x01, 0x21,
    0x30, 0x82, 0x01, 0x1d, 0x30, 0x13, 0x06, 0x09, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x82, 0x37, 0x14,
    0x02, 0x04, 0x06, 0x1e, 0x04, 0x00, 0x43, 0x00, 0x41, 0x30, 0x0b, 0x06, 0x03, 0x55, 0x1d, 0x0f,
    0x04, 0x04, 0x03, 0x02, 0x01, 0x46, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff,
    0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16,
    0x04, 0x14, 0x77, 0xc9, 0x74, 0x69, 0x2c, 0x39, 0xfe, 0x38, 0x65, 0xf4, 0x87, 0x05, 0x58, 0x08,
    0xce, 0xbd, 0xba, 0x97, 0xda, 0x10, 0x30, 0x81, 0xb6, 0x06, 0x03, 0x55, 0x1d, 0x1f, 0x04, 0x81,
    0xae, 0x30, 0x81, 0xab, 0x30, 0x81, 0xa8, 0xa0, 0x81, 0xa5, 0xa0, 0x81, 0xa2, 0x86, 0x4e, 0x68,
    0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77, 0x68, 0x69, 0x63, 0x61, 0x73, 0x61, 0x72, 0x6f, 0x6f,
    0x74, 0x63, 0x61, 0x2e, 0x6e, 0x74, 0x64, 0x65, 0x76, 0x2e, 0x6d, 0x69, 0x63, 0x72, 0x6f, 0x73,
    0x6f, 0x66, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x43, 0x65, 0x72, 0x74, 0x45, 0x6e, 0x72, 0x6f,
    0x6c, 0x6c, 0x2f, 0x4e, 0x54, 0x44, 0x45, 0x56, 0x25, 0x32, 0x30, 0x53, 0x41, 0x25, 0x32, 0x30,
    0x52, 0x6f, 0x6f, 0x74, 0x25, 0x32, 0x30, 0x43, 0x41, 0x2e, 0x63, 0x72, 0x6c, 0x86, 0x50, 0x66,
    0x69, 0x6c, 0x65, 0x3a, 0x2f, 0x2f, 0x5c, 0x5c, 0x77, 0x68, 0x69, 0x63, 0x61, 0x73, 0x61, 0x72,
    0x6f, 0x6f, 0x74, 0x63, 0x61, 0x2e, 0x6e, 0x74, 0x64, 0x65, 0x76, 0x2e, 0x6d, 0x69, 0x63, 0x72,
    0x6f, 0x73, 0x6f, 0x66, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x5c, 0x43, 0x65, 0x72, 0x74, 0x45, 0x6e,
    0x72, 0x6f, 0x6c, 0x6c, 0x5c, 0x4e, 0x54, 0x44, 0x45, 0x56, 0x25, 0x32, 0x30, 0x53, 0x41, 0x25,
    0x32, 0x30, 0x52, 0x6f, 0x6f, 0x74, 0x25, 0x32, 0x30, 0x43, 0x41, 0x2e, 0x63, 0x72, 0x6c, 0x30,
    0x10, 0x06, 0x09, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x82, 0x37, 0x15, 0x01, 0x04, 0x03, 0x02, 0x01,
    0x00, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05, 0x00,
    0x03, 0x81, 0x81, 0x00, 0x08, 0xf9, 0xe1, 0x6f, 0x24, 0xcd, 0xa8, 0xac, 0xf6, 0xff, 0x37, 0x04,
    0x90, 0xa4, 0x40, 0x54, 0xa0, 0x55, 0xe8, 0xe3, 0xde, 0x3b, 0xa7, 0x3d, 0x90, 0xb1, 0x51, 0xe0,
    0xa7, 0x1b, 0x3c, 0xc3, 0x9a, 0xbc, 0x54, 0xb8, 0xe3, 0xdc, 0xa1, 0xfa, 0x18, 0x95, 0x2c, 0x19,
    0xff, 0x5d, 0x6e, 0x2e, 0x85, 0x55, 0x73, 0x9a, 0x82, 0x90, 0x46, 0x64, 0x9d, 0x64, 0xa6, 0xc1,
    0x14, 0x55, 0x8a, 0x28, 0xb3, 0xc9, 0xfd, 0xdd, 0x46, 0xe6, 0x2c, 0x47, 0xdb, 0x1e, 0x3f, 0x68,
    0xb1, 0x25, 0x4b, 0x4a, 0x1c, 0x7c, 0x1b, 0xa8, 0x77, 0xa8, 0x42, 0x95, 0x29, 0x66, 0x93, 0xad,
    0xf9, 0xcc, 0xf2, 0x2c, 0xe2, 0x89, 0xa4, 0xf7, 0x3d, 0x8a, 0x1c, 0x7d, 0xd7, 0xb5, 0xee, 0x98,
    0x30, 0xab, 0x35, 0x31, 0x74, 0x52, 0xb9, 0xfc, 0xa6, 0x8b, 0x86, 0xf7, 0x06, 0x32, 0x07, 0x7c,
    0x14, 0x9e, 0x64, 0x9d
*/
};

/****************************************
* IMPORTANT: Rules to follow for
* thread safety.  There is one global
* variable that needs to be thread safe.
* The array of trusted CA's which is nothing but array of
* Certificates.  The location
* of the array should be protected by
* a critical section.  Also, all certs
* from array[0] to array[cTrustedCAs] should
* be guaranteed to be there, so cTrustedCAs
* should be protected by a critical section,
* and should not be changed until the
* state of the certs is verified.
******************************************/

// TBDTBD: add reference counts to certificates
// to protect them from being deleted out from
// under us.

CRITICAL_SECTION csTrustedCAs;
CRITICAL_SECTION csUpdateCAs;

PPctCertificate * TrustedCAs;  // = NULL;
DWORD             cTrustedCAs; // = 0;
BOOL              fTrustedCAsLoaded; // = FALSE;

const char g_szVerisign3Root[] = "C=US, O=VeriSign, Inc., OU=Class 3 Public Primary Certification Authority";
const char g_szGenevaRoot[] = "CN=Root SGC Authority";

// Two SGC root CAs
PPctCertificate g_pVerisign3Root;
PPctCertificate g_pGenevaRoot;

// For loading resources as required.
HINSTANCE g_hInstance;

#ifdef DEBUG
const TCHAR *g_aKnownKeyNames[] = {
    TEXT("Verisign/RSA Secure Server"),
    TEXT("Verisign Class 2 Public Primary CA"),
    TEXT("Verisign Class 3 Public Primary CA"),
    TEXT("GTE Cybertrust ROOT"),
    TEXT("GTE Cybertrust Root"),
    TEXT("Thawte Server CA"),
    TEXT("Thawte Premium Server CA"),
    TEXT("Thawte Personal Basic CA"),
    TEXT("Thawte Personal Freemail CA"),
    TEXT("Thawte Personal Premium CA"),
    TEXT("Microsoft Root Authority"),
    TEXT("Root SGC Authority")
};

#endif //DEBUG

const DWORD g_aKnownKeyData[] = {
    {IDR_RSASSCA},
    {IDR_VSCLASS2},
    {IDR_VSCLASS3},
    {IDR_CYBERTRUST},
    {IDR_CYBERTRUSTv2},
    {IDR_THAWTE_SERVER_BASIC},
    {IDR_THAWTE_SERVER_PREMIUM},
    {IDR_THAWTE_PERSONAL_BASIC},
    {IDR_THAWTE_PERSONAL_FREEMAIL},
    {IDR_THAWTE_PERSONAL_PREMIUM},
    {IDR_MICROSOFT_ROOT_AUTH},
    {IDR_ENTRUST_SECURE_SERVER},
    {IDR_ENTRUST_2K_SECURE_SERVER},
    {IDR_GENEVA_SGC_CERT}
};

const DWORD g_cKnownKeys = sizeof(g_aKnownKeyData)/sizeof(DWORD);

BOOL
InitializeCACache(
    HINSTANCE hInstance
    )
{
    InitializeCriticalSection(&csTrustedCAs);
    InitializeCriticalSection(&csUpdateCAs);

    TrustedCAs        = NULL;
    cTrustedCAs       = 0;
    fTrustedCAsLoaded = FALSE;
    g_pVerisign3Root = NULL;
    g_pGenevaRoot = NULL;

    g_hInstance  = hInstance;

    return (TRUE);
}

//
// SHolden - Provide a way to shutdown the cache and clean up memory.
//

BOOL
ShutdownCACache()
{
    g_pVerisign3Root = NULL;
    g_pGenevaRoot = NULL;
    DeleteCACache();
    DeleteCriticalSection(&csTrustedCAs);
    DeleteCriticalSection(&csUpdateCAs);
    return (TRUE);
}

BOOL
DeleteCACache()
{
    DWORD iKey;

    EnterCriticalSection(&csTrustedCAs);
    EnterCriticalSection(&csUpdateCAs);

    if (fTrustedCAsLoaded == FALSE)
    {
        ASSERT(TrustedCAs == NULL);
        goto done;
    }

    fTrustedCAsLoaded = FALSE;

    if(TrustedCAs != NULL)
    {
        for(iKey = 0; iKey < cTrustedCAs; iKey++)
        {
            if(TrustedCAs[iKey])
            {
                // Cert will delete itelf when ref count is 0.
                DereferenceCert(TrustedCAs[iKey]->pIssuerCertificate);
                TrustedCAs[iKey]->pIssuerCertificate = NULL;
                DereferenceCert(TrustedCAs[iKey]);
            }
        }

        SPExternalFree(TrustedCAs);
        TrustedCAs  = NULL;
        cTrustedCAs = 0;
    }

done:

    LeaveCriticalSection(&csTrustedCAs);
    LeaveCriticalSection(&csUpdateCAs);

    return (TRUE);
}

PPctCertificate
FindIssuerKey(
    PSTR    pszIssuer)
{
    PPctCertificate Result = NULL;
    DWORD   i;

    EnterCriticalSection(&csTrustedCAs);

    if (fTrustedCAsLoaded == FALSE)
    {
        LoadCAKeys();
    }

    do
    {

        if(cTrustedCAs == 0 ||
           NULL == TrustedCAs)
        {
            break;
        }


        for (i = 0; i < cTrustedCAs ; i++ )
        {
            if (TrustedCAs[i] &&
                (lstrcmpiA(pszIssuer, TrustedCAs[i]->szSigningAuthority) ==0))
            {
                // Validated file time here
                Result = TrustedCAs[i];
                // Inc the reference count.
                break;
            }
        }
        break;
    } while(TRUE);

    // Reference the cert that we're
    // giving out.
    if (Result)
    {
        ReferenceCert(Result);
    }

    LeaveCriticalSection(&csTrustedCAs);
    return Result;
}


//
// SHolden - InitializeCACache used to read the certificates from the resource
//           file and then transfer to registry. This will use extra memory in
//           the registry. Instead, I will load the certificates from the
//           resource file on demand. I will also check the registry in case
//           the user has added their own.
//

SP_STATUS
LoadCAKeys(VOID)
{
    DWORD err;

    DWORD cKeys;
    DWORD cSubkeys;

    DWORD i;
    DWORD iKey;
    DWORD iTrustedKeys;

    DWORD cValues;
    DWORD cchMaxSubkeyLen;
    DWORD cchMaxClassLen;
    DWORD cchMaxValueLen;
    DWORD cchMaxDataLen;

    DEBUGMSG(ZONE_INIT | ZONE_CERT,
             (TEXT("SCHANNEL: +LoadCAKeys()\r\n"))
             );

    EnterCriticalSection(&csUpdateCAs);

    EnterCriticalSection(&csTrustedCAs);

    // Free the current cache if one exists before we re-load.
    DeleteCACache();

    // set first to prevent recursion! i.e. From FindIssuerKey.
    fTrustedCAsLoaded = TRUE;

    // Get the number of CA keys in the registry
#ifdef XBOX
	// BUGBUG Need to really lead certs from somewhere
    cKeys    = 1;
    cSubkeys = 0;
#else
    err = RegQueryInfoKey(g_hkCA,
                    NULL,             // Class name.
                    NULL,             // Size of class name.
                    NULL,             // Reserved. Must be NULL.
                    &cSubkeys,        // Count of number of subkeys.
                    &cchMaxSubkeyLen, // Size of subkey with longest name.
                    &cchMaxClassLen,  // Size of longest string specifying subkey class.
                    &cValues,         // Count of number of values associated with key.
                    &cchMaxValueLen,  // Size of longest value.
                    &cchMaxDataLen,   // Size of longest data component.
                    NULL,             // Must be NULL.
                    NULL);            // Must be NULL.

    if (err == 0)
    {
        DEBUGMSG(ZONE_INIT,
                 (TEXT("SCHANNEL: CA subkeys in registry = %d.\r\n"),
                  cSubkeys)
                 );

        cKeys = cSubkeys + g_cKnownKeys;
    }
    else
	{
        DEBUGMSG(ZONE_INIT,
                 (TEXT("SCHANNEL: RegQueryInfoKey failure = 0x%.8X (%d)\r\n"),
                  GetLastError(), GetLastError())
                 );

        cKeys    = g_cKnownKeys;
        cSubkeys = 0;
    }
#endif

    TrustedCAs  = SPExternalAlloc(cKeys * sizeof(PPctCertificate));
    cTrustedCAs = 0;

    if (TrustedCAs == NULL)
    {
        LeaveCriticalSection(&csTrustedCAs);
        LeaveCriticalSection(&csUpdateCAs);
        return SP_LOG_RESULT(PCT_INT_OUT_OF_MEMORY);
    }

    // We leave the critical section here so calls to
    // find issuer key do not block when we do the cert
    // decode.

    LeaveCriticalSection(&csTrustedCAs);

    iTrustedKeys = 0;

#ifndef XBOX
    LoadRegKeys(
        &iTrustedKeys,
        cSubkeys
        );
#endif

    LoadKnownKeys(
        &iTrustedKeys
        );

    ASSERT(iTrustedKeys == cKeys);

    EnterCriticalSection(&csTrustedCAs);

    cTrustedCAs = iTrustedKeys;

    // Hook up all of the signings.
    DEBUGMSG(ZONE_CERT,
            (TEXT("Hook cert signings...\r\n"))
            );

    for(iKey = 0; iKey < cTrustedCAs; iKey++)
    {
        if(TrustedCAs[iKey])
        {
            for (i = 0; i < cTrustedCAs ; i++ )
            {
                if (TrustedCAs[i] &&
                    (lstrcmpiA(TrustedCAs[i]->pszSubject, TrustedCAs[iKey]->szSigningAuthority) ==0))
                {
                    DEBUGMSG(ZONE_CERT,
                            (TEXT("    Cert%d issuer = Cert%d\r\n"),
                             TrustedCAs[iKey]->dwDebugId,
                             TrustedCAs[i]->dwDebugId)
                            );

                    // Validated file time here
                    TrustedCAs[iKey]->pIssuerCertificate = TrustedCAs[i];
                    // Inc the reference count.
                    ReferenceCert(TrustedCAs[i]);
                    break;
                }
            }
            if (!g_pVerisign3Root &&
                lstrcmpiA(TrustedCAs[iKey]->pszSubject,g_szVerisign3Root) == 0)
            {
                g_pVerisign3Root = TrustedCAs[iKey];
            }
            else if (!g_pGenevaRoot && 
                lstrcmpiA(TrustedCAs[iKey]->pszSubject,g_szGenevaRoot) == 0)
            {
                g_pGenevaRoot = TrustedCAs[iKey];
            }
        }
    }

    DEBUGMSG(ZONE_INIT | ZONE_CERT,
            (TEXT("SCHANNEL: -LoadCAKeys\r\n"))
            );

    LeaveCriticalSection(&csTrustedCAs);
    LeaveCriticalSection(&csUpdateCAs);
    return PCT_ERR_OK;
}


SP_STATUS
LoadKnownKeys(
    LPDWORD lpiTrustedCAs
    )
{
    const CertSystem *pSys = NULL;
#ifdef XBOX
    pSys = CertFromSpec(
        1, // dwCertType for all known = 1.
        SP_PROT_ALL
        );

    if (pSys != NULL)
    {
	    // Note, the issuer of the decoded cert should be NULL,
	    // as we have a size 0 issuer list.
	    pSys->Decode(g_RootCert, sizeof(g_RootCert), &TrustedCAs[*lpiTrustedCAs]);
	    TrustedCAs[(*lpiTrustedCAs)++]->fTrusted = TRUE;
	}
#else
    DWORD i;
    DWORD dwSize;
    HRSRC hResource;
    HGLOBAL hGlobal;

    void *pResource;

    for (i = 0; i < g_cKnownKeys; i++, (*lpiTrustedCAs)++)
    {
    #ifdef DEBUG

        DEBUGMSG(ZONE_INIT,
                 (TEXT("SCHANNEL: Loading CA from resource: %s\r\n"),
                  g_aKnownKeyNames[i])
                 );

    #endif

        hResource = FindResource(
            g_hInstance,
            MAKEINTRESOURCE(g_aKnownKeyData[i]),
            TEXT("CERT")
            );

        if(hResource == NULL)
        {
            DEBUGMSG(ZONE_ERROR,
                     (TEXT("SCHANNEL: FindResource failure 0x%.8X (%d).\r\n"),
                      GetLastError(), GetLastError())
                     );

            continue;
        }

        dwSize = SizeofResource(
            g_hInstance,
            hResource
            );

        if(dwSize == 0)
        {
            continue;
        }

        hGlobal = LoadResource(
            g_hInstance,
            hResource
            );

        if(hGlobal == NULL)
        {
            continue;
        }

        pResource = LockResource(hGlobal);

        if(pResource == NULL)
        {
            continue;
        }

        pSys = CertFromSpec(
            1, // dwCertType for all known = 1.
            SP_PROT_ALL
            );

        if (pSys == NULL)
        {
            continue;
        }

        // Note, the issuer of the decoded cert should be NULL,
        // as we have a size 0 issuer list.
        pSys->Decode(pResource, dwSize, &TrustedCAs[*lpiTrustedCAs]);
        TrustedCAs[*lpiTrustedCAs]->fTrusted = TRUE;
    }
#endif
    return (PCT_ERR_OK);
}

SP_STATUS
LoadRegKeys(
    LPDWORD lpiTrustedCAs,
    DWORD   cSubkeys
    )
{
    DWORD err;
    DWORD iSubkey;
    TCHAR szName[1024];
    DWORD cName;
    HKEY hSubKey;
    DWORD dwSize;
    DWORD dwType;
    DWORD dwEnabled;
    DWORD dwCertType;
    const CertSystem *pSys = NULL;
    PUCHAR pRawCert;

    for(iSubkey = 0;
        iSubkey < cSubkeys;
        iSubkey++
        )
    {
        pSys = NULL;
        TrustedCAs[*lpiTrustedCAs] = NULL;
        cName = sizeof(szName);

#ifndef XBOX
		// BUGBUG Need to really lead certs from resource

        // Now enum through the children of this key.
        err = RegEnumKeyEx(
            g_hkCA,
            iSubkey,
            szName,
            &cName,
            NULL,
            NULL,
            NULL,
            NULL
            );

        if(err)
        {
            continue;
        }

        DEBUGMSG(ZONE_INIT, (TEXT("SCHANNEL: Subkey %s\r\n"), szName));

        err = RegOpenKeyEx(g_hkCA, szName, 0, KEY_READ, &hSubKey);

        if(err)
        {
            continue;
        }

        dwSize = sizeof(DWORD);
        err = RegQueryValueEx(
            hSubKey,
            SP_REG_VAL_ENABLED,
            NULL,
            &dwType,
            (PUCHAR)&dwEnabled,
            &dwSize
            );

        if (err ||
            (REG_DWORD != dwType) ||
            (0 == dwEnabled)
            )
        {
            CloseHandle(hSubKey);
            continue;
        }

        dwSize = sizeof(DWORD);
        err = RegQueryValueEx(
            hSubKey,
            SP_REG_VAL_CERT_TYPE,
            NULL,
            &dwType,
            (PUCHAR)&dwCertType,
            &dwSize
            );

        if (err ||
            (REG_DWORD != dwType) ||
            (NULL == (pSys = CertFromSpec(dwCertType, SP_PROT_ALL)))
            )
        {
            CloseHandle(hSubKey);
            continue;
        }

        // Get the size of the cert
        err = RegQueryValueEx(
            hSubKey,
            SP_REG_VAL_CACERT,
            NULL,
            &dwType,
            NULL,
            &dwSize
            );

        if (err ||
            (REG_BINARY != dwType)
            )
        {
            CloseHandle(hSubKey);
            continue;
        }

        pRawCert = SPExternalAlloc(dwSize);
        if(NULL == pRawCert)
        {
            CloseHandle(hSubKey);
            // BUGBUG: did not clean up anything.
            return SP_LOG_RESULT(PCT_INT_OUT_OF_MEMORY);
        }

        // Get the cert for real this time.
        err = RegQueryValueEx(
            hSubKey,
            SP_REG_VAL_CACERT,
            NULL,
            &dwType,
            pRawCert,
            &dwSize
            );

        CloseHandle(hSubKey);

        if (err ||
            (REG_BINARY != dwType)
            )
        {
            SPExternalFree(pRawCert);
            continue;
        }

        DEBUGMSG(ZONE_INIT,
                 (TEXT("SCHANNEL: %s CA cert retrieved 0x%.8X.\r\n"),
                  szName, pRawCert)
                 );

        // Note, the issuer of the decoded cert should be NULL,
        // as we have a size 0 issuer list.
        if(pSys->Decode(pRawCert, dwSize, &TrustedCAs[*lpiTrustedCAs]))
        {
            TrustedCAs[*lpiTrustedCAs]->fTrusted = TRUE;
            (*lpiTrustedCAs)++;
        }
        SPExternalFree(pRawCert);
#endif

    }

    return (PCT_ERR_OK);
}

/*****************************************************************************/
BOOL GetDefaultIssuers(
    PBYTE pbIssuers,	    // out
    DWORD *pcbIssuers)	    // in, out
{
 	DWORD iCA;
    DWORD cbCurIssuerLen = 0;
 	DWORD cbIssuerLen = *pcbIssuers;
    PBYTE pbCurIssuer = pbIssuers;
	
    if (fTrustedCAsLoaded == FALSE)
    {
        LoadCAKeys();
    }

    if(TrustedCAs != NULL)
    {
        for(iCA = 0; iCA < cTrustedCAs; iCA++)
        {
            if(TrustedCAs[iCA])
            {
                cbCurIssuerLen += 2 + TrustedCAs[iCA]->cbIssuer;
                // Are we writing?
                if(pbIssuers)
                {
                    if(cbCurIssuerLen > cbIssuerLen)
                    {
                        return (FALSE);  // overrun
                    }

                    pbCurIssuer[0] = MSBOF(TrustedCAs[iCA]->cbIssuer);
			        pbCurIssuer[1] = LSBOF(TrustedCAs[iCA]->cbIssuer);
			        pbCurIssuer += 2;
	   			    CopyMemory(pbCurIssuer, TrustedCAs[iCA]->pbIssuer,
   							    TrustedCAs[iCA]->cbIssuer);
	         	    pbCurIssuer += TrustedCAs[iCA]->cbIssuer;
                }
            }
        }
        *pcbIssuers = cbCurIssuerLen;
    }
    else
    {
        *pcbIssuers = 0;
    }
    return TRUE;
}

