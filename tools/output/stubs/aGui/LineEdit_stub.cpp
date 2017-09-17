#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LineEdit.h"

#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "System/Misc/SpringTime.h"

namespace agui {

LineEdit::LineEdit(GuiElement* parent)
  : GuiElement(parent)
  , hasFocus(false)
  , crypt(false)
  , cursorPos(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LineEdit::SetCrypt(bool focus)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LineEdit::SetContent(const std::string& line, bool moveCursor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LineEdit::DrawSelf()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LineEdit::HandleEventSelf(const SDL_Event& ev)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace agui
