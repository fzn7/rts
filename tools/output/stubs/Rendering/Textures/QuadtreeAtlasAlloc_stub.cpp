/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "QuadtreeAtlasAlloc.h"
#include <string.h> // memset
#include "System/Exceptions.h"
#include "System/bitops.h"
#include "System/Log/ILog.h"

#include <algorithm>
#include <vector>

static int NODE_MIN_SIZE = 8;


struct QuadTreeNode {
	QuadTreeNode() {
		used = false;
		posx = posy = size = 0;
		memset(children, 0, 4 * sizeof(QuadTreeNode*));
	}
	~QuadTreeNode() {
		for (int i = 0; i < 4; ++i) {
			if (children[i]) {
				delete children[i];
				children[i] = NULL;
			}
		}
	}

	QuadTreeNode(QuadTreeNode* node, int i) {
		// i ... 0:=topleft, 1:=topright, 2:=btmleft, 3:=btmright
		used = false;
		size = node->size >> 1;
		posx = node->posx + ((i & 1)     ) * size;
		posy = node->posy + ((i & 2) >> 1) * size;
		memset(children, 0, 4 * sizeof(QuadTreeNode*));
	}

	QuadTreeNode* FindPosInQuadTree(int xsize, int ysize);

	int GetMinSize() {
		int minsize = size;
		for (int i = 0; i < 4; ++i) {
			if (children[i]) {
				minsize = std::min(minsize, children[i]->GetMinSize());
			}
		}
		return minsize;
	}

	short int posx;
	short int posy;
	int size;
	bool used;
	QuadTreeNode* children[4];
};


QuadTreeNode* QuadTreeNode::FindPosInQuadTree(int xsize, int ysize)
{
    //stub method
}


CQuadtreeAtlasAlloc::CQuadtreeAtlasAlloc()
{
    //stub method
}


CQuadtreeAtlasAlloc::~CQuadtreeAtlasAlloc()
{
    //stub method
}


QuadTreeNode* CQuadtreeAtlasAlloc::FindPosInQuadTree(int xsize, int ysize)
{
    //stub method
}


int CQuadtreeAtlasAlloc::CompareTex(SAtlasEntry* tex1, SAtlasEntry* tex2)
{
    //stub method
}


bool CQuadtreeAtlasAlloc::Allocate()
{
    //stub method
}


int CQuadtreeAtlasAlloc::GetMaxMipMaps()
{
    //stub method
}
