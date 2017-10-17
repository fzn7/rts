// TODO: Substitue CAutohostInterface with your actual class name
unsigned char CAutohostInterface::uchar(){}
void CAutohostInterface::SendStart(){}
void CAutohostInterface::SendQuit(){}
void CAutohostInterface::SendStartPlaying(const unsigned char * gameID, const std::string & demoName){}
void CAutohostInterface::SendGameOver(AutohostInterface::uchar playerNum, const std::vector<(AutohostInterface::uchar)> & winningAllyTeams){}
void CAutohostInterface::SendPlayerJoined(AutohostInterface::uchar playerNum, const std::string & name){}
void CAutohostInterface::SendPlayerLeft(AutohostInterface::uchar playerNum, AutohostInterface::uchar reason){}
void CAutohostInterface::SendPlayerReady(AutohostInterface::uchar playerNum, AutohostInterface::uchar readyState){}
void CAutohostInterface::SendPlayerChat(AutohostInterface::uchar playerNum, AutohostInterface::uchar destination, const std::string & msg){}
void CAutohostInterface::SendPlayerDefeated(AutohostInterface::uchar playerNum){}
void CAutohostInterface::Message(const std::string & message){}
void CAutohostInterface::Warning(const std::string & message){}
void CAutohostInterface::SendLuaMsg(const std::uint8_t * msg, size_t msgSize){}
void CAutohostInterface::Send(const std::uint8_t * msg, size_t msgSize){}
std::string CAutohostInterface::GetChatMessage(){}
void CAutohostInterface::Send(asio::mutable_buffers_1 sendBuffer){}
std::string CAutohostInterface::TryBindSocket(asio::ip::udp::socket & socket, const std::string & remoteIP, int remotePort, const std::string & localIP, int localPort){}
std::string CAutohostInterface::TryBindSocket(asio::ip::udp::socket & socket, const std::string & remoteIP, int remotePort, const std::string & localIP){}
std::string CAutohostInterface::TryBindSocket(asio::ip::udp::socket & socket, const std::string & remoteIP, int remotePort){}
asio::ip::udp::socket CAutohostInterface::autohost(){}
bool CAutohostInterface::initialized(){}
