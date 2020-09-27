# Shell DLL build
#
# Usage:
#
# nmake /f shl.mk [all]             Build the DLL
# nmake /f shl.mk ssync             Ssync the files needed to build this DLL
# nmake /f shl.mk slmout            Check out the files that are built by this makefile
# nmake /f shl.mk slmin             Check in the files that are built by this makefile
# nmake /f shl.mk clean             Clean the project
# nmake /f shl.mk auto.dep			Generate dependencies file (auto.dep)
#
#
# Additional command line defines: * indicates default
#
# DEBUG=	[ 0* | 1 | 2 ]			Build debug (0), retail (1), or retail with debug info (2)
# BROWSE=	[ 0* | 1 ]				Build with browse information (1)
# PLATFORM= [ X86*, MIPS, ALPHA ]	Specify the platform
# DEPEND=   [ 0 | 1* ]				Indicate whether to include dependent projects (1) or not (0)
#

# ---------------------------------------------
# ensure all defines are defined
# ---------------------------------------------
!ifndef DEBUG
!message DEBUG not defined; defaulting to DEBUG=0
DEBUG=0
!endif
!ifndef BROWSE
!message BROWSE not defined; defaulting to BROWSE=0
BROWSE=0
!endif
!ifndef DEPEND
!message DEPEND not defined; defaulting to DEPEND=1
DEPEND=1
!endif
!ifndef PLATFORM
!ifndef PROCESSOR_ARCHITECTURE
!message PLATFORM or PROCESSOR_ARCHITECTURE not defined; defaulting to PLATFORM=x86
PLATFORM=x86
!else
PLATFORM=$(PROCESSOR_ARCHITECTURE)
!endif
!endif

!ifndef IDESRCDIR
!message IDESRCDIR not defined; defaulting to IDESRCDIR=\ide
IDESRCDIR=\ide
!endif
!ifndef V4LOW
!message V4LOW not defined; defaulting to V4LOW=0
V4LOW=0
!endif

IDELOC=$(IDESRCDIR)\localize

# ---------------------------------------------
# define relative CAFE directories
# ---------------------------------------------
CAFE_INCLUDE=..\..\..\..\..\include
CAFE_TARGET=..\..\..
CAFE_GUI=..\..
CAFE_IDE=..
CAFE_SYM=..\sym
CAFE_SHL=.
CAFE_EDS=..\eds
CAFE_PRJ=..\prj
CAFE_DBG=..\dbg
CAFE_TOOLSET=..\..

EXEDIR=..\..\..\..\..\bin
LIBDIR=..\..\..\..\..\lib

# ---------------------------------------------
# define toolset
# ---------------------------------------------
COMPILER=cl.exe
LINKER=link.exe
RC=rc.exe
BSC=bscmake.exe

# ---------------------------------------------
# set up debug/retail defines
# ---------------------------------------------
!if "$(DEBUG)" == "0"
OBJDIR=WinRel
TARGET=shl
CPP_FLAGS=-Od -DNDEBUG -MD
LINK_FLAGS=-incremental:no
!elseif "$(DEBUG)" == "1"
OBJDIR=WinDebug
TARGET=shld
CPP_FLAGS=-Zi -Od -D_DEBUG -MDd
LINK_FLAGS=-incremental:yes -debug
!else
OBJDIR=WinRel
TARGET=shl
CPP_FLAGS=-Zi -Od -DNDEBUG -MD
LINK_FLAGS=-incremental:no -debug
!endif

# ---------------------------------------------
# set up platform-specific defines
# ---------------------------------------------
!if "$(PLATFORM)" == "x86"
!if "$(DEBUG)" != "0"
!message Shell: MR enabled
CPP_FLAGS=$(CPP_FLAGS) -Gm
!endif
!endif

# ---------------------------------------------
# set up platform defines
# ---------------------------------------------
#!if "$(PLATFORM)" == "MIPS"
#RT=rt_mips.exe
#!elseif "$(PLATFORM)" == "ALPHA"
#RT=rt_alpha.exe
#!else
#RT=rt.exe
#!endif

# ---------------------------------------------
# set up browse info defines
# ---------------------------------------------
!if "$(BROWSE)" == "0"
BSC_FLAGS=
!else
CPP_FLAGS=$(CPP_FLAGS) -FR$(OBJDIR)^\
BSC_FLAGS=-o$(OBJDIR)\$(TARGET).bsc
!endif

