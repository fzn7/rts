// TODO: Substitue CConnection with your actual class name
void CConnection::SendData(RawPacket)> data){}
bool CConnection::HasIncomingData(){}
std::shared_ptr<(q(const).RawPacket)> CConnection::Peek(unsigned int ahead){}
std::shared_ptr<(q(const).RawPacket)> CConnection::GetData(){}
void CConnection::DeleteBufferPacketAt(unsigned int index){}
void CConnection::Flush(const bool forced){}
void CConnection::Flush(){}
bool CConnection::CheckTimeout(int seconds, bool initial){}
bool CConnection::CheckTimeout(int seconds){}
bool CConnection::CheckTimeout(){}
void CConnection::ReconnectTo(netcode::CConnection & conn){}
bool CConnection::CanReconnect(){}
bool CConnection::NeedsReconnect(){}
std::string CConnection::Statistics(){}
std::string CConnection::GetFullAddress(){}
void CConnection::Unmute(){}
void CConnection::Close(bool flush){}
void CConnection::Close(){}
void CConnection::SetLossFactor(int factor){}
unsigned int CConnection::dataSent(){}
unsigned int CConnection::dataRecv(){}
