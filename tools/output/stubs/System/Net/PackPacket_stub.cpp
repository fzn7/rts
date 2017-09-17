#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PackPacket.h"

#include "System/Log/ILog.h"

#include <algorithm>
#include <cstdlib>

namespace netcode
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

PackPacket::PackPacket(const unsigned length, unsigned char msgID)
	: RawPacket(length)
	, pos(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

PackPacket& PackPacket::operator<<(const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

}

