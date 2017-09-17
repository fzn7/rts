#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "StaticMoveType.h"
#include "Map/Ground.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"

CR_BIND_DERIVED(CStaticMoveType, AMoveType, (NULL))
CR_REG_METADATA(CStaticMoveType, )

void CStaticMoveType::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
