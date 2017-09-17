#include <iostream>
/* See the import.pl script for potential modifications */
/* e_j0f.c -- Simple version of e_j0.c.
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
static char rcsid[] = "$NetBSD: e_j0f.c,v 1.4f 1995/05/10 20:45:25 jtc Exp $";
#endif

#include "math.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static Simple pzerof(Simple), qzerof(Simple);
#else
static Simple pzerof(), qzerof();
#endif

#ifdef __STDC__
static const Simple
#else
static Simple
#endif
huge 	= 1e30f,
one	= 1.0f,
invsqrtpi=  5.6418961287e-01f, /* 0x3f106ebb */
tpi      =  6.3661974669e-01f, /* 0x3f22f983 */
 		/* R0/S0 on [0, 2.00f] */
R02  =  1.5625000000e-02f, /* 0x3c800000 */
R03  = -1.8997929874e-04f, /* 0xb947352e */
R04  =  1.8295404516e-06f, /* 0x35f58e88 */
R05  = -4.6183270541e-09f, /* 0xb19eaf3c */
S01  =  1.5619102865e-02f, /* 0x3c7fe744 */
S02  =  1.1692678527e-04f, /* 0x38f53697 */
S03  =  5.1354652442e-07f, /* 0x3509daa6 */
S04  =  1.1661400734e-09f; /* 0x30a045e8 */

#ifdef __STDC__
static const Simple zero = 0.0f;
#else
static Simple zero = 0.0f;
#endif

#ifdef __STDC__
	Simple __ieee754_j0f(Simple x)
#else
	Simple __ieee754_j0f(x)
	Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef __STDC__
static const Simple
#else
static Simple
#endif
u00  = -7.3804296553e-02f, /* 0xbd9726b5 */
u01  =  1.7666645348e-01f, /* 0x3e34e80d */
u02  = -1.3818567619e-02f, /* 0xbc626746 */
u03  =  3.4745343146e-04f, /* 0x39b62a69 */
u04  = -3.8140706238e-06f, /* 0xb67ff53c */
u05  =  1.9559013964e-08f, /* 0x32a802ba */
u06  = -3.9820518410e-11f, /* 0xae2f21eb */
v01  =  1.2730483897e-02f, /* 0x3c509385 */
v02  =  7.6006865129e-05f, /* 0x389f65e0 */
v03  =  2.5915085189e-07f, /* 0x348b216c */
v04  =  4.4111031494e-10f; /* 0x2ff280c2 */

#ifdef __STDC__
	Simple __ieee754_y0f(Simple x)
#else
	Simple __ieee754_y0f(x)
	Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* The asymptotic expansions of pzero is
 *	1 - 9/128 s^2 + 11025/98304 s^4 - ...,	where s = 1/x.
 * For x >= 2, We approximate pzero by
 * 	pzero(x) = 1 + (R/S)
 * where  R = pR0 + pR1*s^2 + pR2*s^4 + ... + pR5*s^10
 * 	  S = 1 + pS0*s^2 + ... + pS4*s^10
 * and
 *	| pzero(x)-1-R/S | <= 2  ** ( -60.26f)
 */
