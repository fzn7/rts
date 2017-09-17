/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/GL/myGL.h"

#include <SDL_keyboard.h>

#include "Game.h"
#include "GameJobDispatcher.h"
#include "Benchmark.h"
#include "Camera.h"
#include "CameraHandler.h"
#include "ChatMessage.h"
#include "CommandMessage.h"
#include "ConsoleHistory.h"
#include "GameHelper.h"
#include "GameSetup.h"
#include "GlobalUnsynced.h"
#include "LoadScreen.h"
#include "SelectedUnitsHandler.h"
#include "WaitCommandsAI.h"
#include "WordCompletion.h"
#include "IVideoCapturing.h"
#include "InMapDraw.h"
#include "InMapDrawModel.h"
#include "SyncedActionExecutor.h"
#include "SyncedGameCommands.h"
#include "UnsyncedActionExecutor.h"
#include "UnsyncedGameCommands.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/UI/PlayerRoster.h"
#include "Game/UI/PlayerRosterDrawer.h"
#include "Game/UI/UnitTracker.h"
#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Rendering/WorldDrawer.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/Fonts/CFontTexture.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/CommandDrawer.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/DebugDrawerAI.h"
#include "Rendering/HUDDrawer.h"
#include "Rendering/IconHandler.h"
#include "Rendering/TeamHighlight.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Lua/LuaInputReceiver.h"
#include "Lua/LuaHandle.h"
#include "Lua/LuaGaia.h"
#include "Lua/LuaRules.h"
#include "Lua/LuaOpenGL.h"
#include "Lua/LuaParser.h"
#include "Lua/LuaSyncedRead.h"
#include "Lua/LuaUI.h"
#include "Lua/LuaUtils.h"
#include "Map/MapDamage.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/BuildingMaskMap.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/InterceptHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/SideParser.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Misc/ResourceHandler.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Scripts/CobEngine.h"
#include "Sim/Units/Scripts/UnitScriptEngine.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "UI/CommandColors.h"
#include "UI/EndGameBox.h"
#include "UI/GameInfo.h"
#include "UI/GameSetupDrawer.h"
#include "UI/GuiHandler.h"
#include "UI/InfoConsole.h"
#include "UI/KeyBindings.h"
#include "UI/KeyCodes.h"
#include "UI/MiniMap.h"
#include "UI/MouseHandler.h"
#include "UI/QuitBox.h"
#include "UI/ResourceBar.h"
#include "UI/SelectionKeyHandler.h"
#include "UI/ShareBox.h"
#include "UI/TooltipConsole.h"
#include "UI/ProfileDrawer.h"
#include "UI/Groups/GroupHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Sync/FPUCheck.h"
#include "System/GlobalConfig.h"
#include "System/myMath.h"
#include "Net/GameServer.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/SpringApp.h"
#include "System/Util.h"
#include "System/Input/KeyInput.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/LoadSave/LoadSaveHandler.h"
#include "System/LoadSave/DemoRecorder.h"
#include "System/Log/ILog.h"
#include "System/Platform/Watchdog.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/DumpState.h"
#include "System/TimeProfiler.h"


#undef CreateDirectory

CONFIG(bool, WindowedEdgeMove).defaultValue(true).description("Sets whether moving the mouse cursor to the screen edge will move the camera across the map.");
CONFIG(bool, FullscreenEdgeMove).defaultValue(true).description("see WindowedEdgeMove, just for fullscreen mode");
CONFIG(bool, ShowFPS).defaultValue(false).description("Displays current framerate.");
CONFIG(bool, ShowClock).defaultValue(true).headlessValue(false).description("Displays a clock on the top-right corner of the screen showing the elapsed time of the current game.");
CONFIG(bool, ShowSpeed).defaultValue(false).description("Displays current game speed.");
CONFIG(int, ShowPlayerInfo).defaultValue(1).headlessValue(0);
CONFIG(float, GuiOpacity).defaultValue(0.8f).minimumValue(0.0f).maximumValue(1.0f).description("Sets the opacity of the built-in Spring UI. Generally has no effect on LuaUI widgets. Can be set in-game using shift+, to decrease and shift+. to increase.");
CONFIG(std::string, InputTextGeo).defaultValue("");


