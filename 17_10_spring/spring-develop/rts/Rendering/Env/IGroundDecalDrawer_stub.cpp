#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IGroundDecalDrawer.h"
#include "Rendering/Env/Decals/DecalsDrawerGL4.h"
#include "Rendering/Env/Decals/GroundDecalHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"

CONFIG(int, GroundDecals)
  .defaultValue(3)
  .headlessValue(0)
  .description("Controls whether ground decals underneath buildings and ground "
               "scars from explosions will be rendered. Values >1 define how "
               "long such decals will stay.");

static NullGroundDecalDrawer nullDecalDrawer;
IGroundDecalDrawer* IGroundDecalDrawer::singleton = &nullDecalDrawer;
int IGroundDecalDrawer::decalLevel = 0;

static IGroundDecalDrawer*
GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IGroundDecalDrawer::Init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IGroundDecalDrawer::FreeInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IGroundDecalDrawer::SetDrawDecals(bool v)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
