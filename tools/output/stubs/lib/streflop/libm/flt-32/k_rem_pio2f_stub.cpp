#include <iostream>
/* See the import.pl script for potential modifications */
/* k_rem_pio2f.c -- Simple version of k_rem_pio2.c
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
static char rcsid[] = "$NetBSD: k_rem_pio2f.c,v 1.4f 1995/05/10 20:46:28 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

/* In the Simple version, the input parameter x contains 8 bit
   integers, not 24 bit integers.  113 bit precision is not supported.  */

namespace streflop_libm {
#ifdef __STDC__
static const int init_jk[] = {4,7,9}; /* initial value for jk */
#else
static int init_jk[] = {4,7,9}; 
#endif

#ifdef __STDC__
static const Simple PIo2[] = {
#else
static Simple PIo2[] = {
#endif
  1.5703125000e+00f, /* 0x3fc90000 */
  4.5776367188e-04f, /* 0x39f00000 */
  2.5987625122e-05f, /* 0x37da0000 */
  7.5437128544e-08f, /* 0x33a20000 */
  6.0026650317e-11f, /* 0x2e840000 */
  7.3896444519e-13f, /* 0x2b500000 */
  5.3845816694e-15f, /* 0x27c20000 */
  5.6378512969e-18f, /* 0x22d00000 */
  8.3009228831e-20f, /* 0x1fc40000 */
  3.2756352257e-22f, /* 0x1bc60000 */
  6.3331015649e-25f, /* 0x17440000 */
};

#ifdef __STDC__
static const Simple			
#else
static Simple			
#endif
zero   = 0.0f,
one    = 1.0f,
two8   =  2.5600000000e+02f, /* 0x43800000 */
twon8  =  3.9062500000e-03f; /* 0x3b800000 */

#ifdef __STDC__
	int __kernel_rem_pio2f(Simple *x, Simple *y, int e0, int nx, int prec, const int32_t *ipio2) 
#else
	int __kernel_rem_pio2f(x,y,e0,nx,prec,ipio2) 	
	Simple x[], y[]; int e0,nx,prec; int32_t ipio2[];
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
