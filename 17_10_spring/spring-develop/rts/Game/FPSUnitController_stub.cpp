#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FPSUnitController.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Game/TraceRay.h"
#include "Map/Ground.h"
#include "Net/Protocol/NetProtocol.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/Scripts/CobInstance.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/Weapon.h"
#include "System/myMath.h"
#include "UI/MouseHandler.h"

#include <SDL_mouse.h>

FPSUnitController::FPSUnitController()
  : targetUnit(NULL)
  , controllee(NULL)
  , controller(NULL)
  , viewDir(FwdVector)
  , targetPos(FwdVector)
  , targetDist(1000.0f)
  , forward(false)
  , back(false)
  , left(false)
  , right(false)
  , mouse1(false)
  , mouse2(false)
  , oldHeading(0)
  , oldPitch(0)
  , oldState(255)
  , oldDCpos(ZeroVector)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FPSUnitController::RecvStateUpdate(const unsigned char* buf)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FPSUnitController::SendStateUpdate()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
