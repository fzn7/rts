/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <cctype>

#include "GroundDecalHandler.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Lua/LuaParser.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Projectiles/ExplosionListener.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Util.h"
#include "System/FileSystem/FileSystem.h"


using std::min;
using std::max;


CONFIG(int, GroundScarAlphaFade).defaultValue(0);

CGroundDecalHandler::CGroundDecalHandler()
	: CEventClient("[CGroundDecalHandler]", 314159, false)
{
    //stub method
}



CGroundDecalHandler::~CGroundDecalHandler()
{
    //stub method
}

void CGroundDecalHandler::LoadDecalShaders() {
	#define sh shaderHandler
	decalShaders.resize(DECAL_SHADER_LAST, NULL);

	// SM3 maps have no baked lighting, so decals blend differently
	const bool haveShadingTexture = (readMap->GetShadingTexture() != 0);
	const char* fragmentProgramNameARB = haveShadingTexture?
		"ARB/GroundDecalsSMF.fp":
		"ARB/GroundDecalsSM3.fp";
	const std::string extraDef = haveShadingTexture?
		"#define HAVE_SHADING_TEX 1\n":
		"#define HAVE_SHADING_TEX 0\n";

	decalShaders[DECAL_SHADER_ARB ] = sh->CreateProgramObject("[GroundDecalHandler]", "DecalShaderARB",  true);
	decalShaders[DECAL_SHADER_GLSL] = sh->CreateProgramObject("[GroundDecalHandler]", "DecalShaderGLSL", false);
	decalShaders[DECAL_SHADER_CURR] = decalShaders[DECAL_SHADER_ARB];

	if (globalRendering->haveARB && !globalRendering->haveGLSL) {
		decalShaders[DECAL_SHADER_ARB]->AttachShaderObject(sh->CreateShaderObject("ARB/GroundDecals.vp", "", GL_VERTEX_PROGRAM_ARB));
		decalShaders[DECAL_SHADER_ARB]->AttachShaderObject(sh->CreateShaderObject(fragmentProgramNameARB, "", GL_FRAGMENT_PROGRAM_ARB));
		decalShaders[DECAL_SHADER_ARB]->Link();
	} else {
		if (globalRendering->haveGLSL) {
			decalShaders[DECAL_SHADER_GLSL]->AttachShaderObject(sh->CreateShaderObject("GLSL/GroundDecalsVertProg.glsl", "",       GL_VERTEX_SHADER));
			decalShaders[DECAL_SHADER_GLSL]->AttachShaderObject(sh->CreateShaderObject("GLSL/GroundDecalsFragProg.glsl", extraDef, GL_FRAGMENT_SHADER));
			decalShaders[DECAL_SHADER_GLSL]->Link();

			decalShaders[DECAL_SHADER_GLSL]->SetUniformLocation("decalTex");           // idx 0
			decalShaders[DECAL_SHADER_GLSL]->SetUniformLocation("shadeTex");           // idx 1
			decalShaders[DECAL_SHADER_GLSL]->SetUniformLocation("shadowTex");          // idx 2
			decalShaders[DECAL_SHADER_GLSL]->SetUniformLocation("mapSizePO2");         // idx 3
			decalShaders[DECAL_SHADER_GLSL]->SetUniformLocation("groundAmbientColor"); // idx 4
			decalShaders[DECAL_SHADER_GLSL]->SetUniformLocation("shadowMatrix");       // idx 5
			decalShaders[DECAL_SHADER_GLSL]->SetUniformLocation("shadowParams");       // idx 6
			decalShaders[DECAL_SHADER_GLSL]->SetUniformLocation("shadowDensity");      // idx 7

			decalShaders[DECAL_SHADER_GLSL]->Enable();
			decalShaders[DECAL_SHADER_GLSL]->SetUniform1i(0, 0); // decalTex  (idx 0, texunit 0)
			decalShaders[DECAL_SHADER_GLSL]->SetUniform1i(1, 1); // shadeTex  (idx 1, texunit 1)
			decalShaders[DECAL_SHADER_GLSL]->SetUniform1i(2, 2); // shadowTex (idx 2, texunit 2)
			decalShaders[DECAL_SHADER_GLSL]->SetUniform2f(3, 1.0f / (mapDims.pwr2mapx * SQUARE_SIZE), 1.0f / (mapDims.pwr2mapy * SQUARE_SIZE));
			decalShaders[DECAL_SHADER_GLSL]->SetUniform1f(7, sky->GetLight()->GetGroundShadowDensity());
			decalShaders[DECAL_SHADER_GLSL]->Disable();
			decalShaders[DECAL_SHADER_GLSL]->Validate();

			decalShaders[DECAL_SHADER_CURR] = decalShaders[DECAL_SHADER_GLSL];
		}
	}

	#undef sh
}

