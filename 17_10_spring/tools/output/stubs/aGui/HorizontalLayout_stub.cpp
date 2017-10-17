#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "HorizontalLayout.h"

#include "Rendering/GL/myGL.h"

namespace agui {

HorizontalLayout::HorizontalLayout(GuiElement* parent)
  : GuiElement(parent)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
HorizontalLayout::GeometryChangeSelf()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
