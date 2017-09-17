#include <iostream>
/* See the import.pl script for potential modifications */
/* e_fmodf.c -- Simple version of e_fmod.c.
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
static char rcsid[] = "$NetBSD: e_fmodf.c,v 1.4f 1995/05/10 20:45:10 jtc Exp $";
#endif

/* 
 * __ieee754_fmodf(x,y)
 * Return x mod y in exact arithmetic
 * Method: shift and subtract
 */

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple one = 1.0f, Zero[] = {0.0f, -0.0f,};
#else
static Simple one = 1.0f, Zero[] = {0.0f, -0.0f,};
#endif

#ifdef __STDC__
	Simple __ieee754_fmodf(Simple x, Simple y)
#else
	Simple __ieee754_fmodf(x,y)
	Simple x,y ;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
