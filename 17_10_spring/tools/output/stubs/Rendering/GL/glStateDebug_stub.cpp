#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#if defined(DEBUG_GLSTATE)

#define NO_GL_WRAP

#include <map>
#include <set>
#include <string>

#include "glStateDebug.h"

#include "System/Log/ILog.h"

#include "System/Platform/Threading.h"

template<typename T, typename F>
static void
VERIFYGL(F func,
         GLenum pname,
         T defaultValue,
         std::string pstr,
         std::string area)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

template<typename T, typename F>
static void
VERIFYGL2(F func,
          GLenum pname,
          T default0,
          T default1,
          std::string pstr,
          std::string area)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

template<typename T, typename F>
static void
VERIFYGL4(F func,
          GLenum pname,
          T default0,
          T default1,
          T default2,
          T default3,
          std::string pstr,
          std::string area)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define VERIFYGLBOOL(pname, defaultValue, area)                                \
    VERIFYGL(glGetBooleanv, pname, (GLboolean)defaultValue, #pname, area)
#define VERIFYGLBOOL4(pname, default0, default1, default2, default3, area)     \
    VERIFYGL4(glGetBooleanv,                                                   \
              pname,                                                           \
              (GLboolean)default0,                                             \
              (GLboolean)default1,                                             \
              (GLboolean)default2,                                             \
              (GLboolean)default3,                                             \
              #pname,                                                          \
              area)

#define VERIFYGLFLOAT(pname, defaultValue, area)                               \
    VERIFYGL(glGetFloatv, pname, (GLfloat)defaultValue, #pname, area)
#define VERIFYGLFLOAT4(pname, default0, default1, default2, default3, area)    \
    VERIFYGL4(glGetFloatv,                                                     \
              pname,                                                           \
              (GLfloat)default0,                                               \
              (GLfloat)default1,                                               \
              (GLfloat)default2,                                               \
              (GLfloat)default3,                                               \
              #pname,                                                          \
              area)

#define VERIFYGLINT(pname, defaultValue, area)                                 \
    VERIFYGL(glGetIntegerv, pname, (GLint)defaultValue, #pname, area)
#define VERIFYGLINT2(pname, default0, default1, area)                          \
    VERIFYGL2(                                                                 \
      glGetIntegerv, pname, (GLint)default0, (GLint)default1, #pname, area)

std::map<std::string, std::string> CGLStateChecker::lastSet;
std::set<std::string> CGLStateChecker::errorsSet;

void
_wrap_glEnable(GLenum pname, std::string pstr, std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glDisable(GLenum pname, std::string pstr, std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glBlendFunc(GLenum sfactor, GLenum dfactor, std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glBlendFuncSeparate(GLenum srcRGB,
                          GLenum dstRGB,
                          GLenum srcAlpha,
                          GLenum dstAlpha,
                          std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glColor3f(GLfloat red, GLfloat green, GLfloat blue, std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glColor4f(GLfloat red,
                GLfloat green,
                GLfloat blue,
                GLfloat alpha,
                std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glColor4fv(const GLfloat* v, std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glDepthMask(GLboolean flag, std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glDepthFunc(GLenum func, std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
_wrap_glColorMask(GLboolean red,
                  GLboolean green,
                  GLboolean blue,
                  GLboolean alpha,
                  std::string location)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGLStateChecker::VerifyState(std::string area)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGLStateChecker::CGLStateChecker(std::string id)
  : id(id)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGLStateChecker::~CGLStateChecker()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif // DEBUG_GLSTATE
