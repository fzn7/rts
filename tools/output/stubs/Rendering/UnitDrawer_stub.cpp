/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UnitDrawer.h"
#include "UnitDrawerState.hpp"

#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Game/GameHelper.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/UI/MiniMap.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"

#include "Rendering/Env/ISky.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/FarTextureHandler.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/IconHandler.h"
#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/3DOTextureHandler.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Rendering/Models/ModelRenderContainer.h"

#include "Sim/Features/Feature.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/Unit.h"

#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Util.h"

#define UNIT_SHADOW_ALPHA_MASKING

CUnitDrawer* unitDrawer;

CONFIG(int, UnitLodDist).defaultValue(1000).headlessValue(0);
CONFIG(int, UnitIconDist).defaultValue(200).headlessValue(0);
CONFIG(float, UnitTransparency).defaultValue(0.7f);

CONFIG(int, MaxDynamicModelLights)
	.defaultValue(1)
	.minimumValue(0);

CONFIG(bool, AdvUnitShading).defaultValue(true).headlessValue(false).safemodeValue(false).description("Determines whether specular highlights and other lighting effects are rendered for units.");




static const void BindOpaqueTex(const CS3OTextureHandler::S3OTexMat* textureMat) {
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textureMat->tex2);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureMat->tex1);
}

static const void BindOpaqueTexAtlas(const CS3OTextureHandler::S3OTexMat*) { texturehandler3DO->Set3doAtlases(); }
static const void BindOpaqueTexDummy(const CS3OTextureHandler::S3OTexMat*) {}

static const void BindShadowTexDummy(const CS3OTextureHandler::S3OTexMat*) {}
static const void KillShadowTexDummy(const CS3OTextureHandler::S3OTexMat*) {}

static const void BindShadowTex(const CS3OTextureHandler::S3OTexMat* textureMat) {
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureMat->tex2);
}

static const void KillShadowTex(const CS3OTextureHandler::S3OTexMat*) {
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE0);
}


static const void PushRenderState3DO() {
	BindOpaqueTexAtlas(nullptr);

	glPushAttrib(GL_POLYGON_BIT);
	glDisable(GL_CULL_FACE);
}

static const void PushRenderStateS3O() {
	if (globalRendering->supportRestartPrimitive) {
		glPrimitiveRestartIndexNV(-1U);
	}
}

static const void PushRenderStateOBJ() { /* no-op */ }
static const void PushRenderStateASS() { /* no-op */ }

static const void PopRenderState3DO() { glPopAttrib(); }
static const void PopRenderStateS3O() {    /* no-op */ }
static const void PopRenderStateOBJ() {    /* no-op */ }
static const void PopRenderStateASS() {    /* no-op */ }


static const void SetTeamColorDummy(const IUnitDrawerState* state, int team, const float2 alpha) {}
static const void SetTeamColorValid(const IUnitDrawerState* state, int team, const float2 alpha) { state->SetTeamColor(team, alpha); }



// typedef std::function<void(int)>                                  BindTexFunc;
// typedef std::function<void(const CS3OTextureHandler::S3OTexMat*)> BindTexFunc;
// typedef std::function<void()>                                     KillTexFunc;
typedef const void (*BindTexFunc)(const CS3OTextureHandler::S3OTexMat*);
typedef const void (*BindTexFunc)(const CS3OTextureHandler::S3OTexMat*);
typedef const void (*KillTexFunc)(const CS3OTextureHandler::S3OTexMat*);

typedef const void (*PushRenderStateFunc)();
typedef const void (*PopRenderStateFunc)();

typedef const void (*SetTeamColorFunc)(const IUnitDrawerState*, int team, const float2 alpha);

static const BindTexFunc opaqueTexBindFuncs[MODELTYPE_OTHER] = {
	BindOpaqueTexDummy, // 3DO (no-op, done by PushRenderState3DO)
	BindOpaqueTex,      // S3O
	BindOpaqueTex,      // OBJ
	BindOpaqueTex,      // ASS
};

