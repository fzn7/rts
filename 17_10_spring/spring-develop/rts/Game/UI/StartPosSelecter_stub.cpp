#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "StartPosSelecter.h"
#include "Game/Camera.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/InMapDraw.h"
#include "Game/Players/Player.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "MouseHandler.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Sim/Misc/TeamHandler.h"

CStartPosSelecter* CStartPosSelecter::selector = NULL;

CStartPosSelecter::CStartPosSelecter()
  : CInputReceiver(BACK)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CStartPosSelecter::~CStartPosSelecter()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CStartPosSelecter::Ready(bool luaForcedReady)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CStartPosSelecter::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CStartPosSelecter::DrawStartBox() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CStartPosSelecter::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
