/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Building.h"
#include "Game/GameHelper.h"
#include "Map/ReadMap.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitLoader.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CBuilding, CUnit, )

CR_REG_METADATA(CBuilding, )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBuilding::CBuilding()
{
    //stub method
}



void CBuilding::PreInit(const UnitLoadParams& params)
{
    //stub method
}

void CBuilding::PostInit(const CUnit* builder)
{
    //stub method
}


void CBuilding::ForcedMove(const float3& newPos) {
	// heading might have changed if building was dropped from transport
	// (always needs to be axis-aligned because yardmaps are not rotated)
	heading = GetHeadingFromFacing(buildFacing);

	UpdateDirVectors(false);
	SetVelocity(ZeroVector);

	// update quadfield, etc.
	CUnit::ForcedMove(CGameHelper::Pos2BuildPos(BuildInfo(unitDef, newPos, buildFacing), true));

	unitLoader->FlattenGround(this);
}

