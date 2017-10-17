#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Joystick.h"
#include "InputHandler.h"

#include <SDL.h>

#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"

CONFIG(bool, JoystickEnabled).defaultValue(true).headlessValue(false);
CONFIG(int, JoystickUse).defaultValue(0);

Joystick* stick = NULL;

void
InitJoystick()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FreeJoystick()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Joystick::Joystick()
  : myStick(nullptr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Joystick::~Joystick()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
Joystick::HandleEvent(const SDL_Event& event)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
