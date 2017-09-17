#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "seh.h"
#include "System/Platform/CrashHandler.h"
#include <windows.h>

#ifdef _MSC_VER
static const char*
ExceptionName(DWORD exceptionCode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//! defined in System/Platform/Win/CrashHandler.cpp
namespace CrashHandler {
LONG CALLBACK
ExceptionHandler(LPEXCEPTION_POINTERS e);
}

void __cdecl se_translator_function(unsigned int err,
                                    struct _EXCEPTION_POINTERS* ep)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

void
InitializeSEH()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
