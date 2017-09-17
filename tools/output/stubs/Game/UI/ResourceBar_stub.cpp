#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ResourceBar.h"
#include "Game/GlobalUnsynced.h"
#include "GuiHandler.h"
#include "MouseHandler.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/TimeProfiler.h"
#include "System/myMath.h"

CResourceBar* resourceBar = NULL;

CResourceBar::CResourceBar()
  : moveBox(false)
  , enabled(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CResourceBar::~CResourceBar() {}

static std::string
FloatToSmallString(float num, float mul = 1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CResourceBar::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CResourceBar::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CResourceBar::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CResourceBar::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CResourceBar::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
