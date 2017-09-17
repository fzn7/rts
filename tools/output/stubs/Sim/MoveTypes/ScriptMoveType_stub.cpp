/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "ScriptMoveType.h"

#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitTypes/Building.h"
#include "System/EventHandler.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CScriptMoveType, AMoveType, (NULL))
CR_REG_METADATA(CScriptMoveType, (
	CR_MEMBER(tag),
	CR_MEMBER(extrapolate),
	CR_MEMBER(useRelVel),
	CR_MEMBER(useRotVel),
	CR_MEMBER(drag),
	CR_MEMBER(velVec),
	CR_MEMBER(relVel),
	CR_MEMBER(rot),
	CR_MEMBER(rotVel),
	CR_MEMBER(mins),
	CR_MEMBER(maxs),

	CR_MEMBER(trackSlope),
	CR_MEMBER(trackGround),
	CR_MEMBER(groundOffset),
	CR_MEMBER(gravityFactor),
	CR_MEMBER(windFactor),
	CR_MEMBER(noBlocking), // copy of CSolidObject::PSTATE_BIT_BLOCKING
	CR_MEMBER(gndStop),
	CR_MEMBER(shotStop),
	CR_MEMBER(slopeStop),
	CR_MEMBER(collideStop),
	CR_MEMBER(scriptNotify)
))


CScriptMoveType::CScriptMoveType(CUnit* owner):
	AMoveType(owner),
	tag(0),
	extrapolate(true),
	useRelVel(false),
	useRotVel(false),
	drag(0.0f),
	velVec(ZeroVector),
	relVel(ZeroVector),
	rot(ZeroVector),
	rotVel(ZeroVector),
	mins(-1.0e9f, -1.0e9f, -1.0e9f),
	maxs(+1.0e9f, +1.0e9f, +1.0e9f),
	trackSlope(false),
	trackGround(false),
	groundOffset(0.0f),
	gravityFactor(0.0f),
	windFactor(0.0f),
	noBlocking(false),
	gndStop(false),
	shotStop(false),
	slopeStop(false),
	collideStop(false),
	scriptNotify(0)
{
    //stub method
}


CScriptMoveType::~CScriptMoveType()
{
    //stub method
}


void CScriptMoveType::CheckNotify()
{
    //stub method
}


bool CScriptMoveType::Update()
{
    //stub method
}


void CScriptMoveType::CheckLimits()
{
    //stub method
}


void CScriptMoveType::SetPhysics(const float3& _pos, const float3& _vel, const float3& _rot)
{
    //stub method
}


void CScriptMoveType::SetPosition(const float3& _pos) { owner->Move(_pos, false); }
void CScriptMoveType::SetVelocity(const float3& _vel) { owner->SetVelocityAndSpeed(velVec = _vel); }



void CScriptMoveType::SetRelativeVelocity(const float3& _relVel)
{
    //stub method
}


void CScriptMoveType::SetRotation(const float3& _rot)
{
    //stub method
}


void CScriptMoveType::SetRotationVelocity(const float3& _rotVel)
{
    //stub method
}


void CScriptMoveType::SetHeading(short heading)
{
    //stub method
}


void CScriptMoveType::SetNoBlocking(bool state)
{
    //stub method
}
