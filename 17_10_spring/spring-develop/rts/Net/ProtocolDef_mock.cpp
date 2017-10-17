// TODO: Substitue CProtocolDef with your actual class name
netcode::ProtocolDef CProtocolDef::GetInstance(){}
void CProtocolDef::AddType(const unsigned char id, const int msgLength){}
int CProtocolDef::PacketLength(const const unsigned char * buf, const unsigned int bufLength){}
bool CProtocolDef::IsValidLength(const int pktLength, const unsigned int bufLength){}
bool CProtocolDef::IsValidPacket(const const unsigned char * buf, const unsigned int bufLength){}
MsgType CProtocolDef::msg(){}
