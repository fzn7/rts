/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Console.h" 

#include "System/Log/ILog.h"
#include "Action.h"

#include <cassert>


void CommandReceiver::RegisterAction(const std::string& name)
{
    //stub method
}


CommandConsole& CommandConsole::Instance()
{
    //stub method
}

void CommandConsole::AddCommandReceiver(const std::string& name, CommandReceiver* rec)
{
    //stub method
}

bool CommandConsole::ExecuteAction(const Action& action)
{
    //stub method
}