void CGroundDecalHandler::SunChanged() {
	if (globalRendering->haveGLSL && decalShaders.size() > DECAL_SHADER_GLSL) {
		decalShaders[DECAL_SHADER_GLSL]->Enable();
		decalShaders[DECAL_SHADER_GLSL]->SetUniform1f(7, sky->GetLight()->GetGroundShadowDensity());
		decalShaders[DECAL_SHADER_GLSL]->Disable();
	}
}

static inline void AddQuadVertices(CVertexArray* va, int x, float* yv, int z, const float* uv, unsigned char* color)
{
    //stub method
}


inline void CGroundDecalHandler::DrawObjectDecal(SolidObjectGroundDecal* decal)
{
    //stub method
}


inline void CGroundDecalHandler::DrawGroundScar(CGroundDecalHandler::Scar* scar, bool fade)
{
    //stub method
}



void CGroundDecalHandler::GatherDecalsForType(CGroundDecalHandler::SolidObjectDecalType* decalType) {
	decalsToDraw.clear();

	auto& objectDecals = decalType->objectDecals;

	for (int i = 0; i < objectDecals.size();) {
		SolidObjectGroundDecal* decal = objectDecals[i];
		CSolidObject* decalOwner = decal->owner;

		if (decalOwner == NULL) {
			if (decal->gbOwner == NULL) {
				decal->alpha -= (decal->alphaFalloff * globalRendering->lastFrameTime * 0.001f * gs->speedFactor);
			}
			if (decal->alpha < 0.0f) {
				// make sure RemoveSolidObject() won't try to modify this decal
				if (decalOwner != NULL) {
					decalOwner->groundDecal = NULL;
				}

				objectDecals[i] = objectDecals.back();
				objectDecals.pop_back();

				delete decal;
				continue;
			}
			++i;
		} else {
			++i;
			if (decalOwner->GetBlockingMapID() < unitHandler->MaxUnits()) {
				const CUnit* decalOwnerUnit = static_cast<const CUnit*>(decalOwner);
				if (decalOwnerUnit->isIcon)
					continue;
				if (!gu->spectatingFullView &&
					(decalOwnerUnit->losStatus[gu->myAllyTeam] & LOS_INLOS) == 0 &&
					(!gameSetup->ghostedBuildings || (decalOwnerUnit->losStatus[gu->myAllyTeam] & LOS_PREVLOS) == 0))
					continue;

				decal->alpha = std::max(0.0f, decalOwnerUnit->buildProgress);
			} else {
				const CFeature* decalOwnerFeature = static_cast<const CFeature*>(decalOwner);
				if (!decalOwnerFeature->IsInLosForAllyTeam(gu->myAllyTeam))
					continue;
				if (decalOwnerFeature->drawAlpha < 0.01f)
					continue;
				decal->alpha = decalOwnerFeature->drawAlpha;
			}
		}
		if (!camera->InView(decal->pos, decal->radius))
			continue;
		decalsToDraw.push_back(decal);
	}
}

void CGroundDecalHandler::DrawObjectDecals() {
	// create and draw the quads for each building decal
	for (SolidObjectDecalType* decalType: objectDecalTypes) {
		if (decalType->objectDecals.empty())
			continue;

		{
			GatherDecalsForType(decalType);
		}

		if (!decalsToDraw.empty()) {
			glBindTexture(GL_TEXTURE_2D, decalType->texture);
			for (SolidObjectGroundDecal* decal: decalsToDraw) {
				DrawObjectDecal(decal);
			}
		}

		// glBindTexture(GL_TEXTURE_2D, 0);
	}
}


void CGroundDecalHandler::AddScars()
{
    //stub method
}

