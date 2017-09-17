/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DebugColVolDrawer.h"
#include <unordered_set>

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/ReadMap.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Models/3DModel.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/Weapon.h"

static const float4 DEFAULT_VOLUME_COLOR = float4(0.45f, 0.0f, 0.45f, 0.35f);
static unsigned int volumeDisplayListIDs[3] = {0, 0, 0};

static inline void DrawCollisionVolume(const CollisionVolume* vol)
{
    //stub method
}



/*
static void DrawUnitDebugPieceTree(const LocalModelPiece* lmp, const LocalModelPiece* lap, int lapf)
{
    //stub method
}
*/

static void DrawObjectDebugPieces(const CSolidObject* o)
{
    //stub method
}



static inline void DrawObjectMidAndAimPos(const CSolidObject* o)
{
    //stub method
}



static inline void DrawFeatureColVol(const CFeature* f)
{
    //stub method
}

static inline void DrawUnitColVol(const CUnit* u)
{
    //stub method
}


class CDebugColVolQuadDrawer : public CReadMap::IQuadDrawer {
public:
	void ResetState() { alreadyDrawnIds.clear(); }
	void DrawQuad(int x, int y)
	{
		const CQuadField::Quad& q = quadField->GetQuadAt(x, y);

		for (const CFeature* f: q.features) {
			if (alreadyDrawnIds.find(MAX_UNITS + f->id) == alreadyDrawnIds.end()) {
				alreadyDrawnIds.insert(MAX_UNITS + f->id);
				DrawFeatureColVol(f);
			}
		}

		for (const CUnit* u: q.units) {
			if (alreadyDrawnIds.find(u->id) == alreadyDrawnIds.end()) {
				alreadyDrawnIds.insert(u->id);
				DrawUnitColVol(u);
			}
		}
	}

	std::unordered_set<int> alreadyDrawnIds;
};



namespace DebugColVolDrawer
{
    //stub method
}
