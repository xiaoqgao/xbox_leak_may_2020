/* The Plum Hall Validation Suite for C
 * Unpublished copyright (c) 1986-1991, Chiron Systems Inc and Plum Hall Inc.
 * VERSION: 3
 * DATE:    91/07/01
 * The "ANSI" mode of the Suite corresponds to the official ANSI C, X3.159-1989.
 * As per your license agreement, your distribution is not to be moved or copied outside the Designated Site
 * without specific permission from Plum Hall Inc.
 */

#include <windows.h>
#include "types.h"

int PASCAL WinMain(HINSTANCE hinst, HINSTANCE hinstPrev, LPSTR lszCmdLine, int nCmdShow)
	
	{
	auto CHAR Bc = 7;
	auto CHAR *pBc = &Bc;
	auto SCHAR Bsc = 8;
	auto SCHAR *pBsc = &Bsc;
	auto SHORT Bs = 9;
	auto SHORT *pBs = &Bs;
	auto INT Bi = 10;
	auto INT *pBi = &Bi;
	auto UCHAR Buc = 11;
	auto UCHAR *pBuc = &Buc;
	auto USHORT Bus = 12;
	auto USHORT *pBus = &Bus;
	auto UINT Bui = 13;
	auto UINT *pBui = &Bui;
	auto LONG Bl = 14;
	auto LONG *pBl = &Bl;
	auto ULONG Bul = 15;
	auto ULONG *pBul = &Bul;
	auto FLOAT Bf = 16;
	auto FLOAT *pBf = &Bf;
	auto DOUBLE Bd = 17;
	auto DOUBLE *pBd = &Bd;
	auto LDOUBLE Bld = 18;
	auto LDOUBLE *pBld = &Bld;
	{
	typedef union {
		CHAR c;
		SHORT s;
		INT i;
		UCHAR uc;
		USHORT us;
		UINT ui;
		LONG l;
		ULONG ul;
		FLOAT f;
		DOUBLE d;
		SCHAR sc;
		LDOUBLE ld;
		} E;
	auto E E1, *pE1 = &E1;
	auto E E2, *pE2 = &E2;
	auto E E3, *pE3 = &E3;
	auto E E4, *pE4 = &E4;
	auto E E5, *pE5 = &E5;
	auto E E6, *pE6 = &E6;
	auto E E7, *pE7 = &E7;
	auto E E8, *pE8 = &E8;
	auto E E9, *pE9 = &E9;
	auto E E10, *pE10 = &E10;
	auto E E11, *pE11 = &E11;
	auto E E12, *pE12 = &E12;
	pE1->c = 7;
	pE2->sc = 8;
	pE3->s = 9;
	pE4->i = 10;
	pE5->uc = 11;
	pE6->us = 12;
	pE7->ui = 13;
	pE8->l = 14;
	pE9->ul = 15;
	pE10->f = 16;
	pE11->d = 17;
	pE12->ld = 18;
	{
	*pBc = 7;
	pE1->c = 7;

	break_here:

	*pBc = 7;
	pE2->sc = 8;
	*pBc = 7;
	pE3->s = 9;
	*pBc = 7;
	pE4->i = 10;
	*pBc = 7;
	pE5->uc = 11;
	*pBc = 7;
	pE6->us = 12;
	*pBc = 7;
	pE7->ui = 13;
	*pBc = 7;
	pE8->l = 14;
	*pBc = 7;
	pE9->ul = 15;
	*pBc = 7;
	pE10->f = 16;
	*pBc = 7;
	pE11->d = 17;
	*pBc = 7;
	pE12->ld = 18;
	*pBsc = 8;
	pE1->c = 7;
	*pBsc = 8;
	pE2->sc = 8;
	*pBsc = 8;
	pE3->s = 9;
	*pBsc = 8;
	pE4->i = 10;
	*pBsc = 8;
	pE5->uc = 11;
	*pBsc = 8;
	pE6->us = 12;
	*pBsc = 8;
	pE7->ui = 13;
	*pBsc = 8;
	pE8->l = 14;
	*pBsc = 8;
	pE9->ul = 15;
	*pBsc = 8;
	pE10->f = 16;
	*pBsc = 8;
	pE11->d = 17;
	*pBsc = 8;
	pE12->ld = 18;
	*pBs = 9;
	pE1->c = 7;
	*pBs = 9;
	pE2->sc = 8;
	*pBs = 9;
	pE3->s = 9;
	*pBs = 9;
	pE4->i = 10;
	*pBs = 9;
	pE5->uc = 11;
	*pBs = 9;
	pE6->us = 12;
	*pBs = 9;
	pE7->ui = 13;
	*pBs = 9;
	pE8->l = 14;
	*pBs = 9;
	pE9->ul = 15;
	*pBs = 9;
	pE10->f = 16;
	*pBs = 9;
	pE11->d = 17;
	*pBs = 9;
	pE12->ld = 18;
	*pBi = 10;
	pE1->c = 7;
	*pBi = 10;
	pE2->sc = 8;
	*pBi = 10;
	pE3->s = 9;
	*pBi = 10;
	pE4->i = 10;
	*pBi = 10;
	pE5->uc = 11;
	*pBi = 10;
	pE6->us = 12;
	*pBi = 10;
	pE7->ui = 13;
	*pBi = 10;
	pE8->l = 14;
	*pBi = 10;
	pE9->ul = 15;
	*pBi = 10;
	pE10->f = 16;
	*pBi = 10;
	pE11->d = 17;
	*pBi = 10;
	pE12->ld = 18;
	*pBuc = 11;
	pE1->c = 7;
	*pBuc = 11;
	pE2->sc = 8;
	*pBuc = 11;
	pE3->s = 9;
	*pBuc = 11;
	pE4->i = 10;
	*pBuc = 11;
	pE5->uc = 11;
	*pBuc = 11;
	pE6->us = 12;
	*pBuc = 11;
	pE7->ui = 13;
	*pBuc = 11;
	pE8->l = 14;
	*pBuc = 11;
	pE9->ul = 15;
	*pBuc = 11;
	pE10->f = 16;
	*pBuc = 11;
	pE11->d = 17;
	*pBuc = 11;
	pE12->ld = 18;
	*pBus = 12;
	pE1->c = 7;
	*pBus = 12;
	pE2->sc = 8;
	*pBus = 12;
	pE3->s = 9;
	*pBus = 12;
	pE4->i = 10;
	*pBus = 12;
	pE5->uc = 11;
	*pBus = 12;
	pE6->us = 12;
	*pBus = 12;
	pE7->ui = 13;
	*pBus = 12;
	pE8->l = 14;
	*pBus = 12;
	pE9->ul = 15;
	*pBus = 12;
	pE10->f = 16;
	*pBus = 12;
	pE11->d = 17;
	*pBus = 12;
	pE12->ld = 18;
	*pBui = 13;
	pE1->c = 7;
	*pBui = 13;
	pE2->sc = 8;
	*pBui = 13;
	pE3->s = 9;
	*pBui = 13;
	pE4->i = 10;
	*pBui = 13;
	pE5->uc = 11;
	*pBui = 13;
	pE6->us = 12;
	*pBui = 13;
	pE7->ui = 13;
	*pBui = 13;
	pE8->l = 14;
	*pBui = 13;
	pE9->ul = 15;
	*pBui = 13;
	pE10->f = 16;
	*pBui = 13;
	pE11->d = 17;
	*pBui = 13;
	pE12->ld = 18;
	*pBl = 14;
	pE1->c = 7;
	*pBl = 14;
	pE2->sc = 8;
	*pBl = 14;
	pE3->s = 9;
	*pBl = 14;
	pE4->i = 10;
	*pBl = 14;
	pE5->uc = 11;
	*pBl = 14;
	pE6->us = 12;
	*pBl = 14;
	pE7->ui = 13;
	*pBl = 14;
	pE8->l = 14;
	*pBl = 14;
	pE9->ul = 15;
	*pBl = 14;
	pE10->f = 16;
	*pBl = 14;
	pE11->d = 17;
	*pBl = 14;
	pE12->ld = 18;
	*pBul = 15;
	pE1->c = 7;
	*pBul = 15;
	pE2->sc = 8;
	*pBul = 15;
	pE3->s = 9;
	*pBul = 15;
	pE4->i = 10;
	*pBul = 15;
	pE5->uc = 11;
	*pBul = 15;
	pE6->us = 12;
	*pBul = 15;
	pE7->ui = 13;
	*pBul = 15;
	pE8->l = 14;
	*pBul = 15;
	pE9->ul = 15;
	*pBul = 15;
	pE10->f = 16;
	*pBul = 15;
	pE11->d = 17;
	*pBul = 15;
	pE12->ld = 18;
	*pBf = 16;
	pE1->c = 7;
	*pBf = 16;
	pE2->sc = 8;
	*pBf = 16;
	pE3->s = 9;
	*pBf = 16;
	pE4->i = 10;
	*pBf = 16;
	pE5->uc = 11;
	*pBf = 16;
	pE6->us = 12;
	*pBf = 16;
	pE7->ui = 13;
	*pBf = 16;
	pE8->l = 14;
	*pBf = 16;
	pE9->ul = 15;
	*pBf = 16;
	pE10->f = 16;
	*pBf = 16;
	pE11->d = 17;
	*pBf = 16;
	pE12->ld = 18;
	*pBd = 17;
	pE1->c = 7;
	*pBd = 17;
	pE2->sc = 8;
	*pBd = 17;
	pE3->s = 9;
	*pBd = 17;
	pE4->i = 10;
	*pBd = 17;
	pE5->uc = 11;
	*pBd = 17;
	pE6->us = 12;
	*pBd = 17;
	pE7->ui = 13;
	*pBd = 17;
	pE8->l = 14;
	*pBd = 17;
	pE9->ul = 15;
	*pBd = 17;
	pE10->f = 16;
	*pBd = 17;
	pE11->d = 17;
	*pBd = 17;
	pE12->ld = 18;
	*pBld = 18;
	pE1->c = 7;
	*pBld = 18;
	pE2->sc = 8;
	*pBld = 18;
	pE3->s = 9;
	*pBld = 18;
	pE4->i = 10;
	*pBld = 18;
	pE5->uc = 11;
	*pBld = 18;
	pE6->us = 12;
	*pBld = 18;
	pE7->ui = 13;
	*pBld = 18;
	pE8->l = 14;
	*pBld = 18;
	pE9->ul = 15;
	*pBld = 18;
	pE10->f = 16;
	*pBld = 18;
	pE11->d = 17;
	*pBld = 18;
	pE12->ld = 18;
	
	return 0;
	}}
	}
