#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GroundFlash.h"
#include "Game/Camera.h"
#include "Map/Ground.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GroundFlashInfo.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ExpGenSpawnableMemberInfo.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CGroundFlash, CExpGenSpawnable, )
CR_REG_METADATA(CGroundFlash,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(size),
                 CR_MEMBER(depthTest),
                 CR_MEMBER(depthMask),
                 CR_MEMBER_ENDFLAG(CM_Config)))

CR_BIND_DERIVED(CStandardGroundFlash, CGroundFlash, )
CR_REG_METADATA(CStandardGroundFlash,
                (CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(flashSize),
                 CR_MEMBER(flashAlpha),
                 CR_MEMBER(circleGrowth),
                 CR_MEMBER(circleAlpha),
                 CR_MEMBER(color),
                 CR_MEMBER_ENDFLAG(CM_Config),

                 CR_MEMBER(side1),
                 CR_MEMBER(side2),
                 CR_MEMBER(circleSize),
                 CR_MEMBER(flashAge),
                 CR_MEMBER(flashAgeSpeed),
                 CR_MEMBER(circleAlphaDec),
                 CR_MEMBER(ttl)))

CR_BIND_DERIVED(CSeismicGroundFlash,
                CGroundFlash,
                (ZeroVector, 1, 0, 1, 1, 1, ZeroVector))
CR_REG_METADATA(CSeismicGroundFlash,
                (CR_MEMBER(side1),
                 CR_MEMBER(side2),
                 CR_MEMBER(texture),
                 CR_MEMBER(sizeGrowth),
                 CR_MEMBER(alpha),
                 CR_MEMBER(fade),
                 CR_MEMBER(ttl),
                 CR_MEMBER(color)))

CR_BIND_DERIVED(CSimpleGroundFlash, CGroundFlash, )
CR_REG_METADATA(CSimpleGroundFlash,
                (CR_MEMBER(side1),
                 CR_MEMBER(side2),
                 CR_MEMBER(age),
                 CR_MEMBER(agerate),
                 CR_MEMBER_BEGINFLAG(CM_Config),
                 CR_MEMBER(sizeGrowth),
                 CR_MEMBER(ttl),
                 CR_MEMBER(colorMap),
                 CR_MEMBER(texture),
                 CR_MEMBER_ENDFLAG(CM_Config)))

CVertexArray* CGroundFlash::va = nullptr;

// CREG-only
CGroundFlash::CGroundFlash()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGroundFlash::CGroundFlash(const float3& _pos)
  : CExpGenSpawnable()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CGroundFlash::CalcNormal(const float3 midPos,
                         const float3 camDir,
                         const float quadSize) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundFlash::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CStandardGroundFlash::CStandardGroundFlash()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CStandardGroundFlash::CStandardGroundFlash(const float3& _pos,
                                           const GroundFlashInfo& info)
  : CGroundFlash(_pos)
  , ttl(info.ttl)
  , flashSize(info.flashSize)
  , circleSize(info.circleGrowth)
  , circleGrowth(info.circleGrowth)
  , circleAlpha(info.circleAlpha)
  , flashAlpha(info.flashAlpha)
  , flashAge(0.0f)
  , flashAgeSpeed(ttl ? 1.0f / ttl : 0.0f)
  , circleAlphaDec(ttl ? circleAlpha / ttl : 0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CStandardGroundFlash::CStandardGroundFlash(const float3& _pos,
                                           float _circleAlpha,
                                           float _flashAlpha,
                                           float _flashSize,
                                           float _circleGrowth,
                                           float _ttl,
                                           const float3& _color)
  : CGroundFlash(_pos)
  , ttl((int)_ttl)
  , flashSize(_flashSize)
  , circleSize(_circleGrowth)
  , circleGrowth(_circleGrowth)
  , circleAlpha(_circleAlpha)
  , flashAlpha(_flashAlpha)
  , flashAge(0)
  , flashAgeSpeed(ttl ? 1.0f / ttl : 0)
  , circleAlphaDec(ttl ? circleAlpha / ttl : 0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CStandardGroundFlash::InitCommon(const float3& _pos, const float3& _color)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CStandardGroundFlash::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CStandardGroundFlash::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CStandardGroundFlash::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSimpleGroundFlash::CSimpleGroundFlash()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSimpleGroundFlash::Init(const CUnit* owner, const float3& offset)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSimpleGroundFlash::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSimpleGroundFlash::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSimpleGroundFlash::GetMemberInfo(SExpGenSpawnableMemberInfo& memberInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSeismicGroundFlash::CSeismicGroundFlash(const float3& _pos,
                                         int _ttl,
                                         int _fade,
                                         float _size,
                                         float _sizeGrowth,
                                         float _alpha,
                                         const float3& _color)
  : CGroundFlash(_pos)
  , texture(projectileDrawer->seismictex)
  , sizeGrowth(_sizeGrowth)
  , alpha(_alpha)
  , fade(_fade)
  , ttl(_ttl)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSeismicGroundFlash::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSeismicGroundFlash::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
