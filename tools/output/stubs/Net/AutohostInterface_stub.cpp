#include <iostream>
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
    std::cout << _FUNCTION_ << std::endl;
}

using namespace boost::asio;

AutohostInterface::AutohostInterface(const std::string& remoteIP, int remotePort, const std::string& localIP, int localPort)
		: autohost(netcode::netservice)
		, initialized(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string AutohostInterface::TryBindSocket(
			boost::asio::ip::udp::socket& socket,
			const std::string& remoteIP, int remotePort,
			const std::string& localIP, int localPort)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

AutohostInterface::~AutohostInterface()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendStart()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendQuit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendStartPlaying(const unsigned char* gameID, const std::string& demoName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendGameOver(uchar playerNum, const std::vector<uchar>& winningAllyTeams)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendPlayerJoined(uchar playerNum, const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendPlayerLeft(uchar playerNum, uchar reason)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendPlayerReady(uchar playerNum, uchar readyState)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendPlayerChat(uchar playerNum, uchar destination, const std::string& chatmsg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendPlayerDefeated(uchar playerNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::Message(const std::string& message)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::Warning(const std::string& message)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::SendLuaMsg(const boost::uint8_t* msg, size_t msgSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::Send(const boost::uint8_t* msg, size_t msgSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string AutohostInterface::GetChatMessage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AutohostInterface::Send(boost::asio::mutable_buffers_1 buffer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
