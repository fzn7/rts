#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifdef free
#undef free
#endif

#include "GLContext.h"

#include <cstddef> // for NULL
#include <list>

using std::list;

struct HookSet
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLContext::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLContext::Free()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLContext::InsertHookSet(Func init, Func free, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GLContext::RemoveHookSet(Func init, Func free, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
