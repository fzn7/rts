/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BaseNetProtocol.h"

#include "Game/Players/PlayerStatistics.h"
#include "Sim/Misc/TeamStatistics.h"
#include "System/Net/RawPacket.h"
#include "System/Net/PackPacket.h"
#include "System/Net/ProtocolDef.h"
#include <boost/cstdint.hpp>

using netcode::PackPacket;
typedef boost::shared_ptr<const netcode::RawPacket> PacketType;

CBaseNetProtocol& CBaseNetProtocol::Get()
{
    //stub method
}

PacketType CBaseNetProtocol::SendKeyFrame(int frameNum)
{
    //stub method
}

PacketType CBaseNetProtocol::SendNewFrame()
{
    //stub method
}


PacketType CBaseNetProtocol::SendQuit(const std::string& reason)
{
    //stub method
}

PacketType CBaseNetProtocol::SendStartPlaying(unsigned countdown)
{
    //stub method
}

PacketType CBaseNetProtocol::SendSetPlayerNum(uchar myPlayerNum)
{
    //stub method
}

PacketType CBaseNetProtocol::SendPlayerName(uchar myPlayerNum, const std::string& playerName)
{
    //stub method
}

PacketType CBaseNetProtocol::SendRandSeed(unsigned randSeed)
{
    //stub method
}

// NETMSG_GAMEID = 9, char gameID[16];
PacketType CBaseNetProtocol::SendGameID(const uchar* buf)
{
    //stub method
}

PacketType CBaseNetProtocol::SendPathCheckSum(uchar myPlayerNum, boost::uint32_t checksum)
{
    //stub method
}


PacketType CBaseNetProtocol::SendCommand(uchar myPlayerNum, int id, uchar options, const std::vector<float>& params)
{
    //stub method
}

PacketType CBaseNetProtocol::SendSelect(uchar myPlayerNum, const std::vector<short>& selectedUnitIDs)
{
    //stub method
}


PacketType CBaseNetProtocol::SendPause(uchar myPlayerNum, uchar bPaused)
{
    //stub method
}



PacketType CBaseNetProtocol::SendAICommand(uchar myPlayerNum, unsigned char aiID, short unitID, int id, int aiCommandId, uchar options, const std::vector<float>& params)
{
    //stub method
}

PacketType CBaseNetProtocol::SendAIShare(uchar myPlayerNum, unsigned char aiID, uchar sourceTeam, uchar destTeam, float metal, float energy, const std::vector<short>& unitIDs)
{
    //stub method
}

PacketType CBaseNetProtocol::SendUserSpeed(uchar myPlayerNum, float userSpeed)
{
    //stub method
}

PacketType CBaseNetProtocol::SendInternalSpeed(float internalSpeed)
{
    //stub method
}

PacketType CBaseNetProtocol::SendCPUUsage(float cpuUsage)
{
    //stub method
}

PacketType CBaseNetProtocol::SendDirectControl(uchar myPlayerNum)
{
    //stub method
}

PacketType CBaseNetProtocol::SendDirectControlUpdate(uchar myPlayerNum, uchar status, short heading, short pitch)
{
    //stub method
}


PacketType CBaseNetProtocol::SendAttemptConnect(const std::string& name, const std::string& passwd, const std::string& version, int netloss, bool reconnect)
{
    //stub method
}


PacketType CBaseNetProtocol::SendRejectConnect(const std::string& reason)
{
    //stub method
}


PacketType CBaseNetProtocol::SendShare(uchar myPlayerNum, uchar shareTeam, uchar bShareUnits, float shareMetal, float shareEnergy)
{
    //stub method
}

PacketType CBaseNetProtocol::SendSetShare(uchar myPlayerNum, uchar myTeam, float metalShareFraction, float energyShareFraction)
{
    //stub method
}


PacketType CBaseNetProtocol::SendPlayerStat(uchar myPlayerNum, const PlayerStatistics& currentStats)
{
    //stub method
}

PacketType CBaseNetProtocol::SendTeamStat(uchar teamNum, const TeamStatistics& currentStats)
{
    //stub method
}



PacketType CBaseNetProtocol::SendGameOver(uchar myPlayerNum, const std::vector<uchar>& winningAllyTeams)
{
    //stub method
}


