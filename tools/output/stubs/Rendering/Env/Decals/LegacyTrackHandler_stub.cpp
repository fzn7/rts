#include <iostream>
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
    std::cout << _FUNCTION_ << std::endl;
}



LegacyTrackHandler::~LegacyTrackHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::LoadDecalShaders()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LegacyTrackHandler::SunChanged()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::AddTracks()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::DrawTracks()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LegacyTrackHandler::CleanTracks()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LegacyTrackHandler::GetDrawTracks() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::BindTextures()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::KillTextures()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::BindShader(const float3& ambientColor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::AddTrack(CUnit* unit, const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LegacyTrackHandler::GetTrackType(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned int LegacyTrackHandler::LoadTexture(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




void LegacyTrackHandler::RemoveTrack(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::UnitMoved(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LegacyTrackHandler::RenderUnitDestroyed(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

