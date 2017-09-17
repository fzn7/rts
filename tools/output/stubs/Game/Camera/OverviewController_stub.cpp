/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "OverviewController.h"

#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Game/UI/MiniMap.h"
#include "Game/UI/MouseHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Log/ILog.h"

COverviewController::COverviewController()
{
    //stub method
}

void COverviewController::KeyMove(float3 move)
{
    //stub method
}

void COverviewController::MouseMove(float3 move)
{
    //stub method
}

void COverviewController::ScreenEdgeMove(float3 move)
{
    //stub method
}

void COverviewController::MouseWheelMove(float move)
{
    //stub method
}

void COverviewController::SetDir(const float3& newDir)
{
    //stub method
}

void COverviewController::SetPos(const float3& newPos)
{
    //stub method
}

float3 COverviewController::SwitchFrom() const
{
    //stub method
}

void COverviewController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
}

void COverviewController::GetState(StateMap& sm) const
{
    //stub method
}

bool COverviewController::SetState(const StateMap& sm)
{
    //stub method
}
