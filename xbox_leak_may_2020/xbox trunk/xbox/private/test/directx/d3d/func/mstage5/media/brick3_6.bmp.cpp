/*******************************************************************************

Copyright (c) 2000 Microsoft Corporation.  All rights reserved.

File Name:

    brick3_6.bmp.cpp

Description

    Data file for the resource brick3_6.bmp.

*******************************************************************************/

#include "d3dlocus.h"

static BYTE g_brick3_6[] = {

   0x42, 0x4D, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 
   0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x0E, 0x00, 0x00, 0xC3, 0x0E, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xFA, 0xFB, 0x68, 0x7E, 0x9A, 0x4E, 0x63, 0x88, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF5, 0xF7, 0xFA, 
   0x6E, 0x83, 0xA7, 0x62, 0x7B, 0x99, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xF8, 0xF9, 0x64, 0x7C, 0x97, 0x4E, 0x64, 0x7D, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF6, 0xF6, 0xF8, 
   0x47, 0xBB, 0xCA, 0x37, 0xBA, 0xC9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF2, 0xFA, 0xFB, 0x31, 0xD2, 0xDD, 0x31, 0xB4, 0xC6, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF6, 0xF5, 0xF7, 
   0x4E, 0xA3, 0xC1, 0x40, 0x98, 0xB2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF5, 0xF6, 0xF9, 0x6A, 0x78, 0x9F, 0x59, 0x69, 0x8B, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF5, 0xF6, 0xF8, 
   0x6F, 0x86, 0x98, 0x64, 0x7C, 0x94, 0x00, 0x00, 
};

static RESOURCEDATA g_rd_brick3_6(TEXT(MODULE_STRING), TEXT("brick3_6.bmp"), g_brick3_6, sizeof(g_brick3_6));

extern "C" LPVOID PREPEND_MODULE(_brick3_6) = (LPVOID)&g_rd_brick3_6;
