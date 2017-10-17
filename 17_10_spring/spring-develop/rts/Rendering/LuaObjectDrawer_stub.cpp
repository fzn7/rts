#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaObjectDrawer.h"
#include "FeatureDrawer.h"
#include "Game/Camera.h"
#include "Game/Game.h" // drawMode
#include "Lua/LuaMaterial.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Models/3DModel.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShadowHandler.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/GlobalConstants.h" // MAX_TEAMS
#include "Sim/Objects/SolidObject.h"
#include "Sim/Units/Unit.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Util.h"
#include "UnitDrawer.h"
#include "UnitDrawerState.hpp"

#define USE_OBJECT_RENDERING_BUCKETS

// applies to both units and features
CONFIG(bool, AllowDeferredModelRendering)
  .defaultValue(false)
  .safemodeValue(false);
CONFIG(bool, AllowDeferredModelBufferClear)
  .defaultValue(false)
  .safemodeValue(false);

CONFIG(float, LODScale).defaultValue(1.0f);
CONFIG(float, LODScaleShadow).defaultValue(1.0f);
CONFIG(float, LODScaleReflection).defaultValue(1.0f);
CONFIG(float, LODScaleRefraction).defaultValue(1.0f);

GL::GeometryBuffer* LuaObjectDrawer::geomBuffer = nullptr;

bool LuaObjectDrawer::inDrawPass = false;
bool LuaObjectDrawer::inAlphaBin = false;

bool LuaObjectDrawer::drawDeferredEnabled = false;
bool LuaObjectDrawer::drawDeferredAllowed = false;
bool LuaObjectDrawer::bufferClearAllowed = false;

int LuaObjectDrawer::binObjTeam = -1;

float LuaObjectDrawer::LODScale[LUAOBJ_LAST];
float LuaObjectDrawer::LODScaleShadow[LUAOBJ_LAST];
float LuaObjectDrawer::LODScaleReflection[LUAOBJ_LAST];
float LuaObjectDrawer::LODScaleRefraction[LUAOBJ_LAST];

#ifdef USE_STD_FUNCTION
#define CALL_FUNC_NA(OBJ, FUN) (FUN)((OBJ))
#define CALL_FUNC_VA(OBJ, FUN, ...) (FUN)((OBJ), __VA_ARGS__)

typedef std::function<void(CEventHandler*)> EventFunc;
typedef std::function<
  void(CUnitDrawer*, const CUnit*, unsigned int, unsigned int, bool, bool)>
  UnitDrawFunc;
typedef std::function<void(CFeatureDrawer*,
                           const CFeature*,
                           unsigned int,
                           unsigned int,
                           bool,
                           bool)>
  FeatureDrawFunc;

#else
#define CALL_FUNC_NA(OBJ, FUN) ((OBJ)->*(FUN))()
#define CALL_FUNC_VA(OBJ, FUN, ...) ((OBJ)->*(FUN))(__VA_ARGS__)

// much nastier syntax especially for member functions
// (another reason to use statics), but also much more
// cache-friendly than std::function's ASM bloat
//
// (if only 'decltype(auto) unitDrawFuncs[2] = {&CUnitDrawer::DrawUnitNoTrans,
// ...}' would work, or even 'std::array<auto, 2> unitDrawFuncs =
// {&CUnitDrawer::DrawUnitNoTrans, ...}' while this can actually be done with
// C++11 forward magic, the code becomes unreadable)
//
typedef void (CEventHandler::*EventFunc)();
typedef void (CUnitDrawer ::*UnitDrawFunc)(const CUnit*,
                                           unsigned int,
                                           unsigned int,
                                           bool,
                                           bool);
typedef void (CFeatureDrawer::*FeatureDrawFunc)(const CFeature*,
                                                unsigned int,
                                                unsigned int,
                                                bool,
                                                bool);

#endif

typedef const void (*TeamColorFunc)(const bool,
                                    const CSolidObject*,
                                    const LuaMaterial*,
                                    const float2);

#ifdef USE_STD_ARRAY
#define DECL_ARRAY(TYPE, NAME, SIZE) std::array<TYPE, SIZE> NAME
#else
#define DECL_ARRAY(TYPE, NAME, SIZE) TYPE NAME[SIZE]
#endif

// these should remain valid on reload
static DECL_ARRAY(EventFunc, eventFuncs, LUAOBJ_LAST) = { nullptr, nullptr };

// transform and no-transform variants
static DECL_ARRAY(UnitDrawFunc, unitDrawFuncs, 2) = { nullptr, nullptr };
static DECL_ARRAY(FeatureDrawFunc, featureDrawFuncs, 2) = { nullptr, nullptr };

static DECL_ARRAY(bool, notifyEventFlags, LUAOBJ_LAST) = { false, false };
static DECL_ARRAY(bool, bufferClearFlags, LUAOBJ_LAST) = { true, true };

