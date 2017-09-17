#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ProjectileDrawer.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Game/LoadScreen.h"
#include "Lua/LuaParser.h"
#include "Map/MapInfo.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/Particles/Classes/FlyingPiece.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GroundFlash.h"
#include "Rendering/Models/ModelRenderContainer.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/PieceProjectile.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Weapons/WeaponDef.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include <array>

CProjectileDrawer* projectileDrawer = NULL;

CProjectileDrawer::CProjectileDrawer()
  : CEventClient("[CProjectileDrawer]", 123456, false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CProjectileDrawer::~CProjectileDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::ParseAtlasTextures(const bool blockTextures,
                                      const LuaTable& textureTable,
                                      std::set<std::string>& blockedTextures,
                                      CTextureAtlas* textureAtlas)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::LoadWeaponTextures()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawProjectiles(int modelType,
                                   bool drawReflection,
                                   bool drawRefraction)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawProjectilesSet(
  const std::vector<CProjectile*>& projectiles,
  bool drawReflection,
  bool drawRefraction)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CProjectileDrawer::CanDrawProjectile(const CProjectile* pro,
                                     const CSolidObject* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawProjectileNow(CProjectile* pro,
                                     bool drawReflection,
                                     bool drawRefraction)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawProjectilesShadow(int modelType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawProjectilesSetShadow(
  const std::vector<CProjectile*>& projectiles)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawProjectileShadow(CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawProjectilesMiniMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawFlyingPieces(int modelType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::Draw(bool drawReflection, bool drawRefraction)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawShadowPass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CProjectileDrawer::DrawProjectileModel(const CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::DrawGroundFlashes()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::UpdateTextures()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::UpdatePerlin()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::GenerateNoiseTex(unsigned int tex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::RenderProjectileCreated(const CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CProjectileDrawer::RenderProjectileDestroyed(const CProjectile* const p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
