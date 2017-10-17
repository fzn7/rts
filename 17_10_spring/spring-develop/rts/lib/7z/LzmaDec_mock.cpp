// TODO: Substitue CLzmaDec with your actual class name
unsigned int CLzmaDec::lc(){}
unsigned int CLzmaDec::lp(){}
unsigned int CLzmaDec::pb(){}
UInt32 CLzmaDec::dicSize(){}
_CLzmaProps CLzmaDec::CLzmaProps(){}
SRes CLzmaDec::LzmaProps_Decode(CLzmaProps * p, const Byte * data, unsigned int size){}
CLzmaProps CLzmaDec::prop(){}
UInt16 CLzmaDec::probs(){}
Byte CLzmaDec::dic(){}
q(const).Byte CLzmaDec::buf(){}
UInt32 CLzmaDec::range(){}
UInt32 CLzmaDec::code(){}
SizeT CLzmaDec::dicPos(){}
SizeT CLzmaDec::dicBufSize(){}
UInt32 CLzmaDec::processedPos(){}
UInt32 CLzmaDec::checkDicSize(){}
unsigned int CLzmaDec::state(){}
UInt32 CLzmaDec::reps(){}
unsigned int CLzmaDec::remainLen(){}
int CLzmaDec::needFlush(){}
int CLzmaDec::needInitState(){}
UInt32 CLzmaDec::numProbs(){}
unsigned int CLzmaDec::tempBufSize(){}
Byte CLzmaDec::tempBuf(){}
CLzmaDec CLzmaDec::CLzmaDec(){}
void CLzmaDec::LzmaDec_Init(CLzmaDec * p){}
enum $unnamed2$ CLzmaDec::ELzmaFinishMode(){}
enum $unnamed3$ CLzmaDec::ELzmaStatus(){}
SRes CLzmaDec::LzmaDec_AllocateProbs(CLzmaDec * p, const Byte * props, unsigned int propsSize, ISzAlloc * alloc){}
void CLzmaDec::LzmaDec_FreeProbs(CLzmaDec * p, ISzAlloc * alloc){}
SRes CLzmaDec::LzmaDec_Allocate(CLzmaDec * state, const Byte * prop, unsigned int propsSize, ISzAlloc * alloc){}
void CLzmaDec::LzmaDec_Free(CLzmaDec * state, ISzAlloc * alloc){}
SRes CLzmaDec::LzmaDec_DecodeToDic(CLzmaDec * p, SizeT dicLimit, const Byte * src, SizeT * srcLen, ELzmaFinishMode finishMode, ELzmaStatus * status){}
SRes CLzmaDec::LzmaDec_DecodeToBuf(CLzmaDec * p, Byte * dest, SizeT * destLen, const Byte * src, SizeT * srcLen, ELzmaFinishMode finishMode, ELzmaStatus * status){}
SRes CLzmaDec::LzmaDecode(Byte * dest, SizeT * destLen, const Byte * src, SizeT * srcLen, const Byte * propData, unsigned int propSize, ELzmaFinishMode finishMode, ELzmaStatus * status, ISzAlloc * alloc){}
