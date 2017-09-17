#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MoveMath.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/MoveTypes/MoveDefHandler.h"

/*
Calculate speed-multiplier for given height and slope data.
*/
float
CMoveMath::GroundSpeedMod(const MoveDef& moveDef, float height, float slope)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CMoveMath::GroundSpeedMod(const MoveDef& moveDef,
                          float height,
                          float slope,
                          float dirSlopeMod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
