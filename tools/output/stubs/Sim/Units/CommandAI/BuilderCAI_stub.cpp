#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BuilderCAI.h"

#include <assert.h>

#include "ExternalAI/EngineOutHandler.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/Team.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitSet.h"
#include "Sim/Units/UnitTypes/Builder.h"
#include "Sim/Units/UnitTypes/Building.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/creg/STL_Map.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CBuilderCAI, CMobileCAI, )

CR_REG_METADATA(CBuilderCAI,
                (CR_MEMBER(ownerBuilder),
                 CR_MEMBER(building),
                 CR_MEMBER(range3D),
                 CR_IGNORED(build),
                 CR_IGNORED(buildOptions),

                 CR_MEMBER(cachedRadiusId),
                 CR_MEMBER(cachedRadius),

                 CR_MEMBER(buildRetries),
                 CR_MEMBER(randomCounter),

                 CR_MEMBER(lastPC1),
                 CR_MEMBER(lastPC2),
                 CR_MEMBER(lastPC3),
                 CR_POSTLOAD(PostLoad)))

// not adding to members, should repopulate itself
CUnitSet CBuilderCAI::reclaimers;
CUnitSet CBuilderCAI::featureReclaimers;
CUnitSet CBuilderCAI::resurrecters;

static std::string
GetUnitDefBuildOptionToolTip(const UnitDef* ud, bool disabled)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBuilderCAI::CBuilderCAI()
  : CMobileCAI()
  , ownerBuilder(NULL)
  , building(false)
  , cachedRadiusId(0)
  , cachedRadius(0)
  , buildRetries(0)
  , randomCounter(0)
  , lastPC1(-1)
  , lastPC2(-1)
  , lastPC3(-1)
  , range3D(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBuilderCAI::~CBuilderCAI()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::InitStatic()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline float
CBuilderCAI::GetBuildRange(const float targetRadius) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::IsInBuildRange(const CWorldObject* obj) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::IsInBuildRange(const float3& objPos, const float objRadius) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline bool
CBuilderCAI::MoveInBuildRange(const CWorldObject* obj,
                              const bool checkMoveTypeForFailed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::MoveInBuildRange(const float3& objPos,
                              float objRadius,
                              const bool checkMoveTypeForFailed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::IsBuildPosBlocked(const BuildInfo& build,
                               const CUnit** nanoFrame) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline bool
CBuilderCAI::OutOfImmobileRange(const Command& cmd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CBuilderCAI::GetBuildOptionRadius(const UnitDef* ud, int cmdId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::CancelRestrictedUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ReclaimFeature(CFeature* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::FinishCommand()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteStop(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteBuildCmd(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::TargetInterceptable(const CUnit* unit, float targetSpeed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteRepair(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteCapture(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteGuard(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteReclaim(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::ResurrectObject(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteResurrect(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecutePatrol(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteFight(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::ExecuteRestore(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CBuilderCAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::AddUnitToReclaimers(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::RemoveUnitFromReclaimers(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::AddUnitToFeatureReclaimers(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::RemoveUnitFromFeatureReclaimers(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::AddUnitToResurrecters(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::RemoveUnitFromResurrecters(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Checks if a unit is being reclaimed by a friendly con.
 *
 * We assume that there will not be a lot of reclaimers, because performance
 * would suck if there were. Ideally, reclaimers should be assigned on a
 * per-unit basis, but this requires tracking of deaths, which albeit
 * already done, is not exactly simple to follow.
 *
 * TODO easy: store reclaiming units per allyteam
 * TODO harder: update reclaimers as they start/finish reclaims and/or die
 */
bool
CBuilderCAI::IsUnitBeingReclaimed(const CUnit* unit, CUnit* friendUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::IsFeatureBeingReclaimed(int featureId, CUnit* friendUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::IsFeatureBeingResurrected(int featureId, CUnit* friendUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::ReclaimObject(CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CBuilderCAI::FindReclaimTarget(const float3& pos,
                               float radius,
                               unsigned char cmdopt,
                               ReclaimOption recoptions,
                               float bestStartDist) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
//
//  Area searches
//

bool
CBuilderCAI::FindReclaimTargetAndReclaim(const float3& pos,
                                         float radius,
                                         unsigned char cmdopt,
                                         ReclaimOption recoptions)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::FindResurrectableFeatureAndResurrect(const float3& pos,
                                                  float radius,
                                                  unsigned char options,
                                                  bool freshOnly)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::FindCaptureTargetAndCapture(const float3& pos,
                                         float radius,
                                         unsigned char options,
                                         bool healthyOnly)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBuilderCAI::FindRepairTargetAndRepair(const float3& pos,
                                       float radius,
                                       unsigned char options,
                                       bool attackEnemy,
                                       bool builtOnly)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBuilderCAI::BuggerOff(const float3& pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
