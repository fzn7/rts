/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "List.h"

#include <SDL_mouse.h>

#include "Rendering/Fonts/glFont.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/myGL.h"
#include "Game/GlobalUnsynced.h"
#include "Game/UI/MouseHandler.h"
#include "Gui.h"
#include "System/Util.h"

namespace agui
{
    //stub method
}

List::~List()
{
    //stub method
}

void List::SetFocus(bool focus)
{
    //stub method
}

void List::RemoveAllItems() {
	items.clear();
}

void List::RefreshQuery() {
	if (query != "") {
		int t = topIndex;
		std::string q = query;
		Filter(true);
		query = q;
		Filter(false);
		topIndex = t;
	}
}

void List::AddItem(const std::string& name, const std::string& description)
{
    //stub method
}

bool List::MousePress(int x, int y, int button)
{
    //stub method
}

int List::NumDisplay()
{
    //stub method
}

void List::ScrollUpOne()
{
    //stub method
}

void List::ScrollDownOne()
{
    //stub method
}

void List::MouseMove(int x, int y, int dx,int dy, int button)
{
    //stub method
}

void List::MouseRelease(int x, int y, int button)
{
    //stub method
}

float List::ScaleFactor() {
	return (float)std::max(1, globalRendering->winSizeY) * (size[1] - 2.0f * borderSpacing);
}

void List::UpdateTopIndex()
{
    //stub method
}

bool List::MouseUpdate(int x, int y)
{
    //stub method
}

void List::DrawSelf()
{
    //stub method
}

bool List::HandleEventSelf(const SDL_Event& ev)
{
    //stub method
}



void List::UpOne()
{
    //stub method
}

void List::DownOne()
{
    //stub method
}

void List::UpPage()
{
    //stub method
}

void List::DownPage()
{
    //stub method
}



std::string List::GetCurrentItem() const
{
    //stub method
}

bool List::SetCurrentItem(const std::string& newCurrent)
{
    //stub method
}

void List::CenterSelected()
{
    //stub method
}

bool List::KeyPressed(int k, bool isRepeat)
{
    //stub method
}

bool List::Filter(bool reset)
{
    //stub method
}

}
