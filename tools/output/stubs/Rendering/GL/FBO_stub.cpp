/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * @brief EXT_framebuffer_object implementation
 * EXT_framebuffer_object class implementation
 */

#include <assert.h>
#include <vector>

#include "FBO.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Log/ILog.h"
#include "System/Config/ConfigHandler.h"

CONFIG(bool, AtiSwapRBFix).defaultValue(false);

std::vector<FBO*> FBO::fboList;
std::map<GLuint,FBO::TexData*> FBO::texBuf;

GLint FBO::maxAttachments = 0;
GLsizei FBO::maxSamples = -1;


/**
 * Returns if the current gpu supports Framebuffer Objects
 */
bool FBO::IsSupported()
{
    //stub method
}


static GLint GetCurrentBoundFBO()
{
    //stub method
}



/**
 * Detects the textureTarget just by the textureName/ID
 */
GLenum FBO::GetTextureTargetByID(const GLuint id, const unsigned int i)
{
    //stub method
}


/**
 * Makes a copy of a texture/RBO in the system ram
 */
void FBO::DownloadAttachment(const GLenum attachment)
{
    //stub method
}

/**
 * @brief GLContextLost
 */
void FBO::GLContextLost()
{
    //stub method
}


/**
 * @brief GLContextReinit
 */
void FBO::GLContextReinit()
{
    //stub method
}


/**
 * Tests for support of the EXT_framebuffer_object
 * extension, and generates a framebuffer if supported
 */
FBO::FBO() : fboId(0), reloadOnAltTab(false)
{
    //stub method
}


/**
 * Unbinds the framebuffer and deletes it
 */
FBO::~FBO()
{
    //stub method
}


/**
 * Tests whether or not if we have a valid framebuffer
 */
bool FBO::IsValid() const
{
    //stub method
}


/**
 * Makes the framebuffer the active framebuffer context
 */
void FBO::Bind()
{
    //stub method
}


/**
 * Unbinds the framebuffer from the current context
 */
void FBO::Unbind()
{
    //stub method
}


/**
 * Tests if the framebuffer is a complete and
 * legitimate framebuffer
 */
bool FBO::CheckStatus(std::string name)
{
    //stub method
}


/**
 * Returns the current framebuffer status
 */
GLenum FBO::GetStatus()
{
    //stub method
}


/**
 * Attaches a GL texture to the framebuffer
 */
void FBO::AttachTexture(const GLuint texId, const GLenum texTarget, const GLenum attachment, const int mipLevel, const int zSlice )
{
    //stub method
}


/**
 * Attaches a GL RenderBuffer to the framebuffer
 */
void FBO::AttachRenderBuffer(const GLuint rboId, const GLenum attachment)
{
    //stub method
}


/**
 * Detaches an attachment from the framebuffer
 */
void FBO::Detach(const GLenum attachment)
{
    //stub method
}


/**
 * Detaches any attachments from the framebuffer
 */
void FBO::DetachAll()
{
    //stub method
}


/**
 * Creates and attaches a RBO
 */
void FBO::CreateRenderBuffer(const GLenum attachment, const GLenum format, const GLsizei width, const GLsizei height)
{
    //stub method
}


/**
 * Creates and attaches a multisampled RBO
 */
void FBO::CreateRenderBufferMultisample(const GLenum attachment, const GLenum format, const GLsizei width, const GLsizei height, GLsizei samples)
{
    //stub method
}

GLsizei FBO::GetMaxSamples()
{
    //stub method
}
