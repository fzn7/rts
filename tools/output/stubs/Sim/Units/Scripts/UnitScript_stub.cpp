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
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/FastMath.h"
#include "System/myMath.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"

#endif

CR_BIND_INTERFACE(CUnitScript)

CR_REG_METADATA(CUnitScript, (
	CR_MEMBER(unit),
	CR_MEMBER(busy),
	CR_MEMBER(anims),

	//Populated by children
	CR_IGNORED(pieces),
	CR_IGNORED(hasSetSFXOccupy),
	CR_IGNORED(hasRockUnit),
	CR_IGNORED(hasStartBuilding)
))

CR_BIND(CUnitScript::AnimInfo,)

CR_REG_METADATA_SUB(CUnitScript, AnimInfo,(
		CR_MEMBER(axis),
		CR_MEMBER(piece),
		CR_MEMBER(speed),
		CR_MEMBER(dest),
		CR_MEMBER(accel),
		CR_MEMBER(done),
		CR_MEMBER(hasWaiting)
))


CUnitScript::CUnitScript(CUnit* unit)
	: unit(unit)
	, busy(false)
	, hasSetSFXOccupy(false)
	, hasRockUnit(false)
	, hasStartBuilding(false)
{
    //stub method
}


/******************************************************************************/


/**
 * @brief Updates move animations
 * @param cur float value to update
 * @param dest float final value
 * @param speed float max increment per tick
 * @return returns true if destination was reached, false otherwise
 */
bool CUnitScript::MoveToward(float& cur, float dest, float speed)
{
    //stub method
}


/**
 * @brief Updates turn animations
 * @param cur float value to update
 * @param dest float final value
 * @param speed float max increment per tick
 * @return returns true if destination was reached, false otherwise
 */
bool CUnitScript::TurnToward(float& cur, float dest, float speed)
{
    //stub method
}


/**
 * @brief Updates spin animations
 * @param cur float value to update
 * @param dest float the final desired speed (NOT the final angle!)
 * @param speed float is updated if it is not equal to dest
 * @param divisor int is the deltatime, it is not added before the call because speed may have to be updated
 * @return true if the desired speed is 0 and it is reached, false otherwise
 */
bool CUnitScript::DoSpin(float& cur, float dest, float &speed, float accel, int divisor)
{
    //stub method
}



void CUnitScript::TickAnims(int deltaTime, AnimType type, std::vector<AnimInfo>& doneAnims) {
	switch (type) {
		case AMove: {
			int i = 0;
			while (i < anims[type].size()) {
				AnimInfo& ai = anims[type][i];
				const int piece = ai.piece;

				// NOTE: we should not need to copy-and-set here, because
				// MoveToward/TurnToward/DoSpin modify pos/rot by reference
				float3 pos = pieces[piece]->GetPosition();

				if (MoveToward(pos[ai.axis], ai.dest, ai.speed / (1000 / deltaTime))) {
					ai.done = true;
					if (ai.hasWaiting)
						doneAnims.push_back(ai);

					ai = anims[type].back();
					anims[type].pop_back();
				} else {
					++i;
				}

				pieces[piece]->SetPosition(pos);
			}
		} break;

		case ATurn: {
			int i = 0;
			while (i < anims[type].size()) {
				AnimInfo& ai = anims[type][i];
				const int piece = ai.piece;
				float3 rot = pieces[piece]->GetRotation();

				if (TurnToward(rot[ai.axis], ai.dest, ai.speed / (1000 / deltaTime))) {
					ai.done = true;
					if (ai.hasWaiting)
						doneAnims.push_back(ai);

					ai = anims[type].back();
					anims[type].pop_back();
				} else {
					++i;
				}

				pieces[piece]->SetRotation(rot);
			}
		} break;

		case ASpin: {
			int i = 0;
			while (i < anims[type].size()) {
				AnimInfo& ai = anims[type][i];
				const int piece = ai.piece;
				float3 rot = pieces[piece]->GetRotation();

				if (DoSpin(rot[ai.axis], ai.dest, ai.speed, ai.accel, 1000 / deltaTime)) {
					ai.done = true;
					if (ai.hasWaiting)
						doneAnims.push_back(ai);

					ai = anims[type].back();
					anims[type].pop_back();
				} else {
					++i;
				}

				pieces[piece]->SetRotation(rot);
			}
		} break;

		default: {
		} break;
	}
}

/**
 * @brief Called by the engine when we are registered as animating.
          If we return false there are no active animations left.
 * @param deltaTime int delta time to update
 * @return true if there are still active animations
 */
bool CUnitScript::Tick(int deltaTime)
{
    //stub method
}



CUnitScript::AnimContainerTypeIt CUnitScript::FindAnim(AnimType type, int piece, int axis)
{
    //stub method
}

void CUnitScript::RemoveAnim(AnimType type, const AnimContainerTypeIt& animInfoIt)
{
    //stub method
}


//Overwrites old information. This means that threads blocking on turn completion
//will now wait for this new turn instead. Not sure if this is the expected behaviour
//Other option would be to kill them. Or perhaps unblock them.
void CUnitScript::AddAnim(AnimType type, int piece, int axis, float speed, float dest, float accel)
{
    //stub method
}


void CUnitScript::Spin(int piece, int axis, float speed, float accel)
{
    //stub method
}


void CUnitScript::StopSpin(int piece, int axis, float decel)
{
    //stub method
}


void CUnitScript::Turn(int piece, int axis, float speed, float destination)
{
    //stub method
}


void CUnitScript::Move(int piece, int axis, float speed, float destination)
{
    //stub method
}


void CUnitScript::MoveNow(int piece, int axis, float destination)
{
    //stub method
}


void CUnitScript::TurnNow(int piece, int axis, float destination)
{
    //stub method
}


void CUnitScript::SetVisibility(int piece, bool visible)
{
    //stub method
}

void CUnitScript::EmitSfx(int sfxType, int piece)
{
    //stub method
}


void CUnitScript::AttachUnit(int piece, int u)
{
    //stub method
}


void CUnitScript::DropUnit(int u)
{
    //stub method
}


//Returns true if there was an animation to listen to
bool CUnitScript::NeedsWait(AnimType type, int piece, int axis)
{
    //stub method
}


//Flags as defined by the cob standard
void CUnitScript::Explode(int piece, int flags)
{
    //stub method
}


void CUnitScript::Shatter(int piece, const float3& pos, const float3& speed)
{
    //stub method
}


void CUnitScript::ShowFlare(int piece)
{
    //stub method
}


/******************************************************************************/
int CUnitScript::GetUnitVal(int val, int p1, int p2, int p3, int p4)
{
    //stub method
}


void CUnitScript::SetUnitVal(int val, int param)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int CUnitScript::ScriptToModel(int scriptPieceNum) const {
	if (!PieceExists(scriptPieceNum))
		return -1;

	const LocalModelPiece* smp = GetScriptLocalModelPiece(scriptPieceNum);

	return (smp->GetLModelPieceIndex());
}

int CUnitScript::ModelToScript(int lmodelPieceNum) const {
	LocalModel& lm = unit->localModel;

	if (!lm.HasPiece(lmodelPieceNum))
		return -1;

	const LocalModelPiece* lmp = lm.GetPiece(lmodelPieceNum);

	return (lmp->GetScriptPieceIndex());
}

void CUnitScript::ShowUnitScriptError(const std::string& error)
{
    //stub method
}

