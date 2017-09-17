/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "RoamMeshDrawer.h"
#include "Game/Camera.h"
#include "Map/ReadMap.h"
#include "Map/SMF/SMFReadMap.h"
#include "Map/SMF/SMFGroundDrawer.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Rectangle.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"

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



bool CRoamMeshDrawer::forceTessellate[2] = {false, false};



CRoamMeshDrawer::CRoamMeshDrawer(CSMFReadMap* rm, CSMFGroundDrawer* gd)
	: CEventClient("[CRoamMeshDrawer]", 271989, false)
	, smfReadMap(rm)
	, smfGroundDrawer(gd)
	, lastGroundDetail{0, 0}
{
    //stub method
}

CRoamMeshDrawer::~CRoamMeshDrawer()
{
    //stub method
}


/**
 * Retessellates the current terrain
 */
void CRoamMeshDrawer::Update()
{
    //stub method
}



void CRoamMeshDrawer::DrawMesh(const DrawPass::e& drawPass)
{
    //stub method
}

void CRoamMeshDrawer::DrawBorderMesh(const DrawPass::e& drawPass)
{
    //stub method
}

void CRoamMeshDrawer::DrawInMiniMap()
{
    //stub method
}



void CRoamMeshDrawer::Reset(bool shadowPass)
{
    //stub method
}



bool CRoamMeshDrawer::Tessellate(std::vector<Patch>& patches, const CCamera* cam, int viewRadius, bool shadowPass)
{
    //stub method
}



void CRoamMeshDrawer::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
}

