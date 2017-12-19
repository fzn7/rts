message(STATUS "DEDICATED2 CONNECTED")
ADD_DEFINITIONS    (-DDEDICATED ${PIC_FLAG} -DNOT_USING_CREG)
ADD_DEFINITIONS    (-DHEADLESS -DNO_SOUND)
REMOVE_DEFINITIONS (-DSTREFLOP_SSE -DAVI_CAPTURING)
REMOVE_DEFINITIONS (-DTRACE_SYNC -DSYNCDEBUG)
REMOVE_DEFINITIONS (-DTHREADPOOL)

# deactivate signaling-NANs for this library
RemoveFlag("-fsignaling-nans")

# Place executables and shared libs under "build-dir/",
# instead of under "build-dir/rts/"
# This way, we have the build-dir structure more like the install-dir one,
# which makes testing spring in the builddir easier, eg. like this:
# cd build-dir
# SPRING_DATADIR=$(pwd) ./spring
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

SET(ENGINE_SRC_ROOT_DIR "${CMAKE_SOURCE_DIR}/rts")
 
### Assemble libraries
LIST(APPEND engineDedicatedLibraries ${Boost_REGEX_LIBRARY})
LIST(APPEND engineDedicatedLibraries ${Boost_SYSTEM_LIBRARY})
LIST(APPEND engineDedicatedLibraries lua 7zip ${SPRING_MINIZIP_LIBRARY} ${ZLIB_LIBRARY} gflags archives)  
LIST(APPEND engineDedicatedLibraries headlessStubs) #engineSystemNet)
LIST(APPEND engineDedicatedLibraries ${LIBUNWIND_LIBRARIES})

IF (WIN32)
	LIST(APPEND engineDedicatedLibraries ${WINMM_LIBRARY})
ENDIF (WIN32)

IF    (UNIX AND NOT MINGW)
	IF    (PREFER_STATIC_LIBS)
		LIST(APPEND engineDedicatedLibraries ${C_LIBRARY} ${MATH_LIBRARY} ${REALTIME_LIBRARY})
	ENDIF (PREFER_STATIC_LIBS)

	# Needed for dynamically loading shared libraries (on some OS)
	LIST(APPEND engineDedicatedLibraries ${CMAKE_DL_LIBS})

	# Needed for backtrace* on some systems
	IF(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
		LIST(APPEND engineDedicatedLibraries execinfo)
	ENDIF(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
ENDIF (UNIX AND NOT MINGW)

IF    (MINGW OR APPLE)
	# Windows:
	# We still need these header files,
	# even if we are not going to link with SDL.
	# We have them available anyway (mingwlibs).
	# OS X:
	# Cocoa requires the SDL libary, whenever the SDL headers are used,
	# due to some #define magic, which is practically impossible to workaround.
	FIND_PACKAGE(SDL2 REQUIRED)
	INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR})
	if("${SDL2_VERSION_STRING}" VERSION_LESS "2")
		message(FATAL_ERROR "Found SDL v${SDL2_VERSION_STRING} while 2 is required!")
	endif()
ELSE  (MINGW OR APPLE)
	# Use a direct copy of the GL and SDL headers,
	# as these may not be available on headless systems.
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include/SDL2)
ENDIF (MINGW OR APPLE)


### Assemble the incude dirs
INCLUDE_DIRECTORIES(${ENGINE_SRC_ROOT_DIR}/)
INCLUDE_DIRECTORIES(${ENGINE_SRC_ROOT_DIR}/lib/lua/include)
INCLUDE_DIRECTORIES(${ENGINE_SRC_ROOT_DIR}/lib/7zip)
INCLUDE_DIRECTORIES(${ENGINE_SRC_ROOT_DIR}/lib/asio/include)


### Assemble sources
IF	(APPLE)
	SET(sources_engine_Platform_CrashHandler
		${ENGINE_SRC_ROOT_DIR}/System/Platform/CpuID.cpp
		${ENGINE_SRC_ROOT_DIR}/System/Platform/Threading.cpp
		${ENGINE_SRC_ROOT_DIR}/System/Platform/Mac/CrashHandler.cpp)