CGame* game = NULL;


CR_BIND(CGame, (std::string(""), std::string(""), NULL))

CR_REG_METADATA(CGame, (
	CR_IGNORED(finishedLoading),
	CR_IGNORED(numDrawFrames),
	CR_MEMBER(lastSimFrame),
	CR_IGNORED(lastNumQueuedSimFrames),
	CR_IGNORED(frameStartTime),
	CR_IGNORED(lastSimFrameTime),
	CR_IGNORED(lastDrawFrameTime),
	CR_IGNORED(lastFrameTime),
	CR_IGNORED(lastReadNetTime),
	CR_IGNORED(lastNetPacketProcessTime),
	CR_IGNORED(lastReceivedNetPacketTime),
	CR_IGNORED(lastSimFrameNetPacketTime),
	CR_IGNORED(updateDeltaSeconds),
	CR_MEMBER(totalGameTime),
	CR_MEMBER(userInputPrefix),
	CR_IGNORED(chatSound),
	CR_MEMBER(hideInterface),
	CR_MEMBER(gameOver),
	CR_IGNORED(gameDrawMode),
	CR_IGNORED(windowedEdgeMove),
	CR_IGNORED(fullscreenEdgeMove),
	CR_MEMBER(showFPS),
	CR_MEMBER(showClock),
	CR_MEMBER(showSpeed),
	CR_IGNORED(chatting),
	CR_IGNORED(curKeyChain),
	CR_IGNORED(playerTraffic),
	CR_MEMBER(noSpectatorChat),
	CR_MEMBER(gameID),
	//CR_MEMBER(infoConsole),
	//CR_MEMBER(consoleHistory),
	CR_IGNORED(inputTextPosX),
	CR_IGNORED(inputTextPosY),
	CR_IGNORED(inputTextSizeX),
	CR_IGNORED(inputTextSizeY),
	CR_IGNORED(skipping),
	CR_MEMBER(playing),
	CR_IGNORED(msgProcTimeLeft),
	CR_IGNORED(consumeSpeedMult),

	CR_IGNORED(skipStartFrame),
	CR_IGNORED(skipEndFrame),
	CR_IGNORED(skipTotalFrames),
	CR_IGNORED(skipSeconds),
	CR_IGNORED(skipSoundmute),
	CR_IGNORED(skipOldSpeed),
	CR_IGNORED(skipOldUserSpeed),
	CR_IGNORED(skipLastDrawTime),

	CR_MEMBER(speedControl),

	CR_IGNORED(infoConsole),
	CR_IGNORED(consoleHistory),
	CR_IGNORED(jobDispatcher),
	CR_IGNORED(worldDrawer),
	CR_IGNORED(defsParser),
	CR_IGNORED(saveFile),

	// from CGameController
	CR_IGNORED(writingPos),
	CR_IGNORED(ignoreNextChar),
	CR_IGNORED(userInput),
	CR_IGNORED(userPrompt),
	CR_IGNORED(userWriting),

	// Post Load
	CR_POSTLOAD(PostLoad)
))



CGame::CGame(const std::string& mapName, const std::string& modName, ILoadSaveHandler* saveFile)
	: gameDrawMode(gameNotDrawing)
	, lastSimFrame(-1)
	, lastNumQueuedSimFrames(-1)
	, numDrawFrames(0)
	, frameStartTime(spring_gettime())
	, lastSimFrameTime(spring_gettime())
	, lastDrawFrameTime(spring_gettime())
	, lastFrameTime(spring_gettime())
	, lastReadNetTime(spring_gettime())
	, lastNetPacketProcessTime(spring_gettime())
	, lastReceivedNetPacketTime(spring_gettime())
	, lastSimFrameNetPacketTime(spring_gettime())
	, updateDeltaSeconds(0.0f)
	, totalGameTime(0)
	, hideInterface(false)
	, skipping(false)
	, playing(false)
	, chatting(false)
	, noSpectatorChat(false)
	, msgProcTimeLeft(0.0f)
	, consumeSpeedMult(1.0f)
	, skipStartFrame(0)
	, skipEndFrame(0)
	, skipTotalFrames(0)
	, skipSeconds(0.0f)
	, skipSoundmute(false)
	, skipOldSpeed(0.0f)
	, skipOldUserSpeed(0.0f)
	, skipLastDrawTime(spring_gettime())
	, speedControl(-1)
	, infoConsole(NULL)
	, consoleHistory(NULL)
	, worldDrawer(NULL)
	, defsParser(NULL)
	, saveFile(saveFile)
	, finishedLoading(false)
	, gameOver(false)
{
    //stub method
}

