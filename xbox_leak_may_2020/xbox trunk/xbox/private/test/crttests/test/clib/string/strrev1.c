
/****************************************************************************
              Copyright (C) 1992, Microsoft Corporation
Method:              cl strrev1.c
                     strrev1
Switches:            NONE
Hard/Soft Needs:
Abstract:            This test verifies the _strrev() function.
OS Version:          REAL/PROT/ALL
CPU:                 8086
Dependencies:        NONE
Environment Vars:    NONE
Verification Method: COMPILE/EXECUTE/COMPARE
Notes:               Must include STRING.H
                     Tests described in the testplan STRING.DOC
Products:            C800
Test Type:       DEPTH

Revision History:
 Date              emailname      description
---------------------------------------------------------------------------
 [ 0] 14-May-92    edv            created

---------------------------------------------------------------------------
EndHeader:
*****************************************************************************/

#include <string.h>
#include <test.h>

static char test[] = __FILE__;
static int perfect;


static unsigned char string1[6] = "ABCDE\0";
static unsigned char string2[5] = "\0\0\0\0\0";
static unsigned char string3[2] = "1\0";
static unsigned char string4[3] = "12\0";
static unsigned char string5[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";

static unsigned char baseline1[6] = "EDCBA\0";
static unsigned char baseline5[37] = "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210\0";

int strrev1Entry(){
    int i;
    unsigned char *pstr;

    startest();



/*  Scenario 1: Verify that the function returns a pointer to the
                altered string.
*/

    pstr = _strrev( string1 );

    checke( pstr, string1 );

    for (i = 0; i < (sizeof( string1 ) - 1); i++)
        checke( pstr[i], baseline1[i] );

    checke( pstr[i], '\0' );





/*  Scenario 2: Verify that the function works correctly when string
                is NULL.
*/

    pstr = _strrev( string2 );            /* String begins with NULL,  */
                                         /*  so string is unalterred. */
    checke( pstr, string2 );

    for (i = 0; i < (sizeof( string2 ) ); i++)
        checke( string2[i], '\0' );




/*  Scenario 3: Verify that the function works correctly when string
                can hold only 1 character.
*/

    pstr = _strrev( string3 );

    checke( pstr, string3 );

    checke( pstr[0], '1' );

    checke( pstr[1], '\0' );




/*  Scenario 4: Verify that the function works correctly when string
                can hold only 2 characters.
*/

    pstr = _strrev( string4 );

    checke( pstr, string4 );

    checke( pstr[0], '2' );

    checke( pstr[1], '1' );

    checke( pstr[2], '\0' );




/*  Scenario 5: Verify that the function works correctly using a
                larger string.
*/

    pstr = _strrev( string5 );

    checke( pstr, string5 );

    for (i = 0; i < (sizeof( string5 ) ); i++)
        checke( pstr[i], baseline5[i] );

    checke( pstr[i], '\0' );




    finish();
}
