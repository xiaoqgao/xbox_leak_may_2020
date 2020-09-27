# Microsoft Developer Studio Generated NMAKE File, Based on Shader.dsp
!IF "$(CFG)" == ""
CFG=Shader - Win32 Hybrid
!MESSAGE No configuration specified. Defaulting to Shader - Win32 Hybrid.
!ENDIF 

!IF "$(CFG)" != "Shader - Win32 Release" && "$(CFG)" != "Shader - Win32 Debug" && "$(CFG)" != "Shader - Win32 Hybrid"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Shader.mak" CFG="Shader - Win32 Hybrid"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Shader - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Shader - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Shader - Win32 Hybrid" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Shader - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\..\..\plugin\Shader_skeleton.dlb"


CLEAN :
	-@erase "$(INTDIR)\Dialog.obj"
	-@erase "$(INTDIR)\Eval.obj"
	-@erase "$(INTDIR)\GetSet.obj"
	-@erase "$(INTDIR)\Plugin.obj"
	-@erase "$(INTDIR)\Shader.obj"
	-@erase "$(INTDIR)\Shader.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Shader_skeleton.exp"
	-@erase "$(OUTDIR)\Shader_skeleton.lib"
	-@erase "..\..\..\..\plugin\Shader_skeleton.dlb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G6 /MD /W3 /GX /O2 /I "..\..\..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SHADER_EXPORTS" /Fp"$(INTDIR)\Shader.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\Shader.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Shader.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=maxscrpt.lib paramblk2.lib core.lib geom.lib gfx.lib maxutil.lib bmm.lib comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x08C10000" /dll /incremental:no /pdb:"$(OUTDIR)\Shader_skeleton.pdb" /machine:I386 /def:".\Plugin.def" /out:"..\..\..\..\plugin\Shader_skeleton.dlb" /implib:"$(OUTDIR)\Shader_skeleton.lib" /libpath:"..\..\..\..\lib" /release 
DEF_FILE= \
	".\Plugin.def"
LINK32_OBJS= \
	"$(INTDIR)\Dialog.obj" \
	"$(INTDIR)\Eval.obj" \
	"$(INTDIR)\GetSet.obj" \
	"$(INTDIR)\Plugin.obj" \
	"$(INTDIR)\Shader.obj" \
	"$(INTDIR)\Shader.res"

"..\..\..\..\plugin\Shader_skeleton.dlb" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Shader - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\..\..\plugin\Shader_skeleton.dlb"


CLEAN :
	-@erase "$(INTDIR)\Dialog.obj"
	-@erase "$(INTDIR)\Eval.obj"
	-@erase "$(INTDIR)\GetSet.obj"
	-@erase "$(INTDIR)\Plugin.obj"
	-@erase "$(INTDIR)\Shader.obj"
	-@erase "$(INTDIR)\Shader.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Shader_skeleton.exp"
	-@erase "$(OUTDIR)\Shader_skeleton.lib"
	-@erase "$(OUTDIR)\Shader_skeleton.pdb"
	-@erase "..\..\..\..\plugin\Shader_skeleton.dlb"
	-@erase "..\..\..\..\plugin\Shader_skeleton.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /I "..\..\..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SHADER_EXPORTS" /Fp"$(INTDIR)\Shader.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\Shader.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Shader.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=maxscrpt.lib paramblk2.lib core.lib geom.lib gfx.lib maxutil.lib bmm.lib comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x08C10000" /dll /incremental:yes /pdb:"$(OUTDIR)\Shader_skeleton.pdb" /debug /machine:I386 /def:".\Plugin.def" /out:"..\..\..\..\plugin\Shader_skeleton.dlb" /implib:"$(OUTDIR)\Shader_skeleton.lib" /pdbtype:sept /libpath:"..\..\..\..\lib" 
DEF_FILE= \
	".\Plugin.def"
LINK32_OBJS= \
	"$(INTDIR)\Dialog.obj" \
	"$(INTDIR)\Eval.obj" \
	"$(INTDIR)\GetSet.obj" \
	"$(INTDIR)\Plugin.obj" \
	"$(INTDIR)\Shader.obj" \
	"$(INTDIR)\Shader.res"

"..\..\..\..\plugin\Shader_skeleton.dlb" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Shader - Win32 Hybrid"

OUTDIR=.\Hybrid
INTDIR=.\Hybrid

ALL : "..\..\..\..\plugin\Shader_skeleton.dlb"


CLEAN :
	-@erase "$(INTDIR)\Dialog.obj"
	-@erase "$(INTDIR)\Eval.obj"
	-@erase "$(INTDIR)\GetSet.obj"
	-@erase "$(INTDIR)\Plugin.obj"
	-@erase "$(INTDIR)\Shader.obj"
	-@erase "$(INTDIR)\Shader.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Shader_skeleton.exp"
	-@erase "$(OUTDIR)\Shader_skeleton.lib"
	-@erase "$(OUTDIR)\Shader_skeleton.pdb"
	-@erase "..\..\..\..\plugin\Shader_skeleton.dlb"
	-@erase "..\..\..\..\plugin\Shader_skeleton.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /G6 /MD /W3 /Gm /GX /ZI /Od /I "..\..\..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SHADER_EXPORTS" /Fp"$(INTDIR)\Shader.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\Shader.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Shader.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=maxscrpt.lib paramblk2.lib core.lib geom.lib gfx.lib maxutil.lib bmm.lib comctl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x08C10000" /dll /incremental:yes /pdb:"$(OUTDIR)\Shader_skeleton.pdb" /debug /machine:I386 /def:".\Plugin.def" /out:"..\..\..\..\plugin\Shader_skeleton.dlb" /implib:"$(OUTDIR)\Shader_skeleton.lib" /pdbtype:sept /libpath:"..\..\..\..\lib" 
DEF_FILE= \
	".\Plugin.def"
LINK32_OBJS= \
	"$(INTDIR)\Dialog.obj" \
	"$(INTDIR)\Eval.obj" \
	"$(INTDIR)\GetSet.obj" \
	"$(INTDIR)\Plugin.obj" \
	"$(INTDIR)\Shader.obj" \
	"$(INTDIR)\Shader.res"

"..\..\..\..\plugin\Shader_skeleton.dlb" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Shader.dep")
!INCLUDE "Shader.dep"
!ELSE 
!MESSAGE Warning: cannot find "Shader.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Shader - Win32 Release" || "$(CFG)" == "Shader - Win32 Debug" || "$(CFG)" == "Shader - Win32 Hybrid"
SOURCE=.\Dialog.cpp

"$(INTDIR)\Dialog.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Eval.cpp

"$(INTDIR)\Eval.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\GetSet.cpp

"$(INTDIR)\GetSet.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Plugin.cpp

"$(INTDIR)\Plugin.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Shader.cpp

"$(INTDIR)\Shader.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Shader.rc

"$(INTDIR)\Shader.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

