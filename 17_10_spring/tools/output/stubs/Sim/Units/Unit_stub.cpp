#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Unit.h"
#include "Scripts/CobInstance.h" // for TAANG2RAD
#include "Scripts/NullUnitScript.h"
#include "Scripts/UnitScriptFactory.h"
#include "UnitDef.h"
#include "UnitDefHandler.h"
#include "UnitHandler.h"
#include "UnitLoader.h"
#include "UnitTypes/Building.h"

#include "CommandAI/AirCAI.h"
#include "CommandAI/BuilderCAI.h"
#include "CommandAI/CommandAI.h"
#include "CommandAI/FactoryCAI.h"
#include "CommandAI/MobileCAI.h"

#include "ExternalAI/EngineOutHandler.h"
#include "Game/GameHelper.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/SelectedUnitsHandler.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"

#include "Rendering/GroundFlash.h"

#include "Game/UI/Groups/Group.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
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
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"
#include "System/Sync/SyncedPrimitive.h"
#include "System/Util.h"
#include "System/creg/DefTypes.h"
#include "System/creg/STL_List.h"
#include "System/myMath.h"

// See end of source for member bindings
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

bool CUnit::spawnFeature = true;

float CUnit::empDeclineRate = 0.0f;
float CUnit::expMultiplier = 0.0f;
float CUnit::expPowerScale = 0.0f;
float CUnit::expHealthScale = 0.0f;
float CUnit::expReloadScale = 0.0f;
float CUnit::expGrade = 0.0f;

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

void
CUnit::InitStatic()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::PreInit(const UnitLoadParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::PostInit(const CUnit* builder)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
//

void
CUnit::FinishedBuilding(bool postInit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::KillUnit(CUnit* attacker,
                bool selfDestruct,
                bool reclaimed,
                bool showDeathSequence)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::ForcedKillUnit(CUnit* attacker,
                      bool selfDestruct,
                      bool reclaimed,
                      bool showDeathSequence)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::ForcedMove(const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CUnit::GetErrorVector(int argAllyTeam) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::UpdatePosErrorParams(bool updateError, bool updateDelta)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::Drop(const float3& parentPos, const float3& parentDir, CUnit* parent)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::DeleteScript()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::EnableScriptMoveType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::DisableScriptMoveType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::UpdateResources()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SetLosStatus(int at, unsigned short newStatus)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned short
CUnit::CalcLosStatus(int at)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::UpdateLosStatus(int at)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SetStunned(bool stun)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::CanUpdateWeapons() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SlowUpdateWeapons()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::HaveTarget() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CUnit::GetFlankingDamageBonus(const float3& attackDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::DoWaterDamage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
AddUnitDamageStats(CUnit* unit, float damage, bool dealt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::DoDamage(const DamageArray& damages,
                const float3& impulse,
                CUnit* attacker,
                int weaponDefID,
                int projectileID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::ApplyImpulse(const float3& impulse)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

CMatrix44f
CUnit::GetTransformMatrix(const bool synced) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CUnit::AddExperience(float exp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SetMass(float newMass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::DoSeismicPing(float pingSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::ChangeLos(int losRad, int airRad)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::ChangeTeam(int newteam, ChangeType type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::ChangeTeamReset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::IsIdle() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::AttackUnit(CUnit* targetUnit,
                  bool isUserTarget,
                  bool wantManualFire,
                  bool fpsMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::AttackGround(const float3& pos,
                    bool isUserTarget,
                    bool wantManualFire,
                    bool fpsMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::DropCurrentAttackTarget()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SetLastAttacker(CUnit* attacker)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::DependentDied(CObject* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::UpdatePhysicalState(float eps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::UpdateTerrainType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::CalculateTerrainType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::SetGroup(CGroup* newGroup, bool fromFactory)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
CUnit::AddBuildPower(CUnit* builder, float amount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
//

void
CUnit::SetMetalStorage(float newStorage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SetEnergyStorage(float newStorage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::AllowedReclaim(CUnit* builder) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::UseMetal(float metal)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::AddMetal(float metal, bool useIncomeMultiplier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::UseEnergy(float energy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::AddEnergy(float energy, bool useIncomeMultiplier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::AddHarvestedMetal(float metal)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SetStorage(const SResourcePack& newStorage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::HaveResources(const SResourcePack& pack) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::UseResources(const SResourcePack& pack)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::AddResources(const SResourcePack& pack, bool useIncomeMultiplier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
CanDispatch(const CUnit* u, const CTeam* team, const SResourceOrder& order)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
GetScale(const float x1, const float x2, float* scale)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
LimitToFullStorage(const CUnit* u, const CTeam* team, SResourceOrder* order)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::IssueResourceOrder(SResourceOrder* order)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CUnit::Activate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::Deactivate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::UpdateWind(float x, float z, float strength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::IncomingMissile(CMissileProjectile* missile)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::TempHoldFire(int cmdID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::StopAttackingAllyTeam(int ally)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::GetNewCloakState(bool stunCheck)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::SlowUpdateCloak(bool stunCheck)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnit::ScriptDecloak(bool updateCloakTimeOut)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
CUnit::CanTransport(const CUnit* unit) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::AttachUnit(CUnit* unit, int piece, bool force)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::DetachUnitCore(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::DetachUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::DetachUnitFromAir(CUnit* unit, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CUnit::CanLoadUnloadAtPos(const float3& wantedPos,
                          const CUnit* unit,
                          float* wantedHeightPtr) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CUnit::GetTransporteeWantedHeight(const float3& wantedPos,
                                  const CUnit* unit,
                                  bool* allowedPos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

short
CUnit::GetTransporteeWantedHeading(const CUnit* unit) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

CR_BIND_DERIVED(CUnit, CSolidObject, )
CR_REG_METADATA(CUnit,
                (CR_MEMBER(unitDef),
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

                 CR_POSTLOAD(PostLoad)))

CR_BIND(CUnit::TransportedUnit, )

CR_REG_METADATA_SUB(CUnit, TransportedUnit, (CR_MEMBER(unit), CR_MEMBER(piece)))
