#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "RectangleOptimizer.h"
#ifdef RO_USE_DEQUE_CONTAINER
#include "System/creg/STL_Deque.h"
#else
#include "System/creg/STL_List.h"
#endif
#include "System/Log/ILog.h"

#include <cassert>

CR_BIND(CRectangleOptimizer, )
CR_REG_METADATA(CRectangleOptimizer,
                (CR_MEMBER(maxAreaPerRect),
                 CR_MEMBER(rectangles),
                 CR_MEMBER(needsUpdate)))

unsigned CRectangleOptimizer::statsTotalSize = 0;
unsigned CRectangleOptimizer::statsOptSize = 0;

CRectangleOptimizer::CRectangleOptimizer()
  : maxAreaPerRect(500 * 500) // FIXME auto adjust this in HeightMapUpdate!
  , needsUpdate(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CRectangleOptimizer::~CRectangleOptimizer()
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
	
}

unsigned
CRectangleOptimizer::GetTotalArea() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CRectangleOptimizer::Optimize()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CRectangleOptimizer::StageMerge()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CRectangleOptimizer::StageOverlap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CRectangleOptimizer::StageSplitTooLarge()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline std::bitset<4>
CRectangleOptimizer::GetEdgesInRect(const SRectangle& rect1,
                                    const SRectangle& rect2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline std::bitset<4>
CRectangleOptimizer::GetSharedEdges(const SRectangle& rect1,
                                    const SRectangle& rect2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline bool
CRectangleOptimizer::AreMergable(const SRectangle& rect1,
                                 const SRectangle& rect2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CRectangleOptimizer::HandleMerge(SRectangle& rect1, SRectangle& rect2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CRectangleOptimizer::HandleOverlapping(SRectangle* rect1, SRectangle* rect2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
