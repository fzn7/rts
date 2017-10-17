#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Button.h"

#include "Gui.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "System/Log/ILog.h"

namespace agui {

Button::Button(const std::string& _label, GuiElement* _parent)
  : GuiElement(_parent)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Button::Label(const std::string& _label)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Button::DrawSelf()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
Button::HandleEventSelf(const SDL_Event& ev)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

} // namespace agui
