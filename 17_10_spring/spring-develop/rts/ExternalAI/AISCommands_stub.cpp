#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Interface/AISCommands.h"
#include "Sim/Units/CommandAI/Command.h"

#include <limits.h>
#include <stdlib.h>

int
toInternalUnitCommandTopic(int aiCmdTopic, const void* sUnitCommandData)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
extractAICommandTopic(const Command* engineCmd, int maxUnits)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
newCommand(void* sUnitCommandData, int sCommandId, int maxUnits, Command* c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
