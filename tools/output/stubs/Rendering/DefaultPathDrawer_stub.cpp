#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/UI/GuiHandler.h"
#include "Game/UI/MiniMap.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"

// FIXME
#define private public
#include "Sim/Path/Default/IPath.h"
#include "Sim/Path/Default/PathEstimator.h"
#include "Sim/Path/Default/PathFinder.h"
#include "Sim/Path/Default/PathFinderDef.h"
#include "Sim/Path/Default/PathFlowMap.hpp"
#include "Sim/Path/Default/PathHeatMap.hpp"
#include "Sim/Path/Default/PathManager.h"
#undef private

#include "Rendering/DefaultPathDrawer.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Map/InfoTexture/Legacy/LegacyInfoTextureHandler.h"
#include "System/Util.h"
#include "System/myMath.h"

#define PE_EXTRA_DEBUG_OVERLAYS 1

static const SColor buildColors[] = {
    SColor(138, 138, 138), // nolos
    SColor(0, 210, 0),     // free
    SColor(190, 180, 0),   // objblocked
    SColor(210, 0, 0),     // terrainblocked
};

static inline const SColor&
GetBuildColor(const DefaultPathDrawer::BuildSquareStatus& status)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

DefaultPathDrawer::DefaultPathDrawer()
  : IPathDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DefaultPathDrawer::DrawAll() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DefaultPathDrawer::DrawInMiniMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DefaultPathDrawer::UpdateExtraTexture(int extraTex,
                                      int starty,
                                      int endy,
                                      int offset,
                                      unsigned char* texMem) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DefaultPathDrawer::Draw() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DefaultPathDrawer::Draw(const CPathFinderDef* pfd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DefaultPathDrawer::Draw(const CPathFinder* pf) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DefaultPathDrawer::Draw(const CPathEstimator* pe) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
