#include <iostream>
/* See the import.pl script for potential modifications */
/* k_cosf.c -- Simple version of k_cos.c
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
static char rcsid[] = "$NetBSD: k_cosf.c,v 1.4f 1995/05/10 20:46:23 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple 
#else
static Simple 
#endif
one =  1.0000000000e+00f, /* 0x3f800000 */
C1  =  4.1666667908e-02f, /* 0x3d2aaaab */
C2  = -1.3888889225e-03f, /* 0xbab60b61 */
C3  =  2.4801587642e-05f, /* 0x37d00d01 */
C4  = -2.7557314297e-07f, /* 0xb493f27c */
C5  =  2.0875723372e-09f, /* 0x310f74f6 */
C6  = -1.1359647598e-11f; /* 0xad47d74e */

#ifdef __STDC__
	Simple __kernel_cosf(Simple x, Simple y)
#else
	Simple __kernel_cosf(x, y)
	Simple x,y;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
