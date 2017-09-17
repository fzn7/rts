#include <iostream>
/* See the import.pl script for potential modifications */
/* s_nextafterf.c -- Simple version of s_nextafter.c.
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
static char rcsid[] = "$NetBSD: s_nextafterf.c,v 1.4f 1995/05/10 20:48:01 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"
#include "../streflop_libm_bridge.h"

namespace streflop_libm {
#ifdef __STDC__
	Simple __nextafterf(Simple x, Simple y)
#else
	Simple __nextafterf(x,y)
	Simple x,y;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
weak_alias (__nextafterf, nextafterf)
}
