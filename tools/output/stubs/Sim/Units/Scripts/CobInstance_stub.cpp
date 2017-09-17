/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "CobEngine.h"
#include "CobFile.h"
#include "CobInstance.h"
#include "CobThread.h"

#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/PieceProjectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/BubbleProjectile.h"
#include "Rendering/Env/Particles/Classes/HeatCloudProjectile.h"
#include "Rendering/Env/Particles/Classes/MuzzleFlame.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Rendering/Env/Particles/Classes/WakeProjectile.h"
#include "Rendering/Env/Particles/Classes/WreckProjectile.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/BeamLaser.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "System/Util.h"
#include "System/myMath.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"


/******************************************************************************/
/******************************************************************************/

CR_BIND_DERIVED(CCobInstance, CUnitScript, )

CR_REG_METADATA(CCobInstance, (
	CR_MEMBER(staticVars),
	CR_MEMBER(threads),

	//loaded from cobFileHandler
	CR_IGNORED(script),

	CR_POSTLOAD(PostLoad)
))


inline bool CCobInstance::HasFunction(int id) const
{
    //stub method
}

//Used by creg
CCobInstance::CCobInstance()
	: CUnitScript(nullptr)
	, script(nullptr)
{
    //stub method
}

void CCobInstance::Init()
{
    //stub method
}

void CCobInstance::PostLoad()
{
    //stub method
}


CCobInstance::~CCobInstance()
{
    //stub method
}


void CCobInstance::MapScriptToModelPieces(LocalModel* lmodel)
{
    //stub method
}


int CCobInstance::GetFunctionId(const std::string& fname) const
{
    //stub method
}


bool CCobInstance::HasBlockShot(int weaponNum) const
{
    //stub method
}


bool CCobInstance::HasTargetWeight(int weaponNum) const
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/


void CCobInstance::Create()
{
    //stub method
}



void CCobInstance::Killed()
{
    //stub method
}


void CCobInstance::WindChanged(float heading, float speed)
{
    //stub method
}


void CCobInstance::ExtractionRateChanged(float speed)
{
    //stub method
}


void CCobInstance::RockUnit(const float3& rockDir)
{
    //stub method
}


void CCobInstance::HitByWeapon(const float3& hitDir, int weaponDefId, float& inoutDamage)
{
    //stub method
}


void CCobInstance::SetSFXOccupy(int curTerrainType)
{
    //stub method
}


void CCobInstance::QueryLandingPads(std::vector<int>& out_pieces)
{
    //stub method
}


void CCobInstance::BeginTransport(const CUnit* unit)
{
    //stub method
}


int CCobInstance::QueryTransport(const CUnit* unit)
{
    //stub method
}


void CCobInstance::TransportPickup(const CUnit* unit)
{
    //stub method
}


void CCobInstance::TransportDrop(const CUnit* unit, const float3& pos)
{
    //stub method
}


void CCobInstance::StartBuilding(float heading, float pitch)
{
    //stub method
}


int CCobInstance::QueryNanoPiece()
{
    //stub method
}


int CCobInstance::QueryBuildInfo()
{
    //stub method
}


int CCobInstance::QueryWeapon(int weaponNum)
{
    //stub method
}


void CCobInstance::AimWeapon(int weaponNum, float heading, float pitch)
{
    //stub method
}


void CCobInstance::AimShieldWeapon(CPlasmaRepulser* weapon)
{
    //stub method
}


int CCobInstance::AimFromWeapon(int weaponNum)
{
    //stub method
}


void CCobInstance::Shot(int weaponNum)
{
    //stub method
}


bool CCobInstance::BlockShot(int weaponNum, const CUnit* targetUnit, bool userTarget)
{
    //stub method
}


float CCobInstance::TargetWeight(int weaponNum, const CUnit* targetUnit)
{
    //stub method
}

void CCobInstance::AnimFinished(AnimType type, int piece, int axis)
{
    //stub method
}


void CCobInstance::Destroy() { Call(COBFN_Destroy); }
void CCobInstance::StartMoving(bool reversing) { Call(COBFN_StartMoving, reversing); }
void CCobInstance::StopMoving() { Call(COBFN_StopMoving); }
void CCobInstance::StartUnload() { Call(COBFN_StartUnload); }
void CCobInstance::EndTransport() { Call(COBFN_EndTransport); }
void CCobInstance::StartBuilding() { Call(COBFN_StartBuilding); }
void CCobInstance::StopBuilding() { Call(COBFN_StopBuilding); }
void CCobInstance::Falling() { Call(COBFN_Falling); }
void CCobInstance::Landed() { Call(COBFN_Landed); }
void CCobInstance::Activate() { Call(COBFN_Activate); }
void CCobInstance::Deactivate() { Call(COBFN_Deactivate); }
void CCobInstance::MoveRate(int curRate) { Call(COBFN_MoveRate0 + curRate); }
void CCobInstance::FireWeapon(int weaponNum) { Call(COBFN_FirePrimary + COBFN_Weapon_Funcs * weaponNum); }
void CCobInstance::EndBurst(int weaponNum) { Call(COBFN_EndBurst + COBFN_Weapon_Funcs * weaponNum); }


/******************************************************************************/


/**
 * @brief Calls a cob script function
 * @param functionId int cob script function id
 * @param args vector<int> function arguments
 * @param cb ThreadCallbackType Callback action
 * @param cbParam int callback argument
 * @return 0 if the call terminated. If the caller provides a callback and the thread does not terminate,
 *  it will continue to run. Otherwise it will be killed. Returns 1 in this case.
 */
int CCobInstance::RealCall(int functionId, vector<int>& args, ThreadCallbackType cb, int cbParam, int* retCode)
{
    //stub method
}


/******************************************************************************/


int CCobInstance::Call(const std::string& fname)
{
    //stub method
}

int CCobInstance::Call(const std::string& fname, std::vector<int>& args)
{
    //stub method
}

int CCobInstance::Call(const std::string& fname, int arg1)
{
    //stub method
}

int CCobInstance::Call(const std::string& fname, std::vector<int>& args, ThreadCallbackType cb, int cbParam, int* retCode)
{
    //stub method
}


int CCobInstance::Call(int id)
{
    //stub method
}

int CCobInstance::Call(int id, int arg1)
{
    //stub method
}

int CCobInstance::Call(int id, std::vector<int>& args)
{
    //stub method
}

int CCobInstance::Call(int id, std::vector<int>& args, ThreadCallbackType cb, int cbParam, int* retCode)
{
    //stub method
}


void CCobInstance::RawCall(int fn)
{
    //stub method
}

int CCobInstance::RawCall(int fn, std::vector<int> &args)
{
    //stub method
}

void CCobInstance::ThreadCallback(ThreadCallbackType type, int retCode, int cbParam)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/


void CCobInstance::Signal(int signal)
{
    //stub method
}


void CCobInstance::PlayUnitSound(int snr, int attr)
{
    //stub method
}


void CCobInstance::ShowScriptError(const std::string& msg)
{
    //stub method
}
