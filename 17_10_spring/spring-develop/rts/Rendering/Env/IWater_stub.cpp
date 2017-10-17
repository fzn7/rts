#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IWater.h"
#include "AdvWater.h"
#include "BasicWater.h"
#include "BumpWater.h"
#include "DynWater.h"
#include "Game/Game.h"
#include "Game/GameHelper.h"
#include "ISky.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/ReadMap.h"
#include "RefractWater.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/FeatureDrawer.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Projectiles/ExplosionListener.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"

CONFIG(int, Water)
  .defaultValue(IWater::WATER_RENDERER_REFLECTIVE)
  .safemodeValue(IWater::WATER_RENDERER_BASIC)
  .headlessValue(0)
  .minimumValue(0)
  .maximumValue(IWater::NUM_WATER_RENDERERS - 1)
  .description("Defines the type of water rendering. Can be set in game. "
               "Options are: 0 = Basic water, 1 = Reflective water, 2 = "
               "Reflective and Refractive water, 3 = Dynamic water, 4 = "
               "Bumpmapped water");

IWater* water = nullptr;
static std::vector<int> waterModes;

IWater::IWater()
  : drawReflection(false)
  , drawRefraction(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IWater::PushWaterMode(int nxtRendererMode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IWater::ApplyPushedChanges(CGame* game)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

IWater*
IWater::GetWater(IWater* curRenderer, int nxtRendererMode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IWater::ExplosionOccurred(const CExplosionParams& event)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IWater::SetModelClippingPlane(const double* planeEq)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IWater::DrawReflections(const double* clipPlaneEqs,
                        bool drawGround,
                        bool drawSky)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
IWater::DrawRefractions(const double* clipPlaneEqs,
                        bool drawGround,
                        bool drawSky)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
