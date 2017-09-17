#include <iostream>
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
    std::cout << _FUNCTION_ << std::endl;
}

void COverviewController::KeyMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverviewController::MouseMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverviewController::ScreenEdgeMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverviewController::MouseWheelMove(float move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverviewController::SetDir(const float3& newDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverviewController::SetPos(const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 COverviewController::SwitchFrom() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverviewController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverviewController::GetState(StateMap& sm) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool COverviewController::SetState(const StateMap& sm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
