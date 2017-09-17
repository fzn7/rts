/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "StartPosSelecter.h"
#include "MouseHandler.h"
#include "Game/Camera.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/InMapDraw.h"
#include "Game/Players/Player.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Fonts/glFont.h"
#include "Net/Protocol/NetProtocol.h"
#include "Sim/Misc/TeamHandler.h"


CStartPosSelecter* CStartPosSelecter::selector = NULL;


CStartPosSelecter::CStartPosSelecter() : CInputReceiver(BACK)
{
    //stub method
}

CStartPosSelecter::~CStartPosSelecter()
{
    //stub method
}


bool CStartPosSelecter::Ready(bool luaForcedReady)
{
    //stub method
}


bool CStartPosSelecter::MousePress(int x, int y, int button)
{
    //stub method
}


void CStartPosSelecter::DrawStartBox() const
{
    //stub method
}


void CStartPosSelecter::Draw()
{
    //stub method
}
