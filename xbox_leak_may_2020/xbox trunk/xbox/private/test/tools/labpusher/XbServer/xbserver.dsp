# Microsoft Developer Studio Project File - Name="XbServer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Xbox Application" 0x0b01

CFG=XbServer - Xbox Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "XbServer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "XbServer.mak" CFG="XbServer - Xbox Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "XbServer - Xbox Release" (based on "Xbox Application")
!MESSAGE "XbServer - Xbox Debug" (based on "Xbox Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe

!IF  "$(CFG)" == "XbServer - Xbox Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "_XBOX" /D "NDEBUG" /YX /FD /G6 /Zvc6 /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "_XBOX" /D "NDEBUG" /YX /FD /G6 /Zvc6 /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 xapilib.lib d3d8.lib d3dx8.lib xgraphics.lib dsound.lib dmusic.lib xnet.lib xboxkrnl.lib /nologo /machine:I386 /subsystem:xbox /fixed:no /debugtype:vc6 /OPT:REF
# ADD LINK32 xapilib.lib d3d8.lib d3dx8.lib xgraphics.lib dsound.lib dmusic.lib xnet.lib xboxkrnl.lib /nologo /machine:I386 /subsystem:xbox /fixed:no /debugtype:vc6 /OPT:REF
XBE=imagebld.exe
# ADD BASE XBE /nologo /stack:0x10000
# ADD XBE /nologo /stack:0x10000
XBCP=xbecopy.exe
# ADD BASE XBCP /NOLOGO
# ADD XBCP /NOLOGO

!ELSEIF  "$(CFG)" == "XbServer - Xbox Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_XBOX" /D "_DEBUG" /YX /FD /G6 /Zvc6 /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "E:\source\public\ddk\inc" /I "E:\source\public\sdk\inc" /I "E:\source\private\ntos\inc" /I "E:\source\private\inc" /D "WIN32" /D "_XBOX" /D "_DEBUG" /D "XBOX" /FR /YX /FD /G6 /Zvc6 /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 xapilibd.lib d3d8d.lib d3dx8d.lib xgraphicsd.lib dsoundd.lib dmusicd.lib xnetd.lib xboxkrnl.lib /nologo /incremental:no /debug /machine:I386 /subsystem:xbox /fixed:no /debugtype:vc6
# ADD LINK32 xapilibd.lib d3d8d.lib d3dx8d.lib xnetd.lib xboxkrnl.lib xbdm.lib /nologo /incremental:no /debug /machine:I386 /subsystem:xbox /fixed:no /debugtype:vc6
# SUBTRACT LINK32 /pdb:none
XBE=imagebld.exe
# ADD BASE XBE /nologo /stack:0x10000 /debug
# ADD XBE /nologo /testname:"LabPusher" /stack:0x10000 /debug
XBCP=xbecopy.exe
# ADD BASE XBCP /NOLOGO
# ADD XBCP /NOLOGO

!ENDIF 

# Begin Target

# Name "XbServer - Xbox Release"
# Name "XbServer - Xbox Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\flashrom.cpp
# End Source File
# Begin Source File

SOURCE=.\graphics.cpp
# End Source File
# Begin Source File

SOURCE=.\mapdrives.cpp
# End Source File
# Begin Source File

SOURCE=.\setled.cpp
# End Source File
# Begin Source File

SOURCE=.\xbserver.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\xbserver.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
