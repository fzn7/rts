/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AutohostInterface.h"

#include "Net/Protocol/BaseNetProtocol.h"
#include "System/Log/ILog.h"
#include "System/Net/Socket.h"

#include <string.h>
#include <vector>
#include <boost/cstdint.hpp>


#define LOG_SECTION_AUTOHOST_INTERFACE "AutohostInterface"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_AUTOHOST_INTERFACE)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_AUTOHOST_INTERFACE


namespace {

/**
 * @enum EVENT Which events can be sent to the autohost
 *   (in brackets: parameters, where uchar means unsigned char and "string"
 *   means plain ascii text)
 */
enum EVENT
{
    //stub method
}

using namespace boost::asio;

AutohostInterface::AutohostInterface(const std::string& remoteIP, int remotePort, const std::string& localIP, int localPort)
		: autohost(netcode::netservice)
		, initialized(false)
{
    //stub method
}

std::string AutohostInterface::TryBindSocket(
			boost::asio::ip::udp::socket& socket,
			const std::string& remoteIP, int remotePort,
			const std::string& localIP, int localPort)
{
    //stub method
}

AutohostInterface::~AutohostInterface()
{
    //stub method
}

void AutohostInterface::SendStart()
{
    //stub method
}

void AutohostInterface::SendQuit()
{
    //stub method
}

void AutohostInterface::SendStartPlaying(const unsigned char* gameID, const std::string& demoName)
{
    //stub method
}

void AutohostInterface::SendGameOver(uchar playerNum, const std::vector<uchar>& winningAllyTeams)
{
    //stub method
}

void AutohostInterface::SendPlayerJoined(uchar playerNum, const std::string& name)
{
    //stub method
}

void AutohostInterface::SendPlayerLeft(uchar playerNum, uchar reason)
{
    //stub method
}

void AutohostInterface::SendPlayerReady(uchar playerNum, uchar readyState)
{
    //stub method
}

void AutohostInterface::SendPlayerChat(uchar playerNum, uchar destination, const std::string& chatmsg)
{
    //stub method
}

void AutohostInterface::SendPlayerDefeated(uchar playerNum)
{
    //stub method
}

void AutohostInterface::Message(const std::string& message)
{
    //stub method
}

void AutohostInterface::Warning(const std::string& message)
{
    //stub method
}

void AutohostInterface::SendLuaMsg(const boost::uint8_t* msg, size_t msgSize)
{
    //stub method
}

void AutohostInterface::Send(const boost::uint8_t* msg, size_t msgSize)
{
    //stub method
}

std::string AutohostInterface::GetChatMessage()
{
    //stub method
}

void AutohostInterface::Send(boost::asio::mutable_buffers_1 buffer)
{
    //stub method
}