CGame::~CGame()
{
    //stub method
}


void CGame::AddTimedJobs()
{
    //stub method
}

void CGame::LoadGame(const std::string& mapName, bool threaded)
{
    //stub method
}


void CGame::LoadMap(const std::string& mapName)
{
    //stub method
}


void CGame::LoadDefs()
{
    //stub method
}

void CGame::PreLoadSimulation()
{
    //stub method
}

void CGame::PostLoadSimulation()
{
    //stub method
}

void CGame::PreLoadRendering()
{
    //stub method
}

void CGame::PostLoadRendering() {
	worldDrawer->LoadPost();
}


void CGame::LoadInterface()
{
    //stub method
}

void CGame::LoadLua()
{
    //stub method
}

void CGame::LoadSkirmishAIs()
{
    //stub method
}

void CGame::LoadFinalize()
{
    //stub method
}


void CGame::PostLoad()
{
    //stub method
}


void CGame::KillLua()
{
    //stub method
}

void CGame::KillMisc()
{
    //stub method
}

void CGame::KillRendering()
{
    //stub method
}

void CGame::KillInterface()
{
    //stub method
}

void CGame::KillSimulation()
{
    //stub method
}





void CGame::ResizeEvent()
{
    //stub method
}


int CGame::KeyPressed(int key, bool isRepeat)
{
    //stub method
}


int CGame::KeyReleased(int k)
{
    //stub method
}



bool CGame::Update()
{
    //stub method
}


bool CGame::UpdateUnsynced(const spring_time currentTime)
{
    //stub method
}


