# Microsoft Developer Studio Project File - Name="pack1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=pack1 - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Pack1.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Pack1.mak" CFG="pack1 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pack1 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "pack1 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "pack1 - Win32 Hybrid" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pack1 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /G6 /MD /W3 /O2 /I "..\..\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "WIN32_LEAN_AND_MEAN" /Yu"pack1.h" /Fd"pack1.pdb" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x232a0000" /subsystem:windows /dll /machine:I386 /out:"..\..\..\maxsdk\plugin\update1.dlo" /release

!ELSEIF  "$(CFG)" == "pack1 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /Fd"pack1.pdb" /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /ZI /Od /I "..\..\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WIN32_LEAN_AND_MEAN" /Fd"pack1.pdb" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x232a0000" /subsystem:windows /dll /debug /machine:I386 /out:"..\..\..\maxsdk\plugin\update1.dlo"

!ELSEIF  "$(CFG)" == "pack1 - Win32 Hybrid"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\prim___W"
# PROP BASE Intermediate_Dir ".\prim___W"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Hybrid"
# PROP Intermediate_Dir ".\Hybrid"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G5 /MD /W3 /Gm /GX /Zi /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"pack1.h" /Fd"pack1.pdb" /c
# ADD CPP /nologo /G6 /MD /W3 /Gm /ZI /Od /I "..\..\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WIN32_LEAN_AND_MEAN" /Yu"pack1.h" /Fd"pack1.pdb" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"..\..\..\maxsdk\plugin\pack1.dlo"
# ADD LINK32 comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x232a0000" /subsystem:windows /dll /debug /machine:I386 /out:"..\..\..\maxsdk\plugin\update1.dlo"

!ENDIF 

# Begin Target

# Name "pack1 - Win32 Release"
# Name "pack1 - Win32 Debug"
# Name "pack1 - Win32 Hybrid"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\approxui.cpp
# End Source File
# Begin Source File

SOURCE=.\pack1.cpp
# ADD CPP /Yc"pack1.h"
# End Source File
# Begin Source File

SOURCE=.\pack1.def
# End Source File
# Begin Source File

SOURCE=.\pack1.h
# End Source File
# Begin Source File

SOURCE=.\pack1.rc
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\triedui.cpp
# End Source File
# Begin Source File

SOURCE=.\triobjed.cpp
# End Source File
# Begin Source File

SOURCE=.\triops.cpp
# End Source File
# Begin Source File

SOURCE=..\..\lib\bmm.lib
# End Source File
# Begin Source File

SOURCE=..\..\lib\core.lib
# End Source File
# Begin Source File

SOURCE=..\..\lib\geom.lib
# End Source File
# Begin Source File

SOURCE=..\..\lib\gfx.lib
# End Source File
# Begin Source File

SOURCE=..\..\lib\Maxscrpt.lib
# End Source File
# Begin Source File

SOURCE=..\..\lib\mesh.lib
# End Source File
# Begin Source File

SOURCE=..\..\lib\maxutil.lib
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=..\..\Include\box3.h
# End Source File
# Begin Source File

SOURCE=..\..\Include\matrix3.h
# End Source File
# Begin Source File

SOURCE=..\..\Include\mesh.h
# End Source File
# Begin Source File

SOURCE=..\..\Include\meshadj.h
# End Source File
# Begin Source File

SOURCE=..\..\Include\MeshDelta.h
# End Source File
# Begin Source File

SOURCE=..\..\Include\point3.h
# End Source File
# Begin Source File

SOURCE=..\..\Include\tab.h
# End Source File
# Begin Source File

SOURCE=.\triobjed.h
# End Source File
# Begin Source File

SOURCE=..\..\Include\vedge.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\addvertc.cur
# End Source File
# Begin Source File

SOURCE=.\Bevel.cur
# End Source File
# Begin Source File

SOURCE=.\cur00001.cur
# End Source File
# Begin Source File

SOURCE=.\echamfer.cur
# End Source File
# Begin Source File

SOURCE=.\extrudec.cur
# End Source File
# Begin Source File

SOURCE=.\faceselt.bmp
# End Source File
# Begin Source File

SOURCE=.\selmask.bmp
# End Source File
# Begin Source File

SOURCE=.\vchamfer.cur
# End Source File
# End Group
# End Target
# End Project
