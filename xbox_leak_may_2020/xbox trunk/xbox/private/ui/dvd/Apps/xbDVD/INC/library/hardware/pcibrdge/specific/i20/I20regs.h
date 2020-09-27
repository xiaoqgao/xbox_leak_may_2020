//
// FILE:      library\hardware\pcibridge\specific\i20\i20regs.h
// AUTHOR:    U. Sigmund
// COPYRIGHT: (c) 1995 Viona Development.  All Rights Reserved.
// CREATED:   21.03.95
//
// PURPOSE:   Register definitions for the I20 chip
// 
// HISTORY:
//
//

#ifndef I20REGS_H
#define I20REGS_H                                            

#include "..\..\..\..\common\prelude.h"

#define I20REG_HTIMING			0x00
#define I20IDX_HSPOL				30
#define I20REG_HSPOL				I20REG_HTIMING, I20IDX_HSPOL
#define I20IDX_HSTART			10, 10
#define I20REG_HSTART			I20REG_HTIMING, I20IDX_HSTART
#define I20IDX_HEND				 0, 10
#define I20REG_HEND				I20REG_HTIMING, I20IDX_HEND     
			
#define I20REG_VTIMING			0x04
#define I20IDX_VSPOL				30
#define I20REG_VSPOL				I20REG_VTIMING, I20IDX_VSPOL
#define I20IDX_VSTART			10, 10
#define I20REG_VSTART			I20REG_VTIMING, I20IDX_VSTART
#define I20IDX_VEND				 0, 10
#define I20REG_VEND				I20REG_VTIMING, I20IDX_VEND     

//
// For VSPOL and HSPOL
//
#define I20_NEGATIVE_EDGE		TRUE
#define I20_POSITIVE_EDGE		FALSE



#define I20REG_VIDCONFIG		0x08
#define I20IDX_EXTFI				26
#define I20REG_EXTFI				I20REG_VIDCONFIG, I20IDX_EXTFI
#define I20IDX_TOPFIELD			25
#define I20REG_TOPFIELD			I20REG_VIDCONFIG, I20IDX_TOPFIELD
#define I20IDX_VCLKPOL			24
#define I20REG_VCLKPOL			I20REG_VIDCONFIG, I20IDX_VCLKPOL
#define I20IDX_HFILTER			21,  3
#define I20REG_HFILTER			I20REG_VIDCONFIG, I20IDX_HFILTER
#define I20IDX_DUPFLD			20
#define I20REG_DUPFLD			I20REG_VIDCONFIG, I20IDX_DUPFLD
#define I20IDX_HORDCM			14,  6
#define I20REG_HORDCM			I20REG_VIDCONFIG, I20IDX_HORDCM
#define I20IDX_VERDCM			 8,  6
#define I20REG_VERDCM			I20REG_VIDCONFIG, I20IDX_VERDCM
#define I20IDX_DISPMOD			 6
#define I20REG_DISPMOD			I20REG_VIDCONFIG, I20IDX_DISPMOD
#define I20IDX_YUV2RGB			 3,  2
#define I20REG_YUV2RGB			I20REG_VIDCONFIG, I20IDX_YUV2RGB
#define I20IDX_ERRDIF			 2
#define I20REG_ERRDIF			I20REG_VIDCONFIG, I20IDX_ERRDIF
#define I20IDX_PACK24			 1
#define I20REG_PACK24			I20REG_VIDCONFIG, I20IDX_PACK24
#define I20IDX_LITTLEENDIAN	 0
#define I20REG_LITTLEENDIAN	I20REG_VIDCONFIG, I20IDX_LITTLEENDIAN                      

//
// For YUV2RGB
//
#define I20_YUV422				0x00
#define I20_RGB888				0x01
#define I20_RGB565				0x02
#define I20_RGB555				0x03



#define I20REG_VIDTOPBASE		0x0c
#define I20REG_VIDBOTBASE		0x10 

#define I20REG_DISPGRAB			0x14
#define I20IDX_DISPSTRIDE		16, 16
#define I20REG_DISPSTRIDE		I20REG_DISPGRAB, I20IDX_DISPSTRIDE
#define I20IDX_VIDOVF			 8
#define I20REG_VIDOVF			I20REG_DISPGRAB, I20IDX_VIDOVF
#define I20IDX_SNAPSHOT			 1
#define I20REG_SNAPSHOT			I20REG_DISPGRAB, I20IDX_SNAPSHOT
#define I20IDX_FRAMEGRAB		 0
#define I20REG_FRAMEGRAB		I20REG_DISPGRAB, I20IDX_FRAMEGRAB

