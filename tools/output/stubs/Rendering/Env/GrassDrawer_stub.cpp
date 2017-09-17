/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cmath>

#include "GrassDrawer.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Misc/Wind.h"
#include "System/EventHandler.h"
#include "System/myMath.h"
#include "System/Config/ConfigHandler.h"
#include "System/Color.h"
#include "System/Exceptions.h"
#include "System/UnsyncedRNG.h"
#include "System/Util.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileHandler.h"

CONFIG(int, GrassDetail).defaultValue(7).headlessValue(0).minimumValue(0).description("Sets how detailed the engine rendered grass will be on any given map.");

static const float turfSize        = 20.0f;            // single turf size
static const float partTurfSize    = turfSize * 1.0f;  // single turf size
static const int   grassSquareSize = 4;                // mapsquares per grass square
static const int   grassBlockSize  = 4;                // grass squares per grass block
static const int   blockMapSize    = grassSquareSize * grassBlockSize;

static const int   gSSsq = SQUARE_SIZE * grassSquareSize;
static const int   bMSsq = SQUARE_SIZE * blockMapSize;

static UnsyncedRNG rng;



static float GetCamDistOfGrassBlock(const int x, const int y, const bool square = false)
{
    //stub method
}


static const bool GrassSort(const CGrassDrawer::GrassStruct* a, const CGrassDrawer::GrassStruct* b) {
	const float distA = GetCamDistOfGrassBlock((a->posX + 0.5f) * grassBlockSize, (a->posZ + 0.5f) * grassBlockSize, true);
	const float distB = GetCamDistOfGrassBlock((b->posX + 0.5f) * grassBlockSize, (b->posZ + 0.5f) * grassBlockSize, true);
	return (distA > distB);
}

static const bool GrassSortNear(const CGrassDrawer::InviewNearGrass& a, const CGrassDrawer::InviewNearGrass& b) {
	return (a.dist > b.dist);
}



//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
/// CGrassBlockDrawer

class CGrassBlockDrawer: public CReadMap::IQuadDrawer
{
    //stub method
}

CGrassDrawer::~CGrassDrawer()
{
    //stub method
}


CGrassDrawer::GrassStruct::~GrassStruct() {
	delete va; va = nullptr;
}


void CGrassDrawer::ChangeDetail(int detail) {
	// TODO: get rid of the magic constants
	const int detail_lim = std::min(3, detail);
	maxGrassDist = 800 + std::sqrt((float) detail) * 240;
	maxDetailedDist = 146 + detail * 24;
	detailedBlocks = int((maxDetailedDist + 128.f * 1.5f) / bMSsq) + 1;
	numTurfs = 3 + int(detail_lim * 0.5f);
	strawPerTurf = std::min(50 + int(std::sqrt((float)detail_lim) * 10), mapInfo->grass.maxStrawsPerTurf);

	// recreate textures & XBOs
	CreateGrassDispList(grassDL);
	CreateFarTex();

	// reset  all cached blocks
	for (GrassStruct& pGS: grass) {
		ResetPos(pGS.posX, pGS.posZ);
	}
}


void CGrassDrawer::ConfigNotify(const std::string& key, const std::string& value) {
	if (key == "GrassDetail") {
		ChangeDetail(std::atoi(value.c_str()));
	}
}


void CGrassDrawer::LoadGrassShaders() {
	if (!globalRendering->haveGLSL) {
		return;
	}

	#define sh shaderHandler
	grassShaders.resize(GRASS_PROGRAM_LAST, NULL);

	static const std::string shaderNames[GRASS_PROGRAM_LAST] = {
		"grassNearAdvShader",
		"grassDistAdvShader",
		"grassShadGenShader"
	};
	static const std::string shaderDefines[GRASS_PROGRAM_LAST] = {
		"#define DISTANCE_NEAR\n",
		"#define DISTANCE_FAR\n",
		"#define SHADOW_GEN\n"
	};

	for (int i = 0; i < GRASS_PROGRAM_LAST; i++) {
		grassShaders[i] = sh->CreateProgramObject("[GrassDrawer]", shaderNames[i] + "GLSL", false);
		grassShaders[i]->AttachShaderObject(sh->CreateShaderObject("GLSL/GrassVertProg.glsl", shaderDefines[i], GL_VERTEX_SHADER));
		grassShaders[i]->AttachShaderObject(sh->CreateShaderObject("GLSL/GrassFragProg.glsl", shaderDefines[i], GL_FRAGMENT_SHADER));
		grassShaders[i]->Link();

		grassShaders[i]->Enable();
		grassShaders[i]->SetUniform("mapSizePO2", 1.0f / (mapDims.pwr2mapx * SQUARE_SIZE), 1.0f / (mapDims.pwr2mapy * SQUARE_SIZE));
		grassShaders[i]->SetUniform("mapSize",    1.0f / (mapDims.mapx     * SQUARE_SIZE), 1.0f / (mapDims.mapy     * SQUARE_SIZE));
		grassShaders[i]->SetUniform("bladeTex",        0);
		grassShaders[i]->SetUniform("grassShadingTex", 1);
		grassShaders[i]->SetUniform("shadingTex",      2);
		grassShaders[i]->SetUniform("infoMap",         3);
		grassShaders[i]->SetUniform("shadowMap",       4);
		grassShaders[i]->SetUniform("specularTex",     5);
		grassShaders[i]->Disable();
		grassShaders[i]->Validate();

		if (!grassShaders[i]->IsValid()) {
			grassOff = true;
			return;
		}
	}

	#undef sh
}


