/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LosHandler.h"

#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Map/ReadMap.h"
#include "System/Log/ILog.h"
#include "System/Sync/HsiehHash.h"
#include "System/creg/STL_Deque.h"
#include "System/EventHandler.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"


CR_BIND(CLosHandler, )

// ILosTypes aren't creg'ed cause they repopulate themselves in case of loading a saved game
CR_REG_METADATA(CLosHandler,(
	CR_IGNORED(autoLinkEvents),
	CR_IGNORED(autoLinkedEvents),
	CR_IGNORED(name),
	CR_IGNORED(order),
	CR_IGNORED(synced_),

	CR_MEMBER(globalLOS),
	CR_IGNORED(los),
	CR_IGNORED(airLos),
	CR_IGNORED(radar),
	CR_IGNORED(sonar),
	CR_IGNORED(seismic),
	CR_IGNORED(jammer),
	CR_IGNORED(sonarJammer),
	CR_MEMBER(baseRadarErrorSize),
	CR_MEMBER(baseRadarErrorMult),
	CR_MEMBER(radarErrorSizes),
	CR_IGNORED(losTypes)
))



//////////////////////////////////////////////////////////////////////
// SLosInstance
//////////////////////////////////////////////////////////////////////

inline void SLosInstance::Init(int radius, int allyteam, int2 basePos, float baseHeight, int hashNum)
{
    //stub method
}


//////////////////////////////////////////////////////////////////////
// ILosType
//////////////////////////////////////////////////////////////////////

size_t ILosType::cacheFails = 1;
size_t ILosType::cacheHits  = 1;
size_t ILosType::cacheReactivated = 1;
constexpr float CLosHandler::defBaseRadarErrorSize;
constexpr float CLosHandler::defBaseRadarErrorMult;
constexpr SLosInstance::RLE SLosInstance::EMPTY_RLE;


ILosType::ILosType(const int mipLevel_, LosType type_)
	: mipLevel(mipLevel_)
	, divisor(SQUARE_SIZE * (1 << mipLevel))
	, invDiv(1.0f / divisor)
	, size(std::max(1, mapDims.mapx >> mipLevel), std::max(1, mapDims.mapy >> mipLevel))
	, type(type_)
	, algoType((type == LOS_TYPE_LOS || type == LOS_TYPE_RADAR) ? LOS_ALGO_RAYCAST : LOS_ALGO_CIRCLE)
	, losMaps(teamHandler->ActiveAllyTeams(),
		CLosMap(size, type == LOS_TYPE_LOS, readMap->GetMIPHeightMapSynced(mipLevel_), int2(mapDims.mapx, mapDims.mapy)))
{
    //stub method
}


float ILosType::GetRadius(const CUnit* unit) const
{
    //stub method
}


float ILosType::GetHeight(const CUnit* unit) const
{
    //stub method
}


inline void ILosType::UpdateUnit(CUnit* unit)
{
    //stub method
}


inline void ILosType::RemoveUnit(CUnit* unit, bool delayed)
{
    //stub method
}


inline void ILosType::LosAdd(SLosInstance* li)
{
    //stub method
}


inline void ILosType::LosRemove(SLosInstance* li)
{
    //stub method
}


inline void ILosType::RefInstance(SLosInstance* li)
{
    //stub method
}


void ILosType::UnrefInstance(SLosInstance* li)
{
    //stub method
}


inline void ILosType::DelayedUnrefInstance(SLosInstance* li)
{
    //stub method
}


inline void ILosType::AddInstanceToCache(SLosInstance* li)
{
    //stub method
}


inline SLosInstance* ILosType::CreateInstance()
{
    //stub method
}


inline void ILosType::DeleteInstance(SLosInstance* li)
{
    //stub method
}


inline void ILosType::UpdateInstanceStatus(SLosInstance* li, SLosInstance::TLosStatus status)
{
    //stub method
}


inline SLosInstance::TLosStatus ILosType::OptimizeInstanceUpdate(SLosInstance* li)
{
    //stub method
}


inline int ILosType::GetHashNum(const int allyteam, const int2 baseLos, const float radius) const
{
    //stub method
}


void ILosType::Update()
{
    //stub method
}


void ILosType::UpdateHeightMapSynced(SRectangle rect)
{
    //stub method
}




//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLosHandler* losHandler = nullptr;

CLosHandler::CLosHandler()
	: CEventClient("[CLosHandler]", 271993, true)

	, globalLOS{false}
	, los(modInfo.losMipLevel, ILosType::LOS_TYPE_LOS)
	, airLos(modInfo.airMipLevel, ILosType::LOS_TYPE_AIRLOS)
	, radar(modInfo.radarMipLevel, ILosType::LOS_TYPE_RADAR)
	, sonar(modInfo.radarMipLevel, ILosType::LOS_TYPE_SONAR)
	, seismic(modInfo.radarMipLevel, ILosType::LOS_TYPE_SEISMIC)
	, jammer(modInfo.radarMipLevel, ILosType::LOS_TYPE_JAMMER)
	, sonarJammer(modInfo.radarMipLevel, ILosType::LOS_TYPE_SONAR_JAMMER)

	, baseRadarErrorSize(defBaseRadarErrorSize)
	, baseRadarErrorMult(defBaseRadarErrorMult)
	, radarErrorSizes(teamHandler->ActiveAllyTeams(), defBaseRadarErrorSize)
{
    //stub method
}


CLosHandler::~CLosHandler()
{
    //stub method
}


void CLosHandler::UnitDestroyed(const CUnit* unit, const CUnit* attacker)
{
    //stub method
}


void CLosHandler::UnitTaken(const CUnit* unit, int oldTeam, int newTeam)
{
    //stub method
}


void CLosHandler::UnitReverseBuilt(const CUnit* unit)
{
    //stub method
}


void CLosHandler::UnitLoaded(const CUnit* unit, const CUnit* transport)
{
    //stub method
}


void CLosHandler::Update()
{
    //stub method
}


void CLosHandler::UpdateHeightMapSynced(SRectangle rect)
{
    //stub method
}


bool CLosHandler::InLos(const CUnit* unit, int allyTeam) const
{
    //stub method
}


bool CLosHandler::InAirLos(const CUnit* unit, int allyTeam) const
{
    //stub method
}


bool CLosHandler::InRadar(const float3 pos, int allyTeam) const
{
    //stub method
}


bool CLosHandler::InRadar(const CUnit* unit, int allyTeam) const
{
    //stub method
}


bool CLosHandler::InJammer(const float3 pos, int allyTeam) const
{
    //stub method
}


bool CLosHandler::InJammer(const CUnit* unit, int allyTeam) const
{
    //stub method
}
