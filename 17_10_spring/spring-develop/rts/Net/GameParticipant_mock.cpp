// TODO: Substitue CGameParticipant with your actual class name
void CGameParticipant::SendData(netcode::RawPacket)> packet){}
void CGameParticipant::Connected(std::shared_ptr<(netcode::CConnection)> link, bool local){}
void CGameParticipant::Kill(const std::string & reason, const bool flush){}
void CGameParticipant::Kill(const std::string & reason){}
int CGameParticipant::id(){}
GameParticipant::State CGameParticipant::myState(){}
int CGameParticipant::lastFrameResponse(){}
int CGameParticipant::speedControl(){}
bool CGameParticipant::isLocal(){}
bool CGameParticipant::isReconn(){}
bool CGameParticipant::isMidgameJoin(){}
std::shared_ptr<(netcode::CConnection)> CGameParticipant::link(){}
PlayerStatistics CGameParticipant::lastStats(){}
std::map<(unsigned char,GameParticipant::PlayerLinkData)> CGameParticipant::linkData(){}