# ---------------------------------------------
# set up toolset flags
# ---------------------------------------------
CPP_FLAGS=$(CPP_FLAGS) -nologo -W3 -GR -GX -DWIN32 -D_WINDOWS -D_AFXDLL -D_MBCS -D_AFXEXT -DEXPORT_SHELL -Fp$(OBJDIR)\$(TARGET).pch -Fo$(OBJDIR)^\ -Fd$(OBJDIR)\$(TARGET).pdb -c
CPP_CREATE_PCH_FLAGS=$(CPP_FLAGS) -Ycstdafx.h
CPP_FLAGS=$(CPP_FLAGS) -Yustdafx.h
LINK_FLAGS=$(LINK_FLAGS) -nologo -subsystem:windows -dll -out:$(EXEDIR)\$(TARGET).dll -pdb:$(EXEDIR)\$(TARGET).pdb -implib:$(LIBDIR)\$(TARGET).lib
RC_FLAGS=/l 0x409 /fo$(OBJDIR)\wb.res /dNDEBUG /d_AFXDLL
BSC_FLAGS=$(BSC_FLAGS) -nologo
# ---------------------------------------------
# set up V4Low flags
# ---------------------------------------------
!if "$(V4LOW)" == "1"
CPP_FLAGS=$(CPP_FLAGS) -DV4LOW
!endif

!if "$(V4LOW)" == "1"
RC_FLAGS=$(RC_FLAGS) /dV4LOW
!endif

# ---------------------------------------------
# define objs
# ---------------------------------------------
OBJFILES= \
	$(OBJDIR)\wb.res       \
	$(OBJDIR)\cmdarray.obj \
	$(OBJDIR)\cowrkspc.obj \
	$(OBJDIR)\stdafx.obj   \
	$(OBJDIR)\ucommdlg.obj \
	$(OBJDIR)\ucustdlg.obj \
	$(OBJDIR)\udockwnd.obj \
	$(OBJDIR)\uioutput.obj \
	$(OBJDIR)\uitabdlg.obj \
	$(OBJDIR)\uiwbdlg.obj  \
	$(OBJDIR)\uiwbmsg.obj  \
	$(OBJDIR)\umainfrm.obj \
	$(OBJDIR)\utbardlg.obj \
	$(OBJDIR)\utoolbar.obj \
	$(OBJDIR)\uwbframe.obj \
	$(OBJDIR)\wbutil.obj   \
	$(OBJDIR)\upropwnd.obj \
	$(OBJDIR)\uioptdlg.obj \
	$(OBJDIR)\newfldlg.obj \
	$(OBJDIR)\uiconnec.obj \
	$(OBJDIR)\coconnec.obj \
	$(OBJDIR)\coenv.obj    \
	$(OBJDIR)\uiconset.obj \
	$(OBJDIR)\shl.obj      \
	$(OBJDIR)\uitipdlg.obj \
	$(OBJDIR)\uopenwrk.obj

# ---------------------------------------------
# define sbrs
# ---------------------------------------------
SBRFILES= \
	$(OBJDIR)\cmdarray.sbr \
	$(OBJDIR)\cowrkspc.sbr \
	$(OBJDIR)\stdafx.sbr   \
	$(OBJDIR)\ucommdlg.sbr \
	$(OBJDIR)\ucustdlg.sbr \
	$(OBJDIR)\udockwnd.sbr \
	$(OBJDIR)\uioutput.sbr \
	$(OBJDIR)\uitabdlg.sbr \
	$(OBJDIR)\uiwbdlg.sbr  \
	$(OBJDIR)\uiwbmsg.sbr  \
	$(OBJDIR)\umainfrm.sbr \
	$(OBJDIR)\utbardlg.sbr \
	$(OBJDIR)\utoolbar.sbr \
	$(OBJDIR)\uwbframe.sbr \
	$(OBJDIR)\wbutil.sbr   \
	$(OBJDIR)\upropwnd.sbr \
	$(OBJDIR)\uioptdlg.sbr \
	$(OBJDIR)\newfldlg.sbr \
	$(OBJDIR)\uiconnec.sbr \
	$(OBJDIR)\coconnec.sbr \
	$(OBJDIR)\coenv.sbr \
	$(OBJDIR)\uiconset.sbr \
	$(OBJDIR)\shl.sbr      \
	$(OBJDIR)\uitipdlg.sbr \
	$(OBJDIR)\uopenwrk.sbr


# ---------------------------------------------
# ---------------------------------------------
# rules
# ---------------------------------------------

.c{$(OBJDIR)}.obj:
   @$(COMPILER) -FIstdafx.h -FIW32Repl.h $(CPP_FLAGS) $<

.cpp{$(OBJDIR)}.obj:
   @$(COMPILER) -FIstdafx.h -FIW32Repl.h $(CPP_FLAGS) $<

.cxx{$(OBJDIR)}.obj:
   @$(COMPILER) -FIstdafx.h -FIW32Repl.h $(CPP_FLAGS) $<


# ---------------------------------------------
# ---------------------------------------------
# targets
# ---------------------------------------------

