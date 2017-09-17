/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LegacyInfoTextureHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/UI/GuiHandler.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/HeightLinePalette.h"
#include "Map/MapInfo.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"
#include "Rendering/IPathDrawer.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "System/TimeProfiler.h"
#include "System/Log/ILog.h"
#include "System/Config/ConfigHandler.h"


CONFIG(bool, HighResLos).defaultValue(false).description("Controls whether LOS (\"L view\") edges are rendered in high resolution. Resource heavy!");
CONFIG(int, ExtraTextureUpdateRate).defaultValue(45).description("EXTREME CPU-HEAVY ON MEDIUM/BIG MAPS! DON'T CHANGE DEFAULT!");


static CLegacyInfoTextureHandler::BaseGroundDrawMode NameToDrawMode(const std::string& name)
{
    //stub method
}


static std::string DrawModeToName(const CLegacyInfoTextureHandler::BaseGroundDrawMode mode)
{
    //stub method
}




CLegacyInfoTextureHandler::CLegacyInfoTextureHandler()
: drawMode(drawNormal)
, updateTextureState(0)
, extraTextureUpdateRate(0)
, returnToLOS(false)
, highResLosTex(false)
, highResInfoTexWanted(false)
{
    //stub method
}


CLegacyInfoTextureHandler::~CLegacyInfoTextureHandler()
{
    //stub method
}


bool CLegacyInfoTextureHandler::IsEnabled() const
{
    //stub method
}


void CLegacyInfoTextureHandler::DisableCurrentMode()
{
    //stub method
}


void CLegacyInfoTextureHandler::SetMode(const std::string& name)
{
    //stub method
}


void CLegacyInfoTextureHandler::ToggleMode(const std::string& name)
{
    //stub method
}


const std::string& CLegacyInfoTextureHandler::GetMode() const
{
    //stub method
}


GLuint CLegacyInfoTextureHandler::GetCurrentInfoTexture() const
{
    //stub method
}


int2 CLegacyInfoTextureHandler::GetCurrentInfoTextureSize() const
{
    //stub method
}


const CInfoTexture* CLegacyInfoTextureHandler::GetInfoTextureConst(const std::string& name) const
{
    //stub method
}

CInfoTexture* CLegacyInfoTextureHandler::GetInfoTexture(const std::string& name)
{
    //stub method
}


/********************************************************************/
/********************************************************************/

static inline int InterpolateLos(const unsigned short* p, int2 size, int mip, int factor, int2 pos)
{
    //stub method
}



void CLegacyInfoTextureHandler::Update()
{
    //stub method
}


// Gradually calculate the extra texture based on updateTextureState:
//   updateTextureState < extraTextureUpdateRate:   Calculate the texture color values and copy them into buffer
//   updateTextureState = extraTextureUpdateRate:   Copy the buffer into a texture
// NOTE:
//   when switching TO an info-texture drawing mode
//   the texture is calculated in its entirety, not
//   over multiple frames
bool CLegacyInfoTextureHandler::UpdateExtraTexture(BaseGroundDrawMode texDrawMode)
{
    //stub method
}
