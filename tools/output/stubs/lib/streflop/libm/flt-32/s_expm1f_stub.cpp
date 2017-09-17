/* See the import.pl script for potential modifications */
/* s_expm1f.c -- Simple version of s_expm1.c.
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
static char rcsid[] = "$NetBSD: s_expm1f.c,v 1.5f 1995/05/10 20:47:11 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

static const Simple huge = 1.0e+30f;
static const Simple tiny = 1.0e-30f;

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
one		= 1.0f,
o_threshold	= 8.8721679688e+01f,/* 0x42b17180 */
ln2_hi		= 6.9313812256e-01f,/* 0x3f317180 */
ln2_lo		= 9.0580006145e-06f,/* 0x3717f7d1 */
invln2		= 1.4426950216e+00f,/* 0x3fb8aa3b */
	/* scaled coefficients related to expm1 */
Q1  =  -3.3333335072e-02f, /* 0xbd088889 */
Q2  =   1.5873016091e-03f, /* 0x3ad00d01 */
Q3  =  -7.9365076090e-05f, /* 0xb8a670cd */
Q4  =   4.0082177293e-06f, /* 0x36867e54 */
Q5  =  -2.0109921195e-07f; /* 0xb457edbb */

#ifdef __STDC__
	Simple __expm1f(Simple x)
#else
	Simple __expm1f(x)
	Simple x;
#endif
{
    //stub method
}
weak_alias (__expm1f, expm1f)
}
