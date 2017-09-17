#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cassert>
#include <limits>

#include "lib/streflop/streflop_cond.h"

#include "Node.hpp"
#include "NodeLayer.hpp"
#include "PathDefines.hpp"
#include "PathManager.hpp"

#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/GlobalConstants.h"

unsigned int QTPFS::QTNode::MIN_SIZE_X;
unsigned int QTPFS::QTNode::MIN_SIZE_Z;
unsigned int QTPFS::QTNode::MAX_DEPTH;

void
QTPFS::INode::SetPathCost(unsigned int type, float cost)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
QTPFS::INode::GetPathCost(unsigned int type) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
QTPFS::INode::GetDistance(const INode* n, unsigned int type) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
QTPFS::INode::GetNeighborRelation(const INode* ngb) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
QTPFS::INode::GetRectangleRelation(const SRectangle& r) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
QTPFS::INode::GetNeighborEdgeTransitionPoint(const INode* ngb,
                                             const float3& pos,
                                             float alpha) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// clip an OVERLAPPING rectangle against our boundaries
//
// NOTE:
//     the rectangle is only ASSUMED to not lie completely
//     inside <this> (in which case this function acts as
//     no-op), we do not explicitly test
//
//     both REL_RECT_EXTERIOR_NODE and REL_NODE_OVERLAPS_RECT
//     relations can produce zero- or negative-area rectangles
//     when clipping --> need to ensure to not leave move-cost
//     at its default value (0.0, which no node can logically
//     have)
//
SRectangle
QTPFS::INode::ClipRectangle(const SRectangle& r) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::QTNode::InitStatic()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

QTPFS::QTNode::QTNode(const QTNode* parent,
                      unsigned int nn,
                      unsigned int x1,
                      unsigned int z1,
                      unsigned int x2,
                      unsigned int z2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::QTNode::Delete()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::uint64_t
QTPFS::QTNode::GetMemFootPrint() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::uint64_t
QTPFS::QTNode::GetCheckSum() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::QTNode::IsLeaf() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::QTNode::CanSplit(bool forced) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::QTNode::Split(NodeLayer& nl, bool forced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::QTNode::Merge(NodeLayer& nl)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef QTPFS_SLOW_ACCURATE_TESSELATION
// re-tesselate a tree from the deepest node <n> that contains
// rectangle <r> (<n> will be found from any higher node passed
// in)
//
// this code can be VERY slow in the worst-case (eg. when <r>
// overlaps all four children of the ROOT node), but minimizes
// the overall number of nodes in the tree at any given time
void
QTPFS::QTNode::PreTesselate(NodeLayer& nl, const SRectangle& r, SRectangle& ur)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#else

void
QTPFS::QTNode::PreTesselate(NodeLayer& nl, const SRectangle& r, SRectangle& ur)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif

void
QTPFS::QTNode::Tesselate(NodeLayer& nl, const SRectangle& r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
QTPFS::QTNode::UpdateMoveCost(const NodeLayer& nl,
                              const SRectangle& r,
                              unsigned int& numNewBinSquares,
                              unsigned int& numDifBinSquares,
                              unsigned int& numClosedSquares,
                              bool& wantSplit,
                              bool& needSplit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// get the maximum number of neighbors this node
// can have, based on its position / size and the
// assumption that all neighbors are 1x1
//
// NOTE: this intentionally does not count corners
unsigned int
QTPFS::QTNode::GetMaxNumNeighbors() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
QTPFS::QTNode::Serialize(std::fstream& fStream,
                         NodeLayer& nodeLayer,
                         unsigned int* streamSize,
                         bool readMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
QTPFS::QTNode::GetNeighbors(const std::vector<INode*>& nodes,
                            std::vector<INode*>& ngbs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<QTPFS::INode*>&
QTPFS::QTNode::GetNeighbors(const std::vector<INode*>& nodes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// this is *either* called from ::GetNeighbors when the conservative
// update-scheme is enabled, *or* from PM::ExecQueuedNodeLayerUpdates
// (never both)
bool
QTPFS::QTNode::UpdateNeighborCache(const std::vector<INode*>& nodes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
