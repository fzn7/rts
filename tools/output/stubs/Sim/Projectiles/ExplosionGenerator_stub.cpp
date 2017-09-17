/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <boost/cstdint.hpp>

#include "ExplosionGenerator.h"
#include "ExpGenSpawner.h" //!!
#include "ExpGenSpawnable.h"
#include "ExpGenSpawnableMemberInfo.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Lua/LuaParser.h"
#include "Map/Ground.h"
#include "Rendering/GroundFlash.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/BubbleProjectile.h"
#include "Rendering/Env/Particles/Classes/DirtProjectile.h"
#include "Rendering/Env/Particles/Classes/ExploSpikeProjectile.h"
#include "Rendering/Env/Particles/Classes/HeatCloudProjectile.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile2.h"
#include "Rendering/Env/Particles/Classes/SpherePartProjectile.h"
#include "Rendering/Env/Particles/Classes/WakeProjectile.h"
#include "Rendering/Env/Particles/Classes/WreckProjectile.h"

#include "System/creg/STL_Map.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileSystemInitializer.h"
#include "System/Log/DefaultFilter.h"
#include "System/Log/ILog.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Util.h"
#include "System/Sync/HsiehHash.h"


CR_BIND_INTERFACE(IExplosionGenerator)
CR_REG_METADATA(IExplosionGenerator, (
	CR_MEMBER(generatorID)
))

CR_BIND_DERIVED(CStdExplosionGenerator, IExplosionGenerator, )
CR_REG_METADATA(CStdExplosionGenerator, )

CR_BIND(CCustomExplosionGenerator::ProjectileSpawnInfo, )
CR_REG_METADATA_SUB(CCustomExplosionGenerator, ProjectileSpawnInfo, (
	CR_MEMBER(spawnableID),
	CR_MEMBER(code),
	CR_MEMBER(count),
	CR_MEMBER(flags)
))

CR_BIND(GroundFlashInfo, )
CR_REG_METADATA(GroundFlashInfo, (
	CR_MEMBER(flashSize),
	CR_MEMBER(flashAlpha),
	CR_MEMBER(circleGrowth),
	CR_MEMBER(circleAlpha),
	CR_MEMBER(ttl),
	CR_MEMBER(flags),
	CR_MEMBER(color)
))

CR_BIND(CCustomExplosionGenerator::ExpGenParams, )
CR_REG_METADATA_SUB(CCustomExplosionGenerator, ExpGenParams, (
	CR_MEMBER(projectiles),
	CR_MEMBER(groundFlash),
	CR_MEMBER(useDefaultExplosions)
))

CR_BIND_DERIVED(CCustomExplosionGenerator, CStdExplosionGenerator, )
CR_REG_METADATA(CCustomExplosionGenerator, (
	CR_MEMBER(expGenParams)
))


CExplosionGeneratorHandler* explGenHandler = NULL;



