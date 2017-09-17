#include <iostream>
/* See the import.pl script for potential modifications */
/* e_powf.c -- Simple version of e_pow.c.
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
static char rcsid[] = "$NetBSD: e_powf.c,v 1.7f 1996/04/08 15:43:44 phil Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

static const Simple huge = 1.0e+30f, tiny = 1.0e-30f;

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
  bp[] =
    {
        1.0f,
        1.5f,
    },
  dp_h[] =
    {
        0.0f,
        5.84960938e-01f,
    }, /* 0x3f15c000 */
  dp_l[] =
    {
        0.0f,
        1.56322085e-06f,
    },                                                      /* 0x35d1cfdc */
  zero = 0.0f, one = 1.0f, two = 2.0f, two24 = 16777216.0f, /* 0x4b800000 */
  /* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
  L1 = 6.0000002384e-01f,      /* 0x3f19999a */
  L2 = 4.2857143283e-01f,      /* 0x3edb6db7 */
  L3 = 3.3333334327e-01f,      /* 0x3eaaaaab */
  L4 = 2.7272811532e-01f,      /* 0x3e8ba305 */
  L5 = 2.3066075146e-01f,      /* 0x3e6c3255 */
  L6 = 2.0697501302e-01f,      /* 0x3e53f142 */
  P1 = 1.6666667163e-01f,      /* 0x3e2aaaab */
  P2 = -2.7777778450e-03f,     /* 0xbb360b61 */
  P3 = 6.6137559770e-05f,      /* 0x388ab355 */
  P4 = -1.6533901999e-06f,     /* 0xb5ddea0e */
  P5 = 4.1381369442e-08f,      /* 0x3331bb4c */
  lg2 = 6.9314718246e-01f,     /* 0x3f317218 */
  lg2_h = 6.93145752e-01f,     /* 0x3f317200 */
  lg2_l = 1.42860654e-06f,     /* 0x35bfbe8c */
  ovt = 4.2995665694e-08f,     /* -(128-log2(ovfl+.5ulp)) */
  cp = 9.6179670095e-01f,      /* 0x3f76384f =2/(3ln2) */
  cp_h = 9.6179199219e-01f,    /* 0x3f763800 =head of cp */
  cp_l = 4.7017383622e-06f,    /* 0x369dc3a0 =tail of cp_h */
  ivln2 = 1.4426950216e+00f,   /* 0x3fb8aa3b =1/ln2 */
  ivln2_h = 1.4426879883e+00f, /* 0x3fb8aa00 =16b 1/ln2*/
  ivln2_l = 7.0526075433e-06f; /* 0x36eca570 =1/ln2 tail*/

#ifdef __STDC__
Simple
__ieee754_powf(Simple x, Simple y)
#else
Simple __ieee754_powf(x, y) Simple x, y;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
