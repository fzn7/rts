#include <iostream>
/* See the import.pl script for potential modifications */
/* e_sqrtf.c -- Simple version of e_sqrt.c.
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
static char rcsid[] = "$NetBSD: e_sqrtf.c,v 1.4f 1995/05/10 20:46:19 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple one = 1.0f, tiny = 1.0e-30f;
#else
static Simple one = 1.0f, tiny = 1.0e-30f;
#endif

#ifdef __STDC__
Simple
__ieee754_sqrtf(Simple x)
#else
Simple __ieee754_sqrtf(x) Simple x;
#endif
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
