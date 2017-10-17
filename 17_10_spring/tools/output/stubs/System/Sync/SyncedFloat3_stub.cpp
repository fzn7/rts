#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SyncedFloat3.h"
#include "System/myMath.h"

#if defined(SYNCDEBUG) || defined(SYNCCHECK)

CR_BIND(SyncedFloat3, )
CR_REG_METADATA(SyncedFloat3, (CR_MEMBER(x), CR_MEMBER(y), CR_MEMBER(z)))

bool
SyncedFloat3::IsInBounds() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SyncedFloat3::ClampInBounds()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SyncedFloat3::ClampInMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif // defined(SYNCDEBUG) || defined(SYNCCHECK)
