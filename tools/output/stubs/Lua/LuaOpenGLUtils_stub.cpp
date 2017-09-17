#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <map>
#include <set>

#include "LuaOpenGLUtils.h"

#include "Game/Camera.h"
#include "LuaHandle.h"
#include "LuaTextures.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/HeightMapTexture.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/GeometryBuffer.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/IconHandler.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Map/InfoTexture/InfoTexture.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/3DOTextureHandler.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitDefImage.h"
#include "System/Log/ILog.h"
#include "System/Matrix44f.h"
#include "System/Sync/HsiehHash.h"
#include "System/Util.h"

// for "$info:los", etc
static std::unordered_map<size_t, LuaMatTexture> luaMatTextures;

static const std::unordered_map<std::string, LuaMatTexture::Type>
  luaMatTexTypeMap = {
      // atlases
      { "$units", LuaMatTexture::LUATEX_3DOTEXTURE },
      { "$units1", LuaMatTexture::LUATEX_3DOTEXTURE },
      { "$units2", LuaMatTexture::LUATEX_3DOTEXTURE },

      // cubemaps
      { "$specular", LuaMatTexture::LUATEX_SPECULAR },
      { "$reflection", LuaMatTexture::LUATEX_MAP_REFLECTION },
      { "$map_reflection", LuaMatTexture::LUATEX_MAP_REFLECTION },
      { "$sky_reflection", LuaMatTexture::LUATEX_SKY_REFLECTION },

      // specials
      { "$shadow", LuaMatTexture::LUATEX_SHADOWMAP },
      { "$heightmap", LuaMatTexture::LUATEX_HEIGHTMAP },

      // SMF-maps
      { "$grass", LuaMatTexture::LUATEX_SMF_GRASS },
      { "$detail", LuaMatTexture::LUATEX_SMF_DETAIL },
      { "$minimap", LuaMatTexture::LUATEX_SMF_MINIMAP },
      { "$shading", LuaMatTexture::LUATEX_SMF_SHADING },
      { "$normals", LuaMatTexture::LUATEX_SMF_NORMALS },
      // SSMF-maps
      { "$ssmf_normals", LuaMatTexture::LUATEX_SSMF_NORMALS },
      { "$ssmf_specular", LuaMatTexture::LUATEX_SSMF_SPECULAR },
      { "$ssmf_splat_distr", LuaMatTexture::LUATEX_SSMF_SDISTRIB },
      { "$ssmf_splat_detail", LuaMatTexture::LUATEX_SSMF_SDETAIL },
      { "$ssmf_splat_normals", LuaMatTexture::LUATEX_SSMF_SNORMALS },
      { "$ssmf_sky_refl", LuaMatTexture::LUATEX_SSMF_SKYREFL },
      { "$ssmf_emission", LuaMatTexture::LUATEX_SSMF_EMISSION },
      { "$ssmf_parallax", LuaMatTexture::LUATEX_SSMF_PARALLAX },

      { "$info", LuaMatTexture::LUATEX_INFOTEX_ACTIVE },
      { "$extra", LuaMatTexture::LUATEX_INFOTEX_ACTIVE },

      { "$map_gb_nt", LuaMatTexture::LUATEX_MAP_GBUFFER_NORM },
      { "$map_gb_dt", LuaMatTexture::LUATEX_MAP_GBUFFER_DIFF },
      { "$map_gb_st", LuaMatTexture::LUATEX_MAP_GBUFFER_SPEC },
      { "$map_gb_et", LuaMatTexture::LUATEX_MAP_GBUFFER_EMIT },
      { "$map_gb_mt", LuaMatTexture::LUATEX_MAP_GBUFFER_MISC },
      { "$map_gb_zt", LuaMatTexture::LUATEX_MAP_GBUFFER_ZVAL },

      { "$map_gbuffer_normtex", LuaMatTexture::LUATEX_MAP_GBUFFER_NORM },
      { "$map_gbuffer_difftex", LuaMatTexture::LUATEX_MAP_GBUFFER_DIFF },
      { "$map_gbuffer_spectex", LuaMatTexture::LUATEX_MAP_GBUFFER_SPEC },
      { "$map_gbuffer_emittex", LuaMatTexture::LUATEX_MAP_GBUFFER_EMIT },
      { "$map_gbuffer_misctex", LuaMatTexture::LUATEX_MAP_GBUFFER_MISC },
      { "$map_gbuffer_zvaltex", LuaMatTexture::LUATEX_MAP_GBUFFER_ZVAL },

      { "$mdl_gb_nt", LuaMatTexture::LUATEX_MODEL_GBUFFER_NORM },
      { "$mdl_gb_dt", LuaMatTexture::LUATEX_MODEL_GBUFFER_DIFF },
      { "$mdl_gb_st", LuaMatTexture::LUATEX_MODEL_GBUFFER_SPEC },
      { "$mdl_gb_et", LuaMatTexture::LUATEX_MODEL_GBUFFER_EMIT },
      { "$mdl_gb_mt", LuaMatTexture::LUATEX_MODEL_GBUFFER_MISC },
      { "$mdl_gb_zt", LuaMatTexture::LUATEX_MODEL_GBUFFER_ZVAL },

      { "$model_gbuffer_normtex", LuaMatTexture::LUATEX_MODEL_GBUFFER_NORM },
      { "$model_gbuffer_difftex", LuaMatTexture::LUATEX_MODEL_GBUFFER_DIFF },
      { "$model_gbuffer_spectex", LuaMatTexture::LUATEX_MODEL_GBUFFER_SPEC },
      { "$model_gbuffer_emittex", LuaMatTexture::LUATEX_MODEL_GBUFFER_EMIT },
      { "$model_gbuffer_misctex", LuaMatTexture::LUATEX_MODEL_GBUFFER_MISC },
      { "$model_gbuffer_zvaltex", LuaMatTexture::LUATEX_MODEL_GBUFFER_ZVAL },

      { "$font", LuaMatTexture::LUATEX_FONT },
      { "$smallfont", LuaMatTexture::LUATEX_FONTSMALL },
      { "$fontsmall", LuaMatTexture::LUATEX_FONTSMALL },

  };

