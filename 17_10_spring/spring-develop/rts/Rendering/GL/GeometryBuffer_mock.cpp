// TODO: Substitue CGeometryBuffer with your actual class name
void CGeometryBuffer::Init(bool ctor){}
void CGeometryBuffer::Kill(bool dtor){}
void CGeometryBuffer::Clear(){}
void CGeometryBuffer::DetachTextures(const bool init){}
void CGeometryBuffer::DrawDebug(const unsigned int texID, const float2 texMins, const float2 texMaxs){}
bool CGeometryBuffer::Create(const int2 size){}
bool CGeometryBuffer::Update(const bool init){}
void CGeometryBuffer::SetDepthRange(float nearDepth, float farDepth){}
int2 CGeometryBuffer::GetWantedSize(bool allowed){}
FBO CGeometryBuffer::buffer(){}
GLuint CGeometryBuffer::bufferTextureIDs(){}
GLenum CGeometryBuffer::bufferAttachments(){}
int2 CGeometryBuffer::prevBufferSize(){}
int2 CGeometryBuffer::currBufferSize(){}
q(const).char CGeometryBuffer::name(){}
bool CGeometryBuffer::dead(){}
bool CGeometryBuffer::bound(){}