static const BindTexFunc shadowTexBindFuncs[MODELTYPE_OTHER] = {
	BindShadowTexDummy, // 3DO (no-op)
	BindShadowTex,      // S3O
	BindShadowTex,      // OBJ
	BindShadowTex,      // ASS
};

static const BindTexFunc* bindModelTexFuncs[] = {
	&opaqueTexBindFuncs[0], // opaque+alpha
	&shadowTexBindFuncs[0], // shadow
};

static const KillTexFunc shadowTexKillFuncs[MODELTYPE_OTHER] = {
	KillShadowTexDummy, // 3DO (no-op)
	KillShadowTex,      // S3O
	KillShadowTex,      // OBJ
	KillShadowTex,      // ASS
};


static const PushRenderStateFunc renderStatePushFuncs[MODELTYPE_OTHER] = {
	PushRenderState3DO,
	PushRenderStateS3O,
	PushRenderStateOBJ,
	PushRenderStateASS,
};

static const PopRenderStateFunc renderStatePopFuncs[MODELTYPE_OTHER] = {
	PopRenderState3DO,
	PopRenderStateS3O,
	PopRenderStateOBJ,
	PopRenderStateASS,
};


static const SetTeamColorFunc setTeamColorFuncs[] = {
	SetTeamColorDummy,
	SetTeamColorValid,
};



// low-level (batch and solo)
// note: also called during SP
void CUnitDrawer::BindModelTypeTexture(int mdlType, int texType) {
	const auto texFun = bindModelTexFuncs[shadowHandler->InShadowPass()][mdlType];
	const auto texMat = texturehandlerS3O->GetTexture(texType);

	texFun(texMat);
}

void CUnitDrawer::PushModelRenderState(int mdlType) { renderStatePushFuncs[mdlType](); }
void CUnitDrawer::PopModelRenderState (int mdlType) { renderStatePopFuncs [mdlType](); }

// mid-level (solo only)
void CUnitDrawer::PushModelRenderState(const S3DModel* m) {
	PushModelRenderState(m->type);
	BindModelTypeTexture(m->type, m->textureType);
}
void CUnitDrawer::PopModelRenderState(const S3DModel* m) {
	PopModelRenderState(m->type);
}

// high-level (solo only)
void CUnitDrawer::PushModelRenderState(const CSolidObject* o) { PushModelRenderState(o->model); }
void CUnitDrawer::PopModelRenderState(const CSolidObject* o) { PopModelRenderState(o->model); }




CUnitDrawer::CUnitDrawer(): CEventClient("[CUnitDrawer]", 271828, false)
{
    //stub method
}

CUnitDrawer::~CUnitDrawer()
{
    //stub method
}



void CUnitDrawer::SetUnitDrawDist(float dist)
{
    //stub method
}

void CUnitDrawer::SetUnitIconDist(float dist)
{
    //stub method
}



void CUnitDrawer::Update()
{
    //stub method
}




void CUnitDrawer::Draw(bool drawReflection, bool drawRefraction)
{
    //stub method
}

void CUnitDrawer::DrawOpaquePass(bool deferredPass, bool drawReflection, bool drawRefraction)
{
    //stub method
}



void CUnitDrawer::DrawOpaqueUnits(int modelType, bool drawReflection, bool drawRefraction)
{
    //stub method
}

inline void CUnitDrawer::DrawOpaqueUnit(CUnit* unit, bool drawReflection, bool drawRefraction)
{
    //stub method
}


void CUnitDrawer::DrawOpaqueAIUnits(int modelType)
{
    //stub method
}

void CUnitDrawer::DrawOpaqueAIUnit(const TempDrawUnit& unit)
{
    //stub method
}



void CUnitDrawer::DrawUnitIcons()
{
    //stub method
}



/******************************************************************************/
/******************************************************************************/

