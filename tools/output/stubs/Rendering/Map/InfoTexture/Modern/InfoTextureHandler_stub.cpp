/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "InfoTextureHandler.h"
#include "AirLos.h"
#include "Combiner.h"
#include "Height.h"
#include "Los.h"
#include "Metal.h"
#include "MetalExtraction.h"
#include "Path.h"
#include "Radar.h"

#include "System/TimeProfiler.h"



CInfoTextureHandler::CInfoTextureHandler()
: returnToLOS(false)
, infoTex(nullptr)
{
    //stub method
}


CInfoTextureHandler::~CInfoTextureHandler()
{
    //stub method
}


void CInfoTextureHandler::AddInfoTexture(CPboInfoTexture* itex)
{
    //stub method
}


const CInfoTexture* CInfoTextureHandler::GetInfoTextureConst(const std::string& name) const
{
    //stub method
}

CInfoTexture* CInfoTextureHandler::GetInfoTexture(const std::string& name)
{
    //stub method
}


bool CInfoTextureHandler::IsEnabled() const
{
    //stub method
}


void CInfoTextureHandler::DisableCurrentMode()
{
    //stub method
}


void CInfoTextureHandler::SetMode(const std::string& name)
{
    //stub method
}


void CInfoTextureHandler::ToggleMode(const std::string& name)
{
    //stub method
}


const std::string& CInfoTextureHandler::GetMode() const
{
    //stub method
}


GLuint CInfoTextureHandler::GetCurrentInfoTexture() const
{
    //stub method
}


int2 CInfoTextureHandler::GetCurrentInfoTextureSize() const
{
    //stub method
}


void CInfoTextureHandler::Update()
{
    //stub method
}
