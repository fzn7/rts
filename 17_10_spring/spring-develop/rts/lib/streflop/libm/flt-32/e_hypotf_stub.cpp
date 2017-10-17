#include <iostream>
/* See the import.pl script for potential modifications */
/* e_hypotf.c -- Simple version of e_hypot.c.
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
  "$NetBSD: e_hypotf.c,v 1.5f 1995/05/12 04:57:30 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
Simple
__ieee754_hypotf(Simple x, Simple y)
#else
Simple __ieee754_hypotf(x, y) Simple x, y;
#endif
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
