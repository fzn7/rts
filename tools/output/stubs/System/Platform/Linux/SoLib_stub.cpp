#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * Linux, Unix and Mac OS X Shared Object loader class implementation
 */

#include "SoLib.h"
#include <dlfcn.h>

/**
 * Instantiates the loader, attempts to dlopen the
 * shared object lazily.
 */
SoLib::SoLib(const char* fileName) : so(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Just dlcloses the shared object
 */
void SoLib::Unload() {

	if (so != NULL) {
		dlclose(so);
		so = NULL;
	}
}

bool SoLib::LoadFailed() {
	return so == NULL;
}

/**
 * Just dlcloses the shared object
 */
SoLib::~SoLib()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Attempts to locate the symbol address with dlsym
 */
void* SoLib::FindAddress(const char* symbol)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
