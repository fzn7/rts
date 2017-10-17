#include <iostream>
/* See the import.pl script for potential modifications */
/* s_modff.c -- Simple version of s_modf.c.
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
static char rcsid[] = "$NetBSD: s_modff.c,v 1.4f 1995/05/10 20:47:56 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple one = 1.0f;
#else
static Simple one = 1.0f;
#endif

#ifdef __STDC__
Simple
__modff(Simple x, Simple* iptr)
#else
Simple __modff(x, iptr) Simple x, *iptr;
#endif
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
weak_alias(__modff, modff)
}
