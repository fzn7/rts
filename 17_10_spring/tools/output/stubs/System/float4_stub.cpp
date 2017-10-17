#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/float4.h"
#include "System/creg/creg_cond.h"
#include "System/myMath.h"

CR_BIND(float4, )
CR_REG_METADATA(float4,
                (CR_MEMBER(x), CR_MEMBER(y), CR_MEMBER(z), CR_MEMBER(w)))

float4::float4()
  : float3()
  , w(0.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
float4::operator==(const float4& f) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