bool CGame::Draw() {
	const spring_time currentTimePreUpdate = spring_gettime();

	if (UpdateUnsynced(currentTimePreUpdate))
		return true;

	const bool doDrawWorld = hideInterface || !minimap->GetMaximized() || minimap->GetMinimized();
	const spring_time currentTimePreDraw = spring_gettime();

	{
		SCOPED_GMARKER("Game::DrawGenesis");
		eventHandler.DrawGenesis();
	}

	if (!globalRendering->active) {
		spring_sleep(spring_msecs(10));

		// return early if and only if less than 30K milliseconds have passed since last draw-frame
		// so we force render two frames per minute when minimized to clear batches and free memory
		// don't need to mess with globalRendering->active since only mouse-input code depends on it
		if ((currentTimePreDraw - lastDrawFrameTime).toSecsi() < 30)
			return true;
	}

	if (globalRendering->drawdebug) {
		const float deltaFrameTime = (currentTimePreUpdate - lastSimFrameTime).toMilliSecsf();
		const float deltaNetPacketProcTime  = (currentTimePreUpdate - lastNetPacketProcessTime ).toMilliSecsf();
		const float deltaReceivedPacketTime = (currentTimePreUpdate - lastReceivedNetPacketTime).toMilliSecsf();
		const float deltaSimFramePacketTime = (currentTimePreUpdate - lastSimFrameNetPacketTime).toMilliSecsf();

		const float currTimeOffset = globalRendering->timeOffset;
		static float lastTimeOffset = globalRendering->timeOffset;
		static int lastGameFrame = gs->frameNum;

		static const char* minFmtStr = "assert(CTO >= 0.0f) failed (SF=%u : DF=%u : CTO=%f : WSF=%f : DT=%fms : DLNPPT=%fms | DLRPT=%fms | DSFPT=%fms : NP=%u)";
		static const char* maxFmtStr = "assert(CTO <= 1.3f) failed (SF=%u : DF=%u : CTO=%f : WSF=%f : DT=%fms : DLNPPT=%fms | DLRPT=%fms | DSFPT=%fms : NP=%u)";

		// CTO = MILLISECSF(CT - LSFT) * WSF = MILLISECSF(CT - LSFT) * (SFPS * 0.001)
		// AT 30Hz LHS (MILLISECSF(CT - LSFT)) SHOULD BE ~33ms, RHS SHOULD BE ~0.03
		assert(currTimeOffset >= 0.0f);

		if (currTimeOffset < 0.0f) LOG_L(L_ERROR, minFmtStr, gs->frameNum, globalRendering->drawFrame, currTimeOffset, globalRendering->weightedSpeedFactor, deltaFrameTime, deltaNetPacketProcTime, deltaReceivedPacketTime, deltaSimFramePacketTime, clientNet->GetNumWaitingServerPackets());
		if (currTimeOffset > 1.3f) LOG_L(L_ERROR, maxFmtStr, gs->frameNum, globalRendering->drawFrame, currTimeOffset, globalRendering->weightedSpeedFactor, deltaFrameTime, deltaNetPacketProcTime, deltaReceivedPacketTime, deltaSimFramePacketTime, clientNet->GetNumWaitingServerPackets());

		// test for monotonicity, normally should only fail
		// when SimFrame() advances time or if simframe rate
		// changes
		if (lastGameFrame == gs->frameNum && currTimeOffset < lastTimeOffset)
			LOG_L(L_ERROR, "assert(CTO >= LTO) failed (SF=%u : DF=%u : CTO=%f : LTO=%f : WSF=%f : DT=%fms)", gs->frameNum, globalRendering->drawFrame, currTimeOffset, lastTimeOffset, globalRendering->weightedSpeedFactor, deltaFrameTime);

		lastTimeOffset = currTimeOffset;
		lastGameFrame = gs->frameNum;
	}

	//FIXME move both to UpdateUnsynced?
	CTeamHighlight::Enable(spring_tomsecs(currentTimePreDraw));
	if (unitTracker.Enabled()) {
		unitTracker.SetCam();
	}

	{
		SCOPED_TIMER("Game::DrawWorld");
		SCOPED_GMARKER("Game::DrawWorld");

		minimap->Update();

		if (doDrawWorld)
			worldDrawer->GenerateIBLTextures();

		camera->Update();

		if (doDrawWorld)
			worldDrawer->Draw();

		worldDrawer->ResetMVPMatrices();
	}

	{
		SCOPED_TIMER("Game::DrawScreen");
		SCOPED_GMARKER("Game::DrawScreen");

		if (doDrawWorld)
			eventHandler.DrawScreenEffects();

		hudDrawer->Draw((gu->GetMyPlayer())->fpsController.GetControllee());
		debugDrawerAI->Draw();

		DrawInputReceivers();
		DrawInputText();
		DrawInterfaceWidgets();
		mouse->DrawCursor();
	}

	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();

	videoCapturing->RenderFrame();

	SetDrawMode(gameNotDrawing);
	CTeamHighlight::Disable();

	const spring_time currentTimePostDraw = spring_gettime();
	const spring_time currentFrameDrawTime = currentTimePostDraw - currentTimePreDraw;
	gu->avgDrawFrameTime = mix(gu->avgDrawFrameTime, currentFrameDrawTime.toMilliSecsf(), 0.05f);

	eventHandler.DbgTimingInfo(TIMING_VIDEO, currentTimePreDraw, currentTimePostDraw);

	return true;
}


void CGame::DrawInputReceivers()
{
    //stub method
}

void CGame::DrawInterfaceWidgets()
{
    //stub method
}


void CGame::ParseInputTextGeometry(const string& geo)
{
    //stub method
}


void CGame::DrawInputText()
{
    //stub method
}


void CGame::StartPlaying()
{
    //stub method
}



