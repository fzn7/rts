#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifdef USE_VALGRIND
#include <valgrind/valgrind.h>
#endif

#include "FPUCheck.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Platform/CpuID.h"
#include "System/ThreadPool.h"
#include "lib/streflop/streflop_cond.h"

#ifdef STREFLOP_H
#ifdef STREFLOP_SSE
#elif STREFLOP_X87
#else
#error "streflop FP-math mode must be either SSE or X87"
#endif
#endif

/**
        @brief checks FPU control registers.
        Checks the FPU control registers MXCSR and FPUCW,

For reference, the layout of the MXCSR register:
            FZ:RC:RC:PM:UM:OM:ZM:DM:IM: Rsvd:PE:UE:OE:ZE:DE:IE
            15 14 13 12 11 10  9  8  7|   6   5  4  3  2  1  0
Spring1:     0  0  0  1  1  1  0  1  0|   0   0  0  0  0  0  0 = 0x1D00 = 7424
Spring2:     0  0  0  1  1  1  1  1  1|   0   0  0  0  0  0  0 = 0x1F80 = 8064
Spring3:     0  0  0  1  1  0  0  1  0|   0   0  0  0  0  0  0 = 0x1900 = 6400
(signan) Default:     0  0  0  1  1  1  1  1  1|   0   0  0  0  0  0  0 = 0x1F80
= 8064 MaskRsvd:    1  1  1  1  1  1  1  1  1|   0   0  0  0  0  0  0 = 0xFF80

And the layout of the 387 FPU control word register:
           Rsvd:Rsvd:Rsvd:X:RC:RC:PC:PC: Rsvd:Rsvd:PM:UM:OM:ZM:DM:IM
            15   14   13 12 11 10  9  8|   7    6   5  4  3  2  1  0
Spring1:     0    0    0  0  0  0  0  0|   0    0   1  1  1  0  1  0 = 0x003A =
58 Spring2:     0    0    0  0  0  0  0  0|   0    0   1  1  1  1  1  1 = 0x003F
= 63 Spring3:     0    0    0  0  0  0  0  0|   0    0   1  1  0  0  1  0 =
0x0032 = 50   (signan) Default:     0    0    0  0  0  0  1  1|   0    0   1  1
1  1  1  1 = 0x033F = 831 MaskRsvd:    0    0    0  1  1  1  1  1|   0    0   1
1  1  1  1  1 = 0x1F3F

        Where:
                Rsvd - Reserved
                FZ   - Flush to Zero
                RC   - Rounding Control
                PM   - Precision Mask
                UM   - Underflow Mask
                OM   - Overflow Mask
                ZM   - Zerodivide Mask
                DM   - Denormal Mask
                IM   - Invalid Mask
                PE   - Precision Exception
                UE   - Underflow Exception
                OE   - Overflow Exception
                ZE   - Zerodivide Exception
                DE   - Denormal Exception
                IE   - Invalid Exception
                X    - Infinity control (unused on 387 and higher)
                PC   - Precision Control

                Spring1  - Control word used by spring in code in
CGame::SimFrame(). Spring2  - Control word used by spring in code everywhere
else. Default  - Default control word according to Intel. MaskRsvd - Masks out
the reserved bits.

        Source: Intel Architecture Software Development Manual, Volume 1, Basic
Architecture
*/
void
good_fpu_control_registers(const char* text)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
good_fpu_init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

namespace springproc {
unsigned int
GetProcMaxStandardLevel()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
GetProcMaxExtendedLevel()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
GetProcSSEBits()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
