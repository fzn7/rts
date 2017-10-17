#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ExplosionListener.h"
#include "System/Util.h"

std::vector<IExplosionListener*> CExplosionCreator::explosionListeners;

IExplosionListener::~IExplosionListener()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CExplosionCreator::AddExplosionListener(IExplosionListener* listener)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CExplosionCreator::RemoveExplosionListener(IExplosionListener* listener)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CExplosionCreator::FireExplosionEvent(const CExplosionParams& event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
