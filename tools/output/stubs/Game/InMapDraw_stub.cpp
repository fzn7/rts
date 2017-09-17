#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SDL_mouse.h"
#include "SDL_keyboard.h"

#include "InMapDraw.h"

#include "InMapDrawModel.h"
#include "Camera.h"
#include "Game.h"
#include "GlobalUnsynced.h"
#include "ExternalAI/AILegacySupport.h" // {Point, Line}Marker
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "UI/MiniMap.h"
#include "UI/MouseHandler.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "Net/Protocol/NetProtocol.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/Net/UnpackPacket.h"
#include "System/EventHandler.h"
#include "System/EventClient.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"


CInMapDraw* inMapDrawer = NULL;

/**
 * This simply makes a noice appear when a map point is placed.
 * We will only receive an even (and thus make a sound) when we are allwoed to
 * know about it.
 */
class CNotificationPeeper : public CEventClient
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CInMapDraw::~CInMapDraw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CInMapDraw::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CInMapDraw::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CInMapDraw::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 CInMapDraw::GetMouseMapPos() // TODO move to some more global place?
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CInMapDraw::GotNetMsg(boost::shared_ptr<const netcode::RawPacket>& packet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CInMapDraw::SetSpecMapDrawingAllowed(bool state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CInMapDraw::SetLuaMapDrawingAllowed(bool state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CInMapDraw::SendErase(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CInMapDraw::SendPoint(const float3& pos, const std::string& label, bool fromLua)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CInMapDraw::SendLine(const float3& pos, const float3& pos2, bool fromLua)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CInMapDraw::SendWaitingInput(const std::string& label)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CInMapDraw::PromptLabel(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CInMapDraw::GetPoints(std::vector<PointMarker>& points, int pointsSizeMax, const std::list<int>& teamIDs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CInMapDraw::GetLines(std::vector<LineMarker>& lines, int linesSizeMax, const std::list<int>& teamIDs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