ELSEIF	(WIN32)
	SET(sources_engine_Platform_CrashHandler
		${ENGINE_SRC_ROOT_DIR}/System/Platform/Win/seh.cpp
		${ENGINE_SRC_ROOT_DIR}/System/Platform/Win/CrashHandler.cpp)
ELSE	()
	SET(sources_engine_Platform_CrashHandler
		#${ENGINE_SRC_ROOT_DIR}/System/Platform/CpuID.cpp
		${ENGINE_SRC_ROOT_DIR}/System/Platform/Threading.cpp
		#${ENGINE_SRC_ROOT_DIR}/System/Platform/Linux/CrashHandler.cpp
		#${ENGINE_SRC_ROOT_DIR}/System/Platform/Linux/ThreadSupport.cpp
		)
ENDIF	()

SET(system_files
	${sources_engine_System_FileSystem}
	${sources_engine_System_Threading}
	${sources_engine_System_Log}
	${sources_engine_Platform_CrashHandler}
	#${ENGINE_SRC_ROOT_DIR}/Net/AutohostInterface.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Config/ConfigHandler.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Config/ConfigLocater.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Config/ConfigSource.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Config/ConfigVariable.cpp
	${ENGINE_SRC_ROOT_DIR}/System/CRC.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Platform/errorhandler.cpp
	#${ENGINE_SRC_ROOT_DIR}/System/Platform/CpuID.cpp
	#${ENGINE_SRC_ROOT_DIR}/System/Platform/Misc.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Platform/ScopedFileLock.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Platform/Threading.cpp
	${ENGINE_SRC_ROOT_DIR}/System/TdfParser.cpp
	#${ENGINE_SRC_ROOT_DIR}/System/GlobalConfig.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Info.cpp
	${ENGINE_SRC_ROOT_DIR}/System/LogOutput.cpp
	${ENGINE_SRC_ROOT_DIR}/System/TimeUtil.cpp
	${ENGINE_SRC_ROOT_DIR}/System/LoadSave/Demo.cpp
	${ENGINE_SRC_ROOT_DIR}/System/LoadSave/DemoReader.cpp
	${ENGINE_SRC_ROOT_DIR}/System/LoadSave/DemoRecorder.cpp
	${ENGINE_SRC_ROOT_DIR}/System/SafeCStrings.c
	${ENGINE_SRC_ROOT_DIR}/System/SafeVector.cpp
	${ENGINE_SRC_ROOT_DIR}/System/UriParser.cpp
	${ENGINE_SRC_ROOT_DIR}/System/StringUtil.cpp
	${ENGINE_SRC_ROOT_DIR}/System/float4.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Log/Backend.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Log/DefaultFilter.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Log/DefaultFormatter.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Log/FramePrefixer.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Log/LogSinkHandler.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Log/LogUtil.c
	${ENGINE_SRC_ROOT_DIR}/System/Log/ConsoleSink.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Misc/SpringTime.cpp
	)
IF    (WIN32)
	LIST(APPEND system_files ${ENGINE_SRC_ROOT_DIR}/System/Platform/Win/WinVersion.cpp)
ENDIF (WIN32)

