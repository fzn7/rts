#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Path.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/UI/GuiHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "System/Color.h"
#include "System/Exceptions.h"
#include "System/ThreadPool.h"
#include "System/Log/ILog.h"



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
    std::cout << _FUNCTION_ << std::endl;
}


enum BuildSquareStatus {
	NOLOS          = 0,
	FREE           = 1,
	OBJECTBLOCKED  = 2,
	TERRAINBLOCKED = 3,
};


static const SColor buildColors[] = {
	SColor(  0,   0,   0), // nolos
	SColor(  0, 255,   0), // free
	SColor(  0,   0, 255), // objblocked
	SColor(254,   0,   0), // terrainblocked
};


static inline const SColor& GetBuildColor(const BuildSquareStatus& status) {
	return buildColors[status];
}


static SColor GetSpeedModColor(const float sm) {
	SColor col(255, 0, 0);
	if (sm > 0.0f) {
		col.r = 255 - std::min(sm * 255.0f, 255.0f);
		col.g = 255 - col.r;
	}
	return col;
}


const MoveDef* CPathTexture::GetSelectedMoveDef()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const UnitDef* CPathTexture::GetCurrentBuildCmdUnitDef()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


GLuint CPathTexture::GetTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CPathTexture::ShowMoveDef(const int pathType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CPathTexture::ShowUnitDef(const int udefid)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CPathTexture::IsUpdateNeeded()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPathTexture::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
