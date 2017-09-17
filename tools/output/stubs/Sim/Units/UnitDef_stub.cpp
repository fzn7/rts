/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UnitDef.h"
#include "UnitDefHandler.h"
#include "UnitDefImage.h"
#include "Game/GameSetup.h"
#include "Lua/LuaParser.h"
#include "Map/MapInfo.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Rendering/IconHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Util.h"

/******************************************************************************/

UnitDefWeapon::UnitDefWeapon()
: def(NULL)
, slavedTo(0)
, maxMainDirAngleDif(-1.0f)
, badTargetCat(0)
, onlyTargetCat(0)
, mainDir(FwdVector)
{
    //stub method
}

UnitDefWeapon::UnitDefWeapon(const WeaponDef* weaponDef) {
	*this = UnitDefWeapon();
	this->def = weaponDef;
}

UnitDefWeapon::UnitDefWeapon(const WeaponDef* weaponDef, const LuaTable& weaponTable) {
	*this = UnitDefWeapon();
	this->def = weaponDef;

	this->slavedTo = weaponTable.GetInt("slaveTo", 0);

	// NOTE:
	//     <maxAngleDif> specifies the full-width arc,
	//     but we want the half-width arc internally
	//     (arcs are always symmetric around mainDir)
	this->maxMainDirAngleDif = math::cos((weaponTable.GetFloat("maxAngleDif", 360.0f) * 0.5f) * (PI / 180.0f));

	const string& btcString = weaponTable.GetString("badTargetCategory", "");
	const string& otcString = weaponTable.GetString("onlyTargetCategory", "");

	this->badTargetCat =                                   CCategoryHandler::Instance()->GetCategories(btcString);
	this->onlyTargetCat = (otcString.empty())? 0xffffffff: CCategoryHandler::Instance()->GetCategories(otcString);

	this->mainDir = weaponTable.GetFloat3("mainDir", FwdVector);
	this->mainDir.SafeNormalize();
}



/******************************************************************************/

UnitDef::UnitDef()
	: SolidObjectDef()
	, cobID(-1)
	, decoyDef(NULL)
	, techLevel(-1)
	, metalUpkeep(0.0f)
	, energyUpkeep(0.0f)
	, metalMake(0.0f)
	, makesMetal(0.0f)
	, energyMake(0.0f)
	, buildTime(0.0f)
	, extractsMetal(0.0f)
	, extractRange(0.0f)
	, windGenerator(0.0f)
	, tidalGenerator(0.0f)
	, metalStorage(0.0f)
	, energyStorage(0.0f)
	, harvestMetalStorage(0.0f)
	, harvestEnergyStorage(0.0f)
	, autoHeal(0.0f)
	, idleAutoHeal(0.0f)
	, idleTime(0)
	, power(0.0f)
	, category(-1)
	, speed(0.0f)
	, rSpeed(0.0f)
	, turnRate(0.0f)
	, turnInPlace(false)
	, turnInPlaceSpeedLimit(0.0f)
	, turnInPlaceAngleLimit(0.0f)
	, collide(false)
	, losHeight(0.0f)
	, radarHeight(0.0f)
	, losRadius(0.0f)
	, airLosRadius(0.0f)
	, radarRadius(0.0f)
	, sonarRadius(0.0f)
	, jammerRadius(0.0f)
	, sonarJamRadius(0.0f)
	, seismicRadius(0.0f)
	, seismicSignature(0.0f)
	, stealth(false)
	, sonarStealth(false)
	, buildRange3D(false)
	, buildDistance(16.0f) // 16.0f is the minimum distance between two 1x1 units
	, buildSpeed(0.0f)
	, reclaimSpeed(0.0f)
	, repairSpeed(0.0f)
	, maxRepairSpeed(0.0f)
	, resurrectSpeed(0.0f)
	, captureSpeed(0.0f)
	, terraformSpeed(0.0f)

	, canSubmerge(false)
	, canfly(false)
	, floatOnWater(false)
	, pushResistant(false)
	, strafeToAttack(false)
	, minCollisionSpeed(0.0f)
	, slideTolerance(0.0f)
	, maxHeightDif(0.0f)
	, waterline(0.0f)
	, minWaterDepth(0.0f)
	, maxWaterDepth(0.0f)
	, pathType(-1U)
	, armoredMultiple(0.0f)
	, armorType(0)
	, flankingBonusMode(0)
	, flankingBonusDir(ZeroVector)
	, flankingBonusMax(0.0f)
	, flankingBonusMin(0.0f)
	, flankingBonusMobilityAdd(0.0f)
	, shieldWeaponDef(NULL)
	, stockpileWeaponDef(NULL)
	, maxWeaponRange(0.0f)
	, maxCoverage(0.0f)
	, deathExpWeaponDef(NULL)
	, selfdExpWeaponDef(NULL)
	, buildPic(NULL)
	, selfDCountdown(0)
	, builder(false)
	, activateWhenBuilt(false)
	, onoffable(false)
	, fullHealthFactory(false)
	, factoryHeadingTakeoff(false)
	, capturable(false)
	, repairable(false)

	, canmove(false)
	, canAttack(false)
	, canFight(false)
	, canPatrol(false)
	, canGuard(false)
	, canRepeat(false)
	, canResurrect(false)
	, canCapture(false)
	, canCloak(false)
	, canSelfD(true)
	, canKamikaze(false)

	, canRestore(false)
	, canRepair(false)
	, canReclaim(false)
	, canAssist(false)

	, canBeAssisted(false)
	, canSelfRepair(false)

	, canFireControl(false)
	, canManualFire(false)

	, fireState(FIRESTATE_HOLDFIRE)
	, moveState(MOVESTATE_HOLDPOS)
	, wingDrag(0.0f)
	, wingAngle(0.0f)
	, frontToSpeed(0.0f)
	, speedToFront(0.0f)
	, myGravity(0.0f)
	, maxBank(0.0f)
	, maxPitch(0.0f)
	, turnRadius(0.0f)
	, wantedHeight(0.0f)
	, verticalSpeed(0.0f)
	, useSmoothMesh(false)
	, hoverAttack(false)
	, airStrafe(false)
	, dlHoverFactor(0.0f)
	, bankingAllowed(false)
	, maxAcc(0.0f)
	, maxDec(0.0f)
	, maxAileron(0.0f)
	, maxElevator(0.0f)
	, maxRudder(0.0f)
	, crashDrag(0.0f)
	, loadingRadius(0.0f)
	, unloadSpread(0.0f)
	, transportCapacity(0)
	, transportSize(0)
	, minTransportSize(0)
	, isAirBase(false)
	, isFirePlatform(false)
	, transportMass(0.0f)
	, minTransportMass(0.0f)
	, holdSteady(false)
	, releaseHeld(false)
	, cantBeTransported(false)
	, transportByEnemy(false)
	, transportUnloadMethod(0)
	, fallSpeed(0.0f)
	, unitFallSpeed(0.0f)
	, startCloaked(false)
	, cloakCost(0.0f)
	, cloakCostMoving(0.0f)
	, decloakDistance(0.0f)
	, decloakSpherical(false)
	, decloakOnFire(false)
	, cloakTimeout(0)
	, kamikazeDist(0.0f)
	, kamikazeUseLOS(false)
	, targfac(false)
	, needGeo(false)
	, isFeature(false)
	, hideDamage(false)
	, showPlayerName(false)
	, highTrajectoryType(0)
	, noChaseCategory(0)
	, canDropFlare(false)
	, flareReloadTime(0.0f)
	, flareEfficiency(0.0f)
	, flareDelay(0.0f)
	, flareDropVector(ZeroVector)
	, flareTime(0)
	, flareSalvoSize(0)
	, flareSalvoDelay(0)
	, canLoopbackAttack(false)
	, levelGround(false)
	, showNanoFrame(false)
	, showNanoSpray(false)
	, nanoColor(ZeroVector)
	, maxThisUnit(0)
	, realMetalCost(0.0f)
	, realEnergyCost(0.0f)
	, realMetalUpkeep(0.0f)
	, realEnergyUpkeep(0.0f)
	, realBuildTime(0.0f)
{
    //stub method
}