void CGroundDecalHandler::DrawScars() {
	// create and draw the 16x16 quads for each ground scar
	for (int i = 0; i < scars.size();) {
		Scar* scar = scars[i];

		if (scar->lifeTime < gs->frameNum) {
			RemoveScar(scar, false);
			scars[i] = scars.back();
			scars.pop_back();
			continue;
		}

		DrawGroundScar(scar, groundScarAlphaFade);
		++i;
	}
}




void CGroundDecalHandler::Draw()
{
    //stub method
}

void CGroundDecalHandler::BindTextures()
{
    //stub method
}

void CGroundDecalHandler::KillTextures()
{
    //stub method
}

void CGroundDecalHandler::BindShader(const float3& ambientColor)
{
    //stub method
}

void CGroundDecalHandler::DrawDecals()
{
    //stub method
}


void CGroundDecalHandler::AddDecal(CUnit* unit, const float3& newPos)
{
    //stub method
}


void CGroundDecalHandler::AddExplosion(float3 pos, float damage, float radius)
{
    //stub method
}


void CGroundDecalHandler::LoadScar(const std::string& file, unsigned char* buf,
                                   int xoffset, int yoffset)
{
    //stub method
}


int CGroundDecalHandler::OverlapSize(Scar* s1, Scar* s2)
{
    //stub method
}


void CGroundDecalHandler::TestOverlaps(Scar* scar)
{
    //stub method
}


void CGroundDecalHandler::RemoveScar(Scar* scar, bool removeFromScars)
{
    //stub method
}

int CGroundDecalHandler::GetSolidObjectDecalType(const std::string& name)
{
    //stub method
}


SolidObjectGroundDecal::~SolidObjectGroundDecal() {
	SafeDelete(va);
}

CGroundDecalHandler::Scar::~Scar() {
	SafeDelete(va);
}








void CGroundDecalHandler::MoveSolidObject(CSolidObject* object, const float3& pos)
{
    //stub method
}


void CGroundDecalHandler::RemoveSolidObject(CSolidObject* object, GhostSolidObject* gb)
{
    //stub method
}


/**
 * @brief immediately remove an object's ground decal, if any (without fade out)
 */
void CGroundDecalHandler::ForceRemoveSolidObject(CSolidObject* object)
{
    //stub method
}













void CGroundDecalHandler::UnitMoved(const CUnit* unit) { AddDecal(const_cast<CUnit*>(unit), unit->pos); }

void CGroundDecalHandler::GhostDestroyed(GhostSolidObject* gb) {
	if (gb->decal)
		gb->decal->gbOwner = NULL;
}






void CGroundDecalHandler::GhostCreated(CSolidObject* object, GhostSolidObject* gb) { RemoveSolidObject(object, gb); }
void CGroundDecalHandler::FeatureMoved(const CFeature* feature, const float3& oldpos) { MoveSolidObject(const_cast<CFeature*>(feature), feature->pos); }

void CGroundDecalHandler::ExplosionOccurred(const CExplosionParams& event) {
	if ((event.weaponDef != nullptr) && !event.weaponDef->visuals.explosionScar)
		return;

	AddExplosion(event.pos, event.damages.GetDefault(), event.craterAreaOfEffect);
}

void CGroundDecalHandler::RenderUnitCreated(const CUnit* unit, int cloaked) { MoveSolidObject(const_cast<CUnit*>(unit), unit->pos); }
void CGroundDecalHandler::RenderUnitDestroyed(const CUnit* unit) {
	RemoveSolidObject(const_cast<CUnit*>(unit), nullptr);
}

void CGroundDecalHandler::RenderFeatureCreated(const CFeature* feature) { MoveSolidObject(const_cast<CFeature*>(feature), feature->pos); }
void CGroundDecalHandler::RenderFeatureDestroyed(const CFeature* feature) { RemoveSolidObject(const_cast<CFeature*>(feature), nullptr); }

// FIXME: Add a RenderUnitLoaded event
void CGroundDecalHandler::UnitLoaded(const CUnit* unit, const CUnit* transport) { ForceRemoveSolidObject(const_cast<CUnit*>(unit)); }
void CGroundDecalHandler::UnitUnloaded(const CUnit* unit, const CUnit* transport) { MoveSolidObject(const_cast<CUnit*>(unit), unit->pos); }

