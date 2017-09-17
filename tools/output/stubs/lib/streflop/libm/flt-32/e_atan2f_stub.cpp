#include <iostream>
/* See the import.pl script for potential modifications */
/* e_atan2f.c -- Simple version of e_atan2.c.
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
static char rcsid[] = "$NetBSD: e_atan2f.c,v 1.4f 1995/05/10 20:44:53 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
tiny  = 1.0e-30f,
zero  = 0.0f,
pi_o_4  = 7.8539818525e-01f,  /* 0x3f490fdb */
pi_o_2  = 1.5707963705e+00f,  /* 0x3fc90fdb */
pi      = 3.1415927410e+00f,  /* 0x40490fdb */
pi_lo   = -8.7422776573e-08f; /* 0xb3bbbd2e */

#ifdef __STDC__
	Simple __ieee754_atan2f(Simple y, Simple x)
#else
	Simple __ieee754_atan2f(y,x)
	Simple  y,x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
