#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstdarg>
#include <cstring>

#include "Terrain.h"
#include "TerrainBase.h"
#include "TerrainVertexBuffer.h"

#include "System/TdfParser.h"

#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "TerrainNode.h"
#include "TerrainTexture.h"
#include <IL/il.h>
#include <assert.h>
#include <deque>
#include <fstream>

// define this for big endian machines
//#define SWAP_SHORT

namespace terrain {

Config::Config()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ILoadCallback::PrintMsg(const char* fmt, ...)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//-----------------------------------------------------------------------
// Quad map - stores a 2D map of the quad nodes,
//            for quick access of nabours
//-----------------------------------------------------------------------

void
QuadMap::Alloc(int W)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QuadMap::Fill(TQuad* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//-----------------------------------------------------------------------
// Terrain Quadtree Node
//-----------------------------------------------------------------------

TQuad::TQuad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TQuad::~TQuad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
TQuad::Build(Heightmap* hm,
             int2 sqStart,
             int2 hmStart,
             int2 quadPos,
             int w,
             int d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
TQuad::GetVertexSize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
TQuad::Draw(IndexTable* indexTable, bool onlyPositions, int lodState)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
TQuad::InFrustum(Frustum* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Calculates the exact nearest point, not just one of the box'es vertices
void
NearestBoxPoint(const Vector3* min,
                const Vector3* max,
                const Vector3* pos,
                Vector3* out)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
TQuad::CalcLod(const Vector3& campos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
TQuad::CollectNodes(std::vector<TQuad*>& quads)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
TQuad::FreeCachedTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TQuad*
TQuad::FindSmallestContainingQuad2D(const Vector3& pos,
                                    float range,
                                    int maxdepth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//-----------------------------------------------------------------------
// Terrain Main class
//-----------------------------------------------------------------------

Terrain::Terrain()
  : heightmap(NULL)
  , lowdetailhm(NULL)
  , quadtree(NULL)
  , activeRC(NULL)
  , curRC(NULL)
  , indexTable(NULL)
  , texturing(NULL)
  , shadowMap(0)
  , quadTreeDepth(0)
  , renderDataManager(NULL)
  , debugQuad(NULL)
  , nodeUpdateCount(0)
  , logUpdates(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::SetShadowMap(uint shadowTex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// used by ForceQueue to queue quads
void
Terrain::QueueLodFixQuad(TQuad* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::ForceQueue(TQuad* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
Terrain::CheckNabourLod(TQuad* q, int xOfs, int yOfs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Check nabour parent nodes to see if they need to be drawn to fix LOD gaps of
// this node.
void
Terrain::UpdateLodFix(TQuad* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Handle visibility with the frustum, and select LOD based on distance to
// camera and LOD setting
void
Terrain::QuadVisLod(TQuad* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
QuadSortFunc(const QuadRenderInfo& q1, const QuadRenderInfo& q2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// update quad node drawing list
void
Terrain::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::DrawSimple()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::DrawOverlayTexture(uint tex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DrawNormals(TQuad* q, const Heightmap* hm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::CalcRenderStats(RenderStats& stats, RenderContext* ctx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifndef TERRAINRENDERERLIB_EXPORTS
void
Terrain::DebugPrint(IFontRenderer* fr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

TQuad*
FindQuad(TQuad* q, const Vector3& cpos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::RenderNodeFlat(int x, int y, int depth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::RenderNode(TQuad* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::CacheTextures()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::DebugEvent(const std::string& event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::Load(const TdfParser& tdf, LightingInfo* li, ILoadCallback* cb)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::LoadHeightMap(const TdfParser& parser, ILoadCallback* cb)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::ReloadShaders()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
FindRAWProps(int len, int& width, int& bytespp, ILoadCallback* cb)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Heightmap*
Terrain::LoadHeightmapFromRAW(const std::string& file, ILoadCallback* cb)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Heightmap*
Terrain::LoadHeightmapFromImage(const std::string& heightmapFile,
                                ILoadCallback* cb)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Vector3
Terrain::TerrainSize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
Terrain::GetHeightmapWidth() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
int
Terrain::GetHeightmapHeight() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::SetShaderParams(Vector3 dir, Vector3 eyevec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// heightmap blitting
void
Terrain::HeightMapUpdatedUnsynced(int sx, int sy, int w, int h)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<float>&
Terrain::GetCornerHeightMapSynced()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
std::vector<float>&
Terrain::GetCornerHeightMapUnsynced()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::SetShadowParams(ShadowMapParams* smp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

RenderContext*
Terrain::AddRenderContext(Camera* cam, bool needsTexturing)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::RemoveRenderContext(RenderContext* rc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Terrain::SetActiveContext(RenderContext* rc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
};
