/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LegacyMeshDrawer.h"
#include "Game/Camera.h"
#include "Map/SMF/SMFReadMap.h"
#include "Map/SMF/SMFGroundDrawer.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "System/Config/ConfigHandler.h"
#include "System/FastMath.h"
#include "System/myMath.h"
#include "System/Util.h"

#define CLAMP(i) Clamp((i), 0, smfReadMap->maxHeightMapIdx)

CLegacyMeshDrawer::CLegacyMeshDrawer(CSMFReadMap* rm, CSMFGroundDrawer* gd)
	: smfReadMap(rm)
	, smfGroundDrawer(gd)
	, viewRadius(4)
	, neededLod(4)
	//, waterDrawn(false)
{
    //stub method
}

CLegacyMeshDrawer::~CLegacyMeshDrawer()
{
    //stub method
}




void CLegacyMeshDrawer::DrawVertexAQ(CVertexArray* ma, int x, int y)
{
    //stub method
}

void CLegacyMeshDrawer::DrawVertexAQ(CVertexArray* ma, int x, int y, float height)
{
    //stub method
}


void CLegacyMeshDrawer::DrawGroundVertexArrayQ(CVertexArray*& ma)
{
    //stub method
}



bool CLegacyMeshDrawer::BigTexSquareRowVisible(const CCamera* cam, int bty) const
{
    //stub method
}



void CLegacyMeshDrawer::FindRange(const CCamera* cam, int& xs, int& xe, int y, int lod)
{
    //stub method
}



void CLegacyMeshDrawer::DoDrawGroundRow(const CCamera* cam, int bty)
{
    //stub method
}


void CLegacyMeshDrawer::UpdateLODParams(const DrawPass::e& drawPass)
{
    //stub method
}


void CLegacyMeshDrawer::DrawMesh(const DrawPass::e& drawPass)
{
    //stub method
}


