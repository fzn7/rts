#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PathManager.h"
#include "Map/MapInfo.h"
#include "PathConstants.h"
#include "PathEstimator.h"
#include "PathFinder.h"
#include "PathFlowMap.hpp"
#include "PathHeatMap.hpp"
#include "PathLog.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Objects/SolidObjectDef.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "System/myMath.h"

CPathManager::CPathManager()
  : maxResPF(nullptr)
  , medResPE(nullptr)
  , lowResPE(nullptr)
  , pathFlowMap(nullptr)
  , pathHeatMap(nullptr)
  , nextPathID(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CPathManager::~CPathManager()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::int64_t
CPathManager::Finalize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPathManager::FinalizePath(MultiPath* path,
                           const float3 startPos,
                           const float3 goalPos,
                           const bool cantGetCloser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IPath::SearchResult
CPathManager::ArrangePath(MultiPath* newPath,
                          const MoveDef* moveDef,
                          const float3& startPos,
                          const float3& goalPos,
                          CPathFinderDef* pfDef,
                          CSolidObject* caller) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
Request a new multipath, store the result and return a handle-id to it.
*/
unsigned int
CPathManager::RequestPath(CSolidObject* caller,
                          const MoveDef* moveDef,
                          float3 startPos,
                          float3 goalPos,
                          float goalRadius,
                          bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
Store a new multipath into the pathmap.
*/
unsigned int
CPathManager::Store(MultiPath* path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// converts part of a med-res path into a max-res path
void
CPathManager::MedRes2MaxRes(MultiPath& multiPath,
                            const float3& startPos,
                            const CSolidObject* owner,
                            bool synced) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// converts part of a low-res path into a med-res path
void
CPathManager::LowRes2MedRes(MultiPath& multiPath,
                            const float3& startPos,
                            const CSolidObject* owner,
                            bool synced) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
Removes and return the next waypoint in the multipath corresponding to given id.
*/
float3
CPathManager::NextWayPoint(const CSolidObject* owner,
                           unsigned int pathID,
                           unsigned int numRetries,
                           float3 callerPos,
                           float radius,
                           bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Delete a given multipath from the collection.
void
CPathManager::DeletePath(unsigned int pathID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Tells estimators about changes in or on the map.
void
CPathManager::TerrainChange(unsigned int x1,
                            unsigned int z1,
                            unsigned int x2,
                            unsigned int z2,
                            unsigned int /*type*/)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPathManager::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// used to deposit heat on the heat-map as a unit moves along its path
void
CPathManager::UpdatePath(const CSolidObject* owner, unsigned int pathID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// get the waypoints in world-coordinates
void
CPathManager::GetDetailedPath(unsigned pathID,
                              std::vector<float3>& points) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPathManager::GetDetailedPathSquares(unsigned pathID,
                                     std::vector<int2>& points) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPathManager::GetPathWayPoints(unsigned int pathID,
                               std::vector<float3>& points,
                               std::vector<int>& starts) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::uint32_t
CPathManager::GetPathCheckSum() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CPathManager::SetNodeExtraCost(unsigned int x,
                               unsigned int z,
                               float cost,
                               bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CPathManager::SetNodeExtraCosts(const float* costs,
                                unsigned int sizex,
                                unsigned int sizez,
                                bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CPathManager::GetNodeExtraCost(unsigned int x,
                               unsigned int z,
                               bool synced) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const float*
CPathManager::GetNodeExtraCosts(bool synced) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int2
CPathManager::GetNumQueuedUpdates() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
