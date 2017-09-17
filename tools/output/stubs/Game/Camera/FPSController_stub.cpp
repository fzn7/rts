#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "FPSController.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"

using std::min;
using std::max;

CONFIG(int, FPSScrollSpeed).defaultValue(10);
CONFIG(float, FPSMouseScale).defaultValue(0.01f);
CONFIG(bool, FPSEnabled).defaultValue(true);
CONFIG(float, FPSFOV).defaultValue(45.0f);


CFPSController::CFPSController()
	: oldHeight(300)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::KeyMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::MouseMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::ScreenEdgeMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::MouseWheelMove(float move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::SetPos(const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::SetDir(const float3& newDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 CFPSController::SwitchFrom() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFPSController::GetState(StateMap& sm) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CFPSController::SetState(const StateMap& sm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


