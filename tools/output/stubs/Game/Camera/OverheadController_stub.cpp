#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <SDL_keycode.h>
#include <boost/cstdint.hpp>

#include "OverheadController.h"

#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Game/UI/MouseHandler.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "System/myMath.h"
#include "System/Log/ILog.h"
#include "System/Config/ConfigHandler.h"
#include "System/Input/KeyInput.h"

CONFIG(float, MiddleClickScrollSpeed).defaultValue(0.01f);
CONFIG(int, OverheadScrollSpeed).defaultValue(10);
CONFIG(float, OverheadTiltSpeed).defaultValue(1.0f);
CONFIG(bool, OverheadEnabled).defaultValue(true).headlessValue(false);
CONFIG(float, OverheadFOV).defaultValue(45.0f);


static const float angleStep = fastmath::HALFPI / 14.f;


COverheadController::COverheadController()
	: flipped(false)
	, height(1500)
	, oldAltHeight(1500)
	, changeAltHeight(true)
	, maxHeight(10000)
	, angle(DEFAULT_ANGLE)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverheadController::KeyMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverheadController::MouseMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverheadController::ScreenEdgeMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void COverheadController::MouseWheelMove(float move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverheadController::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 COverheadController::GetPos() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverheadController::SetPos(const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 COverheadController::SwitchFrom() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverheadController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void COverheadController::GetState(StateMap& sm) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool COverheadController::SetState(const StateMap& sm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
