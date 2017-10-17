#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LegacyMeshDrawer.h"
#include "Game/Camera.h"
#include "Map/SMF/SMFGroundDrawer.h"
#include "Map/SMF/SMFReadMap.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "System/Config/ConfigHandler.h"
#include "System/FastMath.h"
#include "System/Util.h"
#include "System/myMath.h"

#define CLAMP(i) Clamp((i), 0, smfReadMap->maxHeightMapIdx)

CLegacyMeshDrawer::CLegacyMeshDrawer(CSMFReadMap* rm, CSMFGroundDrawer* gd)
  : smfReadMap(rm)
  , smfGroundDrawer(gd)
  , viewRadius(4)
  , neededLod(4)
//, waterDrawn(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLegacyMeshDrawer::DrawVertexAQ(CVertexArray* ma, int x, int y, float height)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLegacyMeshDrawer::DrawGroundVertexArrayQ(CVertexArray*& ma)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CLegacyMeshDrawer::BigTexSquareRowVisible(const CCamera* cam, int bty) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLegacyMeshDrawer::FindRange(const CCamera* cam,
                             int& xs,
                             int& xe,
                             int y,
                             int lod)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLegacyMeshDrawer::DoDrawGroundRow(const CCamera* cam, int bty)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLegacyMeshDrawer::UpdateLODParams(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLegacyMeshDrawer::DrawMesh(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLegacyMeshDrawer::DoDrawGroundShadowLOD(int nlod)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLegacyMeshDrawer::DrawShadowMesh()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
