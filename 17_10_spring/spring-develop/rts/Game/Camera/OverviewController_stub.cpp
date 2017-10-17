#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "OverviewController.h"

#include "Game/UI/MiniMap.h"
#include "Game/UI/MouseHandler.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Log/ILog.h"

COverviewController::COverviewController()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COverviewController::KeyMove(float3 move)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COverviewController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COverviewController::GetState(StateMap& sm) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
COverviewController::SetState(const StateMap& sm)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
