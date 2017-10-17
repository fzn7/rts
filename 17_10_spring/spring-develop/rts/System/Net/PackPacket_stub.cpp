#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PackPacket.h"

#include "System/Log/ILog.h"

#include <algorithm>
#include <cstdlib>

namespace netcode {

PackPacket::PackPacket(const unsigned length)
  : RawPacket(length)
  , pos(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

PackPacket&
PackPacket::operator<<(const std::string& text)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
