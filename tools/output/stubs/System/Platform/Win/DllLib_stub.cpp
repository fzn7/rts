#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * @brief Windows shared library loader implementation
 * Windows Shared Object loader class implementation
 */

#include "DllLib.h"

/**
 * Attempts to LoadLibrary on the given DLL
 */
DllLib::DllLib(const char* fileName)
  : dll(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Does a FreeLibrary on the given DLL
 */
void
DllLib::Unload()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
DllLib::LoadFailed()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Does a FreeLibrary on the given DLL
 */
DllLib::~DllLib()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Attempts to locate the given symbol with GetProcAddress
 */
void*
DllLib::FindAddress(const char* symbol)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
