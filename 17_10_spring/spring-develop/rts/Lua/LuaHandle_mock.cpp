// TODO: Substitue CLuaHandle with your actual class name
void CLuaHandle::CheckStack(){}
bool CLuaHandle::HasCallIn(lua_State * L, const string & name){}
bool CLuaHandle::UpdateCallIn(lua_State * L, const string & name){}
void CLuaHandle::Load(IArchive * archive){}
void CLuaHandle::GamePreload(){}
void CLuaHandle::GameStart(){}
void CLuaHandle::GameOver(const std::vector<(unsigned char)> & winningAllyTeams){}
void CLuaHandle::GamePaused(int playerID, bool paused){}
void CLuaHandle::GameFrame(int frameNum){}
void CLuaHandle::GameID(const unsigned char * gameID, unsigned int numBytes){}
void CLuaHandle::TeamDied(int teamID){}
void CLuaHandle::TeamChanged(int teamID){}
void CLuaHandle::PlayerChanged(int playerID){}
void CLuaHandle::PlayerAdded(int playerID){}
void CLuaHandle::PlayerRemoved(int playerID, int reason){}
void CLuaHandle::UnitCreated(const CUnit * unit, const CUnit * builder){}
void CLuaHandle::UnitFinished(const CUnit * unit){}
void CLuaHandle::UnitFromFactory(const CUnit * unit, const CUnit * factory, bool userOrders){}
void CLuaHandle::UnitReverseBuilt(const CUnit * unit){}
void CLuaHandle::UnitDestroyed(const CUnit * unit, const CUnit * attacker){}
void CLuaHandle::UnitTaken(const CUnit * unit, int oldTeam, int newTeam){}
void CLuaHandle::UnitGiven(const CUnit * unit, int oldTeam, int newTeam){}
void CLuaHandle::UnitIdle(const CUnit * unit){}
void CLuaHandle::UnitCommand(const CUnit * unit, const Command & command){}
void CLuaHandle::UnitCmdDone(const CUnit * unit, const Command & command){}
void CLuaHandle::UnitDamaged(const CUnit * unit, const CUnit * attacker, float damage, int weaponDefID, int projectileID, bool paralyzer){}
void CLuaHandle::UnitStunned(const CUnit * unit, bool stunned){}
void CLuaHandle::UnitExperience(const CUnit * unit, float oldExperience){}
void CLuaHandle::UnitHarvestStorageFull(const CUnit * unit){}
void CLuaHandle::UnitSeismicPing(const CUnit * unit, int allyTeam, const float3 & pos, float strength){}
void CLuaHandle::UnitEnteredRadar(const CUnit * unit, int allyTeam){}
void CLuaHandle::UnitEnteredLos(const CUnit * unit, int allyTeam){}
void CLuaHandle::UnitLeftRadar(const CUnit * unit, int allyTeam){}
void CLuaHandle::UnitLeftLos(const CUnit * unit, int allyTeam){}
void CLuaHandle::UnitEnteredWater(const CUnit * unit){}
void CLuaHandle::UnitEnteredAir(const CUnit * unit){}
void CLuaHandle::UnitLeftWater(const CUnit * unit){}
void CLuaHandle::UnitLeftAir(const CUnit * unit){}
void CLuaHandle::UnitLoaded(const CUnit * unit, const CUnit * transport){}
void CLuaHandle::UnitUnloaded(const CUnit * unit, const CUnit * transport){}
void CLuaHandle::UnitCloaked(const CUnit * unit){}
void CLuaHandle::UnitDecloaked(const CUnit * unit){}
void CLuaHandle::UnitUnitCollision(const CUnit * collider, const CUnit * collidee){}
void CLuaHandle::UnitFeatureCollision(const CUnit * collider, const CFeature * collidee){}
void CLuaHandle::UnitMoveFailed(const CUnit * unit){}
void CLuaHandle::RenderUnitDestroyed(const CUnit * unit){}
void CLuaHandle::FeatureCreated(const CFeature * feature){}
void CLuaHandle::FeatureDestroyed(const CFeature * feature){}
void CLuaHandle::FeatureDamaged(const CFeature * feature, const CUnit * attacker, float damage, int weaponDefID, int projectileID){}
void CLuaHandle::ProjectileCreated(const CProjectile * p){}
void CLuaHandle::ProjectileDestroyed(const CProjectile * p){}
bool CLuaHandle::Explosion(int weaponID, int projectileID, const float3 & pos, const CUnit * owner){}
void CLuaHandle::StockpileChanged(const CUnit * owner, const CWeapon * weapon, int oldCount){}
void CLuaHandle::Save(zipFile archive){}
void CLuaHandle::UnsyncedHeightMapUpdate(const SRectangle & rect){}
void CLuaHandle::Update(){}
bool CLuaHandle::KeyPress(int key, bool isRepeat){}
bool CLuaHandle::KeyRelease(int key){}
bool CLuaHandle::TextInput(const std::string & utf8){}
bool CLuaHandle::MouseMove(int x, int y, int dx, int dy, int button){}
bool CLuaHandle::MousePress(int x, int y, int button){}
void CLuaHandle::MouseRelease(int x, int y, int button){}
bool CLuaHandle::MouseWheel(bool up, float value){}
bool CLuaHandle::JoystickEvent(const std::string & event, int val1, int val2){}
bool CLuaHandle::IsAbove(int x, int y){}
string CLuaHandle::GetTooltip(int x, int y){}
bool CLuaHandle::DefaultCommand(const CUnit * unit, const CFeature * feature, int & cmd){}
bool CLuaHandle::CommandNotify(const Command & cmd){}
bool CLuaHandle::AddConsoleLine(const string & msg, const string & section, int level){}
bool CLuaHandle::GroupChanged(int groupID){}
bool CLuaHandle::GameSetup(const string & state, bool & ready, const std::vector<(std::pair<(int,std::string)>)> & playerStates){}
q(const).char CLuaHandle::RecvSkirmishAIMessage(int aiID, const char * data, int inSize){}
string CLuaHandle::WorldTooltip(const CUnit * unit, const CFeature * feature, const float3 * groundPos){}
bool CLuaHandle::MapDrawCmd(int playerID, int type, const float3 * pos0, const float3 * pos1, const string * labe){}
void CLuaHandle::ViewResize(){}
void CLuaHandle::DrawGenesis(){}
void CLuaHandle::DrawWorld(){}
void CLuaHandle::DrawWorldPreUnit(){}
void CLuaHandle::DrawWorldPreParticles(){}
void CLuaHandle::DrawWorldShadow(){}
void CLuaHandle::DrawWorldReflection(){}
void CLuaHandle::DrawWorldRefraction(){}
void CLuaHandle::DrawGroundPreForward(){}
void CLuaHandle::DrawGroundPreDeferred(){}
void CLuaHandle::DrawGroundPostDeferred(){}
void CLuaHandle::DrawUnitsPostDeferred(){}
void CLuaHandle::DrawFeaturesPostDeferred(){}
void CLuaHandle::DrawScreenCommon(const LuaHashString & cmdStr){}
void CLuaHandle::DrawScreenEffects(){}
void CLuaHandle::DrawScreenPost(){}
void CLuaHandle::DrawScreen(){}
void CLuaHandle::DrawInMiniMap(){}
void CLuaHandle::DrawInMiniMapBackground(){}
void CLuaHandle::GameProgress(int frameNum){}
void CLuaHandle::CollectGarbage(){}
void CLuaHandle::DownloadQueued(int ID, const string & archiveName, const string & archiveType){}
void CLuaHandle::DownloadStarted(int ID){}
void CLuaHandle::DownloadFinished(int ID){}
void CLuaHandle::DownloadFailed(int ID, int errorID){}
void CLuaHandle::DownloadProgress(int ID, long downloaded, long total){}
void CLuaHandle::Shutdown(){}
bool CLuaHandle::GotChatMsg(const string & msg, int playerID){}
bool CLuaHandle::RecvLuaMsg(const string & msg, int playerID){}
int CLuaHandle::XCall(lua_State * srcState, const string & funcName){}
void CLuaHandle::KillLua(bool inFreeHandler){}
void CLuaHandle::KillLua(){}
void CLuaHandle::PushTracebackFuncToRegistry(lua_State * L){}
bool CLuaHandle::AddBasicCalls(lua_State * L){}
bool CLuaHandle::LoadCode(lua_State * L, const string & code, const string & debug){}
bool CLuaHandle::AddEntriesToTable(lua_State * L, const char * name, bool * entriesFunc){}
int CLuaHandle::RunCallInTraceback(lua_State * L, const LuaHashString * hs, std::string * ts, int inArgs, int outArgs, int errFuncIndex, bool popErrFunc){}
bool CLuaHandle::RunCallInTraceback(lua_State * L, const LuaHashString & hs, int inArgs, int outArgs, int errFuncIndex, bool popErrFunc){}
bool CLuaHandle::RunCallInTraceback(lua_State * L, const LuaHashString & hs, int inArgs, int outArgs, int errFuncIndex){}
bool CLuaHandle::RunCallInLUS(lua_State * L, std::string * ts, int inArgs, int outArgs){}
bool CLuaHandle::RunCallIn(lua_State * L, const LuaHashString & hs, int inArgs, int outArgs){}
void CLuaHandle::LosCallIn(const LuaHashString & hs, const CUnit * unit, int allyTeam){}
void CLuaHandle::UnitCallIn(const LuaHashString & hs, const CUnit * unit){}
void CLuaHandle::RunDrawCallIn(const LuaHashString & hs){}
bool CLuaHandle::userMode(){}
bool CLuaHandle::killMe(){}
lua_State CLuaHandle::L(){}
lua_State CLuaHandle::L_GC(){}
luaContextData CLuaHandle::D(){}
string CLuaHandle::killMsg(){}
vector<(bool)> CLuaHandle::watchUnitDefs(){}
vector<(bool)> CLuaHandle::watchFeatureDefs(){}
vector<(bool)> CLuaHandle::watchWeaponDefs(){}
int CLuaHandle::callinErrors(){}
int CLuaHandle::KillActiveHandle(lua_State * L){}
int CLuaHandle::CallOutGetName(lua_State * L){}
int CLuaHandle::CallOutGetSynced(lua_State * L){}
int CLuaHandle::CallOutGetFullCtrl(lua_State * L){}
int CLuaHandle::CallOutGetFullRead(lua_State * L){}
int CLuaHandle::CallOutGetCtrlTeam(lua_State * L){}
int CLuaHandle::CallOutGetReadTeam(lua_State * L){}
int CLuaHandle::CallOutGetReadAllyTeam(lua_State * L){}
int CLuaHandle::CallOutGetSelectTeam(lua_State * L){}
int CLuaHandle::CallOutGetGlobal(lua_State * L){}
int CLuaHandle::CallOutGetRegistry(lua_State * L){}
int CLuaHandle::CallOutGetCallInList(lua_State * L){}
int CLuaHandle::CallOutUpdateCallIn(lua_State * L){}
int CLuaHandle::CallOutIsEngineMinVersion(lua_State * L){}
void CLuaHandle::HandleLuaMsg(int playerID, int script, int mode, const std::vector<(std::uint8_t)> & msg){}
bool CLuaHandle::devMode(){}
