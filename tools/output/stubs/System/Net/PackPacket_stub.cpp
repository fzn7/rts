/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PackPacket.h"

#include "System/Log/ILog.h"

#include <algorithm>
#include <cstdlib>

namespace netcode
{
    //stub method
}

PackPacket::PackPacket(const unsigned length, unsigned char msgID)
	: RawPacket(length)
	, pos(0)
{
    //stub method
}

PackPacket& PackPacket::operator<<(const std::string& text)
{
    //stub method
}

}