unsigned int CCustomExplosionGenerator::GetFlagsFromTable(const LuaTable& table)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int CCustomExplosionGenerator::GetFlagsFromHeight(float height, float groundHeight)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void ClassAliasList::Load(const LuaTable& aliasTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string ClassAliasList::ResolveAlias(const string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


string ClassAliasList::FindAlias(const string& className) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}






CExplosionGeneratorHandler::CExplosionGeneratorHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CExplosionGeneratorHandler::~CExplosionGeneratorHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CExplosionGeneratorHandler::ParseExplosionTables() {
	delete exploParser;
	delete aliasParser;
	delete explTblRoot;

	exploParser = new LuaParser("gamedata/explosions.lua", SPRING_VFS_MOD_BASE, SPRING_VFS_ZIP);
	aliasParser = new LuaParser("gamedata/explosion_alias.lua", SPRING_VFS_MOD_BASE, SPRING_VFS_ZIP);
	explTblRoot = NULL;

	if (!aliasParser->Execute()) {
		LOG_L(L_ERROR, "Failed to parse explosion aliases: %s",
				aliasParser->GetErrorLog().c_str());
	} else {
		const LuaTable& aliasRoot = aliasParser->GetRoot();

		projectileClasses.Clear();
		projectileClasses.Load(aliasRoot.SubTable("projectiles"));
	}

	if (!exploParser->Execute()) {
		LOG_L(L_ERROR, "Failed to parse explosions: %s", exploParser->GetErrorLog().c_str());
	} else {
		explTblRoot = new LuaTable(exploParser->GetRoot());
	}
}

void CExplosionGeneratorHandler::ReloadGenerators(const std::string& tag) {
	// re-parse the projectile and generator tables
	ParseExplosionTables();

	const char* preFmt = "[%s][generatorID=%u] reloading CEG \"%s\"";
	const char* pstFmt = "[%s][generatorID=%u] failed to reload CEG \"%s\"";

	// NOTE:
	//   maps store tags inclusive of CEG_PREFIX_STRING
	//   but the Lua subtables that define each CEG are
	//   only indexed by tag postfix
	if (tag.empty()) {
		for (unsigned int n = 1; n < explosionGenerators.size(); n++) {
			IExplosionGenerator* eg = explosionGenerators[n];

			// standard EG's (empty postfix) do not need to be reloaded
			if (expGenIdentTagMap.find(n) == expGenIdentTagMap.end())
				continue;

			assert(eg->GetGeneratorID() == n);
			LOG(preFmt, __FUNCTION__, n, expGenIdentTagMap[n].c_str());

			if (!eg->Reload(this, expGenIdentTagMap[n].substr(7))) {
				LOG_L(L_WARNING, pstFmt, __FUNCTION__, n, expGenIdentTagMap[n].c_str());
			}
		}
	} else {
		const TagIdentMapConstIt it = expGenTagIdentMap.find(tag);

		if (it == expGenTagIdentMap.end()) {
			LOG_L(L_WARNING, "[%s] no CEG named \"%s\" (forgot the \"%s\" prefix?)", __FUNCTION__, tag.c_str(), CEG_PREFIX_STRING);
			return;
		}

		assert(explosionGenerators[it->second]->GetGeneratorID() == it->second);
		LOG(preFmt, __FUNCTION__, it->second, tag.c_str());

		if (!explosionGenerators[it->second]->Reload(this, tag.substr(7))) {
			LOG_L(L_WARNING, pstFmt, __FUNCTION__, it->second, tag.c_str());
		}
	}
}



unsigned int CExplosionGeneratorHandler::LoadGeneratorID(const std::string& tag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// creates either a standard or a custom explosion generator instance
// NOTE:
//   can be called recursively for custom instances (LoadGenerator ->
//   Load -> ParseExplosionCode -> LoadGenerator -> ...), generators
//   must NOT be overwritten
IExplosionGenerator* CExplosionGeneratorHandler::LoadGenerator(const string& tag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IExplosionGenerator* CExplosionGeneratorHandler::GetGenerator(unsigned int expGenID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CExplosionGeneratorHandler::GenExplosion(
	unsigned int expGenID,
	const float3& pos,
	const float3& dir,
	float damage,
	float radius,
	float gfxMod,
	CUnit* owner,
	CUnit* hit
) {
	if (expGenID == EXPGEN_ID_INVALID)
		return false;

	assert(expGenID < explosionGenerators.size());

	return explosionGenerators[expGenID]->Explosion(pos, dir, damage, radius, gfxMod, owner, hit);
}



bool CStdExplosionGenerator::Explosion(
	const float3& pos,
	const float3& dir,
	float damage,
	float radius,
	float gfxMod,
	CUnit* owner,
	CUnit* hit
) {
	const float groundHeight = CGround::GetHeightReal(pos.x, pos.z);
	const float altitude = pos.y - groundHeight;

	float3 camVect = camera->GetPos() - pos;

	const unsigned int flags = CCustomExplosionGenerator::GetFlagsFromHeight(pos.y, groundHeight);
	const bool airExplosion    = ((flags & CCustomExplosionGenerator::SPW_AIR       ) != 0);
	const bool groundExplosion = ((flags & CCustomExplosionGenerator::SPW_GROUND    ) != 0);
	const bool waterExplosion  = ((flags & CCustomExplosionGenerator::SPW_WATER     ) != 0);
	const bool uwExplosion     = ((flags & CCustomExplosionGenerator::SPW_UNDERWATER) != 0);

	// limit the visual effects based on the radius
	damage /= 20.0f;
	damage = std::min(damage, radius * 1.5f);
	damage *= gfxMod;
	damage = std::max(damage, 0.0f);

	const float sqrtDmg = math::sqrt(damage);
	const float camLength = camVect.Length();
	float moveLength = radius * 0.03f;

	if (camLength > 0.0f) { camVect /= camLength; }
	if (camLength < moveLength + 2) { moveLength = camLength - 2; }

	const float3 npos = pos + camVect * moveLength;

	new CHeatCloudProjectile(owner, npos, float3(0.0f, 0.3f, 0.0f), 8.0f + sqrtDmg * 0.5f, 7 + damage * 2.8f);

	if (projectileHandler->GetParticleSaturation() < 1.0f) {
		// turn off lots of graphic only particles when we have more particles than we want
		float smokeDamage      = damage;
		float smokeDamageSQRT  = 0.0f;
		float smokeDamageISQRT = 0.0f;

		if (uwExplosion) { smokeDamage *= 0.3f; }
		if (airExplosion || waterExplosion) { smokeDamage *= 0.6f; }

		if (smokeDamage > 0.01f) {
			smokeDamageSQRT = math::sqrt(smokeDamage);
			smokeDamageISQRT = 1.0f / (smokeDamageSQRT * 0.35f);
		}

		for (int a = 0; a < smokeDamage * 0.6f; ++a) {
			const float3 speed(
				(-0.1f + gu->RandFloat() * 0.2f),
				( 0.1f + gu->RandFloat() * 0.3f) * smokeDamageISQRT,
				(-0.1f + gu->RandFloat() * 0.2f)
			);

			const float time = (40.0f + smokeDamageSQRT * 15.0f) * (0.8f + gu->RandFloat() * 0.7f);

			float3 dir = gu->RandVector() * smokeDamage;
			dir.y = std::abs(dir.y);
			const float3 npos = pos + dir;

			new CSmokeProjectile2(owner, pos, npos, speed, time, smokeDamageSQRT * 4.0f, 0.4f, 0.6f);
		}

		if (groundExplosion) {
			const int numDirt = std::min(20.0f, damage * 0.8f);
			const float explSpeedMod = 0.7f + std::min(30.0f, damage) / GAME_SPEED;
			const float3 color(0.15f, 0.1f, 0.05f);

			for (int a = 0; a < numDirt; ++a) {
				const float3 explSpeed = float3(
					(0.5f - gu->RandFloat()) * 1.5f,
					 1.7f + gu->RandFloat()  * 1.6f,
					(0.5f - gu->RandFloat()) * 1.5f
				);

				const float3 npos(
					pos.x - (0.5f - gu->RandFloat()) * (radius * 0.6f),
					pos.y -  2.0f - damage * 0.2f,
					pos.z - (0.5f - gu->RandFloat()) * (radius * 0.6f)
				);

				new CDirtProjectile(owner, npos, explSpeed  * explSpeedMod, 90.0f + damage * 2.0f, 2.0f + sqrtDmg * 1.5f, 0.4f, 0.999f, color);
			}
		}

		if (!airExplosion && !uwExplosion && waterExplosion) {
			const int numDirt = std::min(40.f, damage * 0.8f);
			const float3 color(1.0f, 1.0f, 1.0f);

			for (int a = 0; a < numDirt; ++a) {
				const float3 speed(
					(    0.5f - gu->RandFloat()) * 0.2f,
					(a * 0.1f + gu->RandFloat()  * 0.8f),
					(    0.5f - gu->RandFloat()) * 0.2f
				);
				const float3 npos(
					pos.x - (0.5f - gu->RandFloat()) * (radius * 0.2f),
					pos.y -  2.0f - sqrtDmg          *           2.0f,
					pos.z - (0.5f - gu->RandFloat()) * (radius * 0.2f)
				);

				new CDirtProjectile(
					owner,
					npos,
					speed * (0.7f + std::min(30.0f, damage) / GAME_SPEED),
					90.0f + damage * 2.0f,
					2.0f + sqrtDmg * 2.0f,
					0.3f,
					0.99f,
					color
				);
			}
		}
		if (damage >= 20.0f && !uwExplosion && !airExplosion) {
			const int numDebris = (gu->RandInt() % 6) + 3 + int(damage * 0.04f);
			const float explSpeedMod = (0.7f + std::min(30.0f, damage) / 23);

			for (int a = 0; a < numDebris; ++a) {
				const float3 explSpeed = (altitude < 4.0f)?
					float3((0.5f - gu->RandFloat()) * 2.0f, 1.8f + gu->RandFloat() * 1.8f, (0.5f - gu->RandFloat()) * 2.0f):
					float3(gu->RandVector() * 2);

				const float3 npos(
					pos.x - (0.5f - gu->RandFloat()) * (radius * 1),
					pos.y,
					pos.z - (0.5f - gu->RandFloat()) * (radius * 1)
				);

				new CWreckProjectile(owner, npos, explSpeed * explSpeedMod, 90.0f + damage * 2.0f);
			}
		}
		if (uwExplosion) {
			const int numBubbles = (damage * 0.7f);

			for (int a = 0; a < numBubbles; ++a) {
				new CBubbleProjectile(
					owner,
					pos + gu->RandVector() * radius * 0.5f,
					gu->RandVector() * 0.2f + float3(0.0f, 0.2f, 0.0f),
					damage * 2.0f + gu->RandFloat() * damage,
					1.0f + gu->RandFloat() * 2.0f,
					0.02f,
					0.5f + gu->RandFloat() * 0.3f
				);
			}
		}
		if (waterExplosion && !uwExplosion && !airExplosion) {
			const int numWake = (damage * 0.5f);

			for (int a = 0; a < numWake; ++a) {
				new CWakeProjectile(
					owner,
					pos + gu->RandVector() * radius * 0.2f,
					gu->RandVector() * radius * 0.003f,
					sqrtDmg * 4.0f,
					damage * 0.03f,
					0.3f + gu->RandFloat() * 0.2f,
					0.8f / (sqrtDmg * 3 + 50 + gu->RandFloat() * 90.0f),
					1
				);
			}
		}
		if (radius > 10.0f && damage > 4.0f) {
			const int numSpike = int(sqrtDmg) + 8;
			const float explSpeedMod = (8 + damage * 3.0f) / (9 + sqrtDmg * 0.7f) * 0.35f;

			for (int a = 0; a < numSpike; ++a) {
				float3 explSpeed = (gu->RandVector()).SafeNormalize() * explSpeedMod;

				if (!airExplosion && !waterExplosion && (explSpeed.y < 0.0f)) {
					explSpeed.y = -explSpeed.y;
				}

				new CExploSpikeProjectile(
					owner,
					pos + explSpeed,
					explSpeed * (0.9f + gu->RandFloat() * 0.4f),
					radius * 0.1f,
					radius * 0.1f,
					0.6f,
					0.8f / (8.0f + sqrtDmg)
				);
			}
		}
	}

	if (radius > 20.0f && damage > 6.0f && altitude < (radius * 0.7f)) {
		const float flashSize = std::max(radius, damage * 2);
		const float ttl = 8 + sqrtDmg * 0.8f;

		if (flashSize > 5.f && ttl > 15.f) {
			const float flashAlpha = std::min(0.8f, damage * 0.01f);

			float circleAlpha = 0;
			float circleGrowth = 0;

			if (radius > 40.0f && damage > 12.0f) {
				circleAlpha = std::min(0.5f, damage * 0.01f);
				circleGrowth = (8.0f + damage * 2.5f) / (9.0f + sqrtDmg * 0.7f) * 0.55f;
			}

			new CStandardGroundFlash(pos, circleAlpha, flashAlpha, flashSize, circleGrowth, ttl);
		}
	}

	if (radius > 40.0f && damage > 12.0f) {
		CSpherePartProjectile::CreateSphere(
			owner,
			5.0f + int(sqrtDmg * 0.7f),
			std::min(0.7f, damage * 0.02f),
			(8.0f + damage * 2.5f) / (9.0f + sqrtDmg * 0.7f) * 0.5f,
			pos
		);
	}

	return true;
}



void CCustomExplosionGenerator::ExecuteExplosionCode(const char* code, float damage, char* instance, int spawnIndex, const float3& dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CCustomExplosionGenerator::ParseExplosionCode(
	CCustomExplosionGenerator::ProjectileSpawnInfo* psi,
	const string& script,
	SExpGenSpawnableMemberInfo& memberInfo,
	string& code)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CCustomExplosionGenerator::Load(CExplosionGeneratorHandler* handler, const string& tag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CCustomExplosionGenerator::Reload(CExplosionGeneratorHandler* handler, const std::string& tag) {
	const ExpGenParams oldParams = expGenParams;

	if (!Load(explGenHandler, tag)) {
		expGenParams = oldParams;
		return false;
	}

	return true;
}

bool CCustomExplosionGenerator::Explosion(
	const float3& pos,
	const float3& dir,
	float damage,
	float radius,
	float gfxMod,
	CUnit* owner,
	CUnit* hit
) {
	const float groundHeight = CGround::GetHeightReal(pos.x, pos.z);

	unsigned int flags = GetFlagsFromHeight(pos.y, groundHeight);
	const bool groundExplosion = ((flags & CCustomExplosionGenerator::SPW_GROUND) != 0);

	if (hit) flags |= SPW_UNIT;
	else     flags |= SPW_NO_UNIT;

	const std::vector<ProjectileSpawnInfo>& spawnInfo = expGenParams.projectiles;
	const GroundFlashInfo& groundFlash = expGenParams.groundFlash;

	for (int a = 0; a < spawnInfo.size(); a++) {
		const ProjectileSpawnInfo& psi = spawnInfo[a];

		if ((psi.flags & flags) == 0)
			continue;

		// no new projectiles if we're saturated
		if (projectileHandler->GetParticleSaturation() > 1.0f)
			break;

		for (unsigned int c = 0; c < psi.count; c++) {
			CExpGenSpawnable* projectile = CExpGenSpawnable::CreateSpawnable(psi.spawnableID);
			ExecuteExplosionCode(&psi.code[0], damage, (char*) projectile, c, dir);
			projectile->Init(owner, pos);
		}
	}

	if (groundExplosion && (groundFlash.ttl > 0) && (groundFlash.flashSize > 1)) {
		new CStandardGroundFlash(pos, groundFlash);
	}

	if (expGenParams.useDefaultExplosions) {
		return (explGenHandler->GenExplosion(CExplosionGeneratorHandler::EXPGEN_ID_STANDARD, pos, dir, damage, radius, gfxMod, owner, hit));
	}

	return true;
}


bool CCustomExplosionGenerator::OutputProjectileClassInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

