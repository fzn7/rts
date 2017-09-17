#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "KeySet.h"
#include "KeyCodes.h"
#include "KeyBindings.h"

#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/Input/KeyInput.h"

#include <SDL_keycode.h>


#define DISALLOW_RELEASE_BINDINGS


/******************************************************************************/
//
// CKeySet
//

void CKeySet::Reset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CKeySet::ClearModifiers()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CKeySet::SetAnyBit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeySet::IsPureModifier() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CKeySet::CKeySet(int k, bool release)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CKeySet::GetString(bool useDefaultKeysym) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeySet::ParseModifier(std::string& s, const std::string& token, const std::string& abbr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeySet::Parse(const std::string& token, bool showerror)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
// CTimedKeyChain
//

void CTimedKeyChain::push_back(const int key, const spring_time t, const bool isRepeat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
