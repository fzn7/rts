#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Console.h" 

#include "System/Log/ILog.h"
#include "Action.h"

#include <cassert>


void CommandReceiver::RegisterAction(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CommandConsole& CommandConsole::Instance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CommandConsole::AddCommandReceiver(const std::string& name, CommandReceiver* rec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CommandConsole::ExecuteAction(const Action& action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

