#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <assert.h>


#include "CommandMessage.h"

#include "Net/Protocol/BaseNetProtocol.h"
#include "System/Net/PackPacket.h"
#include "System/Net/UnpackPacket.h"

using namespace netcode;

CommandMessage::CommandMessage(const std::string& cmd, int playerID)
	: action(Action(cmd))
	, playerID(playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CommandMessage::CommandMessage(const Action& action, int playerID)
	: action(action)
	, playerID(playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CommandMessage::CommandMessage(boost::shared_ptr<const netcode::RawPacket> pckt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const netcode::RawPacket* CommandMessage::Pack() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

