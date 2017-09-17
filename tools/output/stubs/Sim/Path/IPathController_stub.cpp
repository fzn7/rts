#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */
#include "IPathController.hpp"
#include "Sim/Units/Unit.h"
#include "System/myMath.h"

IPathController*
IPathController::GetInstance(CUnit* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IPathController::FreeInstance(IPathController* instance)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
GMTDefaultPathController::GetDeltaSpeed(unsigned int pathID,
                                        float targetSpeed,  // unsigned
                                        float currentSpeed, // unsigned
                                        float maxAccRate,   // unsigned
                                        float maxDecRate,   // unsigned
                                        bool wantReverse,
                                        bool isReversing) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if 1
short
GMTDefaultPathController::GetDeltaHeading(unsigned int pathID,
                                          short newHeading,
                                          short oldHeading,
                                          float maxTurnRate) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

static float
TurnAccelerationSign(float turnBrakeDist,
                     short curDeltaHeading,
                     short newDeltaHeading)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

short
GMTDefaultPathController::GetDeltaHeading(unsigned int pathID,
                                          short newHeading,
                                          short oldHeading,
                                          float maxTurnSpeed,
                                          float maxTurnAccel,
                                          float turnBrakeDist,
                                          float* curTurnSpeed) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
GMTDefaultPathController::IgnoreTerrain(const MoveDef& md,
                                        const float3& pos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
