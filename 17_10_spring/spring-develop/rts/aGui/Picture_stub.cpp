#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Picture.h"

#include "Rendering/GL/myGL.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Log/ILog.h"

namespace agui {

Picture::Picture(GuiElement* parent)
  : GuiElement(parent)
  , texture(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Picture::Load(const std::string& _file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Picture::DrawSelf()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

} // namespace agui
