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
}


CInMapDraw::~CInMapDraw()
{
    //stub method
}


void CInMapDraw::MousePress(int x, int y, int button)
{
    //stub method
}


void CInMapDraw::MouseRelease(int x, int y, int button)
{
    //stub method
}


void CInMapDraw::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
}


float3 CInMapDraw::GetMouseMapPos() // TODO move to some more global place?
{
    //stub method
}

int CInMapDraw::GotNetMsg(boost::shared_ptr<const netcode::RawPacket>& packet)
{
    //stub method
}


void CInMapDraw::SetSpecMapDrawingAllowed(bool state)
{
    //stub method
}

void CInMapDraw::SetLuaMapDrawingAllowed(bool state)
{
    //stub method
}



void CInMapDraw::SendErase(const float3& pos)
{
    //stub method
}


void CInMapDraw::SendPoint(const float3& pos, const std::string& label, bool fromLua)
{
    //stub method
}


void CInMapDraw::SendLine(const float3& pos, const float3& pos2, bool fromLua)
{
    //stub method
}

void CInMapDraw::SendWaitingInput(const std::string& label)
{
    //stub method
}


void CInMapDraw::PromptLabel(const float3& pos)
{
    //stub method
}


void CInMapDraw::GetPoints(std::vector<PointMarker>& points, int pointsSizeMax, const std::list<int>& teamIDs)
{
    //stub method
}

void CInMapDraw::GetLines(std::vector<LineMarker>& lines, int linesSizeMax, const std::list<int>& teamIDs)
{
    //stub method
}

