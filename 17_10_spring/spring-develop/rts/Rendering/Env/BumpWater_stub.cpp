#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * @brief extended bump-mapping water shader
 */

#include "BumpWater.h"

#include <boost/format.hpp>

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "ISky.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "SunLighting.h"
// #include "Sim/Misc/Wind.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FastMath.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "System/bitops.h"
#include "System/myMath.h"

using std::max;
using std::min;
using std::string;
using std::vector;

CONFIG(int, BumpWaterTexSizeReflection)
  .defaultValue(512)
  .headlessValue(32)
  .minimumValue(32)
  .description("Sets the size of the framebuffer texture used to store the "
               "reflection in Bumpmapped water.");
CONFIG(int, BumpWaterReflection)
  .defaultValue(1)
  .headlessValue(0)
  .minimumValue(0)
  .maximumValue(2)
  .description("Determines the amount of objects reflected in Bumpmapped "
               "water.\n0:=off, 1:=fast (skip terrain), 2:=full");
CONFIG(int, BumpWaterRefraction)
  .defaultValue(1)
  .headlessValue(0)
  .minimumValue(0)
  .maximumValue(1)
  .description("Determines the method of refraction with Bumpmapped "
               "water.\n0:=off, 1:=screencopy, 2:=own rendering cycle "
               "(disabled)");
CONFIG(float, BumpWaterAnisotropy).defaultValue(0.0f).minimumValue(0.0f);
CONFIG(bool, BumpWaterUseDepthTexture).defaultValue(true).headlessValue(false);
CONFIG(int, BumpWaterDepthBits)
  .defaultValue(24)
  .minimumValue(16)
  .maximumValue(32);
CONFIG(bool, BumpWaterBlurReflection).defaultValue(false);
CONFIG(bool, BumpWaterShoreWaves)
  .defaultValue(true)
  .headlessValue(false)
  .safemodeValue(false)
  .description("Enables rendering of shorewaves.");
CONFIG(bool, BumpWaterEndlessOcean)
  .defaultValue(true)
  .description(
    "Sets whether Bumpmapped water will be drawn beyond the map edge.");
CONFIG(bool, BumpWaterDynamicWaves).defaultValue(true);
CONFIG(bool, BumpWaterUseUniforms).defaultValue(false);
CONFIG(bool, BumpWaterOcclusionQuery).defaultValue(false); // FIXME doesn't work
                                                           // as expected (it's
                                                           // slower than w/o),
                                                           // needs fixing

#define LOG_SECTION_BUMP_WATER "BumpWater"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_BUMP_WATER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_BUMP_WATER

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// HELPER FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void
GLSLDefineConst4f(string& str,
                  const string& name,
                  const float x,
                  const float y,
                  const float z,
                  const float w)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
GLSLDefineConstf4(string& str,
                  const string& name,
                  const float3& v,
                  const float& alpha)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
GLSLDefineConstf3(string& str, const string& name, const float3& v)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
GLSLDefineConstf2(string& str,
                  const string& name,
                  const float& x,
                  const float& y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
GLSLDefineConstf1(string& str, const string& name, const float& x)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static GLuint
LoadTexture(const string& filename,
            const float anisotropy = 0.0f,
            int* sizeX = NULL,
            int* sizeY = NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
DrawRadialDisc(CVertexArray* va)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// (DE-)CONSTRUCTOR
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CBumpWater::CBumpWater()
  : CEventClient("[CBumpWater]", 271923, false)
  , target(GL_TEXTURE_2D)
  , screenTextureX(globalRendering->viewSizeX)
  , screenTextureY(globalRendering->viewSizeY)
  , displayList(0)
  , refractTexture(0)
  , reflectTexture(0)
  , depthTexture(0)
  , waveRandTexture(0)
  , foamTexture(0)
  , normalTexture(0)
  , normalTexture2(0)
  , coastTexture(0)
  , coastUpdateTexture(0)
  , wasVisibleLastFrame(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CBumpWater::~CBumpWater()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::SetupUniforms(string& definitions)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::GetUniformLocations(const Shader::IProgramObject* shader)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  UPDATE
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
CBumpWater::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::UpdateWater(CGame* game)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  SHOREWAVES/COASTMAP
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CBumpWater::CoastAtlasRect::CoastAtlasRect(const SRectangle& rect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::UploadCoastline(const bool forceFull)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::UpdateCoastmap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  DYNAMIC WAVES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
CBumpWater::UpdateDynWaves(const bool initialize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  DRAW FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
CBumpWater::SetUniforms()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::DrawRefraction(CGame* game)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::DrawReflection(CGame* game)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CBumpWater::OcclusionQuery()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
