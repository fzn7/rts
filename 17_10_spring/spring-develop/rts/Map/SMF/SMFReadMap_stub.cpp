#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SMFReadMap.h"
#include "Game/Camera.h"
#include "Game/LoadScreen.h"
#include "Map/MapInfo.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "SMFFormat.h"
#include "SMFGroundDrawer.h"
#include "SMFGroundTextures.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/ThreadPool.h"
#include "System/Util.h"
#include "System/bitops.h"
#include "System/myMath.h"

#define SSMF_UNCOMPRESSED_NORMALS 0

using std::max;

CONFIG(bool, GroundNormalTextureHighPrecision).defaultValue(false);
CONFIG(float, SMFTexAniso).defaultValue(4.0f).minimumValue(0.0f);
CONFIG(float, SSMFTexAniso).defaultValue(4.0f).minimumValue(0.0f);

CSMFReadMap::CSMFReadMap(std::string mapname)
  : CEventClient("[CSMFReadMap]", 271950, false)
  , file(mapname)
  , groundDrawer(NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::ParseHeader()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::LoadHeightMap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::LoadMinimap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::InitializeWaterHeightColors()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::CreateSpecularTex()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::CreateSplatDetailTextures()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::CreateGrassTex()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::CreateDetailTex()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::CreateShadingTex()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::CreateNormalTex()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::UpdateHeightMapUnsynced(const SRectangle& update)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::UpdateVertexNormalsUnsynced(const SRectangle& update)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::UpdateFaceNormalsUnsynced(const SRectangle& update)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::UpdateNormalTexture(const SRectangle& update)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::UpdateShadingTexture(const SRectangle& update)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const float
CSMFReadMap::GetCenterHeightUnsynced(const int x, const int y) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::UpdateShadingTexPart(int idx1, int idx2, unsigned char* dst) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CSMFReadMap::DiffuseSunCoeff(const int x, const int y) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CSMFReadMap::GetLightValue(const int x, const int y) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::SunChanged()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::UpdateShadingTexture()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::DrawMinimap() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::GridVisibility(CCamera* cam,
                            IQuadDrawer* qd,
                            float maxDist,
                            int quadSize,
                            int extraSize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CSMFReadMap::GetNumFeatures()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
CSMFReadMap::GetNumFeatureTypes()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::GetFeatureInfo(MapFeatureInfo* f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const char*
CSMFReadMap::GetFeatureTypeName(int typeID)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned char*
CSMFReadMap::GetInfoMap(const std::string& name, MapBitmapInfo* bmInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::FreeInfoMap(const std::string& name, unsigned char* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::ConfigureTexAnisotropyLevels()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSMFReadMap::SetLuaTexture(const MapTextureData& td)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFReadMap::InitGroundDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CSMFReadMap::KillGroundDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline CBaseGroundDrawer*
CSMFReadMap::GetGroundDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
