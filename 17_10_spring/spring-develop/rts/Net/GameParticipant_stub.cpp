#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameParticipant.h"

#include "Net/Protocol/BaseNetProtocol.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Misc/SpringTime.h"
#include "System/Net/Connection.h"

GameParticipant::GameParticipant()
  : id(-1)
  , myState(UNCONNECTED)
  , lastFrameResponse(0)
  , speedControl(0)
  , isLocal(false)
  , isReconn(false)
  , isMidgameJoin(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GameParticipant::SendData(boost::shared_ptr<const netcode::RawPacket> packet)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GameParticipant::Connected(boost::shared_ptr<netcode::CConnection> _link,
                           bool local)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GameParticipant::Kill(const std::string& reason, const bool flush)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
