#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>

#include "CommandColors.h"
#include "CursorIcons.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "GuiHandler.h"
#include "MouseHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"

CCursorIcons cursorIcons;

CCursorIcons::CCursorIcons()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCursorIcons::~CCursorIcons() {}

void
CCursorIcons::Enable(bool value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCursorIcons::Clear()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCursorIcons::SetCustomType(int cmdID, const string& cursor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCursorIcons::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCursorIcons::DrawCursors()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCursorIcons::DrawTexts()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCursorIcons::DrawBuilds()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CMouseCursor*
CCursorIcons::GetCursor(int cmd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
