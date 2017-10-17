#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AutohostInterface.h"

#include "Net/Protocol/BaseNetProtocol.h"
#include "System/Log/ILog.h"
#include "System/Net/Socket.h"

#include <boost/cstdint.hpp>
#include <string.h>
#include <vector>

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
    /// Server has started ()
    SERVER_STARTED = 0,

    /// Server is about to exit ()
    SERVER_QUIT = 1,

    /// Game starts ()
    SERVER_STARTPLAYING = 2,

    /// Game has ended ()
    SERVER_GAMEOVER = 3,

    /// An information message from server (string message)
    SERVER_MESSAGE = 4,

    /// Server gave out a warning (string warningmessage)
    SERVER_WARNING = 5,

    /// Player has joined the game (uchar playernumber, string name)
    PLAYER_JOINED = 10,

    /**
     * Player has left (uchar playernumber, uchar reason
     * (0: lost connection, 1: left, 2: kicked) )
     */
    PLAYER_LEFT = 11,

    /**
     * Player has updated its ready-state
     * (uchar playernumber, uchar state
     * (0: not ready, 1: ready, 2: state not changed) )
     */
    PLAYER_READY = 12,

    /**
     * @brief Player has sent a chat message
     *   (uchar playernumber, uchar destination, string text)
     *
     * Destination can be any of: a playernumber [0-32]
     * static const int TO_ALLIES = 127;
     * static const int TO_SPECTATORS = 126;
     * static const int TO_EVERYONE = 125;
     * (copied from Game/ChatMessage.h)
     */
    PLAYER_CHAT = 13,

    /// Player has been defeated (uchar playernumber)
    PLAYER_DEFEATED = 14,

    /**
     * @brief Message sent by lua script
     *
     * (uchar playernumber, uint16_t script, uint8_t mode, uint8_t[X] data)
     * (X = space left in packet)
     */
    GAME_LUAMSG = 20,

    /**
     * @brief team statistics
     * @see CTeam::Statistics for a reference of how to read them
     * (uchar teamnumber), CTeam::Statistics(in binary form)
     */
    GAME_TEAMSTAT = NETMSG_TEAMSTAT, // should be 60
};

using namespace boost::asio;

AutohostInterface::AutohostInterface(const std::string& remoteIP,
                                     int remotePort,
                                     const std::string& localIP,
                                     int localPort)
  : autohost(netcode::netservice)
  , initialized(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
AutohostInterface::TryBindSocket(boost::asio::ip::udp::socket& socket,
                                 const std::string& remoteIP,
                                 int remotePort,
                                 const std::string& localIP,
                                 int localPort)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

AutohostInterface::~AutohostInterface() {}

void
AutohostInterface::SendStart()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendQuit()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendStartPlaying(const unsigned char* gameID,
                                    const std::string& demoName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendGameOver(uchar playerNum,
                                const std::vector<uchar>& winningAllyTeams)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendPlayerJoined(uchar playerNum, const std::string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendPlayerLeft(uchar playerNum, uchar reason)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendPlayerReady(uchar playerNum, uchar readyState)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendPlayerChat(uchar playerNum,
                                  uchar destination,
                                  const std::string& chatmsg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendPlayerDefeated(uchar playerNum)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::Message(const std::string& message)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::Warning(const std::string& message)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::SendLuaMsg(const boost::uint8_t* msg, size_t msgSize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::Send(const boost::uint8_t* msg, size_t msgSize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
AutohostInterface::GetChatMessage()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AutohostInterface::Send(boost::asio::mutable_buffers_1 buffer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
