// TODO: Substitue CLuaHandleSynced with your actual class name
bool CLuaHandleSynced::DrawUnit(const CUnit * unit){}
bool CLuaHandleSynced::DrawFeature(const CFeature * feature){}
bool CLuaHandleSynced::DrawShield(const CUnit * unit, const CWeapon * weapon){}
bool CLuaHandleSynced::DrawProjectile(const CProjectile * projectile){}
void CLuaHandleSynced::RecvFromSynced(lua_State * srcState, int args){}
bool CLuaHandleSynced::Init(const string & code, const string & file){}
CLuaHandleSynced CLuaHandleSynced::base(){}
bool CLuaHandleSynced::CommandFallback(const CUnit * unit, const Command & cmd){}
bool CLuaHandleSynced::AllowCommand(const CUnit * unit, const Command & cmd, bool fromSynced){}
bool CLuaHandleSynced::AllowUnitCreation(const UnitDef * unitDef, const CUnit * builder, const BuildInfo * buildInfo){}
bool CLuaHandleSynced::AllowUnitTransfer(const CUnit * unit, int newTeam, bool capture){}
bool CLuaHandleSynced::AllowUnitBuildStep(const CUnit * builder, const CUnit * unit, float part){}
bool CLuaHandleSynced::AllowFeatureCreation(const FeatureDef * featureDef, int allyTeamID, const float3 & pos){}
bool CLuaHandleSynced::AllowFeatureBuildStep(const CUnit * builder, const CFeature * feature, float part){}
bool CLuaHandleSynced::AllowResourceLevel(int teamID, const string & type, float level){}
bool CLuaHandleSynced::AllowResourceTransfer(int oldTeam, int newTeam, const string & type, float amount){}
bool CLuaHandleSynced::AllowDirectUnitControl(int playerID, const CUnit * unit){}
bool CLuaHandleSynced::AllowBuilderHoldFire(const CUnit * unit, int action){}
bool CLuaHandleSynced::AllowStartPosition(int playerID, int teamID, unsigned char readyState, const float3 & clampedPos, const float3 & rawPickPos){}
bool CLuaHandleSynced::TerraformComplete(const CUnit * unit, const CUnit * build){}
bool CLuaHandleSynced::MoveCtrlNotify(const CUnit * unit, int data){}
int CLuaHandleSynced::AllowWeaponTargetCheck(unsigned int attackerID, unsigned int attackerWeaponNum, unsigned int attackerWeaponDefID){}
bool CLuaHandleSynced::AllowWeaponTarget(unsigned int attackerID, unsigned int targetID, unsigned int attackerWeaponNum, unsigned int attackerWeaponDefID, float * targetPriority){}
bool CLuaHandleSynced::AllowWeaponInterceptTarget(const CUnit * interceptorUnit, const CWeapon * interceptorWeapon, const CProjectile * interceptorTarget){}
bool CLuaHandleSynced::UnitPreDamaged(const CUnit * unit, const CUnit * attacker, float damage, int weaponDefID, int projectileID, bool paralyzer, float * newDamage, float * impulseMult){}
bool CLuaHandleSynced::FeaturePreDamaged(const CFeature * feature, const CUnit * attacker, float damage, int weaponDefID, int projectileID, float * newDamage, float * impulseMult){}
bool CLuaHandleSynced::ShieldPreDamaged(const CProjectile * projectile, const CWeapon * shieldEmitter, const CUnit * shieldCarrier, bool bounceProjectile, const CWeapon * beamEmitter, const CUnit * beamCarrier, const float3 & startPos, const float3 & hitPos){}
bool CLuaHandleSynced::SyncedActionFallback(const string & line, int playerID){}
bool CLuaHandleSynced::Init(const string & code, const string & file){}
CLuaHandleSynced CLuaHandleSynced::base(){}
spring::unordered_map<(string,string)> CLuaHandleSynced::textCommands(){}
int CLuaHandleSynced::origNextRef(){}
int CLuaHandleSynced::SyncedRandom(lua_State * L){}
int CLuaHandleSynced::SyncedRandomSeed(lua_State * L){}
int CLuaHandleSynced::SyncedNext(lua_State * L){}
int CLuaHandleSynced::SyncedPairs(lua_State * L){}
int CLuaHandleSynced::SendToUnsynced(lua_State * L){}
int CLuaHandleSynced::AddSyncedActionFallback(lua_State * L){}
int CLuaHandleSynced::RemoveSyncedActionFallback(lua_State * L){}
int CLuaHandleSynced::GetWatchUnitDef(lua_State * L){}
int CLuaHandleSynced::SetWatchUnitDef(lua_State * L){}
int CLuaHandleSynced::GetWatchFeatureDef(lua_State * L){}
int CLuaHandleSynced::SetWatchFeatureDef(lua_State * L){}
int CLuaHandleSynced::GetWatchWeaponDef(lua_State * L){}
int CLuaHandleSynced::SetWatchWeaponDef(lua_State * L){}
string CLuaHandleSynced::LoadFile(const string & filename, const string & modes){}
void CLuaHandleSynced::Init(const string & syncedFile, const string & unsyncedFile, const string & modes){}
bool CLuaHandleSynced::AddSyncedCode(lua_State * L){}
bool CLuaHandleSynced::AddUnsyncedCode(lua_State * L){}
int CLuaHandleSynced::LoadStringData(lua_State * L){}
int CLuaHandleSynced::CallAsTeam(lua_State * L){}
CSyncedLuaHandle CLuaHandleSynced::syncedLuaHandle(){}
CUnsyncedLuaHandle CLuaHandleSynced::unsyncedLuaHandle(){}
LuaRulesParams::Params CLuaHandleSynced::gameParams(){}
