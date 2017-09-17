/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cctype>


#include "KeyCodes.h"
#include "SDL_keycode.h"
#include "System/Log/ILog.h"
#include "System/Platform/SDL1_keysym.h"
#include "System/Util.h"

CKeyCodes* keyCodes = NULL;


int CKeyCodes::GetCode(const std::string& name) const
{
    //stub method
}


std::string CKeyCodes::GetName(int code) const
{
    //stub method
}


std::string CKeyCodes::GetDefaultName(int code) const
{
    //stub method
}


bool CKeyCodes::AddKeySymbol(const std::string& name, int code)
{
    //stub method
}


bool CKeyCodes::IsValidLabel(const std::string& label)
{
    //stub method
}


bool CKeyCodes::IsModifier(int code)
{
    //stub method
}


bool CKeyCodes::IsPrintable(int code)
{
    //stub method
}



void CKeyCodes::AddPair(const std::string& name, const int code, const bool printable)
{
    //stub method
}


CKeyCodes::CKeyCodes()
{
    //stub method
}


void CKeyCodes::Reset()
{
    //stub method
}


void CKeyCodes::PrintNameToCode() const
{
    //stub method
}


void CKeyCodes::PrintCodeToName() const
{
    //stub method
}


void CKeyCodes::SaveUserKeySymbols(FILE* file) const
{
    //stub method
}
