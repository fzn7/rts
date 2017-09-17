#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

// NOTE: these _must_ be included before NetProtocol.h due to some ambiguity in
// Boost hash_float.hpp ("call of overloaded ‘ldexp(float&, int&)’ is ambiguous")
#include "System/Net/UDPConnection.h"
#include "System/Net/LocalConnection.h"

#include "NetProtocol.h"

#include "Game/GameData.h"
#include "Game/GlobalUnsynced.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Net/UnpackPacket.h"
#include "System/LoadSave/DemoRecorder.h"
#include "System/Platform/Threading.h"
#include "System/Config/ConfigHandler.h"
#include "System/GlobalConfig.h"
#include "System/Log/ILog.h"

CONFIG(int, SourcePort).defaultValue(0);


CNetProtocol* clientNet = NULL;

CNetProtocol::CNetProtocol() : keepUpdating(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CNetProtocol::~CNetProtocol()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CNetProtocol::InitClient(const char* server_addr, unsigned portnum, const std::string& myName, const std::string& myPasswd, const std::string& myVersion)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CNetProtocol::InitLocalClient()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CNetProtocol::AttemptReconnect(const std::string& myVersion)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CNetProtocol::NeedsReconnect() {
	return serverConn->NeedsReconnect();
}

bool CNetProtocol::CheckTimeout(int nsecs, bool initial) const {
	return serverConn->CheckTimeout(nsecs, initial);
}

bool CNetProtocol::Connected() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CNetProtocol::ConnectionStr() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<const netcode::RawPacket> CNetProtocol::Peek(unsigned ahead) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CNetProtocol::DeleteBufferPacketAt(unsigned index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float CNetProtocol::GetPacketTime(int frameNum) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<const netcode::RawPacket> CNetProtocol::GetData(int frameNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CNetProtocol::Send(boost::shared_ptr<const netcode::RawPacket> pkt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CNetProtocol::Send(const netcode::RawPacket* pkt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
void CNetProtocol::UpdateLoop()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CNetProtocol::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CNetProtocol::Close(bool flush)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CNetProtocol::SetDemoRecorder(CDemoRecorder* r) { demoRecorder.reset(r); }
CDemoRecorder* CNetProtocol::GetDemoRecorder() const { return demoRecorder.get(); }

unsigned int CNetProtocol::GetNumWaitingServerPackets() const { return (serverConn.get())->GetPacketQueueSize(); }

