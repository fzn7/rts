/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <assert.h>
#include <algorithm>
#include "Builder.h"
#include "Building.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Map/ReadMap.h"
#include "System/myMath.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Scripts/CobInstance.h"
#include "Sim/Units/CommandAI/BuilderCAI.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISoundChannels.h"

using std::min;
using std::max;

CR_BIND_DERIVED(CBuilder, CUnit, )

CR_REG_METADATA(CBuilder, (
	CR_MEMBER(range3D),
	CR_MEMBER(buildDistance),
	CR_MEMBER(buildSpeed),
	CR_MEMBER(repairSpeed),
	CR_MEMBER(reclaimSpeed),
	CR_MEMBER(resurrectSpeed),
	CR_MEMBER(captureSpeed),
	CR_MEMBER(terraformSpeed),
	CR_MEMBER(curResurrect),
	CR_MEMBER(lastResurrected),
	CR_MEMBER(curBuild),
	CR_MEMBER(curCapture),
	CR_MEMBER(curReclaim),
	CR_MEMBER(reclaimingUnit),
	CR_MEMBER(helpTerraform),
	CR_MEMBER(terraforming),
	CR_MEMBER(myTerraformLeft),
	CR_MEMBER(terraformHelp),
	CR_MEMBER(tx1), CR_MEMBER(tx2), CR_MEMBER(tz1), CR_MEMBER(tz2),
	CR_MEMBER(terraformCenter),
	CR_MEMBER(terraformRadius),
	CR_MEMBER(terraformType),
	CR_MEMBER(nanoPieceCache)
))


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBuilder::CBuilder():
	range3D(true),
	buildDistance(16),
	buildSpeed(100),
	repairSpeed(100),
	reclaimSpeed(100),
	resurrectSpeed(100),
	captureSpeed(100),
	terraformSpeed(100),
	curResurrect(0),
	lastResurrected(0),
	curBuild(0),
	curCapture(0),
	curReclaim(0),
	reclaimingUnit(false),
	helpTerraform(0),
	terraforming(false),
	terraformHelp(0),
	myTerraformLeft(0),
	terraformType(Terraform_Building),
	tx1(0),
	tx2(0),
	tz1(0),
	tz2(0),
	terraformCenter(ZeroVector),
	terraformRadius(0)
{
    //stub method
}


CBuilder::~CBuilder()
{
    //stub method
}


void CBuilder::PreInit(const UnitLoadParams& params)
{
    //stub method
}


bool CBuilder::CanAssistUnit(const CUnit* u, const UnitDef* def) const
{
    //stub method
}


bool CBuilder::CanRepairUnit(const CUnit* u) const
{
    //stub method
}


void CBuilder::Update()
{
    //stub method
}


void CBuilder::SlowUpdate()
{
    //stub method
}


void CBuilder::SetRepairTarget(CUnit* target)
{
    //stub method
}


void CBuilder::SetReclaimTarget(CSolidObject* target)
{
    //stub method
}


void CBuilder::SetResurrectTarget(CFeature* target)
{
    //stub method
}


void CBuilder::SetCaptureTarget(CUnit* target)
{
    //stub method
}


void CBuilder::StartRestore(float3 centerPos, float radius)
{
    //stub method
}


void CBuilder::StopBuild(bool callScript)
{
    //stub method
}


bool CBuilder::StartBuild(BuildInfo& buildInfo, CFeature*& feature, bool& waitStance)
{
    //stub method
}


float CBuilder::CalculateBuildTerraformCost(BuildInfo& buildInfo)
{
    //stub method
}


void CBuilder::DependentDied(CObject *o)
{
    //stub method
}


bool CBuilder::ScriptStartBuilding(float3 pos, bool silent)
{
    //stub method
}


void CBuilder::HelpTerraform(CBuilder* unit)
{
    //stub method
}


void CBuilder::CreateNanoParticle(const float3& goal, float radius, bool inverse, bool highPriority)
{
    //stub method
}
