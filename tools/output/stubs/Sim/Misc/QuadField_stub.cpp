#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>

#include "QuadField.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/TeamHandler.h"

#ifndef UNIT_TEST
	#include "Sim/Features/Feature.h"
	#include "Sim/Projectiles/Projectile.h"
	#include "Sim/Units/Unit.h"
	#include "Sim/Weapons/PlasmaRepulser.h"
#endif

#include "System/Util.h"

CR_BIND(CQuadField, (int2(1,1), 1))
CR_REG_METADATA(CQuadField, (
	CR_MEMBER(baseQuads),
	CR_MEMBER(numQuadsX),
	CR_MEMBER(numQuadsZ),
	CR_MEMBER(quadSizeX),
	CR_MEMBER(quadSizeZ),

	CR_IGNORED(tempUnits),
	CR_IGNORED(tempFeatures),
	CR_IGNORED(tempProjectiles),
	CR_IGNORED(tempSolids),
	CR_IGNORED(tempQuads)
))

CR_BIND(CQuadField::Quad, )
CR_REG_METADATA_SUB(CQuadField, Quad, (
	CR_MEMBER(units),
	CR_IGNORED(teamUnits),
	CR_MEMBER(features),
	CR_MEMBER(projectiles),
	CR_MEMBER(repulsers),

	CR_POSTLOAD(PostLoad)
))

CQuadField* quadField = NULL;


#ifndef UNIT_TEST
/*
void CQuadField::Resize(int quad_size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
*/
#endif


CQuadField::Quad::Quad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CQuadField::Quad::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CQuadField::CQuadField(int2 mapDims, int quad_size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CQuadField::~CQuadField()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int2 CQuadField::WorldPosToQuadField(const float3 p) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CQuadField::WorldPosToQuadFieldIdx(const float3 p) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


#ifndef UNIT_TEST
const std::vector<int>& CQuadField::GetQuads(float3 pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::vector<int>& CQuadField::GetQuadsRectangle(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif // UNIT_TEST


/// note: this function got an UnitTest, check the tests/ folder!
const std::vector<int>& CQuadField::GetQuadsOnRay(const float3& start, const float3& dir, float length)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


#ifndef UNIT_TEST
void CQuadField::MovedUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CQuadField::RemoveUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CQuadField::MovedRepulser(CPlasmaRepulser* repulser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CQuadField::RemoveRepulser(CPlasmaRepulser* repulser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CQuadField::AddFeature(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CQuadField::RemoveFeature(CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CQuadField::MovedProjectile(CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CQuadField::AddProjectile(CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CQuadField::RemoveProjectile(CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}





const std::vector<CUnit*>& CQuadField::GetUnits(const float3& pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CUnit*>& CQuadField::GetUnitsExact(const float3& pos, float radius, bool spherical)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CUnit*>& CQuadField::GetUnitsExact(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::vector<CFeature*>& CQuadField::GetFeaturesExact(const float3& pos, float radius, bool spherical)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CFeature*>& CQuadField::GetFeaturesExact(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



const std::vector<CProjectile*>& CQuadField::GetProjectilesExact(const float3& pos, float radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<CProjectile*>& CQuadField::GetProjectilesExact(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



const std::vector<CSolidObject*>& CQuadField::GetSolidsExact(
	const float3& pos,
	const float radius,
	const unsigned int physicalStateBits,
	const unsigned int collisionStateBits
) {
	const auto& quads = GetQuads(pos, radius);
	const int tempNum = gs->GetTempNum();
	tempSolids.clear();

	for (const int qi: quads) {
		for (CUnit* u: baseQuads[qi].units) {
			if (u->tempNum == tempNum)
				continue;

			u->tempNum = tempNum;

			if (!u->HasPhysicalStateBit(physicalStateBits))
				continue;
			if (!u->HasCollidableStateBit(collisionStateBits))
				continue;
			if ((pos - u->pos).SqLength() >= Square(radius + u->radius))
				continue;

			tempSolids.push_back(u);
		}

		for (CFeature* f: baseQuads[qi].features) {
			if (f->tempNum == tempNum)
				continue;

			f->tempNum = tempNum;

			if (!f->HasPhysicalStateBit(physicalStateBits))
				continue;
			if (!f->HasCollidableStateBit(collisionStateBits))
				continue;
			if ((pos - f->pos).SqLength() >= Square(radius + f->radius))
				continue;

			tempSolids.push_back(f);
		}
	}

	return tempSolids;
}


bool CQuadField::NoSolidsExact(
	const float3& pos,
	const float radius,
	const unsigned int physicalStateBits,
	const unsigned int collisionStateBits
) {
	const auto& quads = GetQuads(pos, radius);
	const int tempNum = gs->GetTempNum();

	for (const int qi: quads) {
		for (CUnit* u: baseQuads[qi].units) {
			if (u->tempNum == tempNum)
				continue;

			u->tempNum = tempNum;

			if (!u->HasPhysicalStateBit(physicalStateBits))
				continue;
			if (!u->HasCollidableStateBit(collisionStateBits))
				continue;
			if ((pos - u->pos).SqLength() >= Square(radius + u->radius))
				continue;

			return false;
		}

		for (CFeature* f: baseQuads[qi].features) {
			if (f->tempNum == tempNum)
				continue;

			f->tempNum = tempNum;

			if (!f->HasPhysicalStateBit(physicalStateBits))
				continue;
			if (!f->HasCollidableStateBit(collisionStateBits))
				continue;
			if ((pos - f->pos).SqLength() >= Square(radius + f->radius))
				continue;

			return false;
		}
	}

	return true;
}


// optimization specifically for projectile collisions
void CQuadField::GetUnitsAndFeaturesColVol(
	const float3& pos,
	const float radius,
	std::vector<CUnit*>& units,
	std::vector<CFeature*>& features,
	std::vector<CPlasmaRepulser*>* repulsers
) {
	const int tempNum = gs->GetTempNum();

	// start counting from the previous object-cache sizes
	const auto& quads = GetQuads(pos, radius);

	for (const int qi: quads) {
		const Quad& quad = baseQuads[qi];

		for (CUnit* u: quad.units) {
			// prevent double adding
			if (u->tempNum == tempNum)
				continue;

			u->tempNum = tempNum;

			const auto* colvol = &u->collisionVolume;
			const float totRad = radius + colvol->GetBoundingRadius();

			if (pos.SqDistance(colvol->GetWorldSpacePos(u)) >= (totRad * totRad))
				continue;

			units.push_back(u);
		}

		for (CFeature* f: quad.features) {
			// prevent double adding
			if (f->tempNum == tempNum)
				continue;

			f->tempNum = tempNum;

			const auto* colvol = &f->collisionVolume;
			const float totRad = radius + colvol->GetBoundingRadius();

			if (pos.SqDistance(colvol->GetWorldSpacePos(f)) >= (totRad * totRad))
				continue;

			features.push_back(f);
		}
		if (repulsers != nullptr) {
			for (CPlasmaRepulser* r: quad.repulsers) {
				// prevent double adding
				if (r->tempNum == tempNum)
					continue;

				r->tempNum = tempNum;

				const auto* colvol = &r->collisionVolume;
				const float totRad = radius + colvol->GetBoundingRadius();

				if (pos.SqDistance(r->weaponMuzzlePos) >= (totRad * totRad))
					continue;

				repulsers->push_back(r);
			}
		}
	}
}
#endif // UNIT_TEST
