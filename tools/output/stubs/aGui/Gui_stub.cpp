#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Input/InputHandler.h"
#include "Gui.h"

#include <boost/bind.hpp>
#include <SDL_events.h>

#include "GuiElement.h"
#include "Rendering/GL/myGL.h"
#include "System/Log/ILog.h"


namespace agui
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void Gui::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void Gui::Clean() {
	for (ElList::iterator it = toBeAdded.begin(); it != toBeAdded.end(); ++it)
	{
		bool duplicate = false;
		for (ElList::iterator elIt = elements.begin(); elIt != elements.end(); ++elIt)
		{
			if (it->element == elIt->element)
			{
				LOG_L(L_DEBUG, "Gui::AddElement: skipping duplicated object");
				duplicate = true;
				break;
			}
		}
		if (!duplicate)
		{
			if (it->asBackground)
				elements.push_back(*it);
			else
				elements.push_front(*it);
		}
	}
	toBeAdded.clear();

	for (ElList::iterator it = toBeRemoved.begin(); it != toBeRemoved.end(); ++it)
	{
		for (ElList::iterator elIt = elements.begin(); elIt != elements.end(); ++elIt)
		{
			if (it->element == elIt->element)
			{
				delete (elIt->element);
				elements.erase(elIt);
				break;
			}
		}
	}
	toBeRemoved.clear();
}

Gui::~Gui() {
	Clean();
}

void Gui::AddElement(GuiElement* elem, bool asBackground)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void Gui::RmElement(GuiElement* elem)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void Gui::UpdateScreenGeometry(int screenx, int screeny, int screenOffsetX, int screenOffsetY)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool Gui::MouseOverElement(const GuiElement* elem, int x, int y) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool Gui::HandleEvent(const SDL_Event& ev)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Gui* gui = NULL;
void InitGui()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void FreeGui()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

}
