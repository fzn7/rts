#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/DebugDrawerAI.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/bitops.h"

static const float3 GRAPH_MIN_SCALE = float3(1e9, 1e9, 0.0f);
static const float3 GRAPH_MAX_SCALE = float3(-1e9, -1e9, 0.0f);

DebugDrawerAI::DebugDrawerAI()
  : draw(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
DebugDrawerAI::~DebugDrawerAI()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

DebugDrawerAI*
DebugDrawerAI::GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// add a datapoint to the <lineNum>'th line of the graph for team <teamNum>
void
DebugDrawerAI::AddGraphPoint(int teamNum, int lineNum, float x, float y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
// delete the first <N> datapoints from the <lineNum>'th line of the graph for
// team <teamNum>
void
DebugDrawerAI::DelGraphPoints(int teamNum, int lineNum, int numPoints)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::SetGraphPos(int teamNum, float x, float y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::SetGraphSize(int teamNum, float w, float h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::SetGraphLineColor(int teamNum, int lineNum, const float3& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::SetGraphLineLabel(int teamNum, int lineNum, const std::string& s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
DebugDrawerAI::AddOverlayTexture(int teamNum, const float* data, int w, int h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::UpdateOverlayTexture(int teamNum,
                                    int texHandle,
                                    const float* data,
                                    int x,
                                    int y,
                                    int w,
                                    int h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::DelOverlayTexture(int teamNum, int texHandle)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::SetOverlayTexturePos(int teamNum,
                                    int texHandle,
                                    float x,
                                    float y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
DebugDrawerAI::SetOverlayTextureSize(int teamNum,
                                     int texHandle,
                                     float w,
                                     float h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
DebugDrawerAI::SetOverlayTextureLabel(int teamNum,
                                      int texHandle,
                                      const std::string& label)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

DebugDrawerAI::Graph::Graph(const float3& mins, const float3& maxs)
  : pos(ZeroVector)
  , size(ZeroVector)
  , minScale(mins)
  , maxScale(maxs)
  , minLabelSize(1000)
  , minLabelWidth(1000.0f)
  , maxLabelSize(0)
  , maxLabelWidth(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::Graph::DelPoints(int lineNum, int numPoints)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::Graph::SetColor(int lineNum, const float3& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::Graph::SetLabel(int lineNum, const std::string& s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::Graph::Clear()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::Graph::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::TexSet::Clear()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
DebugDrawerAI::TexSet::AddTexture(const float* data, int w, int h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::TexSet::UpdateTexture(int texHandle,
                                     const float* data,
                                     int x,
                                     int y,
                                     int w,
                                     int h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::TexSet::DelTexture(int texHandle)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::TexSet::SetTexturePos(int texHandle, float x, float y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
DebugDrawerAI::TexSet::SetTextureSize(int texHandle, float w, float h)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
DebugDrawerAI::TexSet::SetTextureLabel(int texHandle, const std::string& label)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::TexSet::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

DebugDrawerAI::TexSet::Texture::Texture(int w, int h, const float* data)
  : id(0)
  , xsize(w)
  , ysize(h)
  , pos(ZeroVector)
  , size(ZeroVector)
  , label("")
  , labelWidth(0.0f)
  , labelHeight(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

DebugDrawerAI::TexSet::Texture::~Texture()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DebugDrawerAI::TexSet::Texture::SetLabel(const std::string& s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
