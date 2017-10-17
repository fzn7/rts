#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * @brief EXT_framebuffer_object implementation
 * EXT_framebuffer_object class implementation
 */

#include <assert.h>
#include <vector>

#include "FBO.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"

CONFIG(bool, AtiSwapRBFix).defaultValue(false);

std::vector<FBO*> FBO::fboList;
std::map<GLuint, FBO::TexData*> FBO::texBuf;

GLint FBO::maxAttachments = 0;
GLsizei FBO::maxSamples = -1;

/**
 * Returns if the current gpu supports Framebuffer Objects
 */
bool
FBO::IsSupported()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static GLint
GetCurrentBoundFBO()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Detects the textureTarget just by the textureName/ID
 */
GLenum
FBO::GetTextureTargetByID(const GLuint id, const unsigned int i)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Makes a copy of a texture/RBO in the system ram
 */
void
FBO::DownloadAttachment(const GLenum attachment)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief GLContextLost
 */
void
FBO::GLContextLost()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief GLContextReinit
 */
void
FBO::GLContextReinit()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Tests for support of the EXT_framebuffer_object
 * extension, and generates a framebuffer if supported
 */
FBO::FBO()
  : fboId(0)
  , reloadOnAltTab(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Unbinds the framebuffer and deletes it
 */
FBO::~FBO()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Tests whether or not if we have a valid framebuffer
 */
bool
FBO::IsValid() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Makes the framebuffer the active framebuffer context
 */
void
FBO::Bind()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Unbinds the framebuffer from the current context
 */
void
FBO::Unbind()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Tests if the framebuffer is a complete and
 * legitimate framebuffer
 */
bool
FBO::CheckStatus(std::string name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Returns the current framebuffer status
 */
GLenum
FBO::GetStatus()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Attaches a GL texture to the framebuffer
 */
void
FBO::AttachTexture(const GLuint texId,
                   const GLenum texTarget,
                   const GLenum attachment,
                   const int mipLevel,
                   const int zSlice)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Attaches a GL RenderBuffer to the framebuffer
 */
void
FBO::AttachRenderBuffer(const GLuint rboId, const GLenum attachment)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Detaches an attachment from the framebuffer
 */
void
FBO::Detach(const GLenum attachment)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Detaches any attachments from the framebuffer
 */
void
FBO::DetachAll()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Creates and attaches a RBO
 */
void
FBO::CreateRenderBuffer(const GLenum attachment,
                        const GLenum format,
                        const GLsizei width,
                        const GLsizei height)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Creates and attaches a multisampled RBO
 */
void
FBO::CreateRenderBufferMultisample(const GLenum attachment,
                                   const GLenum format,
                                   const GLsizei width,
                                   const GLsizei height,
                                   GLsizei samples)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

GLsizei
FBO::GetMaxSamples()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
