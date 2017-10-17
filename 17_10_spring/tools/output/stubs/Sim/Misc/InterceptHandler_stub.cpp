#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <limits>

#include "InterceptHandler.h"

#include "Map/Ground.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/EventHandler.h"
#include "System/creg/STL_Deque.h"
#include "System/float3.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CInterceptHandler, CObject, )
CR_REG_METADATA(CInterceptHandler,
                (CR_MEMBER(interceptors), CR_MEMBER(interceptables)))

CInterceptHandler interceptHandler;

void
CInterceptHandler::Update(bool forced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInterceptHandler::AddInterceptorWeapon(CWeapon* weapon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInterceptHandler::RemoveInterceptorWeapon(CWeapon* weapon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInterceptHandler::AddInterceptTarget(CWeaponProjectile* target,
                                      const float3& destination)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInterceptHandler::DependentDied(CObject* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
