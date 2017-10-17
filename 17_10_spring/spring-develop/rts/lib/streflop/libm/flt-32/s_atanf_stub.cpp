#include <iostream>
/* See the import.pl script for potential modifications */
/* s_atanf.c -- Simple version of s_atan.c.
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
static char rcsid[] = "$NetBSD: s_atanf.c,v 1.4f 1995/05/10 20:46:47 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple atanhi[] = {
#else
static Simple atanhi[] = {
#endif
    4.6364760399e-01f, /* atan(0.5f)hi 0x3eed6338 */
    7.8539812565e-01f, /* atan(1.0f)hi 0x3f490fda */
    9.8279368877e-01f, /* atan(1.5f)hi 0x3f7b985e */
    1.5707962513e+00f, /* atan(inf)hi 0x3fc90fda */
};

#ifdef __STDC__
static const Simple atanlo[] = {
#else
static Simple atanlo[] = {
#endif
    5.0121582440e-09f, /* atan(0.5f)lo 0x31ac3769 */
    3.7748947079e-08f, /* atan(1.0f)lo 0x33222168 */
    3.4473217170e-08f, /* atan(1.5f)lo 0x33140fb4 */
    7.5497894159e-08f, /* atan(inf)lo 0x33a22168 */
};

#ifdef __STDC__
static const Simple aT[] = {
#else
static Simple aT[] = {
#endif
    3.3333334327e-01f,  /* 0x3eaaaaaa */
    -2.0000000298e-01f, /* 0xbe4ccccd */
    1.4285714924e-01f,  /* 0x3e124925 */
    -1.1111110449e-01f, /* 0xbde38e38 */
    9.0908870101e-02f,  /* 0x3dba2e6e */
    -7.6918758452e-02f, /* 0xbd9d8795 */
    6.6610731184e-02f,  /* 0x3d886b35 */
    -5.8335702866e-02f, /* 0xbd6ef16b */
    4.9768779427e-02f,  /* 0x3d4bda59 */
    -3.6531571299e-02f, /* 0xbd15a221 */
    1.6285819933e-02f,  /* 0x3c8569d7 */
};

#ifdef __STDC__
static const Simple
#else
static Simple
#endif
  one = 1.0f,
  huge = 1.0e30f;

#ifdef __STDC__
Simple
__atanf(Simple x)
#else
Simple __atanf(x) Simple x;
#endif
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
weak_alias(__atanf, atanf)
}