void CGame::SimFrame() {
	ENTER_SYNCED_CODE();

	good_fpu_control_registers("CGame::SimFrame");

	// note: starts at -1, first actual frame is 0
	gs->frameNum += 1;
	lastFrameTime = spring_gettime();

	// clear allocator statistics periodically
	// note: allocator itself should do this (so that
	// stats are reliable when paused) but see LuaUser
	spring_lua_alloc_update_stats((gs->frameNum % GAME_SPEED) == 0);

#ifdef TRACE_SYNC
	tracefile << "New frame:" << gs->frameNum << " " << gs->GetRandSeed() << "\n";
#endif

	if (!skipping) {
		// everything here is unsynced and should ideally moved to Game::Update()
		waitCommandsAI.Update();
		geometricObjects->Update();
		sound->NewFrame();
		eoh->Update();

		for (size_t a = 0; a < grouphandlers.size(); a++)
			grouphandlers[a]->Update();

		(playerHandler->Player(gu->myPlayerNum)->fpsController).SendStateUpdate(/*camera->GetMovState(), mouse->buttons*/);

		CTeamHighlight::Update(gs->frameNum);
	}

	// everything from here is simulation
	{
		SCOPED_TIMER("EventHandler::GameFrame");
		eventHandler.GameFrame(gs->frameNum);
	}
	{
		SCOPED_TIMER("SimFrame");
		helper->Update();
		mapDamage->Update();
		pathManager->Update();
		unitHandler->Update();
		projectileHandler->Update();
		featureHandler->Update();
		cobEngine->Tick(33);
		unitScriptEngine->Tick(33);
		wind.Update();
		losHandler->Update();
		// dead ghosts have to be updated in sim, after los,
		// to make sure they represent the current knowledge correctly.
		// should probably be split from drawer
		unitDrawer->UpdateGhostedBuildings();
		interceptHandler.Update(false);

		teamHandler->GameFrame(gs->frameNum);
		playerHandler->GameFrame(gs->frameNum);
	}

	lastSimFrameTime = spring_gettime();
	gu->avgSimFrameTime = mix(gu->avgSimFrameTime, (lastSimFrameTime - lastFrameTime).toMilliSecsf(), 0.05f);
	gu->avgSimFrameTime = std::max(gu->avgSimFrameTime, 0.001f);

	eventHandler.DbgTimingInfo(TIMING_SIM, lastFrameTime, lastSimFrameTime);

	#ifdef HEADLESS
	{
		const float msecMaxSimFrameTime = 1000.0f / (GAME_SPEED * gs->wantedSpeedFactor);
		const float msecDifSimFrameTime = (lastSimFrameTime - lastFrameTime).toMilliSecsf();
		// multiply by 0.5 to give unsynced code some execution time (50% of our sleep-budget)
		const float msecSleepTime = (msecMaxSimFrameTime - msecDifSimFrameTime) * 0.5f;

		if (msecSleepTime > 0.0f) {
			spring_sleep(spring_msecs(msecSleepTime));
		}
	}
	#endif

	// useful for desync-debugging (enter instead of -1 start & end frame of the range you want to debug)
	DumpState(-1, -1, 1);

	LEAVE_SYNCED_CODE();
}


void CGame::GameEnd(const std::vector<unsigned char>& winningAllyTeams, bool timeout)
{
    //stub method
}

void CGame::SendNetChat(std::string message, int destination)
{
    //stub method
}


void CGame::HandleChatMsg(const ChatMessage& msg)
{
    //stub method
}



void CGame::StartSkip(int toFrame) {
	return; // FIXME: desyncs

	if (skipping) {
		LOG_L(L_ERROR, "skipping appears to be busted (%i)", skipping);
	}

	skipStartFrame = gs->frameNum;
	skipEndFrame = toFrame;

	if (skipEndFrame <= skipStartFrame) {
		LOG_L(L_WARNING, "Already passed %i (%i)", skipEndFrame / GAME_SPEED, skipEndFrame);
		return;
	}

	skipTotalFrames = skipEndFrame - skipStartFrame;
	skipSeconds = skipTotalFrames / float(GAME_SPEED);

	skipSoundmute = sound->IsMuted();
	if (!skipSoundmute)
		sound->Mute(); // no sounds

	//FIXME not smart to change SYNCED values in demo playbacks etc.
	skipOldSpeed     = gs->speedFactor;
	skipOldUserSpeed = gs->wantedSpeedFactor;
	const float speed = 1.0f;
	gs->speedFactor     = speed;
	gs->wantedSpeedFactor = speed;

	skipLastDrawTime = spring_gettime();

	skipping = true;
}