#SET(libSim
add_library(engineSim2 STATIC
		"${CMAKE_CURRENT_SOURCE_DIR}/Features/Feature.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Features/FeatureDef.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Features/FeatureDefHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Features/FeatureHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/AllyTeam.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/BuildingMaskMap.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/CategoryHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/CollisionHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/CollisionVolume.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/CommonDefHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/DamageArray.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/DamageArrayHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/DefinitionTag.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/GeometricObjects.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/GlobalSynced.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/GroundBlockingObjectMap.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/InterceptHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/LosHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/LosMap.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/ModInfo.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/NanoPieceCache.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/QuadField.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/Resource.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/ResourceHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/ResourceMapAnalyzer.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/SideParser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/SimObjectIDPool.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/SmoothHeightMesh.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/Team.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/TeamBase.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/TeamHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/TeamStatistics.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/Wind.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/AAirMoveType.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/StrafeAirMoveType.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/GroundMoveType.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/MoveDefHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/MoveMath/GroundMoveMath.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/MoveMath/HoverMoveMath.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/MoveMath/MoveMath.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/MoveMath/ShipMoveMath.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/MoveType.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/MoveTypeFactory.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/ScriptMoveType.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/StaticMoveType.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MoveTypes/HoverAirMoveType.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Objects/SolidObject.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Objects/SolidObjectDef.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Objects/WorldObject.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/Default/IPathFinder.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/Default/PathCache.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/Default/PathEstimator.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/Default/PathFinder.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/Default/PathFinderDef.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/Default/PathFlowMap.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/Default/PathHeatMap.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/Default/PathManager.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/QTPFS/Node.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/QTPFS/NodeLayer.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/QTPFS/PathCache.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/QTPFS/PathSearch.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/QTPFS/PathManager.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/IPathController.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Path/IPathManager.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/ExpGenSpawnable.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/ExpGenSpawner.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/ExplosionListener.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/ExplosionGenerator.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/FireProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/FlareProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/PieceProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/Projectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/ProjectileHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/ProjectileFunctors.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/BeamLaserProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/EmgProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/ExplosiveProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/FireBallProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/FlameProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/LargeBeamLaserProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/LaserProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/LightningProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/MissileProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/StarburstProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/TorpedoProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/WeaponProjectile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Projectiles/WeaponProjectiles/WeaponProjectileFactory.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/BuildInfo.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/CommandAI/AirCAI.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/CommandAI/BuilderCAI.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/CommandAI/Command.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/CommandAI/CommandAI.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/CommandAI/CommandDescription.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/CommandAI/FactoryCAI.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/CommandAI/MobileCAI.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/CobEngine.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/CobFile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/CobInstance.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/CobScriptNames.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/CobThread.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/LuaScriptNames.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/LuaUnitScript.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/NullUnitScript.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/UnitScript.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/UnitScriptEngine.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Scripts/UnitScriptFactory.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/Unit.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/UnitDef.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/UnitDefHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/UnitHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/UnitLoader.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/UnitTypes/Builder.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/UnitTypes/Building.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/UnitTypes/ExtractorBuilding.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Units/UnitTypes/Factory.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/BeamLaser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/BombDropper.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/Cannon.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/DGunWeapon.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/EmgCannon.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/FlameThrower.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/LaserCannon.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/LightningCannon.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/MeleeWeapon.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/MissileLauncher.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/NoWeapon.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/PlasmaRepulser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/Rifle.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/StarburstLauncher.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/TorpedoLauncher.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/Weapon.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/WeaponDef.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/WeaponDefHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/WeaponLoader.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Weapons/WeaponTarget.cpp"
		)
		
SET(system_files_for_Sim
	${ENGINE_SRC_ROOT_DIR}/System/CRC.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Color.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Config/ConfigHandler.cpp
	${ENGINE_SRC_ROOT_DIR}/System/EventClient.cpp
	#${ENGINE_SRC_ROOT_DIR}/System/EventHandler.cpp
	${ENGINE_SRC_ROOT_DIR}/System/FileSystem/ArchiveLoader.cpp
	${ENGINE_SRC_ROOT_DIR}/System/FileSystem/ArchiveScanner.cpp
	${ENGINE_SRC_ROOT_DIR}/System/FileSystem/Archives/IArchive.cpp
	${ENGINE_SRC_ROOT_DIR}/System/FileSystem/DataDirsAccess.cpp
	${ENGINE_SRC_ROOT_DIR}/System/FileSystem/FileHandler.cpp
	${ENGINE_SRC_ROOT_DIR}/System/FileSystem/FileSystem.cpp
	${ENGINE_SRC_ROOT_DIR}/System/FileSystem/FileSystemInitializer.cpp
	${ENGINE_SRC_ROOT_DIR}/System/FileSystem/VFSHandler.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Log/DefaultFilter.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Log/FramePrefixer.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Matrix44f.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Object.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Platform/Threading.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Platform/Watchdog.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Rectangle.cpp
	${ENGINE_SRC_ROOT_DIR}/System/SafeVector.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Sound/ISound.cpp
	${ENGINE_SRC_ROOT_DIR}/System/StringUtil.cpp
	#${ENGINE_SRC_ROOT_DIR}/System/Sync/SHA512.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Sync/SyncTracer.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Sync/SyncedFloat3.cpp
	${ENGINE_SRC_ROOT_DIR}/System/Threading/ThreadPool.cpp
	${ENGINE_SRC_ROOT_DIR}/System/TimeProfiler.cpp
	${ENGINE_SRC_ROOT_DIR}/System/float3.cpp
	${ENGINE_SRC_ROOT_DIR}/System/float4.cpp
	${ENGINE_SRC_ROOT_DIR}/System/myMath.cpp
	#${ENGINE_SRC_ROOT_DIR}/System/type2.cpp
	)
