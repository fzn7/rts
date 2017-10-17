#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UDPConnection.h"

#include <boost/cstdint.hpp>
#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>

#include "Exception.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "ProtocolDef.h"
#include "Socket.h"
#include "System/CRC.h"
#include "System/Config/ConfigHandler.h"
#include "System/GlobalConfig.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#ifndef UNIT_TEST
CONFIG(bool, UDPConnectionLogDebugMessages).defaultValue(false);
#endif

namespace netcode {
using namespace boost::asio;

static const unsigned udpMaxPacketSize = 4096;
static const int maxChunkSize = 254;
static const int chunksPerSec = 30;

#if NETWORK_TEST
float
RANDOM_NUMBER()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
EMULATE_PACKET_LOSS(int& lossCtr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
EMULATE_PACKET_CORRUPTION(uint8_t& crc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define LOSS_COUNTER lossCounter

#else
static int dummyLossCounter = 0;
inline bool
EMULATE_PACKET_LOSS(int& lossCtr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
inline void
EMULATE_PACKET_CORRUPTION(boost::uint8_t& crc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Packet::Packet(const unsigned char* data, unsigned length)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Packet::Packet(int _lastContinuous, int _nak)
  : lastContinuous(_lastContinuous)
  , nakType(_nak)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

boost::uint8_t
Packet::GetChecksum() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Packet::Serialize(std::vector<boost::uint8_t>& data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

UDPConnection::UDPConnection(boost::shared_ptr<ip::udp::socket> netSocket,
                             const ip::udp::endpoint& myAddr)
  : addr(myAddr)
  , sharedSocket(true)
  , mySocket(netSocket)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

UDPConnection::UDPConnection(int sourcePort,
                             const std::string& address,
                             const unsigned port)
  : sharedSocket(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

UDPConnection::UDPConnection(CConnection& conn)
  : sharedSocket(true)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::Init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::ReconnectTo(CConnection& conn)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::CopyConnection(UDPConnection& conn)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::InitConnection(ip::udp::endpoint address,
                              boost::shared_ptr<ip::udp::socket> socket)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

UDPConnection::~UDPConnection()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::SendData(boost::shared_ptr<const RawPacket> data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

boost::shared_ptr<const RawPacket>
UDPConnection::Peek(unsigned ahead) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#ifdef ENABLE_DEBUG_STATS
boost::shared_ptr<const RawPacket>
UDPConnection::GetData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#else
boost::shared_ptr<const RawPacket>
UDPConnection::GetData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif

void
UDPConnection::DeleteBufferPacketAt(unsigned index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::ProcessRawPacket(Packet& incoming)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::Flush(const bool forced)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
UDPConnection::CheckTimeout(int seconds, bool initial) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
UDPConnection::NeedsReconnect()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
UDPConnection::CanReconnect() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
UDPConnection::Statistics() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
UDPConnection::IsUsingAddress(const ip::udp::endpoint& from) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
UDPConnection::GetFullAddress() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::SetMTU(unsigned mtu2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::CreateChunk(const unsigned char* data,
                           const unsigned length,
                           const int packetNum)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::SendIfNecessary(bool flushed)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::SendPacket(Packet& pkt)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::AckChunks(int lastAck)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::RequestResend(ChunkPtr ptr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

UDPConnection::BandwidthUsage::BandwidthUsage()
  : lastTime(0)
  , trafficSinceLastTime(1)
  , prelTrafficSinceLastTime(0)
  , average(0.0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::BandwidthUsage::DataSent(unsigned amount, bool prel)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
UDPConnection::BandwidthUsage::GetAverage(bool prel) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::Close(bool flush)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UDPConnection::SetLossFactor(int factor)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

} // namespace netcode
