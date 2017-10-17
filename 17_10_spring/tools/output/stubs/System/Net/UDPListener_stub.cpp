#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UDPListener.h"

#ifdef DEBUG
#include <boost/format.hpp>
#endif
#include <boost/asio.hpp>
#include <boost/cstdint.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <list>
#include <queue>

#include "ProtocolDef.h"
#include "Socket.h"
#include "System/Log/ILog.h"
#include "System/Platform/errorhandler.h"
#include "System/Util.h" // for IntToString (header only)
#include "UDPConnection.h"

namespace netcode {
using namespace boost::asio;

UDPListener::UDPListener(int port, const std::string& ip)
  : acceptNewConnections(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
UDPListener::TryBindSocket(int port, SocketPtr* socket, const std::string& ip)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UDPListener::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<UDPConnection>
UDPListener::SpawnConnection(const std::string& ip, const unsigned port)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UDPListener::SetAcceptingConnections(const bool enable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
UDPListener::IsAcceptingConnections() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
UDPListener::HasIncomingConnections() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::weak_ptr<UDPConnection>
UDPListener::PreviewConnection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<UDPConnection>
UDPListener::AcceptConnection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UDPListener::RejectConnection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UDPListener::UpdateConnections()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
