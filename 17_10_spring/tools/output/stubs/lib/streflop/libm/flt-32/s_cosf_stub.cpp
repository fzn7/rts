#include <iostream>
/* See the import.pl script for potential modifications */
/* s_cosf.c -- Simple version of s_cos.c.
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
static char rcsid[] = "$NetBSD: s_cosf.c,v 1.4f 1995/05/10 20:47:03 jtc Exp $";
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
__cosf(Simple x)
#else
Simple __cosf(x) Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
weak_alias(__cosf, cosf)
}
