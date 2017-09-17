/* See the import.pl script for potential modifications */
/* s_ceilf.c -- Simple version of s_ceil.c.
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
static char rcsid[] = "$NetBSD: s_ceilf.c,v 1.4f 1995/05/10 20:46:55 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple huge = 1.0e30f;
#else
static Simple huge = 1.0e30f;
#endif

#ifdef __STDC__
	Simple __ceilf(Simple x)
#else
	Simple __ceilf(x)
	Simple x;
#endif
{
    //stub method
}
weak_alias (__ceilf, ceilf)
}
