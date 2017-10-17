#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Battery.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/ThreadPool.h"
#include <SDL2/SDL_power.h>

CBattery* battery = nullptr;

CBattery::CBattery()
  : CEventClient("[CBattery]", 314160, false)
  , onBattery(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CBattery::~CBattery()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBattery::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CBattery::HasBattery()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
