#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/bind.hpp>
#include <boost/cstdint.hpp>
#include <boost/thread.hpp>
#include <boost/thread/condition.hpp>

#include "System/ThreadPool.h"

#include "PathDefines.hpp"
#include "PathManager.hpp"

#include "Game/GameSetup.h"
#include "Game/LoadScreen.h"
#include "Map/MapInfo.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"
#include "Sim/Objects/SolidObject.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"
#include "System/Rectangle.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"

#ifdef GetTempPath
#undef GetTempPath
#undef GetTempPathA
#endif

#define NUL_RECTANGLE SRectangle(0, 0, 0, 0)
#define MAP_RECTANGLE SRectangle(0, 0, mapDims.mapx, mapDims.mapy)

namespace QTPFS {
struct PMLoadScreen
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int PathManager::LAYERS_PER_UPDATE;
unsigned int PathManager::MAX_TEAM_SEARCHES;
}

QTPFS::PathManager::PathManager()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

QTPFS::PathManager::~PathManager()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::int64_t
QTPFS::PathManager::Finalize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::InitStatic()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::Load()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::uint64_t
QTPFS::PathManager::GetMemFootPrint() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::SpawnBoostThreads(MemberFunc f, const SRectangle& r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::InitNodeLayersThreaded(const SRectangle& rect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
void
QTPFS::PathManager::InitNodeLayersThread(unsigned int threadNum,
                                         unsigned int numThreads,
                                         const SRectangle& rect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::InitNodeLayer(unsigned int layerNum, const SRectangle& r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::UpdateNodeLayersThreaded(const SRectangle& rect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
void
QTPFS::PathManager::UpdateNodeLayersThread(unsigned int threadNum,
                                           unsigned int numThreads,
                                           const SRectangle& rect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// called in the non-staggered (#ifndef QTPFS_STAGGERED_LAYER_UPDATES)
// layer update scheme and during initialization; see ::TerrainChange
void
QTPFS::PathManager::UpdateNodeLayer(unsigned int layerNum, const SRectangle& r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef QTPFS_STAGGERED_LAYER_UPDATES
void
QTPFS::PathManager::QueueNodeLayerUpdates(const SRectangle& r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::ExecQueuedNodeLayerUpdates(unsigned int layerNum,
                                               bool flushQueue)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

std::string
QTPFS::PathManager::GetCacheDirName(boost::uint32_t mapCheckSum,
                                    boost::uint32_t modCheckSum) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::Serialize(const std::string& cacheFileDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// note that this is called twice per object:
// height-map changes, then blocking-map does
void
QTPFS::PathManager::TerrainChange(unsigned int x1,
                                  unsigned int z1,
                                  unsigned int x2,
                                  unsigned int z2,
                                  unsigned int type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
void
QTPFS::PathManager::ThreadUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::ExecuteQueuedSearches(unsigned int pathType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::PathManager::ExecuteSearch(PathSearchList& searches,
                                  PathSearchListIt& searchesIt,
                                  NodeLayer& nodeLayer,
                                  PathCache& pathCache,
                                  unsigned int pathType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::QueueDeadPathSearches(unsigned int pathType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
QTPFS::PathManager::QueueSearch(const IPath* oldPath,
                                const CSolidObject* object,
                                const MoveDef* moveDef,
                                const float3& sourcePoint,
                                const float3& targetPoint,
                                const float radius,
                                const bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::UpdatePath(const CSolidObject* owner, unsigned int pathID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::DeletePath(unsigned int pathID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
QTPFS::PathManager::RequestPath(CSolidObject* object,
                                const MoveDef* moveDef,
                                float3 sourcePoint,
                                float3 targetPoint,
                                float radius,
                                bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::PathManager::PathUpdated(unsigned int pathID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
QTPFS::PathManager::NextWayPoint(const CSolidObject*, // owner
                                 unsigned int pathID,
                                 unsigned int, // numRetries
                                 float3 point,
                                 float, // radius,
                                 bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::PathManager::GetPathWayPoints(unsigned int pathID,
                                     std::vector<float3>& points,
                                     std::vector<int>& starts) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int2
QTPFS::PathManager::GetNumQueuedUpdates() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
