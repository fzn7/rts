#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SM3Map.h"
#include "SM3GroundDrawer.h"
#include "terrain/TerrainNode.h"

#include "Game/Camera.h"
#include "Game/GameSetup.h"
#include "Game/LoadScreen.h"
#include "Map/MapInfo.h"
#include "Map/MapParser.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/byteorder.h"
#include "System/TdfParser.h"
#include "System/Util.h"

#include <fstream>
#include <stdexcept>

CONFIG(bool, SM3ForceFallbackTex).defaultValue(false);
CONFIG(int, SM3MaxTextureStages).defaultValue(10);

struct Sm3LoadCB : terrain::ILoadCallback
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CR_BIND_DERIVED(CSM3ReadMap, CReadMap, (""))
CR_REG_METADATA(CSM3ReadMap,
                (
                  // FIXME save unsynced heightmap?
                  CR_IGNORED(groundDrawer),
                  CR_IGNORED(renderer),
                  CR_IGNORED(minimapTexture),
                  CR_IGNORED(infoMaps),
                  CR_IGNORED(featureTypes),
                  CR_IGNORED(featureInfo),
                  CR_IGNORED(numFeatures),
                  CR_IGNORED(tmpFrustum)));

CSM3ReadMap::CSM3ReadMap(const std::string& mapName)
  : groundDrawer(NULL)
  , minimapTexture(0)
  , numFeatures(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSM3ReadMap::~CSM3ReadMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3ReadMap::ConfigNotify(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBaseGroundDrawer*
CSM3ReadMap::GetGroundDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSM3ReadMap::InitGroundDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3ReadMap::KillGroundDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3ReadMap::UpdateHeightMapUnsynced(const SRectangle& update)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3ReadMap::DrawMinimap() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Feature creation
int
CSM3ReadMap::GetNumFeatures()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CSM3ReadMap::GetNumFeatureTypes()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3ReadMap::GetFeatureInfo(MapFeatureInfo* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
CSM3ReadMap::GetFeatureTypeName(int typeID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3ReadMap::LoadFeatureData()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSM3ReadMap::InfoMap::InfoMap()
  : w(0)
  , h(0)
  , data(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Bitmaps (such as metal map, grass map, ...), handling them with a string as
// type seems flexible... Some map types:
//   "metal"  -  metalmap
//   "grass"  -  grassmap
unsigned char*
CSM3ReadMap::GetInfoMap(const std::string& name, MapBitmapInfo* bm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3ReadMap::FreeInfoMap(const std::string& name, unsigned char* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct DrawGridParms
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSM3ReadMap::GridVisibility(CCamera* cam,
                            IQuadDrawer* cb,
                            float maxDist,
                            int quadSize,
                            int extraSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
