#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Gui.h"
#include "System/Input/InputHandler.h"

#include <SDL_events.h>
#include <boost/bind.hpp>

#include "GuiElement.h"
#include "Rendering/GL/myGL.h"
#include "System/Log/ILog.h"

namespace agui {

Gui::Gui()
  : inputConBlock(inputCon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Gui::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Gui::Clean()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Gui::~Gui()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Gui::AddElement(GuiElement* elem, bool asBackground)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Gui::RmElement(GuiElement* elem)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Gui::UpdateScreenGeometry(int screenx,
                          int screeny,
                          int screenOffsetX,
                          int screenOffsetY)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
Gui::MouseOverElement(const GuiElement* elem, int x, int y) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
Gui::HandleEvent(const SDL_Event& ev)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Gui* gui = NULL;
void
InitGui()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
FreeGui()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