bool CUnitDrawer::CanDrawOpaqueUnit(
	const CUnit* unit,
	bool drawReflection,
	bool drawRefraction
) const {
	if (unit == (drawReflection? nullptr: (gu->GetMyPlayer())->fpsController.GetControllee()))
		return false;
	if (unit->noDraw)
		return false;
	if (unit->IsInVoid())
		return false;
	if (unit->isIcon)
		return false;

	if (!(unit->losStatus[gu->myAllyTeam] & LOS_INLOS) && !gu->spectatingFullView)
		return false;

	// either PLAYER or UWREFL
	const CCamera* cam = CCamera::GetActiveCamera();

	if (drawRefraction && !unit->IsInWater())
		return false;

	if (drawReflection && !ObjectVisibleReflection(unit->drawMidPos, cam->GetPos(), unit->GetDrawRadius()))
		return false;

	return (cam->InView(unit->drawMidPos, unit->GetDrawRadius()));
}

bool CUnitDrawer::CanDrawOpaqueUnitShadow(const CUnit* unit) const
{
    //stub method
}




void CUnitDrawer::DrawOpaqueUnitShadow(CUnit* unit) {
	if (!CanDrawOpaqueUnitShadow(unit))
		return;

	if (LuaObjectDrawer::AddShadowMaterialObject(unit, LUAOBJ_UNIT))
		return;

	DrawUnit(unit, 0, 0, false, false);
}


void CUnitDrawer::DrawOpaqueUnitsShadow(int modelType) {
	const auto& unitBin = opaqueModelRenderers[modelType]->GetUnitBin();

	for (const auto& unitBinP: unitBin) {
		const auto& unitSet = unitBinP.second;
		const int textureType = unitBinP.first;

		BindModelTypeTexture(modelType, textureType);
		// shadowTexBindFuncs[modelType](texturehandlerS3O->GetTexture(textureType));

		for (const auto& unitSetP: unitSet) {
			DrawOpaqueUnitShadow(unitSetP);
		}

		shadowTexKillFuncs[modelType](nullptr);
	}
}

void CUnitDrawer::DrawShadowPass()
{
    //stub method
}



void CUnitDrawer::DrawIcon(CUnit* unit, bool useDefaultIcon)
{
    //stub method
}






void CUnitDrawer::SetupAlphaDrawing(bool deferredPass)
{
    //stub method
}

void CUnitDrawer::ResetAlphaDrawing(bool deferredPass)
{
    //stub method
}



void CUnitDrawer::DrawAlphaPass()
{
    //stub method
}

void CUnitDrawer::DrawAlphaUnits(int modelType)
{
    //stub method
}

inline void CUnitDrawer::DrawAlphaUnit(CUnit* unit, int modelType, bool drawGhostBuildingsPass) {
	if (!camera->InView(unit->drawMidPos, unit->GetDrawRadius()))
		return;

	if (LuaObjectDrawer::AddAlphaMaterialObject(unit, LUAOBJ_UNIT))
		return;

	const unsigned short losStatus = unit->losStatus[gu->myAllyTeam];

	if (drawGhostBuildingsPass) {
		// check for decoy models
		const UnitDef* decoyDef = unit->unitDef->decoyDef;
		const S3DModel* model = nullptr;

		if (decoyDef == nullptr) {
			model = unit->model;
		} else {
			model = decoyDef->LoadModel();
		}

		// FIXME: needs a second pass
		if (model->type != modelType)
			return;

		// ghosted enemy units
		if (losStatus & LOS_CONTRADAR) {
			glColor4f(0.9f, 0.9f, 0.9f, alphaValues.z);
		} else {
			glColor4f(0.6f, 0.6f, 0.6f, alphaValues.y);
		}

		glPushMatrix();
		glTranslatef3(unit->drawPos);
		glRotatef(unit->buildFacing * 90.0f, 0, 1, 0);

		// the units in liveGhostedBuildings[modelType] are not
		// sorted by textureType, but we cannot merge them with
		// alphaModelRenderers[modelType] either since they are
		// not actually cloaked
		BindModelTypeTexture(modelType, model->textureType);

		SetTeamColour(unit->team, float2((losStatus & LOS_CONTRADAR)? alphaValues.z: alphaValues.y, 1.0f));
		model->DrawStatic();
		glPopMatrix();

		glColor4f(1.0f, 1.0f, 1.0f, alphaValues.x);
		return;
	}

	if (unit->isIcon)
		return;

	if ((losStatus & LOS_INLOS) || gu->spectatingFullView) {
		SetTeamColour(unit->team, float2(alphaValues.x, 1.0f));
		DrawUnit(unit, 0, 0, false, false);
	}
}



