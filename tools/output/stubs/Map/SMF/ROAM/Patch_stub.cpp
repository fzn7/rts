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
#include "RoamMeshDrawer.h"
#include "Game/Camera.h"
#include "Map/ReadMap.h"
#include "Map/SMF/SMFGroundDrawer.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/VertexArray.h"
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

void CTriNodePool::InitPools(bool shadowPass, size_t newPoolSize)
{
    //stub method
}

void CTriNodePool::FreePools(bool shadowPass)
{
    //stub method
}


void CTriNodePool::ResetAll(bool shadowPass)
{
    //stub method
}


CTriNodePool* CTriNodePool::GetPool(bool shadowPass)
{
    //stub method
}


// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// CTriNodePool Class

CTriNodePool::CTriNodePool(const size_t poolSize)
{
    //stub method
}


void CTriNodePool::Reset()
{
    //stub method
}


void CTriNodePool::Allocate(TriTreeNode*& left, TriTreeNode*& right)
{
    //stub method
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
}

Patch::~Patch()
{
    //stub method
}

void Patch::Init(CSMFGroundDrawer* _drawer, int patchX, int patchZ)
{
    //stub method
}

void Patch::Reset()
{
    //stub method
}


void Patch::UpdateHeightMap(const SRectangle& rect)
{
    //stub method
}


void Patch::VBOUploadVertices()
{
    //stub method
}


// -------------------------------------------------------------------------------------------------
// Split a single Triangle and link it into the mesh.
// Will correctly force-split diamonds.
//
void Patch::Split(TriTreeNode* tri)
{
    //stub method
}


// ---------------------------------------------------------------------
// Tessellate a Patch.
// Will continue to split until the variance metric is met.
//
void Patch::RecursTessellate(TriTreeNode* tri, const int2 left, const int2 right, const int2 apex, const int node)
{
    //stub method
}


// ---------------------------------------------------------------------
// Render the tree.
//

void Patch::RecursRender(const TriTreeNode* tri, const int2 left, const int2 right, const int2 apex)
{
    //stub method
}


void Patch::GenerateIndices()
{
    //stub method
}

float Patch::GetHeight(int2 pos)
{
    //stub method
}

// ---------------------------------------------------------------------
// Computes Variance over the entire tree.  Does not examine node relationships.
//
float Patch::RecursComputeVariance(
	const   int2 left,
	const   int2 rght,
	const   int2 apex,
	const float3 hgts,
	const    int node
) {
	/*      A
	 *     /|\
	 *    / | \
	 *   /  |  \
	 *  /   |   \
	 * L----M----R
	 *
	 * first compute the XZ coordinates of 'M' (hypotenuse middle)
	 */
	const int2 mpos = {(left.x + rght.x) >> 1, (left.y + rght.y) >> 1};

	// get the height value at M

	const float mhgt = GetHeight(mpos);

	// variance of this triangle is the actual height at its hypotenuse
	// midpoint minus the interpolated height; use values passed on the
	// stack instead of re-accessing the heightmap
	float myVariance = math::fabs(mhgt - ((hgts.x + hgts.y) * 0.5f));

	// shore lines get more variance for higher accuracy
	// NOTE: .x := height(L), .y := height(R), .z := height(A)
	//
	if ((hgts.x * hgts.y) < 0.0f || (hgts.x * mhgt) < 0.0f || (hgts.y * mhgt) < 0.0f)
		myVariance = std::max(myVariance * 1.5f, 20.0f);

	// myVariance = MAX(abs(left.x - rght.x), abs(left.y - rght.y)) * myVariance;

	// save some CPU, only calculate variance down to a 4x4 block
	if ((abs(left.x - rght.x) >= 4) || (abs(left.y - rght.y) >= 4)) {
		const float3 hgts1 = {hgts.z, hgts.x, mhgt};
		const float3 hgts2 = {hgts.y, hgts.z, mhgt};

		const float child1Variance = RecursComputeVariance(apex, left, mpos, hgts1, (node << 1)    );
		const float child2Variance = RecursComputeVariance(rght, apex, mpos, hgts2, (node << 1) + 1);

		// final variance for this node is the max of its own variance and that of its children
		myVariance = std::max(myVariance, child1Variance);
		myVariance = std::max(myVariance, child2Variance);
	}

	// NOTE: Variance is never zero
	myVariance = std::max(0.001f, myVariance);

	// store the final variance for this node
	if (node < (1 << VARIANCE_DEPTH))
		currentVariance[node] = myVariance;

	return myVariance;
}


