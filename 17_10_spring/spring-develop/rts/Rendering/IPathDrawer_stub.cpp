#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */
#include "IPathDrawer.h"
#include "DefaultPathDrawer.h"
#include "Game/SelectedUnitsHandler.h"
#include "QTPFSPathDrawer.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Path/Default/PathManager.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Path/QTPFS/PathManager.hpp"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/EventHandler.h"

IPathDrawer* pathDrawer = NULL;

IPathDrawer*
IPathDrawer::GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IPathDrawer::FreeInstance(IPathDrawer* pd)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

IPathDrawer::IPathDrawer()
  : CEventClient("[IPathDrawer]", 271991, false)
  , enabled(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
IPathDrawer::~IPathDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const MoveDef*
IPathDrawer::GetSelectedMoveDef()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SColor
IPathDrawer::GetSpeedModColor(const float sm)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#if 0
float IPathDrawer::GetSpeedModNoObstacles(const MoveDef* md, int sqx, int sqz) {
	float m = 0.0f;

	const int hmIdx = sqz * mapDims.mapxp1 + sqx;
	const int cnIdx = sqz * mapDims.mapx   + sqx;

	const float height = hm[hmIdx];
	const float slope = 1.0f - cn[cnIdx].y;

	if (md->speedModClass == MoveDef::Ship) {
		// only check water depth
		m = (height >= (-md->depth))? 0.0f: m;
	} else {
		// check depth and slope (if hover, only over land)
		m = std::max(0.0f, 1.0f - (slope / (md->maxSlope + 0.1f)));
		m = (height < (-md->depth))? 0.0f: m;
		m = (height <= 0.0f && md->speedModClass == MoveDef::Hover)? 1.0f: m;
	}

	return m;
}
#endif
