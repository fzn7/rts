#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LoopbackConnection.h"

namespace netcode {

CLoopbackConnection::CLoopbackConnection() {}

CLoopbackConnection::~CLoopbackConnection() {}

void
CLoopbackConnection::SendData(boost::shared_ptr<const RawPacket> data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<const RawPacket>
CLoopbackConnection::Peek(unsigned ahead) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLoopbackConnection::DeleteBufferPacketAt(unsigned index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<const RawPacket>
CLoopbackConnection::GetData()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLoopbackConnection::Flush(const bool forced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLoopbackConnection::CanReconnect() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLoopbackConnection::NeedsReconnect()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CLoopbackConnection::Statistics() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CLoopbackConnection::GetFullAddress() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLoopbackConnection::HasIncomingData() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace netcode
