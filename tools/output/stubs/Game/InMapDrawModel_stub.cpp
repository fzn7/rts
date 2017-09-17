/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "InMapDrawModel.h"

#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/EventHandler.h"
#include "System/creg/STL_List.h"


CInMapDrawModel* inMapDrawerModel = NULL;

const size_t CInMapDrawModel::DRAW_QUAD_SIZE = 32;

const float CInMapDrawModel::QUAD_SCALE = 1.0f / (DRAW_QUAD_SIZE * SQUARE_SIZE);



CInMapDrawModel::CInMapDrawModel()
	: drawQuadsX(mapDims.mapx / DRAW_QUAD_SIZE)
	, drawQuadsY(mapDims.mapy / DRAW_QUAD_SIZE)
	, drawAllMarks(false)
	, numPoints(0)
	, numLines(0)
{
    //stub method
}


CInMapDrawModel::~CInMapDrawModel()
{
    //stub method
}

bool CInMapDrawModel::MapDrawPrimitive::IsLocalPlayerAllowedToSee(const CInMapDrawModel* inMapDrawModel) const
{
    //stub method
}


bool CInMapDrawModel::AllowedMsg(const CPlayer* sender) const
{
    //stub method
}


bool CInMapDrawModel::AddPoint(const float3& constPos, const std::string& label, int playerID)
{
    //stub method
}


bool CInMapDrawModel::AddLine(const float3& constPos1, const float3& constPos2, int playerID)
{
    //stub method
}


void CInMapDrawModel::EraseNear(const float3& constPos, int playerID)
{
    //stub method
}


void CInMapDrawModel::EraseAll()
{
    //stub method
}


const CInMapDrawModel::DrawQuad* CInMapDrawModel::GetDrawQuad(int x, int y) const
{
    //stub method
}
