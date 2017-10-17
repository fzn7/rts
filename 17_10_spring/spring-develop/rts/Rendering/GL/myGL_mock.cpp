// TODO: Substitue CmyGL with your actual class name
void CmyGL::glOrthoFuncPtr(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far){}
void CmyGL::gluOrtho2DFuncPtr(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top){}
void CmyGL::glFrustumFuncPtr(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far){}
glOrthoFuncPtr CmyGL::glOrthoFuncs(){}
gluOrtho2DFuncPtr CmyGL::gluOrtho2DFuncs(){}
glFrustumFuncPtr CmyGL::glFrustumFuncs(){}
void CmyGL::WorkaroundATIPointSizeBug(){}
void CmyGL::SetTexGen(const float scaleX, const float scaleZ, const float offsetX, const float offsetZ){}
void CmyGL::glSaveTexture(const GLuint textureID, const char * filename){}
void CmyGL::glSpringBindTextures(GLuint first, GLsizei count, const GLuint * textures){}
void CmyGL::glSpringTexStorage2D(const GLenum target, GLint levels, const GLint internalFormat, const GLsizei width, const GLsizei height){}
void CmyGL::glBuildMipmaps(const GLenum target, GLint internalFormat, const GLsizei width, const GLsizei height, const GLenum format, const GLenum type, const void * data){}
void CmyGL::glSpringMatrix2dProj(const int sizex, const int sizey){}
void CmyGL::ClearScreen(){}
bool CmyGL::ProgramStringIsNative(GLenum target, const char * filename){}
unsigned int CmyGL::LoadVertexProgram(const char * filename){}
unsigned int CmyGL::LoadFragmentProgram(const char * filename){}
void CmyGL::glClearErrors(const char * cls, const char * fnc, bool verbose){}
void CmyGL::glClearErrors(const char * cls, const char * fnc){}
void CmyGL::glSafeDeleteProgram(GLuint program){}
bool CmyGL::CheckAvailableVideoModes(){}
bool CmyGL::GetAvailableVideoRAM(GLint * memory, const char * glVendor){}
bool CmyGL::ShowDriverWarning(const char * glVendor, const char * glRenderer){}
CVertexArray CmyGL::GetVertexArray(){}
