/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LegacyTrackHandler.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Units/UnitDef.h"
#include "System/EventHandler.h"
#include "System/Util.h"
#include "System/TimeProfiler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"

#include <algorithm>
#include <cctype>



LegacyTrackHandler::LegacyTrackHandler()
	: CEventClient("[LegacyTrackHandler]", 314160, false)
{
    //stub method
}



LegacyTrackHandler::~LegacyTrackHandler()
{
    //stub method
}


void LegacyTrackHandler::LoadDecalShaders()
{
    //stub method
}

void LegacyTrackHandler::SunChanged()
{
    //stub method
}


void LegacyTrackHandler::AddTracks()
{
    //stub method
}


void LegacyTrackHandler::DrawTracks()
{
    //stub method
}

void LegacyTrackHandler::CleanTracks()
{
    //stub method
}


bool LegacyTrackHandler::GetDrawTracks() const
{
    //stub method
}


void LegacyTrackHandler::Draw()
{
    //stub method
}


void LegacyTrackHandler::BindTextures()
{
    //stub method
}


void LegacyTrackHandler::KillTextures()
{
    //stub method
}


void LegacyTrackHandler::BindShader(const float3& ambientColor)
{
    //stub method
}


void LegacyTrackHandler::AddTrack(CUnit* unit, const float3& newPos)
{
    //stub method
}


int LegacyTrackHandler::GetTrackType(const std::string& name)
{
    //stub method
}


unsigned int LegacyTrackHandler::LoadTexture(const std::string& name)
{
    //stub method
}




void LegacyTrackHandler::RemoveTrack(CUnit* unit)
{
    //stub method
}


void LegacyTrackHandler::UnitMoved(const CUnit* unit)
{
    //stub method
}


void LegacyTrackHandler::RenderUnitDestroyed(const CUnit* unit)
{
    //stub method
}

