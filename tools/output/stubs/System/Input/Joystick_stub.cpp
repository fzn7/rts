/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "InputHandler.h"
#include "Joystick.h"

#include <SDL.h>

#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/EventHandler.h"

CONFIG(bool, JoystickEnabled).defaultValue(true).headlessValue(false);
CONFIG(int, JoystickUse).defaultValue(0);

Joystick* stick = NULL;

void InitJoystick()
{
    //stub method
}

void FreeJoystick() {
	if (stick != NULL) {
		delete stick;
		stick = NULL;
	}
}

Joystick::Joystick()
	: myStick(nullptr)
{
    //stub method
}

Joystick::~Joystick()
{
    //stub method
}

bool Joystick::HandleEvent(const SDL_Event& event)
{
    //stub method
}
