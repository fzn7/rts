#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstdlib>
#include <stdarg.h>

#include "CameraHandler.h"

#include "Action.h"
#include "Camera.h"
#include "Camera/CameraController.h"
#include "Camera/FPSController.h"
#include "Camera/FreeController.h"
#include "Camera/OverheadController.h"
#include "Camera/OverviewController.h"
#include "Camera/RotOverheadController.h"
#include "Camera/SpringController.h"
#include "Players/Player.h"
#include "Rendering/GlobalRendering.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "UI/UnitTracker.h"

static std::string
strformat(const char* fmt, ...)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CONFIG(std::string, CamModeName).defaultValue("");

CONFIG(int, CamMode)
  .defaultValue(CCameraHandler::CAMERA_MODE_SPRING)
  .description(strformat("Defines the used camera. Options are:\n%i = FPS\n%i "
                         "= Overhead\n%i = Spring\n%i = RotOverhead\n%i = "
                         "Free\n%i = Overview",
                         (int)CCameraHandler::CAMERA_MODE_FIRSTPERSON,
                         (int)CCameraHandler::CAMERA_MODE_OVERHEAD,
                         (int)CCameraHandler::CAMERA_MODE_SPRING,
                         (int)CCameraHandler::CAMERA_MODE_ROTOVERHEAD,
                         (int)CCameraHandler::CAMERA_MODE_FREE,
                         (int)CCameraHandler::CAMERA_MODE_OVERVIEW))
  .minimumValue(0)
  .maximumValue(CCameraHandler::CAMERA_MODE_LAST - 1);

CONFIG(float, CamTimeFactor)
  .defaultValue(1.0f)
  .minimumValue(0.0f)
  .description(
    "Scales the speed of camera transitions, e.g. zooming or position change.");

CONFIG(float, CamTimeExponent)
  .defaultValue(4.0f)
  .minimumValue(0.0f)
  .description(
    "Camera transitions happen at lerp(old, new, timeNorm ^ CamTimeExponent).");

CCameraHandler* camHandler = nullptr;

static void
CreateGlobalCams()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
RemoveGlobalCams()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCameraHandler::CCameraHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCameraHandler::~CCameraHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::UpdateController(CPlayer* player,
                                 bool fpsMode,
                                 bool fsEdgeMove,
                                 bool wnEdgeMove)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::UpdateController(CCameraController& camCon,
                                 bool keyMove,
                                 bool wheelMove,
                                 bool edgeMove)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::CameraTransition(float nsecs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::UpdateTransition()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::SetCameraMode(unsigned int newMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::SetCameraMode(const std::string& modeName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCameraHandler::GetModeIndex(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::PushMode()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::PopMode()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::ToggleState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::ToggleOverviewCamera()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::SaveView(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCameraHandler::LoadView(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::GetState(CCameraController::StateMap& sm) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCameraHandler::SetState(const CCameraController::StateMap& sm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCameraHandler::PushAction(const Action& action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCameraHandler::LoadViewData(const ViewData& vd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
