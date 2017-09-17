/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "BuilderCAI.h"

#include <assert.h>

#include "ExternalAI/EngineOutHandler.h"
#include "Game/GameHelper.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/GlobalUnsynced.h"
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
#include "Sim/Units/UnitSet.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitTypes/Builder.h"
#include "Sim/Units/UnitTypes/Building.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "System/myMath.h"
#include "System/Util.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/creg/STL_Map.h"


CR_BIND_DERIVED(CBuilderCAI ,CMobileCAI , )

CR_REG_METADATA(CBuilderCAI , (
	CR_MEMBER(ownerBuilder),
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
	CR_POSTLOAD(PostLoad)
))

// not adding to members, should repopulate itself
CUnitSet CBuilderCAI::reclaimers;
CUnitSet CBuilderCAI::featureReclaimers;
CUnitSet CBuilderCAI::resurrecters;


static std::string GetUnitDefBuildOptionToolTip(const UnitDef* ud, bool disabled) {
	std::string tooltip;

	if (disabled) {
		tooltip = "\xff\xff\x22\x22" "DISABLED: " "\xff\xff\xff\xff";
	} else {
		tooltip = "Build: ";
	}

	tooltip += (ud->humanName + " - " + ud->tooltip);
	tooltip += ("\nHealth "      + FloatToString(ud->health,    "%.0f"));
	tooltip += ("\nMetal cost "  + FloatToString(ud->metal,     "%.0f"));
	tooltip += ("\nEnergy cost " + FloatToString(ud->energy,    "%.0f"));
	tooltip += ("\nBuild time "  + FloatToString(ud->buildTime, "%.0f"));

	return tooltip;
}


CBuilderCAI::CBuilderCAI():
	CMobileCAI(),
	ownerBuilder(NULL),
	building(false),
	cachedRadiusId(0),
	cachedRadius(0),
	buildRetries(0),
	randomCounter(0),
	lastPC1(-1),
	lastPC2(-1),
	lastPC3(-1),
	range3D(true)
{
    //stub method
}

CBuilderCAI::~CBuilderCAI()
{
    //stub method
}

void CBuilderCAI::InitStatic()
{
    //stub method
}

void CBuilderCAI::PostLoad()
{
    //stub method
}



inline float CBuilderCAI::GetBuildRange(const float targetRadius) const
{
    //stub method
}



bool CBuilderCAI::IsInBuildRange(const CWorldObject* obj) const
{
    //stub method
}

bool CBuilderCAI::IsInBuildRange(const float3& objPos, const float objRadius) const
{
    //stub method
}



inline bool CBuilderCAI::MoveInBuildRange(const CWorldObject* obj, const bool checkMoveTypeForFailed)
{
    //stub method
}

bool CBuilderCAI::MoveInBuildRange(const float3& objPos, float objRadius, const bool checkMoveTypeForFailed)
{
    //stub method
}


bool CBuilderCAI::IsBuildPosBlocked(const BuildInfo& build, const CUnit** nanoFrame) const
{
    //stub method
}



inline bool CBuilderCAI::OutOfImmobileRange(const Command& cmd) const
{
    //stub method
}


float CBuilderCAI::GetBuildOptionRadius(const UnitDef* ud, int cmdId)
{
    //stub method
}


void CBuilderCAI::CancelRestrictedUnit()
{
    //stub method
}


void CBuilderCAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
}


void CBuilderCAI::SlowUpdate()
{
    //stub method
}


void CBuilderCAI::ReclaimFeature(CFeature* f)
{
    //stub method
}


void CBuilderCAI::FinishCommand()
{
    //stub method
}


void CBuilderCAI::ExecuteStop(Command& c)
{
    //stub method
}


void CBuilderCAI::ExecuteBuildCmd(Command& c)
{
    //stub method
}


