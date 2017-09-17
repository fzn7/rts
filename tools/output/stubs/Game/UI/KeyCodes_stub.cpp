#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cctype>

#include "KeyCodes.h"
#include "SDL_keycode.h"
#include "System/Log/ILog.h"
#include "System/Platform/SDL1_keysym.h"
#include "System/Util.h"

CKeyCodes* keyCodes = NULL;

int
CKeyCodes::GetCode(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CKeyCodes::GetName(int code) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CKeyCodes::GetDefaultName(int code) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyCodes::AddKeySymbol(const std::string& name, int code)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyCodes::IsValidLabel(const std::string& label)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyCodes::IsModifier(int code)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyCodes::IsPrintable(int code)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CKeyCodes::AddPair(const std::string& name,
                   const int code,
                   const bool printable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CKeyCodes::CKeyCodes()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CKeyCodes::Reset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CKeyCodes::PrintNameToCode() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CKeyCodes::PrintCodeToName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CKeyCodes::SaveUserKeySymbols(FILE* file) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
