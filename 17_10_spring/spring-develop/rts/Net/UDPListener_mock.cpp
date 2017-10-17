// TODO: Substitue CUDPListener with your actual class name
std::shared_ptr<(asio::ip::udp::socket)> CUDPListener::netcode::SocketPtr(){}
std::string CUDPListener::TryBindSocket(int port, netcode::SocketPtr * socket, const std::string & ip){}
std::string CUDPListener::TryBindSocket(int port, netcode::SocketPtr * socket){}
void CUDPListener::Update(){}
std::shared_ptr<(netcode::UDPConnection)> CUDPListener::SpawnConnection(const std::string & ip, const unsigned int port){}
void CUDPListener::SetAcceptingConnections(const bool enable){}
bool CUDPListener::IsAcceptingConnections(){}
bool CUDPListener::HasIncomingConnections(){}
std::weak_ptr<(netcode::UDPConnection)> CUDPListener::PreviewConnection(){}
std::shared_ptr<(netcode::UDPConnection)> CUDPListener::AcceptConnection(){}
void CUDPListener::RejectConnection(){}
void CUDPListener::UpdateConnections(){}
bool CUDPListener::acceptNewConnections(){}
netcode::SocketPtr CUDPListener::mySocket(){}
std::map<(asio::ip::udp::endpoint,std::weak_ptr<(netcode::UDPConnection)>)> CUDPListener::connMap(){}
std::map<(std::string,size_t)> CUDPListener::dropMap(){}
std::queue<(std::shared_ptr<(netcode::UDPConnection)>)> CUDPListener::waiting(){}
