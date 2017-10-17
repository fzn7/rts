#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "VerticalLayout.h"

#include "Rendering/GL/myGL.h"

namespace agui {

VerticalLayout::VerticalLayout(GuiElement* parent)
  : GuiElement(parent)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
VerticalLayout::GeometryChangeSelf()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