// [NETMSG_MAPDRAW = 31] uchar messageSize = 9, myPlayerNum, command = MAPDRAW_ERASE; short x, z; bool
PacketType CBaseNetProtocol::SendMapErase(uchar myPlayerNum, short x, short z)
{
    //stub method
}

// [NETMSG_MAPDRAW = 31] uchar messageSize, uchar myPlayerNum, command = MAPDRAW_POINT; short x, z; bool; std::string label;
PacketType CBaseNetProtocol::SendMapDrawPoint(uchar myPlayerNum, short x, short z, const std::string& label, bool fromLua)
{
    //stub method
}

// [NETMSG_MAPDRAW = 31] uchar messageSize = 13, myPlayerNum, command = MAPDRAW_LINE; short x1, z1, x2, z2; bool
PacketType CBaseNetProtocol::SendMapDrawLine(uchar myPlayerNum, short x1, short z1, short x2, short z2, bool fromLua)
{
    //stub method
}


PacketType CBaseNetProtocol::SendSyncResponse(uchar myPlayerNum, int frameNum, uint checksum)
{
    //stub method
}

PacketType CBaseNetProtocol::SendSystemMessage(uchar myPlayerNum, std::string message)
{
    //stub method
}

PacketType CBaseNetProtocol::SendStartPos(uchar myPlayerNum, uchar teamNum, uchar readyState, float x, float y, float z)
{
    //stub method
}

PacketType CBaseNetProtocol::SendPlayerInfo(uchar myPlayerNum, float cpuUsage, int ping)
{
    //stub method
}

PacketType CBaseNetProtocol::SendPlayerLeft(uchar myPlayerNum, uchar bIntended)
{
    //stub method
}

// NETMSG_LUAMSG = 50, uchar myPlayerNum; std::string modName; (e.g. `custom msg')
PacketType CBaseNetProtocol::SendLuaMsg(uchar myPlayerNum, unsigned short script, uchar mode, const std::vector<boost::uint8_t>& msg)
{
    //stub method
}

PacketType CBaseNetProtocol::SendGiveAwayEverything(uchar myPlayerNum, uchar giveToTeam, uchar takeFromTeam)
{
    //stub method
}

PacketType CBaseNetProtocol::SendResign(uchar myPlayerNum)
{
    //stub method
}

PacketType CBaseNetProtocol::SendJoinTeam(uchar myPlayerNum, uchar wantedTeamNum)
{
    //stub method
}

PacketType CBaseNetProtocol::SendTeamDied(uchar myPlayerNum, uchar whichTeam)
{
    //stub method
}

PacketType CBaseNetProtocol::SendAICreated(const uchar myPlayerNum,
                                           const uchar whichSkirmishAI,
                                           const uchar team,
                                           const std::string& name)
{
    //stub method
}

PacketType CBaseNetProtocol::SendAIStateChanged(const uchar myPlayerNum,
                                                const uchar whichSkirmishAI,
                                                const uchar newState)
{
    //stub method
}

PacketType CBaseNetProtocol::SendSetAllied(uchar myPlayerNum, uchar whichAllyTeam, uchar state)
{
    //stub method
}


PacketType CBaseNetProtocol::SendCreateNewPlayer( uchar playerNum, bool spectator, uchar teamNum, std::string playerName )
{
    //stub method
}

PacketType CBaseNetProtocol::SendCurrentFrameProgress(int frameNum)
{
    //stub method
}



#ifdef SYNCDEBUG
PacketType CBaseNetProtocol::SendSdCheckrequest(int frameNum)
{
    //stub method
}

PacketType CBaseNetProtocol::SendSdCheckresponse(uchar myPlayerNum, boost::uint64_t flop, std::vector<unsigned> checksums)
{
    //stub method
}

PacketType CBaseNetProtocol::SendSdReset()
{
    //stub method
}

PacketType CBaseNetProtocol::SendSdBlockrequest(unsigned short begin, unsigned short length, unsigned short requestSize)
{
    //stub method
}


PacketType CBaseNetProtocol::SendSdBlockresponse(uchar myPlayerNum, std::vector<unsigned> checksums)
{
    //stub method
}
#endif // SYNCDEBUG


CBaseNetProtocol::CBaseNetProtocol()
{
    //stub method
}