void CUnitDrawer::DrawAlphaAIUnits(int modelType)
{
    //stub method
}

void CUnitDrawer::DrawAlphaAIUnit(const TempDrawUnit& unit)
{
    //stub method
}

void CUnitDrawer::DrawAlphaAIUnitBorder(const TempDrawUnit& unit)
{
    //stub method
}

void CUnitDrawer::UpdateGhostedBuildings()
{
    //stub method
}

void CUnitDrawer::DrawGhostedBuildings(int modelType)
{
    //stub method
}






void CUnitDrawer::SetupOpaqueDrawing(bool deferredPass)
{
    //stub method
}

void CUnitDrawer::ResetOpaqueDrawing(bool deferredPass)
{
    //stub method
}

const IUnitDrawerState* CUnitDrawer::GetWantedDrawerState(bool alphaPass) const
{
    //stub method
}



void CUnitDrawer::SetTeamColour(int team, const float2 alpha) const
{
    //stub method
}

/**
 * Set up the texture environment in texture unit 0
 * to give an S3O texture its team-colour.
 *
 * Also:
 * - call SetBasicTeamColour to set the team colour to transform to.
 * - Replace the output alpha channel. If not, only the team-coloured bits will show, if that. Or something.
 */
void CUnitDrawer::SetupBasicS3OTexture0()
{
    //stub method
}

/**
 * This sets the first texture unit to GL_MODULATE the colours from the
 * first texture unit with the current glColor.
 *
 * Normal S3O drawing sets the color to full white; translucencies
 * use this setup to 'tint' the drawn model.
 *
 * - Leaves glActivateTextureARB at the first unit.
 * - This doesn't tinker with the output alpha, either.
 */
void CUnitDrawer::SetupBasicS3OTexture1()
{
    //stub method
}


void CUnitDrawer::CleanupBasicS3OTexture1()
{
    //stub method
}

void CUnitDrawer::CleanupBasicS3OTexture0()
{
    //stub method
}




void CUnitDrawer::PushIndividualOpaqueState(const S3DModel* model, int teamID, bool deferredPass)
{
    //stub method
}

void CUnitDrawer::PushIndividualAlphaState(const S3DModel* model, int teamID, bool deferredPass)
{
    //stub method
}


void CUnitDrawer::PopIndividualOpaqueState(const S3DModel* model, int teamID, bool deferredPass)
{
    //stub method
}

void CUnitDrawer::PopIndividualAlphaState(const S3DModel* model, int teamID, bool deferredPass)
{
    //stub method
}


void CUnitDrawer::PushIndividualOpaqueState(const CUnit* unit, bool deferredPass)
{
    //stub method
}

void CUnitDrawer::PopIndividualOpaqueState(const CUnit* unit, bool deferredPass)
{
    //stub method
}


void CUnitDrawer::DrawIndividual(const CUnit* unit, bool noLuaCall)
{
    //stub method
}

void CUnitDrawer::DrawIndividualNoTrans(const CUnit* unit, bool noLuaCall)
{
    //stub method
}




static void DIDResetPrevProjection(bool toScreen)
{
    //stub method
}

static void DIDResetPrevModelView()
{
    //stub method
}

static bool DIDCheckMatrixMode(int wantedMode)
{
    //stub method
}


// used by LuaOpenGL::Draw{Unit,Feature}Shape
// acts like DrawIndividual but can not apply
// custom materials
void CUnitDrawer::DrawIndividualDefOpaque(const SolidObjectDef* objectDef, int teamID, bool rawState, bool toScreen)
{
    //stub method
}

// used for drawing building orders (with translucency)
void CUnitDrawer::DrawIndividualDefAlpha(const SolidObjectDef* objectDef, int teamID, bool rawState, bool toScreen)
{
    //stub method
}






