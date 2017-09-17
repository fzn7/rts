/* See the import.pl script for potential modifications */
/* Single-precision floating point 2^x.
   Copyright (C) 1997,1998,2000,2001,2005,2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Geoffrey Keating <geoffk@ozemail.com.au>

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1f of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/* The basic design here is from
   Shmuel Gal and Boris Bachelis, "An Accurate Elementary Mathematical
   Library for the IEEE Floating Point Standard", ACM Trans. Math. Soft.,
   17 (1), March 1991, pp. 26-45.
   It has been slightly modified to compute 2^x instead of e^x, and for
   single-precision.
   */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include "../streflop_libm_bridge.h"
#include "../streflop_libm_bridge.h"
#include "ieee754.h"
#include "SMath.h"
#include "../streflop_libm_bridge.h"
#include "../streflop_libm_bridge.h"
#include "math_private.h"

#include "t_exp2f.h"

static const Simple TWOM100 = 7.88860905e-31f;
static const Simple TWO127 = 1.7014118346e+38f;

namespace streflop_libm {
Simple
__ieee754_exp2f (Simple x)
{
    //stub method
}
}