void CGrassDrawer::EnableShader(const GrassShaderProgram type) {
	const float3 windSpeed =
		wind.GetCurrentDirection() *
		wind.GetCurrentStrength() *
		mapInfo->grass.bladeWaveScale;

	grassShader = grassShaders[type];
	grassShader->SetFlag("HAVE_INFOTEX", infoTextureHandler->IsEnabled());
	grassShader->SetFlag("HAVE_SHADOWS", shadowHandler->ShadowsLoaded());
	grassShader->Enable();

	grassShader->SetUniform("frame", gs->frameNum + globalRendering->timeOffset);
	grassShader->SetUniform3v("windSpeed", &windSpeed.x);
	grassShader->SetUniform3v("camPos",    &camera->GetPos().x);
	grassShader->SetUniform3v("camDir",    &camera->GetDir().x);
	grassShader->SetUniform3v("camUp",     &camera->GetUp().x);
	grassShader->SetUniform3v("camRight",  &camera->GetRight().x);

	grassShader->SetUniform("groundShadowDensity", mapInfo->light.groundShadowDensity);
	grassShader->SetUniformMatrix4x4("shadowMatrix", false, shadowHandler->GetShadowMatrixRaw());
	grassShader->SetUniform4v("shadowParams", &shadowHandler->GetShadowParams().x);

	grassShader->SetUniform3v("ambientLightColor",  &sunLighting->unitAmbientColor.x);
	grassShader->SetUniform3v("diffuseLightColor",  &sunLighting->unitDiffuseColor.x);
	grassShader->SetUniform3v("specularLightColor", &sunLighting->unitSpecularColor.x);
	grassShader->SetUniform3v("sunDir",             &mapInfo->light.sunDir.x);
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

struct STurfParams {
	float x, y, rotation;
};


static STurfParams GetTurfParams(UnsyncedRNG& rng, const int x, const int y)
{
    //stub method
}



void CGrassDrawer::DrawNear(const std::vector<InviewNearGrass>& inviewGrass)
{
    //stub method
}


void CGrassDrawer::DrawBillboard(const int x, const int y, const float dist, VA_TYPE_TN* va_tn)
{
    //stub method
}


void CGrassDrawer::DrawFarBillboards(const std::vector<GrassStruct*>& inviewFarGrass)
{
    //stub method
}


void CGrassDrawer::DrawNearBillboards(const std::vector<InviewNearGrass>& inviewNearGrass)
{
    //stub method
}


void CGrassDrawer::Update()
{
    //stub method
}


void CGrassDrawer::Draw()
{
    //stub method
}


void CGrassDrawer::DrawShadow()
{
    //stub method
}


void CGrassDrawer::SetupGlStateNear()
{
    //stub method
}


void CGrassDrawer::ResetGlStateNear()
{
    //stub method
}


void CGrassDrawer::SetupGlStateFar()
{
    //stub method
}


void CGrassDrawer::ResetGlStateFar()
{
    //stub method
}


void CGrassDrawer::CreateGrassDispList(int listNum)
{
    //stub method
}

void CGrassDrawer::CreateGrassBladeTex(unsigned char* buf)
{
    //stub method
}

void CGrassDrawer::CreateFarTex()
{
    //stub method
}


void CGrassDrawer::ResetPos(const int grassBlockX, const int grassBlockZ)
{
    //stub method
}


void CGrassDrawer::ResetPos(const float3& pos)
{
    //stub method
}


void CGrassDrawer::AddGrass(const float3& pos)
{
    //stub method
}


void CGrassDrawer::RemoveGrass(const float3& pos)
{
    //stub method
}


void CGrassDrawer::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
}
