#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AICheats.h"

#include "ExternalAI/SkirmishAIWrapper.h"
#include "Game/GameSetup.h"
#include "Game/TraceRay.h"
#include "Net/GameServer.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/GlobalConstants.h" // needed for MAX_UNITS
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "System/myMath.h"

#include <list>
#include <vector>

#define CHECK_UNITID(id) ((unsigned)(id) < (unsigned)unitHandler->MaxUnits())
#define CHECK_GROUPID(id) ((unsigned)(id) < (unsigned)gh->groups.size())

CUnit*
CAICheats::GetUnit(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CAICheats::CAICheats(CSkirmishAIWrapper* ai)
  : ai(ai)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAICheats::EnableCheatEvents(bool enable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAICheats::SetMyIncomeMultiplier(float incomeMultiplier)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAICheats::GiveMeMetal(float amount)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAICheats::GiveMeEnergy(float amount)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::CreateUnit(const char* name, const float3& pos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const UnitDef*
CAICheats::GetUnitDef(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CAICheats::GetUnitPos(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CAICheats::GetUnitVelocity(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
FilterUnitsVector(const std::vector<CUnit*>& units,
                  int* unitIds,
                  int unitIds_max,
                  bool (*includeUnit)(CUnit*) = NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
unit_IsNeutral(CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int myAllyTeamId = -1;

/// You have to set myAllyTeamId before callign this function. NOT thread safe!
static inline bool
unit_IsEnemy(CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::GetEnemyUnits(int* unitIds, int unitIds_max)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::GetEnemyUnits(int* unitIds,
                         const float3& pos,
                         float radius,
                         int unitIds_max)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::GetNeutralUnits(int* unitIds, int unitIds_max)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::GetNeutralUnits(int* unitIds,
                           const float3& pos,
                           float radius,
                           int unitIds_max)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::GetFeatures(int* features, int max) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
CAICheats::GetFeatures(int* features,
                       int max,
                       const float3& pos,
                       float radius) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::GetUnitTeam(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::GetUnitAllyTeam(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CAICheats::GetUnitHealth(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CAICheats::GetUnitMaxHealth(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CAICheats::GetUnitPower(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CAICheats::GetUnitExperience(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAICheats::IsUnitActivated(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAICheats::UnitBeingBuilt(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAICheats::GetUnitResourceInfo(int unitId, UnitResourceInfo* unitResInf) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const CCommandQueue*
CAICheats::GetCurrentUnitCommands(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::GetBuildingFacing(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAICheats::IsUnitCloaked(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAICheats::IsUnitParalyzed(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAICheats::IsUnitNeutral(int unitId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAICheats::GetProperty(int id, int property, void* data) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CAICheats::GetValue(int id, void* data) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CAICheats::HandleCommand(int commandId, void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
