#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

//
// ROAM Simplistic Implementation
// Added to Spring by Peter Sarkozy (mysterme AT gmail DOT com)
// Billion thanks to Bryan Turner (Jan, 2000)
//                    brturn@bellsouth.net
//
// Based on the Tread Marks engine by Longbow Digital Arts
//                               (www.LongbowDigitalArts.com)
// Much help and hints provided by Seumas McNally, LDA.
//

#include "Patch.h"
#include "Game/Camera.h"
#include "Map/ReadMap.h"
#include "Map/SMF/SMFGroundDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "RoamMeshDrawer.h"
#include "System/Log/ILog.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"

#include <climits>

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// STATICS

static int MAX_POOL_SIZE = 8000000;

Patch::RenderMode Patch::renderMode = Patch::VBO;

// one pool per thread
static size_t poolSize = 0;
static std::vector<CTriNodePool> pools[CRoamMeshDrawer::MESH_COUNT];

void
CTriNodePool::InitPools(bool shadowPass, size_t newPoolSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CTriNodePool::FreePools(bool shadowPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CTriNodePool::ResetAll(bool shadowPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CTriNodePool*
CTriNodePool::GetPool(bool shadowPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// CTriNodePool Class

CTriNodePool::CTriNodePool(const size_t poolSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CTriNodePool::Reset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CTriNodePool::Allocate(TriTreeNode*& left, TriTreeNode*& right)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// Patch Class
//

Patch::Patch()
  : smfGroundDrawer(nullptr)
  , currentVariance(nullptr)
  , currentPool(nullptr)
  , isDirty(true)
  , vboVerticesUploaded(false)
  , varianceMaxLimit(std::numeric_limits<float>::max())
  , camDistLODFactor(1.0f)
  , coors(-1, -1)
  , triList(0)
  , vertexBuffer(0)
  , vertexIndexBuffer(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Patch::~Patch()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::Init(CSMFGroundDrawer* _drawer, int patchX, int patchZ)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::Reset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::UpdateHeightMap(const SRectangle& rect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::VBOUploadVertices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// -------------------------------------------------------------------------------------------------
// Split a single Triangle and link it into the mesh.
// Will correctly force-split diamonds.
//
void
Patch::Split(TriTreeNode* tri)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// ---------------------------------------------------------------------
// Tessellate a Patch.
// Will continue to split until the variance metric is met.
//
void
Patch::RecursTessellate(TriTreeNode* tri,
                        const int2 left,
                        const int2 right,
                        const int2 apex,
                        const int node)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// ---------------------------------------------------------------------
// Render the tree.
//

void
Patch::RecursRender(const TriTreeNode* tri,
                    const int2 left,
                    const int2 right,
                    const int2 apex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::GenerateIndices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
Patch::GetHeight(int2 pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// ---------------------------------------------------------------------
// Computes Variance over the entire tree.  Does not examine node relationships.
//
float
Patch::RecursComputeVariance(const int2 left,
                             const int2 rght,
                             const int2 apex,
                             const float3 hgts,
                             const int node)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// ---------------------------------------------------------------------
// Compute the variance tree for each of the Binary Triangles in this patch.
//
void
Patch::ComputeVariance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// ---------------------------------------------------------------------
// Create an approximate mesh.
//
bool
Patch::Tessellate(const float3& campos, int groundDetail, bool shadowPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// ---------------------------------------------------------------------
// Render the mesh.
//

void
Patch::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::DrawBorder()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::RecursBorderRender(CVertexArray* va,
                          const TriTreeNode* tri,
                          const int2 left,
                          const int2 rght,
                          const int2 apex,
                          int depth,
                          bool leftChild)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::GenerateBorderIndices(CVertexArray* va)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::Upload()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::SetSquareTexture() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Patch::SwitchRenderMode(int mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    // ---------------------------------------------------------------------
    // Visibility Update Functions
    //

#if 0
void Patch::UpdateVisibility(CCamera* cam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

class CPatchInViewChecker : public CReadMap::IQuadDrawer
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
Patch::IsVisible(const CCamera* cam) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
