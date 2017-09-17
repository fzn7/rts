/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ModelRenderContainer.h"

#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/3DOTextureHandler.h"
#include "Sim/Features/Feature.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Units/Unit.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#define LOG_SECTION_WORLD_OBJECT_MODEL_RENDERER "ModelRenderContainer"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_WORLD_OBJECT_MODEL_RENDERER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_WORLD_OBJECT_MODEL_RENDERER


IModelRenderContainer* IModelRenderContainer::GetInstance(int modelType)
{
    //stub method
}

IModelRenderContainer::~IModelRenderContainer()
{
    //stub method
}



void IModelRenderContainer::AddUnit(const CUnit* u)
{
    //stub method
}

void IModelRenderContainer::DelUnit(const CUnit* u)
{
    //stub method
}


void IModelRenderContainer::AddFeature(const CFeature* f)
{
    //stub method
}

void IModelRenderContainer::DelFeature(const CFeature* f)
{
    //stub method
}


void IModelRenderContainer::AddProjectile(const CProjectile* p)
{
    //stub method
}

void IModelRenderContainer::DelProjectile(const CProjectile* p)
{
    //stub method
}

