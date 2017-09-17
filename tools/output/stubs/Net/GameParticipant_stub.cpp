/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameParticipant.h"

#include "Net/Protocol/BaseNetProtocol.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Net/Connection.h"
#include "System/Misc/SpringTime.h"

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
}

void GameParticipant::SendData(boost::shared_ptr<const netcode::RawPacket> packet)
{
    //stub method
}

void GameParticipant::Connected(boost::shared_ptr<netcode::CConnection> _link, bool local)
{
    //stub method
}

void GameParticipant::Kill(const std::string& reason, const bool flush)
{
    //stub method
}

