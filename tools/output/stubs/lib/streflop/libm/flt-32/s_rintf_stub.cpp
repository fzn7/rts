/* See the import.pl script for potential modifications */
/* s_rintf.c -- Simple version of s_rint.c.
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
static char rcsid[] = "$NetBSD: s_rintf.c,v 1.4f 1995/05/10 20:48:06 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple 
#endif
TWO23[2]={
  8.3886080000e+06f, /* 0x4b000000 */
 -8.3886080000e+06f, /* 0xcb000000 */
};

#ifdef __STDC__
	Simple __rintf(Simple x)
#else
	Simple __rintf(x)
	Simple x;
#endif
{
    //stub method
}
weak_alias (__rintf, rintf)
}
