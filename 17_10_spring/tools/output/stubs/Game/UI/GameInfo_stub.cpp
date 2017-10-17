#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameInfo.h"
#include "Game/GameSetup.h"
#include "Game/GameVersion.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "MouseHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/Team.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Path/IPathManager.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"

#include <SDL_keycode.h>
#include <cstdio>

using std::string;
using std::vector;

static const char*
boolString(bool value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char*
floatString(float value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
StringListStats(const vector<CGameInfo::FontString>& list,
                float& maxWidth,
                float& maxHeight)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static CGameInfo* instance = NULL;

void
CGameInfo::Enable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameInfo::Disable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGameInfo::IsActive()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameInfo::CGameInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameInfo::~CGameInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameInfo::FontString::FontString(const char* c)
  : msg(c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
CGameInfo::FontString::FontString(const std::string& s)
  : msg(s)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
CGameInfo::FontString::FontString(bool b)
  : msg(boolString(b))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
CGameInfo::FontString::FontString(float f)
  : msg(floatString(f))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameInfo::FontString::CalcDimensions()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

std::string
CGameInfo::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGameInfo::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGameInfo::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameInfo::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGameInfo::KeyPressed(int key, bool isRepeat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGameInfo::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
