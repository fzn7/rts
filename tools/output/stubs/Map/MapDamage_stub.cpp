/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "MapDamage.h"
#include "BasicMapDamage.h"
#include "NoMapDamage.h"
#include "MapInfo.h"
#include "Game/GameSetup.h"

IMapDamage* mapDamage = nullptr;

IMapDamage::IMapDamage():
	disabled(true),
	mapHardness(0.0f)
{
    //stub method
}

IMapDamage* IMapDamage::GetMapDamage()
{
    //stub method
}
