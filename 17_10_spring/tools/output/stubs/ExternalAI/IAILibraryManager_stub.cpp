#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IAILibraryManager.h"

#include "AIInterfaceKey.h"
#include "AILibraryManager.h"
#include "SkirmishAIKey.h"
#include "System/FileSystem/SimpleParser.h" // for Split()

#include <climits>
#include <cstdio>
#include <cstring>

IAILibraryManager* IAILibraryManager::gAILibraryManager = NULL;

IAILibraryManager*
IAILibraryManager::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IAILibraryManager::Destroy()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IAILibraryManager::OutputAIInterfacesInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SkirmishAIKey
IAILibraryManager::ResolveSkirmishAIKey(
  const SkirmishAIKey& skirmishAIKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IAILibraryManager::OutputSkirmishAIInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
IAILibraryManager::VersionCompare(const std::string& version1,
                                  const std::string& version2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
