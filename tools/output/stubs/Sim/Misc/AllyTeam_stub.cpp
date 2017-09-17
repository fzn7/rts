/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AllyTeam.h"

#include <cstdlib>
#include "System/creg/STL_Map.h"


CR_BIND(AllyTeam, )

CR_REG_METADATA(AllyTeam, (
	CR_MEMBER(startRectTop),
	CR_MEMBER(startRectBottom),
	CR_MEMBER(startRectLeft),
	CR_MEMBER(startRectRight),
	CR_MEMBER(allies),
	CR_MEMBER(customValues)
))


AllyTeam::AllyTeam()
	: startRectTop(0)
	, startRectBottom(1)
	, startRectLeft(0)
	, startRectRight(1)
{
    //stub method
}

void AllyTeam::SetValue(const std::string& key, const std::string& value)
{
    //stub method
}