#define I20REG_VIDWIN			0x18
#define I20IDX_VIDEN				31
#define I20REG_VIDEN				I20REG_VIDWIN, I20IDX_VIDEN
#define I20IDX_MINPIX			25,  6
#define I20REG_MINPIX			I20REG_VIDWIN, I20IDX_MINPIX
#define I20IDX_TRITONFIX		24
#define I20REG_TRITONFIX		I20REG_VIDWIN, I20IDX_TRITONFIX
#define I20IDX_VIDWINHT			12, 10
#define I20REG_VIDWINHT			I20REG_VIDWIN, I20IDX_VIDWINHT
#define I20IDX_VIDWINWID		 0, 10
#define I20REG_VIDWINWID		I20REG_VIDWIN, I20IDX_VIDWINWID

#define I20REG_MASKTOPBASE		0x1c
#define I20REG_MASKBOTBASE		0x20
                                                             
#define I20REG_MASKCTRL			0x24                                                             
#define I20IDX_OVLENABLE		15
#define I20REG_OVLENABLE		I20REG_MASKCTRL, I20IDX_OVLENABLE
#define I20IDX_MASKSTRIDE		 0,  8
#define I20REG_MASKSTRIDE		I20REG_MASKCTRL, I20IDX_MASKSTRIDE

#define I20REG_SYSCTRL			0x28
#define I20IDX_SOFTRESET		24
#define I20REG_SOFTRESET		I20REG_SYSCTRL, I20IDX_SOFTRESET
#define I20IDX_WAITSTATE		16,  3
#define I20REG_WAITSTATE		I20REG_SYSCTRL, I20IDX_WAITSTATE
#define I20IDX_GENPURDIR		 0,  8
#define I20REG_GENPURDIR		I20REG_SYSCTRL, I20IDX_GENPURDIR

#define I20REG_GUESTCTRL		0x2c
#define I20IDX_GENPURIO(x,y)	(24+x),  y
#define I20REG_GENPURIO(x,y)	I20REG_GUESTCTRL, I20IDX_GENPURIO(x, y)
#define I20IDX_GENPURIOBIT(x)	(24+x)
#define I20REG_GENPURIOBIT(x)	I20REG_GUESTCTRL, I20IDX_GENPURIOBIT(x)
#define I20IDX_GUESTDUR(x)		(2+4*x), 2                 
#define I20REG_GUESTDUR(x)		I20REG_GUESTCTRL, I20IDX_GUESTDUR(x)
#define I20IDX_GUESTREC(x)		(0+4*x), 2              
#define I20REG_GUESTREC(x)		I20REG_GUESTCTRL, I20IDX_GUESTREC(x)

#define I20REG_GENPURIOALL			0x2f

//
// For GENPURIO
//

#define I20_GENP_INPUT				TRUE
#define I20_GENP_OUTPUT				FALSE

//
// For GUESTDUR
//
#define I20_DUR3CLKS				0x00
#define I20_DUR4CLKS				0x01
#define I20_DUR12CLKS			0x02
#define I20_DUR15CLKS			0x03

//
// For GUESTREC
//
#define I20_REC3CLKS				0x00
#define I20_REC4CLKS				0x01
#define I20_REC12CLKS			0x02
#define I20_REC15CLKS			0x03


#define I20REG_CODMEMBASE		0x30