typedef const void (*DrawModelBuildStageFunc)(const CUnit*, const double*, const double*, bool);

static const void DrawModelNoopBuildStage(const CUnit*, const double*, const double*, bool)
{
    //stub method
}

static const void DrawModelWireBuildStage(
	const CUnit* unit,
	const double* upperPlane,
	const double* lowerPlane,
	bool noLuaCall
) {
	if (globalRendering->atiHacks) {
		// some ATi mobility cards/drivers dont like clipping wireframes
		glDisable(GL_CLIP_PLANE0);
		glDisable(GL_CLIP_PLANE1);
	} else {
		glClipPlane(GL_CLIP_PLANE0, upperPlane);
		glClipPlane(GL_CLIP_PLANE1, lowerPlane);
	}

	// FFP-only drawing still needs raw colors
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		CUnitDrawer::DrawUnitModel(unit, noLuaCall);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (globalRendering->atiHacks) {
		glEnable(GL_CLIP_PLANE0);
		glEnable(GL_CLIP_PLANE1);
	}
}

static const void DrawModelFlatBuildStage(
	const CUnit* unit,
	const double* upperPlane,
	const double* lowerPlane,
	bool noLuaCall
) {
	glClipPlane(GL_CLIP_PLANE0, upperPlane);
	glClipPlane(GL_CLIP_PLANE1, lowerPlane);

	CUnitDrawer::DrawUnitModel(unit, noLuaCall);
}

static const void DrawModelFillBuildStage(
	const CUnit* unit,
	const double* upperPlane,
	const double* lowerPlane,
	bool noLuaCall
) {
	if (globalRendering->atiHacks) {
		glDisable(GL_CLIP_PLANE0);
	} else {
		glClipPlane(GL_CLIP_PLANE0, upperPlane);
	}

	glPolygonOffset(1.0f, 1.0f);
	glEnable(GL_POLYGON_OFFSET_FILL);
		CUnitDrawer::DrawUnitModel(unit, noLuaCall);
	glDisable(GL_POLYGON_OFFSET_FILL);
}

static const DrawModelBuildStageFunc drawModelBuildStageFuncs[] = {
	DrawModelNoopBuildStage,
	DrawModelWireBuildStage,
	DrawModelFlatBuildStage,
	DrawModelFillBuildStage,
};




void CUnitDrawer::DrawUnitModelBeingBuiltShadow(const CUnit* unit, bool noLuaCall)
{
    //stub method
}

void CUnitDrawer::DrawUnitModelBeingBuiltOpaque(const CUnit* unit, bool noLuaCall)
{
    //stub method
}




void CUnitDrawer::DrawUnitModel(const CUnit* unit, bool noLuaCall) {
	if (!noLuaCall && unit->luaDraw && eventHandler.DrawUnit(unit))
		return;

	unit->localModel.Draw();
}


void CUnitDrawer::DrawUnitNoTrans(
	const CUnit* unit,
	unsigned int preList,
	unsigned int postList,
	bool lodCall,
	bool noLuaCall
) {
	const unsigned int b0 = lodCall || !unit->beingBuilt || !unit->unitDef->showNanoFrame;
	const unsigned int b1 = shadowHandler->InShadowPass();

	if (preList != 0) {
		glCallList(preList);
	}

	// if called from LuaObjectDrawer, unit has a custom material
	//
	// we want Lua-material shaders to have full control over build
	// visualisation, so keep it simple and make LOD-calls draw the
	// full model
	//
	// NOTE: "raw" calls will no longer skip DrawUnitBeingBuilt
	//
	drawModelFuncs[ std::max(b0 * 2, b1) ](unit, noLuaCall);

	if (postList != 0) {
		glCallList(postList);
	}
}

void CUnitDrawer::DrawUnit(const CUnit* unit, unsigned int preList, unsigned int postList, bool lodCall, bool noLuaCall)
{
    //stub method
}




