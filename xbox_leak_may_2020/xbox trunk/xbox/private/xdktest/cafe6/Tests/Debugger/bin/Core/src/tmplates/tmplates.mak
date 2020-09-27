########################################################################
# Makefile for tmplates.exe

!CMDSWITCHES +i

CC = cl

CC_FLAGS = -MDd -Gm -GX -Od -ZI -DWIN32 -D_DEBUG -D_WINDOWS -D_AFXDLL

OBJDIR = debug
TESTDIR = $(MAKEDIR)

########################################################################
{}.cpp{}.obj:
	$(CC) -c $(CC_FLAGS) $(DEFS) $(TEST) -Fo$@ $<
########################################################################

goal:  tmplates.exe	

tmplates.exe: tmplates.lnk tmplates.obj
	link -out:tmplates.exe -debug:full -debugtype:CV -pdbtype:sept @tmplates.lnk /incremental:yes
	
tmplates.lnk:                   .\tmplates.mak
	echo tmplates.obj  > tmplates.lnk
