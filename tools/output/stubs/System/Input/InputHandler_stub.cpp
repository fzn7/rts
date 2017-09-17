/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "InputHandler.h"
#include "System/TimeProfiler.h"

InputHandler input;

InputHandler::InputHandler()
{
    //stub method
}

void InputHandler::PushEvent(const SDL_Event& ev)
{
    //stub method
}

void InputHandler::PushEvents()
{
    //stub method
}


boost::signals2::connection InputHandler::AddHandler(SignalType::slot_function_type handler)
{
    //stub method
}
