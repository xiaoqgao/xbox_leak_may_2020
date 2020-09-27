/*******************************************************************************

Copyright (c) 2000 Microsoft Corporation.  All rights reserved.

File Name:

    vshader1.vsh.cpp

Description

    Data file for the resource vshader1.vsh.

*******************************************************************************/

#include "d3dlocus.h"

static BYTE g_vshader1[] = {

   0x3B, 0x0D, 0x0A, 0x3B, 0x20, 0x56, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x69, 0x6E, 0x70, 0x75, 
   0x74, 0x20, 0x72, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, 0x73, 0x3A, 0x0D, 0x0A, 0x3B, 0x0D, 
   0x0A, 0x3B, 0x20, 0x76, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x56, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x70, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 
   0x0D, 0x0A, 0x3B, 0x20, 0x76, 0x33, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x56, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x6E, 0x6F, 0x72, 0x6D, 0x61, 0x6C, 0x0D, 
   0x0A, 0x3B, 0x20, 0x76, 0x37, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x56, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x20, 
   0x63, 0x6F, 0x6F, 0x72, 0x64, 0x69, 0x6E, 0x61, 0x74, 0x65, 0x73, 0x0D, 0x0A, 0x3B, 0x0D, 0x0A, 
   0x3B, 0x20, 0x43, 0x6F, 0x6E, 0x73, 0x74, 0x61, 0x6E, 0x74, 0x20, 0x72, 0x65, 0x67, 0x69, 0x73, 
   0x74, 0x65, 0x72, 0x73, 0x3A, 0x0D, 0x0A, 0x3B, 0x0D, 0x0A, 0x3B, 0x20, 0x63, 0x30, 0x20, 0x2D, 
   0x20, 0x63, 0x33, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x54, 0x72, 0x61, 0x6E, 0x73, 0x70, 
   0x6F, 0x73, 0x65, 0x64, 0x20, 0x63, 0x6F, 0x6E, 0x63, 0x61, 0x74, 0x65, 0x6E, 0x61, 0x74, 0x69, 
   0x6F, 0x6E, 0x20, 0x6F, 0x66, 0x20, 0x77, 0x6F, 0x72, 0x6C, 0x64, 0x2C, 0x20, 0x76, 0x69, 0x65, 
   0x77, 0x2C, 0x20, 0x61, 0x6E, 0x64, 0x20, 0x70, 0x72, 0x6F, 0x6A, 0x65, 0x63, 0x74, 0x69, 0x6F, 
   0x6E, 0x20, 0x6D, 0x61, 0x74, 0x72, 0x69, 0x63, 0x65, 0x73, 0x0D, 0x0A, 0x3B, 0x0D, 0x0A, 0x3B, 
   0x20, 0x63, 0x34, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4E, 
   0x6F, 0x72, 0x6D, 0x61, 0x6C, 0x69, 0x7A, 0x65, 0x64, 0x20, 0x6C, 0x69, 0x67, 0x68, 0x74, 0x20, 
   0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x0D, 0x0A, 0x3B, 0x20, 0x63, 0x35, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x56, 0x69, 0x65, 0x77, 0x20, 
   0x70, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x0D, 0x0A, 0x3B, 0x20, 0x63, 0x36, 0x2E, 0x78, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4D, 0x61, 0x74, 0x65, 0x72, 0x69, 
   0x61, 0x6C, 0x20, 0x70, 0x6F, 0x77, 0x65, 0x72, 0x0D, 0x0A, 0x3B, 0x20, 0x63, 0x36, 0x2E, 0x79, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x30, 0x2E, 0x30, 0x66, 0x0D, 0x0A, 
   0x3B, 0x20, 0x63, 0x36, 0x2E, 0x7A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x31, 0x2E, 0x30, 0x66, 0x0D, 0x0A, 0x3B, 0x20, 0x63, 0x37, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x44, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x62, 0x61, 
   0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x28, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 
   0x65, 0x20, 0x6C, 0x69, 0x67, 0x68, 0x74, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x6D, 0x6F, 
   0x64, 0x75, 0x6C, 0x61, 0x74, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x64, 0x69, 0x66, 
   0x66, 0x75, 0x73, 0x65, 0x20, 0x6D, 0x61, 0x74, 0x65, 0x72, 0x69, 0x61, 0x6C, 0x20, 0x63, 0x6F, 
   0x6C, 0x6F, 0x72, 0x29, 0x0D, 0x0A, 0x3B, 0x20, 0x63, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x44, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x6F, 0x66, 
   0x66, 0x73, 0x65, 0x74, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x28, 0x61, 0x6D, 0x62, 0x69, 
   0x65, 0x6E, 0x74, 0x20, 0x72, 0x6F, 0x6F, 0x6D, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x6D, 
   0x6F, 0x64, 0x75, 0x6C, 0x61, 0x74, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x6D, 
   0x62, 0x69, 0x65, 0x6E, 0x74, 0x20, 0x6D, 0x61, 0x74, 0x65, 0x72, 0x69, 0x61, 0x6C, 0x20, 0x63, 
   0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x2B, 0x0D, 0x0A, 0x3B, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x61, 0x6D, 
   0x62, 0x69, 0x65, 0x6E, 0x74, 0x20, 0x6C, 0x69, 0x67, 0x68, 0x74, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 
   0x72, 0x20, 0x6D, 0x6F, 0x64, 0x75, 0x6C, 0x61, 0x74, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 
   0x20, 0x61, 0x6D, 0x62, 0x69, 0x65, 0x6E, 0x74, 0x20, 0x6D, 0x61, 0x74, 0x65, 0x72, 0x69, 0x61, 
   0x6C, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x2B, 0x0D, 0x0A, 0x3B, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x65, 0x6D, 0x69, 0x73, 0x73, 0x69, 0x76, 0x65, 0x20, 0x6D, 0x61, 0x74, 0x65, 0x72, 0x69, 
   0x61, 0x6C, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x29, 0x0D, 0x0A, 0x3B, 0x20, 0x63, 0x39, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x53, 0x70, 0x65, 0x63, 0x75, 
   0x6C, 0x61, 0x72, 0x20, 0x62, 0x61, 0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x28, 
   0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x6C, 0x69, 0x67, 0x68, 0x74, 0x20, 0x63, 
   0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x6D, 0x6F, 0x64, 0x75, 0x6C, 0x61, 0x74, 0x65, 0x64, 0x20, 0x77, 
   0x69, 0x74, 0x68, 0x20, 0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x6D, 0x61, 0x74, 
   0x65, 0x72, 0x69, 0x61, 0x6C, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x29, 0x0D, 0x0A, 0x3B, 0x0D, 
   0x0A, 0x0D, 0x0A, 0x76, 0x73, 0x2E, 0x31, 0x2E, 0x30, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 
   0x09, 0x3B, 0x20, 0x56, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x73, 0x68, 0x61, 0x64, 0x65, 0x72, 
   0x20, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x20, 0x31, 0x2E, 0x30, 0x0D, 0x0A, 0x0D, 0x0A, 
   0x3B, 0x20, 0x54, 0x72, 0x61, 0x6E, 0x73, 0x66, 0x6F, 0x72, 0x6D, 0x20, 0x74, 0x68, 0x65, 0x20, 
   0x76, 0x65, 0x72, 0x74, 0x65, 0x78, 0x0D, 0x0A, 0x0D, 0x0A, 0x64, 0x70, 0x34, 0x20, 0x6F, 0x50, 
   0x6F, 0x73, 0x2E, 0x78, 0x2C, 0x20, 0x76, 0x30, 0x2C, 0x20, 0x63, 0x30, 0x0D, 0x0A, 0x64, 0x70, 
   0x34, 0x20, 0x6F, 0x50, 0x6F, 0x73, 0x2E, 0x79, 0x2C, 0x20, 0x76, 0x30, 0x2C, 0x20, 0x63, 0x31, 
   0x0D, 0x0A, 0x64, 0x70, 0x34, 0x20, 0x6F, 0x50, 0x6F, 0x73, 0x2E, 0x7A, 0x2C, 0x20, 0x76, 0x30, 
   0x2C, 0x20, 0x63, 0x32, 0x0D, 0x0A, 0x64, 0x70, 0x34, 0x20, 0x6F, 0x50, 0x6F, 0x73, 0x2E, 0x77, 
   0x2C, 0x20, 0x76, 0x30, 0x2C, 0x20, 0x63, 0x33, 0x0D, 0x0A, 0x0D, 0x0A, 0x3B, 0x20, 0x4C, 0x69, 
   0x67, 0x68, 0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x76, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x77, 
   0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x61, 
   0x6C, 0x20, 0x6C, 0x69, 0x67, 0x68, 0x74, 0x0D, 0x0A, 0x0D, 0x0A, 0x64, 0x70, 0x33, 0x20, 0x72, 
   0x32, 0x2E, 0x78, 0x2C, 0x20, 0x76, 0x33, 0x2C, 0x20, 0x2D, 0x63, 0x34, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 
   0x20, 0x44, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x69, 0x6E, 0x74, 0x65, 0x6E, 0x73, 0x69, 
   0x74, 0x79, 0x20, 0x3D, 0x20, 0x64, 0x6F, 0x74, 0x70, 0x72, 0x6F, 0x64, 0x75, 0x63, 0x74, 0x28, 
   0x76, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x6E, 0x6F, 0x72, 0x6D, 0x61, 0x6C, 0x2C, 0x20, 0x6C, 
   0x69, 0x67, 0x68, 0x74, 0x20, 0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x29, 0x0D, 
   0x0A, 0x0D, 0x0A, 0x61, 0x64, 0x64, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x76, 0x30, 0x2C, 0x20, 0x2D, 
   0x63, 0x35, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x43, 0x61, 0x6C, 0x63, 0x75, 0x6C, 0x61, 
   0x74, 0x65, 0x20, 0x61, 0x20, 0x76, 0x65, 0x63, 0x74, 0x6F, 0x72, 0x20, 0x66, 0x72, 0x6F, 0x6D, 
   0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x79, 0x65, 0x20, 0x74, 0x6F, 0x20, 0x74, 0x68, 0x65, 0x20, 
   0x76, 0x65, 0x72, 0x74, 0x65, 0x78, 0x0D, 0x0A, 0x64, 0x70, 0x33, 0x20, 0x72, 0x31, 0x2E, 0x77, 
   0x2C, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x6E, 0x6D, 
   0x33, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 0x30, 0x0D, 0x0A, 0x72, 0x73, 0x71, 0x20, 0x72, 0x31, 
   0x2E, 0x77, 0x2C, 0x20, 0x72, 0x31, 0x2E, 0x77, 0x0D, 0x0A, 0x6D, 0x75, 0x6C, 0x20, 0x72, 0x31, 
   0x2E, 0x78, 0x79, 0x7A, 0x2C, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 0x31, 0x2E, 0x77, 0x0D, 0x0A, 
   0x61, 0x64, 0x64, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 0x31, 0x2C, 0x20, 0x63, 0x34, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x43, 0x61, 0x6C, 0x63, 0x75, 0x6C, 0x61, 0x74, 0x65, 0x20, 
   0x74, 0x68, 0x65, 0x20, 0x68, 0x61, 0x6C, 0x66, 0x2D, 0x76, 0x65, 0x63, 0x74, 0x6F, 0x72, 0x0D, 
   0x0A, 0x64, 0x70, 0x33, 0x20, 0x72, 0x31, 0x2E, 0x77, 0x2C, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 
   0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x6E, 0x6D, 0x33, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 
   0x30, 0x0D, 0x0A, 0x72, 0x73, 0x71, 0x20, 0x72, 0x31, 0x2E, 0x77, 0x2C, 0x20, 0x72, 0x31, 0x2E, 
   0x77, 0x0D, 0x0A, 0x6D, 0x75, 0x6C, 0x20, 0x72, 0x31, 0x2E, 0x78, 0x79, 0x7A, 0x2C, 0x20, 0x72, 
   0x30, 0x2C, 0x20, 0x72, 0x31, 0x2E, 0x77, 0x0D, 0x0A, 0x64, 0x70, 0x33, 0x20, 0x72, 0x32, 0x2E, 
   0x79, 0x2C, 0x20, 0x76, 0x33, 0x2C, 0x20, 0x2D, 0x72, 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x53, 
   0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x69, 0x6E, 0x74, 0x65, 0x6E, 0x73, 0x69, 0x74, 
   0x79, 0x20, 0x3D, 0x20, 0x64, 0x6F, 0x74, 0x70, 0x72, 0x6F, 0x64, 0x75, 0x63, 0x74, 0x28, 0x76, 
   0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x6E, 0x6F, 0x72, 0x6D, 0x61, 0x6C, 0x2C, 0x20, 0x6C, 0x69, 
   0x67, 0x68, 0x74, 0x2F, 0x65, 0x79, 0x65, 0x20, 0x68, 0x61, 0x6C, 0x66, 0x2D, 0x76, 0x65, 0x63, 
   0x74, 0x6F, 0x72, 0x29, 0x0D, 0x0A, 0x0D, 0x0A, 0x6D, 0x6F, 0x76, 0x20, 0x72, 0x32, 0x2E, 0x77, 
   0x2C, 0x20, 0x63, 0x36, 0x2E, 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x4D, 0x61, 
   0x74, 0x65, 0x72, 0x69, 0x61, 0x6C, 0x20, 0x70, 0x6F, 0x77, 0x65, 0x72, 0x0D, 0x0A, 0x0D, 0x0A, 
   0x6C, 0x69, 0x74, 0x20, 0x72, 0x33, 0x2C, 0x20, 0x72, 0x32, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x4C, 0x69, 0x67, 0x68, 0x74, 0x20, 0x63, 0x6F, 0x65, 0x66, 
   0x66, 0x69, 0x63, 0x69, 0x65, 0x6E, 0x74, 0x73, 0x0D, 0x0A, 0x0D, 0x0A, 0x3B, 0x6D, 0x61, 0x64, 
   0x20, 0x72, 0x30, 0x2E, 0x78, 0x79, 0x7A, 0x2C, 0x20, 0x72, 0x33, 0x2E, 0x79, 0x2C, 0x20, 0x63, 
   0x37, 0x2E, 0x78, 0x79, 0x7A, 0x2C, 0x20, 0x63, 0x38, 0x2E, 0x78, 0x79, 0x7A, 0x20, 0x20, 0x20, 
   0x20, 0x3B, 0x20, 0x44, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 
   0x20, 0x3D, 0x20, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x69, 0x6E, 0x74, 0x65, 0x6E, 
   0x73, 0x69, 0x74, 0x79, 0x20, 0x2A, 0x20, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x62, 
   0x61, 0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x2B, 0x20, 0x64, 0x69, 0x66, 0x66, 
   0x75, 0x73, 0x65, 0x20, 0x6F, 0x66, 0x66, 0x73, 0x65, 0x74, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 
   0x0D, 0x0A, 0x6D, 0x75, 0x6C, 0x20, 0x72, 0x30, 0x2E, 0x78, 0x79, 0x7A, 0x2C, 0x20, 0x72, 0x33, 
   0x2E, 0x79, 0x2C, 0x20, 0x63, 0x37, 0x2E, 0x78, 0x79, 0x7A, 0x0D, 0x0A, 0x61, 0x64, 0x64, 0x20, 
   0x72, 0x30, 0x2E, 0x78, 0x79, 0x7A, 0x2C, 0x20, 0x72, 0x30, 0x2E, 0x78, 0x79, 0x7A, 0x2C, 0x20, 
   0x63, 0x38, 0x2E, 0x78, 0x79, 0x7A, 0x0D, 0x0A, 0x0D, 0x0A, 0x6D, 0x6F, 0x76, 0x20, 0x72, 0x30, 
   0x2E, 0x77, 0x2C, 0x20, 0x63, 0x37, 0x2E, 0x77, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 
   0x44, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x61, 0x6C, 0x70, 0x68, 0x61, 0x20, 0x3D, 0x20, 
   0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x62, 0x61, 0x73, 0x65, 0x20, 0x61, 0x6C, 0x70, 
   0x68, 0x61, 0x0D, 0x0A, 0x6D, 0x69, 0x6E, 0x20, 0x6F, 0x44, 0x30, 0x2C, 0x20, 0x72, 0x30, 0x2C, 
   0x20, 0x72, 0x33, 0x2E, 0x77, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x43, 0x6C, 0x61, 0x6D, 0x70, 0x20, 
   0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x73, 0x20, 0x74, 
   0x6F, 0x20, 0x31, 0x2E, 0x30, 0x66, 0x0D, 0x0A, 0x0D, 0x0A, 0x6D, 0x75, 0x6C, 0x20, 0x72, 0x30, 
   0x2E, 0x78, 0x79, 0x7A, 0x2C, 0x20, 0x72, 0x33, 0x2E, 0x7A, 0x2C, 0x20, 0x63, 0x39, 0x2E, 0x78, 
   0x79, 0x7A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 
   0x53, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x3D, 
   0x20, 0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x69, 0x6E, 0x74, 0x65, 0x6E, 0x73, 
   0x69, 0x74, 0x79, 0x20, 0x2A, 0x20, 0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x62, 
   0x61, 0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x0D, 0x0A, 0x6D, 0x6F, 0x76, 0x20, 0x72, 
   0x30, 0x2E, 0x77, 0x2C, 0x20, 0x63, 0x39, 0x2E, 0x77, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 
   0x20, 0x53, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x61, 0x6C, 0x70, 0x68, 0x61, 0x20, 
   0x3D, 0x20, 0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x62, 0x61, 0x73, 0x65, 0x20, 
   0x61, 0x6C, 0x70, 0x68, 0x61, 0x0D, 0x0A, 0x6D, 0x69, 0x6E, 0x20, 0x6F, 0x44, 0x31, 0x2C, 0x20, 
   0x72, 0x30, 0x2C, 0x20, 0x72, 0x33, 0x2E, 0x77, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x43, 0x6C, 0x61, 
   0x6D, 0x70, 0x20, 0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 
   0x72, 0x73, 0x20, 0x74, 0x6F, 0x20, 0x31, 0x2E, 0x30, 0x66, 0x0D, 0x0A, 0x0D, 0x0A, 0x6D, 0x6F, 
   0x76, 0x20, 0x6F, 0x54, 0x30, 0x2C, 0x20, 0x76, 0x37, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x3B, 0x20, 0x50, 0x72, 0x6F, 0x70, 0x61, 0x67, 0x61, 0x74, 0x65, 0x20, 0x74, 0x65, 
   0x78, 0x74, 0x75, 0x72, 0x65, 0x20, 0x63, 0x6F, 0x6F, 0x72, 0x64, 0x69, 0x6E, 0x61, 0x74, 0x65, 
   0x73, 0x0D, 0x0A, 0x0D, 0x0A, 0x3B, 0x20, 0x4C, 0x69, 0x67, 0x68, 0x74, 0x20, 0x69, 0x6E, 0x74, 
   0x65, 0x6E, 0x73, 0x69, 0x74, 0x79, 0x20, 0x66, 0x61, 0x63, 0x74, 0x6F, 0x72, 0x65, 0x64, 0x20, 
   0x69, 0x6E, 0x74, 0x6F, 0x20, 0x61, 0x6C, 0x70, 0x68, 0x61, 0x20, 0x63, 0x61, 0x6C, 0x63, 0x75, 
   0x6C, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x73, 0x0D, 0x0A, 0x0D, 0x0A, 0x3B, 0x64, 0x70, 0x33, 0x20, 
   0x72, 0x32, 0x2E, 0x78, 0x2C, 0x20, 0x76, 0x33, 0x2C, 0x20, 0x2D, 0x63, 0x34, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x44, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x69, 0x6E, 
   0x74, 0x65, 0x6E, 0x73, 0x69, 0x74, 0x79, 0x20, 0x3D, 0x20, 0x64, 0x6F, 0x74, 0x70, 0x72, 0x6F, 
   0x64, 0x75, 0x63, 0x74, 0x28, 0x76, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x6E, 0x6F, 0x72, 0x6D, 
   0x61, 0x6C, 0x2C, 0x20, 0x6C, 0x69, 0x67, 0x68, 0x74, 0x20, 0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 
   0x69, 0x6F, 0x6E, 0x29, 0x0D, 0x0A, 0x0D, 0x0A, 0x3B, 0x61, 0x64, 0x64, 0x20, 0x72, 0x30, 0x2C, 
   0x20, 0x76, 0x30, 0x2C, 0x20, 0x2D, 0x63, 0x35, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x3B, 0x20, 0x43, 0x61, 0x6C, 0x63, 0x75, 0x6C, 0x61, 0x74, 0x65, 0x20, 0x61, 0x20, 0x76, 
   0x65, 0x63, 0x74, 0x6F, 0x72, 0x20, 0x66, 0x72, 0x6F, 0x6D, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 
   0x79, 0x65, 0x20, 0x74, 0x6F, 0x20, 0x74, 0x68, 0x65, 0x20, 0x76, 0x65, 0x72, 0x74, 0x65, 0x78, 
   0x0D, 0x0A, 0x3B, 0x6E, 0x6D, 0x33, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 0x30, 0x0D, 0x0A, 0x3B, 
   0x61, 0x64, 0x64, 0x20, 0x72, 0x31, 0x2C, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x63, 0x34, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x43, 0x61, 0x6C, 0x63, 0x75, 0x6C, 
   0x61, 0x74, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 0x68, 0x61, 0x6C, 0x66, 0x2D, 0x76, 0x65, 0x63, 
   0x74, 0x6F, 0x72, 0x0D, 0x0A, 0x3B, 0x6E, 0x6D, 0x33, 0x20, 0x72, 0x31, 0x2C, 0x20, 0x72, 0x31, 
   0x0D, 0x0A, 0x3B, 0x64, 0x70, 0x33, 0x20, 0x72, 0x32, 0x2E, 0x79, 0x2C, 0x20, 0x76, 0x33, 0x2C, 
   0x20, 0x2D, 0x72, 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x53, 0x70, 0x65, 
   0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x69, 0x6E, 0x74, 0x65, 0x6E, 0x73, 0x69, 0x74, 0x79, 0x20, 
   0x3D, 0x20, 0x64, 0x6F, 0x74, 0x70, 0x72, 0x6F, 0x64, 0x75, 0x63, 0x74, 0x28, 0x76, 0x65, 0x72, 
   0x74, 0x65, 0x78, 0x20, 0x6E, 0x6F, 0x72, 0x6D, 0x61, 0x6C, 0x2C, 0x20, 0x6C, 0x69, 0x67, 0x68, 
   0x74, 0x2F, 0x65, 0x79, 0x65, 0x20, 0x68, 0x61, 0x6C, 0x66, 0x2D, 0x76, 0x65, 0x63, 0x74, 0x6F, 
   0x72, 0x29, 0x0D, 0x0A, 0x0D, 0x0A, 0x3B, 0x6D, 0x6F, 0x76, 0x20, 0x72, 0x32, 0x2E, 0x77, 0x2C, 
   0x20, 0x63, 0x36, 0x2E, 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 
   0x20, 0x4D, 0x61, 0x74, 0x65, 0x72, 0x69, 0x61, 0x6C, 0x20, 0x70, 0x6F, 0x77, 0x65, 0x72, 0x0D, 
   0x0A, 0x0D, 0x0A, 0x3B, 0x6C, 0x69, 0x74, 0x20, 0x72, 0x33, 0x2C, 0x20, 0x72, 0x32, 0x20, 0x20, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x4C, 0x69, 
   0x67, 0x68, 0x74, 0x20, 0x63, 0x6F, 0x65, 0x66, 0x66, 0x69, 0x63, 0x69, 0x65, 0x6E, 0x74, 0x73, 
   0x0D, 0x0A, 0x0D, 0x0A, 0x3B, 0x6D, 0x61, 0x64, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 0x33, 0x2E, 
   0x79, 0x2C, 0x20, 0x63, 0x37, 0x2C, 0x20, 0x63, 0x38, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x44, 
   0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x3D, 0x20, 0x64, 
   0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x69, 0x6E, 0x74, 0x65, 0x6E, 0x73, 0x69, 0x74, 0x79, 
   0x20, 0x2A, 0x20, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x62, 0x61, 0x73, 0x65, 0x20, 
   0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x2B, 0x20, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 
   0x6F, 0x66, 0x66, 0x73, 0x65, 0x74, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x0D, 0x0A, 0x3B, 0x6D, 
   0x69, 0x6E, 0x20, 0x6F, 0x44, 0x30, 0x2C, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 0x33, 0x2E, 0x77, 
   0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x43, 0x6C, 0x61, 0x6D, 0x70, 0x20, 0x64, 
   0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x73, 0x20, 0x74, 0x6F, 
   0x20, 0x31, 0x2E, 0x30, 0x66, 0x0D, 0x0A, 0x0D, 0x0A, 0x3B, 0x6D, 0x75, 0x6C, 0x20, 0x72, 0x30, 
   0x2C, 0x20, 0x72, 0x33, 0x2E, 0x7A, 0x2C, 0x20, 0x63, 0x39, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
   0x20, 0x20, 0x3B, 0x20, 0x53, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x63, 0x6F, 0x6C, 
   0x6F, 0x72, 0x20, 0x3D, 0x20, 0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x69, 0x6E, 
   0x74, 0x65, 0x6E, 0x73, 0x69, 0x74, 0x79, 0x20, 0x2A, 0x20, 0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 
   0x61, 0x72, 0x20, 0x62, 0x61, 0x73, 0x65, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x0D, 0x0A, 0x3B, 
   0x6D, 0x69, 0x6E, 0x20, 0x6F, 0x44, 0x31, 0x2C, 0x20, 0x72, 0x30, 0x2C, 0x20, 0x72, 0x33, 0x2E, 
   0x77, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3B, 0x20, 0x43, 0x6C, 0x61, 0x6D, 0x70, 0x20, 
   0x73, 0x70, 0x65, 0x63, 0x75, 0x6C, 0x61, 0x72, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x73, 0x20, 
   0x74, 0x6F, 0x20, 0x31, 0x2E, 0x30, 0x66, 0x0D, 0x0A, 
};

static RESOURCEDATA g_rd_vshader1(TEXT(MODULE_STRING), TEXT("vshader1.vsh"), g_vshader1, sizeof(g_vshader1));

extern "C" LPVOID PREPEND_MODULE(_vshader1) = (LPVOID)&g_rd_vshader1;
