#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Path.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/UI/GuiHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "System/Color.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/ThreadPool.h"

CPathTexture::CPathTexture()
  : CPboInfoTexture("path")
  , isCleared(false)
  //, updateFrame(0)
  , updateProcess(0)
  , lastSelectedPathType(0)
  , forcedPathType(-1)
  , forcedUnitDef(-1)
  , lastUsage(spring_gettime())
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

enum BuildSquareStatus
{
    NOLOS          = 0,
    FREE           = 1,
    OBJECTBLOCKED  = 2,
    TERRAINBLOCKED = 3,
};

static SColor
GetSpeedModColor(const float sm)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const MoveDef*
CPathTexture::GetSelectedMoveDef()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const UnitDef*
CPathTexture::GetCurrentBuildCmdUnitDef()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

GLuint
CPathTexture::GetTexture()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CPathTexture::ShowMoveDef(const int pathType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CPathTexture::ShowUnitDef(const int udefid)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CPathTexture::IsUpdateNeeded()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CPathTexture::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
