#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <stdexcept>
#include <string.h>

#include "RawPacket.h"

#include "System/Log/ILog.h"

namespace netcode {

RawPacket::RawPacket(const unsigned char* const tdata, const unsigned newLength)
  : length(newLength)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

RawPacket::RawPacket(const unsigned newLength)
  : length(newLength)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

RawPacket::~RawPacket()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

} // namespace netcode
