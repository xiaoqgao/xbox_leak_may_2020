#define BIGDATE_BC      0
#define BIGDATE_AD      4
#define SIZEOF_BIGDATE  8

#define BBOX_XMIN   0
#define BBOX_YMIN   2
#define BBOX_XMAX   4
#define BBOX_YMAX   6
#define SIZEOF_BBOX 8

#define SFNT_DIRECTORYENTRY_TAG         0
#define SFNT_DIRECTORYENTRY_CHECKSUM    4
#define SFNT_DIRECTORYENTRY_TABLEOFFSET 8
#define SFNT_DIRECTORYENTRY_TABLELENGTH 12
#define SIZEOF_SFNT_DIRECTORYENTRY      16

#define SFNT_OFFSETTABLE_VERSION        0
#define SFNT_OFFSETTABLE_NUMOFFSETS     4
#define SFNT_OFFSETTABLE_SEARCHRANGE    6
#define SFNT_OFFSETTABLE_ENTRYSELECTOR  8
#define SFNT_OFFSETTABLE_RANGESHIFT     10
#define SFNT_OFFSETTABLE_TABLE          12
#define SIZEOF_SFNT_OFFSETTABLE         12

#define SFNT_FONTHEADER_VERSION             0
#define SFNT_FONTHEADER_FONTREVISION        4
#define SFNT_FONTHEADER_CHECKSUMADJUSTMENT  8
#define SFNT_FONTHEADER_MAGICNUMBER         12
#define SFNT_FONTHEADER_FLAGS               16
#define SFNT_FONTHEADER_UNITSPEREM          18
#define SFNT_FONTHEADER_CREATED             20
#define SFNT_FONTHEADER_MODIFIED            28
#define SFNT_FONTHEADER_XMIN                36
#define SFNT_FONTHEADER_YMIN                38
#define SFNT_FONTHEADER_XMAX                40
#define SFNT_FONTHEADER_YMAX                42
#define SFNT_FONTHEADER_MACSTYLE            44
#define SFNT_FONTHEADER_LOWESTRECPPEM       46
#define SFNT_FONTHEADER_FONTDIRECTIONHINT   48
#define SFNT_FONTHEADER_INDEXTOLOCFORMAT    50
#define SFNT_FONTHEADER_GLYPHDATAFORMAT     52
#define SIZEOF_SFNT_FONTHEADER              54

#define SFNT_HORIZONTALHEADER_VERSION                           0
#define SFNT_HORIZONTALHEADER_YASCENDER                         4
#define SFNT_HORIZONTALHEADER_YDESCENDER                        6
#define SFNT_HORIZONTALHEADER_YLINEGAP                          8
#define SFNT_HORIZONTALHEADER_ADVANCEWIDTHMAX                   10
#define SFNT_HORIZONTALHEADER_MINLEFTSIDEBEARING                12
#define SFNT_HORIZONTALHEADER_MINRIGHTSIDEBEARING               14
#define SFNT_HORIZONTALHEADER_XMAXEXTENT                        16
#define SFNT_HORIZONTALHEADER_HORIZONTALCARETSLOPENUMERATOR     18
#define SFNT_HORIZONTALHEADER_HORIZONTALCARETSLOPEDENOMINATOR   20
#define SFNT_HORIZONTALHEADER_RESERVED0                         22
#define SFNT_HORIZONTALHEADER_RESERVED1                         24
#define SFNT_HORIZONTALHEADER_RESERVED2                         26
#define SFNT_HORIZONTALHEADER_RESERVED3                         28
#define SFNT_HORIZONTALHEADER_RESERVED4                         30
#define SFNT_HORIZONTALHEADER_METRICDATAFORMAT                  32
#define SFNT_HORIZONTALHEADER_NUMBEROF_LONGHORMETRICS           34
#define SIZEOF_SFNT_HORIZONTALHEADER                            36

#define SFNT_HORIZONTALMETRICS_ADVANCEWIDTH     0
#define SFNT_HORIZONTALMETRICS_LEFTSIDEBEARING  2
#define SIZEOF_SFNT_HORIZONTALMETRICS           4

#define SFNT_VERTICALHEADER_NUMBEROF_LONGVERTMETRICS            34

#define SFNT_VERTICALMETRICS_ADVANCEHEIGHT      0
#define SFNT_VERTICALMETRICS_TOPSIDEBEARING     2
#define SIZEOF_SFNT_VERTICALMETRICS             4



