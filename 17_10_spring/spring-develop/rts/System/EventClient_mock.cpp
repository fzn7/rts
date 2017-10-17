// TODO: Substitue CEventClient with your actual class name
void CEventClient::zipFile(){}
bool CEventClient::WantsEvent(const std::string & eventName){}
q(const).std::string CEventClient::name(){}
q(const).int CEventClient::order(){}
q(const).bool CEventClient::synced_(){}
bool CEventClient::autoLinkEvents(){}
std::pair<(std::string,bool)> CEventClient::LinkPair(){}
std::vector<(CEventClient::LinkPair)> CEventClient::autoLinkedEvents(){}
bool CEventClient::CommandFallback(const CUnit * unit, const Command & cmd){}
bool CEventClient::AllowCommand(const CUnit * unit, const Command & cmd, bool fromSynced){}
bool CEventClient::AllowUnitCreation(const UnitDef * unitDef, const CUnit * builder, const BuildInfo * buildInfo){}
bool CEventClient::AllowUnitTransfer(const CUnit * unit, int newTeam, bool capture){}
bool CEventClient::AllowUnitBuildStep(const CUnit * builder, const CUnit * unit, float part){}
bool CEventClient::AllowFeatureCreation(const FeatureDef * featureDef, int allyTeamID, const float3 & pos){}
bool CEventClient::AllowFeatureBuildStep(const CUnit * builder, const CFeature * feature, float part){}
bool CEventClient::AllowResourceLevel(int teamID, const string & type, float level){}
bool CEventClient::AllowResourceTransfer(int oldTeam, int newTeam, const string & type, float amount){}
bool CEventClient::AllowDirectUnitControl(int playerID, const CUnit * unit){}
bool CEventClient::AllowBuilderHoldFire(const CUnit * unit, int action){}
bool CEventClient::AllowStartPosition(int playerID, int teamID, unsigned char readyState, const float3 & clampedPos, const float3 & rawPickPos){}
bool CEventClient::TerraformComplete(const CUnit * unit, const CUnit * build){}
bool CEventClient::MoveCtrlNotify(const CUnit * unit, int data){}
bool CEventClient::SyncedActionFallback(const string & line, int playerID){}
void CEventClient::Save(zipFile archive){}
void CEventClient::Update(){}
void CEventClient::UnsyncedHeightMapUpdate(const SRectangle & rect){}
bool CEventClient::KeyPress(int key, bool isRepeat){}
bool CEventClient::KeyRelease(int key){}
bool CEventClient::TextInput(const std::string & utf8){}
bool CEventClient::MouseMove(int x, int y, int dx, int dy, int button){}
bool CEventClient::MousePress(int x, int y, int button){}
void CEventClient::MouseRelease(int x, int y, int button){}
bool CEventClient::MouseWheel(bool up, float value){}
bool CEventClient::JoystickEvent(const std::string & event, int val1, int val2){}
void CEventClient::DownloadQueued(int ID, const string & archiveName, const string & archiveType){}
void CEventClient::DownloadStarted(int ID){}
void CEventClient::DownloadFinished(int ID){}
void CEventClient::DownloadFailed(int ID, int errorID){}
void CEventClient::DownloadProgress(int ID, long downloaded, long total){}
bool CEventClient::IsAbove(int x, int y){}
std::string CEventClient::GetTooltip(int x, int y){}
bool CEventClient::DefaultCommand(const CUnit * unit, const CFeature * feature, int & cmd){}
bool CEventClient::CommandNotify(const Command & cmd){}
bool CEventClient::AddConsoleLine(const std::string & msg, const std::string & section, int level){}
void CEventClient::LastMessagePosition(const float3 & pos){}
bool CEventClient::GroupChanged(int groupID){}
bool CEventClient::GameSetup(const std::string & state, bool & ready, const std::vector<(std::pair<(int,std::string)>)> & playerStates){}
std::string CEventClient::WorldTooltip(const CUnit * unit, const CFeature * feature, const float3 * groundPos){}
bool CEventClient::MapDrawCmd(int playerID, int type, const float3 * pos0, const float3 * pos1, const std::string * label){}
void CEventClient::SunChanged(){}
void CEventClient::ViewResize(){}
bool CEventClient::DrawUnit(const CUnit * unit){}
bool CEventClient::DrawFeature(const CFeature * feature){}
bool CEventClient::DrawShield(const CUnit * unit, const CWeapon * weapon){}
bool CEventClient::DrawProjectile(const CProjectile * projectile){}
void CEventClient::GameProgress(int gameFrame){}
void CEventClient::DrawLoadScreen(){}
void CEventClient::LoadProgress(const std::string & msg, const bool replace_lastline){}
void CEventClient::CollectGarbage(){}
void CEventClient::DbgTimingInfo(DbgTimingInfoType type, const spring_time start, const spring_time end){}
void CEventClient::MetalMapChanged(const int x, const int z){}
