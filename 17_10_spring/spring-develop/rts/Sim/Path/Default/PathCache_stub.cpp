#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>

#include "PathCache.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Log/ILog.h"

#define MAX_CACHE_QUEUE_SIZE 200
#define MAX_PATH_LIFETIME_SECS 6
#define USE_NONCOLLIDABLE_HASH 1

CPathCache::CPathCache(int blocksX, int blocksZ)
  : numBlocksX(blocksX)
  , numBlocksZ(blocksZ)
  , numBlocks(numBlocksX * numBlocksZ)

  , maxCacheSize(0)
  , numCacheHits(0)
  , numCacheMisses(0)
  , numHashCollisions(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CPathCache::AddPath(const IPath::Path* path,
                    const IPath::SearchResult result,
                    const int2 strtBlock,
                    const int2 goalBlock,
                    float goalRadius,
                    int pathType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const CPathCache::CacheItem*
CPathCache::GetCachedPath(const int2 strtBlock,
                          const int2 goalBlock,
                          float goalRadius,
                          int pathType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CPathCache::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CPathCache::RemoveFrontQueItem()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

boost::uint64_t
CPathCache::GetHash(const int2 strtBlk,
                    const int2 goalBlk,
                    boost::uint32_t goalRadius,
                    boost::int32_t pathType) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CPathCache::HashCollision(const CacheItem* ci,
                          const int2 strtBlk,
                          const int2 goalBlk,
                          float goalRadius,
                          int pathType) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
