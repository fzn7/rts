/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "InMapDrawView.h"
#include "Rendering/Colors.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"

#include "Game/Camera.h"
#include "Game/InMapDrawModel.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/TeamHandler.h"

CInMapDrawView* inMapDrawerView = NULL;


/**
 * how far on the way between x and y [0.0f, 1.0f]
 */
static inline unsigned char smoothStep(int x, int y, int a) {
	return (unsigned char)((x * (1.0f - a)) + (y * a));
}

CInMapDrawView::CInMapDrawView()
{
    //stub method
}


CInMapDrawView::~CInMapDrawView()
{
    //stub method
}


struct InMapDraw_QuadDrawer: public CReadMap::IQuadDrawer
{
    //stub method
}

void InMapDraw_QuadDrawer::DrawLine(const CInMapDrawModel::MapLine* line) const
{
    //stub method
}

void InMapDraw_QuadDrawer::DrawQuad(int x, int y)
{
    //stub method
}



void CInMapDrawView::Draw()
{
    //stub method
}
