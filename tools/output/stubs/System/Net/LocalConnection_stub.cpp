/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/format.hpp>

#include "LocalConnection.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "Exception.h"
#include "ProtocolDef.h"
#include "System/Log/ILog.h"

namespace netcode {

// static stuff
unsigned CLocalConnection::instances = 0;

std::deque< boost::shared_ptr<const RawPacket> > CLocalConnection::pqueues[2];
boost::mutex CLocalConnection::mutexes[2];

CLocalConnection::CLocalConnection()
{
    //stub method
}

CLocalConnection::~CLocalConnection()
{
    //stub method
}

void CLocalConnection::Close(bool flush)
{
    //stub method
}

void CLocalConnection::SendData(boost::shared_ptr<const RawPacket> packet)
{
    //stub method
}

boost::shared_ptr<const RawPacket> CLocalConnection::GetData()
{
    //stub method
}

boost::shared_ptr<const RawPacket> CLocalConnection::Peek(unsigned ahead) const
{
    //stub method
}

void CLocalConnection::DeleteBufferPacketAt(unsigned index)
{
    //stub method
}


std::string CLocalConnection::Statistics() const
{
    //stub method
}

std::string CLocalConnection::GetFullAddress() const
{
    //stub method
}


bool CLocalConnection::HasIncomingData() const
{
    //stub method
}

unsigned int CLocalConnection::GetPacketQueueSize() const
{
    //stub method
}

} // namespace netcode

