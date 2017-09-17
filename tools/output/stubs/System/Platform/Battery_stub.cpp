/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Battery.h"
#include "System/EventHandler.h"
#include "System/ThreadPool.h"
#include "System/Config/ConfigHandler.h"
#include <SDL2/SDL_power.h>


CBattery* battery = nullptr;


CBattery::CBattery()
	: CEventClient("[CBattery]", 314160, false)
	, onBattery(false)
{
    //stub method
}


CBattery::~CBattery()
{
    //stub method
}


void CBattery::Update()
{
    //stub method
}


bool CBattery::HasBattery()
{
    //stub method
}

