#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TerrainBase.h"

#include "Map/SM3/Plane.h"
#include "TerrainTexEnvCombine.h"
#include "TerrainTexture.h"

#include <assert.h>

namespace terrain {

uint
NodeTexEnvSetup::GetVertexDataRequirements()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
NodeTexEnvSetup::GetDebugDesc()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
NodeTexEnvSetup::GetTextureUnits(BaseTexture* tex,
                                 int& imageUnit,
                                 int& coordUnit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
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
    std::cout << __FUNCTION__ << std::endl;
}

int
TexEnvSetupHandler::MaxTextureUnits()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
TexEnvSetupHandler::MaxTextureCoords()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TexEnvSetupHandler::BuildNodeSetup(ShaderDef* shaderDef,
                                   RenderSetup* renderSetup)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TexEnvSetupHandler::BeginPass(const std::vector<Blendmap*>& blendMaps,
                              const std::vector<TiledTexture*>& textures,
                              int pass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TexEnvSetupHandler::BeginTexturing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TexEnvSetupHandler::EndTexturing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TexEnvSetupHandler::SetTexCoordGen(float* tgv)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
