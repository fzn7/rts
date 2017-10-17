#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "WeaponLoader.h"
#include "BeamLaser.h"
#include "BombDropper.h"
#include "Cannon.h"
#include "DGunWeapon.h"
#include "EmgCannon.h"
#include "FlameThrower.h"
#include "LaserCannon.h"
#include "LightningCannon.h"
#include "MeleeWeapon.h"
#include "MissileLauncher.h"
#include "NoWeapon.h"
#include "PlasmaRepulser.h"
#include "Rifle.h"
#include "StarburstLauncher.h"
#include "TorpedoLauncher.h"
#include "WeaponDef.h"

#include "Game/TraceRay.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

CWeaponLoader*
CWeaponLoader::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CWeaponLoader::LoadWeapons(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CWeapon*
CWeaponLoader::LoadWeapon(CUnit* owner, const UnitDefWeapon* defWeapon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CWeapon*
CWeaponLoader::InitWeapon(CUnit* owner,
                          CWeapon* weapon,
                          const UnitDefWeapon* defWeapon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
