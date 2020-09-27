#include "tif_port.h"

#ifndef lint
static char sccsid[] = "@(#)tiff_thunder.c	1.7 4/25/89";
#endif

/*
 * Copyright (c) 1988 by Sam Leffler.
 * All rights reserved.
 *
 * This file is provided for unrestricted use provided that this
 * legend is included on all tape media and as a part of the
 * software program in whole or part.  Users may copy, modify or
 * distribute this file at will.
 */

/*
 * TIFF Library.
 *
 * ThunderScan 4-bit Compression Algorithm Support
 */
#include "tiffio.h"

static	int ThunderScanEncode(), ThunderScanDecode();

TIFFInitThunderScan(tif)
	TIFF *tif;
{

	tif->tif_decoderow = ThunderScanDecode;
	tif->tif_encoderow = ThunderScanEncode;
	return (1);
}

/*
 * ThunderScan uses an encoding scheme designed for
 * 4-bit pixel values.  Data is encoded in bytes, with
 * each byte split into a 2-bit code word and a 6-bit
 * data value.  The encoding gives raw data, runs of
 * pixels, or pixel values encoded as a delta from the
 * previous pixel value.  For the latter, either 2-bit
 * or 3-bit delta values are used, with the deltas packed
 * into a single byte.
 */
#define	THUNDER_DATA		0x3f	/* mask for 6-bit data */
#define	THUNDER_CODE		0xc0	/* mask for 2-bit code word */
/* code values */
#define	THUNDER_RUN		0x00	/* run of pixels w/ encoded count */
#define	THUNDER_2BITDELTAS	0x40	/* 3 pixels w/ encoded 2-bit deltas */
#define	    DELTA2_SKIP		2	/* skip code for 2-bit deltas */
#define	THUNDER_3BITDELTAS	0x80	/* 2 pixels w/ encoded 3-bit deltas */
#define	    DELTA3_SKIP		4	/* skip code for 3-bit deltas */
#define	THUNDER_RAW		0xc0	/* raw data encoded */

static	int twobitdeltas[4] = { 0, 1, 0, -1 };
static	int threebitdeltas[8] = { 0, 1, 2, 3, 0, -3, -2, -1 };

static
ThunderScanEncode(tif, pp, cc)
	TIFF *tif;
	u_char *pp;
{

	TIFFError(tif->tif_name, "ThunderScan encoding is not implemented");
	return (-1);
}

#define	SETPIXEL(op, v) { \
	lastpixel = (v) & 0xf; \
	if (npixels++ & 1) \
	    *op++ |= lastpixel; \
	else \
	    op[0] = lastpixel << 4; \
}

static
ThunderScanDecode(tif, op, occ)
	TIFF *tif;
	register u_char *op;
{
	register u_char *bp;
	register int n, cc, lastpixel, npixels, delta;
	int imagewidth;

	bp = (u_char *)tif->tif_rawcp;
	cc = tif->tif_rawcc;
	imagewidth = tif->tif_dir.td_imagewidth;
	lastpixel = npixels = 0;
	while (cc > 0 && npixels < imagewidth) {
		n = *bp++, cc--;
		switch (n & THUNDER_CODE) {
		case THUNDER_RUN:		/* pixel run */
			/*
			 * Replicate the last pixel n times,
			 * where n is the lower-order 6 bits.
			 */
			if (npixels & 1) {
				op[0] |= lastpixel;
				lastpixel = *op++; npixels++; n--;
			} else
				lastpixel |= lastpixel << 4;
			npixels += n;
			for (; n > 0; n -= 2)
				*op++ = lastpixel;
			if (n == -1)
				*--op &= 0xf0;
			lastpixel &= 0xf;
			break;
		case THUNDER_2BITDELTAS:	/* 2-bit deltas */
			if ((delta = ((n >> 4) & 3)) != DELTA2_SKIP)
				SETPIXEL(op, lastpixel + twobitdeltas[delta]);
			if ((delta = ((n >> 2) & 3)) != DELTA2_SKIP)
				SETPIXEL(op, lastpixel + twobitdeltas[delta]);
			if ((delta = (n & 3)) != DELTA2_SKIP)
				SETPIXEL(op, lastpixel + twobitdeltas[delta]);
			break;
		case THUNDER_3BITDELTAS:	/* 3-bit deltas */
			if ((delta = ((n >> 3) & 7)) != DELTA3_SKIP)
				SETPIXEL(op, lastpixel + threebitdeltas[delta]);
			if ((delta = (n & 7)) != DELTA3_SKIP)
				SETPIXEL(op, lastpixel + threebitdeltas[delta]);
			break;
		case THUNDER_RAW:		/* raw data */
			SETPIXEL(op, n);
			break;
		}
	}
	tif->tif_rawcp = (char *)bp;
	tif->tif_rawcc = cc;
	if (npixels != imagewidth) {
		TIFFError(tif->tif_name,
		    "ThunderScanDecode: %s data for scanline %d (npixels=%d)",
		    npixels < imagewidth ? "Not enough" : "Too much",
		    tif->tif_row, npixels);
		return (0);
	}
	return (1);
}