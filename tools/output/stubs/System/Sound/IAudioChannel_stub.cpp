#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IAudioChannel.h"

IAudioChannel::IAudioChannel()
	: volume(1.0f)
	, enabled(true)
	, emmitsPerFrame(1000)
	, emmitsThisFrame(0)
	, maxConcurrentSources(1024)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IAudioChannel::~IAudioChannel()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
