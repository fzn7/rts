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
CR_REG_METADATA(CRectangleOptimizer, (
	CR_MEMBER(maxAreaPerRect),
	CR_MEMBER(rectangles),
	CR_MEMBER(needsUpdate)
))

unsigned CRectangleOptimizer::statsTotalSize = 0;
unsigned CRectangleOptimizer::statsOptSize   = 0;

CRectangleOptimizer::CRectangleOptimizer()
	: maxAreaPerRect(500 * 500) // FIXME auto adjust this in HeightMapUpdate!
	, needsUpdate(false)
{
    //stub method
}


CRectangleOptimizer::~CRectangleOptimizer()
{
    //stub method
}


unsigned CRectangleOptimizer::GetTotalArea() const
{
    //stub method
}


void CRectangleOptimizer::Optimize()
{
    //stub method
}

void CRectangleOptimizer::StageMerge()
{
    //stub method
}


void CRectangleOptimizer::StageOverlap()
{
    //stub method
}


void CRectangleOptimizer::StageSplitTooLarge()
{
    //stub method
}


inline std::bitset<4> CRectangleOptimizer::GetEdgesInRect(const SRectangle& rect1, const SRectangle& rect2)
{
    //stub method
}


inline std::bitset<4> CRectangleOptimizer::GetSharedEdges(const SRectangle& rect1, const SRectangle& rect2)
{
    //stub method
}


inline bool CRectangleOptimizer::AreMergable(const SRectangle& rect1, const SRectangle& rect2)
{
    //stub method
}


bool CRectangleOptimizer::HandleMerge(SRectangle& rect1, SRectangle& rect2)
{
    //stub method
}


int CRectangleOptimizer::HandleOverlapping(SRectangle* rect1, SRectangle* rect2)
{
    //stub method
}