#define SFNT_CONTROLVALUE 2

#define SFNT_MAPPINGTABLE_FORMAT            0
#define SFNT_MAPPINGTABLE_MAPTABLELENGTH    2
#define SFNT_MAPPINGTABLE_VERSION           4
#define SIZEOF_SFNT_MAPPINGTABLE            6

#define SFNT_PLATFORMENTRY_PLATFORMID       0
#define SFNT_PLATFORMENTRY_SPECIFICID       2
#define SFNT_PLATFORMENTRY_PLATFORMOFFSET   4
#define SIZEOF_SFNT_PLATFORMENTRY           8

#define SFNT_CHAR2INDEXDIRECTORY_VERSION    0
#define SFNT_CHAR2INDEXDIRECTORY_NUMTABLES  2
#define SFNT_CHAR2INDEXDIRECTORY_PLATFORM   4
#define SIZEOF_SFNT_CHAR2INDEXDIRECTORY     4

#define SFNT_SUBHEADER2_FIRSTCODE       0
#define SFNT_SUBHEADER2_ENTRYCOUNT      2
#define SFNT_SUBHEADER2_IDDELTA         4
#define SFNT_SUBHEADER2_IDRANGEOFFSET   6
#define SIZEOF_SFNT_SUBHEADER2          8

#define SFNT_MAPPINGTABLE2_SUBHEADERSKEYS   0
#define SFNT_MAPPINGTABLE2_SUBHEADERS       512
#define SIZEOF_SFNT_MAPPINGTABLE2           512

#define SFNT_MAPPINGTABLE4_SEGCOUNTX2       0
#define SFNT_MAPPINGTABLE4_SEARCHRANGE      2
#define SFNT_MAPPINGTABLE4_ENTRYSELECTOR    4
#define SFNT_MAPPINGTABLE4_RANGESHIFT       6
#define SFNT_MAPPINGTABLE4_ENDCOUNT         8
#define SIZEOF_SFNT_MAPPINGTABLE4           8

#define SFNT_MAPPINGTABLE6_FIRSTCODE    0
#define SFNT_MAPPINGTABLE6_ENTRYCOUNT   2
#define SFNT_MAPPINGTABLE6_GLYPHIDARRAY 4
#define SIZEOF_SFNT_MAPPINGTABLE6       4

#define SFNT_NAMERECORD_PLATFORMID  0
#define SFNT_NAMERECORD_SPECIFICID  2
#define SFNT_NAMERECORD_LANGUAGEID  4
#define SFNT_NAMERECORD_NAMEID      6
#define SFNT_NAMERECORD_NAMELENGTH  8
#define SFNT_NAMERECORD_NAMEOFFSET  10
#define SIZEOF_SFNT_NAMERECORD      12

#define SFNT_NAMINGTABLE_FORMAT         0
#define SFNT_NAMINGTABLE_COUNT          2
#define SFNT_NAMINGTABLE_STRINGOFFSET   4
/*  SFNT_NAMERECORD[COUNT]  */
#define SIZEOF_SFNT_NAMINGTABLE         6

#define SFNT_PACKEDSPLINEFORMAT_NUMBEROFCONTOURS    0
#define SFNT_PACKEDSPLINEFORMAT_BBOX                2
#define SFNT_PACKEDSPLINEFORMAT_ENDPOINTS           10
#define SIZEOF_SFNT_PACKEDSPLINEFORMAT              10

#define SFNT_DEVICEMETRICS_VERSION      0
#define SFNT_DEVICEMETRICS_NUMRECORDS   2
#define SFNT_DEVICEMETRICS_RECORDSIZE   4
/* BYTE WIDTHS[NUMGLYPHS+2] * NUMRECORDS */
#define SIZEOF_SFNT_DEVICEMETRICS       8

