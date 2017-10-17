#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstdlib>

#include "MapDamage.h"
#include "MapInfo.h"
#include "MetalMap.h"
#include "ReadMap.h"
// #include "SM3/SM3Map.h"
#include "Game/LoadScreen.h"
#include "SMF/SMFReadMap.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Misc/RectangleOptimizer.h"
#include "System/Sync/HsiehHash.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "System/bitops.h"
#include "System/myMath.h"

#ifdef USE_UNSYNCED_HEIGHTMAP
#include "Game/GlobalUnsynced.h"
#include "Sim/Misc/LosHandler.h"
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// assigned to in CGame::CGame ("readMap = CReadMap::LoadMap(mapname)")
CReadMap* readMap = nullptr;
MapDimensions mapDims;

#ifdef USE_UNSYNCED_HEIGHTMAP
#define HEIGHTMAP_DIGESTS                                                      \
    CR_MEMBER(syncedHeightMapDigests), CR_MEMBER(unsyncedHeightMapDigests),
#else
#define HEIGHTMAP_DIGESTS
#endif

CR_BIND(MapDimensions, ())
CR_REG_METADATA(MapDimensions,
                (CR_MEMBER(mapx),
                 CR_MEMBER(mapxm1),
                 CR_MEMBER(mapxp1),

                 CR_MEMBER(mapy),
                 CR_MEMBER(mapym1),
                 CR_MEMBER(mapyp1),

                 CR_MEMBER(mapSquares),

                 CR_MEMBER(hmapx),
                 CR_MEMBER(hmapy),
                 CR_MEMBER(pwr2mapx),
                 CR_MEMBER(pwr2mapy)))

CR_BIND_INTERFACE(CReadMap)
CR_REG_METADATA(CReadMap,
                (CR_MEMBER(metalMap),
                 CR_IGNORED(initHeightBounds),
                 CR_IGNORED(currHeightBounds),
                 CR_IGNORED(boundingRadius),
                 CR_IGNORED(mapChecksum),
                 CR_IGNORED(heightMapSyncedPtr),
                 CR_IGNORED(heightMapUnsyncedPtr),
                 CR_IGNORED(originalHeightMap),
                 CR_IGNORED(centerHeightMap),
                 CR_IGNORED(mipCenterHeightMaps),
                 CR_IGNORED(mipPointerHeightMaps),
                 CR_IGNORED(visVertexNormals),
                 CR_IGNORED(faceNormalsSynced),
                 CR_IGNORED(faceNormalsUnsynced),
                 CR_IGNORED(centerNormalsSynced),
                 CR_IGNORED(centerNormalsUnsynced),
                 CR_IGNORED(centerNormals2DSynced),
                 CR_IGNORED(centerNormals2DUnsynced),
                 CR_IGNORED(slopeMap),
                 CR_IGNORED(sharedCornerHeightMaps),
                 CR_IGNORED(sharedCenterHeightMaps),
                 CR_IGNORED(sharedFaceNormals),
                 CR_IGNORED(sharedCenterNormals),
                 CR_IGNORED(sharedCenterNormals2D),
                 CR_IGNORED(sharedSlopeMaps),
                 CR_MEMBER(typeMap),
                 CR_MEMBER(unsyncedHeightMapUpdates),
                 CR_MEMBER(unsyncedHeightMapUpdatesTemp),
                 HEIGHTMAP_DIGESTS CR_POSTLOAD(PostLoad),
                 CR_SERIALIZER(Serialize)))

MapTexture::~MapTexture()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CReadMap*
CReadMap::LoadMap(const std::string& mapname)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#ifdef USING_CREG
void
CReadMap::Serialize(creg::ISerializer* s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif // USING_CREG

CReadMap::CReadMap()
  : metalMap(nullptr)
  , heightMapSyncedPtr(nullptr)
  , heightMapUnsyncedPtr(nullptr)
  , mapChecksum(0)
  , boundingRadius(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::Initialize()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CReadMap::CalcHeightmapChecksum()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CReadMap::CalcTypemapChecksum()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::UpdateDraw(bool firstCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::UpdateHeightMapSynced(SRectangle rect, bool initialize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::UpdateCenterHeightmap(const SRectangle& rect, bool initialize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::UpdateMipHeightmaps(const SRectangle& rect, bool initialize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::UpdateFaceNormals(const SRectangle& rect, bool initialize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::UpdateSlopemap(const SRectangle& rect, bool initialize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/// split the update into multiple invididual (los-square) chunks:
void
CReadMap::HeightMapUpdateLOSCheck(const SRectangle& rect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::InitHeightMapDigestsVectors()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CReadMap::HasHeightMapChanged(const int lmx, const int lmy)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::UpdateLOS(const SRectangle& rect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CReadMap::BecomeSpectator()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CReadMap::HasVisibleWater() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
CReadMap::HasOnlyVoidWater() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
