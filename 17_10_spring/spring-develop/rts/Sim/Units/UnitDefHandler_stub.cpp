/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <locale>
#include <stdio.h>

#include "Lua/LuaParser.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Misc/SideParser.h"
#include "Sim/Misc/Team.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISound.h"
#include "System/Util.h"
#include "UnitDef.h"
#include "UnitDefHandler.h"
#include "UnitDefImage.h"

CUnitDefHandler* unitDefHandler = NULL;

#if defined(_MSC_VER) && (_MSC_VER < 1800)
bool
isblank(int c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif

CUnitDefHandler::CUnitDefHandler(LuaParser* defsParser)
  : noCost(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CUnitDefHandler::~CUnitDefHandler() {}

int
CUnitDefHandler::PushNewUnitDef(const std::string& unitName,
                                const LuaTable& udTable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::CleanBuildOptions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::ProcessDecoys()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::FindStartUnits()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::UnitDefLoadSounds(UnitDef* ud, const LuaTable& udTable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::LoadSounds(const LuaTable& soundsTable,
                            GuiSoundSet& gsound,
                            const string& soundName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::LoadSound(GuiSoundSet& gsound,
                           const string& fileName,
                           const float volume)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const UnitDef*
CUnitDefHandler::GetUnitDefByName(std::string name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const UnitDef*
CUnitDefHandler::GetUnitDefByID(int defid)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static bool
LoadBuildPic(const string& filename, CBitmap& bitmap)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CUnitDefHandler::GetUnitDefImage(const UnitDef* unitDef)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::SetUnitDefImage(const UnitDef* unitDef,
                                 const std::string& texName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::SetUnitDefImage(const UnitDef* unitDef,
                                 unsigned int texID,
                                 int xsize,
                                 int ysize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CUnitDefHandler::ToggleNoCost()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::AssignTechLevels()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CUnitDefHandler::AssignTechLevel(UnitDef& ud, int level)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
