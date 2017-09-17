/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/cstdint.hpp>
#include <SDL_keycode.h>

#include "FreeController.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/GlobalRendering.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/Input/KeyInput.h"
#include "System/myMath.h"

using std::max;
using std::min;

CONFIG(bool, CamFreeEnabled).defaultValue(false);
CONFIG(bool, CamFreeInvertAlt).defaultValue(false);
CONFIG(bool, CamFreeGoForward).defaultValue(false);
CONFIG(float, CamFreeFOV).defaultValue(45.0f);
CONFIG(float, CamFreeScrollSpeed).defaultValue(500.0f);
CONFIG(float, CamFreeGravity).defaultValue(-500.0f).description("When free camera is locked, Gravity will be used if you jump off of a ground ramp.");
CONFIG(float, CamFreeSlide).defaultValue(0.5f);
CONFIG(float, CamFreeGroundOffset).defaultValue(16.0f).description("Determines ground handling for the free camera.\n0 - the camera can move anywhere,\n< 0 - the camera is always offset from the ground height by -CamFreeGroundOffset\n> 0 - the camera can be \"locked\" to the ground by using SHIFT UP_ARROW. (and will use CamFreeGroundOffset as the offset). To release the lock, simply press SHIFT DOWN_ARROW.");
CONFIG(float, CamFreeTiltSpeed).defaultValue(150.0f);
CONFIG(float, CamFreeAutoTilt).defaultValue(150.0f).description("When free camera is locked, AutoTilt will point the camera in the direction of the ground's slope");
CONFIG(float, CamFreeVelTime).defaultValue(1.5f);
CONFIG(float, CamFreeAngVelTime).defaultValue(1.0f);

/******************************************************************************/
/******************************************************************************/
//
//  TODO: - separate speed variable for tracking state
//        - smooth transitions between tracking states and units
//        - improve controls
//        - rename it?  ;-)
//

CFreeController::CFreeController()
: trackRadius(0.0f),
  tracking(false),
  gndLock(false)
{
    //stub method
}


void CFreeController::SetTrackingInfo(const float3& target, float radius)
{
    //stub method
}


void CFreeController::Update()
{
    //stub method
}

float3 CFreeController::GetDir() const
{
    //stub method
}


void CFreeController::KeyMove(float3 move)
{
    //stub method
}


void CFreeController::MouseMove(float3 move)
{
    //stub method
}


void CFreeController::ScreenEdgeMove(float3 move)
{
    //stub method
}


void CFreeController::MouseWheelMove(float move)
{
    //stub method
}


void CFreeController::SetPos(const float3& newPos)
{
    //stub method
}


float3 CFreeController::SwitchFrom() const
{
    //stub method
}


void CFreeController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
}


void CFreeController::GetState(StateMap& sm) const
{
    //stub method
}


bool CFreeController::SetState(const StateMap& sm)
{
    //stub method
}
