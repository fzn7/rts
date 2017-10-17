#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CobInstance.h"
#include "CobEngine.h"
#include "CobFile.h"
#include "CobThread.h"

#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/Classes/BubbleProjectile.h"
#include "Rendering/Env/Particles/Classes/HeatCloudProjectile.h"
#include "Rendering/Env/Particles/Classes/MuzzleFlame.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Rendering/Env/Particles/Classes/WakeProjectile.h"
#include "Rendering/Env/Particles/Classes/WreckProjectile.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/PieceProjectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/BeamLaser.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"
#include "System/Util.h"
#include "System/myMath.h"

/******************************************************************************/
/******************************************************************************/

CR_BIND_DERIVED(CCobInstance, CUnitScript, )

CR_REG_METADATA(CCobInstance,
                (CR_MEMBER(staticVars),
                 CR_MEMBER(threads),

                 // loaded from cobFileHandler
                 CR_IGNORED(script),

                 CR_POSTLOAD(PostLoad)))

inline bool
CCobInstance::HasFunction(int id) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Used by creg
CCobInstance::CCobInstance()
  : CUnitScript(nullptr)
  , script(nullptr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCobInstance::~CCobInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::MapScriptToModelPieces(LocalModel* lmodel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::GetFunctionId(const std::string& fname) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCobInstance::HasBlockShot(int weaponNum) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCobInstance::HasTargetWeight(int weaponNum) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CCobInstance::Create()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::Killed()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::WindChanged(float heading, float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::ExtractionRateChanged(float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::RockUnit(const float3& rockDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::HitByWeapon(const float3& hitDir,
                          int weaponDefId,
                          float& inoutDamage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::SetSFXOccupy(int curTerrainType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::QueryLandingPads(std::vector<int>& out_pieces)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::BeginTransport(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::QueryTransport(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::TransportPickup(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::TransportDrop(const CUnit* unit, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::StartBuilding(float heading, float pitch)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::QueryNanoPiece()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::QueryBuildInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::QueryWeapon(int weaponNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::AimWeapon(int weaponNum, float heading, float pitch)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::AimShieldWeapon(CPlasmaRepulser* weapon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::AimFromWeapon(int weaponNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::Shot(int weaponNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCobInstance::BlockShot(int weaponNum, const CUnit* targetUnit, bool userTarget)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CCobInstance::TargetWeight(int weaponNum, const CUnit* targetUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::AnimFinished(AnimType type, int piece, int axis)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::Destroy()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::StartMoving(bool reversing)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::StopMoving()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::StartUnload()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::EndTransport()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::StartBuilding()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::StopBuilding()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::Falling()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::Landed()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::Activate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::Deactivate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::MoveRate(int curRate)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::FireWeapon(int weaponNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CCobInstance::EndBurst(int weaponNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

/**
 * @brief Calls a cob script function
 * @param functionId int cob script function id
 * @param args vector<int> function arguments
 * @param cb ThreadCallbackType Callback action
 * @param cbParam int callback argument
 * @return 0 if the call terminated. If the caller provides a callback and the
 * thread does not terminate, it will continue to run. Otherwise it will be
 * killed. Returns 1 in this case.
 */
int
CCobInstance::RealCall(int functionId,
                       vector<int>& args,
                       ThreadCallbackType cb,
                       int cbParam,
                       int* retCode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int
CCobInstance::Call(const std::string& fname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::Call(const std::string& fname, std::vector<int>& args)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::Call(const std::string& fname, int arg1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::Call(const std::string& fname,
                   std::vector<int>& args,
                   ThreadCallbackType cb,
                   int cbParam,
                   int* retCode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::Call(int id)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::Call(int id, int arg1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::Call(int id, std::vector<int>& args)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::Call(int id,
                   std::vector<int>& args,
                   ThreadCallbackType cb,
                   int cbParam,
                   int* retCode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::RawCall(int fn)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobInstance::RawCall(int fn, std::vector<int>& args)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::ThreadCallback(ThreadCallbackType type, int retCode, int cbParam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CCobInstance::Signal(int signal)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::PlayUnitSound(int snr, int attr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobInstance::ShowScriptError(const std::string& msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
