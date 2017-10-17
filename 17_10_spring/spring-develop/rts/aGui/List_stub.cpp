#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "List.h"

#include <SDL_mouse.h>

#include "Game/GlobalUnsynced.h"
#include "Game/UI/MouseHandler.h"
#include "Gui.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "System/Util.h"

namespace agui {

const float itemFontScale = 1.0f;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

List::List(GuiElement* parent)
  : GuiElement(parent)
  , cancelPlace(-1)
  , tooltip("No tooltip defined")
  , clickedTime(spring_now())
  , place(0)
  , activeMousePress(false)
  , activeScrollbar(false)
  , scrollbarGrabPos(0.0f)
  , filteredItems(&items)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

List::~List() {}

void
List::SetFocus(bool focus)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::RemoveAllItems()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::RefreshQuery()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::AddItem(const std::string& name, const std::string& description)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
List::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
List::NumDisplay()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::ScrollUpOne()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::ScrollDownOne()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
List::ScaleFactor()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::UpdateTopIndex()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
List::MouseUpdate(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::DrawSelf()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
List::HandleEventSelf(const SDL_Event& ev)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::UpOne()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::DownOne()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::UpPage()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::DownPage()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
List::GetCurrentItem() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
List::SetCurrentItem(const std::string& newCurrent)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
List::CenterSelected()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
List::KeyPressed(int k, bool isRepeat)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
List::Filter(bool reset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
