#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Socket.h"

#include <boost/system/error_code.hpp>
#include "lib/streflop/streflop_cond.h"

#include "System/Log/ILog.h"
#include "System/Util.h"


namespace netcode
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::asio::ip::udp::endpoint ResolveAddr(const std::string& host, int port, boost::system::error_code* err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


boost::asio::ip::address WrapIP(const std::string& ip,
		boost::system::error_code* err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::asio::ip::udp::resolver::iterator WrapResolve(
		boost::asio::ip::udp::resolver& resolver,
		boost::asio::ip::udp::resolver::query& query,
		boost::system::error_code* err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


boost::asio::ip::address GetAnyAddress(const bool IPv6)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


} // namespace netcode

