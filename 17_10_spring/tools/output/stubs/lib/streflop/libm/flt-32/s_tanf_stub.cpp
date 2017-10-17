#include <iostream>
/* See the import.pl script for potential modifications */
/* s_tanf.c -- Simple version of s_tan.c.
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
static char rcsid[] = "$NetBSD: s_tanf.c,v 1.4f 1995/05/10 20:48:20 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
Simple
__tanf(Simple x)
#else
Simple __tanf(x) Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
weak_alias(__tanf, tanf)
}