SET(luafiles
	#${ENGINE_SRC_ROOT_DIR}/Lua/LuaHandleSynced.cpp
	#${ENGINE_SRC_ROOT_DIR}/Lua/LuaParser.cpp
	${ENGINE_SRC_ROOT_DIR}/Lua/LuaRules.cpp
	${ENGINE_SRC_ROOT_DIR}/Lua/LuaRulesParams.cpp
	${ENGINE_SRC_ROOT_DIR}/Lua/LuaSyncedRead.cpp
	#${ENGINE_SRC_ROOT_DIR}/Lua/LuaUtils.cpp
		)

SET(engineDedicatedSources
	${system_files}
	#${sources_engine_NetServer}
	${sources_engine_System_Log}
	${ENGINE_SRC_ROOT_DIR}/Game/ClientSetup.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/GameSetup.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/GameData.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/Players/PlayerBase.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/Players/PlayerStatistics.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/GameVersion.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/IVideoCapturing.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/DummyVideoCapturing.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/CommandMessage.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/ChatMessage.cpp
	${ENGINE_SRC_ROOT_DIR}/Game/Action.cpp
	${ENGINE_SRC_ROOT_DIR}/Sim/Misc/TeamBase.cpp
	${ENGINE_SRC_ROOT_DIR}/Sim/Misc/TeamStatistics.cpp
	${ENGINE_SRC_ROOT_DIR}/Sim/Misc/AllyTeam.cpp
	${ENGINE_SRC_ROOT_DIR}/Lua/LuaConstEngine.cpp
	${ENGINE_SRC_ROOT_DIR}/Lua/LuaIO.cpp
	${ENGINE_SRC_ROOT_DIR}/Lua/LuaMemPool.cpp
	${ENGINE_SRC_ROOT_DIR}/Lua/LuaParser.cpp
	${ENGINE_SRC_ROOT_DIR}/Lua/LuaUtils.cpp
	${ENGINE_SRC_ROOT_DIR}/Map/MapParser.cpp
	)


# Compile dedicated server executable
ADD_LIBRARY(engine-dedicated2 STATIC
		${ENGINE_SRC_ROOT_DIR}/Map/MapParser.cpp
		${engineDedicatedSources}
		${sources_engine_System_Log_sinkConsole}
		${sources_engine_System_Log_sinkFile}
		${sources_engine_System_Log_sinkOutputDebugString}
		${ENGINE_ICON}
		${engineSim2}
		${system_files_for_Sim}
		${luafiles}
	)
TARGET_LINK_LIBRARIES(engine-dedicated2 ${engineDedicatedLibraries})
IF    (MINGW)
	TARGET_LINK_LIBRARIES(engine-dedicated2 ${WS2_32_LIBRARY} ${IMAGEHLP_LIBRARY} ${WINMM_LIBRARY})
ENDIF (MINGW)
IF    (MSVC)
	TARGET_LINK_LIBRARIES(engine-dedicated2 ${DBGHELP_LIBRARY})
ENDIF (MSVC)
Add_Dependencies(engine-dedicated2 generateVersionFiles)

#INSTALL(TARGETS engine-dedicated2 DESTINATION ${BINDIR})

# Only build & install spring-dedicated executable & dependencies
# use cases:
# * make spring-dedicated
# * make install-spring-dedicated
CreateEngineBuildAndInstallTarget(dedicated2)

