// TODO: Substitue CFBO with your actual class name
bool CFBO::IsSupported(){}
GLuint CFBO::fboId(){}
bool CFBO::reloadOnAltTab(){}
bool CFBO::CheckStatus(std::string name){}
GLenum CFBO::GetStatus(){}
GLsizei CFBO::GetMaxSamples(){}
bool CFBO::IsValid(){}
void CFBO::AttachTexture(const GLuint texId, const GLenum texTarget, const GLenum attachment, const int mipLevel, const int zSlice){}
void CFBO::AttachTexture(const GLuint texId, const GLenum texTarget, const GLenum attachment, const int mipLevel){}
void CFBO::AttachTexture(const GLuint texId, const GLenum texTarget, const GLenum attachment){}
void CFBO::AttachTexture(const GLuint texId, const GLenum texTarget){}
void CFBO::AttachTexture(const GLuint texId){}
void CFBO::AttachRenderBuffer(const GLuint rboId, const GLenum attachment){}
void CFBO::AttachRenderBuffer(const GLuint rboId){}
void CFBO::CreateRenderBuffer(const GLenum attachment, const GLenum format, const GLsizei width, const GLsizei height){}
void CFBO::CreateRenderBufferMultisample(const GLenum attachment, const GLenum format, const GLsizei width, const GLsizei height, GLsizei samples){}
void CFBO::Detach(const GLenum attachment){}
void CFBO::DetachAll(){}
void CFBO::Bind(){}
void CFBO::Unbind(){}
void CFBO::GLContextLost(){}
void CFBO::GLContextReinit(){}
bool CFBO::valid(){}
std::vector<(GLuint)> CFBO::rboIDs(){}
std::vector<(p.FBO)> CFBO::activeFBOs(){}
spring::unordered_map<(GLuint,TexData)> CFBO::fboTexData(){}
GLint CFBO::maxAttachments(){}
GLsizei CFBO::maxSamples(){}
void CFBO::DownloadAttachment(const GLenum attachment){}
GLenum CFBO::GetTextureTargetByID(const GLuint id, const unsigned int i){}
GLenum CFBO::GetTextureTargetByID(const GLuint id){}
