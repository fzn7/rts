/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Net/UDPListener.h"
#include "System/Net/UDPConnection.h"

#include <boost/bind.hpp>
#include <boost/format.hpp>
#include <boost/version.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <deque>
#if defined DEDICATED || defined DEBUG
	#include <iostream>
#endif

#include "GameServer.h"

#include "GameParticipant.h"
#include "GameSkirmishAI.h"
#include "AutohostInterface.h"

#include "Game/ClientSetup.h"
#include "Game/GameSetup.h"

#include "Game/Action.h"
#include "Game/ChatMessage.h"
#include "Game/CommandMessage.h"
#include "Game/GlobalUnsynced.h" // for syncdebug
#include "Game/IVideoCapturing.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"

#include "Net/Protocol/BaseNetProtocol.h"
#include "Sim/Misc/GlobalConstants.h"

// This undef is needed, as somewhere there is a type interface specified,
// which we need not!
// (would cause problems in ExternalAI/Interface/SAIInterfaceLibrary.h)
#ifdef interface
	#undef interface
#endif
#include "System/CRC.h"
#include "System/GlobalConfig.h"
#include "System/MsgStrings.h"
#include "System/myMath.h"
#include "System/Util.h"
#include "System/TdfParser.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Net/Connection.h"
#include "System/Net/LocalConnection.h"
#include "System/Net/UnpackPacket.h"
#include "System/LoadSave/DemoRecorder.h"
#include "System/LoadSave/DemoReader.h"
#include "System/Log/ILog.h"
#include "System/Platform/errorhandler.h"
#include "System/Platform/Threading.h"

#ifndef DEDICATED
#include "lib/luasocket/src/restrictions.h"
#endif

#define ALLOW_DEMO_GODMODE
#define PKTCACHE_VECSIZE 1000

using netcode::RawPacket;
using boost::format;


CONFIG(int, AutohostPort).defaultValue(0);
CONFIG(int, ServerSleepTime).defaultValue(5).description("number of milliseconds to sleep per tick");
CONFIG(int, SpeedControl).defaultValue(1).minimumValue(1).maximumValue(2)
	.description("Sets how server adjusts speed according to player's load (CPU), 1: use average, 2: use highest");
CONFIG(bool, AllowSpectatorJoin).defaultValue(true).description("allow any unauthenticated clients to join as spectator with any name, name will be prefixed with ~");
CONFIG(bool, WhiteListAdditionalPlayers).defaultValue(true);
CONFIG(bool, ServerRecordDemos).defaultValue(false).dedicatedValue(true);
CONFIG(bool, ServerLogInfoMessages).defaultValue(false);
CONFIG(bool, ServerLogDebugMessages).defaultValue(false);
CONFIG(std::string, AutohostIP).defaultValue("127.0.0.1");


// use the specific section for all LOG*() calls in this source file
#define LOG_SECTION_GAMESERVER "GameServer"
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_GAMESERVER

LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_GAMESERVER)



/// frames until a synccheck will time out and a warning is given out
static const unsigned SYNCCHECK_TIMEOUT = 300;

/// used to prevent msg spam
static const unsigned SYNCCHECK_MSG_TIMEOUT = 400;

/// The time interval in msec for sending player statistics to each client
static const spring_time playerInfoTime = spring_secs(2);

/// every n'th frame will be a keyframe (and contain the server's framenumber)
static const unsigned serverKeyframeInterval = 16;

/// players incoming bandwidth new allowance every X milliseconds
static const unsigned playerBandwidthInterval = 100;

/// every 10 sec we'll broadcast current frame in a message that skips queue & cache
/// to let clients that are fast-forwarding to current point to know their loading %
static const unsigned gameProgressFrameInterval = GAME_SPEED * 10;

static const unsigned syncResponseEchoInterval = GAME_SPEED * 2;


//FIXME remodularize server commands, so they get registered in word completion etc.
static const std::string SERVER_COMMANDS[] = {
	"kick", "kickbynum",
	"mute", "mutebynum",
	"setminspeed", "setmaxspeed",
	"nopause", "nohelp", "cheat", "godmode", "globallos",
	"nocost", "forcestart", "nospectatorchat", "nospecdraw",
	"skip", "reloadcob", "reloadcegs", "devlua", "editdefs",
	"singlestep", "spec", "specbynum"
};


std::set<std::string> CGameServer::commandBlacklist;



CGameServer* gameServer = NULL;

CGameServer::CGameServer(
	const boost::shared_ptr<const ClientSetup> newClientSetup,
	const boost::shared_ptr<const    GameData> newGameData,
	const boost::shared_ptr<const  CGameSetup> newGameSetup
)
: quitServer(false)
, serverFrameNum(-1)

