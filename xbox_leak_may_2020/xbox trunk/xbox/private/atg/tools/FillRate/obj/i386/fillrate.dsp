# Microsoft Developer Studio Project File - Name="FillRate Tool" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Xbox Application" 0x0b01

CFG=FillRate Tool - Xbox Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FillRate Tool.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FillRate Tool.mak" CFG="FillRate Tool - Xbox Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FillRate Tool - Xbox Release" (based on "Xbox Application")
!MESSAGE "FillRate Tool - Xbox Debug" (based on "Xbox Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe

!IF  "$(CFG)" == "FillRate Tool - Xbox Release"


# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Zvc6 /O2 /D "WIN32" /D "_USE_XGMATH" /D "_XBOX" /D "NDEBUG" /YX /FD /G6 /c
# ADD CPP /nologo /W3 /GX /Zvc6 /O2 /I "..\..\samples\Common\include" /D "WIN32" /D "_USE_XGMATH" /D "_XBOX" /D "NDEBUG" /YX /FD /G6 /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 xapilib.lib d3d8.lib d3dx8.lib xgraphics.lib dsound.lib dmusic.lib xboxkrnl.lib /nologo /incremental:no /machine:I386 /subsystem:xbox  /opt:ref /fixed:no /debugtype:vc6
# ADD LINK32 xapilib.lib d3d8.lib d3dx8.lib xgraphics.lib dsound.lib dmusic.lib xboxkrnl.lib  /nologo /incremental:no /machine:I386 /subsystem:xbox  /opt:ref /fixed:no /debugtype:vc6
XBE=imagebld.exe
# ADD BASE XBE /nologo /stack:0x10000
# ADD XBE /nologo /testid:"0xffff34f1" /testname:"FillRate Tool" /stack:0x10000 /INITFLAGS:0x00000000  /out:"Release/fillrate.xbe"
XBCP=xbecopy.exe
# ADD BASE XBCP /NOLOGO
# ADD XBCP /NOLOGO


!ELSEIF  "$(CFG)" == "FillRate Tool - Xbox Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Zvc6 /Od /D "WIN32" /D "_USE_XGMATH" /D "_XBOX" /D "_DEBUG" /YX /FD /G6 /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Zvc6 /Od /I "..\..\samples\Common\include" /D "WIN32" /D "_USE_XGMATH" /D "_XBOX" /D "_DEBUG" /YX /FD /G6 /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 xapilibd.lib d3d8d.lib d3dx8d.lib xgraphicsd.lib dsoundd.lib dmusicd.lib xboxkrnl.lib /nologo /incremental:no /debug /machine:I386 /subsystem:xbox  /fixed:no /debugtype:vc6
# ADD LINK32 xapilibd.lib d3d8d.lib d3dx8d.lib xgraphicsd.lib dsoundd.lib dmusicd.lib xboxkrnl.lib  /nologo /incremental:no /debug /machine:I386 /subsystem:xbox  /fixed:no /debugtype:vc6
XBE=imagebld.exe
# ADD BASE XBE /nologo /stack:0x10000 /debug
# ADD XBE /nologo /testid:"0xffff34f1" /testname:"FillRate Tool" /stack:0x10000 /debug /INITFLAGS:0x00000000  /out:"Debug/fillrate.xbe"
XBCP=xbecopy.exe
# ADD BASE XBCP /NOLOGO
# ADD XBCP /NOLOGO


!ENDIF 

# Begin Target

# Name "FillRate Tool - Xbox Release"
# Name "FillRate Tool - Xbox Debug"

# Begin Source File

SOURCE=.\fillrate.cpp
# End Source File
# Begin Source File

SOURCE=.\fillrate.h
# End Source File
# Begin Source File

SOURCE=.\bitfont.cpp
# End Source File
# Begin Source File

SOURCE=.\bitfont.h
# End Source File
# Begin Source File

SOURCE=.\inifile.cpp
# End Source File
# Begin Source File

SOURCE=.\inifile.h
# End Source File
# Begin Source File

SOURCE=.\utils.cpp
# End Source File
# Begin Source File

SOURCE=.\utils.h
# End Source File
# End Target
# End Project
)

