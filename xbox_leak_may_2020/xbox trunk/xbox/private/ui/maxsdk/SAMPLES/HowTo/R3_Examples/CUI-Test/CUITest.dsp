# Microsoft Developer Studio Project File - Name="CUITest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=CUITest - Win32 Hybrid
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CUITest.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CUITest.mak" CFG="CUITest - Win32 Hybrid"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CUITest - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CUITest - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CUITest - Win32 Hybrid" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CUITest - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /Gm /GX /Zi /O2 /I "..\..\..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 COMCTL32.LIB KERNEL32.LIB USER32.LIB GDI32.LIB WINSPOOL.LIB COMDLG32.LIB ADVAPI32.LIB SHELL32.LIB OLE32.LIB OLEAUT32.LIB UUID.LIB bmm.lib core.lib geom.lib gfx.lib mesh.lib maxutil.lib maxscrpt.lib /nologo /base:"0x087B0000" /subsystem:windows /dll /machine:I386 /out:"..\..\..\..\plugin\CUITest.dlu" /libpath:"..\..\..\..\lib" /release
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "CUITest - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /Zi /Od /I "..\..\..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 COMCTL32.LIB KERNEL32.LIB USER32.LIB GDI32.LIB WINSPOOL.LIB COMDLG32.LIB ADVAPI32.LIB SHELL32.LIB OLE32.LIB OLEAUT32.LIB UUID.LIB bmm.lib core.lib geom.lib gfx.lib mesh.lib maxutil.lib maxscrpt.lib /nologo /base:"0x087B0000" /subsystem:windows /dll /debug /machine:I386 /out:"..\..\..\..\plugin\CUITest.dlu" /pdbtype:sept /libpath:"..\..\..\..\lib"

!ELSEIF  "$(CFG)" == "CUITest - Win32 Hybrid"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "CUITest___Win32_Hybrid"
# PROP BASE Intermediate_Dir "CUITest___Win32_Hybrid"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Hybrid"
# PROP Intermediate_Dir "Hybrid"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G6 /MDd /W3 /Gm /GX /Zi /Od /I "..\..\..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MD /W3 /Gm /GX /Zi /Od /I "..\..\..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 COMCTL32.LIB KERNEL32.LIB USER32.LIB GDI32.LIB WINSPOOL.LIB COMDLG32.LIB ADVAPI32.LIB SHELL32.LIB OLE32.LIB OLEAUT32.LIB UUID.LIB bmm.lib core.lib geom.lib gfx.lib mesh.lib maxutil.lib maxscrpt.lib /nologo /base:"0x087B0000" /subsystem:windows /dll /debug /machine:I386 /out:"..\..\..\..\plugin\CUITest.dlu" /pdbtype:sept /libpath:"..\..\..\..\lib"
# ADD LINK32 COMCTL32.LIB KERNEL32.LIB USER32.LIB GDI32.LIB WINSPOOL.LIB COMDLG32.LIB ADVAPI32.LIB SHELL32.LIB OLE32.LIB OLEAUT32.LIB UUID.LIB bmm.lib core.lib geom.lib gfx.lib mesh.lib maxutil.lib maxscrpt.lib /nologo /base:"0x087B0000" /subsystem:windows /dll /debug /machine:I386 /out:"..\..\..\..\plugin\CUITest.dlu" /pdbtype:sept /libpath:"..\..\..\..\lib"

!ENDIF 

# Begin Target

# Name "CUITest - Win32 Release"
# Name "CUITest - Win32 Debug"
# Name "CUITest - Win32 Hybrid"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CUITest.cpp
# End Source File
# Begin Source File

SOURCE=.\CUITest.def
# End Source File
# Begin Source File

SOURCE=.\Plugin.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CUITest.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\CUITest.rc
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# End Group
# End Target
# End Project