inline void CUnitDrawer::UpdateUnitIconState(CUnit* unit) {
	const unsigned short losStatus = unit->losStatus[gu->myAllyTeam];

	// reset
	unit->isIcon = losStatus & LOS_INRADAR;

	if ((losStatus & LOS_INLOS) || gu->spectatingFullView)
		unit->isIcon = DrawAsIcon(unit, (unit->pos - camera->GetPos()).SqLength());

	if (!unit->isIcon)
		return;
	if (unit->noDraw)
		return;
	if (unit->IsInVoid())
		return;

	iconUnits.push_back(unit);
}

inline void CUnitDrawer::UpdateUnitDrawPos(CUnit* u) {
	const CUnit* t = u->GetTransporter();

	if (t != nullptr) {
		u->drawPos = u->GetDrawPos(t->speed, globalRendering->timeOffset);
	} else {
		u->drawPos = u->GetDrawPos(          globalRendering->timeOffset);
	}

	u->drawMidPos = u->GetMdlDrawMidPos();
}



bool CUnitDrawer::DrawAsIcon(const CUnit* unit, const float sqUnitCamDist) const {

	const float sqIconDistMult = unit->unitDef->iconType->GetDistanceSqr();
	const float realIconLength = iconLength * sqIconDistMult;

	bool asIcon = false;

	if (useDistToGroundForIcons) {
		asIcon = (sqCamDistToGroundForIcons > realIconLength);
	} else {
		asIcon = (sqUnitCamDist > realIconLength);
	}

	return asIcon;
}




// visualize if a unit can be built at specified position
bool CUnitDrawer::ShowUnitBuildSquare(const BuildInfo& buildInfo)
{
    //stub method
}

bool CUnitDrawer::ShowUnitBuildSquare(const BuildInfo& buildInfo, const std::vector<Command>& commands)
{
    //stub method
}



inline const icon::CIconData* GetUnitIcon(const CUnit* unit) {
	const unsigned short losStatus = unit->losStatus[gu->myAllyTeam];
	const unsigned short prevMask = (LOS_PREVLOS | LOS_CONTRADAR);

	const UnitDef* unitDef = unit->unitDef;
	const icon::CIconData* iconData = nullptr;

	// use the unit's custom icon if we can currently see it,
	// or have seen it before and did not lose contact since
	const bool unitVisible = ((losStatus & (LOS_INLOS | LOS_INRADAR)) && ((losStatus & prevMask) == prevMask));
	const bool customIcon = (minimap->UseUnitIcons() && (unitVisible || gu->spectatingFullView));

	if (customIcon) {
		iconData = unitDef->iconType.GetIconData();
	} else {
		if (losStatus & LOS_INRADAR) {
			iconData = icon::iconHandler->GetDefaultIconData();
		}
	}

	return iconData;
}

inline float GetUnitIconScale(const CUnit* unit) {
	float scale = unit->myIcon->GetSize();

	if (!minimap->UseUnitIcons())
		return scale;
	if (!unit->myIcon->GetRadiusAdjust())
		return scale;

	const unsigned short losStatus = unit->losStatus[gu->myAllyTeam];
	const unsigned short prevMask = (LOS_PREVLOS | LOS_CONTRADAR);
	const bool unitVisible = ((losStatus & LOS_INLOS) || ((losStatus & LOS_INRADAR) && ((losStatus & prevMask) == prevMask)));

	if ((unitVisible || gu->spectatingFullView)) {
		scale *= (unit->radius / unit->myIcon->GetRadiusScale());
	}

	return scale;
}


