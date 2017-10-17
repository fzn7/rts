#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UnitLoader.h"
#include "Unit.h"
#include "UnitDef.h"
#include "UnitDefHandler.h"
#include "UnitHandler.h"

#include "Scripts/UnitScript.h"

#include "UnitTypes/Builder.h"
#include "UnitTypes/ExtractorBuilding.h"
#include "UnitTypes/Factory.h"

#include "CommandAI/AirCAI.h"
#include "CommandAI/BuilderCAI.h"
#include "CommandAI/CommandAI.h"
#include "CommandAI/FactoryCAI.h"
#include "CommandAI/MobileCAI.h"

#include "Game/GameHelper.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Map/ReadMap.h"

#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/TeamHandler.h"

#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Platform/Watchdog.h"

CUnitLoader*
CUnitLoader::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CUnitLoader::LoadUnit(const std::string& name, const UnitLoadParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit*
CUnitLoader::LoadUnit(const UnitLoadParams& cparams)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitLoader::ParseAndExecuteGiveUnitsCommand(
  const std::vector<std::string>& args,
  int team)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitLoader::GiveUnits(const std::string& objectName,
                       float3 pos,
                       int amount,
                       int team,
                       int featureAllyTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitLoader::FlattenGround(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitLoader::RestoreGround(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