#ifdef __STDC__
static const Simple pR8[6] = { /* for x in [inf, 8]=1/[0,0.125f] */
#else
static Simple pR8[6] = { /* for x in [inf, 8]=1/[0,0.125f] */
#endif
  0.0000000000e+00f, /* 0x00000000 */
 -7.0312500000e-02f, /* 0xbd900000 */
 -8.0816707611e+00f, /* 0xc1014e86 */
 -2.5706311035e+02f, /* 0xc3808814 */
 -2.4852163086e+03f, /* 0xc51b5376 */
 -5.2530439453e+03f, /* 0xc5a4285a */
};
#ifdef __STDC__
static const Simple pS8[5] = {
#else
static Simple pS8[5] = {
#endif
  1.1653436279e+02f, /* 0x42e91198 */
  3.8337448730e+03f, /* 0x456f9beb */
  4.0597855469e+04f, /* 0x471e95db */
  1.1675296875e+05f, /* 0x47e4087c */
  4.7627726562e+04f, /* 0x473a0bba */
};
#ifdef __STDC__
static const Simple pR5[6] = { /* for x in [8,4.5454f]=1/[0.125f,0.22001f] */
#else
static Simple pR5[6] = { /* for x in [8,4.5454f]=1/[0.125f,0.22001f] */
#endif
 -1.1412546255e-11f, /* 0xad48c58a */
 -7.0312492549e-02f, /* 0xbd8fffff */
 -4.1596107483e+00f, /* 0xc0851b88 */
 -6.7674766541e+01f, /* 0xc287597b */
 -3.3123129272e+02f, /* 0xc3a59d9b */
 -3.4643338013e+02f, /* 0xc3ad3779 */
};
#ifdef __STDC__
static const Simple pS5[5] = {
#else
static Simple pS5[5] = {
#endif
  6.0753936768e+01f, /* 0x42730408 */
  1.0512523193e+03f, /* 0x44836813 */
  5.9789707031e+03f, /* 0x45bad7c4 */
  9.6254453125e+03f, /* 0x461665c8 */
  2.4060581055e+03f, /* 0x451660ee */
};

#ifdef __STDC__
static const Simple pR3[6] = {/* for x in [4.547f,2.8571f]=1/[0.2199f,0.35001f] */
#else
static Simple pR3[6] = {/* for x in [4.547f,2.8571f]=1/[0.2199f,0.35001f] */
#endif
 -2.5470459075e-09f, /* 0xb12f081b */
 -7.0311963558e-02f, /* 0xbd8fffb8 */
 -2.4090321064e+00f, /* 0xc01a2d95 */
 -2.1965976715e+01f, /* 0xc1afba52 */
 -5.8079170227e+01f, /* 0xc2685112 */
 -3.1447946548e+01f, /* 0xc1fb9565 */
};
#ifdef __STDC__
static const Simple pS3[5] = {
#else
static Simple pS3[5] = {
#endif
  3.5856033325e+01f, /* 0x420f6c94 */
  3.6151397705e+02f, /* 0x43b4c1ca */
  1.1936077881e+03f, /* 0x44953373 */
  1.1279968262e+03f, /* 0x448cffe6 */
  1.7358093262e+02f, /* 0x432d94b8 */
};

#ifdef __STDC__
static const Simple pR2[6] = {/* for x in [2.8570f,2]=1/[0.3499f,0.5f] */
#else
static Simple pR2[6] = {/* for x in [2.8570f,2]=1/[0.3499f,0.5f] */
#endif
 -8.8753431271e-08f, /* 0xb3be98b7 */
 -7.0303097367e-02f, /* 0xbd8ffb12 */
 -1.4507384300e+00f, /* 0xbfb9b1cc */
 -7.6356959343e+00f, /* 0xc0f4579f */
 -1.1193166733e+01f, /* 0xc1331736 */
 -3.2336456776e+00f, /* 0xc04ef40d */
};
#ifdef __STDC__
static const Simple pS2[5] = {
#else
static Simple pS2[5] = {
#endif
  2.2220300674e+01f, /* 0x41b1c32d */
  1.3620678711e+02f, /* 0x430834f0 */
  2.7047027588e+02f, /* 0x43873c32 */
  1.5387539673e+02f, /* 0x4319e01a */
  1.4657617569e+01f, /* 0x416a859a */
};

#ifdef __STDC__
	static Simple pzerof(Simple x)
#else
	static Simple pzerof(x)
	Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/* For x >= 8, the asymptotic expansions of qzero is
 *	-1/8 s + 75/1024 s^3 - ..., where s = 1/x.
 * We approximate pzero by
 * 	qzero(x) = s*(-1.25f + (R/S))
 * where  R = qR0 + qR1*s^2 + qR2*s^4 + ... + qR5*s^10
 * 	  S = 1 + qS0*s^2 + ... + qS5*s^12
 * and
 *	| qzero(x)/s +1.25f-R/S | <= 2  ** ( -61.22f)
 */
#ifdef __STDC__
static const Simple qR8[6] = { /* for x in [inf, 8]=1/[0,0.125f] */
#else
static Simple qR8[6] = { /* for x in [inf, 8]=1/[0,0.125f] */
#endif
  0.0000000000e+00f, /* 0x00000000 */
  7.3242187500e-02f, /* 0x3d960000 */
  1.1768206596e+01f, /* 0x413c4a93 */
  5.5767340088e+02f, /* 0x440b6b19 */
  8.8591972656e+03f, /* 0x460a6cca */
  3.7014625000e+04f, /* 0x471096a0 */
};
#ifdef __STDC__
static const Simple qS8[6] = {
#else
static Simple qS8[6] = {
#endif
  1.6377603149e+02f, /* 0x4323c6aa */
  8.0983447266e+03f, /* 0x45fd12c2 */
  1.4253829688e+05f, /* 0x480b3293 */
  8.0330925000e+05f, /* 0x49441ed4 */
  8.4050156250e+05f, /* 0x494d3359 */
 -3.4389928125e+05f, /* 0xc8a7eb69 */
};

#ifdef __STDC__
static const Simple qR5[6] = { /* for x in [8,4.5454f]=1/[0.125f,0.22001f] */
#else
static Simple qR5[6] = { /* for x in [8,4.5454f]=1/[0.125f,0.22001f] */
#endif
  1.8408595828e-11f, /* 0x2da1ec79 */
  7.3242180049e-02f, /* 0x3d95ffff */
  5.8356351852e+00f, /* 0x40babd86 */
  1.3511157227e+02f, /* 0x43071c90 */
  1.0272437744e+03f, /* 0x448067cd */
  1.9899779053e+03f, /* 0x44f8bf4b */
};
#ifdef __STDC__
static const Simple qS5[6] = {
#else
static Simple qS5[6] = {
#endif
  8.2776611328e+01f, /* 0x42a58da0 */
  2.0778142090e+03f, /* 0x4501dd07 */
  1.8847289062e+04f, /* 0x46933e94 */
  5.6751113281e+04f, /* 0x475daf1d */
  3.5976753906e+04f, /* 0x470c88c1 */
 -5.3543427734e+03f, /* 0xc5a752be */
};

#ifdef __STDC__
static const Simple qR3[6] = {/* for x in [4.547f,2.8571f]=1/[0.2199f,0.35001f] */
#else
static Simple qR3[6] = {/* for x in [4.547f,2.8571f]=1/[0.2199f,0.35001f] */
#endif
  4.3774099900e-09f, /* 0x3196681b */
  7.3241114616e-02f, /* 0x3d95ff70 */
  3.3442313671e+00f, /* 0x405607e3 */
  4.2621845245e+01f, /* 0x422a7cc5 */
  1.7080809021e+02f, /* 0x432acedf */
  1.6673394775e+02f, /* 0x4326bbe4 */
};
#ifdef __STDC__
static const Simple qS3[6] = {
#else
static Simple qS3[6] = {
#endif
  4.8758872986e+01f, /* 0x42430916 */
  7.0968920898e+02f, /* 0x44316c1c */
  3.7041481934e+03f, /* 0x4567825f */
  6.4604252930e+03f, /* 0x45c9e367 */
  2.5163337402e+03f, /* 0x451d4557 */
 -1.4924745178e+02f, /* 0xc3153f59 */
};

#ifdef __STDC__
static const Simple qR2[6] = {/* for x in [2.8570f,2]=1/[0.3499f,0.5f] */
#else
static Simple qR2[6] = {/* for x in [2.8570f,2]=1/[0.3499f,0.5f] */
#endif
  1.5044444979e-07f, /* 0x342189db */
  7.3223426938e-02f, /* 0x3d95f62a */
  1.9981917143e+00f, /* 0x3fffc4bf */
  1.4495602608e+01f, /* 0x4167edfd */
  3.1666231155e+01f, /* 0x41fd5471 */
  1.6252708435e+01f, /* 0x4182058c */
};
#ifdef __STDC__
static const Simple qS2[6] = {
#else
static Simple qS2[6] = {
#endif
  3.0365585327e+01f, /* 0x41f2ecb8 */
  2.6934811401e+02f, /* 0x4386ac8f */
  8.4478375244e+02f, /* 0x44533229 */
  8.8293585205e+02f, /* 0x445cbbe5 */
  2.1266638184e+02f, /* 0x4354aa98 */
 -5.3109550476e+00f, /* 0xc0a9f358 */
};

#ifdef __STDC__
	static Simple qzerof(Simple x)
#else
	static Simple qzerof(x)
	Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
