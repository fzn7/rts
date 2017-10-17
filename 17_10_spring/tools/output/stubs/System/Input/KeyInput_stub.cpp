#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cctype>

#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_stdinc.h>

#include "KeyInput.h"

#include "System/Log/ILog.h"
/**
 * @brief keys
 *
 * Array of possible keys, and which are being pressed
 */
static std::map<int, bool> keys;
static SDL_Keymod keyMods;

namespace KeyInput {
bool
IsKeyPressed(int idx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SetKeyModState(int mod, bool pressed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
GetKeyModState(int mod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Tests SDL keystates and sets values in key array
 */
void
Update(int currKeycode, int fakeMetaKey)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::map<int, bool>&
GetPressedKeys()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
GetNormalizedKeySymbol(int sym)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ReleaseAllKeys()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
} // namespace KeyInput