#define POSTSCRIPTNAMEINDICES_VERSION               0
#define POSTSCRIPTNAMEINDICES_ITALICANGLE           4
#define POSTSCRIPTNAMEINDICES_UNDERLINEPOSITION     8
#define POSTSCRIPTNAMEINDICES_UNDERLINETHICKNESS    10
#define POSTSCRIPTNAMEINDICES_ISFIXEDPITCH          12
#define POSTSCRIPTNAMEINDICES_PAD                   14
#define POSTSCRIPTNAMEINDICES_MINMEMTYPE42          16
#define POSTSCRIPTNAMEINDICES_MAXMEMTYPE42          20
#define POSTSCRIPTNAMEINDICES_MINMEMTYPE1           24
#define POSTSCRIPTNAMEINDICES_MAXMEMTYPE1           28
#define POSTSCRIPTNAMEINDICES_NUMBERGLYPHS          32
#define GLYPHNAMEINDEX                              34
#define GLYPHNAMEINDEX25                            34
#define SIZEOF_SFNT_POSTSCRIPTINFO                  36

#define SFNT_OS2_VERSION                0
#define SFNT_OS2_XAVGCHARWIDTH          2
#define SFNT_OS2_USWEIGHTCLASS          4
#define SFNT_OS2_USWIDTHCLASS           6
#define SFNT_OS2_FSTYPE                 8
#define SFNT_OS2_YSUBSCRIPTXSIZE        10
#define SFNT_OS2_YSUBSCRIPTYSIZE        12
#define SFNT_OS2_YSUBSCRIPTXOFFSET      14
#define SFNT_OS2_YSUBSCRIPTYOFFSET      16
#define SFNT_OS2_YSUPERSCRIPTXSIZE      18
#define SFNT_OS2_YSUPERSCRIPTYSIZE      20
#define SFNT_OS2_YSUPERSCRIPTXOFFSET    22
#define SFNT_OS2_YSUPERSCRIPTYOFFSET    24
#define SFNT_OS2_YSTRIKEOUTSIZE         26
#define SFNT_OS2_YSTRIKEOUTPOSITION     28
#define SFNT_OS2_SFAMILYCLASS           30
#define SFNT_OS2_PANOSE                 32
#define SFNT_OS2_ULCHARRANGE            42
#define SFNT_OS2_ACHVENDID              58
#define SFNT_OS2_USSELECTION            62
#define SFNT_OS2_USFIRSTCHAR            64
#define SFNT_OS2_USLASTCHAR             66
#define SFNT_OS2_STYPOASCENDER          68
#define SFNT_OS2_STYPODESCENDER         70
#define SFNT_OS2_STYPOLINEGAP           72
#define SFNT_OS2_SWINASCENT             74
#define SFNT_OS2_SWINDESCENT            76
#define SIZEOF_SFNT_OS2                 78

#define SFNT_HDMX_VERSION               0
#define SFNT_HDMX_SNUMRECORDS           2
#define SFNT_HDMX_LSIZERECORD           4
#define SFNT_HDMX_HDMXTABLE             8
#define SIZEOF_SFNT_HDMX                8

#define SFNT_HDMXRECORD_BEMY            0
#define SFNT_HDMXRECORD_BEMX            1
#define SFNT_HDMXRECORD_BWIDTHS         2
#define SIZEOF_SFNT_HDMXRECORD          2

#define SFNT_LTSH_VERSION               0
#define SFNT_LTSH_NUMGLYPHS             2
#define SFNT_LTSH_UBYPELSHEIGHT         4
#define SIZEOF_SFNT_LTSH                4

#define SFNT_MAXPROFILETABLE_VERSION                0
#define SFNT_MAXPROFILETABLE_NUMGLYPHS              4
#define SFNT_MAXPROFILETABLE_MAXPOINTS              6
#define SFNT_MAXPROFILETABLE_MAXCONTOURS            8
#define SFNT_MAXPROFILETABLE_MAXCOMPOSITEPOINTS     10
#define SFNT_MAXPROFILETABLE_MAXCOMPOSITECONTOURS   12
#define SFNT_MAXPROFILETABLE_MAXELEMENTS            14
#define SFNT_MAXPROFILETABLE_MAXTWILIGHTPOINTS      16
#define SFNT_MAXPROFILETABLE_MAXSTORAGE             18
#define SFNT_MAXPROFILETABLE_MAXFUNCTIONDEFS        20
#define SFNT_MAXPROFILETABLE_MAXINSTRUCTIONDEFS     22
#define SFNT_MAXPROFILETABLE_MAXSTACKELEMENTS       24
#define SFNT_MAXPROFILETABLE_MAXSIZEOFINSTRUCTIONS  26
#define SFNT_MAXPROFILETABLE_MAXCOMPONENTELEMENTS   28
#define SFNT_MAXPROFILETABLE_MAXCOMPONENTDEPTH      30
#define SIZEOF_SFNT_MAXPROFILETABLE 				32

