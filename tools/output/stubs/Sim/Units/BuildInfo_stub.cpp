#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */
#include "BuildInfo.h"

#include "UnitDef.h"
#include "UnitDefHandler.h"
#include "Sim/Units/CommandAI/Command.h"
#include "System/myMath.h"
#include "System/float3.h"


BuildInfo::BuildInfo()
	: def(NULL)
	, pos(ZeroVector)
	, buildFacing(FACING_SOUTH)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void BuildInfo::AddCommandParams(Command& cmd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool BuildInfo::Parse(const Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int BuildInfo::GetXSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int BuildInfo::GetZSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
