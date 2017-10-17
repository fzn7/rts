#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <SDL_keycode.h>
#include <boost/cstdint.hpp>

#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Game/UI/MouseHandler.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "SpringController.h"
#include "System/Config/ConfigHandler.h"
#include "System/Input/KeyInput.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"

CONFIG(bool, CamSpringEnabled).defaultValue(true).headlessValue(false);
CONFIG(int, CamSpringScrollSpeed).defaultValue(10);
CONFIG(float, CamSpringFOV).defaultValue(45.0f);
CONFIG(bool, CamSpringLockCardinalDirections)
  .defaultValue(true)
  .description("Whether cardinal directions should be `locked` for a short "
               "time when rotating.");
CONFIG(bool, CamSpringZoomInToMousePos).defaultValue(true);
CONFIG(bool, CamSpringZoomOutFromMousePos).defaultValue(false);
CONFIG(bool, CamSpringEdgeRotate)
  .defaultValue(false)
  .description("Rotate camera when cursor touches screen borders.");

CSpringController::CSpringController()
  : rot(2.677f, 0.f, 0.f)
  , curDist(float3(mapDims.mapx * 0.5f, 0.0f, mapDims.mapy * 0.55f).Length2D() *
            1.5f * SQUARE_SIZE)
  , maxDist(std::max(mapDims.mapx, mapDims.mapy) * SQUARE_SIZE * 1.333f)
  , oldDist(0.f)
  , zoomBack(false)
  , cursorZoomIn(configHandler->GetBool("CamSpringZoomInToMousePos"))
  , cursorZoomOut(configHandler->GetBool("CamSpringZoomOutFromMousePos"))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSpringController::KeyMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSpringController::MouseMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSpringController::ScreenEdgeMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSpringController::MouseWheelMove(float move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CSpringController::ZoomIn(const float3& curCamPos, const float2& zoomParams)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CSpringController::ZoomOut(const float3& curCamPos, const float2& zoomParams)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSpringController::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static float
GetRotationWithCardinalLock(float rot)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CSpringController::MoveAzimuth(float move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CSpringController::GetAzimuth() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CSpringController::GetPos() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSpringController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSpringController::GetState(StateMap& sm) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSpringController::SetState(const StateMap& sm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
