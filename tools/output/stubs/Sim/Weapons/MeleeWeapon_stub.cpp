#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MeleeWeapon.h"
#include "Sim/Units/Unit.h"
#include "WeaponDef.h"

CR_BIND_DERIVED(CMeleeWeapon, CWeapon, (NULL, NULL))
CR_REG_METADATA(CMeleeWeapon, )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMeleeWeapon::CMeleeWeapon(CUnit* owner, const WeaponDef* def)
  : CWeapon(owner, def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMeleeWeapon::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
