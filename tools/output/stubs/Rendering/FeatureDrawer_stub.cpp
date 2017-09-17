/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FeatureDrawer.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/FarTextureHandler.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/ITreeDrawer.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Rendering/Textures/3DOTextureHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/UnitDrawerState.hpp"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/myMath.h"
#include "System/Util.h"

#define DRAW_QUAD_SIZE 32

CONFIG(bool, ShowRezBars).defaultValue(true).headlessValue(false);

CONFIG(float, FeatureDrawDistance)
.defaultValue(6000.0f)
.minimumValue(0.0f)
.description("Maximum distance at which features will be drawn.");

CONFIG(float, FeatureFadeDistance)
.defaultValue(4500.0f)
.minimumValue(0.0f)
.description("Distance at which features will begin to fade from view.");



static bool SetFeatureDrawAlpha(
	CFeature* f,
	const CCamera* cam,
	float sqFadeDistMin = -1.0f,
	float sqFadeDistMax = -1.0f
) {
	// always reset
	f->drawAlpha = 0.0f;

	if (cam == nullptr)
		return false;

	// special case for non-fading features
	if (!f->alphaFade) {
		f->drawAlpha = 1.0f;
		return true;
	}

	const float sqDist = (f->pos - cam->GetPos()).SqLength();
	const float farLength = f->sqRadius * unitDrawer->unitDrawDistSqr;

	// if true, feature will become a fartex
	if (sqDist >= farLength)
		return false;

	float sqFadeDistB = sqFadeDistMin;
	float sqFadeDistE = sqFadeDistMax;

	if (farLength < sqFadeDistMax) {
		sqFadeDistE = farLength;
		sqFadeDistB = farLength * (sqFadeDistMin / sqFadeDistMax);
	}

	if (sqDist < sqFadeDistB) {
		// draw feature as normal, no fading
		f->drawAlpha = 1.0f;
		return true;
	}

	if (sqDist < sqFadeDistE) {
		// otherwise save it for the fade-pass
		f->drawAlpha = 1.0f - ((sqDist - sqFadeDistB) / (sqFadeDistE - sqFadeDistB));
		return true;
	}

	return false;
}



static const void SetFeatureAlphaMatSSP(const CFeature* f) { glAlphaFunc(GL_GREATER, f->drawAlpha * 0.5f); }
static const void SetFeatureAlphaMatFFP(const CFeature* f)
{
    //stub method
}


typedef const void (*SetFeatureAlphaMatFunc)(const CFeature*);

static const SetFeatureAlphaMatFunc setFeatureAlphaMatFuncs[] = {
	SetFeatureAlphaMatSSP,
	SetFeatureAlphaMatFFP,
};



CFeatureDrawer* featureDrawer = nullptr;


/******************************************************************************/



CFeatureDrawer::CFeatureDrawer(): CEventClient("[CFeatureDrawer]", 313373, false)
{
    //stub method
}


CFeatureDrawer::~CFeatureDrawer()
{
    //stub method
}



void CFeatureDrawer::RenderFeatureCreated(const CFeature* feature)
{
    //stub method
}



void CFeatureDrawer::RenderFeatureDestroyed(const CFeature* feature)
{
    //stub method
}


void CFeatureDrawer::FeatureMoved(const CFeature* feature, const float3& oldpos)
{
    //stub method
}

void CFeatureDrawer::UpdateDrawQuad(CFeature* feature)
{
    //stub method
}


void CFeatureDrawer::Update()
{
    //stub method
}


inline void CFeatureDrawer::UpdateDrawPos(CFeature* f)
{
    //stub method
}


void CFeatureDrawer::Draw()
{
    //stub method
}

void CFeatureDrawer::DrawOpaquePass(bool deferredPass, bool, bool)
{
    //stub method
}

void CFeatureDrawer::DrawOpaqueFeatures(int modelType)
{
    //stub method
}

bool CFeatureDrawer::CanDrawFeature(const CFeature* feature) const
{
    //stub method
}



inline void CFeatureDrawer::DrawFeatureModel(const CFeature* feature, bool noLuaCall) {
	if (!noLuaCall && feature->luaDraw && eventHandler.DrawFeature(feature))
		return;

	feature->localModel.Draw();
}

void CFeatureDrawer::DrawFeatureNoTrans(
	const CFeature* feature,
	unsigned int preList,
	unsigned int postList,
	bool /*lodCall*/,
	bool noLuaCall
) {
	if (preList != 0) {
		glCallList(preList);
	}

	DrawFeatureModel(feature, noLuaCall);

	if (postList != 0) {
		glCallList(postList);
	}
}

