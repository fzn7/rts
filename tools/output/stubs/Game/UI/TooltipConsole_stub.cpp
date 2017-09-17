#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TooltipConsole.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/PlayerHandler.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Map/MapInfo.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"
#include "MouseHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Util.h"

CONFIG(std::string, TooltipGeometry).defaultValue("0.0 0.0 0.41 0.1");
CONFIG(bool, TooltipOutlineFont).defaultValue(true).headlessValue(false);

CTooltipConsole* tooltip = NULL;

CTooltipConsole::CTooltipConsole()
  : enabled(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CTooltipConsole::~CTooltipConsole() {}

void
CTooltipConsole::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CTooltipConsole::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    /******************************************************************************/

#define RED "\xff\xff\x50\x01"
#define BLUE "\xff\xd3\xdb\xff"
#define GREEN "\xff\x50\xff\x50"
#define GREY "\xff\x90\x90\x90"
#define DARKBLUE "\xff\xc0\xc0\xff"

static void
GetDecoyResources(const CUnit* unit,
                  float& mMake,
                  float& mUse,
                  float& eMake,
                  float& eUse)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CTooltipConsole::MakeUnitString(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CTooltipConsole::MakeUnitStatsString(const SUnitStats& stats)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CTooltipConsole::MakeFeatureString(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CTooltipConsole::MakeGroundString(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/***********************************************************************/
/***********************************************************************/

SUnitStats::SUnitStats()
  : health(0.0f)
  , maxHealth(0.0f)
  , experience(0.0f)
  , cost(0.0f)
  , maxRange(0.0f)
  , metalMake(0.0f)
  , metalUse(0.0f)
  , energyMake(0.0f)
  , energyUse(0.0f)
  , harvestMetal(0.0f)
  , harvestMetalMax(0.0f)
  , harvestEnergy(0.0f)
  , harvestEnergyMax(0.0f)
  , count(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
