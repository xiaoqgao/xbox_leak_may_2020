//-----------------------------------------------------------------------------
// File: XODash.h
//
// Container for XOnline's dash.  Stolen from ATG
// Copyright (c) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#ifndef XBAPP_H
#define XBAPP_H

#include <xtl.h>
#include <xgraphics.h>
#include <stdio.h>
#include "XBInput.h"
#include "XBUtil.h"


#include "SmartObject.h"
#include <vector>
#include <list>

using namespace std;


struct XBGAMEPAD;
class SmartObject;

typedef list<SmartObject* > ListSmartObj;

typedef ListSmartObj::iterator SmartObjIter;


//-----------------------------------------------------------------------------
// Global access to common members
//-----------------------------------------------------------------------------
extern LPDIRECT3DDEVICE8 g_pd3dDevice;




//-----------------------------------------------------------------------------
// Error codes
//-----------------------------------------------------------------------------
#define XBAPPERR_MEDIANOTFOUND       0x82000003




//-----------------------------------------------------------------------------
// Name: class XOApplication
// Desc: holds all really high level objects, sets up D3D
//          Initialize()          - To initialize the device-dependant objects
//          FrameMove()           - To animate the scene
//          Render()              - To render the scene
//-----------------------------------------------------------------------------
class XOApplication
{
protected:
    // Main objects used for creating and rendering the 3D scene
    D3DPRESENT_PARAMETERS m_d3dpp;
    LPDIRECT3D8           m_pD3D;              // The D3D enumerator object
    LPDIRECT3DDEVICE8     m_pd3dDevice;        // The D3D rendering device
    LPDIRECT3DSURFACE8    m_pBackBuffer;       // The backbuffer
    LPDIRECT3DSURFACE8    m_pDepthBuffer;      // The depthbuffer

    // Variables for timing
    FLOAT      m_fTime;             // Current absolute time in seconds
    FLOAT      m_fElapsedTime;      // Elapsed absolute time since last frame
    FLOAT      m_fAppTime;          // Current app time in seconds
    FLOAT      m_fElapsedAppTime;   // Elapsed app time since last frame
    BOOL       m_bPaused;           // Whether app time is paused by user
    FLOAT      m_fFPS;              // Instanteous frame rate
    WCHAR      m_strFrameRate[20];  // Frame rate written to a string
    HANDLE     m_hFrameCounter;     // Handle to framerate perf counter
	


    // Members to init the XINPUT devices.
    XDEVICE_PREALLOC_TYPE* m_InputDeviceTypes;
    DWORD                  m_dwNumInputDeviceTypes;
    XBGAMEPAD*             m_Gamepad;
    XBGAMEPAD              m_DefaultGamepad;


    // Helper functions
    HRESULT RenderGradientBackground( DWORD dwTopColor, DWORD dwBottomColor );

    // Overridable functions for the 3D scene created by the app
    virtual HRESULT Initialize();
    virtual HRESULT FrameMove();
    virtual HRESULT Render();
    virtual HRESULT Cleanup();
	HRESULT Update();

public:

	TCHAR					m_szAppDir[MAX_PATH];

    // Functions to create, run, and clean up the application
    HRESULT Create();
    INT     Run();
    VOID    Destroy();

    // Internal constructor
    XOApplication();

	float	GetTime(){ return m_fAppTime; }

private:
	ListSmartObj m_SmartObjects; 
	void AddText();
	DWORD m_nCurLanguage;
	float m_fLastChangeLanguge;
};


extern XOApplication	theApp; // the single instance


#endif
