// TODO: Substitue CNetProtocol with your actual class name
void CNetProtocol::InitClient(const char * server, unsigned int portnum, const std::string & myName, const std::string & myPasswd, const std::string & myVersion){}
void CNetProtocol::InitLocalClient(){}
bool CNetProtocol::CheckTimeout(int nsecs, bool initial){}
bool CNetProtocol::CheckTimeout(int nsecs){}
bool CNetProtocol::CheckTimeout(){}
void CNetProtocol::AttemptReconnect(const std::string & myVersion){}
bool CNetProtocol::NeedsReconnect(){}
bool CNetProtocol::Connected(){}
std::string CNetProtocol::ConnectionStr(){}
std::shared_ptr<(q(const).netcode::RawPacket)> CNetProtocol::Peek(unsigned int ahead){}
void CNetProtocol::DeleteBufferPacketAt(unsigned int index){}
float CNetProtocol::GetPacketTime(int frameNum){}
std::shared_ptr<(q(const).netcode::RawPacket)> CNetProtocol::GetData(int framenum){}
void CNetProtocol::Send(netcode::RawPacket)> pkt){}
void CNetProtocol::Send(const netcode::RawPacket * pkt){}
void CNetProtocol::UpdateLoop(){}
void CNetProtocol::Update(){}
void CNetProtocol::Close(bool flush){}
void CNetProtocol::Close(){}
void CNetProtocol::SetDemoRecorder(CDemoRecorder * r){}
CDemoRecorder CNetProtocol::GetDemoRecorder(){}
unsigned int CNetProtocol::GetNumWaitingServerPackets(){}
q(volatile).bool CNetProtocol::keepUpdating(){}
std::unique_ptr<(netcode::CConnection)> CNetProtocol::serverConn(){}
std::unique_ptr<(CDemoRecorder)> CNetProtocol::demoRecorder(){}
std::string CNetProtocol::userName(){}
std::string CNetProtocol::userPasswd(){}
CNetProtocol CNetProtocol::clientNet(){}