static const std::unordered_map<std::string, LuaMatrixType> luaMatrixTypeMap = {
    { "view", LUAMATRICES_VIEW },
    { "projection", LUAMATRICES_PROJECTION },
    { "viewprojection", LUAMATRICES_VIEWPROJECTION },
    { "viewinverse", LUAMATRICES_VIEWINVERSE },
    { "projectioninverse", LUAMATRICES_PROJECTIONINVERSE },
    { "viewprojectioninverse", LUAMATRICES_VIEWPROJECTIONINVERSE },
    { "billboard", LUAMATRICES_BILLBOARD },
    { "shadow", LUAMATRICES_SHADOW },

    // backward compability
    { "camera", LUAMATRICES_VIEW },
    { "camprj", LUAMATRICES_PROJECTION },
    { "caminv", LUAMATRICES_VIEWINVERSE },
    { "camprjinv", LUAMATRICES_PROJECTIONINVERSE },
};

/******************************************************************************/
/******************************************************************************/

void
LuaOpenGLUtils::ResetState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaMatTexture::Type
LuaOpenGLUtils::GetLuaMatTextureType(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LuaMatrixType
LuaOpenGLUtils::GetLuaMatrixType(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CMatrix44f*
LuaOpenGLUtils::GetNamedMatrix(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

S3DModel*
ParseModel(int defID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ParseTexture(const S3DModel* model, LuaMatTexture& texUnit, char texNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ParseUnitTexture(LuaMatTexture& texUnit, const std::string& texture)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ParseNamedSubTexture(LuaMatTexture& texUnit, const std::string& texName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaOpenGLUtils::ParseTextureImage(lua_State* L,
                                  LuaMatTexture& texUnit,
                                  const std::string& image)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLuint
LuaMatTexture::GetTextureID() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLuint
LuaMatTexture::GetTextureTarget() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaMatTexture::Bind() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaMatTexture::Unbind() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int2
LuaMatTexture::GetSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaMatTexture::Finalize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaMatTexture::Compare(const LuaMatTexture& a, const LuaMatTexture& b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaMatTexture::Print(const string& indent) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
