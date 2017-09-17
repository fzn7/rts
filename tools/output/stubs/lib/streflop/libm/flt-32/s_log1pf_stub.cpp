/* See the import.pl script for potential modifications */
/* s_log1pf.c -- Simple version of s_log1p.c.
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
static char rcsid[] = "$NetBSD: s_log1pf.c,v 1.4f 1995/05/10 20:47:48 jtc Exp $";
#endif

#include "SMath.h"
#include "math_private.h"

namespace streflop_libm {
#ifdef __STDC__
static const Simple
#else
static Simple
#endif
ln2_hi =   6.9313812256e-01f,	/* 0x3f317180 */
ln2_lo =   9.0580006145e-06f,	/* 0x3717f7d1 */
two25 =    3.355443200e+07f,	/* 0x4c000000 */
Lp1 = 6.6666668653e-01f,	/* 3F2AAAAB */
Lp2 = 4.0000000596e-01f,	/* 3ECCCCCD */
Lp3 = 2.8571429849e-01f, /* 3E924925 */
Lp4 = 2.2222198546e-01f, /* 3E638E29 */
Lp5 = 1.8183572590e-01f, /* 3E3A3325 */
Lp6 = 1.5313838422e-01f, /* 3E1CD04F */
Lp7 = 1.4798198640e-01f; /* 3E178897 */

#ifdef __STDC__
static const Simple zero = 0.0f;
#else
static Simple zero = 0.0f;
#endif

#ifdef __STDC__
	Simple __log1pf(Simple x)
#else
	Simple __log1pf(x)
	Simple x;
#endif
{
    //stub method
}
weak_alias (__log1pf, log1pf)
}
