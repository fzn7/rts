#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "RoamMeshDrawer.h"
#include "Game/Camera.h"
#include "Map/ReadMap.h"
#include "Map/SMF/SMFGroundDrawer.h"
#include "Map/SMF/SMFReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/Rectangle.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"

#ifdef DRAW_DEBUG_IN_MINIMAP
#include "Game/UI/MiniMap.h"
#endif

#include <cmath>

#define LOG_SECTION_ROAM "RoamMeshDrawer"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_ROAM)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_ROAM

bool CRoamMeshDrawer::forceTessellate[2] = { false, false };

CRoamMeshDrawer::CRoamMeshDrawer(CSMFReadMap* rm, CSMFGroundDrawer* gd)
  : CEventClient("[CRoamMeshDrawer]", 271989, false)
  , smfReadMap(rm)
  , smfGroundDrawer(gd)
  , lastGroundDetail{ 0, 0 }
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CRoamMeshDrawer::~CRoamMeshDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Retessellates the current terrain
 */
void
CRoamMeshDrawer::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRoamMeshDrawer::DrawMesh(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRoamMeshDrawer::DrawBorderMesh(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRoamMeshDrawer::DrawInMiniMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRoamMeshDrawer::Reset(bool shadowPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CRoamMeshDrawer::Tessellate(std::vector<Patch>& patches,
                            const CCamera* cam,
                            int viewRadius,
                            bool shadowPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRoamMeshDrawer::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
