// TODO: Substitue CLocalConnection with your actual class name
void CLocalConnection::SendData(RawPacket)> packet){}
bool CLocalConnection::HasIncomingData(){}
std::shared_ptr<(q(const).RawPacket)> CLocalConnection::Peek(unsigned int ahead){}
std::shared_ptr<(q(const).RawPacket)> CLocalConnection::GetData(){}
void CLocalConnection::DeleteBufferPacketAt(unsigned int index){}
void CLocalConnection::Close(bool flush){}
unsigned int CLocalConnection::GetPacketQueueSize(){}
std::string CLocalConnection::Statistics(){}
std::string CLocalConnection::GetFullAddress(){}
std::deque<(std::shared_ptr<(q(const).RawPacket)>)> CLocalConnection::pqueues(){}
spring::mutex CLocalConnection::mutexes(){}
unsigned int CLocalConnection::instances(){}
unsigned int CLocalConnection::instance(){}
