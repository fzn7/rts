#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TextElement.h"

#include "Rendering/Fonts/glFont.h"

namespace agui {

TextElement::TextElement(const std::string& _text, GuiElement* parent)
  : GuiElement(parent)
  , text(_text)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TextElement::DrawSelf()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