all: dependencies $(EXEDIR)\$(TARGET).dll

# ---------------------------------------------
# build dependencies
# ---------------------------------------------
dependencies:
!if "$(DEPEND)" == "1"
	@echo Shell: building dependencies...
# GUI DLL
	@cd $(CAFE_GUI)
	@$(MAKE) -nologo -$(MAKEFLAGS) -f gui.mk DEBUG=$(DEBUG) BROWSE=$(BROWSE) PLATFORM=$(PLATFORM) DEPEND=$(DEPEND)
	@cd $(MAKEDIR)
!endif

# ---------------------------------------------
# build norc.exe
# ---------------------------------------------
#norc.exe: norc.c
#	@echo Shell: building norc.exe...
#	@$(COMPILER) -nologo norc.c

# ---------------------------------------------
# build target DLL
# ---------------------------------------------
$(EXEDIR)\$(TARGET).dll: $(OBJDIR) $(OBJDIR)\$(TARGET).pch $(OBJFILES)
	@echo Shell: linking DLL...
	@-if exist $(EXEDIR)\$(TARGET).dll attrib -r $(EXEDIR)\$(TARGET).dll
	@-if exist $(EXEDIR)\$(TARGET).pdb attrib -r $(EXEDIR)\$(TARGET).pdb
	@-if exist $(LIBDIR)\$(TARGET).lib attrib -r $(LIBDIR)\$(TARGET).lib
	@$(LINKER) @<<
		$(LINK_FLAGS) $(OBJFILES)
<<
# ---------------------------------------------
# build BSC
# ---------------------------------------------
!if "$(BROWSE)" == "1"
	@echo Shell: creating BSC...
	@$(BSC) @<<
		$(BSC_FLAGS) $(SBRFILES)
<<
!endif

# ---------------------------------------------
# object file targets
# ---------------------------------------------

#cmdarryj.cpp: cmdarray.cpp $(IDELOC)\japan.lng
#	@echo Translating CMDARRAY.CPP to CMDARRYJ.CPP...
#	@$(IDELOC)\$(RT) -h $(IDELOC)\japan.lng cmdarray.cpp cmdarryj.cpp
#	@echo

#wbus.cpp: wbus.rc $(IDELOC)\japan.lng
#	@echo Generating WBUS.CPP from WBUS.RC...
#	@norc <wbus.rc >wbus.cpp

#wbj.cpp: wbus.cpp $(IDELOC)\japan.lng
#	@echo Translating WBUS.CPP to WBJ.CPP...
#	@$(IDELOC)\$(RT) -h $(IDELOC)\japan.lng wbus.cpp wbj.cpp

!if exist(auto.dep)
!include auto.dep
!else
!message Note: no AUTO.DEP currently exists
!endif

#$(OBJDIR)\cmdarray.obj:
#	@$(CPP) $(CPP_FLAGS) -DCMDTABLE=m_aCmdTable cmdarray.cpp

#$(OBJDIR)\cmdarryj.obj:
#	@$(CPP) $(CPP_FLAGS) -DCMDTABLE=m_aCmdTableJ cmdarryj.cpp

#$(OBJDIR)\wbj.obj:             
#	@$(CPP) $(CPP_FLAGS) -DLOCSTRTABLE=m_aLocStrJ wbj.cpp

#$(OBJDIR)\wbus.obj:            
#	@$(CPP) $(CPP_FLAGS) -DLOCSTRTABLE=m_aLocStr wbus.cpp

$(OBJDIR)\wb.res:             \
	wb.rc
	@echo Shell: compiling resources...
	@$(RC) $(RC_FLAGS) wb.rc

# ---------------------------------------------
# create object file directory
# ---------------------------------------------
$(OBJDIR):
	@if not exist $(OBJDIR)\nul mkdir $(OBJDIR)

# ---------------------------------------------
# ssync
# ---------------------------------------------
ssync: ssync.depend
	@echo Shell: ssyncing DLL...
	-ssync -f
	@cd $(CAFE_INCLUDE)
	-ssync -fr
	@cd $(MAKEDIR)

# ---------------------------------------------
# dependency ssync
# ---------------------------------------------
ssync.depend:
!if "$(DEPEND)" == "1"
	@echo Shell: ssynching dependencies...
	@cd $(CAFE_GUI)
	@$(MAKE) -nologo -$(MAKEFLAGS) -f gui.mk DEBUG=$(DEBUG) BROWSE=$(BROWSE) PLATFORM=$(PLATFORM) DEPEND=$(DEPEND) ssync
	@cd $(MAKEDIR)
!endif

