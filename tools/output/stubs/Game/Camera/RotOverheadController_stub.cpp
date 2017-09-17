/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "RotOverheadController.h"

#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "System/myMath.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"

CONFIG(float, RotOverheadMouseScale).defaultValue(0.01f);
CONFIG(int, RotOverheadScrollSpeed).defaultValue(10);
CONFIG(bool, RotOverheadEnabled).defaultValue(true).headlessValue(false);
CONFIG(float, RotOverheadFOV).defaultValue(45.0f);


CRotOverheadController::CRotOverheadController()
	: oldHeight(500)
{
    //stub method
}


void CRotOverheadController::KeyMove(float3 move)
{
    //stub method
}


void CRotOverheadController::MouseMove(float3 move)
{
    //stub method
}


void CRotOverheadController::ScreenEdgeMove(float3 move)
{
    //stub method
}


void CRotOverheadController::MouseWheelMove(float move)
{
    //stub method
}

void CRotOverheadController::Update()
{
    //stub method
}

void CRotOverheadController::SetPos(const float3& newPos)
{
    //stub method
}


float3 CRotOverheadController::SwitchFrom() const
{
    //stub method
}


void CRotOverheadController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
}


void CRotOverheadController::GetState(StateMap& sm) const
{
    //stub method
}


bool CRotOverheadController::SetState(const StateMap& sm)
{
    //stub method
}

