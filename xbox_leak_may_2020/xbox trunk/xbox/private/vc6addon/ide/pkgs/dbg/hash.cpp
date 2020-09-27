
/*++

Copyright(c) 1997  Microsoft Corporation

Module Name:

	hash.cpp

Abstract:

	Some stuff for templated hash table package.  Look at the file
	hash.inl for the implementation of the hash table.

Author:

    Matthew D Hendel (math) 13-May-1997

--*/

#include "stdafx.h"

const ULONG Primes [] =
{
	37,          47,          67,          73,          89,          137,
	149,         173,         211,         257,         263,         269,
	293,         373,         379,         449,         479,         491,
	521,         587,         599,         659,         677,         733,
	787,         919,         929,         977,         983,         997,
	1009,        1061,        1201,        1213,        1217,        1237,
	1259,        1307,        1319,        1361,        1367,        1471,
	1523,        1531,        1543,        1559,        1607,        1709,
	1721,        1861,        1871,        1889,        1931,        1949,
	2143,        2153,        2267,        2287,        2377,        2389,
	2393,        2417,        2503,        2539,        2633,        2657,
	2659,        2729,        2789,        2797,        2837,        2879,
	2939,        2969,        3061,        3067,        3089,        3163,
	3167,        3203,        3209,        3217,        3331,        3389,
	3391,        3407,        3449,        3499,        3631,        3671,
	3691,        3709,        3821,        3847,        3917,        3931,
	3943,        3947,        3967,        3989,        4673,        5309,
	6607,        6761,        7283,        7817,        8513,        8999,
	9103,        9173,        9323,        10091,       10631,       13147,
	13397,       13873,       13997,       14419,       15013,       15031,
	16963,       19081,       20681,       21059,       21487,       21683,
	22769,       23209,       23497,       23599,       23623,       24197,
	24281,       24329,       24877,       25537,       25561,       29347,
	29917,       30851,       32531,       32887,       33589,       34961,
	37273,       37619,       38219,       38321,       38543,       38917,
	39043,       39667,       39953,       39979,       40693,       41579,
	42061,       42443,       43013,       43753,       43759,       44059,
	44531,       44647,       46133,       46727,       47381,       48049,
	48157,       48311,       48449,       49117,       50119,       50359,
	53047,       53101,       53267,       53269,       54083,       54517,
	54577,       54601,       55103,       55147,       56659,       56891,
	57457,       57991,       58211,       58337,       59341,       60013,
	60317,       61253,       62081,       62401,       63311,       63727,
	64433,       65089,       66343,       66449,       66569,       67531,
	68207,       68813,       69191,       69427,       69539,       69809,
	70841,       73181,       73351,       73583,       74093,       74257,
	74377,       75079,       75967,       76031,       77069,       79031,
	79087,       79537,       79559,       81071,       81527,       81967,
	84521,       84589,       85159,       85577,       85781,       86243,
	86813,       87187,       87701,       88681,       89891,       90089,
	91331,       92657,       93941,       93979,       94033,       94307,
	95549,       95857,       96443,       96487,       96517,       96703,
	97397,       97523,       98123,       98297,       100151,      100649,
	102533,      102587,      103591,      103769,      104233,      104491,
	105137,      106163,      108263,      109103,      109567,      109741,
	109751,      110183,      112799,      114311,      114967,      115963,
	117563,      118453,      118603,      118787,      119099,      121271,
	121507,      121843,      122147,      122489,      122839,      123581,
	123631,      124147,      124291,      124567,      124753,      126223,
	127219,      127997,      128717,      129419,      129443,      130769,
	131759,      135479,      136727,      137927,      139291,      140827,
	142501,      142559,      142573,      143333,      144563,      144629,
	144701,      144817,      145303,      146063,      146117,      148429,
	149053,      152083,      152441,      152533,      153271,      153929,
	154303,      154787,      154807,      155231,      155303,      155693,
	159589,      161717,      163193,      166273,      167149,      167213,
	169313,      169591,      171517,      174673,      175709,      176041,
	176489,      177967,      184199,      184607,      185789,      189463,
	189583,      190283,      193441,      194167,      194309,      195457,
	199289,      202219,      203449,      204749,      204913,      205991,
	208931,      212467,      213977,      214351,      216347,      219059,
	219361,      221251,      221537,      224669,      226483,      228181,
	230003,      230239,      230999,      231779,      232643,      233353,
	236207,      236503,      237967,      238141,      239441,      240997,
	241847,      243917,      244243,      247829,      248267,      248309,
	254039,      255869,      256019,      256057,      257339,      257921,
	257981,      260317,      260873,      261223,      263089,      268771,
	273929,      273971,      275623,      284153,      284539,      287237,
	290107,      292223,      293071,      295769,      295943,      298099,
	298451,      298897,      299977,      306809,      309031,      314467,
	315671,      317957,      318023,      321289,      323591,      324757,
	326681,      328037,      331651,      332837,      333041,      336823,
	339239,      342187,      344543,      346627,      346933,      351383,
	351643,      355331,      360007,      360541,      361183,      369293,
	369851,      373393,      373937,      374239,      374929,      381167,
	388169,      388231,      389003,      393451,      393929,      406951,
	412289,      413069,      414157,      417371,      418259,      418751,
	423121,      423307,      424903,      426731,      431857,      435983,
	441631,      446819,      451159,      451657,      453559,      453631,
	456821,      457087,      463663,      465071,      465293,      465407,
	469793,      470149,      471923,      477341,      483787,      484769,
	487637,      488227,      489817,      491039,      500567,      500909,
	502237,      505601,      513347,      514543,      516617,      522763,
	523169,      523177,      532733,      535303,      548323,      548771,
	558241,      571759,      579451,      588311,      592217,      612947,
	621583,      627293,      628673,      628799,      631429,      637129,
	638893,      642791,      644047,      646453,      647147,      648331,
	660181,      662203,      664199,      666607,      667507,      669023,
	686863,      693019,      713737,      723473,      730397,      745517,
	751237,      751321,      752251,      758029,      759223,      762871,
	763513,      778541,      780323,      780841,      809399,      810091,
	825229,      826711,      829159,      830309,      831967,      834497,
	836203,      839693,      852809,      856553,      856897,      859361,
	865717,      875107,      876371,      877817,      880027,      883109,
	883187,      887701,      904987,      907513,      920323,      921191,
	922487,      930973,      934033,      938387,      938437,      956503,
	957599,      964823,      964981,      966233,      975157,      977791,
	993541,      993683,      997769,      997949,      1000609,     1000697,
	1006123,     1008493,     1011827,     1011893,     1018873,     1020839,
	1021651,     1025789,     1028471,     1039279,     1043083,     1045543,
	1069919,     1143341,     1192699,     1229827,     1284317,     1484837,
	1576921,     1728317,     1776989,     1921747,     2136973,     2815993,
	3242741,     3250099,     3356887,     3603253,     3688661,     3728821,
	3878263,     4027519,     5049659,     5099009,     5970287,     6082877,
	6497453,     6941843,     7414843,     8221739,     8227363,     8348911,
	10207181,    10978691,    11769643,    12268411,    12600491,    12677407,
	12833441,    13178593,    14008381,    16632223,    17512069,    19167457,
	21225037,    21375821,    22492991,    25255831,    25769839,    27382181,
	30231937,    33249247,    33656081,    36280501,    48701881,    50044997,
	51524653,    51602263,    55633867,    61605589,    64620401,    65635133,
	72011221,    81148127,    96091343,    96533483,    102767663,   105270679,
	113083961,   121509259,   122008037,   122947933,   144655573,   171798791,
	178803551,   183792571,   184341169,   188621711,   216804967,   244609823,
	249846307,   255327089,   270947893,   295046699,   313227877,   323673101,
	377392009,   396772021,   407300819,   407560381,   432897131,   468734377,
	556368823,   588383363,   633068497,   665362081,   717397817,   771867997,
	773652487,   821146201,   875510453,   900546047,   1154772097,  1187122043,
	1209001181,  1252109039,  1548726757,  1583686249,  1654707661,  1669720813,
	1721118499,  1785257767,  2401783861,  2509908811,  2650017823,  2822422711,
	2833118147,  3514535009,  3571824167,  3646253383,  3775153601,  4136745101,
};

const ULONG nPrimes = (sizeof (Primes) / sizeof (Primes [0]));


ULONG
HashPjw(
	LPCSTR	sz
	)
/*++

Routine Description:

	Peter Weinberger's hash function from the Red Dragon Book.

--*/
{
	LPCSTR		p = NULL;
	ULONG		h = 0;
	ULONG		g = 0;

	for (p = sz; *p ; p++) {
	
		h = (h << 4) + *p;
		g = h & 0xF0000000;

		if (g) {
			h = h ^ (g >> 24);
			h ^= g;
		}
	}

	return h;
}

