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
}

std::string NodeTexEnvSetup::GetDebugDesc()
{
    //stub method
}

void NodeTexEnvSetup::GetTextureUnits(BaseTexture* tex, int& imageUnit, int& coordUnit)
{
    //stub method
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
}

TexEnvSetupHandler::TexEnvSetupHandler()
	: maxtu(0)
	, hasDot3(!!GLEW_ARB_texture_env_dot3)
	, lastShader(NULL)
	, curSetup(NULL)
{
    //stub method
}

int TexEnvSetupHandler::MaxTextureUnits()
{
    //stub method
}
int TexEnvSetupHandler::MaxTextureCoords()
{
    //stub method
}

void TexEnvSetupHandler::BuildNodeSetup(ShaderDef* shaderDef, RenderSetup* renderSetup)
{
    //stub method
}

void TexEnvSetupHandler::BeginPass(const std::vector<Blendmap*>& blendMaps, const std::vector<TiledTexture*>& textures, int pass)
{
    //stub method
}

void TexEnvSetupHandler::BeginTexturing()
{
    //stub method
}

void TexEnvSetupHandler::EndTexturing()
{
    //stub method
}

void TexEnvSetupHandler::SetTexCoordGen(float* tgv)
{
    //stub method
}

}
