// TODO: Substitue CSocket with your actual class name
asio::io_service CSocket::netcode::netservice(){}
bool CSocket::netcode::CheckErrorCode(asio::error_code & err){}
asio::ip::udp::endpoint CSocket::netcode::ResolveAddr(const std::string & host, int port, asio::error_code * error){}
asio::ip::address CSocket::netcode::WrapIP(const std::string & ip, asio::error_code * err){}
asio::ip::address CSocket::netcode::WrapIP(const std::string & ip){}
asio::ip::udp::resolver::iterator CSocket::netcode::WrapResolve(asio::ip::udp::resolver & resolver, asio::ip::udp::resolver::query & query, asio::error_code * err){}
asio::ip::udp::resolver::iterator CSocket::netcode::WrapResolve(asio::ip::udp::resolver & resolver, asio::ip::udp::resolver::query & query){}
asio::ip::address CSocket::netcode::GetAnyAddress(const bool IPv6){}
