#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Window.h"

#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"

namespace agui {

Window::Window(const std::string& _title, GuiElement* parent)
  : GuiElement(parent)
  , title(_title)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Window::AddChild(GuiElement* elem)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Window::DrawSelf()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
Window::HandleEventSelf(const SDL_Event& ev)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
Window::Opacity() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
