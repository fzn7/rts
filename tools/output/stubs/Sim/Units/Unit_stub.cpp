#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UnitDef.h"
#include "Unit.h"
#include "UnitHandler.h"
#include "UnitDefHandler.h"
#include "UnitLoader.h"
#include "UnitTypes/Building.h"
#include "Scripts/NullUnitScript.h"
#include "Scripts/UnitScriptFactory.h"
#include "Scripts/CobInstance.h" // for TAANG2RAD

#include "CommandAI/CommandAI.h"
#include "CommandAI/FactoryCAI.h"
#include "CommandAI/AirCAI.h"
#include "CommandAI/BuilderCAI.h"
#include "CommandAI/CommandAI.h"
#include "CommandAI/FactoryCAI.h"
#include "CommandAI/MobileCAI.h"

#include "ExternalAI/EngineOutHandler.h"
#include "Game/GameHelper.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/Players/Player.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"

#include "Rendering/GroundFlash.h"

#include "Game/UI/Groups/Group.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/MoveTypes/GroundMoveType.h"
#include "Sim/MoveTypes/HoverAirMoveType.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/MoveTypes/MoveTypeFactory.h"
#include "Sim/MoveTypes/ScriptMoveType.h"
#include "Sim/Projectiles/FlareProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/MissileProjectile.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "Sim/Weapons/WeaponLoader.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"
#include "System/creg/DefTypes.h"
#include "System/creg/STL_List.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncedPrimitive.h"
#include "System/Sync/SyncTracer.h"
#include "System/Util.h"


// See end of source for member bindings
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

bool  CUnit::spawnFeature = true;

float CUnit::empDeclineRate = 0.0f;
float CUnit::expMultiplier  = 0.0f;
float CUnit::expPowerScale  = 0.0f;
float CUnit::expHealthScale = 0.0f;
float CUnit::expReloadScale = 0.0f;
float CUnit::expGrade       = 0.0f;


CUnit::CUnit()
: CSolidObject()
, unitDef(nullptr)
, shieldWeapon(nullptr)
, stockpileWeapon(nullptr)
, selfdExpDamages(nullptr)
, deathExpDamages(nullptr)
, soloBuilder(nullptr)
, lastAttacker(nullptr)
, lastAttackFrame(-200)
, lastFireWeapon(0)
, transporter(nullptr)
, transportCapacityUsed(0)
, transportMassUsed(0)
, moveType(nullptr)
, prevMoveType(nullptr)
, commandAI(nullptr)
, script(nullptr)
, los(ILosType::LOS_TYPE_COUNT, nullptr)
, losStatus(teamHandler->ActiveAllyTeams(), 0)
, fpsControlPlayer(nullptr)
, deathSpeed(ZeroVector)
, lastMuzzleFlameDir(UpVector)
, flankingBonusDir(RgtVector)
, posErrorVector(ZeroVector)
, posErrorDelta(ZeroVector)
, featureDefID(-1)
, power(100.0f)
, buildProgress(0.0f)
, paralyzeDamage(0.0f)
, captureProgress(0.0f)
, experience(0.0f)
, limExperience(0.0f)
, neutral(false)
, beingBuilt(true)
, upright(true)
, groundLevelled(true)
, terraformLeft(0.0f)
, lastNanoAdd(gs->frameNum)
, lastFlareDrop(0)
, repairAmount(0.0f)
, loadingTransportId(-1)
, unloadingTransportId(-1)
, inBuildStance(false)
, useHighTrajectory(false)
, dontUseWeapons(false)
, dontFire(false)
, deathScriptFinished(false)
, delayedWreckLevel(-1)
, restTime(0)
, outOfMapTime(0)
, reloadSpeed(1.0f)
, maxRange(0.0f)
, lastMuzzleFlameSize(0.0f)
, armorType(0)
, category(0)
, mapSquare(-1)
, realLosRadius(0)
, realAirLosRadius(0)
, losRadius(0)
, airLosRadius(0)
, radarRadius(0)
, sonarRadius(0)
, jammerRadius(0)
, sonarJamRadius(0)
, seismicRadius(0)
, seismicSignature(0.0f)
, stealth(false)
, sonarStealth(false)
, energyTickMake(0.0f)
, metalExtract(0.0f)
, cost(100.0f, 0.0f)
, buildTime(100.0f)
, recentDamage(0.0f)
, fireState(FIRESTATE_FIREATWILL)
, moveState(MOVESTATE_MANEUVER)
, activated(false)
, isDead(false)
, fallSpeed(0.2f)
, travel(0.0f)
, travelPeriod(0.0f)
, flankingBonusMode(0)
, flankingBonusMobility(10.0f)
, flankingBonusMobilityAdd(0.01f)
, flankingBonusAvgDamage(1.4f)
, flankingBonusDifDamage(0.5f)
, armoredState(false)
, armoredMultiple(1.0f)
, curArmorMultiple(1.0f)
, nextPosErrorUpdate(1)
, isCloaked(false)
, wantCloak(false)
, scriptCloak(0)
, cloakTimeout(128)
, curCloakTimeout(gs->frameNum)
, decloakDistance(0.0f)
, lastTerrainType(-1)
, curTerrainType(0)
, selfDCountdown(0)
, cegDamage(1)

