#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cassert>
#include <limits>
#include <list>

#include "NodeLayer.hpp"
#include "Path.hpp"
#include "PathCache.hpp"
#include "PathSearch.hpp"
#include "Sim/Misc/GlobalConstants.h"

#ifdef QTPFS_TRACE_PATH_SEARCHES
#include "Sim/Misc/GlobalSynced.h"
#endif

#include "System/float3.h"

QTPFS::binary_heap<QTPFS::INode*> QTPFS::PathSearch::openNodes;

void
QTPFS::PathSearch::Initialize(NodeLayer* layer,
                              PathCache* cache,
                              const float3& sourcePoint,
                              const float3& targetPoint,
                              const SRectangle& searchArea)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
QTPFS::PathSearch::Execute(unsigned int searchStateOffset,
                           unsigned int searchMagicNumber)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFS::PathSearch::ResetState(INode* node)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFS::PathSearch::UpdateNode(INode* nextNode,
                              INode* prevNode,
                              unsigned int netPointIdx)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFS::PathSearch::IterateNodes(const std::vector<INode*>& allNodes)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFS::PathSearch::IterateNodeNeighbors(const std::vector<INode*>& nxtNodes)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFS::PathSearch::Finalize(IPath* path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFS::PathSearch::TracePath(IPath* path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFS::PathSearch::SmoothPath(IPath* path) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
QTPFS::PathSearch::SmoothPathIter(IPath* path) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
QTPFS::PathSearch::SharedFinalize(const IPath* srcPath, IPath* dstPath)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const boost::uint64_t
QTPFS::PathSearch::GetHash(boost::uint64_t N, boost::uint32_t k) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
