/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "SolidObject.h"
#include "SolidObjectDef.h"
#include "Map/ReadMap.h"
#include "Map/Ground.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "System/myMath.h"

int CSolidObject::deletingRefID = -1;

const float CSolidObject::DEFAULT_MASS = 1e5f;
const float CSolidObject::MINIMUM_MASS = 1e0f; // 1.0f
const float CSolidObject::MAXIMUM_MASS = 1e6f;

CR_BIND_DERIVED_INTERFACE(CSolidObject, CWorldObject)
CR_REG_METADATA(CSolidObject,
(
	CR_MEMBER(health),
	CR_MEMBER(maxHealth),

	CR_MEMBER(mass),
	CR_MEMBER(crushResistance),

	CR_MEMBER(crushable),
	CR_MEMBER(immobile),
	CR_MEMBER(blockEnemyPushing),
	CR_MEMBER(blockHeightChanges),

	CR_MEMBER_UN(noDraw),
	CR_MEMBER_UN(luaDraw),
	CR_MEMBER_UN(noSelect),

	CR_MEMBER(xsize),
	CR_MEMBER(zsize),
 	CR_MEMBER(footprint),
	CR_MEMBER(heading),

	CR_MEMBER(physicalState),
	CR_MEMBER(collidableState),

	CR_MEMBER(team),
	CR_MEMBER(allyteam),

	CR_MEMBER(tempNum),
	CR_MEMBER(lastHitPieceFrame),

	CR_MEMBER(moveDef),

	CR_MEMBER(localModel),
	CR_MEMBER(collisionVolume),
	CR_MEMBER(lastHitPiece),

	CR_IGNORED(groundDecal), // loaded from render*Created

	CR_MEMBER(frontdir),
	CR_MEMBER(rightdir),
	CR_MEMBER(updir),

	CR_MEMBER(relMidPos),
 	CR_MEMBER(relAimPos),
	CR_MEMBER(midPos),
	CR_MEMBER(aimPos),
	CR_MEMBER(mapPos),
	CR_MEMBER(groundBlockPos),

	CR_MEMBER(dragScales),

	CR_MEMBER(drawPos),
	CR_MEMBER(drawMidPos),
	CR_IGNORED(blockMap), // reloaded in CUnit's PostLoad
	CR_MEMBER(yardOpen),

	CR_MEMBER(buildFacing),
	CR_MEMBER(modParams),

	CR_POSTLOAD(PostLoad)

))


CSolidObject::CSolidObject():
	health(0.0f),
	maxHealth(1.0f),

	mass(DEFAULT_MASS),
	crushResistance(0.0f),

	crushable(false),
	immobile(false),
	blockEnemyPushing(true),
	blockHeightChanges(false),

	noDraw(false),
	luaDraw(false),
	noSelect(false),

	xsize(1),
	zsize(1),
	footprint(1, 1),

	heading(0),

	// objects start out non-blocking but fully collidable
	// SolidObjectDef::collidable controls only the SO-bit
	physicalState(PhysicalState(PSTATE_BIT_ONGROUND)),
	collidableState(CollidableState(CSTATE_BIT_SOLIDOBJECTS | CSTATE_BIT_PROJECTILES | CSTATE_BIT_QUADMAPRAYS)),

	team(0),
	allyteam(0),

	tempNum(0),
	lastHitPieceFrame(-1),

	moveDef(nullptr),

	lastHitPiece(nullptr),
	groundDecal(nullptr),

	frontdir( FwdVector),
	rightdir(-RgtVector),
	updir(UpVector),

	midPos(pos),
	mapPos(GetMapPos()),

	dragScales(OnesVector),

	blockMap(nullptr),
	yardOpen(false),
	buildFacing(0)
{
    //stub method
}


void CSolidObject::PostLoad()
{
    //stub method
}


void CSolidObject::UpdatePhysicalState(float eps)
{
    //stub method
}


bool CSolidObject::SetVoidState()
{
    //stub method
}

bool CSolidObject::ClearVoidState()
{
    //stub method
}

void CSolidObject::UpdateVoidState(bool set)
{
    //stub method
}


void CSolidObject::SetMass(float newMass)
{
    //stub method
}


void CSolidObject::UnBlock()
{
    //stub method
}

void CSolidObject::Block()
{
    //stub method
}


YardMapStatus CSolidObject::GetGroundBlockingMaskAtPos(float3 gpos) const
{
    //stub method
}


// FIXME move somewhere else?
int2 CSolidObject::GetMapPos(const float3& position) const
{
    //stub method
}

float3 CSolidObject::GetDragAccelerationVec(const float4& params) const
{
    //stub method
}

float3 CSolidObject::GetWantedUpDir(bool useGroundNormal) const
{
    //stub method
}



void CSolidObject::SetDirVectorsEuler(const float3 angles)
{
    //stub method
}

void CSolidObject::SetHeadingFromDirection()
{
    //stub method
}

void CSolidObject::UpdateDirVectors(bool useGroundNormal)
{
    //stub method
}



void CSolidObject::ForcedSpin(const float3& newDir)
{
    //stub method
}



void CSolidObject::Kill(CUnit* killer, const float3& impulse, bool crushed)
{
    //stub method
}

