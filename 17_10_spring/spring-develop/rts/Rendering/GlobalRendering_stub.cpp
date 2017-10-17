#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GlobalRendering.h"

#include "Rendering/GL/FBO.h"
#include "Rendering/GL/myGL.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/creg/creg_cond.h"
#include "System/type2.h"

#include <SDL_video.h>
#include <string>

CONFIG(bool, CompressTextures)
  .defaultValue(false)
  .safemodeValue(true)
  .description("Runtime compress most textures to save VideoRAM."); // in
                                                                    // safemode
                                                                    // enabled,
                                                                    // cause it
                                                                    // ways more
                                                                    // likely
                                                                    // the gpu
                                                                    // runs out
                                                                    // of memory
                                                                    // than this
                                                                    // extension
                                                                    // cause
                                                                    // crashes!
CONFIG(int, ForceShaders).defaultValue(-1).minimumValue(-1).maximumValue(1);
CONFIG(int, AtiHacks)
  .defaultValue(-1)
  .headlessValue(0)
  .minimumValue(-1)
  .maximumValue(1)
  .description("Enables graphics drivers workarounds for users with ATI video "
               "cards.\n -1:=runtime detect, 0:=off, 1:=on");
CONFIG(bool, DualScreenMode)
  .defaultValue(false)
  .description("Sets whether to split the screen in half, with one half for "
               "minimap and one for main screen. Right side is for minimap "
               "unless DualScreenMiniMapOnLeft is set.");
CONFIG(bool, DualScreenMiniMapOnLeft)
  .defaultValue(false)
  .description("When set, will make the left half of the screen the minimap "
               "when DualScreenMode is set.");
CONFIG(bool, TeamNanoSpray).defaultValue(true).headlessValue(false);

/**
 * @brief global rendering
 *
 * Global instance of CGlobalRendering
 */
CGlobalRendering* globalRendering;

const float CGlobalRendering::MAX_VIEW_RANGE = 8000.0f;
const float CGlobalRendering::NEAR_PLANE = 2.8f;
const float CGlobalRendering::SMF_INTENSITY_MULT = 210.0f / 255.0f;
const int CGlobalRendering::minWinSizeX = 400;
const int CGlobalRendering::minWinSizeY = 300;

CR_BIND(CGlobalRendering, )

CR_REG_METADATA(CGlobalRendering,
                (CR_MEMBER(teamNanospray),
                 CR_MEMBER(drawSky),
                 CR_MEMBER(drawWater),
                 CR_MEMBER(drawGround),
                 CR_MEMBER(drawMapMarks),
                 CR_MEMBER(drawFog),
                 CR_MEMBER(drawdebug),
                 CR_MEMBER(drawdebugtraceray),
                 CR_MEMBER(timeOffset),
                 CR_MEMBER(lastFrameTime),
                 CR_MEMBER(lastFrameStart),
                 CR_MEMBER(weightedSpeedFactor),
                 CR_MEMBER(drawFrame),
                 CR_MEMBER(FPS),

                 CR_IGNORED(winState),
                 CR_IGNORED(screenSizeX),
                 CR_IGNORED(screenSizeY),
                 CR_IGNORED(winPosX),
                 CR_IGNORED(winPosY),
                 CR_IGNORED(winSizeX),
                 CR_IGNORED(winSizeY),
                 CR_IGNORED(viewPosX),
                 CR_IGNORED(viewPosY),
                 CR_IGNORED(viewSizeX),
                 CR_IGNORED(viewSizeY),
                 CR_IGNORED(pixelX),
                 CR_IGNORED(pixelY),
                 CR_IGNORED(aspectRatio),
                 CR_IGNORED(zNear),
                 CR_IGNORED(viewRange),
                 CR_IGNORED(FSAA),
                 CR_IGNORED(maxTextureSize),
                 CR_IGNORED(active),
                 CR_IGNORED(compressTextures),
                 CR_IGNORED(haveATI),
                 CR_IGNORED(haveMesa),
                 CR_IGNORED(haveIntel),
                 CR_IGNORED(haveNvidia),
                 CR_IGNORED(atiHacks),
                 CR_IGNORED(supportNPOTs),
                 CR_IGNORED(support24bitDepthBuffers),
                 CR_IGNORED(supportRestartPrimitive),
                 CR_IGNORED(haveARB),
                 CR_IGNORED(haveGLSL),
                 CR_IGNORED(maxSmoothPointSize),
                 CR_IGNORED(glslMaxVaryings),
                 CR_IGNORED(glslMaxAttributes),
                 CR_IGNORED(glslMaxDrawBuffers),
                 CR_IGNORED(glslMaxRecommendedIndices),
                 CR_IGNORED(glslMaxRecommendedVertices),
                 CR_IGNORED(glslMaxUniformBufferBindings),
                 CR_IGNORED(glslMaxUniformBufferSize),
                 CR_IGNORED(dualScreenMode),
                 CR_IGNORED(dualScreenMiniMapOnLeft),
                 CR_IGNORED(fullScreen),
                 CR_IGNORED(window)))

CGlobalRendering::CGlobalRendering()
  : timeOffset(0.0f)
  , lastFrameTime(0.0f)
  , lastFrameStart(spring_notime)
  , weightedSpeedFactor(0.0f)
  , drawFrame(1)
  , FPS(GAME_SPEED)

  , winState(WINSTATE_DEFAULT)
  , screenSizeX(1)
  , screenSizeY(1)

  // window geometry
  , winPosX(0)
  , winPosY(0)
  , winSizeX(1)
  , winSizeY(1)

  // viewport geometry
  , viewPosX(0)
  , viewPosY(0)
  , viewSizeX(1)
  , viewSizeY(1)

  // pixel geometry
  , pixelX(0.01f)
  , pixelY(0.01f)

  , aspectRatio(1.0f)

  , zNear(NEAR_PLANE)
  , viewRange(MAX_VIEW_RANGE)
  , FSAA(0)

  , maxTextureSize(2048)

  , drawSky(true)
  , drawWater(true)
  , drawGround(true)
  , drawMapMarks(true)
  , drawFog(true)
  , drawdebug(false)
  , drawdebugtraceray(false)

  , teamNanospray(true)
  , active(true)
  , compressTextures(false)
  , haveATI(false)
  , haveMesa(false)
  , haveIntel(false)
  , haveNvidia(false)
  , atiHacks(false)
  , supportNPOTs(false)
  , support24bitDepthBuffers(false)
  , supportRestartPrimitive(false)
  , haveARB(false)
  , haveGLSL(false)
  , maxSmoothPointSize(1.0f)

  , glslMaxVaryings(0)
  , glslMaxAttributes(0)
  , glslMaxDrawBuffers(0)
  , glslMaxRecommendedIndices(0)
  , glslMaxRecommendedVertices(0)
  , glslMaxUniformBufferBindings(0)
  , glslMaxUniformBufferSize(0)

  , dualScreenMode(false)
  , dualScreenMiniMapOnLeft(false)
  , fullScreen(true)

  , window(nullptr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGlobalRendering::SetFullScreen(bool configFullScreen,
                                bool cmdLineWindowed,
                                bool cmdLineFullScreen)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int2
CGlobalRendering::GetWantedViewSize(const bool fullscreen)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGlobalRendering::SetDualScreenParams()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGlobalRendering::UpdateViewPortGeometry()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGlobalRendering::UpdatePixelGeometry()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
