/* See the import.pl script for potential modifications */
/* s_rintf.c -- Simple version of s_rint.c.
 * Conversion to Simple by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */
/* Adapted for use as nearbyint by Ulrich Drepper <drepper@cygnus.com>.  */

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


#include "../streflop_libm_bridge.h"
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
	Simple __nearbyintf(Simple x)
#else
	Simple __nearbyintf(x)
	Simple x;
#endif
{
    //stub method
}
weak_alias (__nearbyintf, nearbyintf)
}
