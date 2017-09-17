/* See the import.pl script for potential modifications */
/* e_jnf.c -- Simple version of e_jn.c.
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
static char rcsid[] = "$NetBSD: e_jnf.c,v 1.5f 1995/05/10 20:45:37 jtc Exp $";
#endif

#include "math.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
two   =  2.0000000000e+00f, /* 0x40000000 */
one   =  1.0000000000e+00f; /* 0x3F800000 */

#ifdef __STDC__
static const Simple zero  =  0.0000000000e+00f;
#else
static Simple zero  =  0.0000000000e+00f;
#endif

#ifdef __STDC__
	Simple __ieee754_jnf(int n, Simple x)
#else
	Simple __ieee754_jnf(n,x)
	int n; Simple x;
#endif
{
    //stub method
}

#ifdef __STDC__
	Simple __ieee754_ynf(int n, Simple x)
#else
	Simple __ieee754_ynf(n,x)
	int n; Simple x;
#endif
{
    //stub method
}
}
