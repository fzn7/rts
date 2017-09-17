#include <iostream>
/* See the import.pl script for potential modifications */
/* e_acosf.c -- Simple version of e_acos.c.
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
static char rcsid[] = "$NetBSD: e_acosf.c,v 1.5f 1995/05/12 04:57:16 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
  one = 1.0000000000e+00f,     /* 0x3F800000 */
  pi = 3.1415925026e+00f,      /* 0x40490fda */
  pio2_hi = 1.5707962513e+00f, /* 0x3fc90fda */
  pio2_lo = 7.5497894159e-08f, /* 0x33a22168 */
  pS0 = 1.6666667163e-01f,     /* 0x3e2aaaab */
  pS1 = -3.2556581497e-01f,    /* 0xbea6b090 */
  pS2 = 2.0121252537e-01f,     /* 0x3e4e0aa8 */
  pS3 = -4.0055535734e-02f,    /* 0xbd241146 */
  pS4 = 7.9153501429e-04f,     /* 0x3a4f7f04 */
  pS5 = 3.4793309169e-05f,     /* 0x3811ef08 */
  qS1 = -2.4033949375e+00f,    /* 0xc019d139 */
  qS2 = 2.0209457874e+00f,     /* 0x4001572d */
  qS3 = -6.8828397989e-01f,    /* 0xbf303361 */
  qS4 = 7.7038154006e-02f;     /* 0x3d9dc62e */

#ifdef __STDC__
Simple
__ieee754_acosf(Simple x)
#else
Simple __ieee754_acosf(x) Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
