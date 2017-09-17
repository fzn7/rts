#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/* heavily based on CobInstance.cpp */
#include "UnitScript.h"

#include "CobDefines.h"
#include "CobFile.h"
#include "CobInstance.h"
#include "UnitScriptEngine.h"

#ifndef _CONSOLE

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
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/AAirMoveType.h"
#include "Sim/MoveTypes/GroundMoveType.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/PieceProjectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/FastMath.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"
#include "System/Util.h"
#include "System/myMath.h"

#endif

CR_BIND_INTERFACE(CUnitScript)

CR_REG_METADATA(CUnitScript,
                (CR_MEMBER(unit),
                 CR_MEMBER(busy),
                 CR_MEMBER(anims),

                 // Populated by children
                 CR_IGNORED(pieces),
                 CR_IGNORED(hasSetSFXOccupy),
                 CR_IGNORED(hasRockUnit),
                 CR_IGNORED(hasStartBuilding)))

CR_BIND(CUnitScript::AnimInfo, )

CR_REG_METADATA_SUB(CUnitScript,
                    AnimInfo,
                    (CR_MEMBER(axis),
                     CR_MEMBER(piece),
                     CR_MEMBER(speed),
                     CR_MEMBER(dest),
                     CR_MEMBER(accel),
                     CR_MEMBER(done),
                     CR_MEMBER(hasWaiting)))

CUnitScript::CUnitScript(CUnit* unit)
  : unit(unit)
  , busy(false)
  , hasSetSFXOccupy(false)
  , hasRockUnit(false)
  , hasStartBuilding(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

/**
 * @brief Updates move animations
 * @param cur float value to update
 * @param dest float final value
 * @param speed float max increment per tick
 * @return returns true if destination was reached, false otherwise
 */
bool
CUnitScript::MoveToward(float& cur, float dest, float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Updates turn animations
 * @param cur float value to update
 * @param dest float final value
 * @param speed float max increment per tick
 * @return returns true if destination was reached, false otherwise
 */
bool
CUnitScript::TurnToward(float& cur, float dest, float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Updates spin animations
 * @param cur float value to update
 * @param dest float the final desired speed (NOT the final angle!)
 * @param speed float is updated if it is not equal to dest
 * @param divisor int is the deltatime, it is not added before the call because
 * speed may have to be updated
 * @return true if the desired speed is 0 and it is reached, false otherwise
 */
bool
CUnitScript::DoSpin(float& cur,
                    float dest,
                    float& speed,
                    float accel,
                    int divisor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::TickAnims(int deltaTime,
                       AnimType type,
                       std::vector<AnimInfo>& doneAnims)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Called by the engine when we are registered as animating.
          If we return false there are no active animations left.
 * @param deltaTime int delta time to update
 * @return true if there are still active animations
 */
bool
CUnitScript::Tick(int deltaTime)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CUnitScript::AnimContainerTypeIt
CUnitScript::FindAnim(AnimType type, int piece, int axis)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::RemoveAnim(AnimType type, const AnimContainerTypeIt& animInfoIt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Overwrites old information. This means that threads blocking on turn
// completion  will now wait for this new turn instead. Not sure if this is the
// expected behaviour  Other option would be to kill them. Or perhaps unblock
// them.
void
CUnitScript::AddAnim(AnimType type,
                     int piece,
                     int axis,
                     float speed,
                     float dest,
                     float accel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::Spin(int piece, int axis, float speed, float accel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::StopSpin(int piece, int axis, float decel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::Turn(int piece, int axis, float speed, float destination)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::Move(int piece, int axis, float speed, float destination)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::MoveNow(int piece, int axis, float destination)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::TurnNow(int piece, int axis, float destination)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::SetVisibility(int piece, bool visible)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::EmitSfx(int sfxType, int piece)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::AttachUnit(int piece, int u)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::DropUnit(int u)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Returns true if there was an animation to listen to
bool
CUnitScript::NeedsWait(AnimType type, int piece, int axis)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Flags as defined by the cob standard
void
CUnitScript::Explode(int piece, int flags)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::Shatter(int piece, const float3& pos, const float3& speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::ShowFlare(int piece)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
int
CUnitScript::GetUnitVal(int val, int p1, int p2, int p3, int p4)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::SetUnitVal(int val, int param)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
CUnitScript::ScriptToModel(int scriptPieceNum) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CUnitScript::ModelToScript(int lmodelPieceNum) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CUnitScript::ShowUnitScriptError(const std::string& error)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
