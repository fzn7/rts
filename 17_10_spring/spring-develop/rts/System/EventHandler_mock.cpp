// TODO: Substitue CEventHandler with your actual class name
void CEventHandler::ResetState(){}
void CEventHandler::SetupEvents(){}
void CEventHandler::AddClient(CEventClient * ec){}
void CEventHandler::RemoveClient(CEventClient * ec){}
bool CEventHandler::InsertEvent(CEventClient * ec, const std::string & ciName){}
bool CEventHandler::RemoveEvent(CEventClient * ec, const std::string & ciName){}
void CEventHandler::GetEventList(std::vector<(std::string)> & list){}
bool CEventHandler::IsKnown(const std::string & ciName){}
bool CEventHandler::IsManaged(const std::string & ciName){}
bool CEventHandler::IsUnsynced(const std::string & ciName){}
bool CEventHandler::IsController(const std::string & ciName){}
void CEventHandler::Load(IArchive * archive){}
void CEventHandler::GamePreload(){}
void CEventHandler::GameStart(){}
void CEventHandler::GameOver(const std::vector<(unsigned char)> & winningAllyTeams){}
void CEventHandler::GamePaused(int playerID, bool paused){}
void CEventHandler::GameFrame(int gameFrame){}
void CEventHandler::GameID(const unsigned char * gameID, unsigned int numBytes){}
void CEventHandler::TeamDied(int teamID){}
void CEventHandler::TeamChanged(int teamID){}
void CEventHandler::PlayerChanged(int playerID){}
void CEventHandler::PlayerAdded(int playerID){}
void CEventHandler::PlayerRemoved(int playerID, int reason){}
void CEventHandler::UnitCreated(const CUnit * unit, const CUnit * builder){}
void CEventHandler::UnitFinished(const CUnit * unit){}
void CEventHandler::UnitReverseBuilt(const CUnit * unit){}
void CEventHandler::UnitFromFactory(const CUnit * unit, const CUnit * factory, bool userOrders){}
void CEventHandler::UnitDestroyed(const CUnit * unit, const CUnit * attacker){}
void CEventHandler::UnitTaken(const CUnit * unit, int oldTeam, int newTeam){}
void CEventHandler::UnitGiven(const CUnit * unit, int oldTeam, int newTeam){}
void CEventHandler::RenderUnitCreated(const CUnit * unit, int cloaked){}
void CEventHandler::RenderUnitDestroyed(const CUnit * unit){}
void CEventHandler::RenderFeatureCreated(const CFeature * feature){}
void CEventHandler::RenderFeatureDestroyed(const CFeature * feature){}
void CEventHandler::RenderProjectileCreated(const CProjectile * proj){}
void CEventHandler::RenderProjectileDestroyed(const CProjectile * proj){}
void CEventHandler::UnitIdle(const CUnit * unit){}
void CEventHandler::UnitCommand(const CUnit * unit, const Command & command){}
void CEventHandler::UnitCmdDone(const CUnit * unit, const Command & command){}
void CEventHandler::UnitDamaged(const CUnit * unit, const CUnit * attacker, float damage, int weaponDefID, int projectileID, bool paralyzer){}
void CEventHandler::UnitStunned(const CUnit * unit, bool stunned){}
void CEventHandler::UnitExperience(const CUnit * unit, float oldExperience){}
void CEventHandler::UnitHarvestStorageFull(const CUnit * unit){}
void CEventHandler::UnitSeismicPing(const CUnit * unit, int allyTeam, const float3 & pos, float strength){}
void CEventHandler::UnitEnteredRadar(const CUnit * unit, int allyTeam){}
void CEventHandler::UnitEnteredLos(const CUnit * unit, int allyTeam){}
void CEventHandler::UnitLeftRadar(const CUnit * unit, int allyTeam){}
void CEventHandler::UnitLeftLos(const CUnit * unit, int allyTeam){}
void CEventHandler::UnitEnteredWater(const CUnit * unit){}
void CEventHandler::UnitEnteredAir(const CUnit * unit){}
void CEventHandler::UnitLeftWater(const CUnit * unit){}
void CEventHandler::UnitLeftAir(const CUnit * unit){}
void CEventHandler::UnitLoaded(const CUnit * unit, const CUnit * transport){}
void CEventHandler::UnitUnloaded(const CUnit * unit, const CUnit * transport){}
void CEventHandler::UnitCloaked(const CUnit * unit){}
void CEventHandler::UnitDecloaked(const CUnit * unit){}
void CEventHandler::UnitUnitCollision(const CUnit * collider, const CUnit * collidee){}
void CEventHandler::UnitFeatureCollision(const CUnit * collider, const CFeature * collidee){}
void CEventHandler::UnitMoved(const CUnit * unit){}
void CEventHandler::UnitMoveFailed(const CUnit * unit){}
void CEventHandler::FeatureCreated(const CFeature * feature){}
void CEventHandler::FeatureDestroyed(const CFeature * feature){}
void CEventHandler::FeatureDamaged(const CFeature * feature, const CUnit * attacker, float damage, int weaponDefID, int projectileID){}
void CEventHandler::FeatureMoved(const CFeature * feature, const float3 & oldpos){}
void CEventHandler::ProjectileCreated(const CProjectile * proj, int allyTeam){}
void CEventHandler::ProjectileDestroyed(const CProjectile * proj, int allyTeam){}
bool CEventHandler::Explosion(int weaponDefID, int projectileID, const float3 & pos, const CUnit * owner){}
void CEventHandler::StockpileChanged(const CUnit * unit, const CWeapon * weapon, int oldCount){}
bool CEventHandler::CommandFallback(const CUnit * unit, const Command & cmd){}
bool CEventHandler::AllowCommand(const CUnit * unit, const Command & cmd, bool fromSynced){}
bool CEventHandler::AllowUnitCreation(const UnitDef * unitDef, const CUnit * builder, const BuildInfo * buildInfo){}
bool CEventHandler::AllowUnitTransfer(const CUnit * unit, int newTeam, bool capture){}
bool CEventHandler::AllowUnitBuildStep(const CUnit * builder, const CUnit * unit, float part){}
bool CEventHandler::AllowFeatureCreation(const FeatureDef * featureDef, int allyTeamID, const float3 & pos){}
bool CEventHandler::AllowFeatureBuildStep(const CUnit * builder, const CFeature * feature, float part){}
bool CEventHandler::AllowResourceLevel(int teamID, const string & type, float level){}
bool CEventHandler::AllowResourceTransfer(int oldTeam, int newTeam, const string & type, float amount){}
bool CEventHandler::AllowDirectUnitControl(int playerID, const CUnit * unit){}
bool CEventHandler::AllowBuilderHoldFire(const CUnit * unit, int action){}
bool CEventHandler::AllowStartPosition(int playerID, int teamID, unsigned char readyState, const float3 & clampedPos, const float3 & rawPickPos){}
bool CEventHandler::TerraformComplete(const CUnit * unit, const CUnit * build){}
bool CEventHandler::MoveCtrlNotify(const CUnit * unit, int data){}
int CEventHandler::AllowWeaponTargetCheck(unsigned int attackerID, unsigned int attackerWeaponNum, unsigned int attackerWeaponDefID){}
bool CEventHandler::AllowWeaponTarget(unsigned int attackerID, unsigned int targetID, unsigned int attackerWeaponNum, unsigned int attackerWeaponDefID, float * targetPriority){}
bool CEventHandler::AllowWeaponInterceptTarget(const CUnit * interceptorUnit, const CWeapon * interceptorWeapon, const CProjectile * interceptorTarget){}
bool CEventHandler::UnitPreDamaged(const CUnit * unit, const CUnit * attacker, float damage, int weaponDefID, int projectileID, bool paralyzer, float * newDamage, float * impulseMult){}
bool CEventHandler::FeaturePreDamaged(const CFeature * feature, const CUnit * attacker, float damage, int weaponDefID, int projectileID, float * newDamage, float * impulseMult){}
bool CEventHandler::ShieldPreDamaged(const CProjectile * projectile, const CWeapon * shieldEmitter, const CUnit * shieldCarrier, bool bounceProjectile, const CWeapon * beamEmitter, const CUnit * beamCarrier, const float3 & startPos, const float3 & hitPos){}
bool CEventHandler::SyncedActionFallback(const string & line, int playerID){}
void CEventHandler::Save(zipFile archive){}
void CEventHandler::UnsyncedHeightMapUpdate(const SRectangle & rect){}
void CEventHandler::Update(){}
bool CEventHandler::KeyPress(int key, bool isRepeat){}
bool CEventHandler::KeyRelease(int key){}
bool CEventHandler::TextInput(const std::string & utf8){}
bool CEventHandler::MouseMove(int x, int y, int dx, int dy, int button){}
bool CEventHandler::MousePress(int x, int y, int button){}
void CEventHandler::MouseRelease(int x, int y, int button){}
bool CEventHandler::MouseWheel(bool up, float value){}
bool CEventHandler::JoystickEvent(const std::string & event, int val1, int val2){}
bool CEventHandler::IsAbove(int x, int y){}
std::string CEventHandler::GetTooltip(int x, int y){}
bool CEventHandler::DefaultCommand(const CUnit * unit, const CFeature * feature, int & cmd){}
bool CEventHandler::CommandNotify(const Command & cmd){}
bool CEventHandler::AddConsoleLine(const std::string & msg, const std::string & section, int level){}
void CEventHandler::LastMessagePosition(const float3 & pos){}
bool CEventHandler::GroupChanged(int groupID){}
bool CEventHandler::GameSetup(const std::string & state, bool & ready, const std::vector<(std::pair<(int,std::string)>)> & playerStates){}
void CEventHandler::DownloadQueued(int ID, const string & archiveName, const string & archiveType){}
void CEventHandler::DownloadStarted(int ID){}
void CEventHandler::DownloadFinished(int ID){}
void CEventHandler::DownloadFailed(int ID, int errorID){}
void CEventHandler::DownloadProgress(int ID, long downloaded, long total){}
std::string CEventHandler::WorldTooltip(const CUnit * unit, const CFeature * feature, const float3 * groundPos){}
bool CEventHandler::MapDrawCmd(int playerID, int type, const float3 * pos0, const float3 * pos1, const std::string * label){}
void CEventHandler::SunChanged(){}
void CEventHandler::ViewResize(){}
void CEventHandler::DrawGenesis(){}
void CEventHandler::DrawWorld(){}
void CEventHandler::DrawWorldPreUnit(){}
void CEventHandler::DrawWorldPreParticles(){}
void CEventHandler::DrawWorldShadow(){}
void CEventHandler::DrawWorldReflection(){}
void CEventHandler::DrawWorldRefraction(){}
void CEventHandler::DrawGroundPreForward(){}
void CEventHandler::DrawGroundPreDeferred(){}
void CEventHandler::DrawGroundPostDeferred(){}
void CEventHandler::DrawUnitsPostDeferred(){}
void CEventHandler::DrawFeaturesPostDeferred(){}
void CEventHandler::DrawScreenPost(){}
void CEventHandler::DrawScreenEffects(){}
void CEventHandler::DrawScreen(){}
void CEventHandler::DrawInMiniMap(){}
void CEventHandler::DrawInMiniMapBackground(){}
bool CEventHandler::DrawUnit(const CUnit * unit){}
bool CEventHandler::DrawFeature(const CFeature * feature){}
bool CEventHandler::DrawShield(const CUnit * unit, const CWeapon * weapon){}
bool CEventHandler::DrawProjectile(const CProjectile * projectile){}
void CEventHandler::GameProgress(int gameFrame){}
void CEventHandler::CollectGarbage(){}
void CEventHandler::DbgTimingInfo(DbgTimingInfoType type, const spring_time start, const spring_time end){}
void CEventHandler::MetalMapChanged(const int x, const int z){}
std::vector<(p.CEventClient)> CEventHandler::EventClientList(){}
std::pair<(std::string,EventInfo)> CEventHandler::EventPair(){}
std::vector<(CEventHandler::EventPair)> CEventHandler::EventMap(){}
void CEventHandler::SetupEvent(const std::string & ciName, CEventHandler::EventClientList * list, int props){}
void CEventHandler::ListInsert(CEventHandler::EventClientList & ciList, CEventClient * ec){}
void CEventHandler::ListRemove(CEventHandler::EventClientList & ciList, CEventClient * ec){}
CEventClient CEventHandler::mouseOwner(){}
CEventHandler::EventMap CEventHandler::eventMap(){}
CEventHandler::EventClientList CEventHandler::handles(){}
CEventHandler CEventHandler::eventHandler(){}
