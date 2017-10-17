#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Console.h"

#include "Action.h"
#include "System/Log/ILog.h"

#include <cassert>

void
CommandReceiver::RegisterAction(const std::string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CommandConsole&
CommandConsole::Instance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CommandConsole::AddCommandReceiver(const std::string& name,
                                   CommandReceiver* rec)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CommandConsole::ExecuteAction(const Action& action)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
