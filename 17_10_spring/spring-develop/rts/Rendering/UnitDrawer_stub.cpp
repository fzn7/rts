#include <iostream>
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

#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/FarTextureHandler.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/IconHandler.h"
#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/Models/ModelRenderContainer.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/3DOTextureHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/S3OTextureHandler.h"

#include "Sim/Features/Feature.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"

#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/myMath.h"

#define UNIT_SHADOW_ALPHA_MASKING

CUnitDrawer* unitDrawer;

CONFIG(int, UnitLodDist).defaultValue(1000).headlessValue(0);
CONFIG(int, UnitIconDist).defaultValue(200).headlessValue(0);
CONFIG(float, UnitTransparency).defaultValue(0.7f);

CONFIG(int, MaxDynamicModelLights).defaultValue(1).minimumValue(0);

CONFIG(bool, AdvUnitShading)
  .defaultValue(true)
  .headlessValue(false)
  .safemodeValue(false)
  .description("Determines whether specular highlights and other lighting "
               "effects are rendered for units.");

static const void
BindOpaqueTex(const CS3OTextureHandler::S3OTexMat* textureMat)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
BindOpaqueTexAtlas(const CS3OTextureHandler::S3OTexMat*)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
static const void
BindOpaqueTexDummy(const CS3OTextureHandler::S3OTexMat*)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
KillShadowTex(const CS3OTextureHandler::S3OTexMat*)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
PushRenderState3DO()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
PushRenderStateS3O()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
PushRenderStateOBJ()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
static const void
PushRenderStateASS()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
PopRenderState3DO()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
static const void
PopRenderStateS3O()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
static const void
PopRenderStateOBJ()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
static const void
PopRenderStateASS()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
SetTeamColorDummy(const IUnitDrawerState* state, int team, const float2 alpha)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// typedef std::function<void(int)> BindTexFunc; typedef
// std::function<void(const CS3OTextureHandler::S3OTexMat*)> BindTexFunc;
// typedef std::function<void()> KillTexFunc;
typedef const void (*BindTexFunc)(const CS3OTextureHandler::S3OTexMat*);
typedef const void (*BindTexFunc)(const CS3OTextureHandler::S3OTexMat*);
typedef const void (*KillTexFunc)(const CS3OTextureHandler::S3OTexMat*);

typedef const void (*PushRenderStateFunc)();
typedef const void (*PopRenderStateFunc)();

