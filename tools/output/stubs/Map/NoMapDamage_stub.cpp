/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MapDamage.h"
#include "NoMapDamage.h"

/* Do no deformation. (Maybe I should've left all this in the header?) */

CNoMapDamage::CNoMapDamage()
{
    //stub method
}

CNoMapDamage::~CNoMapDamage()
{
    //stub method
}

void CNoMapDamage::Explosion(const float3& pos, float strength, float radius)
{
    //stub method
}

void CNoMapDamage::RecalcArea(int x1, int x2, int y1, int y2)
{
    //stub method
}

void CNoMapDamage::Update()
{
    //stub method
}
