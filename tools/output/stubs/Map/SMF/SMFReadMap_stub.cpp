/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "SMFReadMap.h"
#include "SMFGroundTextures.h"
#include "SMFGroundDrawer.h"
#include "SMFFormat.h"
#include "Map/MapInfo.h"
#include "Game/Camera.h"
#include "Game/LoadScreen.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/bitops.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/ThreadPool.h"
#include "System/myMath.h"
#include "System/Util.h"

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
}



void CSMFReadMap::ParseHeader()
{
    //stub method
}


void CSMFReadMap::LoadHeightMap()
{
    //stub method
}


void CSMFReadMap::LoadMinimap()
{
    //stub method
}


void CSMFReadMap::InitializeWaterHeightColors()
{
    //stub method
}


void CSMFReadMap::CreateSpecularTex()
{
    //stub method
}

void CSMFReadMap::CreateSplatDetailTextures()
{
    //stub method
}


void CSMFReadMap::CreateGrassTex()
{
    //stub method
}


void CSMFReadMap::CreateDetailTex()
{
    //stub method
}


void CSMFReadMap::CreateShadingTex()
{
    //stub method
}


void CSMFReadMap::CreateNormalTex()
{
    //stub method
}



void CSMFReadMap::UpdateHeightMapUnsynced(const SRectangle& update)
{
    //stub method
}


void CSMFReadMap::UpdateVertexNormalsUnsynced(const SRectangle& update)
{
    //stub method
}


void CSMFReadMap::UpdateFaceNormalsUnsynced(const SRectangle& update)
{
    //stub method
}


void CSMFReadMap::UpdateNormalTexture(const SRectangle& update)
{
    //stub method
}


void CSMFReadMap::UpdateShadingTexture(const SRectangle& update)
{
    //stub method
}


const float CSMFReadMap::GetCenterHeightUnsynced(const int x, const int y) const
{
    //stub method
}


void CSMFReadMap::UpdateShadingTexPart(int idx1, int idx2, unsigned char* dst) const
{
    //stub method
}


float CSMFReadMap::DiffuseSunCoeff(const int x, const int y) const
{
    //stub method
}


float3 CSMFReadMap::GetLightValue(const int x, const int y) const
{
    //stub method
}

void CSMFReadMap::SunChanged()
{
    //stub method
}


void CSMFReadMap::UpdateShadingTexture()
{
    //stub method
}


void CSMFReadMap::DrawMinimap() const
{
    //stub method
}


void CSMFReadMap::GridVisibility(CCamera* cam, IQuadDrawer* qd, float maxDist, int quadSize, int extraSize)
{
    //stub method
}


int CSMFReadMap::GetNumFeatures() { return file.GetNumFeatures(); }
int CSMFReadMap::GetNumFeatureTypes() { return file.GetNumFeatureTypes(); }

void CSMFReadMap::GetFeatureInfo(MapFeatureInfo* f) { file.ReadFeatureInfo(f); }

const char* CSMFReadMap::GetFeatureTypeName(int typeID) { return file.GetFeatureTypeName(typeID); }


unsigned char* CSMFReadMap::GetInfoMap(const std::string& name, MapBitmapInfo* bmInfo)
{
    //stub method
}


void CSMFReadMap::FreeInfoMap(const std::string& name, unsigned char *data)
{
    //stub method
}


void CSMFReadMap::ConfigureTexAnisotropyLevels()
{
    //stub method
}


bool CSMFReadMap::SetLuaTexture(const MapTextureData& td) {
	const unsigned int num = Clamp(int(td.num), 0, NUM_SPLAT_DETAIL_NORMALS - 1);

	switch (td.type) {
		case MAP_BASE_GRASS_TEX: { grassShadingTex.SetLuaTexture(td); } break;
		case MAP_BASE_DETAIL_TEX: { detailTex.SetLuaTexture(td); } break;
		case MAP_BASE_MINIMAP_TEX: { minimapTex.SetLuaTexture(td); } break;
		case MAP_BASE_SHADING_TEX: { shadingTex.SetLuaTexture(td); } break;
		case MAP_BASE_NORMALS_TEX: { normalsTex.SetLuaTexture(td); } break;

		case MAP_SSMF_SPECULAR_TEX: { specularTex.SetLuaTexture(td); } break;
		case MAP_SSMF_NORMALS_TEX: { blendNormalsTex.SetLuaTexture(td); } break;

		case MAP_SSMF_SPLAT_DISTRIB_TEX: { splatDistrTex.SetLuaTexture(td); } break;
		case MAP_SSMF_SPLAT_DETAIL_TEX: { splatDetailTex.SetLuaTexture(td); } break;
		case MAP_SSMF_SPLAT_NORMAL_TEX: { splatNormalTextures[num].SetLuaTexture(td); } break;

		case MAP_SSMF_SKY_REFLECTION_TEX: { skyReflectModTex.SetLuaTexture(td); } break;
		case MAP_SSMF_LIGHT_EMISSION_TEX: { lightEmissionTex.SetLuaTexture(td); } break;
		case MAP_SSMF_PARALLAX_HEIGHT_TEX: { parallaxHeightTex.SetLuaTexture(td); } break;

		default: {
			return false;
		} break;
	}

	groundDrawer->UpdateRenderState();
	return true;
}

void CSMFReadMap::InitGroundDrawer() { groundDrawer = new CSMFGroundDrawer(this); }
void CSMFReadMap::KillGroundDrawer() { SafeDelete(groundDrawer); }

inline CBaseGroundDrawer* CSMFReadMap::GetGroundDrawer() { return groundDrawer; }

