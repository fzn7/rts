#include <iostream>
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
    std::cout << _FUNCTION_ << std::endl;
}

CInfoTextureHandler::~CInfoTextureHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInfoTextureHandler::AddInfoTexture(CPboInfoTexture* itex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CInfoTexture*
CInfoTextureHandler::GetInfoTextureConst(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CInfoTexture*
CInfoTextureHandler::GetInfoTexture(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CInfoTextureHandler::IsEnabled() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInfoTextureHandler::DisableCurrentMode()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInfoTextureHandler::SetMode(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInfoTextureHandler::ToggleMode(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
CInfoTextureHandler::GetMode() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLuint
CInfoTextureHandler::GetCurrentInfoTexture() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int2
CInfoTextureHandler::GetCurrentInfoTextureSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInfoTextureHandler::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
