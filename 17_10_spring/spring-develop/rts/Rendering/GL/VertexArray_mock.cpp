// TODO: Substitue CVertexArray with your actual class name
float3 CVertexArray::p(){}
float3 CVertexArray::p(){}
float3 CVertexArray::n(){}
float3 CVertexArray::p(){}
SColor CVertexArray::c(){}
float3 CVertexArray::p(){}
float CVertexArray::s(){}
float CVertexArray::t(){}
float3 CVertexArray::p(){}
float CVertexArray::s(){}
float CVertexArray::t(){}
float3 CVertexArray::n(){}
float3 CVertexArray::p(){}
float CVertexArray::s(){}
float CVertexArray::t(){}
SColor CVertexArray::c(){}
float3 CVertexArray::p(){}
float CVertexArray::s(){}
float CVertexArray::t(){}
float3 CVertexArray::n(){}
float3 CVertexArray::uv1(){}
float3 CVertexArray::uv2(){}
float CVertexArray::x(){}
float CVertexArray::y(){}
float CVertexArray::x(){}
float CVertexArray::y(){}
float CVertexArray::s(){}
float CVertexArray::t(){}
float CVertexArray::x(){}
float CVertexArray::y(){}
float CVertexArray::s(){}
float CVertexArray::t(){}
SColor CVertexArray::c(){}
void CVertexArray::StripCallback(void * data){}
CVertexArray CVertexArray::operator =(const CVertexArray & va){}
bool CVertexArray::IsReady(){}
void CVertexArray::Initialize(){}
void CVertexArray::CheckInitSize(const unsigned int vertexes, const unsigned int strips){}
void CVertexArray::CheckInitSize(const unsigned int vertexes){}
void CVertexArray::EnlargeArrays(const unsigned int vertexes, const unsigned int strips, const unsigned int stripsize){}
void CVertexArray::EnlargeArrays(const unsigned int vertexes, const unsigned int strips){}
void CVertexArray::EnlargeArrays(const unsigned int vertexes){}
void CVertexArray::AddVertex0(const float3 & p){}
void CVertexArray::AddVertex0(float x, float y, float z){}
void CVertexArray::AddVertexN(const float3 & p, const float3 & n){}
void CVertexArray::AddVertexT(const float3 & p, float tx, float ty){}
void CVertexArray::AddVertexC(const float3 & p, const unsigned char * c){}
void CVertexArray::AddVertexTC(const float3 & p, float tx, float ty, const unsigned char * c){}
void CVertexArray::AddVertexTN(const float3 & p, float tx, float ty, const float3 & n){}
void CVertexArray::AddVertexTNT(const float3 & p, float tx, float ty, const float3 & n, const float3 & st, const float3 & tt){}
void CVertexArray::AddVertex2d0(float x, float z){}
void CVertexArray::AddVertex2dT(float x, float y, float tx, float ty){}
void CVertexArray::AddVertex2dTC(float x, float y, float tx, float ty, const unsigned char * c){}
void CVertexArray::AddVertexQ0(float x, float y, float z){}
void CVertexArray::AddVertexQ0(const float3 & f3){}
void CVertexArray::AddVertexQN(const float3 & p, const float3 & n){}
void CVertexArray::AddVertexQC(const float3 & p, const unsigned char * c){}
void CVertexArray::AddVertexQT(const float3 & p, float tx, float ty){}
void CVertexArray::AddVertexQTN(const float3 & p, float tx, float ty, const float3 & n){}
void CVertexArray::AddVertexQTNT(const float3 & p, float tx, float ty, const float3 & n, const float3 & st, const float3 & tt){}
void CVertexArray::AddVertexQTC(const float3 & p, float tx, float ty, const unsigned char * c){}
void CVertexArray::AddVertexQ2d0(float x, float z){}
void CVertexArray::AddVertexQ2dT(float x, float y, float tx, float ty){}
void CVertexArray::AddVertexQ2dTC(float x, float y, float tx, float ty, const unsigned char * c){}
void CVertexArray::DrawArray0(const int drawType, unsigned int stride){}
void CVertexArray::DrawArray0(const int drawType){}
void CVertexArray::DrawArray2d0(const int drawType, unsigned int stride){}
void CVertexArray::DrawArray2d0(const int drawType){}
void CVertexArray::DrawArrayN(const int drawType, unsigned int stride){}
void CVertexArray::DrawArrayN(const int drawType){}
void CVertexArray::DrawArrayT(const int drawType, unsigned int stride){}
void CVertexArray::DrawArrayT(const int drawType){}
void CVertexArray::DrawArrayC(const int drawType, unsigned int stride){}
void CVertexArray::DrawArrayC(const int drawType){}
void CVertexArray::DrawArrayTC(const int drawType, unsigned int stride){}
void CVertexArray::DrawArrayTC(const int drawType){}
void CVertexArray::DrawArrayTN(const int drawType, unsigned int stride){}
void CVertexArray::DrawArrayTN(const int drawType){}
void CVertexArray::DrawArrayTNT(const int drawType, unsigned int stride){}
void CVertexArray::DrawArrayTNT(const int drawType){}
void CVertexArray::DrawArray2dT(const int drawType, unsigned int stride){}
void CVertexArray::DrawArray2dT(const int drawType){}
void CVertexArray::DrawArray2dTC(const int drawType, unsigned int stride){}
void CVertexArray::DrawArray2dTC(const int drawType){}
void CVertexArray::DrawArray2dT(const int drawType, CVertexArray::StripCallback callback, void * data, unsigned int stride){}
void CVertexArray::DrawArray2dT(const int drawType, CVertexArray::StripCallback callback, void * data){}
void CVertexArray::EndStrip(){}
void CVertexArray::DrawArrays(const GLenum mode, const unsigned int stride){}
void CVertexArray::DrawArraysCallback(const GLenum mode, const unsigned int stride, CVertexArray::StripCallback callback, void * data){}
void CVertexArray::CheckEnlargeDrawArray(size_t bytesNeeded){}
void CVertexArray::EnlargeStripArray(){}
void CVertexArray::EnlargeDrawArray(){}
void CVertexArray::CheckEndStrip(){}
float CVertexArray::drawArray(){}
float CVertexArray::drawArrayPos(){}
float CVertexArray::drawArraySize(){}
unsigned int CVertexArray::stripArray(){}
unsigned int CVertexArray::stripArrayPos(){}
unsigned int CVertexArray::stripArraySize(){}
unsigned int CVertexArray::maxVertices(){}
