#include <iostream>
/* See the import.pl script for potential modifications */
/* s_asinhf.c -- Simple version of s_asinh.c.
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
static char rcsid[] =
  "$NetBSD: s_asinhf.c,v 1.5f 1995/05/12 04:57:39 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
  one = 1.0000000000e+00f, /* 0x3F800000 */
  ln2 = 6.9314718246e-01f, /* 0x3f317218 */
  huge = 1.0000000000e+30f;

#ifdef __STDC__
Simple
__asinhf(Simple x)
#else
Simple __asinhf(x) Simple x;
#endif
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
weak_alias(__asinhf, asinhf)
}