void CUnitDrawer::DrawUnitMiniMapIcon(const CUnit* unit, CVertexArray* va) const {
	if (unit->noMinimap)
		return;
	if (unit->myIcon == nullptr)
		return;
	if (unit->IsInVoid())
		return;

	const unsigned char defaultColor[4] = {255, 255, 255, 255};
	const unsigned char* color = &defaultColor[0];

	if (!unit->isSelected) {
		if (minimap->UseSimpleColors()) {
			if (unit->team == gu->myTeam) {
				color = minimap->GetMyTeamIconColor();
			} else if (teamHandler->Ally(gu->myAllyTeam, unit->allyteam)) {
				color = minimap->GetAllyTeamIconColor();
			} else {
				color = minimap->GetEnemyTeamIconColor();
			}
		} else {
			color = teamHandler->Team(unit->team)->color;
		}
	}

	const float iconScale = GetUnitIconScale(unit);
	const float3& iconPos = (!gu->spectatingFullView) ?
		unit->GetObjDrawErrorPos(gu->myAllyTeam):
		unit->GetObjDrawMidPos();

	const float iconSizeX = (iconScale * minimap->GetUnitSizeX());
	const float iconSizeY = (iconScale * minimap->GetUnitSizeY());

	const float x0 = iconPos.x - iconSizeX;
	const float x1 = iconPos.x + iconSizeX;
	const float y0 = iconPos.z - iconSizeY;
	const float y1 = iconPos.z + iconSizeY;

	unit->myIcon->DrawArray(va, x0, y0, x1, y1, color);
}

// TODO:
//   UnitDrawer::DrawIcon was half-duplicate of MiniMap::DrawUnit&co
//   the latter has been replaced by this, do the same for the former
//   (mini-map icons and real-map radar icons are the same anyway)
void CUnitDrawer::DrawUnitMiniMapIcons() const {
	CVertexArray* va = GetVertexArray();

	for (auto iconIt = unitsByIcon.cbegin(); iconIt != unitsByIcon.cend(); ++iconIt) {
		const icon::CIconData* icon = iconIt->first;
		const std::vector<const CUnit*>& units = iconIt->second;

		if (icon == nullptr)
			continue;
		if (units.empty())
			continue;

		va->Initialize();
		va->EnlargeArrays(units.size() * 4, 0, VA_SIZE_2DTC);
		icon->BindTexture();

		for (const CUnit* unit: units) {
			assert(unit->myIcon == icon);
			DrawUnitMiniMapIcon(unit, va);
		}

		va->DrawArray2dTC(GL_QUADS);
	}
}

void CUnitDrawer::UpdateUnitMiniMapIcon(const CUnit* unit, bool forced, bool killed) {
	CUnit* u = const_cast<CUnit*>(unit);

	icon::CIconData* oldIcon = unit->myIcon;
	icon::CIconData* newIcon = const_cast<icon::CIconData*>(GetUnitIcon(unit));

	u->myIcon = nullptr;

	if (!killed) {
		if ((oldIcon != newIcon) || forced) {
			VectorErase(unitsByIcon[oldIcon], unit);
			unitsByIcon[newIcon].push_back(unit);
		}

		u->myIcon = newIcon;
		return;
	}

	VectorErase(unitsByIcon[oldIcon], unit);
}



void CUnitDrawer::RenderUnitCreated(const CUnit* u, int cloaked) {
	CUnit* unit = const_cast<CUnit*>(u);

	if (u->model != nullptr) {
		if (cloaked) {
			alphaModelRenderers[MDL_TYPE(u)]->AddUnit(u);
		} else {
			opaqueModelRenderers[MDL_TYPE(u)]->AddUnit(u);
		}
	}

	UpdateUnitMiniMapIcon(u, false, false);
	unsortedUnits.push_back(unit);
}

void CUnitDrawer::RenderUnitDestroyed(const CUnit* unit) {
	CUnit* u = const_cast<CUnit*>(unit);

	const UnitDef* unitDef = unit->unitDef;
	const UnitDef* decoyDef = unitDef->decoyDef;

	// TODO - make ghosted buildings per allyTeam - so they are correctly dealt with
	// when spectating
	for (int allyTeam = 0; allyTeam < deadGhostBuildings.size(); ++allyTeam) {
		if (unitDef->IsBuildingUnit() && gameSetup->ghostedBuildings &&
			!(u->losStatus[allyTeam] & (LOS_INLOS | LOS_CONTRADAR)) &&
			(u->losStatus[allyTeam] & (LOS_PREVLOS))
		) {
			// FIXME -- adjust decals for decoys? gets weird?
			S3DModel* gbModel = (decoyDef == nullptr)? u->model: decoyDef->LoadModel();

			GhostSolidObject* gb = new GhostSolidObject();
			gb->pos    = u->pos;
			gb->model  = gbModel;
			gb->decal  = nullptr;
			gb->facing = u->buildFacing;
			gb->dir    = u->frontdir;
			gb->team   = u->team;

			deadGhostBuildings[allyTeam][gbModel->type].push_back(gb);

			groundDecals->GhostCreated(u, gb);
		}
		VectorErase(liveGhostBuildings[allyTeam][MDL_TYPE(u)], u);
	}

	if (u->model != nullptr) {
		// delete from both; cloaked state is unreliable at this point
		alphaModelRenderers[MDL_TYPE(u)]->DelUnit(u);
		opaqueModelRenderers[MDL_TYPE(u)]->DelUnit(u);
	}

	VectorErase(unsortedUnits, u);

	UpdateUnitMiniMapIcon(unit, false, true);
	LuaObjectDrawer::SetObjectLOD(u, LUAOBJ_UNIT, 0);
}


