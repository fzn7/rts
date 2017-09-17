#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string.h>
#include <stdexcept>

#include "RawPacket.h"

#include "System/Log/ILog.h"

namespace netcode
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

RawPacket::RawPacket(const unsigned newLength)
	: length(newLength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

RawPacket::~RawPacket()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace netcode
