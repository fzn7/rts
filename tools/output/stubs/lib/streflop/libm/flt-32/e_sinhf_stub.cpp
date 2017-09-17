/* See the import.pl script for potential modifications */
/* e_sinhf.c -- Simple version of e_sinh.c.
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
static char rcsid[] = "$NetBSD: e_sinhf.c,v 1.4f 1995/05/10 20:46:15 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple one = 1.0f, shuge = 1.0e37f;
#else
static Simple one = 1.0f, shuge = 1.0e37f;
#endif

#ifdef __STDC__
	Simple __ieee754_sinhf(Simple x)
#else
	Simple __ieee754_sinhf(x)
	Simple x;
#endif
{
    //stub method
}
}
