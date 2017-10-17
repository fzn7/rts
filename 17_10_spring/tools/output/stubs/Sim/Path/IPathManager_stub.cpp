#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IPathManager.h"
#include "Default/PathManager.h"
#include "QTPFS/PathManager.hpp"
#include "System/Log/ILog.h"

IPathManager* pathManager = NULL;

IPathManager*
IPathManager::GetInstance(unsigned int type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IPathManager::FreeInstance(IPathManager* pm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