#define I20REG_CODCTRL			0x34
#define I20IDX_CODTIME			30
#define I20REG_CODTIME			I20REG_CODCTRL, I20IDX_CODTIME    
#define I20IDX_CODEMPTY			29
#define I20REG_CODEMPTY			I20REG_CODCTRL, I20IDX_CODEMPTY
#define I20IDX_CODFLUSH			28                            
#define I20REG_CODFLUSH			I20REG_CODCTRL, I20IDX_CODFLUSH
#define I20IDX_CODGUESTID		20,  3
#define I20REG_CODGUESTID		I20REG_CODCTRL, I20IDX_CODGUESTID
#define I20IDX_CODGUESTREG		16,  3                           
#define I20REG_CODGUESTREG		I20REG_CODCTRL, I20IDX_CODGUESTREG
#define I20IDX_CODMEMSIZE		12,  3                            
#define I20REG_CODMEMSIZE		I20REG_CODCTRL, I20IDX_CODMEMSIZE
#define I20IDX_CODMEMSTEP		 8,  3                           
#define I20REG_CODMEMSTEP		I20REG_CODCTRL, I20IDX_CODMEMSTEP
#define I20IDX_CODREADEN		 7                               
#define I20REG_CODREADEN		I20REG_CODCTRL, I20IDX_CODREADEN
#define I20IDX_CODTRSHLD		 1,  3                          
#define I20REG_CODTRSHLD		I20REG_CODCTRL, I20IDX_CODTRSHLD
#define I20IDX_CODAUTOEN		 0                              
#define I20REG_CODAUTOEN		I20REG_CODCTRL, I20IDX_CODAUTOEN

//
// For CODMEMSIZE
//
#define I20_CODMEMSIZE8K		0x00
#define I20_CODMEMSIZE16K		0x01
#define I20_CODMEMSIZE32K		0x02
#define I20_CODMEMSIZE64K		0x03
#define I20_CODMEMSIZE128K		0x04
#define I20_CODMEMSIZE256K		0x05
                                  
//
// For CODMEMSTEP
//                                  
#define I20_CODMEMSTEP8K		0x00
#define I20_CODMEMSTEP16K		0x01
#define I20_CODMEMSTEP32K		0x02
#define I20_CODMEMSTEP64K		0x03
#define I20_CODMEMSTEP128K		0x04
#define I20_CODMEMSTEP256K		0x05


#define I20REG_CODMEMPOINT32	0x38
#define I20REG_CODMEMPOINT		0x38,  0, 16

#define I20REG_INTSTATUS		0x3c
#define I20IDX_GIRQ1				30
#define I20REG_GIRQ1				I20REG_INTSTATUS, I20IDX_GIRQ1
#define I20IDX_GIRQ0				29
#define I20REG_GIRQ0				I20REG_INTSTATUS, I20IDX_GIRQ0
#define I20IDX_CODREPIRQ		28
#define I20REG_CODREPIRQ		I20REG_INTSTATUS, I20IDX_CODREPIRQ
                                                                
#define I20REG_INTENABLE		0x40                                                                
#define I20IDX_GIRQ1EN			30
#define I20REG_GIRQ1EN			I20REG_INTENABLE, I20IDX_GIRQ1EN
#define I20IDX_GIRQ0EN			29
#define I20REG_GIRQ0EN			I20REG_INTENABLE, I20IDX_GIRQ0EN
#define I20IDX_CODREPIRQEN		28
#define I20REG_CODREPIRQEN		I20REG_INTENABLE, I20IDX_CODREPIRQEN
#define I20IDX_INTPINEN			24
#define I20REG_INTPINEN			I20REG_INTENABLE, I20IDX_INTPINEN

#define I20REG_I2C				0x44
#define I20IDX_I2CSDA			1
#define I20REG_I2CSDA			I20REG_I2C, I20IDX_I2CSDA
#define I20IDX_I2CSCL			0
#define I20REG_I2CSCL			I20REG_I2C, I20IDX_I2CSCL

#define I20REG_POSTOFFICE		0x200
#define I20IDX_POPEN				25
#define I20REG_POPEN				I20REG_POSTOFFICE, I20IDX_POPEN
#define I20IDX_POTIME			24
#define I20REG_POTIME			I20REG_POSTOFFICE, I20IDX_POTIME
#define I20IDX_PODIR				23
#define I20REG_PODIR				I20REG_POSTOFFICE, I20IDX_PODIR
#define I20IDX_POGUESTID		20,  3
#define I20REG_POGUESTID		I20REG_POSTOFFICE, I20IDX_POGUESTID
#define I20IDX_POGUESTREG		16,  3
#define I20REG_POGUESTREG		I20REG_POSTOFFICE, I20IDX_POGUESTREG
#define I20IDX_PODATA			 0,  8
#define I20REG_PODATA			I20REG_POSTOFFICE, I20IDX_PODATA

#define I20_PO_OUTPUT			HIGH
#define I20_PO_INPUT				LOW

#endif   
