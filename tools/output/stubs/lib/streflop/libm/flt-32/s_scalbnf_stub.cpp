#include <iostream>
/* See the import.pl script for potential modifications */
/* s_scalbnf.c -- Simple version of s_scalbn.c.
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
static char rcsid[] = "$NetBSD: s_scalbnf.c,v 1.4f 1995/05/10 20:48:10 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
two25   =  3.355443200e+07f,	/* 0x4c000000 */
twom25  =  2.9802322388e-08f,	/* 0x33000000 */
huge   = 1.0e+30f,
tiny   = 1.0e-30f;

#ifdef __STDC__
	Simple __scalbnf (Simple x, int n)
#else
	Simple __scalbnf (x,n)
	Simple x; int n;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
weak_alias (__scalbnf, scalbnf)
}
