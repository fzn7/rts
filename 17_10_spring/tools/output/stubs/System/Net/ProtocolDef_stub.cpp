#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ProtocolDef.h"

#include <boost/format.hpp>
#include <string.h>

#include "Exception.h"

namespace netcode {

ProtocolDef*
ProtocolDef::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

ProtocolDef::ProtocolDef()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ProtocolDef::AddType(const unsigned char id, const int msgLength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
ProtocolDef::PacketLength(const unsigned char* const buf,
                          const unsigned bufLength) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ProtocolDef::IsValidLength(const int pktLength, const unsigned bufLength) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ProtocolDef::IsValidPacket(const unsigned char* const buf,
                           const unsigned bufLength) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace netcode
