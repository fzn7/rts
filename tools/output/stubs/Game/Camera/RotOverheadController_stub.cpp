#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "RotOverheadController.h"

#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"

CONFIG(float, RotOverheadMouseScale).defaultValue(0.01f);
CONFIG(int, RotOverheadScrollSpeed).defaultValue(10);
CONFIG(bool, RotOverheadEnabled).defaultValue(true).headlessValue(false);
CONFIG(float, RotOverheadFOV).defaultValue(45.0f);

CRotOverheadController::CRotOverheadController()
  : oldHeight(500)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRotOverheadController::KeyMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRotOverheadController::MouseMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRotOverheadController::ScreenEdgeMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRotOverheadController::MouseWheelMove(float move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRotOverheadController::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRotOverheadController::SetPos(const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CRotOverheadController::SwitchFrom() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRotOverheadController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CRotOverheadController::GetState(StateMap& sm) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CRotOverheadController::SetState(const StateMap& sm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
