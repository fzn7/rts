#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Platform/Win/win32.h"

#include "PathEstimator.h"

#include <fstream>
#include <boost/bind.hpp>
#include <boost/thread/barrier.hpp>
#include <boost/thread/thread.hpp>

#include "minizip/zip.h"

#include "PathFinder.h"
#include "PathFinderDef.h"
#include "PathFlowMap.hpp"
#include "PathLog.h"
#include "Game/LoadScreen.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/Archives/IArchive.h"
#include "System/FileSystem/ArchiveLoader.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/Platform/Threading.h"
#include "System/Sync/HsiehHash.h"


CONFIG(int, MaxPathCostsMemoryFootPrint).defaultValue(512).minimumValue(64).description("Maximum memusage (in MByte) of mutlithreaded pathcache generator at loading time.");



static const std::string GetPathCacheDir() {
	return (FileSystem::GetCacheDir() + "/paths/");
}

static size_t GetNumThreads() {
	const size_t numThreads = std::max(0, configHandler->GetInt("PathingThreadCount"));
	const size_t numCores = Threading::GetLogicalCpuCores();
	return ((numThreads == 0)? numCores: numThreads);
}



CPathEstimator::CPathEstimator(IPathFinder* pf, unsigned int BLOCK_SIZE, const std::string& cacheFileName, const std::string& mapFileName)
	: IPathFinder(BLOCK_SIZE)
	, BLOCKS_TO_UPDATE(SQUARES_TO_UPDATE / (BLOCK_SIZE * BLOCK_SIZE) + 1)
	, nextOffsetMessageIdx(0)
	, nextCostMessageIdx(0)
	, pathChecksum(0)
	, offsetBlockNum(nbrOfBlocks.x * nbrOfBlocks.y)
	, costBlockNum(nbrOfBlocks.x * nbrOfBlocks.y)
	, pathFinder(pf)
	, nextPathEstimator(nullptr)
	, blockUpdatePenalty(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CPathEstimator::~CPathEstimator()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const int2* CPathEstimator::GetDirectionVectorsTable() {
	return (&PE_DIRECTION_VECTORS[0]);
}


void CPathEstimator::InitEstimator(const std::string& cacheFileName, const std::string& map)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPathEstimator::InitBlocks()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


__FORCE_ALIGN_STACK__
void CPathEstimator::CalcOffsetsAndPathCosts(unsigned int threadNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPathEstimator::CalculateBlockOffsets(unsigned int blockIdx, unsigned int threadNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPathEstimator::EstimatePathCosts(unsigned int blockIdx, unsigned int threadNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Move around the blockPos a bit, so we `surround` unpassable blocks.
 */
int2 CPathEstimator::FindOffset(const MoveDef& moveDef, unsigned int blockX, unsigned int blockZ) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Calculate all vertices connected from the given block
 */
void CPathEstimator::CalculateVertices(const MoveDef& moveDef, int2 block, unsigned int thread)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Calculate requested vertex
 */
void CPathEstimator::CalculateVertex(
	const MoveDef& moveDef,
	int2 parentBlock,
	unsigned int direction,
	unsigned int threadNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Mark affected blocks as obsolete
 */
void CPathEstimator::MapChanged(unsigned int x1, unsigned int z1, unsigned int x2, unsigned z2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Update some obsolete blocks using the FIFO-principle
 */
void CPathEstimator::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const CPathCache::CacheItem* CPathEstimator::GetCache(const int2 strtBlock, const int2 goalBlock, float goalRadius, int pathType, const bool synced) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CPathEstimator::AddCache(const IPath::Path* path, const IPath::SearchResult result, const int2 strtBlock, const int2 goalBlock, float goalRadius, int pathType, const bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Performs the actual search.
 */
IPath::SearchResult CPathEstimator::DoSearch(const MoveDef& moveDef, const CPathFinderDef& peDef, const CSolidObject* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Test the accessability of a block and its value,
 * possibly also add it to the open-blocks pqueue.
 */
bool CPathEstimator::TestBlock(
	const MoveDef& moveDef,
	const CPathFinderDef& peDef,
	const PathNode* parentOpenBlock,
	const CSolidObject* owner,
	const unsigned int pathDir,
	const unsigned int /*blockStatus*/,
	float /*speedMod*/
) {
	testedBlocks++;

	// initial calculations of the new block
	const int2 testBlockPos = parentOpenBlock->nodePos + PE_DIRECTION_VECTORS[pathDir];
	const int2 goalBlockPos = {int(peDef.goalSquareX / BLOCK_SIZE), int(peDef.goalSquareZ / BLOCK_SIZE)};

	const unsigned int testBlockIdx = BlockPosToIdx(testBlockPos);

	// bounds-check
	if ((unsigned)testBlockPos.x >= nbrOfBlocks.x) return false;
	if ((unsigned)testBlockPos.y >= nbrOfBlocks.y) return false;

	// check if the block is unavailable
	if (blockStates.nodeMask[testBlockIdx] & (PATHOPT_BLOCKED | PATHOPT_CLOSED))
		return false;

	// read precached vertex costs
	const unsigned int pathTypeBaseIdx = moveDef.pathType * blockStates.GetSize() * PATH_DIRECTION_VERTICES;
	const unsigned int blockNumBaseIdx = parentOpenBlock->nodeNum * PATH_DIRECTION_VERTICES;
	const unsigned int vertexIdx = pathTypeBaseIdx + blockNumBaseIdx + GetBlockVertexOffset(pathDir, nbrOfBlocks.x);
	assert(vertexIdx < vertexCosts.size());


	if (vertexCosts[vertexIdx] >= PATHCOST_INFINITY) {
		// warning: we cannot naively set PATHOPT_BLOCKED here;
		// vertexCosts[] depends on the direction and nodeMask
		// does not
		// we would have to save the direction via PATHOPT_LEFT
		// etc. in the nodeMask but that is complicated and not
		// worth it: would just save the vertexCosts[] lookup
		//
		// blockStates.nodeMask[testBlockIdx] |= (PathDir2PathOpt(pathDir) | PATHOPT_BLOCKED);
		// dirtyBlocks.push_back(testBlockIdx);
		return false;
	}

	// check if the block is out of constraints
	const int2 square = blockStates.peNodeOffsets[moveDef.pathType][testBlockIdx];
	if (!peDef.WithinConstraints(square.x, square.y)) {
		blockStates.nodeMask[testBlockIdx] |= PATHOPT_BLOCKED;
		dirtyBlocks.push_back(testBlockIdx);
		return false;
	}

	// constraintDisabled is a hackish way to make sure we don't check this in CalculateVertices
	if (testBlockPos == goalBlockPos && peDef.needPath) {
		IPath::Path path;

		// if we have expanded the goal-block, check if a valid
		// max-resolution path exists (from where we entered it
		// to the actual goal position) since there might still
		// be impassable terrain in between
		//
		// const float3 gWorldPos = {            testBlockPos.x * BLOCK_PIXEL_SIZE * 1.0f, 0.0f,             testBlockPos.y * BLOCK_PIXEL_SIZE * 1.0f};
		// const float3 sWorldPos = {parentOpenBlock->nodePos.x * BLOCK_PIXEL_SIZE * 1.0f, 0.0f, parentOpenBlock->nodePos.y * BLOCK_PIXEL_SIZE * 1.0f};
		const int idx = BlockPosToIdx(testBlockPos);
		const int2 testSquare = blockStates.peNodeOffsets[moveDef.pathType][idx];

		const float3 sWorldPos = SquareToFloat3(testSquare.x, testSquare.y);
		const float3 gWorldPos = peDef.goal;

		if (sWorldPos.SqDistance2D(gWorldPos) > peDef.sqGoalRadius) {
			CRectangularSearchConstraint pfDef = CRectangularSearchConstraint(sWorldPos, gWorldPos, peDef.sqGoalRadius, BLOCK_SIZE); // sets goalSquare{X,Z}
			pfDef.testMobile     = false;
			pfDef.needPath       = false;
			pfDef.exactPath      = true;
			pfDef.dirIndependent = true;
			const IPath::SearchResult searchRes = pathFinder->GetPath(moveDef, pfDef, owner, sWorldPos, path, MAX_SEARCHED_NODES_PF >> 3);

			if (searchRes != IPath::Ok) {
				// we cannot set PATHOPT_BLOCKED here either, result
				// depends on direction of entry from the parent node
				//
				// blockStates.nodeMask[testBlockIdx] |= PATHOPT_BLOCKED;
				// dirtyBlocks.push_back(testBlockIdx);
				return false;
			}
		}
	}


	// evaluate this node (NOTE the max-resolution indexing for {flow,extra}Cost)
	//const float flowCost  = (peDef.testMobile) ? (PathFlowMap::GetInstance())->GetFlowCost(square.x, square.y, moveDef, PathDir2PathOpt(pathDir)) : 0.0f;
	const float extraCost = blockStates.GetNodeExtraCost(square.x, square.y, peDef.synced);
	const float nodeCost  = vertexCosts[vertexIdx] + extraCost;

	const float gCost = parentOpenBlock->gCost + nodeCost;
	const float hCost = peDef.Heuristic(square.x, square.y);
	const float fCost = gCost + hCost;

	// already in the open set?
	if (blockStates.nodeMask[testBlockIdx] & PATHOPT_OPEN) {
		// check if new found path is better or worse than the old one
		if (blockStates.fCost[testBlockIdx] <= fCost)
			return true;

		// no, clear old path data
		blockStates.nodeMask[testBlockIdx] &= ~PATHOPT_CARDINALS;
	}

	// look for improvements
	if (hCost < mGoalHeuristic) {
		mGoalBlockIdx = testBlockIdx;
		mGoalHeuristic = hCost;
	}

	// store this block as open
	openBlockBuffer.SetSize(openBlockBuffer.GetSize() + 1);
	assert(openBlockBuffer.GetSize() < MAX_SEARCHED_NODES_PE);

	PathNode* ob = openBlockBuffer.GetNode(openBlockBuffer.GetSize());
		ob->fCost   = fCost;
		ob->gCost   = gCost;
		ob->nodePos = testBlockPos;
		ob->nodeNum = testBlockIdx;
	openBlocks.push(ob);

	blockStates.SetMaxCost(NODE_COST_F, std::max(blockStates.GetMaxCost(NODE_COST_F), fCost));
	blockStates.SetMaxCost(NODE_COST_G, std::max(blockStates.GetMaxCost(NODE_COST_G), gCost));

	// mark this block as open
	blockStates.fCost[testBlockIdx] = fCost;
	blockStates.gCost[testBlockIdx] = gCost;
	blockStates.nodeMask[testBlockIdx] |= (PathDir2PathOpt(pathDir) | PATHOPT_OPEN);

	dirtyBlocks.push_back(testBlockIdx);
	return true;
}


/**
 * Recreate the path taken to the goal
 */
IPath::SearchResult CPathEstimator::FinishSearch(const MoveDef& moveDef, const CPathFinderDef& pfDef, IPath::Path& foundPath) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Try to read offset and vertices data from file, return false on failure
 */
bool CPathEstimator::ReadFile(const std::string& cacheFileName, const std::string& map)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Try to write offset and vertex data to file.
 */
void CPathEstimator::WriteFile(const std::string& cacheFileName, const std::string& map)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


boost::uint32_t CPathEstimator::CalcChecksum() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * Returns a hash-code identifying the dataset of this estimator.
 */
unsigned int CPathEstimator::Hash() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
