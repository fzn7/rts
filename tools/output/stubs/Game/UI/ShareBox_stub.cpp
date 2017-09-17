/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ShareBox.h"

#include "MouseHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/MsgStrings.h"

#include <SDL_keycode.h>


#define MAX_SHARE_TEAMS (teamHandler->ActiveTeams() - 1)
int CShareBox::lastShareTeam = 0;

CShareBox::CShareBox()
{
    //stub method
}

CShareBox::~CShareBox()
{
    //stub method
}

void CShareBox::Draw()
{
    //stub method
}

bool CShareBox::IsAbove(int x, int y)
{
    //stub method
}

std::string CShareBox::GetTooltip(int x, int y)
{
    //stub method
}

bool CShareBox::MousePress(int x, int y, int button)
{
    //stub method
}

void CShareBox::MouseRelease(int x, int y, int button)
{
    //stub method
}

void CShareBox::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
}

bool CShareBox::KeyPressed(int key, bool isRepeat)
{
    //stub method
}