#define SFNT_GASPRANGE_RANGEMAXPPEM 		0
#define SFNT_GASPRANGE_RANGEGASPBEHAVIOR	2
#define SIZEOF_SFNT_GASPRANGE				4

#define SFNT_GASP_VERSION					0
#define SFNT_GASP_NUMRANGES 				2
#define SFNT_GASP_GASPRANGE 				4
#define SIZEOF_SFNT_GASP					4

/**********************************************************************/

/*      Embedded Bitmap (sbit) Table Offsets      */

/**********************************************************************/

/*  Bloc, Bdat and Bsca file constants    */

/*  This first bloc is common to both bloc and bsca tables */

#define     SFNT_BLOC_NUMSIZES               4
#define     SFNT_BLOC_FIRSTSTRIKE            8

#define     SFNT_BLOC_INDEXARRAYOFFSET       0
#define     SFNT_BLOC_NUMINDEXTABLES         8
#define     SFNT_BLOC_COLORREF              12
#define     SFNT_BLOC_STARTGLYPH            40
#define     SFNT_BLOC_ENDGLYPH              42
#define     SFNT_BLOC_PPEMX                 44
#define     SFNT_BLOC_PPEMY                 45
#define     SFNT_BLOC_BITDEPTH              46
#define     SFNT_BLOC_FLAGS                 47
#define     SIZEOF_BLOC_SIZESUBTABLE        48

#define     SFNT_BLOC_FIRSTGLYPH             0
#define     SFNT_BLOC_LASTGLYPH              2
#define     SFNT_BLOC_ADDITIONALOFFSET       4
#define     SIZEOF_BLOC_INDEXARRAY           8

#define     SFNT_BLOC_INDEXFORMAT            0
#define     SFNT_BLOC_IMAGEFORMAT            2
#define     SFNT_BLOC_IMAGEOFFSET            4
#define     SFNT_BLOC_OFFSETARRAY            8

#define     SFNT_BLOC_IDX2IMAGESIZE          8
#define     SFNT_BLOC_IDX2METRICS           12

#define     SFNT_BLOC_IDX4NUMGLYPHS          8
#define     SFNT_BLOC_IDX4OFFSETARRAY       12

#define     SFNT_BLOC_IDX4CODE               0
#define     SFNT_BLOC_IDX4OFFSET             2
#define     SIZEOF_CODEOFFSETPAIR            4
                
#define     SFNT_BLOC_IDX5IMAGESIZE          8
#define     SFNT_BLOC_IDX5METRICS           12
#define     SFNT_BLOC_IDX5NUMGLYPHS         20
#define     SFNT_BLOC_IDX5CODEARRAY         24

#define     SFNT_SBIT_HEIGHT                 0
#define     SFNT_SBIT_WIDTH                  1
#define     SFNT_SBIT_BEARINGX               2
#define     SFNT_SBIT_BEARINGY               3
#define     SFNT_SBIT_ADVANCE                4
#define     SFNT_SBIT_VERTBEARINGX           5
#define     SFNT_SBIT_VERTBEARINGY           6
#define     SFNT_SBIT_VERTADVANCE            7
#define     SIZEOF_SBIT_SMALLMETRICS         5
#define     SIZEOF_SBIT_BIGMETRICS           8

#define     SFNT_BDAT_COMPCOUNT              0
#define     SIZEOF_SBIT_GLYPH8PAD            1
#define     SFNT_BDAT_FIRSTCOMP              2

#define     SFNT_BDAT_COMPGLYPH              0
#define     SFNT_BDAT_COMPXOFF               2
#define     SFNT_BDAT_COMPYOFF               3
#define     SIZEOF_SBIT_BDATCOMPONENT        4

#define     SFNT_BSCA_NUMSIZES               4
#define     SFNT_BSCA_FIRSTSTRIKE            8

#define     SFNT_BSCA_PPEMX                 24
#define     SFNT_BSCA_PPEMY                 25
#define     SFNT_BSCA_SUBPPEMX              26
#define     SFNT_BSCA_SUBPPEMY              27
#define     SIZEOF_BSCA_SIZESUBTABLE        28

/**********************************************************************/
