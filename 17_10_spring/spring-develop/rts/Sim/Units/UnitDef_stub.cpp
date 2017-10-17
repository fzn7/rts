#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UnitDef.h"
#include "Game/GameSetup.h"
#include "Lua/LuaParser.h"
#include "Map/MapInfo.h"
#include "Rendering/IconHandler.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/myMath.h"
#include "UnitDefHandler.h"
#include "UnitDefImage.h"

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
    std::cout << __FUNCTION__ << std::endl;
}

UnitDefWeapon::UnitDefWeapon(const WeaponDef* weaponDef,
                             const LuaTable& weaponTable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
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
    std::cout << __FUNCTION__ << std::endl;
}

UnitDef::~UnitDef()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UnitDef::ParseWeaponsTable(const LuaTable& weaponsTable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UnitDef::CreateYardMap(std::string yardMapStr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UnitDef::SetNoCost(bool noCost)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
UnitDef::CheckTerrainConstraints(const MoveDef* moveDef,
                                 float rawHeight,
                                 float* clampedHeight) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
UnitDef::HasBomberWeapon() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
