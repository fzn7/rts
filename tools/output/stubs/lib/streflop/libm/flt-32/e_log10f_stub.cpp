#include <iostream>
/* See the import.pl script for potential modifications */
/* e_log10f.c -- Simple version of e_log10.c.
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
static char rcsid[] = "$NetBSD: e_log10f.c,v 1.5f 1995/05/10 20:45:53 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
two25      =  3.3554432000e+07f, /* 0x4c000000 */
ivln10     =  4.3429449201e-01f, /* 0x3ede5bd9 */
log10_2hi  =  3.0102920532e-01f, /* 0x3e9a2080 */
log10_2lo  =  7.9034151668e-07f; /* 0x355427db */

#ifdef __STDC__
static const Simple zero   =  0.0f;
#else
static Simple zero   =  0.0f;
#endif

#ifdef __STDC__
	Simple __ieee754_log10f(Simple x)
#else
	Simple __ieee754_log10f(x)
	Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