, noMinimap(false)
, leaveTracks(false)
, isSelected(false)
, isIcon(false)
, iconRadius(0.0f)
, lastUnitUpdate(0)
, group(nullptr)
, myTrack(nullptr)
, myIcon(nullptr)

, stunned(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnit::~CUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::InitStatic()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::PreInit(const UnitLoadParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::PostInit(const CUnit* builder)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


//////////////////////////////////////////////////////////////////////
//

void CUnit::FinishedBuilding(bool postInit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::KillUnit(CUnit* attacker, bool selfDestruct, bool reclaimed, bool showDeathSequence)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::ForcedKillUnit(CUnit* attacker, bool selfDestruct, bool reclaimed, bool showDeathSequence)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::ForcedMove(const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



float3 CUnit::GetErrorVector(int argAllyTeam) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::UpdatePosErrorParams(bool updateError, bool updateDelta)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::Drop(const float3& parentPos, const float3& parentDir, CUnit* parent)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::DeleteScript()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::EnableScriptMoveType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::DisableScriptMoveType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::UpdateResources()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::SetLosStatus(int at, unsigned short newStatus)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned short CUnit::CalcLosStatus(int at)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::UpdateLosStatus(int at)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::SetStunned(bool stun) {
	stunned = stun;

	if (moveType->progressState == AMoveType::Active) {
		if (stunned) {
			script->StopMoving();
		} else {
			script->StartMoving(moveType->IsReversing());
		}
	}

	eventHandler.UnitStunned(this, stun);
}


void CUnit::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::CanUpdateWeapons() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::SlowUpdateWeapons()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::HaveTarget() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CUnit::GetFlankingDamageBonus(const float3& attackDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::DoWaterDamage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



static void AddUnitDamageStats(CUnit* unit, float damage, bool dealt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::DoDamage(
	const DamageArray& damages,
	const float3& impulse,
	CUnit* attacker,
	int weaponDefID,
	int projectileID
) {
	if (isDead)
		return;
	if (IsCrashing() || IsInVoid())
		return;

	float baseDamage = damages.Get(armorType);
	float experienceMod = expMultiplier;
	float impulseMult = 1.0f;

	const bool isParalyzer = (damages.paralyzeDamageTime != 0);

	if (baseDamage > 0.0f) {
		if (attacker != NULL) {
			SetLastAttacker(attacker);

			// FIXME -- not the impulse direction?
			baseDamage *= GetFlankingDamageBonus((attacker->pos - pos).SafeNormalize());
		}

		baseDamage *= curArmorMultiple;
		restTime = 0; // bleeding != resting
	}

	if (eventHandler.UnitPreDamaged(this, attacker, baseDamage, weaponDefID, projectileID, isParalyzer, &baseDamage, &impulseMult))
		return;

	script->WorldHitByWeapon(-(float3(impulse * impulseMult)).SafeNormalize2D(), weaponDefID, /*inout*/ baseDamage);
	ApplyImpulse((impulse * impulseMult) / mass);

	if (!isParalyzer) {
		// real damage
		if (baseDamage > 0.0f) {
			// do not log overkill damage (so nukes etc do not inflate values)
			AddUnitDamageStats(attacker, Clamp(maxHealth - health, 0.0f, baseDamage), true);
			AddUnitDamageStats(this, Clamp(maxHealth - health, 0.0f, baseDamage), false);

			health -= baseDamage;
		} else { // healing
			health -= baseDamage;
			health = std::min(health, maxHealth);

			if (health > paralyzeDamage && !modInfo.paralyzeOnMaxHealth) {
				SetStunned(false);
			}
		}
	} else {
		// paralyzation damage (adds reduced experience for the attacker)
		experienceMod *= 0.1f;

		// paralyzeDamage may not get higher than baseHealth * (paralyzeTime + 1),
		// which means the unit will be destunned after <paralyzeTime> seconds.
		// (maximum paralyzeTime of all paralyzer weapons which recently hit it ofc)
		//
		// rate of paralysis-damage reduction is lower if the unit has less than
		// maximum health to ensure stun-time is always equal to <paralyzeTime>
		const float baseHealth = (modInfo.paralyzeOnMaxHealth? maxHealth: health);
		const float paralysisDecayRate = baseHealth * CUnit::empDeclineRate;
		const float sumParalysisDamage = paralysisDecayRate * damages.paralyzeDamageTime;
		const float maxParalysisDamage = std::max(baseHealth + sumParalysisDamage - paralyzeDamage, 0.0f);

		if (baseDamage > 0.0f) {
			// clamp the dealt paralysis-damage to [0, maxParalysisDamage]
			baseDamage = Clamp(baseDamage, 0.0f, maxParalysisDamage);

			// no attacker gains experience from a stunned target
			experienceMod *= (1 - IsStunned());
			// increase the current level of paralysis-damage
			paralyzeDamage += baseDamage;

			if (paralyzeDamage >= baseHealth) {
				SetStunned(true);
			}
		} else {
			// no experience from healing a non-stunned target
			experienceMod *= (paralyzeDamage > 0.0f);
			// decrease ("heal") the current level of paralysis-damage
			paralyzeDamage += baseDamage;
			paralyzeDamage = std::max(paralyzeDamage, 0.0f);

			if (paralyzeDamage <= baseHealth) {
				SetStunned(false);
			}
		}
	}

	recentDamage += baseDamage;

	eventHandler.UnitDamaged(this, attacker, baseDamage, weaponDefID, projectileID, isParalyzer);
	eoh->UnitDamaged(*this, attacker, baseDamage, weaponDefID, projectileID, isParalyzer);

#ifdef TRACE_SYNC
	tracefile << "Damage: ";
	tracefile << id << " " << baseDamage << "\n";
#endif

	if (baseDamage > 0.0f) {
		if ((attacker != NULL) && !teamHandler->Ally(allyteam, attacker->allyteam)) {
			const float scaledExpMod = 0.1f * experienceMod * (power / attacker->power);
			const float scaledDamage = std::max(0.0f, (baseDamage + std::min(0.0f, health))) / maxHealth;
			// alternative
			// scaledDamage = (max(healthPreDamage, 0) - max(health, 0)) / maxHealth

			// FIXME: why is experience added a second time when health <= 0.0f?
			attacker->AddExperience(scaledExpMod * scaledDamage);
		}
	}

	if (health <= 0.0f) {
		KillUnit(attacker, false, false);

		if (!isDead)
			return;
		if (beingBuilt)
			return;
		if (attacker == nullptr)
			return;

		if (!teamHandler->Ally(allyteam, attacker->allyteam)) {
			attacker->AddExperience(expMultiplier * 0.1f * (power / attacker->power));
			teamHandler->Team(attacker->team)->GetCurrentStats().unitsKilled++;
		}
	}
}



void CUnit::ApplyImpulse(const float3& impulse) {
	if (GetTransporter() != NULL) {
		// transfer impulse to unit transporting us, scaled by its mass
		// assume we came here straight from DoDamage, not LuaSyncedCtrl
		GetTransporter()->ApplyImpulse((impulse * mass) / (GetTransporter()->mass));
		return;
	}

	const float3& groundNormal = CGround::GetNormal(pos.x, pos.z);
	const float groundImpulseScale = std::min(0.0f, impulse.dot(groundNormal));
	const float3 modImpulse = impulse - (groundNormal * groundImpulseScale * IsOnGround());

	if (moveType->CanApplyImpulse(modImpulse)) {
		CSolidObject::ApplyImpulse(modImpulse);
	}
}



/******************************************************************************/
/******************************************************************************/

CMatrix44f CUnit::GetTransformMatrix(const bool synced) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void CUnit::AddExperience(float exp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::SetMass(float newMass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::DoSeismicPing(float pingSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::ChangeLos(int losRad, int airRad)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::ChangeTeam(int newteam, ChangeType type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::ChangeTeamReset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::IsIdle() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::AttackUnit(CUnit* targetUnit, bool isUserTarget, bool wantManualFire, bool fpsMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CUnit::AttackGround(const float3& pos, bool isUserTarget, bool wantManualFire, bool fpsMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::DropCurrentAttackTarget()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::SetLastAttacker(CUnit* attacker)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::DependentDied(CObject* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CUnit::UpdatePhysicalState(float eps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::UpdateTerrainType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::CalculateTerrainType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::SetGroup(CGroup* newGroup, bool fromFactory)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

bool CUnit::AddBuildPower(CUnit* builder, float amount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


//////////////////////////////////////////////////////////////////////
//

void CUnit::SetMetalStorage(float newStorage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::SetEnergyStorage(float newStorage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::AllowedReclaim(CUnit* builder) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::UseMetal(float metal)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::AddMetal(float metal, bool useIncomeMultiplier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::UseEnergy(float energy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CUnit::AddEnergy(float energy, bool useIncomeMultiplier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::AddHarvestedMetal(float metal)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::SetStorage(const SResourcePack& newStorage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::HaveResources(const SResourcePack& pack) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::UseResources(const SResourcePack& pack)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::AddResources(const SResourcePack& pack, bool useIncomeMultiplier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool CanDispatch(const CUnit* u, const CTeam* team, const SResourceOrder& order)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void GetScale(const float x1, const float x2, float* scale)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool LimitToFullStorage(const CUnit* u, const CTeam* team, SResourceOrder* order)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::IssueResourceOrder(SResourceOrder* order)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void CUnit::Activate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::Deactivate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CUnit::UpdateWind(float x, float z, float strength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::IncomingMissile(CMissileProjectile* missile)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CUnit::TempHoldFire(int cmdID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::StopAttackingAllyTeam(int ally)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::GetNewCloakState(bool stunCheck) {
	if (stunCheck) {
		if (IsStunned() && isCloaked && scriptCloak <= 3) {
			return false;
		}

		return isCloaked;
	}

	if (scriptCloak >= 3) {
		return true;
	}

	if (wantCloak || (scriptCloak >= 1)) {
		const CUnit* closestEnemy = CGameHelper::GetClosestEnemyUnitNoLosTest(NULL, midPos, decloakDistance, allyteam, unitDef->decloakSpherical, false);
		const float cloakCost = (Square(speed.w) > 0.2f)? unitDef->cloakCostMoving: unitDef->cloakCost;

		if (decloakDistance > 0.0f && closestEnemy != NULL) {
			curCloakTimeout = gs->frameNum + cloakTimeout;
			return false;
		}

		if (isCloaked || (gs->frameNum >= curCloakTimeout)) {
			return ((scriptCloak >= 2) || UseEnergy(cloakCost * 0.5f));
		}
	}

	return false;
}


void CUnit::SlowUpdateCloak(bool stunCheck)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnit::ScriptDecloak(bool updateCloakTimeOut)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

bool CUnit::CanTransport(const CUnit* unit) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::AttachUnit(CUnit* unit, int piece, bool force)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::DetachUnitCore(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::DetachUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnit::DetachUnitFromAir(CUnit* unit, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CUnit::CanLoadUnloadAtPos(const float3& wantedPos, const CUnit* unit, float* wantedHeightPtr) const {
	bool canLoadUnload = false;
	float wantedHeight = GetTransporteeWantedHeight(wantedPos, unit, &canLoadUnload);

	if (wantedHeightPtr != NULL)
		*wantedHeightPtr = wantedHeight;

	return canLoadUnload;
}

float CUnit::GetTransporteeWantedHeight(const float3& wantedPos, const CUnit* unit, bool* allowedPos) const {
	bool isAllowedHeight = true;

	float wantedHeight = unit->pos.y;
	float clampedHeight = wantedHeight;

	const UnitDef* transporteeUnitDef = unit->unitDef;
	const MoveDef* transporteeMoveDef = unit->moveDef;

	if (unit->GetTransporter() != NULL) {
		// if unit is being transported, set <clampedHeight>
		// to the altitude at which to UNload the transportee
		wantedHeight = CGround::GetHeightReal(wantedPos.x, wantedPos.z);
		isAllowedHeight = transporteeUnitDef->CheckTerrainConstraints(transporteeMoveDef, wantedHeight, &clampedHeight);

		if (isAllowedHeight) {
			if (transporteeMoveDef != NULL) {
				// transportee is a mobile ground unit
				switch (transporteeMoveDef->speedModClass) {
					case MoveDef::Ship: {
						wantedHeight = std::max(-transporteeUnitDef->waterline, wantedHeight);
						clampedHeight = wantedHeight;
					} break;
					case MoveDef::Hover: {
						wantedHeight = std::max(0.0f, wantedHeight);
						clampedHeight = wantedHeight;
					} break;
					default: {
					} break;
				}
			} else {
				// transportee is a building or an airplane
				wantedHeight *= (1 - transporteeUnitDef->floatOnWater);
				clampedHeight = wantedHeight;
			}
		}

		if (dynamic_cast<const CBuilding*>(unit) != NULL) {
			// for transported structures, <wantedPos> must be free/buildable
			// (note: TestUnitBuildSquare calls CheckTerrainConstraints again)
			BuildInfo bi(transporteeUnitDef, wantedPos, unit->buildFacing);
			bi.pos = CGameHelper::Pos2BuildPos(bi, true);
			CFeature* f = NULL;

			if (isAllowedHeight && (!CGameHelper::TestUnitBuildSquare(bi, f, -1, true) || f != NULL))
				isAllowedHeight = false;
		}
	}


	float rawContactHeight = clampedHeight + unit->height;
	float modContactHeight = rawContactHeight;

	// *we* must be capable of reaching the point-of-contact height
	// however this check fails for eg. ships that want to (un)load
	// land units on shore --> would require too many special cases
	// therefore restrict its use to transport aircraft
	if (this->moveDef == NULL) {
		isAllowedHeight &= unitDef->CheckTerrainConstraints(NULL, rawContactHeight, &modContactHeight);
	}

	if (allowedPos != NULL) {
		*allowedPos = isAllowedHeight;
	}

	return modContactHeight;
}

short CUnit::GetTransporteeWantedHeading(const CUnit* unit) const {
	if (unit->GetTransporter() == NULL)
		return unit->heading;
	if (dynamic_cast<CHoverAirMoveType*>(moveType) == NULL)
		return unit->heading;
	if (dynamic_cast<const CBuilding*>(unit) == NULL)
		return unit->heading;

	// transported structures want to face a cardinal direction
	return (GetHeadingFromFacing(unit->buildFacing));
}

/******************************************************************************/
/******************************************************************************/


CR_BIND_DERIVED(CUnit, CSolidObject, )
CR_REG_METADATA(CUnit, (
	CR_MEMBER(unitDef),
	CR_MEMBER(featureDefID),

	CR_MEMBER(upright),

	CR_MEMBER(deathSpeed),

	CR_MEMBER(travel),
	CR_MEMBER(travelPeriod),

	CR_MEMBER(power),

	CR_MEMBER(paralyzeDamage),
	CR_MEMBER(captureProgress),
	CR_MEMBER(experience),
	CR_MEMBER(limExperience),

	CR_MEMBER(neutral),

	CR_MEMBER(soloBuilder),
	CR_MEMBER(beingBuilt),
	CR_MEMBER(lastNanoAdd),
	CR_MEMBER(repairAmount),
	CR_MEMBER(transportCapacityUsed),
	CR_MEMBER(transportMassUsed),
	CR_MEMBER(transportedUnits),
	CR_MEMBER(transporter),
	CR_MEMBER(loadingTransportId),
	CR_MEMBER(unloadingTransportId),
	CR_MEMBER(buildProgress),
	CR_MEMBER(groundLevelled),
	CR_MEMBER(terraformLeft),
	CR_MEMBER(realLosRadius),
	CR_MEMBER(realAirLosRadius),

	CR_MEMBER(losStatus),

	CR_MEMBER(inBuildStance),
	CR_MEMBER(useHighTrajectory),

	CR_MEMBER(dontUseWeapons),
	CR_MEMBER(dontFire),

	CR_MEMBER(deathScriptFinished),
	CR_MEMBER(delayedWreckLevel),

	CR_MEMBER(restTime),
	CR_MEMBER(outOfMapTime),

	CR_MEMBER(weapons),
	CR_MEMBER(shieldWeapon),
	CR_MEMBER(stockpileWeapon),
	CR_MEMBER(selfdExpDamages),
	CR_MEMBER(deathExpDamages),

	CR_MEMBER(reloadSpeed),
	CR_MEMBER(maxRange),

	CR_MEMBER(lastMuzzleFlameSize),
	CR_MEMBER(lastMuzzleFlameDir),

	CR_MEMBER(armorType),
	CR_MEMBER(category),

	CR_MEMBER(quads),
	CR_IGNORED(los),

	CR_MEMBER(mapSquare),

	CR_MEMBER(losRadius),
	CR_MEMBER(airLosRadius),

	CR_MEMBER(radarRadius),
	CR_MEMBER(sonarRadius),
	CR_MEMBER(jammerRadius),
	CR_MEMBER(sonarJamRadius),
	CR_MEMBER(seismicRadius),
	CR_MEMBER(seismicSignature),
	CR_MEMBER(stealth),
	CR_MEMBER(sonarStealth),

	CR_MEMBER(moveType),
	CR_MEMBER(prevMoveType),

	CR_MEMBER(fpsControlPlayer),
	CR_MEMBER(commandAI),
	CR_MEMBER(group),

	CR_MEMBER(script),

	CR_MEMBER(resourcesCondUse),
	CR_MEMBER(resourcesCondMake),
	CR_MEMBER(resourcesUncondUse),
	CR_MEMBER(resourcesUncondMake),

	CR_MEMBER(resourcesUse),
	CR_MEMBER(resourcesMake),

	CR_MEMBER(resourcesUseI),
	CR_MEMBER(resourcesMakeI),
	CR_MEMBER(resourcesUseOld),
	CR_MEMBER(resourcesMakeOld),

	CR_MEMBER(storage),

	CR_MEMBER(harvestStorage),
	CR_MEMBER(harvested),

	CR_MEMBER(energyTickMake),
	CR_MEMBER(metalExtract),

	CR_MEMBER(cost),
	CR_MEMBER(buildTime),

	CR_MEMBER(lastAttacker),
	CR_MEMBER(lastAttackFrame),
	CR_MEMBER(lastFireWeapon),
	CR_MEMBER(recentDamage),

	CR_MEMBER(fireState),
	CR_MEMBER(moveState),

	CR_MEMBER(activated),

	CR_MEMBER(curTarget),

	CR_MEMBER(isDead),
	CR_MEMBER(fallSpeed),

	CR_MEMBER(flankingBonusMode),
	CR_MEMBER(flankingBonusDir),
	CR_MEMBER(flankingBonusMobility),
	CR_MEMBER(flankingBonusMobilityAdd),
	CR_MEMBER(flankingBonusAvgDamage),
	CR_MEMBER(flankingBonusDifDamage),

	CR_MEMBER(armoredState),
	CR_MEMBER(armoredMultiple),
	CR_MEMBER(curArmorMultiple),

	CR_MEMBER(posErrorVector),
	CR_MEMBER(posErrorDelta),
	CR_MEMBER(nextPosErrorUpdate),

	CR_MEMBER(wantCloak),
	CR_MEMBER(scriptCloak),
	CR_MEMBER(cloakTimeout),
	CR_MEMBER(curCloakTimeout),
	CR_MEMBER(isCloaked),
	CR_MEMBER(decloakDistance),

	CR_MEMBER(lastTerrainType),
	CR_MEMBER(curTerrainType),

	CR_MEMBER(selfDCountdown),

	CR_MEMBER_UN(myTrack),
	CR_MEMBER_UN(myIcon),

	CR_MEMBER(incomingMissiles),
	CR_MEMBER(lastFlareDrop),

	CR_MEMBER(cegDamage),

	CR_MEMBER_UN(noMinimap),
	CR_MEMBER_UN(leaveTracks),

	CR_MEMBER_UN(isSelected),
	CR_MEMBER_UN(isIcon),
	CR_MEMBER(iconRadius),

	CR_MEMBER(lastUnitUpdate),

	CR_MEMBER_UN(tooltip),

	CR_MEMBER(stunned),

//	CR_MEMBER(expMultiplier),
//	CR_MEMBER(expPowerScale),
//	CR_MEMBER(expHealthScale),
//	CR_MEMBER(expReloadScale),
//	CR_MEMBER(expGrade),

//	CR_MEMBER(empDecline),
//	CR_MEMBER(spawnFeature),

//	CR_MEMBER(model),

	CR_POSTLOAD(PostLoad)
))

CR_BIND(CUnit::TransportedUnit,)

CR_REG_METADATA_SUB(CUnit,TransportedUnit,(
	CR_MEMBER(unit),
	CR_MEMBER(piece)
))
