#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


// TODO:
// - go back to counting matrix push/pops (just for modelview?)
//   would have to make sure that display lists are also handled
//   (GL_MODELVIEW_STACK_DEPTH could help current situation, but
//    requires the ARB_imaging extension)
// - use materials instead of raw calls (again, handle dlists)

#include "Rendering/GL/myGL.h"
#include <string>
#include <vector>
#include <algorithm>

#include "LuaOpenGL.h"

#include "LuaInclude.h"
#include "LuaContextData.h"
#include "LuaDisplayLists.h"
#include "LuaFBOs.h"
#include "LuaFonts.h"
#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaIO.h"
#include "LuaOpenGLUtils.h"
#include "LuaRBOs.h"
#include "LuaShaders.h"
#include "LuaTextures.h"
#include "LuaUtils.h"
//FIXME#include "LuaVBOs.h"
#include "Game/Camera.h"
#include "Game/UI/CommandColors.h"
#include "Game/UI/MiniMap.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/HeightMapTexture.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/IconHandler.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/FeatureDrawer.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/Models/3DModel.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Rendering/Textures/3DOTextureHandler.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitDefImage.h"
#include "Sim/Units/UnitHandler.h"
#include "System/Log/ILog.h"
#include "System/Matrix44f.h"
#include "System/Config/ConfigHandler.h"

using std::max;
using std::string;

#undef far // avoid collision with windef.h
#undef near

CONFIG(bool, LuaShaders).defaultValue(true).headlessValue(false).safemodeValue(false);

static const int MAX_TEXTURE_UNITS = 32;

/******************************************************************************/
/******************************************************************************/

void (*LuaOpenGL::resetMatrixFunc)(void) = NULL;

unsigned int LuaOpenGL::resetStateList = 0;

LuaOpenGL::DrawMode LuaOpenGL::drawMode = LuaOpenGL::DRAW_NONE;
LuaOpenGL::DrawMode LuaOpenGL::prevDrawMode = LuaOpenGL::DRAW_NONE;

bool  LuaOpenGL::safeMode = true;
bool  LuaOpenGL::canUseShaders = false;

float LuaOpenGL::screenWidth = 0.36f;
float LuaOpenGL::screenDistance = 0.60f;

std::set<unsigned int> LuaOpenGL::occlusionQueries;




