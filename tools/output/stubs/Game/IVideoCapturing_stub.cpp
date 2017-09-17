#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IVideoCapturing.h"


#if       defined AVI_CAPTURING
#include "AviVideoCapturing.h"
#else  // defined AVI_CAPTURING
#include "DummyVideoCapturing.h"
#endif // defined AVI_CAPTURING

#include <cstdlib> // for NULL

IVideoCapturing* IVideoCapturing::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void IVideoCapturing::FreeInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


IVideoCapturing::IVideoCapturing()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IVideoCapturing::~IVideoCapturing()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void IVideoCapturing::SetCapturing(bool enabled) {

	if (!GetInstance()->IsCapturing() && enabled) {
		GetInstance()->StartCapturing();
	} else if (GetInstance()->IsCapturing() && !enabled) {
		GetInstance()->StopCapturing();
	}
}
