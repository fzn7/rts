// TODO: Substitue CUDPConnection with your actual class name
void CUDPConnection::UpdateChecksum(CRC & crc){}
q(const).unsigned int CUDPConnection::maxSize(){}
q(const).unsigned int CUDPConnection::headerSize(){}
std::int32_t CUDPConnection::chunkNumber(){}
std::uint8_t CUDPConnection::chunkSize(){}
std::vector<(std::uint8_t)> CUDPConnection::data(){}
std::shared_ptr<(netcode::Chunk)> CUDPConnection::netcode::ChunkPtr(){}
q(const).unsigned int CUDPConnection::headerSize(){}
unsigned int CUDPConnection::GetSize(){}
std::uint8_t CUDPConnection::GetChecksum(){}
void CUDPConnection::Serialize(std::vector<(std::uint8_t)> & data){}
std::int32_t CUDPConnection::lastContinuous(){}
std::int8_t CUDPConnection::nakType(){}
std::uint8_t CUDPConnection::checksum(){}
std::vector<(std::uint8_t)> CUDPConnection::naks(){}
std::list<(netcode::ChunkPtr)> CUDPConnection::chunks(){}
void CUDPConnection::SendData(RawPacket)> data){}
std::shared_ptr<(q(const).RawPacket)> CUDPConnection::Peek(unsigned int ahead){}
std::shared_ptr<(q(const).RawPacket)> CUDPConnection::GetData(){}
void CUDPConnection::DeleteBufferPacketAt(unsigned int index){}
void CUDPConnection::Flush(const bool forced){}
bool CUDPConnection::CheckTimeout(int seconds, bool initial){}
bool CUDPConnection::CheckTimeout(int seconds){}
bool CUDPConnection::CheckTimeout(){}
void CUDPConnection::ReconnectTo(CConnection & conn){}
bool CUDPConnection::CanReconnect(){}
bool CUDPConnection::NeedsReconnect(){}
std::string CUDPConnection::Statistics(){}
std::string CUDPConnection::GetFullAddress(){}
void CUDPConnection::Update(){}
void CUDPConnection::ProcessRawPacket(netcode::Packet & packet){}
bool CUDPConnection::IsUsingAddress(const asio::ip::udp::endpoint & from){}
void CUDPConnection::Close(bool flush){}
void CUDPConnection::SetLossFactor(int factor){}
void CUDPConnection::InitConnection(asio::ip::udp::endpoint address, std::shared_ptr<(asio::ip::udp::socket)> socket){}
void CUDPConnection::CopyConnection(netcode::UDPConnection & conn){}
void CUDPConnection::SetMTU(unsigned int mtu){}
void CUDPConnection::Init(){}
void CUDPConnection::CreateChunk(const unsigned char * data, const unsigned int length, const int packetNum){}
void CUDPConnection::SendIfNecessary(bool flushed){}
void CUDPConnection::AckChunks(int lastAck){}
void CUDPConnection::RequestResend(netcode::ChunkPtr ptr){}
void CUDPConnection::SendPacket(netcode::Packet & pkt){}
spring_time CUDPConnection::lastChunkCreatedTime(){}
spring_time CUDPConnection::lastPacketSendTime(){}
spring_time CUDPConnection::lastPacketRecvTime(){}
spring_time CUDPConnection::lastUnackResentTime(){}
spring_time CUDPConnection::lastNakTime(){}
spring_time CUDPConnection::lastDebugMessageTime(){}
spring_time CUDPConnection::lastFramePacketRecvTime(){}
std::map<(int,p.RawPacket)> CUDPConnection::packetMap(){}
std::list<(std::shared_ptr<(q(const).RawPacket)>)> CUDPConnection::packetList(){}
asio::ip::udp::endpoint CUDPConnection::addr(){}
unsigned int CUDPConnection::mtu(){}
bool CUDPConnection::muted(){}
bool CUDPConnection::closed(){}
bool CUDPConnection::resend(){}
bool CUDPConnection::sharedSocket(){}
bool CUDPConnection::logMessages(){}
int CUDPConnection::netLossFactor(){}
int CUDPConnection::reconnectTime(){}
netcode::UDPConnection::packetList CUDPConnection::outgoingData(){}
netcode::UDPConnection::packetMap CUDPConnection::waitingPackets(){}
std::deque<(netcode::ChunkPtr)> CUDPConnection::newChunks(){}
std::deque<(netcode::ChunkPtr)> CUDPConnection::unackedChunks(){}
std::map<(std::int32_t,netcode::ChunkPtr)> CUDPConnection::resendRequested(){}
std::deque<(std::shared_ptr<(q(const).RawPacket)>)> CUDPConnection::msgQueue(){}
std::int32_t CUDPConnection::lastMidChunk(){}
int CUDPConnection::lastInOrder(){}
int CUDPConnection::lastNak(){}
std::shared_ptr<(asio::ip::udp::socket)> CUDPConnection::mySocket(){}
RawPacket CUDPConnection::fragmentBuffer(){}
float CUDPConnection::sumDeltaFramePacketRecvTime(){}
float CUDPConnection::minDeltaFramePacketRecvTime(){}
float CUDPConnection::maxDeltaFramePacketRecvTime(){}
unsigned int CUDPConnection::numReceivedFramePackets(){}
unsigned int CUDPConnection::numEnqueuedFramePackets(){}
unsigned int CUDPConnection::numEmptyGetDataCalls(){}
unsigned int CUDPConnection::numTotalGetDataCalls(){}
unsigned int CUDPConnection::currentPacketChunkNum(){}
unsigned int CUDPConnection::resentChunks(){}
unsigned int CUDPConnection::droppedChunks(){}
unsigned int CUDPConnection::sentOverhead(){}
unsigned int CUDPConnection::recvOverhead(){}
unsigned int CUDPConnection::sentPackets(){}
unsigned int CUDPConnection::recvPackets(){}
BandwidthUsage CUDPConnection::outgoing(){}
