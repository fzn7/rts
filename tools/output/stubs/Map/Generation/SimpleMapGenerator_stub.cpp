#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SimpleMapGenerator.h"

CSimpleMapGenerator::CSimpleMapGenerator(const CGameSetup* setup)
  : CMapGenerator(setup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSimpleMapGenerator::~CSimpleMapGenerator() {}

void
CSimpleMapGenerator::GenerateInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSimpleMapGenerator::GenerateMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