void CGame::EndSkip() {
	return; // FIXME
/*
	skipping = false;

	gu->gameTime    += skipSeconds;
	gu->modGameTime += skipSeconds;

	gs->speedFactor     = skipOldSpeed;
	gs->wantedSpeedFactor = skipOldUserSpeed;

	if (!skipSoundmute) {
		sound->Mute(); // sounds back on
	}

	LOG("Skipped %.1f seconds", skipSeconds);
*/
}



void CGame::DrawSkip(bool blackscreen) {
	const int framesLeft = (skipEndFrame - gs->frameNum);
	if (blackscreen) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glColor3f(0.5f, 1.0f, 0.5f);
	font->glFormat(0.5f, 0.55f, 2.5f, FONT_CENTER | FONT_SCALE | FONT_NORM, "Skipping %.1f game seconds", skipSeconds);
	glColor3f(1.0f, 1.0f, 1.0f);
	font->glFormat(0.5f, 0.45f, 2.0f, FONT_CENTER | FONT_SCALE | FONT_NORM, "(%i frames left)", framesLeft);

	const float ff = (float)framesLeft / (float)skipTotalFrames;
	glDisable(GL_TEXTURE_2D);
	const float b = 0.004f; // border
	const float yn = 0.35f;
	const float yp = 0.38f;
	glColor3f(0.2f, 0.2f, 1.0f);
	glRectf(0.25f - b, yn - b, 0.75f + b, yp + b);
	glColor3f(0.25f + (0.75f * ff), 1.0f - (0.75f * ff), 0.0f);
	glRectf(0.5 - (0.25f * ff), yn, 0.5f + (0.25f * ff), yp);
}



void CGame::ReloadCOB(const string& msg, int player)
{
    //stub method
}


//FIXME remove!
void CGame::ReColorTeams()
{
    //stub method
}

bool CGame::IsLagging(float maxLatency) const
{
    //stub method
}


void CGame::SaveGame(const std::string& filename, bool overwrite, bool usecreg)
{
    //stub method
}


void CGame::ReloadGame()
{
    //stub method
}




bool CGame::ProcessCommandText(unsigned int key, const std::string& command) {
	if (command.size() <= 2)
		return false;

	if ((command[0] == '/') && (command[1] != '/')) {
		// strip the '/'
		const Action fakeAction(command.substr(1));

		ProcessAction(fakeAction, key, false);
		return true;
	}

	return false;
}

