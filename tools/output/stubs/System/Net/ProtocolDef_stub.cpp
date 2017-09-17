/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ProtocolDef.h"

#include <string.h>
#include <boost/format.hpp>

#include "Exception.h"

namespace netcode {

ProtocolDef* ProtocolDef::GetInstance()
{
    //stub method
}

ProtocolDef::ProtocolDef()
{
    //stub method
}

void ProtocolDef::AddType(const unsigned char id, const int msgLength)
{
    //stub method
}

int ProtocolDef::PacketLength(const unsigned char* const buf, const unsigned bufLength) const
{
    //stub method
}

bool ProtocolDef::IsValidLength(const int pktLength, const unsigned bufLength) const
{
    //stub method
}

bool ProtocolDef::IsValidPacket(const unsigned char* const buf, const unsigned bufLength) const
{
    //stub method
}

} // namespace netcode
