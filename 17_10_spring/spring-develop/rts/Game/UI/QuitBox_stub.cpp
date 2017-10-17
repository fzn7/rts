#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "QuitBox.h"

#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "MouseHandler.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/LoadSave/LoadSaveHandler.h"
#include "System/Log/ILog.h"
#include "System/MsgStrings.h"
#include "System/TimeUtil.h"

#include <SDL_keycode.h>

#define MAX_QUIT_TEAMS (teamHandler->ActiveTeams() - 1)

#undef CreateDirectory

CQuitBox::CQuitBox()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CQuitBox::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CQuitBox::IsAbove(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CQuitBox::GetTooltip(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CQuitBox::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CQuitBox::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CQuitBox::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CQuitBox::KeyPressed(int key, bool isRepeat)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
