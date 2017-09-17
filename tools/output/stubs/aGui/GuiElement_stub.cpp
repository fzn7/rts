#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GuiElement.h"

#include "Rendering/GL/myGL.h"

namespace agui {

int GuiElement::screensize[2];
int GuiElement::screenoffset[2];

GuiElement::GuiElement(GuiElement* _parent)
  : parent(_parent)
  , fixedSize(false)
  , weight(1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GuiElement::~GuiElement()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GuiElement::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
GuiElement::HandleEvent(const SDL_Event& ev)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
GuiElement::MouseOver(int x, int y) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
GuiElement::MouseOver(float x, float y) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GuiElement::UpdateDisplayGeo(int x, int y, int xOffset, int yOffset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
GuiElement::PixelToGlX(int x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
GuiElement::PixelToGlY(int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
GuiElement::GlToPixelX(float x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
GuiElement::GlToPixelY(float y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GuiElement::AddChild(GuiElement* elem)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GuiElement::SetPos(float x, float y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GuiElement::SetSize(float x, float y, bool fixed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GuiElement::GeometryChange()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
GuiElement::DefaultOpacity() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GuiElement::Move(float x, float y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GuiElement::DrawBox(int how)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
