#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UDPConnection.h"

#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/cstdint.hpp>


#include "Socket.h"
#include "ProtocolDef.h"
#include "Exception.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "System/Config/ConfigHandler.h"
#include "System/CRC.h"
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
float RANDOM_NUMBER() {
	// spring has some srand calls that interfere with the random seed
	static int lastRand = 0;

	srand(lastRand);

	// [0.0f, 1.0f)
	return (lastRand = rand()) / float(RAND_MAX);
}

bool EMULATE_PACKET_LOSS(int& lossCtr) {
	if (RANDOM_NUMBER() < (PACKET_LOSS_FACTOR / 100.0f))
		return true;

	const bool loss = RANDOM_NUMBER() < (SEVERE_PACKET_LOSS_FACTOR / 100.0f);

	if (loss && lossCtr == 0)
		lossCtr = SEVERE_PACKET_LOSS_MAX_COUNT * RANDOM_NUMBER();

	return (lossCtr > 0 && lossCtr--);
}

void EMULATE_PACKET_CORRUPTION(uint8_t& crc) {
	if ((RANDOM_NUMBER() < (PACKET_CORRUPTION_FACTOR / 100.0f)))
		crc = (uint8_t)rand();
}

#define LOSS_COUNTER lossCounter

#else
static int dummyLossCounter = 0;
inline bool EMULATE_PACKET_LOSS(int &lossCtr) { return false; }
inline void EMULATE_PACKET_CORRUPTION(boost::uint8_t& crc) {}
#define LOSS_COUNTER dummyLossCounter
#endif


#if NETWORK_TEST && PACKET_MAX_LATENCY > 0 && PACKET_MAX_LATENCY >= PACKET_MIN_LATENCY
#define EMULATE_LATENCY(cond) \
	for (auto di = delayed.begin(); di != delayed.end(); ) { \
		spring_time curtime = spring_gettime(); \
		if (curtime > di->first && (curtime - di->first) > spring_msecs(0)) { \
			mySocket->send_to(buffer(di->second), addr, flags, err); \
			di = delayed.erase(di); \
		} else { ++di; } \
	} \
	if (cond) \
		delayed[spring_gettime() + spring_msecs(PACKET_MIN_LATENCY + (PACKET_MAX_LATENCY - PACKET_MIN_LATENCY) * RANDOM_NUMBER())] = data; \
	if (false)
#else
#define EMULATE_LATENCY(cond) if(cond)
#endif


class Unpacker
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



Packet::Packet(const unsigned char* data, unsigned length)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Packet::Packet(int _lastContinuous, int _nak)
	: lastContinuous(_lastContinuous)
	, nakType(_nak)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned Packet::GetSize() const {

	unsigned size = headerSize + naks.size();

	for (auto chk = chunks.begin(); chk != chunks.end(); ++chk)
		size += (*chk)->GetSize();

	return size;
}

boost::uint8_t Packet::GetChecksum() const {

	CRC crc;
	crc << lastContinuous;
	crc << (unsigned int)nakType;

	if (!naks.empty())
		crc.Update(&naks[0], naks.size());

	for (auto chk = chunks.begin(); chk != chunks.end(); ++chk)
		(*chk)->UpdateChecksum(crc);

	return (boost::uint8_t)crc.GetDigest();
}

void Packet::Serialize(std::vector<boost::uint8_t>& data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




UDPConnection::UDPConnection(boost::shared_ptr<ip::udp::socket> netSocket, const ip::udp::endpoint& myAddr)
	: addr(myAddr)
	, sharedSocket(true)
	, mySocket(netSocket)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

UDPConnection::UDPConnection(int sourcePort, const std::string& address, const unsigned port)
	: sharedSocket(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

UDPConnection::UDPConnection(CConnection& conn)
	: sharedSocket(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::ReconnectTo(CConnection& conn) {
	dynamic_cast<UDPConnection &>(conn).CopyConnection(*this);
}

void UDPConnection::CopyConnection(UDPConnection &conn) {
	conn.InitConnection(addr, mySocket);
}

void UDPConnection::InitConnection(ip::udp::endpoint address, boost::shared_ptr<ip::udp::socket> socket) {
	addr = address;
	mySocket = socket;
}

UDPConnection::~UDPConnection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::SendData(boost::shared_ptr<const RawPacket> data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<const RawPacket> UDPConnection::Peek(unsigned ahead) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef ENABLE_DEBUG_STATS
boost::shared_ptr<const RawPacket> UDPConnection::GetData()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#else
boost::shared_ptr<const RawPacket> UDPConnection::GetData()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif


void UDPConnection::DeleteBufferPacketAt(unsigned index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::ProcessRawPacket(Packet& incoming)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::Flush(const bool forced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool UDPConnection::CheckTimeout(int seconds, bool initial) const {

	int timeout;

	if (seconds == 0) {
		timeout = (dataRecv && !initial)
				? globalConfig->networkTimeout
				: globalConfig->initialNetworkTimeout;
	} else if (seconds > 0) {
		timeout = seconds;
	} else {
		timeout = globalConfig->reconnectTimeout;
	}

	return (timeout > 0 && (spring_gettime() - lastPacketRecvTime) > spring_secs(timeout));
}

bool UDPConnection::NeedsReconnect() {

	if (CanReconnect()) {
		if (!CheckTimeout(-1)) {
			reconnectTime = globalConfig->reconnectTimeout;
		} else if (CheckTimeout(reconnectTime)) {
			++reconnectTime;
			return true;
		}
	}

	return false;
}

bool UDPConnection::CanReconnect() const {
	return (globalConfig->reconnectTimeout > 0);
}

std::string UDPConnection::Statistics() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool UDPConnection::IsUsingAddress(const ip::udp::endpoint& from) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string UDPConnection::GetFullAddress() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::SetMTU(unsigned mtu2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::CreateChunk(const unsigned char* data, const unsigned length, const int packetNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::SendIfNecessary(bool flushed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::SendPacket(Packet& pkt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::AckChunks(int lastAck)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::RequestResend(ChunkPtr ptr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

UDPConnection::BandwidthUsage::BandwidthUsage()
	: lastTime(0)
	, trafficSinceLastTime(1)
	, prelTrafficSinceLastTime(0)
	, average(0.0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::BandwidthUsage::UpdateTime(unsigned newTime)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::BandwidthUsage::DataSent(unsigned amount, bool prel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float UDPConnection::BandwidthUsage::GetAverage(bool prel) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void UDPConnection::Close(bool flush) {

	if (closed) {
		return;
	}

	Flush(flush);
	muted = true;
	if (!sharedSocket) {
		try {
			mySocket->close();
		} catch (const boost::system::system_error& ex) {
			LOG_L(L_ERROR, "Failed closing UDP connection: %s", ex.what());
		}
	}
	closed = true;
}

void UDPConnection::SetLossFactor(int factor) {
	netLossFactor = std::max((int)MIN_LOSS_FACTOR, std::min(factor, (int)MAX_LOSS_FACTOR));
}

} // namespace netcode
