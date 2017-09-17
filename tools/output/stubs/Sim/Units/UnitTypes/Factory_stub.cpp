/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Factory.h"
#include "Game/GameHelper.h"
#include "Game/WaitCommandsAI.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/FactoryCAI.h"
#include "Sim/Units/CommandAI/MobileCAI.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "Sim/Units/UnitDefHandler.h"
#include "System/EventHandler.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"
#include "System/creg/DefTypes.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"

#include "Game/GlobalUnsynced.h"

CR_BIND_DERIVED(CFactory, CBuilding, )

CR_REG_METADATA(CFactory, (
	CR_MEMBER(buildSpeed),
	CR_MEMBER(lastBuildUpdateFrame),
	CR_MEMBER(curBuildDef),
	CR_MEMBER(curBuild),
	CR_MEMBER(finishedBuildCommand),
	CR_MEMBER(nanoPieceCache)
))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFactory::CFactory():
	buildSpeed(100.0f),
	curBuild(nullptr),
	curBuildDef(nullptr),
	lastBuildUpdateFrame(-1)
{
    //stub method
}

void CFactory::KillUnit(CUnit* attacker, bool selfDestruct, bool reclaimed, bool showDeathSequence)
{
    //stub method
}

void CFactory::PreInit(const UnitLoadParams& params)
{
    //stub method
}



float3 CFactory::CalcBuildPos(int buildPiece)
{
    //stub method
}



void CFactory::Update()
{
    //stub method
}

/*
void CFactory::SlowUpdate(void)
{
    //stub method
}
*/



void CFactory::StartBuild(const UnitDef* buildeeDef) {
	const float3& buildPos = CalcBuildPos();
	const bool blocked = groundBlockingObjectMap->GroundBlocked(buildPos, this);

	// wait until buildPos is no longer blocked (eg. by a previous buildee)
	//
	// it might rarely be the case that a unit got stuck inside the factory
	// or died right after completion and left some wreckage, but that is up
	// to players to fix (we no longer broadcast BuggerOff directives, since
	// those are indiscriminate and ineffective)
	if (blocked)
		return;

	UnitLoadParams buildeeParams = {buildeeDef, this, buildPos, ZeroVector, -1, team, buildFacing, true, false};
	CUnit* buildee = unitLoader->LoadUnit(buildeeParams);

	if (!unitDef->canBeAssisted) {
		buildee->soloBuilder = this;
		buildee->AddDeathDependence(this, DEPENDENCE_BUILDER);
	}

	AddDeathDependence(buildee, DEPENDENCE_BUILD);
	script->StartBuilding();

	// set curBuildDef to NULL to indicate construction
	// has started, otherwise we would keep being called
	curBuild = buildee;
	curBuildDef = nullptr;

	if (losStatus[gu->myAllyTeam] & LOS_INLOS) {
		Channels::General->PlayRandomSample(unitDef->sounds.build, buildPos);
	}
}

void CFactory::UpdateBuild(CUnit* buildee) {
	if (IsStunned())
		return;

	// factory not under construction and
	// nanolathing unit: continue building
	lastBuildUpdateFrame = gs->frameNum;

	// buildPiece is the rotating platform
	const int buildPiece = script->QueryBuildInfo();
	const float3& buildPos = CalcBuildPos(buildPiece);
	const CMatrix44f& buildPieceMat = script->GetPieceMatrix(buildPiece);
	const int buildPieceHeading = GetHeadingFromVector(buildPieceMat[2], buildPieceMat[10]); //! x.z, z.z

	float3 buildeePos = buildPos;

	// rotate unit nanoframe with platform
	buildee->heading = (-buildPieceHeading + GetHeadingFromFacing(buildFacing)) & (SPRING_CIRCLE_DIVS - 1);

	if (buildee->unitDef->floatOnWater && (buildeePos.y <= 0.0f))
		buildeePos.y = -buildee->unitDef->waterline;

	buildee->Move(buildeePos, false);
	buildee->UpdateDirVectors(false);
	buildee->UpdateMidAndAimPos();

	const CCommandQueue& queue = commandAI->commandQue;

	if (!queue.empty() && (queue.front().GetID() == CMD_WAIT)) {
		buildee->AddBuildPower(this, 0.0f);
	} else {
		if (buildee->AddBuildPower(this, buildSpeed)) {
			CreateNanoParticle();
		}
	}
}

