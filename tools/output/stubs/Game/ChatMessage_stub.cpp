#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "ChatMessage.h"

#include "Net/Protocol/BaseNetProtocol.h"
#include "System/Net/PackPacket.h"
#include "System/Net/UnpackPacket.h"
#include <boost/cstdint.hpp>

using namespace netcode;

ChatMessage::ChatMessage(int from, int dest, const std::string& chat)
	: fromPlayer(from)
	, destination(dest)
	, msg(chat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

ChatMessage::ChatMessage(boost::shared_ptr<const netcode::RawPacket> data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const netcode::RawPacket* ChatMessage::Pack() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
