/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PlayerBase.h"

#include <cstdlib>
#include "System/creg/STL_Map.h"


CR_BIND_DERIVED(PlayerBase,TeamController, )
CR_REG_METADATA(PlayerBase, (
	CR_MEMBER(rank),
	CR_MEMBER(countryCode),
	CR_MEMBER(spectator),
	CR_MEMBER(isFromDemo),
	CR_MEMBER(readyToStart),
	CR_MEMBER(desynced),
	CR_MEMBER(cpuUsage),
	CR_MEMBER(customValues)
))



PlayerBase::PlayerBase() :
	TeamController(),
	rank(-1),
	cpuUsage (0.0f),
	spectator(false),
	isFromDemo(false),
	readyToStart(false),
	desynced(false)
{
    //stub method
}

void PlayerBase::SetValue(const std::string& key, const std::string& value)
{
    //stub method
}