void CFeatureDrawer::DrawFeature(const CFeature* feature, unsigned int preList, unsigned int postList, bool lodCall, bool noLuaCall)
{
    //stub method
}




void CFeatureDrawer::PushIndividualState(const CFeature* feature, bool deferredPass)
{
    //stub method
}

void CFeatureDrawer::PopIndividualState(const CFeature* feature, bool deferredPass)
{
    //stub method
}


void CFeatureDrawer::DrawIndividual(const CFeature* feature, bool noLuaCall)
{
    //stub method
}

void CFeatureDrawer::DrawIndividualNoTrans(const CFeature* feature, bool noLuaCall)
{
    //stub method
}



void CFeatureDrawer::DrawAlphaPass()
{
    //stub method
}

void CFeatureDrawer::DrawAlphaFeatures(int modelType)
{
    //stub method
}




void CFeatureDrawer::DrawShadowPass()
{
    //stub method
}



class CFeatureQuadDrawer : public CReadMap::IQuadDrawer {
public:
	CFeatureQuadDrawer(int _numQuadsX): numQuadsX(_numQuadsX) {}

	void ResetState() { numQuadsX = 0; }

	void DrawQuad(int x, int y) {
		camQuads.push_back(y * numQuadsX + x);

		// used so we do not iterate over non-visited renderers (in any pass)
		rdrProxies[y * numQuadsX + x].SetLastDrawFrame(globalRendering->drawFrame);
	}

	std::vector<int>& GetCamQuads() { return camQuads; }
	std::vector<CFeatureDrawer::RdrContProxy>& GetRdrProxies() { return rdrProxies; }

private:
	std::vector<int> camQuads;
	std::vector<CFeatureDrawer::RdrContProxy> rdrProxies;

	int numQuadsX;
};



void CFeatureDrawer::FlagVisibleFeatures(
	const CCamera* cam,
	bool drawShadowPass,
	bool drawReflection,
	bool drawRefraction,
	bool drawFarFeatures
) {
	const auto& quads = camVisibleQuads[cam->GetCamType()];

	const float sqFadeDistBegin = featureFadeDistance * featureFadeDistance;
	const float sqFadeDistEnd = featureDrawDistance * featureDrawDistance;

	const CCamera* playerCam = CCamera::GetCamera(CCamera::CAMTYPE_PLAYER);

	for (unsigned int n = 0; n < quads.size(); n++) {
		auto& mdlRenderProxy = featureDrawer->modelRenderers[ quads[n] ];

		for (int i = 0; i < MODELTYPE_OTHER; ++i) {
			auto mdlRenderer = mdlRenderProxy.GetRenderer(i);
			auto& featureBin = mdlRenderer->GetFeatureBinMutable();

			for (auto& binElem: featureBin) {
				for (CFeature* f: binElem.second) {
					assert(quads[n] == f->drawQuad);

					// clear marker; will be set at most once below
					f->drawFlag = CFeature::FD_NODRAW_FLAG;

					if (f->noDraw)
						continue;
					if (f->IsInVoid())
						continue;

					assert(f->def->drawType == DRAWTYPE_MODEL);

					if (!gu->spectatingFullView && !f->IsInLosForAllyTeam(gu->myAllyTeam))
						continue;


					if (drawShadowPass) {
						if (SetFeatureDrawAlpha(f, playerCam, sqFadeDistBegin, sqFadeDistEnd)) {
							// no shadows for fully alpha-faded features from player's POV
							f->UpdateTransform(f->drawPos, false);
							f->drawFlag = CFeature::FD_SHADOW_FLAG;
						}
						continue;
					}

					if (drawRefraction && !f->IsInWater())
						continue;

					if (drawReflection && !CUnitDrawer::ObjectVisibleReflection(f->drawMidPos, cam->GetPos(), f->GetDrawRadius()))
						continue;


					if (SetFeatureDrawAlpha(f, cam, sqFadeDistBegin, sqFadeDistEnd)) {
						f->UpdateTransform(f->drawPos, false);
						f->drawFlag += (CFeature::FD_OPAQUE_FLAG * (f->drawAlpha == 1.0f));
						f->drawFlag += (CFeature::FD_ALPHAF_FLAG * (f->drawAlpha <  1.0f));
						continue;
					}

					// note: it looks pretty bad to first alpha-fade and then
					// draw a fully *opaque* fartex, so restrict impostors to
					// non-fading features
					f->drawFlag = CFeature::FD_FARTEX_FLAG * drawFarFeatures * (!f->alphaFade);
				}
			}
		}
	}
}

void CFeatureDrawer::GetVisibleFeatures(CCamera* cam, int extraSize, bool drawFar)
{
    //stub method
}
