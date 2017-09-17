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
}

static inline CUnit* ParseDrawUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}




static inline bool IsFeatureVisible(const lua_State* L, const CFeature* feature)
{
    //stub method
}

static CFeature* ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
}




/******************************************************************************/
/******************************************************************************/

void LuaOpenGL::Init()
{
    //stub method
}

void LuaOpenGL::Free()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

bool LuaOpenGL::PushEntries(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void LuaOpenGL::ResetGLState()
{
    //stub method
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
}


void LuaOpenGL::DisableCommon(DrawMode mode)
{
    //stub method
}


/******************************************************************************/
//
//  Genesis
//

void LuaOpenGL::EnableDrawGenesis()
{
    //stub method
}


void LuaOpenGL::DisableDrawGenesis()
{
    //stub method
}


void LuaOpenGL::ResetDrawGenesis()
{
    //stub method
}


/******************************************************************************/
//
//  World
//

void LuaOpenGL::EnableDrawWorld()
{
    //stub method
}

void LuaOpenGL::DisableDrawWorld()
{
    //stub method
}

void LuaOpenGL::ResetDrawWorld()
{
    //stub method
}


/******************************************************************************/
//
//  WorldPreUnit -- the same as World
//

void LuaOpenGL::EnableDrawWorldPreUnit()
{
    //stub method
}

void LuaOpenGL::DisableDrawWorldPreUnit()
{
    //stub method
}

void LuaOpenGL::ResetDrawWorldPreUnit()
{
    //stub method
}


/******************************************************************************/
//
//  WorldShadow
//

void LuaOpenGL::EnableDrawWorldShadow()
{
    //stub method
}

void LuaOpenGL::DisableDrawWorldShadow()
{
    //stub method
}

void LuaOpenGL::ResetDrawWorldShadow()
{
    //stub method
}


/******************************************************************************/
//
//  WorldReflection
//

void LuaOpenGL::EnableDrawWorldReflection()
{
    //stub method
}

void LuaOpenGL::DisableDrawWorldReflection()
{
    //stub method
}

void LuaOpenGL::ResetDrawWorldReflection()
{
    //stub method
}


/******************************************************************************/
//
//  WorldRefraction
//

void LuaOpenGL::EnableDrawWorldRefraction()
{
    //stub method
}

void LuaOpenGL::DisableDrawWorldRefraction()
{
    //stub method
}

void LuaOpenGL::ResetDrawWorldRefraction()
{
    //stub method
}


/******************************************************************************/
//
//  ScreenEffects -- same as Screen
//

void LuaOpenGL::EnableDrawScreenEffects()
{
    //stub method
}


void LuaOpenGL::DisableDrawScreenEffects()
{
    //stub method
}


void LuaOpenGL::ResetDrawScreenEffects()
{
    //stub method
}


/******************************************************************************/
//
//  Screen
//

void LuaOpenGL::EnableDrawScreen()
{
    //stub method
}


void LuaOpenGL::DisableDrawScreen()
{
    //stub method
}


void LuaOpenGL::ResetDrawScreen()
{
    //stub method
}


/******************************************************************************/
//
//  MiniMap
//

void LuaOpenGL::EnableDrawInMiniMap()
{
    //stub method
}


void LuaOpenGL::DisableDrawInMiniMap()
{
    //stub method
}


void LuaOpenGL::ResetDrawInMiniMap()
{
    //stub method
}


/******************************************************************************/
//
//  MiniMap BG
//

void LuaOpenGL::EnableDrawInMiniMapBackground()
{
    //stub method
}


void LuaOpenGL::DisableDrawInMiniMapBackground()
{
    //stub method
}


void LuaOpenGL::ResetDrawInMiniMapBackground()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void LuaOpenGL::SetupWorldLighting()
{
    //stub method
}


void LuaOpenGL::RevertWorldLighting()
{
    //stub method
}


void LuaOpenGL::SetupScreenMatrices()
{
    //stub method
}


void LuaOpenGL::RevertScreenMatrices()
{
    //stub method
}


void LuaOpenGL::SetupScreenLighting()
{
    //stub method
}


void LuaOpenGL::RevertScreenLighting()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void LuaOpenGL::ResetGenesisMatrices()
{
    //stub method
}


void LuaOpenGL::ResetWorldMatrices()
{
    //stub method
}


void LuaOpenGL::ResetWorldShadowMatrices()
{
    //stub method
}


void LuaOpenGL::ResetScreenMatrices()
{
    //stub method
}


void LuaOpenGL::ResetMiniMapMatrices()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/


inline void LuaOpenGL::CheckDrawingEnabled(lua_State* L, const char* caller)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::HasExtension(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetNumber(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetString(lua_State* L)
{
    //stub method
}


int LuaOpenGL::ConfigScreen(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetViewSizes(lua_State* L)
{
    //stub method
}


int LuaOpenGL::SlaveMiniMap(lua_State* L)
{
    //stub method
}


int LuaOpenGL::ConfigMiniMap(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DrawMiniMap(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
//
//  Font Renderer
//

int LuaOpenGL::BeginText(lua_State* L)
{
    //stub method
}


int LuaOpenGL::EndText(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Text(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetTextWidth(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetTextHeight(lua_State* L)
{
    //stub method
}


/******************************************************************************/

static void GLObjectPiece(lua_State* L, const CSolidObject* obj)
{
    //stub method
}

static void GLObjectPieceMultMatrix(lua_State* L, const CSolidObject* obj)
{
    //stub method
}

static bool GLObjectDrawWithLuaMat(lua_State* L, CSolidObject* obj, LuaObjType objType)
{
    //stub method
}


static void GLObjectShape(lua_State* L, const SolidObjectDef* def)
{
    //stub method
}


static void GLObjectTextures(lua_State* L, const CSolidObject* obj)
{
    //stub method
}

static void GLObjectShapeTextures(lua_State* L, const SolidObjectDef* def)
{
    //stub method
}


int LuaOpenGL::UnitCommon(lua_State* L, bool applyTransform, bool callDrawUnit)
{
    //stub method
}

int LuaOpenGL::Unit(lua_State* L) { return (UnitCommon(L, true, true)); }
int LuaOpenGL::UnitRaw(lua_State* L) { return (UnitCommon(L, false, false)); }

int LuaOpenGL::UnitTextures(lua_State* L)
{
    //stub method
}

int LuaOpenGL::UnitShape(lua_State* L)
{
    //stub method
}

int LuaOpenGL::UnitShapeTextures(lua_State* L)
{
    //stub method
}


int LuaOpenGL::UnitMultMatrix(lua_State* L)
{
    //stub method
}

int LuaOpenGL::UnitPiece(lua_State* L)
{
    //stub method
}

int LuaOpenGL::UnitPieceMatrix(lua_State* L) { return (UnitPieceMultMatrix(L)); }
int LuaOpenGL::UnitPieceMultMatrix(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::FeatureCommon(lua_State* L, bool applyTransform, bool callDrawFeature)
{
    //stub method
}

int LuaOpenGL::Feature(lua_State* L) { return (FeatureCommon(L, true, true)); }
int LuaOpenGL::FeatureRaw(lua_State* L) { return (FeatureCommon(L, false, false)); }

int LuaOpenGL::FeatureTextures(lua_State* L)
{
    //stub method
}

int LuaOpenGL::FeatureShape(lua_State* L)
{
    //stub method
}

int LuaOpenGL::FeatureShapeTextures(lua_State* L)
{
    //stub method
}


int LuaOpenGL::FeatureMultMatrix(lua_State* L)
{
    //stub method
}

int LuaOpenGL::FeaturePiece(lua_State* L)
{
    //stub method
}


int LuaOpenGL::FeaturePieceMatrix(lua_State* L) { return (FeaturePieceMultMatrix(L)); }
int LuaOpenGL::FeaturePieceMultMatrix(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaOpenGL::DrawListAtUnit(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DrawFuncAtUnit(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DrawGroundCircle(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DrawGroundQuad(lua_State* L)
{
    //stub method
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
}


int LuaOpenGL::Shape(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::BeginEnd(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::Vertex(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Normal(lua_State* L)
{
    //stub method
}


int LuaOpenGL::TexCoord(lua_State* L)
{
    //stub method
}


int LuaOpenGL::MultiTexCoord(lua_State* L)
{
    //stub method
}


int LuaOpenGL::SecondaryColor(lua_State* L)
{
    //stub method
}


int LuaOpenGL::FogCoord(lua_State* L)
{
    //stub method
}


int LuaOpenGL::EdgeFlag(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::Rect(lua_State* L)
{
    //stub method
}


int LuaOpenGL::TexRect(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::Color(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Material(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::ResetState(lua_State* L)
{
    //stub method
}


int LuaOpenGL::ResetMatrices(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Lighting(lua_State* L)
{
    //stub method
}


int LuaOpenGL::ShadeModel(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Scissor(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Viewport(lua_State* L)
{
    //stub method
}


int LuaOpenGL::ColorMask(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DepthMask(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DepthTest(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DepthClamp(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Culling(lua_State* L)
{
    //stub method
}


int LuaOpenGL::LogicOp(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Fog(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Blending(lua_State* L)
{
    //stub method
}


int LuaOpenGL::BlendEquation(lua_State* L)
{
    //stub method
}


int LuaOpenGL::BlendFunc(lua_State* L)
{
    //stub method
}


int LuaOpenGL::BlendEquationSeparate(lua_State* L)
{
    //stub method
}


int LuaOpenGL::BlendFuncSeparate(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Smoothing(lua_State* L)
{
    //stub method
}


int LuaOpenGL::AlphaTest(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PolygonMode(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PolygonOffset(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::StencilTest(lua_State* L)
{
    //stub method
}


int LuaOpenGL::StencilMask(lua_State* L)
{
    //stub method
}


int LuaOpenGL::StencilFunc(lua_State* L)
{
    //stub method
}


int LuaOpenGL::StencilOp(lua_State* L)
{
    //stub method
}


int LuaOpenGL::StencilMaskSeparate(lua_State* L)
{
    //stub method
}


int LuaOpenGL::StencilFuncSeparate(lua_State* L)
{
    //stub method
}


int LuaOpenGL::StencilOpSeparate(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::LineStipple(lua_State* L)
{
    //stub method
}


int LuaOpenGL::LineWidth(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PointSize(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PointSprite(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PointParameter(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Texture(lua_State* L)
{
    //stub method
}


int LuaOpenGL::CreateTexture(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DeleteTexture(lua_State* L)
{
    //stub method
}


// FIXME: obsolete
int LuaOpenGL::DeleteTextureFBO(lua_State* L)
{
    //stub method
}


int LuaOpenGL::TextureInfo(lua_State* L)
{
    //stub method
}


int LuaOpenGL::CopyToTexture(lua_State* L)
{
    //stub method
}


// FIXME: obsolete
int LuaOpenGL::RenderToTexture(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GenerateMipmap(lua_State* L)
{
    //stub method
}


int LuaOpenGL::ActiveTexture(lua_State* L)
{
    //stub method
}


int LuaOpenGL::TexEnv(lua_State* L)
{
    //stub method
}


int LuaOpenGL::MultiTexEnv(lua_State* L)
{
    //stub method
}


static void SetTexGenState(GLenum target, bool state)
{
    //stub method
}


int LuaOpenGL::TexGen(lua_State* L)
{
    //stub method
}


int LuaOpenGL::MultiTexGen(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::Clear(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::Translate(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Scale(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Rotate(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Ortho(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Frustum(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Billboard(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::Light(lua_State* L)
{
    //stub method
}


int LuaOpenGL::ClipPlane(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::MatrixMode(lua_State* L)
{
    //stub method
}


int LuaOpenGL::LoadIdentity(lua_State* L)
{
    //stub method
}


int LuaOpenGL::LoadMatrix(lua_State* L)
{
    //stub method
}


int LuaOpenGL::MultMatrix(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PushMatrix(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PopMatrix(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PushPopMatrix(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetMatrixData(lua_State* L)
{
    //stub method
}

/******************************************************************************/

int LuaOpenGL::PushAttrib(lua_State* L)
{
    //stub method
}


int LuaOpenGL::PopAttrib(lua_State* L)
{
    //stub method
}


int LuaOpenGL::UnsafeState(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::CreateList(lua_State* L)
{
    //stub method
}


int LuaOpenGL::CallList(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DeleteList(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::Flush(lua_State* L)
{
    //stub method
}


int LuaOpenGL::Finish(lua_State* L)
{
    //stub method
}


/******************************************************************************/

static int PixelFormatSize(GLenum f)
{
    //stub method
}


static void PushPixelData(lua_State* L, int fSize, const float*& data)
{
    //stub method
}


int LuaOpenGL::ReadPixels(lua_State* L)
{
    //stub method
}


int LuaOpenGL::SaveImage(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::CreateQuery(lua_State* L)
{
    //stub method
}


int LuaOpenGL::DeleteQuery(lua_State* L)
{
    //stub method
}


int LuaOpenGL::RunQuery(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetQuery(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaOpenGL::GetGlobalTexNames(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetGlobalTexCoords(lua_State* L)
{
    //stub method
}


int LuaOpenGL::GetShadowMapParams(lua_State* L)
{
    //stub method
}

int LuaOpenGL::GetAtmosphere(lua_State* L)
{
    //stub method
}

int LuaOpenGL::GetSun(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/
