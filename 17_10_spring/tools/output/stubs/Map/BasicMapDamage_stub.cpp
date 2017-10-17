#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BasicMapDamage.h"
#include "MapInfo.h"
#include "ReadMap.h"
#include "Rendering/Env/GrassDrawer.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "System/TimeProfiler.h"

CBasicMapDamage::CBasicMapDamage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBasicMapDamage::Explosion(const float3& pos, float strength, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBasicMapDamage::RecalcArea(int x1, int x2, int y1, int y2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBasicMapDamage::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
