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
}


CUnitTracker::~CUnitTracker()
{
    //stub method
}


void CUnitTracker::Disable()
{
    //stub method
}


int CUnitTracker::GetMode() const
{
    //stub method
}


void CUnitTracker::IncMode()
{
    //stub method
}


void CUnitTracker::SetMode(int mode)
{
    //stub method
}


/******************************************************************************/

void CUnitTracker::Track()
{
    //stub method
}


void CUnitTracker::MakeTrackGroup()
{
    //stub method
}


void CUnitTracker::CleanTrackGroup()
{
    //stub method
}


void CUnitTracker::NextUnit()
{
    //stub method
}


CUnit* CUnitTracker::GetTrackUnit()
{
    //stub method
}


float3 CUnitTracker::CalcAveragePos() const
{
    //stub method
}


float3 CUnitTracker::CalcExtentsPos() const
{
    //stub method
}


/******************************************************************************/

void CUnitTracker::SetCam()
{
    //stub method
}