static inline CUnit* ParseUnit(lua_State* L, const char* caller, int index, bool allyCheck = true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline CUnit* ParseDrawUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




static inline bool IsFeatureVisible(const lua_State* L, const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static CFeature* ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




/******************************************************************************/
/******************************************************************************/

void LuaOpenGL::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::Free()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

bool LuaOpenGL::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void LuaOpenGL::ResetGLState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
//  Common routines
//

const GLbitfield AttribBits =
	GL_COLOR_BUFFER_BIT |
	GL_DEPTH_BUFFER_BIT |
	GL_ENABLE_BIT       |
	GL_LIGHTING_BIT     |
	GL_LINE_BIT         |
	GL_POINT_BIT        |
	GL_POLYGON_BIT      |
	GL_VIEWPORT_BIT;


void LuaOpenGL::EnableCommon(DrawMode mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::DisableCommon(DrawMode mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  Genesis
//

void LuaOpenGL::EnableDrawGenesis()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::DisableDrawGenesis()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetDrawGenesis()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  World
//

void LuaOpenGL::EnableDrawWorld()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::DisableDrawWorld()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::ResetDrawWorld()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  WorldPreUnit -- the same as World
//

void LuaOpenGL::EnableDrawWorldPreUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::DisableDrawWorldPreUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::ResetDrawWorldPreUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  WorldShadow
//

void LuaOpenGL::EnableDrawWorldShadow()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::DisableDrawWorldShadow()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::ResetDrawWorldShadow()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  WorldReflection
//

void LuaOpenGL::EnableDrawWorldReflection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::DisableDrawWorldReflection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::ResetDrawWorldReflection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  WorldRefraction
//

void LuaOpenGL::EnableDrawWorldRefraction()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::DisableDrawWorldRefraction()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaOpenGL::ResetDrawWorldRefraction()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  ScreenEffects -- same as Screen
//

void LuaOpenGL::EnableDrawScreenEffects()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::DisableDrawScreenEffects()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetDrawScreenEffects()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  Screen
//

void LuaOpenGL::EnableDrawScreen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::DisableDrawScreen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetDrawScreen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  MiniMap
//

void LuaOpenGL::EnableDrawInMiniMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::DisableDrawInMiniMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetDrawInMiniMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  MiniMap BG
//

void LuaOpenGL::EnableDrawInMiniMapBackground()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::DisableDrawInMiniMapBackground()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetDrawInMiniMapBackground()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void LuaOpenGL::SetupWorldLighting()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::RevertWorldLighting()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::SetupScreenMatrices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::RevertScreenMatrices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::SetupScreenLighting()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::RevertScreenLighting()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void LuaOpenGL::ResetGenesisMatrices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetWorldMatrices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetWorldShadowMatrices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetScreenMatrices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaOpenGL::ResetMiniMapMatrices()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/


inline void LuaOpenGL::CheckDrawingEnabled(lua_State* L, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::HasExtension(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetNumber(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetString(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::ConfigScreen(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetViewSizes(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::SlaveMiniMap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::ConfigMiniMap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DrawMiniMap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
//  Font Renderer
//

int LuaOpenGL::BeginText(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::EndText(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Text(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetTextWidth(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetTextHeight(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static void GLObjectPiece(lua_State* L, const CSolidObject* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void GLObjectPieceMultMatrix(lua_State* L, const CSolidObject* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool GLObjectDrawWithLuaMat(lua_State* L, CSolidObject* obj, LuaObjType objType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void GLObjectShape(lua_State* L, const SolidObjectDef* def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void GLObjectTextures(lua_State* L, const CSolidObject* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void GLObjectShapeTextures(lua_State* L, const SolidObjectDef* def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::UnitCommon(lua_State* L, bool applyTransform, bool callDrawUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::Unit(lua_State* L) { return (UnitCommon(L, true, true)); }
int LuaOpenGL::UnitRaw(lua_State* L) { return (UnitCommon(L, false, false)); }

int LuaOpenGL::UnitTextures(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::UnitShape(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::UnitShapeTextures(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::UnitMultMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::UnitPiece(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::UnitPieceMatrix(lua_State* L) { return (UnitPieceMultMatrix(L)); }
int LuaOpenGL::UnitPieceMultMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::FeatureCommon(lua_State* L, bool applyTransform, bool callDrawFeature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::Feature(lua_State* L) { return (FeatureCommon(L, true, true)); }
int LuaOpenGL::FeatureRaw(lua_State* L) { return (FeatureCommon(L, false, false)); }

int LuaOpenGL::FeatureTextures(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::FeatureShape(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::FeatureShapeTextures(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::FeatureMultMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::FeaturePiece(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::FeaturePieceMatrix(lua_State* L) { return (FeaturePieceMultMatrix(L)); }
int LuaOpenGL::FeaturePieceMultMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaOpenGL::DrawListAtUnit(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DrawFuncAtUnit(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DrawGroundCircle(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DrawGroundQuad(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

struct VertexData {
	float vert[3];
	float norm[3];
	float txcd[2];
	float color[4];
	bool hasVert;
	bool hasNorm;
	bool hasTxcd;
	bool hasColor;
};


static bool ParseVertexData(lua_State* L, VertexData& vd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Shape(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::BeginEnd(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::Vertex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Normal(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::TexCoord(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::MultiTexCoord(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::SecondaryColor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::FogCoord(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::EdgeFlag(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::Rect(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::TexRect(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::Color(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Material(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::ResetState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::ResetMatrices(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Lighting(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::ShadeModel(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Scissor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Viewport(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::ColorMask(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DepthMask(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DepthTest(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DepthClamp(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Culling(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::LogicOp(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Fog(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Blending(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::BlendEquation(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::BlendFunc(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::BlendEquationSeparate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::BlendFuncSeparate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Smoothing(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::AlphaTest(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PolygonMode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PolygonOffset(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::StencilTest(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::StencilMask(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::StencilFunc(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::StencilOp(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::StencilMaskSeparate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::StencilFuncSeparate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::StencilOpSeparate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::LineStipple(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::LineWidth(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PointSize(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PointSprite(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PointParameter(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Texture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::CreateTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DeleteTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// FIXME: obsolete
int LuaOpenGL::DeleteTextureFBO(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::TextureInfo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::CopyToTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// FIXME: obsolete
int LuaOpenGL::RenderToTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GenerateMipmap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::ActiveTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::TexEnv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::MultiTexEnv(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void SetTexGenState(GLenum target, bool state)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::TexGen(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::MultiTexGen(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::Clear(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::Translate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Scale(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Rotate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Ortho(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Frustum(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Billboard(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::Light(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::ClipPlane(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::MatrixMode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::LoadIdentity(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::LoadMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::MultMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PushMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PopMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PushPopMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetMatrixData(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaOpenGL::PushAttrib(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::PopAttrib(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::UnsafeState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::CreateList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::CallList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DeleteList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::Flush(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::Finish(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int PixelFormatSize(GLenum f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void PushPixelData(lua_State* L, int fSize, const float*& data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::ReadPixels(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::SaveImage(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::CreateQuery(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::DeleteQuery(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::RunQuery(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetQuery(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaOpenGL::GetGlobalTexNames(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetGlobalTexCoords(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaOpenGL::GetShadowMapParams(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::GetAtmosphere(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaOpenGL::GetSun(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
