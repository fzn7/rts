#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "TerrainBase.h"

#include "TerrainTexture.h"
#include "TerrainTexEnvCombine.h"
#include "Map/SM3/Plane.h"

#include <assert.h>

namespace terrain {

uint NodeTexEnvSetup::GetVertexDataRequirements()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string NodeTexEnvSetup::GetDebugDesc()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void NodeTexEnvSetup::GetTextureUnits(BaseTexture* tex, int& imageUnit, int& coordUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//-----------------------------------------------------------------------
// texture env state builder
//-----------------------------------------------------------------------

TexEnvStage::TexEnvStage()
	: operation(Replace)
	, source(None)
	, srcTexture(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TexEnvSetupHandler::TexEnvSetupHandler()
	: maxtu(0)
	, hasDot3(!!GLEW_ARB_texture_env_dot3)
	, lastShader(NULL)
	, curSetup(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int TexEnvSetupHandler::MaxTextureUnits()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
int TexEnvSetupHandler::MaxTextureCoords()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void TexEnvSetupHandler::BuildNodeSetup(ShaderDef* shaderDef, RenderSetup* renderSetup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void TexEnvSetupHandler::BeginPass(const std::vector<Blendmap*>& blendMaps, const std::vector<TiledTexture*>& textures, int pass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void TexEnvSetupHandler::BeginTexturing()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void TexEnvSetupHandler::EndTexturing()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void TexEnvSetupHandler::SetTexCoordGen(float* tgv)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

}