bool CBuilderCAI::TargetInterceptable(const CUnit* unit, float targetSpeed) {
	// if the target is moving away at a higher speed than we can manage, there is little point in chasing it
	const float maxSpeed = owner->moveType->GetMaxSpeed();
	if (targetSpeed <= maxSpeed)
		return true;
	const float3 unitToPos = unit->pos - owner->pos;
	return (unitToPos.dot2D(unit->speed) <= unitToPos.Length2D() * maxSpeed);
}


void CBuilderCAI::ExecuteRepair(Command& c)
{
    //stub method
}


void CBuilderCAI::ExecuteCapture(Command& c)
{
    //stub method
}


void CBuilderCAI::ExecuteGuard(Command& c)
{
    //stub method
}


void CBuilderCAI::ExecuteReclaim(Command& c)
{
    //stub method
}


bool CBuilderCAI::ResurrectObject(CFeature *feature) {
	if (MoveInBuildRange(feature, true)) {
		ownerBuilder->SetResurrectTarget(feature);
	} else {
		if (owner->moveType->progressState == AMoveType::Failed) {
			return false;
		}
	}

	return true;
}


void CBuilderCAI::ExecuteResurrect(Command& c)
{
    //stub method
}


void CBuilderCAI::ExecutePatrol(Command& c)
{
    //stub method
}


void CBuilderCAI::ExecuteFight(Command& c)
{
    //stub method
}


void CBuilderCAI::ExecuteRestore(Command& c)
{
    //stub method
}


int CBuilderCAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
}


void CBuilderCAI::AddUnitToReclaimers(CUnit* unit)
{
    //stub method
}


void CBuilderCAI::RemoveUnitFromReclaimers(CUnit* unit)
{
    //stub method
}


void CBuilderCAI::AddUnitToFeatureReclaimers(CUnit* unit)
{
    //stub method
}

void CBuilderCAI::RemoveUnitFromFeatureReclaimers(CUnit* unit)
{
    //stub method
}

void CBuilderCAI::AddUnitToResurrecters(CUnit* unit)
{
    //stub method
}

void CBuilderCAI::RemoveUnitFromResurrecters(CUnit* unit)
{
    //stub method
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
bool CBuilderCAI::IsUnitBeingReclaimed(const CUnit* unit, CUnit *friendUnit)
{
    //stub method
}


bool CBuilderCAI::IsFeatureBeingReclaimed(int featureId, CUnit *friendUnit)
{
    //stub method
}


bool CBuilderCAI::IsFeatureBeingResurrected(int featureId, CUnit *friendUnit)
{
    //stub method
}


bool CBuilderCAI::ReclaimObject(CSolidObject* object) {
	if (MoveInBuildRange(object)) {
		ownerBuilder->SetReclaimTarget(object);
	} else {
		if (owner->moveType->progressState == AMoveType::Failed) {
			return false;
		}
	}

	return true;
}


int CBuilderCAI::FindReclaimTarget(const float3& pos, float radius, unsigned char cmdopt, ReclaimOption recoptions, float bestStartDist) const
{
    //stub method
}


/******************************************************************************/
//
//  Area searches
//

bool CBuilderCAI::FindReclaimTargetAndReclaim(const float3& pos, float radius, unsigned char cmdopt, ReclaimOption recoptions)
{
    //stub method
}


bool CBuilderCAI::FindResurrectableFeatureAndResurrect(const float3& pos,
                                                       float radius,
                                                       unsigned char options,
													   bool freshOnly)
{
    //stub method
}


bool CBuilderCAI::FindCaptureTargetAndCapture(const float3& pos, float radius,
                                              unsigned char options,
											  bool healthyOnly)
{
    //stub method
}


bool CBuilderCAI::FindRepairTargetAndRepair(const float3& pos, float radius,
                                            unsigned char options,
                                            bool attackEnemy,
											bool builtOnly)
{
    //stub method
}



void CBuilderCAI::BuggerOff(const float3& pos, float radius) {
	if (owner->unitDef->IsStaticBuilderUnit())
		return;

	CMobileCAI::BuggerOff(pos, radius);
}

