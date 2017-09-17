#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/float3.h"
#include "System/creg/creg_cond.h"
#include "System/myMath.h"

CR_BIND(float3, )
CR_REG_METADATA(float3, (CR_MEMBER(x), CR_MEMBER(y), CR_MEMBER(z)))

//! gets initialized later when the map is loaded
float float3::maxxpos = -1.0f;
float float3::maxzpos = -1.0f;

bool float3::IsInBounds() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void float3::ClampInBounds()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool float3::IsInMap() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void float3::ClampInMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 float3::min(const float3 v1, const float3 v2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 float3::max(const float3 v1, const float3 v2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 float3::fabs(const float3 v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool float3::equals(const float3& f, const float3& eps) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

