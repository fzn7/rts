/*
    streflop: STandalone REproducible FLOating-Point
    Nicolas Brodu, 2006
    Code released according to the GNU Lesser General Public License

    Heavily relies on GNU Libm, itself depending on netlib fplibm, GNU MP, and
   IBM MP lib. Uses SoftFloat too.

    Please read the history and copyright information in the documentation
   provided with the source code
*/

// Include time(0) function to get a seed based on system time
#include "streflop.h"
#include <iostream>
#include <time.h>

// Include endian-specific code
#undef __BYTE_ORDER
#undef __FLOAT_WORD_ORDER
#include "System.h"

namespace streflop {

//////////////////////////////////////////////////////////////////////
// Code stolen and adapted from mt19937ar.c
//////////////////////////////////////////////////////////////////////

/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using init_genrand(seed)
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.
   Copyright (C) 2005, Mutsuo Saito,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER
   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove space)
*/

#if STREFLOP_RANDOM_GEN_SIZE == 32

/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

/* initializes mt[N] with a seed */
inline void init_genrand(SizedUnsignedInteger<32>::Type s, RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* generates a random number on [0,0xffffffff]-interval */
inline SizedUnsignedInteger<32>::Type
genrand_int(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#else

//////////////////////////////////////////////////////////////////////
// End of code adapted from mt19937ar.c
// Now adapt code from the 64-bit version in mt19937-64.c
//////////////////////////////////////////////////////////////////////

/*
   A C-program for MT19937-64 (2004/9/29 version).
   Coded by Takuji Nishimura and Makoto Matsumoto.

   This is a 64-bit version of Mersenne Twister pseudorandom number
   generator.

   Before using, initialize the state by using init_genrand64(seed)
   or init_by_array64(init_key, key_length).

   Copyright (C) 2004, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER
   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   References:
   T. Nishimura, ``Tables of 64-bit Mersenne Twisters''
     ACM Transactions on Modeling and
     Computer Simulation 10. (2000) 348--357.
   M. Matsumoto and T. Nishimura,
     ``Mersenne Twister: a 623-dimensionally equidistributed
       uniform pseudorandom number generator''
     ACM Transactions on Modeling and
     Computer Simulation 8. (Jan. 1998) 3--30.

   Any feedback is very welcome.
   http://www.math.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove spaces)
*/

#define NN 312
#define MM 156
#define MATRIX_A 0xB5026F5AA96619E9ULL
#define UM 0xFFFFFFFF80000000ULL /* Most significant 33 bits */
#define LM 0x7FFFFFFFULL         /* Least significant 31 bits */

/* initializes mt[NN] with a seed */
inline void init_genrand(SizedUnsignedInteger<64>::Type seed,
                         RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* generates a random number on [0, 2^64-1]-interval */
inline SizedUnsignedInteger<64>::Type
genrand_int(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

//////////////////////////////////////////////////////////////////////
// End of code adapted from mt19937-64.c
//////////////////////////////////////////////////////////////////////

// Bit getter utilities
template<int nbits>
struct Accessor
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
SPECIALIZE_RANDOM_FOR_SIMPLE_ULP(E,I)
SPECIALIZE_RANDOM_FOR_SIMPLE_ULP(E,E)
SPECIALIZE_RANDOM_FOR_SIMPLE_ULP(I,E)
SPECIALIZE_RANDOM_FOR_SIMPLE_ULP(I,I)
*/

// Return a random float
template<>
Simple
Random<Simple>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in 1..2 - ideal IE case
template<>
Simple
Random12<true, false, Simple>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in 1..2 - near ideal EI case
template<>
Simple
Random12<false, true, Simple>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in 1..2 - need to include both bounds
template<>
Simple
Random12<true, true, Simple>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in 1..2 - need to exclude both bounds
template<>
Simple
Random12<false, false, Simple>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////// Double versions  ///////////

// Return a random float
template<>
Double
Random<Double>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in a 1..2 - ideal IE case
template<>
Double
Random12<true, false, Double>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in a 1..2 - near ideal EI case
template<>
Double
Random12<false, true, Double>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in a 1..2 - need to include both bounds
template<>
Double
Random12<true, true, Double>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in a 1..2 - need to exclude both bounds
template<>
Double
Random12<false, false, Double>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef Extended

// little endian
#if __FLOAT_WORD_ORDER == 1234

/// Little endian is fine, always the same offsets whatever the memory model
template<int Nbytes>
struct ExtendedConverter
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// Extended is softfloat
template<>
struct ExtendedConverter<10>
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in 1..2 - ideal IE case
template<>
Extended
Random12<true, false, Extended>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in 1..2 - near ideal EI case
template<>
Extended
Random12<false, true, Extended>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in 1..2 - need to include both bounds
template<>
Extended
Random12<true, true, Extended>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Random in 1..2 - need to exclude both bounds
template<>
Extended
Random12<false, false, Extended>(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif

// This is a way to hide the implementation from the header
// And also to ensure there is only one template instanciation, instead of
// duplicating the code in all object files
template<typename FloatType>
static inline FloatType
NRandom_Generic(FloatType* secondary, RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Specialize for the Float types declared in the header
template<>
Simple
NRandom(Simple* secondary, RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
template<> Double NRandom(Double *secondary, RandomState& state) {
    return NRandom_Generic<Double>(secondary,state);
}
#if defined(Extended)
template<> Extended NRandom(Extended *secondary, RandomState& state) {
    return NRandom_Generic<Extended>(secondary,state);
}
#endif
*/

// May save one mul
template<typename FloatType>
static inline FloatType
NRandom_Generic(FloatType mean,
                FloatType std_dev,
                FloatType* secondary,
                RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Specialize for the Float types declared in the header
template<>
Simple
NRandom(Simple mean, Simple std_dev, Simple* secondary, RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
template<> Double NRandom(Double mean, Double std_dev, Double *secondary,
RandomState& state) { return NRandom_Generic<Double>(mean, std_dev,
secondary,state);
}
#if defined(Extended)
template<> Extended NRandom(Extended mean, Extended std_dev, Extended
*secondary, RandomState& state) { return NRandom_Generic<Extended>(mean,
std_dev, secondary,state);
}
#endif
*/

SizedUnsignedInteger<32>::Type
RandomInit(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SizedUnsignedInteger<32>::Type RandomInit(SizedUnsignedInteger<32>::Type seed,
                                          RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SizedUnsignedInteger<32>::Type
RandomSeed(RandomState& state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Default state holder, so single threaded applications don't bother setting up
// an object
RandomState DefaultRandomState;

} // end streflop namespace
