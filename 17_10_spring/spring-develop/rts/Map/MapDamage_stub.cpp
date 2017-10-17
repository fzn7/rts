#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MapDamage.h"
#include "BasicMapDamage.h"
#include "Game/GameSetup.h"
#include "MapInfo.h"
#include "NoMapDamage.h"

IMapDamage* mapDamage = nullptr;

IMapDamage::IMapDamage()
  : disabled(true)
  , mapHardness(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
