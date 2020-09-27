# Microsoft Developer Studio Generated NMAKE File, Based on Aiimp.dsp
!IF "$(CFG)" == ""
CFG=aiimp - Win32 Release
!MESSAGE No configuration specified. Defaulting to aiimp - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "aiimp - Win32 Release" && "$(CFG)" != "aiimp - Win32 Debug" && "$(CFG)" != "aiimp - Win32 Hybrid"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Aiimp.mak" CFG="aiimp - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "aiimp - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "aiimp - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "aiimp - Win32 Hybrid" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "aiimp - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\..\maxsdk\plugin\aiimp.dli"


CLEAN :
	-@erase "$(INTDIR)\aiimp.obj"
	-@erase "$(INTDIR)\aiimp.res"
	-@erase "$(OUTDIR)\aiimp.exp"
	-@erase "$(OUTDIR)\aiimp.lib"
	-@erase "..\..\..\maxsdk\plugin\aiimp.dli"
	-@erase ".\aiimp.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G6 /MD /W3 /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fo"$(INTDIR)\\" /Fd"aiimp.pdb" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\aiimp.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aiimp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x05EF0000" /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\aiimp.pdb" /machine:I386 /def:".\aiimp.def" /out:"..\..\..\maxsdk\plugin\aiimp.dli" /implib:"$(OUTDIR)\aiimp.lib" /release 
DEF_FILE= \
	".\aiimp.def"
LINK32_OBJS= \
	"$(INTDIR)\aiimp.obj" \
	"$(INTDIR)\aiimp.res" \
	"..\..\Lib\core.lib" \
	"..\..\Lib\geom.lib" \
	"..\..\Lib\gfx.lib" \
	"..\..\Lib\maxutil.lib"

"..\..\..\maxsdk\plugin\aiimp.dli" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "aiimp - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\..\maxsdk\plugin\aiimp.dli"


CLEAN :
	-@erase "$(INTDIR)\aiimp.obj"
	-@erase "$(INTDIR)\aiimp.res"
	-@erase "$(OUTDIR)\aiimp.exp"
	-@erase "$(OUTDIR)\aiimp.lib"
	-@erase "$(OUTDIR)\aiimp.pdb"
	-@erase "..\..\..\maxsdk\plugin\aiimp.dli"
	-@erase "..\..\..\maxsdk\plugin\aiimp.ilk"
	-@erase ".\aiimp.idb"
	-@erase ".\aiimp.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G6 /MDd /W3 /Gm /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fo"$(INTDIR)\\" /Fd"aiimp.pdb" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\aiimp.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aiimp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x05EF0000" /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\aiimp.pdb" /debug /machine:I386 /def:".\aiimp.def" /out:"..\..\..\maxsdk\plugin\aiimp.dli" /implib:"$(OUTDIR)\aiimp.lib" 
DEF_FILE= \
	".\aiimp.def"
LINK32_OBJS= \
	"$(INTDIR)\aiimp.obj" \
	"$(INTDIR)\aiimp.res" \
	"..\..\Lib\core.lib" \
	"..\..\Lib\geom.lib" \
	"..\..\Lib\gfx.lib" \
	"..\..\Lib\maxutil.lib"

"..\..\..\maxsdk\plugin\aiimp.dli" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "aiimp - Win32 Hybrid"

OUTDIR=.\Hybrid
INTDIR=.\Hybrid

ALL : "..\..\..\maxsdk\plugin\aiimp.dli"


CLEAN :
	-@erase "$(INTDIR)\aiimp.obj"
	-@erase "$(INTDIR)\aiimp.res"
	-@erase "$(OUTDIR)\aiimp.exp"
	-@erase "$(OUTDIR)\aiimp.lib"
	-@erase "$(OUTDIR)\aiimp.pdb"
	-@erase "..\..\..\maxsdk\plugin\aiimp.dli"
	-@erase "..\..\..\maxsdk\plugin\aiimp.ilk"
	-@erase ".\aiimp.idb"
	-@erase ".\aiimp.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G6 /MD /W3 /Gm /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fo"$(INTDIR)\\" /Fd"aiimp.pdb" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\aiimp.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aiimp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x05EF0000" /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\aiimp.pdb" /debug /machine:I386 /def:".\aiimp.def" /out:"..\..\..\maxsdk\plugin\aiimp.dli" /implib:"$(OUTDIR)\aiimp.lib" 
DEF_FILE= \
	".\aiimp.def"
LINK32_OBJS= \
	"$(INTDIR)\aiimp.obj" \
	"$(INTDIR)\aiimp.res" \
	"..\..\Lib\core.lib" \
	"..\..\Lib\geom.lib" \
	"..\..\Lib\gfx.lib" \
	"..\..\Lib\maxutil.lib"

"..\..\..\maxsdk\plugin\aiimp.dli" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Aiimp.dep")
!INCLUDE "Aiimp.dep"
!ELSE 
!MESSAGE Warning: cannot find "Aiimp.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "aiimp - Win32 Release" || "$(CFG)" == "aiimp - Win32 Debug" || "$(CFG)" == "aiimp - Win32 Hybrid"
SOURCE=.\aiimp.cpp

"$(INTDIR)\aiimp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\aiimp.rc

"$(INTDIR)\aiimp.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

