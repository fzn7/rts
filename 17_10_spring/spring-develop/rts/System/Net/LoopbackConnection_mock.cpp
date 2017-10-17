// TODO: Substitue CLoopbackConnection with your actual class name
void CLoopbackConnection::SendData(RawPacket)> data){}
bool CLoopbackConnection::HasIncomingData(){}
std::shared_ptr<(q(const).RawPacket)> CLoopbackConnection::Peek(unsigned int ahead){}
std::shared_ptr<(q(const).RawPacket)> CLoopbackConnection::GetData(){}
void CLoopbackConnection::DeleteBufferPacketAt(unsigned int index){}
void CLoopbackConnection::Flush(const bool forced){}
bool CLoopbackConnection::CheckTimeout(int seconds, bool initial){}
bool CLoopbackConnection::CanReconnect(){}
bool CLoopbackConnection::NeedsReconnect(){}
std::string CLoopbackConnection::Statistics(){}
std::string CLoopbackConnection::GetFullAddress(){}
std::deque<(std::shared_ptr<(q(const).RawPacket)>)> CLoopbackConnection::Data(){}
