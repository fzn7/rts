/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TeamBase.h"

#include <cstdlib>
#include <sstream>

#include "System/Util.h"
#include "System/creg/STL_Map.h"


CR_BIND(TeamBase, )
CR_REG_METADATA(TeamBase, (
	CR_MEMBER(leader),
	CR_MEMBER(color),
	CR_MEMBER(teamStartNum),
	CR_MEMBER(teamAllyteam),
	CR_MEMBER(incomeMultiplier),
	CR_MEMBER(side),
	CR_MEMBER(startPos),
	CR_MEMBER(customValues)
))


unsigned char TeamBase::teamDefaultColor[10][4] =
{
    //stub method
}

void TeamBase::SetValue(const std::string& key, const std::string& value)
{
    //stub method
}


void TeamBase::SetAdvantage(float advantage) {

	advantage = std::max(0.0f, advantage);

	SetIncomeMultiplier(advantage + 1.0f);
}

void TeamBase::SetIncomeMultiplier(float incomeMultiplier) {
	this->incomeMultiplier = std::max(0.0f, incomeMultiplier);
}
