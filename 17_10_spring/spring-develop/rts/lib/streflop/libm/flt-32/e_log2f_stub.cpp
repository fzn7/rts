#include <iostream>
/* See the import.pl script for potential modifications */
/* e_logf.c -- Simple version of e_log.c.
 * Conversion to Simple by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 * adapted for log2 by Ulrich Drepper <drepper@cygnus.com>
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

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
  ln2 = 0.69314718055994530942f,
  two25 = 3.355443200e+07f, /* 0x4c000000 */
  Lg1 = 6.6666668653e-01f,  /* 3F2AAAAB */
  Lg2 = 4.0000000596e-01f,  /* 3ECCCCCD */
  Lg3 = 2.8571429849e-01f,  /* 3E924925 */
  Lg4 = 2.2222198546e-01f,  /* 3E638E29 */
  Lg5 = 1.8183572590e-01f,  /* 3E3A3325 */
  Lg6 = 1.5313838422e-01f,  /* 3E1CD04F */
  Lg7 = 1.4798198640e-01f;  /* 3E178897 */

#ifdef __STDC__
static const Simple zero = 0.0f;
#else
static Simple zero = 0.0f;
#endif

#ifdef __STDC__
Simple
__ieee754_log2f(Simple x)
#else
Simple __ieee754_log2f(x) Simple x;
#endif
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
