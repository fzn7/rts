#include <iostream>
#include <limits>

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"

// FIXME
#define private public
#define protected public
#include "Sim/Path/QTPFS/Node.hpp"
#include "Sim/Path/QTPFS/NodeLayer.hpp"
#include "Sim/Path/QTPFS/Path.hpp"
#include "Sim/Path/QTPFS/PathCache.hpp"
#include "Sim/Path/QTPFS/PathManager.hpp"
#undef protected
#undef private

#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Map/InfoTexture/Legacy/LegacyInfoTextureHandler.h"
#include "Rendering/QTPFSPathDrawer.h"
#include "System/Util.h"

QTPFSPathDrawer::QTPFSPathDrawer()
  : IPathDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawAll() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawNodeTree(const MoveDef* md) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawNodeTreeRec(const QTPFS::QTNode* nt,
                                 const MoveDef* md,
                                 CVertexArray* va) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::GetVisibleNodes(const QTPFS::QTNode* nt,
                                 std::list<const QTPFS::QTNode*>& nodes) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawPaths(const MoveDef* md) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawPath(const QTPFS::IPath* path, CVertexArray* va) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawSearchExecution(
  unsigned int pathType,
  const QTPFS::PathSearchTrace::Execution* searchExec) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawSearchIteration(unsigned int pathType,
                                     const std::list<unsigned int>& nodeIndices,
                                     CVertexArray* va) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawNode(const QTPFS::QTNode* node,
                          const MoveDef* md,
                          CVertexArray* va,
                          bool fillQuad,
                          bool showCost,
                          bool batchDraw) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::DrawNodeLink(const QTPFS::QTNode* pushedNode,
                              const QTPFS::QTNode* poppedNode,
                              CVertexArray* va) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
QTPFSPathDrawer::UpdateExtraTexture(int extraTex,
                                    int starty,
                                    int endy,
                                    int offset,
                                    unsigned char* texMem) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
