/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "CameraController.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Config/ConfigHandler.h"


CONFIG(float, UseDistToGroundForIcons).defaultValue(0.95f);


CCameraController::CCameraController()
{
    //stub method
}



bool CCameraController::SetStateBool(const StateMap& sm,
                                     const std::string& name, bool& var)
{
    //stub method
}


bool CCameraController::SetStateFloat(const StateMap& sm,
                                      const std::string& name, float& var)
{
    //stub method
}

// Uses distance to ground for large angles (near 90 degree),
// and distance to unit for flat angles (near 0 degree),
// when comparing the camera direction to the map surface,
// assuming the map is flat.
bool CCameraController::GetUseDistToGroundForIcons() {
	// dir should already be normalized
	const float rawDot = UpVector.dot(GetDir());
	const float absDot = Clamp(math::fabs(rawDot), 0.0f, 1.0f);

	// dot< switch: flat angle (typical for first person camera)
	// dot>=switch: steep angle (typical for overhead camera)
	return (absDot >= switchVal);
}



bool CCameraController::SetState(const StateMap& sm)
{
    //stub method
}

void CCameraController::GetState(StateMap& sm) const
{
    //stub method
}