# ---------------------------------------------
# slmout
# ---------------------------------------------
slmout: slmout.depend
	@echo Shell: checking out DLL...
	@cd $(EXEDIR)
	-out -f $(TARGET).dll $(TARGET).pdb
	@cd $(MAKEDIR)
	@cd $(LIBDIR)
	-out -f $(TARGET).lib
	@cd $(MAKEDIR)

# ---------------------------------------------
# dependency slmout
# ---------------------------------------------
slmout.depend:
!if "$(DEPEND)" == "1"
	@echo Shell: checking out dependencies...
	@cd $(CAFE_GUI)
	@$(MAKE) -nologo -$(MAKEFLAGS) -f gui.mk DEBUG=$(DEBUG) BROWSE=$(BROWSE) PLATFORM=$(PLATFORM) DEPEND=$(DEPEND) slmout
	@cd $(MAKEDIR)
!endif

# ---------------------------------------------
# slmin
# ---------------------------------------------
slmin: slmin.depend
	@echo Shell: checking in DLL...
	@cd $(EXEDIR)
	-in -c "Automated check-in" -f $(TARGET).dll $(TARGET).pdb
	@cd $(MAKEDIR)
	@cd $(LIBDIR)
	-in -c "Automated check-in" -f $(TARGET).lib
	@cd $(MAKEDIR)

# ---------------------------------------------
# dependency slmin
# ---------------------------------------------
slmin.depend:
!if "$(DEPEND)" == "1"
	@echo Shell: checking in dependencies...
	@cd $(CAFE_GUI)
	@$(MAKE) -nologo -$(MAKEFLAGS) -f gui.mk DEBUG=$(DEBUG) BROWSE=$(BROWSE) PLATFORM=$(PLATFORM) DEPEND=$(DEPEND) slmin
	@cd $(MAKEDIR)
!endif

# ---------------------------------------------
# clean
# ---------------------------------------------
clean: clean.depend
	@echo Shell: cleaning DLL...
	@-if exist wbus.cpp erase wbus.cpp
	@-if exist wbj.cpp erase wbj.cpp
	@-if exist cmdarryj.cpp erase cmdarryj.cpp
	@-if exist norc.obj erase norc.obj
	@-if exist norc.exe erase norc.exe
	@-if exist $(OBJDIR)\*.obj erase $(OBJDIR)\*.obj
	@-if exist $(OBJDIR)\*.pch erase $(OBJDIR)\*.pch
	@-if exist $(OBJDIR)\*.sbr erase $(OBJDIR)\*.sbr
	@-if exist $(OBJDIR)\*.pdb erase $(OBJDIR)\*.pdb
	@-if exist $(OBJDIR)\*.res erase $(OBJDIR)\*.res
	@-if exist $(OBJDIR)\*.bsc erase $(OBJDIR)\*.bsc
	@-if exist $(OBJDIR)\*.idb erase $(OBJDIR)\*.idb
	@-if exist $(OBJDIR) rmdir $(OBJDIR)
	@-if exist $(EXEDIR)\$(TARGET).* erase $(EXEDIR)\$(TARGET).*
	@-if exist $(LIBDIR)\$(TARGET).* erase $(LIBDIR)\$(TARGET).*

# ---------------------------------------------
# dependency clean
# ---------------------------------------------
clean.depend:
!if "$(DEPEND)" == "1"
	@echo Shell: cleaning dependencies...
	@cd $(CAFE_GUI)
	@$(MAKE) -nologo -$(MAKEFLAGS) -f gui.mk DEBUG=$(DEBUG) BROWSE=$(BROWSE) PLATFORM=$(PLATFORM) DEPEND=$(DEPEND) clean
	@cd $(MAKEDIR)
!endif

# ---------------------------------------------
# dependency generation
# ---------------------------------------------
auto.dep: auto.dep.depend
    @attrib -r auto.dep
    @mkdep  -I $(CAFE_INCLUDE) -P $$(OBJDIR)\ -s.obj -n *.cpp >auto.dep

# ---------------------------------------------
# dependencies for dependency generation
# ---------------------------------------------
auto.dep.depend: nul
!if "$(DEPEND)" == "1"
	@echo Shell: Updating dependency files...
# Shl
	@cd $(CAFE_GUI)
	@$(MAKE) -nologo -$(MAKEFLAGS) -f gui.mk DEBUG=$(DEBUG) BROWSE=$(BROWSE) PLATFORM=$(PLATFORM) DEPEND=$(DEPEND) auto.dep
	@cd $(MAKEDIR)
!endif

# ---------------------------------------------
# PCH file generation
# ---------------------------------------------
$(OBJDIR)\$(TARGET).pch: stdafx.cpp stdafx.h
	@echo Shell: compiling...
	@$(CPP) $(CPP_CREATE_PCH_FLAGS) stdafx.cpp