UnitDef::UnitDef(const LuaTable& udTable, const std::string& unitName, int id)
{
    //stub method
}


UnitDef::~UnitDef()
{
    //stub method
}



void UnitDef::ParseWeaponsTable(const LuaTable& weaponsTable)
{
    //stub method
}



void UnitDef::CreateYardMap(std::string yardMapStr)
{
    //stub method
}



void UnitDef::SetNoCost(bool noCost)
{
    //stub method
}

bool UnitDef::CheckTerrainConstraints(const MoveDef* moveDef, float rawHeight, float* clampedHeight) const {
	// can fail if LuaMoveCtrl has changed a unit's MoveDef (UnitDef::pathType is not updated)
	// assert(pathType == -1u || moveDef == moveDefHandler->GetMoveDefByPathType(pathType));

	float minDepth = MoveDef::GetDefaultMinWaterDepth();
	float maxDepth = MoveDef::GetDefaultMaxWaterDepth();

	if (moveDef != NULL) {
		// we are a mobile ground-unit, use MoveDef limits
		if (moveDef->speedModClass == MoveDef::Ship) {
			minDepth = moveDef->depth;
		} else {
			maxDepth = moveDef->depth;
		}
	} else {
		if (!canfly) {
			// we are a building, use UnitDef limits
			minDepth = this->minWaterDepth;
			maxDepth = this->maxWaterDepth;
		} else {
			maxDepth *= canSubmerge;
			maxDepth *= (1 - floatOnWater);
		}
	}

	if (clampedHeight != NULL) {
		*clampedHeight = Clamp(rawHeight, -maxDepth, -minDepth);
	}

	// <rawHeight> must lie in the range [-maxDepth, -minDepth]
	return (rawHeight >= -maxDepth && rawHeight <= -minDepth);
}

bool UnitDef::HasBomberWeapon() const {
	if (weapons.empty()) { return false; }
	if (weapons[0].def == NULL) { return false; }
	return
		weapons[0].def->type == "AircraftBomb" ||
		weapons[0].def->type == "TorpedoLauncher";
}

/******************************************************************************/
