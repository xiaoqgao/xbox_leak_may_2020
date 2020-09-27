// FILE:        attenfvfls.cpp
// DESC:        attenuate class methods for point sprite conformance test
// AUTHOR:      Todd M. Frost
// COMMENTS:    D3DFVF_LVERTEX | D3DFVF_PSIZE

#define STRICT
//#define D3D_OVERLOADS
#include "d3dlocus.h"
#include "cd3dtest.h"
#include "3dmath.h"
#include "PointSprite.h"

// NAME:        CSpriteAttenuateFVFLS()
// DESC:        constructor for sprite attenuate class (D3DFVF_LVERTEX | D3DFVF_PSIZE)
// INPUT:       none
// OUTPUT:      none

CSpriteAttenuateFVFLS::CSpriteAttenuateFVFLS(VOID)
{
    m_szTestName=TEXT("Point sprite attenuation (D3DFVF_LVERTEX | D3DFVF_PSIZE)");
    m_szCommandKey=TEXT("AttenuateFVFLS");

    m_dvPointSizeMax = 0.0f;

    m_LineOfSight.x = 0.0f;
    m_LineOfSight.y = 0.0f;
    m_LineOfSight.z = 0.0f;

    memset(m_Coefficients, 0, NCSETS*sizeof(COEFFDATA));
}

// NAME:        ~CSpriteAttenuateFVFLS()
// DESC:        destructor for sprite attenuate class (D3DFVF_LVERTEX | D3DFVF_PSIZE)
// INPUT:       none
// OUTPUT:      none

CSpriteAttenuateFVFLS::~CSpriteAttenuateFVFLS(VOID)
{
}

// NAME:        CommandLineHelp()
// DESC:        command line help
// INPUT:       none
// OUTPUT:      none

void CSpriteAttenuateFVFLS::CommandLineHelp(void)
{
    CSprite::CommandLineHelp();
//    WriteCommandLineHelp("$yinvalid: $wrun invalid parameter tests$c($wYes$c/No)");
    return;
}

// NAME:        TestInitialize()
// DESC:        initialize test
// INPUT:       none
// OUTPUT:      appropriate D3DTESTINIT code

UINT CSpriteAttenuateFVFLS::TestInitialize(VOID)
{
    double dTemp;
    D3DVECTOR V;
    UINT uResult = CSprite::TestInitialize();

	// Although this values is set and used to calculate the coefficients
	// It will not be used by the test as the point size is passed with the 
	// vertex and is set in the Execute section of this test.
    m_Sprite.PointSize.f = 1.0f;//m_Sprite.PointSizeMax.f;

    V.x = m_At.x - m_From.x;
    V.y = m_At.y - m_From.y;
    V.z = m_At.z - m_From.z;
    dTemp = sqrt((double) (V.x*V.x + V.y*V.y + V.z*V.z));
    m_LineOfSight.x = (D3DVALUE) (V.x/dTemp);
    m_LineOfSight.y = (D3DVALUE) (V.y/dTemp);
    m_LineOfSight.z = (D3DVALUE) (V.z/dTemp);

    // Point Sprite scale formula 
	// Ss = Vh * Si * sqrt( 1/(A + B*De + C*(De*De) )
	// Si is the per vertex value or the RS point size

    // constant: a = ((Si*Vh)/Ss)**2
    //           This means that A will cause the point sprite to be max size.

    m_Coefficients[0].Ka.f =  ((m_Sprite.PointSize.f*m_ViewportCenter.y*2)/m_Sprite.PointSizeMax.f);//(m_ViewportCenter.y/5.0f) * (m_ViewportCenter.y/5.0f);
	m_Coefficients[0].Ka.f *= m_Coefficients[0].Ka.f;
	m_Coefficients[0].Kb.f = 0.0f;
	m_Coefficients[0].Kc.f = 0.0f;
        
    // linear: b = ((Si*Vh)/Ss)**2
    //         This causes the point sprite to be max size when De = 1;

    m_Coefficients[1].Ka.f = 0.0f;
	m_Coefficients[1].Kb.f = ((m_Sprite.PointSize.f*m_ViewportCenter.y*2)/m_Sprite.PointSizeMax.f);
	m_Coefficients[1].Kb.f *= m_Coefficients[1].Kb.f;
	m_Coefficients[1].Kc.f = 0.0f;    
    
    // quadratic: c = 1
    //            sqrt(1/(1.75*d*d))

    m_Coefficients[2].Ka.f = 0.0f;
	m_Coefficients[2].Kb.f = 0.0f;
	m_Coefficients[2].Kc.f = 1.75f;   

    // full: a = 0.514, b = 0.514, c = 0.514
    //      sqrt( 1/( 0.514 + (0.514*d) + (0.514*(d*d)) ) )

	m_Coefficients[3].Ka.f = 0.514f;
	m_Coefficients[3].Kb.f = 0.514f;
    m_Coefficients[3].Kc.f = 0.514f;

    m_nVariationsPerFormat *= NCSETS;
    SetTestRange((UINT) 1, (UINT) (m_nFormats*m_nVariationsPerFormat));

    SetRenderState(D3DRS_POINTSCALEENABLE, (DWORD) TRUE);

#ifndef UNDER_XBOX
    if (!m_Flags.bCheck(VERTEXPOINTSIZE) && !m_Flags.bCheck(INVALID))
        uResult = D3DTESTINIT_SKIPALL;
#endif

    return uResult;
}

