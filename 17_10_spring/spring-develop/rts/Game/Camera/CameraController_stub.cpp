#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CameraController.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Config/ConfigHandler.h"

CONFIG(float, UseDistToGroundForIcons).defaultValue(0.95f);

CCameraController::CCameraController()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCameraController::SetStateBool(const StateMap& sm,
                                const std::string& name,
                                bool& var)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCameraController::SetStateFloat(const StateMap& sm,
                                 const std::string& name,
                                 float& var)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// Uses distance to ground for large angles (near 90 degree),
// and distance to unit for flat angles (near 0 degree),
// when comparing the camera direction to the map surface,
// assuming the map is flat.
bool
CCameraController::GetUseDistToGroundForIcons()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCameraController::SetState(const StateMap& sm)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCameraController::GetState(StateMap& sm) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
