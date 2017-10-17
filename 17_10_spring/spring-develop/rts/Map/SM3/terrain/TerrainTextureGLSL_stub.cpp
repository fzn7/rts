#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Terrain.h"
#include "TerrainBase.h"
#include "TerrainTexture.h"

#include "Rendering/GL/FBO.h"
#include "Rendering/GlobalRendering.h"
#include "System/Exceptions.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/bitops.h"
#include "TerrainTextureGLSL.h"

#include <assert.h>
#include <fstream>
#include <list>

namespace terrain {

static void
ShowInfoLog(GLhandleARB handle)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

struct Shader
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

// A framebuffer enabled as texture
class BufferTexture : public BaseTexture
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ShaderBuilder::TexReq
ShaderBuilder::CalcStagesTexReq(const std::vector<ShaderDef::Stage>& stages,
                                uint index) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderBuilder::TexReq::GetFromGL()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ShaderBuilder::ShaderBuilder(RenderSetup* rs)
  : renderSetup(rs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
ShaderBuilder::GenTextureRead(int tu, int tc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

NodeGLSLShader*
ShaderBuilder::EndPass(ShaderDef* sd,
                       const std::string& operations,
                       uint passIndex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderBuilder::AddPPDefines(ShaderDef* sd, Shader& shader, uint passIndex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderBuilder::BuildFragmentShader(NodeGLSLShader* ns,
                                   uint passIndex,
                                   const std::string& operations,
                                   ShaderDef* sd)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderBuilder::BuildVertexShader(NodeGLSLShader* ns,
                                 uint passIndex,
                                 ShaderDef* sd)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ShaderBuilder::ProcessStage(std::vector<ShaderDef::Stage>& stages,
                            uint& index,
                            std::string& opstr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ShaderBuilder::Build(ShaderDef* shaderDef)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

NodeGLSLShader::NodeGLSLShader()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

NodeGLSLShader::~NodeGLSLShader()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
NodeGLSLShader::BindTSM(Vector3* buf, uint vertexSize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
NodeGLSLShader::UnbindTSM()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
NodeGLSLShader::Setup(NodeSetupParams& params)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
NodeGLSLShader::Cleanup()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
NodeGLSLShader::GetDebugDesc()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

uint
NodeGLSLShader::GetVertexDataRequirements()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
NodeGLSLShader::GetTextureUnits(BaseTexture* tex,
                                int& imageUnit,
                                int& coordUnit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

GLSLShaderHandler::~GLSLShaderHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GLSLShaderHandler::EndTexturing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GLSLShaderHandler::BeginTexturing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
GLSLShaderHandler::SetupShader(IShaderSetup* ps, NodeSetupParams& params)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GLSLShaderHandler::BeginBuild()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GLSLShaderHandler::EndBuild()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
GLSLShaderHandler::BuildNodeSetup(ShaderDef* shaderDef,
                                  RenderSetup* renderSetup)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
GLSLShaderHandler::MaxTextureUnits()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
GLSLShaderHandler::MaxTextureCoords()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SimpleCopyShader::SimpleCopyShader(BufferTexture* buf)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SimpleCopyShader::~SimpleCopyShader()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SimpleCopyShader::Setup()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SimpleCopyShader::Cleanup()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
