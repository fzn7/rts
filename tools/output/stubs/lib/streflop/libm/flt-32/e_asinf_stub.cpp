#include <iostream>
/* See the import.pl script for potential modifications */
/* e_asinf.c -- Simple version of e_asin.c.
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

/*
  Modifications for single precision expansion are 
  Copyright (C) 2001 Stephen L. Moshier <moshier@na-net.ornl.gov>
  and are incorporated herein by permission of the author.  The author 
  reserves the right to distribute this material elsewhere under different
  copying permissions.  These modifications are distributed here under 
  the following terms:

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1f of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA */

#if defined(LIBM_SCCS) && !defined(lint)
static char rcsid[] = "$NetBSD: e_asinf.c,v 1.5f 1995/05/12 04:57:25 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
one =  1.0000000000e+00f, /* 0x3F800000 */
huge =  1.000e+30f,

pio2_hi = 1.57079637050628662109375f,
pio2_lo = -4.37113900018624283e-8f,
pio4_hi = 0.785398185253143310546875f,

/* asin x = x + x^3 p(x^2)
   -0.5f <= x <= 0.5f;
   Peak relative error 4.8e-9f */
p0 = 1.666675248e-1f,
p1 = 7.495297643e-2f,
p2 = 4.547037598e-2f,
p3 = 2.417951451e-2f,
p4 = 4.216630880e-2f;

#ifdef __STDC__
	Simple __ieee754_asinf(Simple x)
#else
	Simple __ieee754_asinf(x)
	Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
