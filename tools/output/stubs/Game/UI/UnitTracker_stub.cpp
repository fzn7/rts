#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "UnitTracker.h"
#include "Game/Camera/FPSController.h"
#include "Game/CameraHandler.h"
#include "Game/Camera.h"
#include "Game/SelectedUnitsHandler.h"
#include "Map/Ground.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"


CUnitTracker unitTracker;


const char* CUnitTracker::modeNames[TrackModeCount] = {
	"Single",
	"Average",
	"Extents"
};


CUnitTracker::CUnitTracker():
	enabled(false),
	firstUpdate(true),
	trackMode(TrackSingle),
	trackUnit(0),
	timeOut(15),
	lastFollowUnit(0),
	lastUpdateTime(0.0f),
	trackPos(500.0f, 100.0f, 500.0f),
	trackDir(FwdVector),
	smoothedRight(RgtVector),
	oldCamDir(RgtVector),
	oldCamPos(500.0f, 500.0f, 500.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CUnitTracker::~CUnitTracker()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitTracker::Disable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CUnitTracker::GetMode() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitTracker::IncMode()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitTracker::SetMode(int mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CUnitTracker::Track()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitTracker::MakeTrackGroup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitTracker::CleanTrackGroup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitTracker::NextUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CUnit* CUnitTracker::GetTrackUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 CUnitTracker::CalcAveragePos() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 CUnitTracker::CalcExtentsPos() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CUnitTracker::SetCam()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
