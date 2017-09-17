/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <assert.h>
#include <zlib.h>

#include "GameData.h"

#include "Net/Protocol/BaseNetProtocol.h"
#include "System/Net/PackPacket.h"
#include "System/Net/UnpackPacket.h"

using namespace netcode;

GameData::GameData()
	: mapChecksum(0)
	, modChecksum(0)
	, randomSeed(0)
{
    //stub method
}


GameData::GameData(const std::string& setup)
	: setupText(setup)
	, mapChecksum(0)
	, modChecksum(0)
	, randomSeed(0)
{
    //stub method
}


GameData::GameData(boost::shared_ptr<const RawPacket> pckt)
{
    //stub method
}

const netcode::RawPacket* GameData::Pack() const
{
    //stub method
}

void GameData::SetSetupText(const std::string& newSetup)
{
    //stub method
}

void GameData::SetMapChecksum(const unsigned checksum)
{
    //stub method
}

void GameData::SetModChecksum(const unsigned checksum)
{
    //stub method
}

void GameData::SetRandomSeed(const unsigned seed)
{
    //stub method
}
