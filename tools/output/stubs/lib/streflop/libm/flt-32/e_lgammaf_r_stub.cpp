#include <iostream>
/* See the import.pl script for potential modifications */
/* e_lgammaf_r.c -- Simple version of e_lgamma_r.c.
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
static char rcsid[] = "$NetBSD: e_lgammaf_r.c,v 1.3f 1995/05/10 20:45:47 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
two23=  8.3886080000e+06f, /* 0x4b000000 */
half=  5.0000000000e-01f, /* 0x3f000000 */
one =  1.0000000000e+00f, /* 0x3f800000 */
pi  =  3.1415927410e+00f, /* 0x40490fdb */
a0  =  7.7215664089e-02f, /* 0x3d9e233f */
a1  =  3.2246702909e-01f, /* 0x3ea51a66 */
a2  =  6.7352302372e-02f, /* 0x3d89f001 */
a3  =  2.0580807701e-02f, /* 0x3ca89915 */
a4  =  7.3855509982e-03f, /* 0x3bf2027e */
a5  =  2.8905137442e-03f, /* 0x3b3d6ec6 */
a6  =  1.1927076848e-03f, /* 0x3a9c54a1 */
a7  =  5.1006977446e-04f, /* 0x3a05b634 */
a8  =  2.2086278477e-04f, /* 0x39679767 */
a9  =  1.0801156895e-04f, /* 0x38e28445 */
a10 =  2.5214456400e-05f, /* 0x37d383a2 */
a11 =  4.4864096708e-05f, /* 0x383c2c75 */
tc  =  1.4616321325e+00f, /* 0x3fbb16c3 */
tf  = -1.2148628384e-01f, /* 0xbdf8cdcd */
/* tt = -(tail of tf) */
tt  =  6.6971006518e-09f, /* 0x31e61c52 */
t0  =  4.8383611441e-01f, /* 0x3ef7b95e */
t1  = -1.4758771658e-01f, /* 0xbe17213c */
t2  =  6.4624942839e-02f, /* 0x3d845a15 */
t3  = -3.2788541168e-02f, /* 0xbd064d47 */
t4  =  1.7970675603e-02f, /* 0x3c93373d */
t5  = -1.0314224288e-02f, /* 0xbc28fcfe */
t6  =  6.1005386524e-03f, /* 0x3bc7e707 */
t7  = -3.6845202558e-03f, /* 0xbb7177fe */
t8  =  2.2596477065e-03f, /* 0x3b141699 */
t9  = -1.4034647029e-03f, /* 0xbab7f476 */
t10 =  8.8108185446e-04f, /* 0x3a66f867 */
t11 = -5.3859531181e-04f, /* 0xba0d3085 */
t12 =  3.1563205994e-04f, /* 0x39a57b6b */
t13 = -3.1275415677e-04f, /* 0xb9a3f927 */
t14 =  3.3552918467e-04f, /* 0x39afe9f7 */
u0  = -7.7215664089e-02f, /* 0xbd9e233f */
u1  =  6.3282704353e-01f, /* 0x3f2200f4 */
u2  =  1.4549225569e+00f, /* 0x3fba3ae7 */
u3  =  9.7771751881e-01f, /* 0x3f7a4bb2 */
u4  =  2.2896373272e-01f, /* 0x3e6a7578 */
u5  =  1.3381091878e-02f, /* 0x3c5b3c5e */
v1  =  2.4559779167e+00f, /* 0x401d2ebe */
v2  =  2.1284897327e+00f, /* 0x4008392d */
v3  =  7.6928514242e-01f, /* 0x3f44efdf */
v4  =  1.0422264785e-01f, /* 0x3dd572af */
v5  =  3.2170924824e-03f, /* 0x3b52d5db */
s0  = -7.7215664089e-02f, /* 0xbd9e233f */
s1  =  2.1498242021e-01f, /* 0x3e5c245a */
s2  =  3.2577878237e-01f, /* 0x3ea6cc7a */
s3  =  1.4635047317e-01f, /* 0x3e15dce6 */
s4  =  2.6642270386e-02f, /* 0x3cda40e4 */
s5  =  1.8402845599e-03f, /* 0x3af135b4 */
s6  =  3.1947532989e-05f, /* 0x3805ff67 */
r1  =  1.3920053244e+00f, /* 0x3fb22d3b */
r2  =  7.2193557024e-01f, /* 0x3f38d0c5 */
r3  =  1.7193385959e-01f, /* 0x3e300f6e */
r4  =  1.8645919859e-02f, /* 0x3c98bf54 */
r5  =  7.7794247773e-04f, /* 0x3a4beed6 */
r6  =  7.3266842264e-06f, /* 0x36f5d7bd */
w0  =  4.1893854737e-01f, /* 0x3ed67f1d */
w1  =  8.3333335817e-02f, /* 0x3daaaaab */
w2  = -2.7777778450e-03f, /* 0xbb360b61 */
w3  =  7.9365057172e-04f, /* 0x3a500cfd */
w4  = -5.9518753551e-04f, /* 0xba1c065c */
w5  =  8.3633989561e-04f, /* 0x3a5b3dd2 */
w6  = -1.6309292987e-03f; /* 0xbad5c4e8 */

#ifdef __STDC__
static const Simple zero=  0.0000000000e+00f;
#else
static Simple zero=  0.0000000000e+00f;
#endif

#ifdef __STDC__
	static Simple sin_pif(Simple x)
#else
	static Simple sin_pif(x)
	Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


#ifdef __STDC__
	Simple __ieee754_lgammaf_r(Simple x, int *signgamp)
#else
	Simple __ieee754_lgammaf_r(x,signgamp)
	Simple x; int *signgamp;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
