/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/cstdint.hpp>
#include <cassert>
#include <iostream>
#include <stdexcept>

#include "ExpGenSpawnable.h"
#include "ExpGenSpawnableMemberInfo.h"
#include "ExpGenSpawner.h" //!!
#include "ExplosionGenerator.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Lua/LuaParser.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/Classes/BubbleProjectile.h"
#include "Rendering/Env/Particles/Classes/DirtProjectile.h"
#include "Rendering/Env/Particles/Classes/ExploSpikeProjectile.h"
#include "Rendering/Env/Particles/Classes/HeatCloudProjectile.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile2.h"
#include "Rendering/Env/Particles/Classes/SpherePartProjectile.h"
#include "Rendering/Env/Particles/Classes/WakeProjectile.h"
#include "Rendering/Env/Particles/Classes/WreckProjectile.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GroundFlash.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ProjectileHandler.h"

#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystemInitializer.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Log/DefaultFilter.h"
#include "System/Log/ILog.h"
#include "System/Sync/HsiehHash.h"
#include "System/Util.h"
#include "System/creg/STL_Map.h"

CR_BIND_INTERFACE(IExplosionGenerator)
CR_REG_METADATA(IExplosionGenerator, (CR_MEMBER(generatorID)))

CR_BIND_DERIVED(CStdExplosionGenerator, IExplosionGenerator, )
CR_REG_METADATA(CStdExplosionGenerator, )

CR_BIND(CCustomExplosionGenerator::ProjectileSpawnInfo, )
CR_REG_METADATA_SUB(
  CCustomExplosionGenerator,
  ProjectileSpawnInfo,
  (CR_MEMBER(spawnableID), CR_MEMBER(code), CR_MEMBER(count), CR_MEMBER(flags)))

CR_BIND(GroundFlashInfo, )
CR_REG_METADATA(GroundFlashInfo,
                (CR_MEMBER(flashSize),
                 CR_MEMBER(flashAlpha),
                 CR_MEMBER(circleGrowth),
                 CR_MEMBER(circleAlpha),
                 CR_MEMBER(ttl),
                 CR_MEMBER(flags),
                 CR_MEMBER(color)))

CR_BIND(CCustomExplosionGenerator::ExpGenParams, )
CR_REG_METADATA_SUB(CCustomExplosionGenerator,
                    ExpGenParams,
                    (CR_MEMBER(projectiles),
                     CR_MEMBER(groundFlash),
                     CR_MEMBER(useDefaultExplosions)))

CR_BIND_DERIVED(CCustomExplosionGenerator, CStdExplosionGenerator, )
CR_REG_METADATA(CCustomExplosionGenerator, (CR_MEMBER(expGenParams)))

CExplosionGeneratorHandler* explGenHandler = NULL;

unsigned int
CCustomExplosionGenerator::GetFlagsFromTable(const LuaTable& table)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CCustomExplosionGenerator::GetFlagsFromHeight(float height, float groundHeight)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ClassAliasList::Load(const LuaTable& aliasTable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
ClassAliasList::ResolveAlias(const string& name) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

string
ClassAliasList::FindAlias(const string& className) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CExplosionGeneratorHandler::CExplosionGeneratorHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CExplosionGeneratorHandler::~CExplosionGeneratorHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CExplosionGeneratorHandler::ParseExplosionTables()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CExplosionGeneratorHandler::ReloadGenerators(const std::string& tag)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CExplosionGeneratorHandler::LoadGeneratorID(const std::string& tag)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// creates either a standard or a custom explosion generator instance
// NOTE:
//   can be called recursively for custom instances (LoadGenerator ->
//   Load -> ParseExplosionCode -> LoadGenerator -> ...), generators
//   must NOT be overwritten
IExplosionGenerator*
CExplosionGeneratorHandler::LoadGenerator(const string& tag)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

IExplosionGenerator*
CExplosionGeneratorHandler::GetGenerator(unsigned int expGenID)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CExplosionGeneratorHandler::GenExplosion(unsigned int expGenID,
                                         const float3& pos,
                                         const float3& dir,
                                         float damage,
                                         float radius,
                                         float gfxMod,
                                         CUnit* owner,
                                         CUnit* hit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CStdExplosionGenerator::Explosion(const float3& pos,
                                  const float3& dir,
                                  float damage,
                                  float radius,
                                  float gfxMod,
                                  CUnit* owner,
                                  CUnit* hit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCustomExplosionGenerator::ExecuteExplosionCode(const char* code,
                                                float damage,
                                                char* instance,
                                                int spawnIndex,
                                                const float3& dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCustomExplosionGenerator::ParseExplosionCode(
  CCustomExplosionGenerator::ProjectileSpawnInfo* psi,
  const string& script,
  SExpGenSpawnableMemberInfo& memberInfo,
  string& code)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCustomExplosionGenerator::Load(CExplosionGeneratorHandler* handler,
                                const string& tag)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCustomExplosionGenerator::Reload(CExplosionGeneratorHandler* handler,
                                  const std::string& tag)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCustomExplosionGenerator::Explosion(const float3& pos,
                                     const float3& dir,
                                     float damage,
                                     float radius,
                                     float gfxMod,
                                     CUnit* owner,
                                     CUnit* hit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CCustomExplosionGenerator::OutputProjectileClassInfo()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