void CLegacyMeshDrawer::DoDrawGroundShadowLOD(int nlod) {
	CVertexArray* ma = GetVertexArray();
	ma->Initialize();

	bool inStrip = false;
	int x,y;
	int lod = 1 << nlod;

	float cx2 = camera->GetPos().x / SQUARE_SIZE;
	float cy2 = camera->GetPos().z / SQUARE_SIZE;

	float oldcamxpart = 0.0f;
	float oldcamypart = 0.0f;

	int hlod = lod >> 1;
	int dlod = lod << 1;

	int cx = (int)cx2;
	int cy = (int)cy2;
	if (lod > 1) {
		int cxo = (cx / hlod) * hlod;
		int cyo = (cy / hlod) * hlod;
		float cx2o = (cxo / lod) * lod;
		float cy2o = (cyo / lod) * lod;
		oldcamxpart = (cx2 - cx2o) / lod;
		oldcamypart = (cy2 - cy2o) / lod;
	}

	cx = (cx / lod) * lod;
	cy = (cy / lod) * lod;
	const int ysquaremod = (cy % dlod) / lod;
	const int xsquaremod = (cx % dlod) / lod;

	const float camxpart = (cx2 - (cx / dlod) * dlod) / dlod;
	const float camypart = (cy2 - (cy / dlod) * dlod) / dlod;

	const int minty = 0, maxty = mapDims.mapy;
	const int mintx = 0, maxtx = mapDims.mapx;

	const int minly = cy + (-viewRadius + 3 - ysquaremod) * lod, maxly = cy + ( viewRadius - 1 - ysquaremod) * lod;
	const int minlx = cx + (-viewRadius + 3 - xsquaremod) * lod, maxlx = cx + ( viewRadius - 1 - xsquaremod) * lod;

	const int xstart = std::max(minlx, mintx), xend   = std::min(maxlx, maxtx);
	const int ystart = std::max(minly, minty), yend   = std::min(maxly, maxty);

	const int lhdx = lod * smfReadMap->heightMapSizeX;
	const int hhdx = hlod * smfReadMap->heightMapSizeX;
	const int dhdx = dlod * smfReadMap->heightMapSizeX;

	const float mcxp  = 1.0f - camxpart, mcyp  = 1.0f - camypart;
	const float hcxp  = 0.5f * camxpart, hcyp  = 0.5f * camypart;
	const float hmcxp = 0.5f * mcxp,     hmcyp = 0.5f * mcyp;

	const float mocxp  = 1.0f - oldcamxpart, mocyp  = 1.0f - oldcamypart;
	const float hocxp  = 0.5f * oldcamxpart, hocyp  = 0.5f * oldcamypart;
	const float hmocxp = 0.5f * mocxp,       hmocyp = 0.5f * mocyp;

	const int vrhlod = viewRadius * hlod;

	for (y = ystart; y < yend; y += lod) {
		int xs = xstart;
		int xe = xend;

		if (xe < xs) continue;

		int ylod = y + lod;
		int yhlod = y + hlod;
		int ydx = y * smfReadMap->heightMapSizeX;
		int nloop = (xe - xs) / lod + 1;

		ma->EnlargeArrays(52 * nloop);

		for (x = xs; x < xe; x += lod) {
			int xlod = x + lod;
			int xhlod = x + hlod;
			if ((lod == 1) ||
				(x > cx + vrhlod) || (x < cx - vrhlod) ||
				(y > cy + vrhlod) || (y < cy - vrhlod)) {
					if (!inStrip) {
						DrawVertexAQ(ma, x, y   );
						DrawVertexAQ(ma, x, ylod);
						inStrip = true;
					}
					DrawVertexAQ(ma, xlod, y   );
					DrawVertexAQ(ma, xlod, ylod);
			}
			else {  //! inre begr?sning mot f?eg?nde lod
				int yhdx=ydx+x;
				int ylhdx=yhdx+lhdx;
				int yhhdx=yhdx+hhdx;

				if ( x>= cx + vrhlod) {
					const float h1 = (GetVisibleVertexHeight(yhdx ) + GetVisibleVertexHeight(ylhdx    )) * hmocxp + GetVisibleVertexHeight(yhhdx     ) * oldcamxpart;
					const float h2 = (GetVisibleVertexHeight(yhdx ) + GetVisibleVertexHeight(yhdx+lod )) * hmocxp + GetVisibleVertexHeight(yhdx+hlod ) * oldcamxpart;
					const float h3 = (GetVisibleVertexHeight(ylhdx) + GetVisibleVertexHeight(yhdx+lod )) * hmocxp + GetVisibleVertexHeight(yhhdx+hlod) * oldcamxpart;
					const float h4 = (GetVisibleVertexHeight(ylhdx) + GetVisibleVertexHeight(ylhdx+lod)) * hmocxp + GetVisibleVertexHeight(ylhdx+hlod) * oldcamxpart;

					if(inStrip){
						ma->EndStrip();
						inStrip=false;
					}
					DrawVertexAQ(ma, x,y);
					DrawVertexAQ(ma, x,yhlod,h1);
					DrawVertexAQ(ma, xhlod,y,h2);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					ma->EndStrip();
					DrawVertexAQ(ma, x,yhlod,h1);
					DrawVertexAQ(ma, x,ylod);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					DrawVertexAQ(ma, xhlod,ylod,h4);
					ma->EndStrip();
					DrawVertexAQ(ma, xhlod,ylod,h4);
					DrawVertexAQ(ma, xlod,ylod);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					DrawVertexAQ(ma, xlod,y);
					DrawVertexAQ(ma, xhlod,y,h2);
					ma->EndStrip();
				}
				if (x <= cx - vrhlod) {
					const float h1 = (GetVisibleVertexHeight(yhdx+lod) + GetVisibleVertexHeight(ylhdx+lod)) * hocxp + GetVisibleVertexHeight(yhhdx+lod ) * mocxp;
					const float h2 = (GetVisibleVertexHeight(yhdx    ) + GetVisibleVertexHeight(yhdx+lod )) * hocxp + GetVisibleVertexHeight(yhdx+hlod ) * mocxp;
					const float h3 = (GetVisibleVertexHeight(ylhdx   ) + GetVisibleVertexHeight(yhdx+lod )) * hocxp + GetVisibleVertexHeight(yhhdx+hlod) * mocxp;
					const float h4 = (GetVisibleVertexHeight(ylhdx   ) + GetVisibleVertexHeight(ylhdx+lod)) * hocxp + GetVisibleVertexHeight(ylhdx+hlod) * mocxp;

					if(inStrip){
						ma->EndStrip();
						inStrip=false;
					}
					DrawVertexAQ(ma, xlod,yhlod,h1);
					DrawVertexAQ(ma, xlod,y);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					DrawVertexAQ(ma, xhlod,y,h2);
					ma->EndStrip();
					DrawVertexAQ(ma, xlod,ylod);
					DrawVertexAQ(ma, xlod,yhlod,h1);
					DrawVertexAQ(ma, xhlod,ylod,h4);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					ma->EndStrip();
					DrawVertexAQ(ma, xhlod,y,h2);
					DrawVertexAQ(ma, x,y);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					DrawVertexAQ(ma, x,ylod);
					DrawVertexAQ(ma, xhlod,ylod,h4);
					ma->EndStrip();
				}
				if (y >= cy + vrhlod) {
					const float h1 = (GetVisibleVertexHeight(yhdx     ) + GetVisibleVertexHeight(yhdx+lod)) * hmocyp + GetVisibleVertexHeight(yhdx+hlod ) * oldcamypart;
					const float h2 = (GetVisibleVertexHeight(yhdx     ) + GetVisibleVertexHeight(ylhdx   )) * hmocyp + GetVisibleVertexHeight(yhhdx     ) * oldcamypart;
					const float h3 = (GetVisibleVertexHeight(ylhdx    ) + GetVisibleVertexHeight(yhdx+lod)) * hmocyp + GetVisibleVertexHeight(yhhdx+hlod) * oldcamypart;
					const float h4 = (GetVisibleVertexHeight(ylhdx+lod) + GetVisibleVertexHeight(yhdx+lod)) * hmocyp + GetVisibleVertexHeight(yhhdx+lod ) * oldcamypart;

					if(inStrip){
						ma->EndStrip();
						inStrip=false;
					}
					DrawVertexAQ(ma, x,y);
					DrawVertexAQ(ma, x,yhlod,h2);
					DrawVertexAQ(ma, xhlod,y,h1);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					DrawVertexAQ(ma, xlod,y);
					DrawVertexAQ(ma, xlod,yhlod,h4);
					ma->EndStrip();
					DrawVertexAQ(ma, x,yhlod,h2);
					DrawVertexAQ(ma, x,ylod);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					DrawVertexAQ(ma, xlod,ylod);
					DrawVertexAQ(ma, xlod,yhlod,h4);
					ma->EndStrip();
				}
				if (y <= cy - vrhlod) {
					const float h1 = (GetVisibleVertexHeight(ylhdx    ) + GetVisibleVertexHeight(ylhdx+lod)) * hocyp + GetVisibleVertexHeight(ylhdx+hlod) * mocyp;
					const float h2 = (GetVisibleVertexHeight(yhdx     ) + GetVisibleVertexHeight(ylhdx    )) * hocyp + GetVisibleVertexHeight(yhhdx     ) * mocyp;
					const float h3 = (GetVisibleVertexHeight(ylhdx    ) + GetVisibleVertexHeight(yhdx+lod )) * hocyp + GetVisibleVertexHeight(yhhdx+hlod) * mocyp;
					const float h4 = (GetVisibleVertexHeight(ylhdx+lod) + GetVisibleVertexHeight(yhdx+lod )) * hocyp + GetVisibleVertexHeight(yhhdx+lod ) * mocyp;

					if (inStrip) {
						ma->EndStrip();
						inStrip = false;
					}
					DrawVertexAQ(ma, x,yhlod,h2);
					DrawVertexAQ(ma, x,ylod);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					DrawVertexAQ(ma, xhlod,ylod,h1);
					DrawVertexAQ(ma, xlod,yhlod,h4);
					DrawVertexAQ(ma, xlod,ylod);
					ma->EndStrip();
					DrawVertexAQ(ma, xlod,yhlod,h4);
					DrawVertexAQ(ma, xlod,y);
					DrawVertexAQ(ma, xhlod,yhlod,h3);
					DrawVertexAQ(ma, x,y);
					DrawVertexAQ(ma, x,yhlod,h2);
					ma->EndStrip();
				}
			}
		}
		if (inStrip) {
			ma->EndStrip();
			inStrip=false;
		}
	}

	int yst = std::max(ystart - lod, minty);
	int yed = std::min(yend + lod, maxty);
	int nloop = (yed - yst) / lod + 1;
	ma->EnlargeArrays(8 * nloop);

	//!rita yttre begr?snings yta mot n?ta lod
	if (maxlx < maxtx && maxlx >= mintx) {
		x = maxlx;
		const int xlod = x + lod;

		for (y = yst; y < yed; y += lod) {
			DrawVertexAQ(ma, x, y      );
			DrawVertexAQ(ma, x, y + lod);
			const int yhdx = y * smfReadMap->heightMapSizeX + x;

			if (y % dlod) {
				const float h = (GetVisibleVertexHeight(yhdx - lhdx + lod) + GetVisibleVertexHeight(yhdx + lhdx + lod)) * hmcxp + GetVisibleVertexHeight(yhdx+lod) * camxpart;
				DrawVertexAQ(ma, xlod, y, h);
				DrawVertexAQ(ma, xlod, y + lod);
			} else {
				const float h = (GetVisibleVertexHeight(yhdx+lod) + GetVisibleVertexHeight(yhdx+dhdx+lod)) * hmcxp + GetVisibleVertexHeight(yhdx+lhdx+lod) * camxpart;
				DrawVertexAQ(ma, xlod,y);
				DrawVertexAQ(ma, xlod,y+lod,h);
			}
			ma->EndStrip();
		}
	}

	if (minlx > mintx && minlx < maxtx) {
		x = minlx - lod;
		const int xlod = x + lod;

		for(y = yst; y < yed; y += lod) {
			int yhdx = y * smfReadMap->heightMapSizeX + x;
			if(y%dlod){
				const float h = (GetVisibleVertexHeight(yhdx-lhdx) + GetVisibleVertexHeight(yhdx+lhdx)) * hcxp + GetVisibleVertexHeight(yhdx) * mcxp;
				DrawVertexAQ(ma, x,y,h);
				DrawVertexAQ(ma, x,y+lod);
			} else {
				const float h = (GetVisibleVertexHeight(yhdx) + GetVisibleVertexHeight(yhdx+dhdx)) * hcxp + GetVisibleVertexHeight(yhdx+lhdx) * mcxp;
				DrawVertexAQ(ma, x,y);
				DrawVertexAQ(ma, x,y+lod,h);
			}
			DrawVertexAQ(ma, xlod,y);
			DrawVertexAQ(ma, xlod,y+lod);
			ma->EndStrip();
		}
	}
	if (maxly < maxty && maxly > minty) {
		y = maxly;
		const int xs = std::max(xstart -lod, mintx);
		const int xe = std::min(xend + lod, maxtx);

		if (xs < xe) {
			x = xs;
			const int ylod = y + lod;
			const int ydx = y * smfReadMap->heightMapSizeX;
			const int nloop = (xe - xs) / lod + 2; //! two extra for if statment

			ma->EnlargeArrays(2 * nloop);

			if (x % dlod) {
				const int ylhdx = ydx + x + lhdx;
				const float h = (GetVisibleVertexHeight(ylhdx-lod) + GetVisibleVertexHeight(ylhdx+lod)) * hmcyp + GetVisibleVertexHeight(ylhdx) * camypart;
				DrawVertexAQ(ma, x, y);
				DrawVertexAQ(ma, x, ylod, h);
			} else {
				DrawVertexAQ(ma, x, y);
				DrawVertexAQ(ma, x, ylod);
			}

			for (x = xs; x < xe; x += lod) {
				if (x % dlod) {
					DrawVertexAQ(ma, x + lod, y);
					DrawVertexAQ(ma, x + lod, ylod);
				} else {
					DrawVertexAQ(ma, x+lod,y);
					const int ylhdx = ydx + x + lhdx;
					const float h = (GetVisibleVertexHeight(ylhdx+dlod) + GetVisibleVertexHeight(ylhdx)) * hmcyp + GetVisibleVertexHeight(ylhdx+lod) * camypart;
					DrawVertexAQ(ma, x+lod,ylod,h);
				}
			}
			ma->EndStrip();
		}
	}
	if (minly > minty && minly < maxty) {
		y = minly - lod;
		const int xs = std::max(xstart - lod, mintx);
		const int xe = std::min(xend + lod, maxtx);

		if (xs < xe) {
			x = xs;
			const int ylod = y + lod;
			const int ydx = y * smfReadMap->heightMapSizeX;
			const int nloop = (xe - xs) / lod + 2; //! two extra for if statment

			ma->EnlargeArrays(2 * nloop);

			if (x % dlod) {
				const int yhdx = ydx + x;
				const float h = (GetVisibleVertexHeight(yhdx-lod) + GetVisibleVertexHeight(yhdx + lod)) * hcyp + GetVisibleVertexHeight(yhdx) * mcyp;
				DrawVertexAQ(ma, x, y, h);
				DrawVertexAQ(ma, x, ylod);
			} else {
				DrawVertexAQ(ma, x, y);
				DrawVertexAQ(ma, x, ylod);
			}

			for (x = xs; x < xe; x += lod) {
				if (x % dlod) {
					DrawVertexAQ(ma, x + lod, y);
					DrawVertexAQ(ma, x + lod, ylod);
				} else {
					const int yhdx = ydx + x;
					const float h = (GetVisibleVertexHeight(yhdx+dlod) + GetVisibleVertexHeight(yhdx)) * hcyp + GetVisibleVertexHeight(yhdx+lod) * mcyp;
					DrawVertexAQ(ma, x + lod, y, h);
					DrawVertexAQ(ma, x + lod, ylod);
				}
			}
			ma->EndStrip();
		}
	}
	DrawGroundVertexArrayQ(ma);
}


void CLegacyMeshDrawer::DrawShadowMesh()
{
    //stub method
}
