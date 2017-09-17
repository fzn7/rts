#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "InputHandler.h"
#include "System/TimeProfiler.h"

InputHandler input;

InputHandler::InputHandler() {}

void
InputHandler::PushEvent(const SDL_Event& ev)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
InputHandler::PushEvents()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::signals2::connection
InputHandler::AddHandler(SignalType::slot_function_type handler)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
