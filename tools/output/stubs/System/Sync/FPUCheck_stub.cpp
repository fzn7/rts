#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifdef USE_VALGRIND
	#include <valgrind/valgrind.h>
#endif

#include "FPUCheck.h"
#include "lib/streflop/streflop_cond.h"
#include "System/Exceptions.h"
#include "System/ThreadPool.h"
#include "System/Log/ILog.h"
#include "System/Platform/CpuID.h"

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
Spring3:     0  0  0  1  1  0  0  1  0|   0   0  0  0  0  0  0 = 0x1900 = 6400  (signan)
Default:     0  0  0  1  1  1  1  1  1|   0   0  0  0  0  0  0 = 0x1F80 = 8064
MaskRsvd:    1  1  1  1  1  1  1  1  1|   0   0  0  0  0  0  0 = 0xFF80

And the layout of the 387 FPU control word register:
           Rsvd:Rsvd:Rsvd:X:RC:RC:PC:PC: Rsvd:Rsvd:PM:UM:OM:ZM:DM:IM
            15   14   13 12 11 10  9  8|   7    6   5  4  3  2  1  0
Spring1:     0    0    0  0  0  0  0  0|   0    0   1  1  1  0  1  0 = 0x003A = 58
Spring2:     0    0    0  0  0  0  0  0|   0    0   1  1  1  1  1  1 = 0x003F = 63
Spring3:     0    0    0  0  0  0  0  0|   0    0   1  1  0  0  1  0 = 0x0032 = 50   (signan)
Default:     0    0    0  0  0  0  1  1|   0    0   1  1  1  1  1  1 = 0x033F = 831
MaskRsvd:    0    0    0  1  1  1  1  1|   0    0   1  1  1  1  1  1 = 0x1F3F

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

		Spring1  - Control word used by spring in code in CGame::SimFrame().
		Spring2  - Control word used by spring in code everywhere else.
		Default  - Default control word according to Intel.
		MaskRsvd - Masks out the reserved bits.

	Source: Intel Architecture Software Development Manual, Volume 1, Basic Architecture
*/
void good_fpu_control_registers(const char* text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void good_fpu_init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

namespace springproc {
	unsigned int GetProcMaxStandardLevel()
	{
		unsigned int rEAX = 0x00000000;
		unsigned int rEBX =          0;
		unsigned int rECX =          0;
		unsigned int rEDX =          0;

		ExecCPUID(&rEAX, &rEBX, &rECX, &rEDX);

		return rEAX;
	}

	unsigned int GetProcMaxExtendedLevel()
	{
		unsigned int rEAX = 0x80000000;
		unsigned int rEBX =          0;
		unsigned int rECX =          0;
		unsigned int rEDX =          0;

		ExecCPUID(&rEAX, &rEBX, &rECX, &rEDX);

		return rEAX;
	}

	unsigned int GetProcSSEBits()
	{
		unsigned int rEAX = 0;
		unsigned int rEBX = 0;
		unsigned int rECX = 0;
		unsigned int rEDX = 0;
		unsigned int bits = 0;

		if (GetProcMaxStandardLevel() >= 0x00000001U) {
			rEAX = 0x00000001U; ExecCPUID(&rEAX, &rEBX, &rECX, &rEDX);

			int SSE42  = (rECX >> 20) & 1; bits |= ( SSE42 << 0); // SSE 4.2
			int SSE41  = (rECX >> 19) & 1; bits |= ( SSE41 << 1); // SSE 4.1
			int SSSE30 = (rECX >>  9) & 1; bits |= (SSSE30 << 2); // Supplemental SSE 3.0
			int SSE30  = (rECX >>  0) & 1; bits |= ( SSE30 << 3); // SSE 3.0

			int SSE20  = (rEDX >> 26) & 1; bits |= ( SSE20 << 4); // SSE 2.0
			int SSE10  = (rEDX >> 25) & 1; bits |= ( SSE10 << 5); // SSE 1.0
			int MMX    = (rEDX >> 23) & 1; bits |= ( MMX   << 6); // MMX
		}

		if (GetProcMaxExtendedLevel() >= 0x80000001U) {
			rEAX = 0x80000001U; ExecCPUID(&rEAX, &rEBX, &rECX, &rEDX);

			int SSE50A = (rECX >> 11) & 1; bits |= (SSE50A << 7); // SSE 5.0A
			int SSE40A = (rECX >>  6) & 1; bits |= (SSE40A << 8); // SSE 4.0A
			int MSSE   = (rECX >>  7) & 1; bits |= (MSSE   << 9); // Misaligned SSE
		}

		return bits;
	}
}
