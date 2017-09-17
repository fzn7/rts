#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#ifdef free
#undef free
#endif

#include "GLContext.h"

#include <list>
#include <cstddef> // for NULL

using std::list;


struct HookSet {
	HookSet()
	: init(NULL), free(NULL), data(NULL) {}

	HookSet(GLContext::Func i, GLContext::Func f, void* d)
	: init(i), free(f), data(d) {}

	bool operator==(const HookSet& hs) const
	{
		return ((init == hs.init) && (free == hs.free) && (data == hs.data));
	}

	GLContext::Func init;
	GLContext::Func free;
	void* data;
};


static list<HookSet>& getHooks()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void GLContext::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void GLContext::Free()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void GLContext::InsertHookSet(Func init, Func free, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void GLContext::RemoveHookSet(Func init, Func free, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
