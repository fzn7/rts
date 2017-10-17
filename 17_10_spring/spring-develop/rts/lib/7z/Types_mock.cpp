// TODO: Substitue CTypes with your actual class name
int CTypes::SRes(){}
int CTypes::WRes(){}
unsigned char CTypes::Byte(){}
short CTypes::Int16(){}
unsigned short CTypes::UInt16(){}
int CTypes::Int32(){}
unsigned int CTypes::UInt32(){}
long long CTypes::Int64(){}
unsigned long long CTypes::UInt64(){}
size_t CTypes::SizeT(){}
int CTypes::Bool(){}
Byte CTypes::Read(void * p){}
IByteIn CTypes::IByteIn(){}
void CTypes::Write(void * p, Byte b){}
IByteOut CTypes::IByteOut(){}
SRes CTypes::Read(void * p, void * buf, size_t * size){}
ISeqInStream CTypes::ISeqInStream(){}
SRes CTypes::SeqInStream_Read(ISeqInStream * stream, void * buf, size_t size){}
SRes CTypes::SeqInStream_Read2(ISeqInStream * stream, void * buf, size_t size, SRes errorType){}
SRes CTypes::SeqInStream_ReadByte(ISeqInStream * stream, Byte * buf){}
size_t CTypes::Write(void * p, const void * buf, size_t size){}
ISeqOutStream CTypes::ISeqOutStream(){}
enum $unnamed5$ CTypes::ESzSeek(){}
SRes CTypes::Read(void * p, void * buf, size_t * size){}
SRes CTypes::Seek(void * p, Int64 * pos, ESzSeek origin){}
ISeekInStream CTypes::ISeekInStream(){}
SRes CTypes::Look(void * p, const void ** buf, size_t * size){}
SRes CTypes::Skip(void * p, size_t offset){}
SRes CTypes::Read(void * p, void * buf, size_t * size){}
SRes CTypes::Seek(void * p, Int64 * pos, ESzSeek origin){}
ILookInStream CTypes::ILookInStream(){}
SRes CTypes::LookInStream_LookRead(ILookInStream * stream, void * buf, size_t * size){}
SRes CTypes::LookInStream_SeekTo(ILookInStream * stream, UInt64 offset){}
SRes CTypes::LookInStream_Read2(ILookInStream * stream, void * buf, size_t size, SRes errorType){}
SRes CTypes::LookInStream_Read(ILookInStream * stream, void * buf, size_t size){}
ILookInStream CTypes::s(){}
ISeekInStream CTypes::realStream(){}
size_t CTypes::pos(){}
size_t CTypes::size(){}
Byte CTypes::buf(){}
CLookToRead CTypes::CLookToRead(){}
void CTypes::LookToRead_CreateVTable(CLookToRead * p, int lookahead){}
void CTypes::LookToRead_Init(CLookToRead * p){}
ISeqInStream CTypes::s(){}
ILookInStream CTypes::realStream(){}
CSecToLook CTypes::CSecToLook(){}
void CTypes::SecToLook_CreateVTable(CSecToLook * p){}
ISeqInStream CTypes::s(){}
ILookInStream CTypes::realStream(){}
CSecToRead CTypes::CSecToRead(){}
void CTypes::SecToRead_CreateVTable(CSecToRead * p){}
SRes CTypes::Progress(void * p, UInt64 inSize, UInt64 outSize){}
ICompressProgress CTypes::ICompressProgress(){}
void CTypes::Alloc(void * p, size_t size){}
void CTypes::Free(void * p, void * address){}
ISzAlloc CTypes::ISzAlloc(){}