, serverStartTime(spring_gettime())
, readyTime(spring_notime)
, gameEndTime(spring_notime)
, lastPlayerInfo(serverStartTime)
, lastUpdate(serverStartTime)

, modGameTime(0.0f)
, gameTime(0.0f)
, startTime(0.0f)
, frameTimeLeft(0.0f)

, isPaused(false)
, gamePausable(true)

, userSpeedFactor(1.0f)
, internalSpeed(1.0f)

, medianCpu(0.0f)
, medianPing(0)

, cheating(false)
, noHelperAIs(false)
, canReconnect(false)
, allowSpecDraw(true)

, syncErrorFrame(0)
, syncWarningFrame(0)

, localClientNumber(-1u)

, gameHasStarted(false)
, generatedGameID(false)
, reloadingServer(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameServer::~CGameServer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::Initialize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::PostLoad(int newServerFrameNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::Reload(const boost::shared_ptr<const CGameSetup> newGameSetup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::WriteDemoData()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::StripGameSetupText(const GameData* newGameData)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::AddLocalClient(const std::string& myName, const std::string& myVersion)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::AddAutohostInterface(const std::string& autohostIP, const int autohostPort)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::SkipTo(int targetFrameNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CGameServer::GetPlayerNames(const std::vector<int>& indices) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CGameServer::SendDemoData(int targetFrameNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::Broadcast(boost::shared_ptr<const netcode::RawPacket> packet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::Message(const std::string& message, bool broadcast)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::PrivateMessage(int playerNum, const std::string& message) {
	players[playerNum].SendData(CBaseNetProtocol::Get().SendSystemMessage(SERVER_PLAYER, message));
}

void CGameServer::CheckSync()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CGameServer::GetDemoTime() const {
	if (!gameHasStarted) return gameTime;
	return (startTime + serverFrameNum / float(GAME_SPEED));
}


void CGameServer::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CGameServer::LagProtection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/// has to be consistent with Game.cpp/CPlayerHandler
static std::vector<int> getPlayersInTeam(const std::vector<GameParticipant>& players, const int teamId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Duplicates functionality of CPlayerHandler::ActivePlayersInTeam(int teamId)
 * as playerHandler is not available on the server
 */
static int countNumPlayersInTeam(const std::vector<GameParticipant>& players, const int teamId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// has to be consistent with Game.cpp/CSkirmishAIHandler
static std::vector<unsigned char> getSkirmishAIIds(const std::map<unsigned char, GameSkirmishAI>& ais, const int teamId, const int hostPlayer = -2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Duplicates functionality of CSkirmishAIHandler::GetSkirmishAIsInTeam(const int teamId)
 * as skirmishAIHandler is not available on the server
 */
static int countNumSkirmishAIsInTeam(const std::map<unsigned char, GameSkirmishAI>& ais, const int teamId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::ProcessPacket(const unsigned playerNum, boost::shared_ptr<const netcode::RawPacket> packet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::HandleConnectionAttempts()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::ServerReadNet()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::GenerateAndSendGameID()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::CheckForGameStart(bool forced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::StartGame(bool forced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::SetGamePausable(const bool arg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::PushAction(const Action& action, bool fromAutoHost)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CGameServer::HasFinished() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGameServer::CreateNewFrame(bool fromServerThread, bool fixedFrameTime)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::UpdateSpeedControl(int speedCtrl)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CGameServer::SpeedControlToString(int speedCtrl)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


__FORCE_ALIGN_STACK__
void CGameServer::UpdateLoop()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::KickPlayer(const int playerNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::MutePlayer(const int playerNum, bool muteChat, bool muteDraw)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::SpecPlayer(const int player)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::ResignPlayer(const int player)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CGameServer::CheckPlayersPassword(const int playerNum, const std::string& pw) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::AddAdditionalUser(const std::string& name, const std::string& passwd, bool fromDemo, bool spectator, int team, int playerNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned CGameServer::BindConnection(std::string name, const std::string& passwd, const std::string& version, bool isLocal, boost::shared_ptr<netcode::CConnection> link, bool reconnect, int netloss)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::GotChatMessage(const ChatMessage& msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::InternalSpeedChange(float newSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::UserSpeedChange(float newSpeed, int player)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned char CGameServer::ReserveNextAvailableSkirmishAIId()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::FreeSkirmishAIId(const unsigned char skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGameServer::AddToPacketCache(boost::shared_ptr<const netcode::RawPacket> &pckt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
