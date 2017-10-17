// TODO: Substitue CGameServer with your actual class name
bool CGameServer::active(){}
void CGameServer::Reload(const CGameSetup)> newGameSetup){}
void CGameServer::AddLocalClient(const std::string & myName, const std::string & myVersion){}
void CGameServer::AddAutohostInterface(const std::string & autohostIP, const int autohostPort){}
void CGameServer::Initialize(){}
void CGameServer::PostLoad(int serverFrameNum){}
void CGameServer::CreateNewFrame(bool fromServerThread, bool fixedFrameTime){}
void CGameServer::SetGamePausable(const bool arg){}
bool CGameServer::HasFinished(){}
void CGameServer::UpdateSpeedControl(int speedCtrl){}
std::string CGameServer::SpeedControlToString(int speedCtrl){}
std::string CGameServer::GetPlayerNames(const std::vector<(int)> & indices){}
void CGameServer::GotChatMessage(const ChatMessage & msg){}
void CGameServer::PushAction(const Action & action, bool fromAutoHost){}
void CGameServer::StripGameSetupText(const const GameData * newGameData){}
void CGameServer::KickPlayer(const int playerNum){}
void CGameServer::SpecPlayer(const int playerNum){}
void CGameServer::MutePlayer(const int playerNum, bool muteChat, bool muteDraw){}
void CGameServer::ResignPlayer(const int playerNum){}
bool CGameServer::CheckPlayersPassword(const int playerNum, const std::string & pw){}
unsigned int CGameServer::BindConnection(std::string name, const std::string & passwd, const std::string & version, bool isLocal, std::shared_ptr<(netcode::CConnection)> link, bool reconnect, int netloss){}
unsigned int CGameServer::BindConnection(std::string name, const std::string & passwd, const std::string & version, bool isLocal, std::shared_ptr<(netcode::CConnection)> link, bool reconnect){}
unsigned int CGameServer::BindConnection(std::string name, const std::string & passwd, const std::string & version, bool isLocal, std::shared_ptr<(netcode::CConnection)> link){}
void CGameServer::CheckForGameStart(bool forced){}
void CGameServer::CheckForGameStart(){}
void CGameServer::StartGame(bool forced){}
void CGameServer::UpdateLoop(){}
void CGameServer::Update(){}
void CGameServer::ProcessPacket(const unsigned int playerNum, netcode::RawPacket)> packet){}
void CGameServer::CheckSync(){}
void CGameServer::HandleConnectionAttempts(){}
void CGameServer::ServerReadNet(){}
void CGameServer::LagProtection(){}
void CGameServer::GenerateAndSendGameID(){}
void CGameServer::WriteDemoData(){}
bool CGameServer::SendDemoData(int targetFrameNum){}
void CGameServer::Broadcast(netcode::RawPacket)> packet){}
void CGameServer::SkipTo(int targetFrameNum){}
void CGameServer::Message(const std::string & message, bool broadcast){}
void CGameServer::Message(const std::string & message){}
void CGameServer::PrivateMessage(int playerNum, const std::string & message){}
void CGameServer::AddToPacketCache(netcode::RawPacket)> & pckt){}
float CGameServer::GetDemoTime(){}
std::shared_ptr<(q(const).ClientSetup)> CGameServer::myClientSetup(){}
std::shared_ptr<(q(const).GameData)> CGameServer::myGameData(){}
std::shared_ptr<(q(const).CGameSetup)> CGameServer::myGameSetup(){}
q(volatile).bool CGameServer::quitServer(){}
int CGameServer::serverFrameNum(){}
spring_time CGameServer::serverStartTime(){}
spring_time CGameServer::readyTime(){}
spring_time CGameServer::gameStartTime(){}
spring_time CGameServer::gameEndTime(){}
spring_time CGameServer::lastNewFrameTick(){}
spring_time CGameServer::lastPlayerInfo(){}
spring_time CGameServer::lastUpdate(){}
spring_time CGameServer::lastBandwidthUpdate(){}
float CGameServer::modGameTime(){}
float CGameServer::gameTime(){}
float CGameServer::startTime(){}
float CGameServer::frameTimeLeft(){}
bool CGameServer::isPaused(){}
bool CGameServer::gamePausable(){}
float CGameServer::userSpeedFactor(){}
float CGameServer::internalSpeed(){}
std::map<(unsigned char,GameSkirmishAI)> CGameServer::ais(){}
std::array<(bool,MAX_AIS)> CGameServer::usedSkirmishAIIds(){}
std::vector<(GameParticipant)> CGameServer::players(){}
std::vector<(GameTeam)> CGameServer::teams(){}
std::vector<(unsigned char)> CGameServer::winningAllyTeams(){}
std::array<(std::pair<(spring_time,uint32_t)>,MAX_PLAYERS)> CGameServer::clientDrawFilter(){}
std::array<(std::pair<(bool,bool)>,MAX_PLAYERS)> CGameServer::clientMuteFilter(){}
float CGameServer::medianCpu(){}
int CGameServer::medianPing(){}
int CGameServer::curSpeedCtrl(){}
int CGameServer::loopSleepTime(){}
float CGameServer::maxUserSpeed(){}
float CGameServer::minUserSpeed(){}
bool CGameServer::cheating(){}
bool CGameServer::noHelperAIs(){}
bool CGameServer::canReconnect(){}
bool CGameServer::allowSpecDraw(){}
bool CGameServer::allowSpecJoin(){}
bool CGameServer::whiteListAdditionalPlayers(){}
bool CGameServer::logInfoMessages(){}
bool CGameServer::logDebugMessages(){}
std::deque<(std::shared_ptr<(q(const).netcode::RawPacket)>)> CGameServer::packetCache(){}
int CGameServer::syncErrorFrame(){}
int CGameServer::syncWarningFrame(){}
void CGameServer::InternalSpeedChange(float newSpeed){}
void CGameServer::UserSpeedChange(float newSpeed, int player){}
void CGameServer::AddAdditionalUser(const std::string & name, const std::string & passwd, bool fromDemo, bool spectator, int team, int playerNum){}
void CGameServer::AddAdditionalUser(const std::string & name, const std::string & passwd, bool fromDemo, bool spectator, int team){}
void CGameServer::AddAdditionalUser(const std::string & name, const std::string & passwd, bool fromDemo, bool spectator){}
void CGameServer::AddAdditionalUser(const std::string & name, const std::string & passwd, bool fromDemo){}
void CGameServer::AddAdditionalUser(const std::string & name, const std::string & passwd){}
uint8_t CGameServer::ReserveSkirmishAIId(){}
unsigned int CGameServer::localClientNumber(){}
std::set<(std::string)> CGameServer::commandBlacklist(){}
std::unique_ptr<(netcode::UDPListener)> CGameServer::UDPNet(){}
std::unique_ptr<(CDemoReader)> CGameServer::demoReader(){}
std::unique_ptr<(CDemoRecorder)> CGameServer::demoRecorder(){}
std::unique_ptr<(AutohostInterface)> CGameServer::hostif(){}
CGlobalUnsyncedRNG CGameServer::rng(){}
spring::thread CGameServer::thread(){}
spring::recursive_mutex CGameServer::gameServerMutex(){}
q(volatile).bool CGameServer::gameHasStarted(){}
q(volatile).bool CGameServer::generatedGameID(){}
q(volatile).bool CGameServer::reloadingServer(){}
int CGameServer::linkMinPacketSize(){}
CGameServer CGameServer::gameServer(){}
