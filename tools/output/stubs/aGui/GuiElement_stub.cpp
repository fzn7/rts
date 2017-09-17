/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GuiElement.h"

#include "Rendering/GL/myGL.h"

namespace agui
{
    //stub method
}

GuiElement::~GuiElement()
{
    //stub method
}

void GuiElement::Draw()
{
    //stub method
}

bool GuiElement::HandleEvent(const SDL_Event& ev)
{
    //stub method
}

bool GuiElement::MouseOver(int x, int y) const
{
    //stub method
}

bool GuiElement::MouseOver(float x, float y) const
{
    //stub method
}

void GuiElement::UpdateDisplayGeo(int x, int y, int xOffset, int yOffset)
{
    //stub method
}

float GuiElement::PixelToGlX(int x)
{
    //stub method
}

float GuiElement::PixelToGlY(int y)
{
    //stub method
}

float GuiElement::GlToPixelX(float x)
{
    //stub method
}

float GuiElement::GlToPixelY(float y)
{
    //stub method
}

void GuiElement::AddChild(GuiElement* elem)
{
    //stub method
}

void GuiElement::SetPos(float x, float y)
{
    //stub method
}

void GuiElement::SetSize(float x, float y, bool fixed)
{
    //stub method
}

void GuiElement::GeometryChange()
{
    //stub method
}

float GuiElement::DefaultOpacity() const
{
    //stub method
}

void GuiElement::Move(float x, float y)
{
    //stub method
}

void GuiElement::DrawBox(int how)
{
    //stub method
}

}
