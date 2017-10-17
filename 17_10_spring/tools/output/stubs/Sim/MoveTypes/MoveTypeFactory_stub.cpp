#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */
#include "MoveTypeFactory.h"
#include "GroundMoveType.h"
#include "HoverAirMoveType.h"
#include "MoveDefHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "StaticMoveType.h"
#include "StrafeAirMoveType.h"

AMoveType*
MoveTypeFactory::GetMoveType(CUnit* unit, const UnitDef* ud)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
