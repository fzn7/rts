#include <iostream>
/* See the import.pl script for potential modifications */
/* s_floorf.c -- Simple version of s_floor.c.
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
  "$NetBSD: s_floorf.c,v 1.4f 1995/05/10 20:47:22 jtc Exp $";
#endif

/*
 * floorf(x)
 * Return x rounded toward -inf to integral value
 * Method:
 *	Bit twiddling.
 * Exception:
 *	Inexact flag raised if x not equal to floorf(x).
 */

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple huge = 1.0e30f;
#else
static Simple huge = 1.0e30f;
#endif

#ifdef __STDC__
Simple
__floorf(Simple x)
#else
Simple __floorf(x) Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
weak_alias(__floorf, floorf)
}
