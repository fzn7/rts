#include <iostream>
/* See the import.pl script for potential modifications */
/* e_expf.c -- Simple version of e_exp.c.
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
static char rcsid[] = "$NetBSD: e_expf.c,v 1.6f 1996/04/08 15:43:43 phil Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

static const Simple huge = 1.0e+30f;

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
  one = 1.0f,
  halF[2] =
    {
        0.5f,
        -0.5f,
    },
  twom100 = 7.8886090522e-31f,      /* 2**-100=0x0d800000 */
  o_threshold = 8.8721679688e+01f,  /* 0x42b17180 */
  u_threshold = -1.0397208405e+02f, /* 0xc2cff1b5 */
  ln2HI[2] =
    {
        6.9313812256e-01f, /* 0x3f317180 */
        -6.9313812256e-01f,
    }, /* 0xbf317180 */
  ln2LO[2] =
    {
        9.0580006145e-06f, /* 0x3717f7d1 */
        -9.0580006145e-06f,
    },                        /* 0xb717f7d1 */
  invln2 = 1.4426950216e+00f, /* 0x3fb8aa3b */
  P1 = 1.6666667163e-01f,     /* 0x3e2aaaab */
  P2 = -2.7777778450e-03f,    /* 0xbb360b61 */
  P3 = 6.6137559770e-05f,     /* 0x388ab355 */
  P4 = -1.6533901999e-06f,    /* 0xb5ddea0e */
  P5 = 4.1381369442e-08f;     /* 0x3331bb4c */

#ifdef __STDC__
Simple
__ieee754_expf(Simple x) /* default IEEE Double exp */
#else
Simple __ieee754_expf(x) /* default IEEE Double exp */
  Simple x;
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
