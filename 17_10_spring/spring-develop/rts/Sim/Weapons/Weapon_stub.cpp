#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Weapon.h"
#include "Game/GameHelper.h"
#include "Game/Players/Player.h"
#include "Game/TraceRay.h"
#include "Lua/LuaConfig.h"
#include "Map/Ground.h"
#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/InterceptHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/AAirMoveType.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Scripts/CobInstance.h"
#include "Sim/Units/Scripts/NullUnitScript.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Weapons/Cannon.h"
#include "Sim/Weapons/NoWeapon.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"
#include "System/creg/DefTypes.h"
#include "System/creg/STL_Map.h"
#include "System/myMath.h"
#include "WeaponDefHandler.h"

CR_BIND_DERIVED(CWeapon, CObject, (NULL, NULL))

CR_REG_METADATA(CWeapon,
                (CR_MEMBER(owner),
                 CR_MEMBER(weaponDef),
                 CR_MEMBER(aimFromPiece),
                 CR_MEMBER(muzzlePiece),
                 CR_MEMBER(range),
                 CR_MEMBER(damages),
                 CR_MEMBER(reloadTime),
                 CR_MEMBER(reloadStatus),
                 CR_MEMBER(salvoLeft),
                 CR_MEMBER(salvoDelay),
                 CR_MEMBER(salvoSize),
                 CR_MEMBER(projectilesPerShot),
                 CR_MEMBER(nextSalvo),
                 CR_MEMBER(accuracyError),
                 CR_MEMBER(projectileSpeed),
                 CR_MEMBER(predictSpeedMod),
                 CR_MEMBER(fireSoundId),
                 CR_MEMBER(fireSoundVolume),
                 CR_MEMBER(hasBlockShot),
                 CR_MEMBER(hasTargetWeight),
                 CR_MEMBER(angleGood),
                 CR_MEMBER(avoidTarget),
                 CR_MEMBER(onlyForward),
                 CR_MEMBER(muzzleFlareSize),
                 CR_MEMBER(doTargetGroundPos),
                 CR_MEMBER(noAutoTarget),
                 CR_MEMBER(alreadyWarnedAboutMissingPieces),

                 CR_MEMBER(badTargetCategory),
                 CR_MEMBER(onlyTargetCategory),
                 CR_MEMBER(incomingProjectiles),
                 CR_MEMBER(buildPercent),
                 CR_MEMBER(numStockpiled),
                 CR_MEMBER(numStockpileQued),
                 CR_MEMBER(sprayAngle),

                 CR_MEMBER(lastRequest),
                 CR_MEMBER(lastTargetRetry),

                 CR_MEMBER(slavedTo),
                 CR_MEMBER(maxForwardAngleDif),
                 CR_MEMBER(maxMainDirAngleDif),
                 CR_MEMBER(heightBoostFactor),
                 CR_MEMBER(avoidFlags),
                 CR_MEMBER(collisionFlags),
                 CR_MEMBER(weaponNum),

                 CR_MEMBER(relAimFromPos),
                 CR_MEMBER(aimFromPos),
                 CR_MEMBER(relWeaponMuzzlePos),
                 CR_MEMBER(weaponMuzzlePos),
                 CR_MEMBER(weaponDir),
                 CR_MEMBER(mainDir),
                 CR_MEMBER(wantedDir),
                 CR_MEMBER(lastRequestedDir),
                 CR_MEMBER(salvoError),
                 CR_MEMBER(errorVector),
                 CR_MEMBER(errorVectorAdd),

                 CR_MEMBER(currentTarget),
                 CR_MEMBER(currentTargetPos)))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWeapon::CWeapon(CUnit* owner, const WeaponDef* def)
  : owner(owner)
  , weaponDef(def)
  , weaponNum(-1)
  , aimFromPiece(-1)
  , muzzlePiece(-1)
  , reloadTime(1)
  , reloadStatus(0)
  , range(1)
  , damages(nullptr)
  , projectileSpeed(1)
  , accuracyError(0)
  , sprayAngle(0)
  , salvoDelay(0)
  , salvoSize(1)
  , projectilesPerShot(1)
  , nextSalvo(0)
  , salvoLeft(0)
  , predictSpeedMod(1)
  ,

  hasBlockShot(false)
  , hasTargetWeight(false)
  , angleGood(false)
  , avoidTarget(false)
  , onlyForward(false)
  , doTargetGroundPos(false)
  , noAutoTarget(false)
  , alreadyWarnedAboutMissingPieces(false)
  , badTargetCategory(0)
  , onlyTargetCategory(0xffffffff)
  ,

  buildPercent(0)
  , numStockpiled(0)
  , numStockpileQued(0)
  ,

  lastRequest(0)
  , lastTargetRetry(-100)
  ,

  slavedTo(NULL)
  , maxForwardAngleDif(0.0f)
  , maxMainDirAngleDif(-1.0f)
  , heightBoostFactor(-1.f)
  , avoidFlags(0)
  , collisionFlags(0)
  ,

  relAimFromPos(UpVector)
  , aimFromPos(ZeroVector)
  , relWeaponMuzzlePos(UpVector)
  , weaponMuzzlePos(ZeroVector)
  , weaponDir(ZeroVector)
  , mainDir(FwdVector)
  , wantedDir(UpVector)
  , lastRequestedDir(-UpVector)
  , salvoError(ZeroVector)
  , errorVector(ZeroVector)
  , errorVectorAdd(ZeroVector)
  , muzzleFlareSize(1)
  , fireSoundId(0)
  , fireSoundVolume(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::SetWeaponNum(int num)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline bool
CWeapon::CobBlockShot() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CWeapon::TargetWeight(const CUnit* targetUnit) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::UpdateWeaponPieces(const bool updateAimFrom)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::UpdateWeaponVectors()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::UpdateWantedDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CWeapon::GetPredictedImpactTime(float3 p) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::UpdateAim()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::ReAimWeapon()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::CanFire(bool ignoreAngleGood,
                 bool ignoreTargetType,
                 bool ignoreRequestedDir) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::UpdateFire()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::UpdateStockpile()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::UpdateSalvo()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::Attack(const SWeaponTarget& newTarget)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::SetAttackTarget(const SWeaponTarget& newTarget)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::DropCurrentTarget()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::AllowWeaponAutoTarget() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::AutoTarget()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::SlowUpdate()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::HoldIfTargetInvalid()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::DependentDied(CObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TargetUnderWater(const float3 tgtPos, const SWeaponTarget& target)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TargetInWater(const float3 tgtPos, const SWeaponTarget& target)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::CheckTargetAngleConstraint(const float3 worldTargetDir,
                                    const float3 worldWeaponDir) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CWeapon::GetTargetBorderPos(const CUnit* targetUnit,
                            const float3 rawTargetPos,
                            const float3 rawTargetDir) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TryTarget(const float3 tgtPos,
                   const SWeaponTarget& trg,
                   bool preFire) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TestTarget(const float3 tgtPos, const SWeaponTarget& trg) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TestRange(const float3 tgtPos, const SWeaponTarget& trg) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::HaveFreeLineOfFire(const float3 pos,
                            const SWeaponTarget& trg,
                            bool useMuzzle) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TryTarget(const SWeaponTarget& trg) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TryTargetRotate(const CUnit* unit, bool userTarget, bool manualFire)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TryTargetRotate(float3 pos, bool userTarget, bool manualFire)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWeapon::TryTargetHeading(short heading, const SWeaponTarget& trg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::Init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::Fire(bool scriptCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::UpdateInterceptTarget()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ProjectileParams
CWeapon::GetProjectileParams()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CWeapon::GetRange2D(const float yDiff) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWeapon::StopAttackingAllyTeam(const int ally)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

// NOTE:
//   GUIHandler places (some) user ground-attack orders on the
//   water surface, others on the ocean floor and in both cases
//   without examining weapon abilities (its logic is "obtuse")
//
//   this inconsistency would be hard(er) to fix on the UI side
//   so we must adjust all such target positions in synced code
//
//   see also CommandAI::AdjustGroundAttackCommand
void
CWeapon::AdjustTargetPosToWater(float3& tgtPos, bool attackGround) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CWeapon::GetUnitPositionWithError(const CUnit* unit) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CWeapon::GetUnitLeadTargetPos(const CUnit* unit) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CWeapon::GetLeadVec(const CUnit* unit) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CWeapon::ExperienceErrorScale() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CWeapon::MoveErrorExperience() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CWeapon::GetLeadTargetPos(const SWeaponTarget& target) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
