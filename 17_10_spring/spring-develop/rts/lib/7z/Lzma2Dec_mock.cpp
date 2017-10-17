// TODO: Substitue CLzma2Dec with your actual class name
CLzmaDec CLzma2Dec::decoder(){}
UInt32 CLzma2Dec::packSize(){}
UInt32 CLzma2Dec::unpackSize(){}
int CLzma2Dec::state(){}
Byte CLzma2Dec::control(){}
Bool CLzma2Dec::needInitDic(){}
Bool CLzma2Dec::needInitState(){}
Bool CLzma2Dec::needInitProp(){}
CLzma2Dec CLzma2Dec::CLzma2Dec(){}
SRes CLzma2Dec::Lzma2Dec_AllocateProbs(CLzma2Dec * p, Byte prop, ISzAlloc * alloc){}
SRes CLzma2Dec::Lzma2Dec_Allocate(CLzma2Dec * p, Byte prop, ISzAlloc * alloc){}
void CLzma2Dec::Lzma2Dec_Init(CLzma2Dec * p){}
SRes CLzma2Dec::Lzma2Dec_DecodeToDic(CLzma2Dec * p, SizeT dicLimit, const Byte * src, SizeT * srcLen, ELzmaFinishMode finishMode, ELzmaStatus * status){}
SRes CLzma2Dec::Lzma2Dec_DecodeToBuf(CLzma2Dec * p, Byte * dest, SizeT * destLen, const Byte * src, SizeT * srcLen, ELzmaFinishMode finishMode, ELzmaStatus * status){}
SRes CLzma2Dec::Lzma2Decode(Byte * dest, SizeT * destLen, const Byte * src, SizeT * srcLen, Byte prop, ELzmaFinishMode finishMode, ELzmaStatus * status, ISzAlloc * alloc){}
