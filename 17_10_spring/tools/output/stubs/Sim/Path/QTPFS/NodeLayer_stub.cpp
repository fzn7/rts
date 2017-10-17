#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <limits>

#include "Node.hpp"
#include "NodeLayer.hpp"
#include "PathManager.hpp"

#include "Map/MapInfo.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"
#include "System/myMath.h"

unsigned int QTPFS::NodeLayer::NUM_SPEEDMOD_BINS;
float QTPFS::NodeLayer::MIN_SPEEDMOD_VALUE;
float QTPFS::NodeLayer::MAX_SPEEDMOD_VALUE;

QTPFS::NodeLayer::NodeLayer()
  : layerNumber(0)
  , numLeafNodes(0)
  , updateCounter(0)
  , xsize(0)
  , zsize(0)
  , maxRelSpeedMod(0.0f)
  , avgRelSpeedMod(0.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::NodeLayer::RegisterNode(INode* n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::NodeLayer::Init(unsigned int layerNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::NodeLayer::Clear()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef QTPFS_STAGGERED_LAYER_UPDATES
void
QTPFS::NodeLayer::QueueUpdate(const SRectangle& r, const MoveDef* md)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::NodeLayer::ExecQueuedUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

bool
QTPFS::NodeLayer::Update(const SRectangle& r,
                         const MoveDef* md,
                         const std::vector<float>* luSpeedMods,
                         const std::vector<int>* luBlockBits)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

QTPFS::NodeLayer::SpeedBinType
QTPFS::NodeLayer::GetSpeedModBin(float absSpeedMod, float relSpeedMod) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// update the neighbor-cache for (a chunk of) the leaf
// nodes in this layer; this amortizes (in theory) the
// cost of doing it "on-demand" in PathSearch::Iterate
// when QTPFS_CONSERVATIVE_NEIGHBOR_CACHE_UPDATES
//
// NOTE:
//   exclusive to the QTPFS_STAGGERED_LAYER_UPDATES path,
//   and makes no sense to use with the non-conservative
//   update scheme
//
#ifdef QTPFS_AMORTIZED_NODE_NEIGHBOR_CACHE_UPDATES
#ifdef QTPFS_CONSERVATIVE_NEIGHBOR_CACHE_UPDATES
void
QTPFS::NodeLayer::ExecNodeNeighborCacheUpdate(unsigned int currFrameNum,
                                              unsigned int currMagicNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif
#endif

void
QTPFS::NodeLayer::ExecNodeNeighborCacheUpdates(const SRectangle& ur,
                                               unsigned int currMagicNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
