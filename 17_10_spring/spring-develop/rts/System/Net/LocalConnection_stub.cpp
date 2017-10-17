#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/format.hpp>

#include "Exception.h"
#include "LocalConnection.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "ProtocolDef.h"
#include "System/Log/ILog.h"

namespace netcode {

// static stuff
unsigned CLocalConnection::instances = 0;

std::deque<boost::shared_ptr<const RawPacket>> CLocalConnection::pqueues[2];
boost::mutex CLocalConnection::mutexes[2];

CLocalConnection::CLocalConnection()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CLocalConnection::~CLocalConnection()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLocalConnection::Close(bool flush)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLocalConnection::SendData(boost::shared_ptr<const RawPacket> packet)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

boost::shared_ptr<const RawPacket>
CLocalConnection::GetData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

boost::shared_ptr<const RawPacket>
CLocalConnection::Peek(unsigned ahead) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLocalConnection::DeleteBufferPacketAt(unsigned index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CLocalConnection::Statistics() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CLocalConnection::GetFullAddress() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CLocalConnection::HasIncomingData() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CLocalConnection::GetPacketQueueSize() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

} // namespace netcode
