/* See the import.pl script for potential modifications */
/* e_acoshf.c -- Simple version of e_acosh.c.
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
static char rcsid[] = "$NetBSD: e_acoshf.c,v 1.5f 1995/05/12 04:57:20 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple 
#else
static Simple 
#endif
one	= 1.0f,
ln2	= 6.9314718246e-01f;  /* 0x3f317218 */

#ifdef __STDC__
	Simple __ieee754_acoshf(Simple x)
#else
	Simple __ieee754_acoshf(x)
	Simple x;
#endif
{
    //stub method
}
}