// NAME:        ExecuteTest()
// DESC:        execute test
// INPUT:       uTest....test number
// OUTPUT:      true.....if test is executed successfully
//              false....otherwise

bool CSpriteAttenuateFVFLS::ExecuteTest(UINT uTest)
{
    bool bResult = true;
    D3DVALUE dvDistance, dvT;
    UINT uSet, uLocations;
   
	uLocations = m_nVariationsPerFormat/NCSETS;
    dvT = (D3DVALUE) ((uTest - 1) % uLocations) / (D3DVALUE) (uLocations - 1);
    dvDistance = dvT*((m_dvFar +1.0f ) - 2.0f*EPSILON);	// pick a range that culls front and back
    uSet = (UINT) ((uTest - 1) / uLocations) % NCSETS;

    m_Sprite.Ka.f = m_Coefficients[uSet].Ka.f;
    m_Sprite.Kb.f = m_Coefficients[uSet].Kb.f;
    m_Sprite.Kc.f = m_Coefficients[uSet].Kc.f;

    if (!CSprite::ExecuteTest(uTest))
        return false;

    sprintf(m_szBuffer, "(Ka,Kb,Kc)=(%f,%f,%f), distance %f",
            m_Sprite.Ka.f, m_Sprite.Kb.f, m_Sprite.Kc.f, dvDistance);
    BeginTestCase(m_szBuffer);

    SwitchAPI((UINT)m_fFrame);

    m_pDevice->SetViewport(&m_vpFull);
    m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET, RGB_MAKE(74, 150, 202), 1.0f, 0);

    m_pDevice->SetViewport(&m_vpTest);

    ClearFrame();

    if (BeginScene())
    {
        DWORD dwFormat = MYD3DFVF_LSVERTEX;
        MYD3DLSVERTEX Vertex;

        Vertex.dvX = m_From.x + EPSILON + dvDistance*m_LineOfSight.x;
        Vertex.dvY = m_From.y + EPSILON + dvDistance*m_LineOfSight.y;
        Vertex.dvZ = m_From.z + EPSILON + dvDistance*m_LineOfSight.z;
        Vertex.dcColor = m_Flags.bCheck(TEXTUREON) ? m_dcBackground : D3DCOLOR_RGBA(0,255,0,255);
        Vertex.dcSpecular = m_dcBackground;
        Vertex.dvTU = 0.0f;
        Vertex.dvTV = 0.0f;
#ifndef UNDER_XBOX
        Vertex.dvS = 2.0f;// A non-zero sensible value Chosen not to be 1;
#else

        m_pDevice->SetRenderState(D3DRS_POINTSIZE, F2DW(2.0f));
#endif

        if (!RenderPrimitive(D3DPT_POINTLIST, dwFormat, &Vertex, (DWORD) 1))
        {
            WriteToLog("RenderPrimitive() failed.\n");
            bResult = false;
        }

#ifdef UNDER_XBOX
        m_pDevice->SetRenderState(D3DRS_POINTSIZE, F2DW(1.0f));
#endif

        // Display the adapter mode
        ShowDisplayMode();

        // Display the frame rate
        ShowFrameRate();

        // Display the console
        m_pDisplay->ShowConsole();

        if (!EndScene())
        {
            WriteToLog("EndScene() failed.\n");
            bResult = false;
        }
    }
    else
    {
        WriteToLog("BeginScene() failed.\n");
        bResult = false;
    }

    // Update the screen
    m_pDevice->Present(NULL, NULL, NULL, NULL);

//    return bResult;
    return false;
}