void CFactory::FinishBuild(CUnit* buildee) {
	if (buildee->beingBuilt) { return; }
	if (unitDef->fullHealthFactory && buildee->health < buildee->maxHealth) { return; }

	{
		if (group && !buildee->group) {
			buildee->SetGroup(group, true);
		}
	}

	const CCommandAI* bcai = buildee->commandAI;
	// if not idle, the buildee already has user orders
	const bool buildeeIdle = (bcai->commandQue.empty());
	const bool buildeeMobile = (dynamic_cast<const CMobileCAI*>(bcai) != nullptr);

	if (buildeeIdle || buildeeMobile) {
		AssignBuildeeOrders(buildee);
		waitCommandsAI.AddLocalUnit(buildee, this);
	}

	// inform our commandAI
	CFactoryCAI* factoryCAI = static_cast<CFactoryCAI*>(commandAI);
	factoryCAI->FactoryFinishBuild(finishedBuildCommand);

	eventHandler.UnitFromFactory(buildee, this, !buildeeIdle);
	StopBuild();
}



unsigned int CFactory::QueueBuild(const UnitDef* buildeeDef, const Command& buildCmd)
{
    //stub method
}

void CFactory::StopBuild()
{
    //stub method
}

void CFactory::DependentDied(CObject* o)
{
    //stub method
}



void CFactory::SendToEmptySpot(CUnit* unit)
{
    //stub method
}

void CFactory::AssignBuildeeOrders(CUnit* unit) {
	CCommandAI* unitCAI = unit->commandAI;
	CCommandQueue& unitCmdQue = unitCAI->commandQue;

	const CFactoryCAI* factoryCAI = static_cast<CFactoryCAI*>(commandAI);
	const CCommandQueue& factoryCmdQue = factoryCAI->newUnitCommands;

	if (factoryCmdQue.empty() && unitCmdQue.empty()) {
		SendToEmptySpot(unit);
		return;
	}

	Command c(CMD_MOVE);

	if (!unit->unitDef->canfly) {
		// HACK: when a factory has a rallypoint set far enough away
		// to trigger the non-admissable path estimators, we want to
		// avoid units getting stuck inside by issuing them an extra
		// move-order. However, this order can *itself* cause the PF
		// system to consider the path blocked if the extra waypoint
		// falls within the factory's confines, so use a wide berth.
		const float xs = unitDef->xsize * SQUARE_SIZE * 0.5f;
		const float zs = unitDef->zsize * SQUARE_SIZE * 0.5f;

		float tmpDst = 2.0f;
		float3 tmpPos = unit->pos + (frontdir * this->radius * tmpDst);

		if (buildFacing == FACING_NORTH || buildFacing == FACING_SOUTH) {
			while ((tmpPos.z >= unit->pos.z - zs && tmpPos.z <= unit->pos.z + zs)) {
				tmpDst += 0.5f;
				tmpPos = unit->pos + (frontdir * this->radius * tmpDst);
			}
		} else {
			while ((tmpPos.x >= unit->pos.x - xs && tmpPos.x <= unit->pos.x + xs)) {
				tmpDst += 0.5f;
				tmpPos = unit->pos + (frontdir * this->radius * tmpDst);
			}
		}

		c.PushPos(tmpPos.cClampInBounds());
	} else {
		// dummy rallypoint for aircraft
		c.PushPos(unit->pos);
	}

	if (unitCmdQue.empty()) {
		unitCAI->GiveCommand(c);

		// copy factory orders for new unit
		for (CCommandQueue::const_iterator ci = factoryCmdQue.begin(); ci != factoryCmdQue.end(); ++ci) {
			Command c = *ci;
			c.options |= SHIFT_KEY;

			if (c.GetID() == CMD_MOVE) {
				float xjit = gs->randFloat() * TWOPI;
				float zjit = gs->randFloat() * TWOPI;

				const float3 p1 = c.GetPos(0);
				const float3 p2 = float3(p1.x + xjit, p1.y, p1.z + zjit);

				// apply a small amount of random jitter to move commands
				// such that new units do not all share the same goal-pos
				// and start forming a "trail" back to the factory exit
				c.SetPos(0, p2);
			}

			unitCAI->GiveCommand(c);
		}
	} else {
		unitCmdQue.push_front(c);
	}
}



bool CFactory::ChangeTeam(int newTeam, ChangeType type)
{
    //stub method
}


void CFactory::CreateNanoParticle(bool highPriority)
{
    //stub method
}
