/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SMFReadMap.h"
#include "SMFGroundDrawer.h"
#include "SMFGroundTextures.h"
#include "SMFRenderState.h"
#include "Game/Camera.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Map/SMF/Legacy/LegacyMeshDrawer.h"
#include "Map/SMF/ROAM/RoamMeshDrawer.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Shaders/Shader.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/FastMath.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/TimeProfiler.h"

CONFIG(int, GroundDetail).defaultValue(60).headlessValue(0).minimumValue(0).maximumValue(200).description("Controls how detailed the map geometry will be. On lowered settings, cliffs may appear to be jagged or \"melting\".");
CONFIG(bool, MapBorder).defaultValue(true).description("Draws a solid border at the edges of the map.");


CONFIG(int, MaxDynamicMapLights)
	.defaultValue(1)
	.minimumValue(0);

CONFIG(bool, AdvMapShading).defaultValue(true).safemodeValue(false).description("Enable shaders for terrain rendering and enable so more effects.");
CONFIG(bool, AllowDeferredMapRendering).defaultValue(false).safemodeValue(false);

CONFIG(int, ROAM)
	.defaultValue(Patch::VBO)
	.safemodeValue(Patch::DL)
	.minimumValue(0)
	.maximumValue(Patch::VA)
	.description("Use ROAM for terrain mesh rendering. 0:=disable ROAM, 1=VBO mode, 2=DL mode, 3=VA mode");


CSMFGroundDrawer::CSMFGroundDrawer(CSMFReadMap* rm)
	: smfMap(rm)
	, meshDrawer(NULL)
{
    //stub method
}

CSMFGroundDrawer::~CSMFGroundDrawer()
{
    //stub method
}



IMeshDrawer* CSMFGroundDrawer::SwitchMeshDrawer(int mode)
{
    //stub method
}



void CSMFGroundDrawer::CreateWaterPlanes(bool camOufOfMap) {
	glDisable(GL_TEXTURE_2D);
	glDepthMask(GL_FALSE);

	const float xsize = (smfMap->mapSizeX) >> 2;
	const float ysize = (smfMap->mapSizeZ) >> 2;
	const float size = std::min(xsize, ysize);

	CVertexArray* va = GetVertexArray();
	va->Initialize();

	const unsigned char fogColor[4] = {
		(unsigned char)(255 * sky->fogColor[0]),
		(unsigned char)(255 * sky->fogColor[1]),
		(unsigned char)(255 * sky->fogColor[2]),
		 255
	};

	const unsigned char planeColor[4] = {
		(unsigned char)(255 * mapInfo->water.planeColor[0]),
		(unsigned char)(255 * mapInfo->water.planeColor[1]),
		(unsigned char)(255 * mapInfo->water.planeColor[2]),
		 255
	};

	const float alphainc = fastmath::PI2 / 32;
	float alpha,r1,r2;

	float3 p(0.0f, 0.0f, 0.0f);

	for (int n = (camOufOfMap) ? 0 : 1; n < 4 ; ++n) {
		if ((n == 1) && !camOufOfMap) {
			// don't render vertices under the map
			r1 = 2 * size;
		} else {
			r1 = n*n * size;
		}

		if (n == 3) {
			// last stripe: make it thinner (looks better with fog)
			r2 = (n+0.5)*(n+0.5) * size;
		} else {
			r2 = (n+1)*(n+1) * size;
		}
		for (alpha = 0.0f; (alpha - fastmath::PI2) < alphainc ; alpha += alphainc) {
			p.x = r1 * fastmath::sin(alpha) + 2 * xsize;
			p.z = r1 * fastmath::cos(alpha) + 2 * ysize;
			va->AddVertexC(p, planeColor );
			p.x = r2 * fastmath::sin(alpha) + 2 * xsize;
			p.z = r2 * fastmath::cos(alpha) + 2 * ysize;
			va->AddVertexC(p, (n==3) ? fogColor : planeColor);
		}
	}
	va->DrawArrayC(GL_TRIANGLE_STRIP);

	glDepthMask(GL_TRUE);
}


inline void CSMFGroundDrawer::DrawWaterPlane(bool drawWaterReflection) {
	if (drawWaterReflection)
		return;

	glPushMatrix();
	glTranslatef(0.f, std::min(-200.0f, smfMap->GetCurrMinHeight() - 400.0f), 0.f);
	glCallList(waterPlaneDispLists[camera->GetPos().IsInBounds() && !mapInfo->map.voidWater]);
	glPopMatrix();
}



ISMFRenderState* CSMFGroundDrawer::SelectRenderState(const DrawPass::e& drawPass)
{
    //stub method
}

bool CSMFGroundDrawer::HaveLuaRenderState() const
{
    //stub method
}



void CSMFGroundDrawer::DrawDeferredPass(const DrawPass::e& drawPass, bool alphaTest)
{
    //stub method
}

void CSMFGroundDrawer::DrawForwardPass(const DrawPass::e& drawPass, bool alphaTest)
{
    //stub method
}

void CSMFGroundDrawer::Draw(const DrawPass::e& drawPass)
{
    //stub method
}


void CSMFGroundDrawer::DrawBorder(const DrawPass::e drawPass)
{
    //stub method
}


void CSMFGroundDrawer::DrawShadowPass()
{
    //stub method
}



void CSMFGroundDrawer::SetLuaShader(const LuaMapShaderData* luaMapShaderData)
{
    //stub method
}

void CSMFGroundDrawer::SetupBigSquare(const int bigSquareX, const int bigSquareY)
{
    //stub method
}



void CSMFGroundDrawer::Update()
{
    //stub method
}

void CSMFGroundDrawer::UpdateRenderState()
{
    //stub method
}

void CSMFGroundDrawer::SunChanged() {
	// Lua has gl.GetSun
	if (HaveLuaRenderState())
		return;

	// always update, SSMF shader needs current sundir even when shadows are disabled
	// note: only the active state is notified of a given change
	smfRenderStates[RENDER_STATE_SEL]->UpdateCurrentShaderSky(sky->GetLight());
}


bool CSMFGroundDrawer::UpdateGeometryBuffer(bool init)
{
    //stub method
}



void CSMFGroundDrawer::IncreaseDetail()
{
    //stub method
}

void CSMFGroundDrawer::DecreaseDetail()
{
    //stub method
}

void CSMFGroundDrawer::SetDetail(int newGroundDetail)
{
    //stub method
}



int CSMFGroundDrawer::GetGroundDetail(const DrawPass::e& drawPass) const
{
    //stub method
}