typedef const void (*SetTeamColorFunc)(const IUnitDrawerState*,
                                       int team,
                                       const float2 alpha);

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
void
CUnitDrawer::BindModelTypeTexture(int mdlType, int texType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::PushModelRenderState(int mdlType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CUnitDrawer::PopModelRenderState(int mdlType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// mid-level (solo only)
void
CUnitDrawer::PushModelRenderState(const S3DModel* m)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CUnitDrawer::PopModelRenderState(const S3DModel* m)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// high-level (solo only)
void
CUnitDrawer::PushModelRenderState(const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CUnitDrawer::PopModelRenderState(const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CUnitDrawer::CUnitDrawer()
  : CEventClient("[CUnitDrawer]", 271828, false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CUnitDrawer::~CUnitDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::SetUnitDrawDist(float dist)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::SetUnitIconDist(float dist)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::Draw(bool drawReflection, bool drawRefraction)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawOpaquePass(bool deferredPass,
                            bool drawReflection,
                            bool drawRefraction)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawOpaqueUnits(int modelType,
                             bool drawReflection,
                             bool drawRefraction)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CUnitDrawer::DrawOpaqueUnit(CUnit* unit,
                            bool drawReflection,
                            bool drawRefraction)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawOpaqueAIUnits(int modelType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawOpaqueAIUnit(const TempDrawUnit& unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawUnitIcons()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
CUnitDrawer::CanDrawOpaqueUnit(const CUnit* unit,
                               bool drawReflection,
                               bool drawRefraction) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CUnitDrawer::CanDrawOpaqueUnitShadow(const CUnit* unit) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawOpaqueUnitShadow(CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawOpaqueUnitsShadow(int modelType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawShadowPass()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawIcon(CUnit* unit, bool useDefaultIcon)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::SetupAlphaDrawing(bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::ResetAlphaDrawing(bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawAlphaPass()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawAlphaUnits(int modelType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CUnitDrawer::DrawAlphaUnit(CUnit* unit,
                           int modelType,
                           bool drawGhostBuildingsPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawAlphaAIUnits(int modelType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawAlphaAIUnit(const TempDrawUnit& unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawAlphaAIUnitBorder(const TempDrawUnit& unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UpdateGhostedBuildings()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawGhostedBuildings(int modelType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::SetupOpaqueDrawing(bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::ResetOpaqueDrawing(bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const IUnitDrawerState*
CUnitDrawer::GetWantedDrawerState(bool alphaPass) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::SetTeamColour(int team, const float2 alpha) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Set up the texture environment in texture unit 0
 * to give an S3O texture its team-colour.
 *
 * Also:
 * - call SetBasicTeamColour to set the team colour to transform to.
 * - Replace the output alpha channel. If not, only the team-coloured bits will
 * show, if that. Or something.
 */
void
CUnitDrawer::SetupBasicS3OTexture0()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
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
void
CUnitDrawer::SetupBasicS3OTexture1()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::CleanupBasicS3OTexture1()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::CleanupBasicS3OTexture0()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::PushIndividualOpaqueState(const S3DModel* model,
                                       int teamID,
                                       bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::PushIndividualAlphaState(const S3DModel* model,
                                      int teamID,
                                      bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::PopIndividualOpaqueState(const S3DModel* model,
                                      int teamID,
                                      bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::PopIndividualAlphaState(const S3DModel* model,
                                     int teamID,
                                     bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::PushIndividualOpaqueState(const CUnit* unit, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::PopIndividualOpaqueState(const CUnit* unit, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawIndividual(const CUnit* unit, bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawIndividualNoTrans(const CUnit* unit, bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
DIDResetPrevProjection(bool toScreen)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
DIDResetPrevModelView()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static bool
DIDCheckMatrixMode(int wantedMode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// used by LuaOpenGL::Draw{Unit,Feature}Shape
// acts like DrawIndividual but can not apply
// custom materials
void
CUnitDrawer::DrawIndividualDefOpaque(const SolidObjectDef* objectDef,
                                     int teamID,
                                     bool rawState,
                                     bool toScreen)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// used for drawing building orders (with translucency)
void
CUnitDrawer::DrawIndividualDefAlpha(const SolidObjectDef* objectDef,
                                    int teamID,
                                    bool rawState,
                                    bool toScreen)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

typedef const void (*DrawModelBuildStageFunc)(const CUnit*,
                                              const double*,
                                              const double*,
                                              bool);

static const void
DrawModelNoopBuildStage(const CUnit*, const double*, const double*, bool)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
DrawModelFlatBuildStage(const CUnit* unit,
                        const double* upperPlane,
                        const double* lowerPlane,
                        bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
DrawModelFillBuildStage(const CUnit* unit,
                        const double* upperPlane,
                        const double* lowerPlane,
                        bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const DrawModelBuildStageFunc drawModelBuildStageFuncs[] = {
    DrawModelNoopBuildStage,
    DrawModelWireBuildStage,
    DrawModelFlatBuildStage,
    DrawModelFillBuildStage,
};

void
CUnitDrawer::DrawUnitModelBeingBuiltShadow(const CUnit* unit, bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawUnitModelBeingBuiltOpaque(const CUnit* unit, bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawUnitModel(const CUnit* unit, bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawUnitNoTrans(const CUnit* unit,
                             unsigned int preList,
                             unsigned int postList,
                             bool lodCall,
                             bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawUnit(const CUnit* unit,
                      unsigned int preList,
                      unsigned int postList,
                      bool lodCall,
                      bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CUnitDrawer::UpdateUnitIconState(CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CUnitDrawer::UpdateUnitDrawPos(CUnit* u)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CUnitDrawer::DrawAsIcon(const CUnit* unit, const float sqUnitCamDist) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// visualize if a unit can be built at specified position
bool
CUnitDrawer::ShowUnitBuildSquare(const BuildInfo& buildInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CUnitDrawer::ShowUnitBuildSquare(const BuildInfo& buildInfo,
                                 const std::vector<Command>& commands)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline const icon::CIconData*
GetUnitIcon(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline float
GetUnitIconScale(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::DrawUnitMiniMapIcon(const CUnit* unit, CVertexArray* va) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// TODO:
//   UnitDrawer::DrawIcon was half-duplicate of MiniMap::DrawUnit&co
//   the latter has been replaced by this, do the same for the former
//   (mini-map icons and real-map radar icons are the same anyway)
void
CUnitDrawer::DrawUnitMiniMapIcons() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UpdateUnitMiniMapIcon(const CUnit* unit, bool forced, bool killed)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::RenderUnitCreated(const CUnit* u, int cloaked)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::RenderUnitDestroyed(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UnitCloaked(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UnitDecloaked(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UnitEnteredLos(const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UnitLeftLos(const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UnitEnteredRadar(const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UnitLeftRadar(const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::PlayerChanged(int playerNum)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::SunChanged()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CUnitDrawer::ObjectVisibleReflection(const float3 objPos,
                                     const float3 camPos,
                                     float maxRadius)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::AddTempDrawUnit(const TempDrawUnit& tdu)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDrawer::UpdateTempDrawUnits(std::vector<TempDrawUnit>& tempDrawUnits)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