void CUnitDrawer::UnitCloaked(const CUnit* unit) {
	CUnit* u = const_cast<CUnit*>(unit);

	if (u->model != nullptr) {
		alphaModelRenderers[MDL_TYPE(u)]->AddUnit(u);
		opaqueModelRenderers[MDL_TYPE(u)]->DelUnit(u);
	}
}

void CUnitDrawer::UnitDecloaked(const CUnit* unit) {
	CUnit* u = const_cast<CUnit*>(unit);

	if (u->model != nullptr) {
		opaqueModelRenderers[MDL_TYPE(u)]->AddUnit(u);
		alphaModelRenderers[MDL_TYPE(u)]->DelUnit(u);
	}
}

void CUnitDrawer::UnitEnteredLos(const CUnit* unit, int allyTeam) {
	CUnit* u = const_cast<CUnit*>(unit); //cleanup

	if (gameSetup->ghostedBuildings && unit->unitDef->IsImmobileUnit())
		VectorErase(liveGhostBuildings[allyTeam][MDL_TYPE(unit)], u);

	if (allyTeam != gu->myAllyTeam)
		return;

	UpdateUnitMiniMapIcon(unit, false, false);
}

void CUnitDrawer::UnitLeftLos(const CUnit* unit, int allyTeam) {
	CUnit* u = const_cast<CUnit*>(unit); //cleanup

	if (gameSetup->ghostedBuildings && unit->unitDef->IsImmobileUnit())
		VectorInsertUnique(liveGhostBuildings[allyTeam][MDL_TYPE(unit)], u, true);

	if (allyTeam != gu->myAllyTeam)
		return;

	UpdateUnitMiniMapIcon(unit, false, false);
}

void CUnitDrawer::UnitEnteredRadar(const CUnit* unit, int allyTeam) {
	if (allyTeam != gu->myAllyTeam)
		return;

	UpdateUnitMiniMapIcon(unit, false, false);
}

void CUnitDrawer::UnitLeftRadar(const CUnit* unit, int allyTeam) {
	if (allyTeam != gu->myAllyTeam)
		return;

	UpdateUnitMiniMapIcon(unit, false, false);
}


void CUnitDrawer::PlayerChanged(int playerNum) {
	if (playerNum != gu->myPlayerNum)
		return;

	for (auto iconIt = unitsByIcon.begin(); iconIt != unitsByIcon.end(); ++iconIt) {
		(iconIt->second).clear();
	}

	for (CUnit* unit: unsortedUnits) {
		// force an erase (no-op) followed by an insert
		UpdateUnitMiniMapIcon(unit, true, false);
	}
}

void CUnitDrawer::SunChanged() {
	unitDrawerStates[DRAWER_STATE_SEL]->UpdateCurrentShaderSky(this, sky->GetLight());
}



bool CUnitDrawer::ObjectVisibleReflection(const float3 objPos, const float3 camPos, float maxRadius)
{
    //stub method
}



void CUnitDrawer::AddTempDrawUnit(const TempDrawUnit& tdu)
{
    //stub method
}

void CUnitDrawer::UpdateTempDrawUnits(std::vector<TempDrawUnit>& tempDrawUnits)
{
    //stub method
}