static const DECL_ARRAY(LuaMatType, opaqueMats, 2) = { LUAMAT_OPAQUE,
                                                       LUAMAT_OPAQUE_REFLECT };
static const DECL_ARRAY(LuaMatType, alphaMats, 2) = { LUAMAT_ALPHA,
                                                      LUAMAT_ALPHA_REFLECT };

static const DECL_ARRAY(LuaMatShader::Pass,
                        shaderPasses,
                        2) = { LuaMatShader::LUASHADER_PASS_FWD,
                               LuaMatShader::LUASHADER_PASS_DFR };

#ifdef USE_OBJECT_RENDERING_BUCKETS
static DECL_ARRAY(std::vector<const CSolidObject*>, objectBuckets, MAX_TEAMS);
#endif

static float
GetLODFloat(const std::string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// opaque-pass state management funcs
static void
SetupOpaqueUnitDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
ResetOpaqueUnitDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// NOTE: incomplete (FeatureDrawer::Draw sets more state)
static void
SetupOpaqueFeatureDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
static void
ResetOpaqueFeatureDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// transparency-pass (reflection, ...) state management funcs
static void
SetupAlphaUnitDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
ResetAlphaUnitDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// NOTE: incomplete (FeatureDrawer::DrawAlphaPass sets more state)
static void
SetupAlphaFeatureDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
static void
ResetAlphaFeatureDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// shadow-pass state management funcs
// FIXME: setup face culling for S3O?
static void
SetupShadowUnitDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
ResetShadowUnitDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// NOTE: incomplete (FeatureDrawer::DrawShadowPass sets more state)
static void
SetupShadowFeatureDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
static void
ResetShadowFeatureDrawState(unsigned int modelType, bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
SetObjectTeamColorNoType(const bool deferredPass,
                         const CSolidObject* o,
                         const LuaMaterial* m,
                         const float2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
SetObjectTeamColorCustom(const bool deferredPass,
                         const CSolidObject* o,
                         const LuaMaterial* m,
                         const float2 alpha)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const void
SetObjectTeamColorEngine(const bool deferredPass,
                         const CSolidObject* o,
                         const LuaMaterial* m,
                         const float2 alpha)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static const TeamColorFunc teamColorFuncs[] = {
    SetObjectTeamColorNoType,
    SetObjectTeamColorCustom,
    SetObjectTeamColorEngine,
};

static inline unsigned int
GetTeamColorFuncIndex(const CSolidObject* o, const LuaMatShader* s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::Init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::Kill()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::Update(bool init)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::ReadLODScales(LuaObjType objType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::SetDrawPassGlobalLODFactor(LuaObjType objType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LuaMatType
LuaObjectDrawer::GetDrawPassOpaqueMat()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
LuaMatType
LuaObjectDrawer::GetDrawPassAlphaMat()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::DrawMaterialBins(LuaObjType objType,
                                  LuaMatType matType,
                                  bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::DrawMaterialBin(const LuaMatBin* currBin,
                                 const LuaMaterial* prevMat,
                                 LuaObjType objType,
                                 LuaMatType matType,
                                 bool deferredPass,
                                 bool alphaMatBin)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::DrawBinObject(const CSolidObject* obj,
                               LuaObjType objType,
                               const LuaObjectLODMaterial* lodMat,
                               const LuaMaterial* luaMat,
                               bool deferredPass,
                               bool alphaMatBin,
                               bool applyTrans,
                               bool noLuaCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::DrawDeferredPass(LuaObjType objType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaObjectDrawer::DrawSingleObjectCommon(const CSolidObject* obj,
                                        LuaObjType objType,
                                        bool applyTrans)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaObjectDrawer::DrawSingleObject(const CSolidObject* obj, LuaObjType objType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaObjectDrawer::DrawSingleObjectNoTrans(const CSolidObject* obj,
                                         LuaObjType objType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::SetObjectLOD(CSolidObject* obj,
                              LuaObjType objType,
                              unsigned int lodCount)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaObjectDrawer::AddObjectForLOD(CSolidObject* obj,
                                 LuaObjType objType,
                                 bool useAlphaMat,
                                 bool useShadowMat)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaObjectDrawer::AddOpaqueMaterialObject(CSolidObject* obj, LuaObjType objType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaObjectDrawer::AddAlphaMaterialObject(CSolidObject* obj, LuaObjType objType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LuaObjectDrawer::AddShadowMaterialObject(CSolidObject* obj, LuaObjType objType)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::DrawOpaqueMaterialObjects(LuaObjType objType,
                                           bool deferredPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::DrawAlphaMaterialObjects(LuaObjType objType, bool)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LuaObjectDrawer::DrawShadowMaterialObjects(LuaObjType objType, bool)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
