#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Building.h"
#include "Game/GameHelper.h"
#include "Map/ReadMap.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitLoader.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CBuilding, CUnit, )

CR_REG_METADATA(CBuilding, )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBuilding::CBuilding()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilding::PreInit(const UnitLoadParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilding::PostInit(const CUnit* builder)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilding::ForcedMove(const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
