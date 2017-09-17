/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Sim/Projectiles/PieceProjectile.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Rendering/Colors.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/Models/3DModel.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/SmokeTrailProjectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"

#define SMOKE_TIME 40

CR_BIND_DERIVED(CPieceProjectile, CProjectile, )
CR_REG_METADATA(CPieceProjectile,(
	CR_SETFLAG(CF_Synced),

	CR_MEMBER(age),
	CR_MEMBER(explFlags),
	CR_IGNORED(dispList),
	CR_IGNORED(omp),
	CR_IGNORED(smokeTrail),
	CR_IGNORED(fireTrailPoints),
	CR_MEMBER(spinVec),
	CR_MEMBER(spinSpeed),
	CR_MEMBER(spinAngle),
	CR_MEMBER(oldSmokePos),
	CR_MEMBER(oldSmokeDir)
))

CPieceProjectile::CPieceProjectile(
	CUnit* owner,
	LocalModelPiece* lmp,
	const float3& pos,
	const float3& speed,
	int flags,
	float radius
):
	CProjectile(pos, speed, owner, true, false, true),
	age(0),
	explFlags(flags),
	dispList((lmp != nullptr) ? lmp->dispListID : 0),
	omp((lmp != nullptr) ? lmp->original : nullptr),
	smokeTrail(NULL)
{
    //stub method
}


void CPieceProjectile::Collision()
{
    //stub method
}


void CPieceProjectile::Collision(CFeature* f)
{
    //stub method
}


void CPieceProjectile::Collision(CUnit* unit)
{
    //stub method
}


void CPieceProjectile::Collision(CUnit* unit, CFeature* feature)
{
    //stub method
}



float3 CPieceProjectile::RandomVertexPos() const
{
    //stub method
}


float CPieceProjectile::GetDrawAngle() const
{
    //stub method
}


void CPieceProjectile::Update()
{
    //stub method
}


void CPieceProjectile::DrawOnMinimap(CVertexArray& lines, CVertexArray& points)
{
    //stub method
}


void CPieceProjectile::Draw()
{
    //stub method
}


int CPieceProjectile::GetProjectilesCount() const
{
    //stub method
}