bool CGame::ProcessKeyPressAction(unsigned int key, const Action& action) {
	if (!userWriting)
		return false;

	if (action.command == "pastetext") {
		//we cannot use extra commands because tokenization strips multiple spaces
		//or even trailing spaces, the text should be copied verbatim
		const std::string pastecommand = "pastetext ";

		if (action.rawline.length() > pastecommand.length()) {
			userInput.insert(writingPos, action.rawline.substr(pastecommand.length(), action.rawline.length() - pastecommand.length()));
			writingPos += (action.rawline.length() - pastecommand.length());
		} else {
			PasteClipboard();
		}

		return true;
	}

	if (action.command.find("edit_") == 0) {
		if (action.command == "edit_return") {
			userWriting = false;
			writingPos = 0;

			if (chatting) {
				string command;

				if ((userInput.find_first_of("aAsS") == 0) && (userInput[1] == ':')) {
					command = userInput.substr(2);
				} else {
					command = userInput;
				}

				if (ProcessCommandText(key, command)) {
					// execute an action
					consoleHistory->AddLine(command);
					LOG_L(L_DEBUG, "%s", command.c_str());

					chatting = false;
					userInput = "";
					writingPos = 0;
				}
			}

			return true;
		}

		if (action.command == "edit_escape") {
			if (chatting || inMapDrawer->IsWantLabel()) {
				if (chatting) {
					consoleHistory->AddLine(userInput);
				}
				userWriting = false;
				chatting = false;
				inMapDrawer->SetWantLabel(false);
				userInput = "";
				writingPos = 0;
			}

			return true;
		}

		if (action.command == "edit_complete") {
			string head = userInput.substr(0, writingPos);
			string tail = userInput.substr(writingPos);

			// fills head with the first partial match
			const vector<string>& partials = wordCompletion->Complete(head);

			userInput = head + tail;
			writingPos = head.length();

			if (!partials.empty()) {
				string msg;
				for (unsigned int i = 0; i < partials.size(); i++) {
					msg += "  ";
					msg += partials[i];
				}
				LOG("%s", msg.c_str());
			}

			return true;
		}


		if (action.command == "edit_backspace") {
			if (!userInput.empty() && (writingPos > 0)) {
				const int prev = Utf8PrevChar(userInput, writingPos);
				userInput.erase(prev, writingPos - prev);
				writingPos = prev;
			}

			return true;
		}

		if (action.command == "edit_delete") {
			if (!userInput.empty() && (writingPos < (int)userInput.size())) {
				userInput.erase(writingPos, Utf8CharLen(userInput, writingPos));
			}

			return true;
		}


		if (action.command == "edit_home") {
			writingPos = 0;
			return true;
		}

		if (action.command == "edit_end") {
			writingPos = userInput.length();
			return true;
		}


		if (action.command == "edit_prev_char") {
			writingPos = Utf8PrevChar(userInput, writingPos);
			return true;
		}

		if (action.command == "edit_next_char") {
			writingPos = Utf8NextChar(userInput, writingPos);
			return true;
		}


		if (action.command == "edit_prev_word") { //TODO don't seems to work correctly with utf-8
			// prev word
			const char* s = userInput.c_str();
			int p = writingPos;
			while ((p > 0) && !isalnum(s[p - 1])) { p--; }
			while ((p > 0) &&  isalnum(s[p - 1])) { p--; }
			writingPos = p;
			return true;
		}

		if (action.command == "edit_next_word") { //TODO don't seems to work correctly with utf-8
			const size_t len = userInput.length();
			const char* s = userInput.c_str();
			size_t p = writingPos;
			while ((p < len) && !isalnum(s[p])) { p++; }
			while ((p < len) &&  isalnum(s[p])) { p++; }
			writingPos = p;
			return true;
		}


		if ((action.command == "edit_prev_line") && chatting) {
			userInput = consoleHistory->PrevLine(userInput);
			writingPos = (int)userInput.length();
			return true;
		}

		if ((action.command == "edit_next_line") && chatting) {
			userInput = consoleHistory->NextLine(userInput);
			writingPos = (int)userInput.length();
			return true;
		}

		// unknown edit-command
		return false;
	}


	if (action.command.find("chatswitch") == 0) {
		if (action.command == "chatswitchall") {
			if ((userInput.find_first_of("aAsS") == 0) && (userInput[1] == ':')) {
				userInput = userInput.substr(2);
				writingPos = std::max(0, writingPos - 2);
			}

			userInputPrefix = "";
			return true;
		}

		if (action.command == "chatswitchally") {
			if ((userInput.find_first_of("aA") == 0) && (userInput[1] == ':')) {
				// already are in ally chat -> toggle it off
				userInput = userInput.substr(2);
				writingPos = std::max(0, writingPos - 2);
				userInputPrefix = "";
			}
			else if ((userInput.find_first_of("sS") == 0) && (userInput[1] == ':')) {
				// are in spec chat -> switch it to ally chat
				userInput[0] = 'a';
				userInputPrefix = "a:";
			} else {
				userInput = "a:" + userInput;
				writingPos += 2;
				userInputPrefix = "a:";
			}

			return true;
		}

		if (action.command == "chatswitchspec") {
			if ((userInput.find_first_of("sS") == 0) && (userInput[1] == ':')) {
				// already are in spec chat -> toggle it off
				userInput = userInput.substr(2);
				writingPos = std::max(0, writingPos - 2);
				userInputPrefix = "";
			}
			else if ((userInput.find_first_of("aA") == 0) && (userInput[1] == ':')) {
				// are in ally chat -> switch it to spec chat
				userInput[0] = 's';
				userInputPrefix = "s:";
			} else {
				userInput = "s:" + userInput;
				writingPos += 2;
				userInputPrefix = "s:";
			}

			return true;
		}

		// unknown chat-command
		return false;
	}

	return false;
}


bool CGame::ProcessAction(const Action& action, unsigned int key, bool isRepeat)
{
    //stub method
}

void CGame::ActionReceived(const Action& action, int playerID)
{
    //stub method
}

bool CGame::ActionPressed(unsigned int key, const Action& action, bool isRepeat)
{
    //stub method
}