// ---------------------------------------------------------------------
// Compute the variance tree for each of the Binary Triangles in this patch.
//
void Patch::ComputeVariance()
{
    //stub method
}


// ---------------------------------------------------------------------
// Create an approximate mesh.
//
bool Patch::Tessellate(const float3& campos, int groundDetail, bool shadowPass)
{
    //stub method
}


// ---------------------------------------------------------------------
// Render the mesh.
//

void Patch::Draw()
{
    //stub method
}


void Patch::DrawBorder()
{
    //stub method
}


void Patch::RecursBorderRender(
	CVertexArray* va,
	const TriTreeNode* tri,
	const int2 left,
	const int2 rght,
	const int2 apex,
	int depth,
	bool leftChild
) {
	if (tri->IsLeaf()) {
		const float3& v1 = *(float3*)&vertices[(apex.x + apex.y * (PATCH_SIZE + 1))*3];
		const float3& v2 = *(float3*)&vertices[(left.x + left.y * (PATCH_SIZE + 1))*3];
		const float3& v3 = *(float3*)&vertices[(rght.x + rght.y * (PATCH_SIZE + 1))*3];

		static const unsigned char white[] = {255,255,255,255};
		static const unsigned char trans[] = {255,255,255,0};

		va->EnlargeArrays(6, 0, VA_SIZE_C);

		if ((depth & 1) == 0) {
			va->AddVertexQC(v2,                          white);
			va->AddVertexQC(float3(v2.x, -400.0f, v2.z), trans);
			va->AddVertexQC(float3(v3.x, v3.y, v3.z),    white);

			va->AddVertexQC(v3,                          white);
			va->AddVertexQC(float3(v2.x, -400.0f, v2.z), trans);
			va->AddVertexQC(float3(v3.x, -400.0f, v3.z), trans);
		} else {
			if (leftChild) {
				va->AddVertexQC(v1,                          white);
				va->AddVertexQC(float3(v1.x, -400.0f, v1.z), trans);
				va->AddVertexQC(float3(v2.x, v2.y, v2.z),    white);

				va->AddVertexQC(v2,                          white);
				va->AddVertexQC(float3(v1.x, -400.0f, v1.z), trans);
				va->AddVertexQC(float3(v2.x, -400.0f, v2.z), trans);
			} else {
				va->AddVertexQC(v3,                          white);
				va->AddVertexQC(float3(v3.x, -400.0f, v3.z), trans);
				va->AddVertexQC(float3(v1.x, v1.y, v1.z),    white);

				va->AddVertexQC(v1,                          white);
				va->AddVertexQC(float3(v3.x, -400.0f, v3.z), trans);
				va->AddVertexQC(float3(v1.x, -400.0f, v1.z), trans);
			}
		}

		return;
	}

	const int2 center = {(left.x + rght.x) >> 1, (left.y + rght.y) >> 1};

	if ((depth & 1) == 0) {
		       RecursBorderRender(va, tri->LeftChild,  apex, left, center, depth + 1, !leftChild);
		return RecursBorderRender(va, tri->RightChild, rght, apex, center, depth + 1,  leftChild); // return is needed for tail call optimization (it's still unlikely gcc does so...)
	}

	if (leftChild) {
		return RecursBorderRender(va, tri->LeftChild,  apex, left, center, depth + 1,  leftChild);
	} else {
		return RecursBorderRender(va, tri->RightChild, rght, apex, center, depth + 1, !leftChild);
	}
}

void Patch::GenerateBorderIndices(CVertexArray* va)
{
    //stub method
}


void Patch::Upload()
{
    //stub method
}

void Patch::SetSquareTexture() const
{
    //stub method
}


void Patch::SwitchRenderMode(int mode)
{
    //stub method
}



// ---------------------------------------------------------------------
// Visibility Update Functions
//

#if 0
void Patch::UpdateVisibility(CCamera* cam)
{
    //stub method
}
#endif


class CPatchInViewChecker : public CReadMap::IQuadDrawer
{
    //stub method
}

bool Patch::IsVisible(const CCamera* cam) const {
	return (lastDrawFrames[cam->GetCamType()] >= globalRendering->drawFrame);
}

