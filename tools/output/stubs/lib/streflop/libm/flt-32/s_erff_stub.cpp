/* See the import.pl script for potential modifications */
/* s_erff.c -- Simple version of s_erf.c.
 * Conversion to Simple by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

#if defined(LIBM_SCCS) && !defined(lint)
static char rcsid[] = "$NetBSD: s_erff.c,v 1.4f 1995/05/10 20:47:07 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
tiny	    = 1e-30f,
half=  5.0000000000e-01f, /* 0x3F000000 */
one =  1.0000000000e+00f, /* 0x3F800000 */
two =  2.0000000000e+00f, /* 0x40000000 */
	/* c = (subfloat)0.84506291151f */
erx =  8.4506291151e-01f, /* 0x3f58560b */
/*
 * Coefficients for approximation to  erf on [0,0.84375]
 */
efx =  1.2837916613e-01f, /* 0x3e0375d4 */
efx8=  1.0270333290e+00f, /* 0x3f8375d4 */
pp0  =  1.2837916613e-01f, /* 0x3e0375d4 */
pp1  = -3.2504209876e-01f, /* 0xbea66beb */
pp2  = -2.8481749818e-02f, /* 0xbce9528f */
pp3  = -5.7702702470e-03f, /* 0xbbbd1489 */
pp4  = -2.3763017452e-05f, /* 0xb7c756b1 */
qq1  =  3.9791721106e-01f, /* 0x3ecbbbce */
qq2  =  6.5022252500e-02f, /* 0x3d852a63 */
qq3  =  5.0813062117e-03f, /* 0x3ba68116 */
qq4  =  1.3249473704e-04f, /* 0x390aee49 */
qq5  = -3.9602282413e-06f, /* 0xb684e21a */
/*
 * Coefficients for approximation to  erf  in [0.84375f,1.25f] 
 */
pa0  = -2.3621185683e-03f, /* 0xbb1acdc6 */
pa1  =  4.1485610604e-01f, /* 0x3ed46805 */
pa2  = -3.7220788002e-01f, /* 0xbebe9208 */
pa3  =  3.1834661961e-01f, /* 0x3ea2fe54 */
pa4  = -1.1089469492e-01f, /* 0xbde31cc2 */
pa5  =  3.5478305072e-02f, /* 0x3d1151b3 */
pa6  = -2.1663755178e-03f, /* 0xbb0df9c0 */
qa1  =  1.0642088205e-01f, /* 0x3dd9f331 */
qa2  =  5.4039794207e-01f, /* 0x3f0a5785 */
qa3  =  7.1828655899e-02f, /* 0x3d931ae7 */
qa4  =  1.2617121637e-01f, /* 0x3e013307 */
qa5  =  1.3637083583e-02f, /* 0x3c5f6e13 */
qa6  =  1.1984500103e-02f, /* 0x3c445aa3 */
/*
 * Coefficients for approximation to  erfc in [1.25f,1/0.35f]
 */
ra0  = -9.8649440333e-03f, /* 0xbc21a093 */
ra1  = -6.9385856390e-01f, /* 0xbf31a0b7 */
ra2  = -1.0558626175e+01f, /* 0xc128f022 */
ra3  = -6.2375331879e+01f, /* 0xc2798057 */
ra4  = -1.6239666748e+02f, /* 0xc322658c */
ra5  = -1.8460508728e+02f, /* 0xc3389ae7 */
ra6  = -8.1287437439e+01f, /* 0xc2a2932b */
ra7  = -9.8143291473e+00f, /* 0xc11d077e */
sa1  =  1.9651271820e+01f, /* 0x419d35ce */
sa2  =  1.3765776062e+02f, /* 0x4309a863 */
sa3  =  4.3456588745e+02f, /* 0x43d9486f */
sa4  =  6.4538726807e+02f, /* 0x442158c9 */
sa5  =  4.2900814819e+02f, /* 0x43d6810b */
sa6  =  1.0863500214e+02f, /* 0x42d9451f */
sa7  =  6.5702495575e+00f, /* 0x40d23f7c */
sa8  = -6.0424413532e-02f, /* 0xbd777f97 */
/*
 * Coefficients for approximation to  erfc in [1/.35f,28]
 */
rb0  = -9.8649431020e-03f, /* 0xbc21a092 */
rb1  = -7.9928326607e-01f, /* 0xbf4c9dd4 */
rb2  = -1.7757955551e+01f, /* 0xc18e104b */
rb3  = -1.6063638306e+02f, /* 0xc320a2ea */
rb4  = -6.3756646729e+02f, /* 0xc41f6441 */
rb5  = -1.0250950928e+03f, /* 0xc480230b */
rb6  = -4.8351919556e+02f, /* 0xc3f1c275 */
sb1  =  3.0338060379e+01f, /* 0x41f2b459 */
sb2  =  3.2579251099e+02f, /* 0x43a2e571 */
sb3  =  1.5367296143e+03f, /* 0x44c01759 */
sb4  =  3.1998581543e+03f, /* 0x4547fdbb */
sb5  =  2.5530502930e+03f, /* 0x451f90ce */
sb6  =  4.7452853394e+02f, /* 0x43ed43a7 */
sb7  = -2.2440952301e+01f; /* 0xc1b38712 */

#ifdef __STDC__
	Simple __erff(Simple x)
#else
	Simple __erff(x)
	Simple x;
#endif
{
    //stub method
}
weak_alias (__erff, erff)

#ifdef __STDC__
	Simple __erfcf(Simple x)
#else
	Simple __erfcf(x)
	Simple x;
#endif
{
    //stub method
}
weak_alias (__erfcf, erfcf)
}
