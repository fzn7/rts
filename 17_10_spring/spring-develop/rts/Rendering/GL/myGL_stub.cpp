#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <SDL.h>
#include <string>
#include <vector>

#if defined(WIN32) && !defined(HEADLESS) && !defined(_MSC_VER)
// for APIENTRY
#include <windef.h>
#endif

#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/CrashHandler.h"
#include "System/Platform/MessageBox.h"
#include "System/Platform/Threading.h"
#include "System/TimeProfiler.h"
#include "System/type2.h"
#include "VertexArray.h"
#include "myGL.h"

CONFIG(bool, DisableCrappyGPUWarning)
  .defaultValue(false)
  .description("Disables the warning an user will receive if (s)he attempts to "
               "run Spring on an outdated and underpowered video card.");
CONFIG(bool, DebugGL)
  .defaultValue(false)
  .description("Enables _driver_ debug feedback. (see GL_ARB_debug_output)");
CONFIG(bool, DebugGLStacktraces)
  .defaultValue(false)
  .description("Create a stacktrace when an OpenGL error occurs");

static std::vector<CVertexArray*> vertexArrays;
static int currentVertexArray = 0;

/******************************************************************************/
/******************************************************************************/

CVertexArray*
GetVertexArray()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
PrintAvailableResolutions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#ifdef GL_ARB_debug_output
#if defined(WIN32) && !defined(HEADLESS)
#if defined(_MSC_VER) && _MSC_VER >= 1600
#define _APIENTRY __stdcall
#else
#define _APIENTRY APIENTRY
#endif
#else
#define _APIENTRY
#endif

void _APIENTRY
OpenGLDebugMessageCallback(GLenum source,
                           GLenum type,
                           GLuint id,
                           GLenum severity,
                           GLsizei length,
                           const GLchar* message,
                           const GLvoid* userParam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif // GL_ARB_debug_output

static bool
GetAvailableVideoRAM(GLint* memory)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
ShowCrappyGpuWarning(const char* glVendor, const char* glRenderer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// FIXME move most of this to globalRendering's ctor?
void
LoadExtensions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UnloadExtensions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
WorkaroundATIPointSizeBug()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
glSaveTexture(const GLuint textureID, const std::string& filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
glSpringBindTextures(GLuint first, GLsizei count, const GLuint* textures)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
glSpringTexStorage2D(const GLenum target,
                     GLint levels,
                     const GLint internalFormat,
                     const GLsizei width,
                     const GLsizei height)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
glBuildMipmaps(const GLenum target,
               GLint internalFormat,
               const GLsizei width,
               const GLsizei height,
               const GLenum format,
               const GLenum type,
               const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
glSpringMatrix2dProj(const int sizex, const int sizey)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
ClearScreen()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

static unsigned int
LoadProgram(GLenum, const char*, const char*);

/**
 * True if the program in DATADIR/shaders/filename is
 * loadable and can run inside our graphics server.
 *
 * @param target glProgramStringARB target: GL_FRAGMENT_PROGRAM_ARB
 * GL_VERTEX_PROGRAM_ARB
 * @param filename Name of the file under shaders with the program in it.
 */

bool
ProgramStringIsNative(GLenum target, const char* filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Presumes the last GL operation was to load a vertex or
 * fragment program.
 *
 * If it was invalid, display an error message about
 * what and where the problem in the program source is.
 *
 * @param filename Only substituted in the message.
 * @param program The program text (used to enhance the message)
 */
static bool
CheckParseErrors(GLenum target, const char* filename, const char* program)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static unsigned int
LoadProgram(GLenum target, const char* filename, const char* program_type)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
LoadVertexProgram(const char* filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
LoadFragmentProgram(const char* filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
glSafeDeleteProgram(GLuint program)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
glClearErrors()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
SetTexGen(const float& scaleX,
          const float& scaleZ,
          const float& offsetX,
          const float& offsetZ)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
