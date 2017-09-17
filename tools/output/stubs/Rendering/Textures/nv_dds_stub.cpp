#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

// This software contains source code provided by NVIDIA Corporation.
// License: http://developer.download.nvidia.com/licenses/general_license.txt

// Modified DDS reader class from NVIDIA SDK
///////////////////////////////////////////////////////////////////////////////
//
// Description:
// 
// Loads DDS images (DXTC1, DXTC3, DXTC5, RGB (888, 888X), and RGBA (8888) are
// supported) for use in OpenGL. Image is flipped when its loaded as DX images
// are stored with different coordinate system. If file has mipmaps and/or 
// cubemaps then these are loaded as well. Volume textures can be loaded as 
// well but they must be uncompressed.
//
// When multiple textures are loaded (i.e a volume or cubemap texture), 
// additional faces can be accessed using the array operator. 
//
// The mipmaps for each face are also stored in a list and can be accessed like 
// so: image.get_mipmap() (which accesses the first mipmap of the first 
// image). To get the number of mipmaps call the get_num_mipmaps function for
// a given texture.
//
// Call the is_volume() or is_cubemap() function to check that a loaded image
// is a volume or cubemap texture respectively. If a volume texture is loaded
// then the get_depth() function should return a number greater than 1. 
// Mipmapped volume textures and DXTC compressed volume textures are supported.
//
///////////////////////////////////////////////////////////////////////////////
//
// Update: 9/15/2003
//
// Added functions to create new image from a buffer of pixels. Added function
// to save current image to disk.
//
// Update: 6/11/2002
//
// Added some convenience functions to handle uploading textures to OpenGL. The
// following functions have been added:
//
//     bool upload_texture1D();
//     bool upload_texture2D(unsigned int imageIndex = 0, GLenum target = GL_TEXTURE_2D);
//     bool upload_textureRectangle();
//     bool upload_texture3D();
//     bool upload_textureCubemap();
//
// See function implementation below for instructions/comments on using each
// function.
//
// The open function has also been updated to take an optional second parameter
// specifying whether the image should be flipped on load. This defaults to 
// true.
//
///////////////////////////////////////////////////////////////////////////////
// Sample usage
///////////////////////////////////////////////////////////////////////////////
//
// Loading a compressed texture:
//
// CDDSImage image;
// GLuint texobj;
//
// image.load("compressed.dds");
// 
// glGenTextures(1, &texobj);
// glEnable(GL_TEXTURE_2D);
// glBindTexture(GL_TEXTURE_2D, texobj);
//
// glCompressedTexImage2DARB(GL_TEXTURE_2D, 0, image.get_format(), 
//     image.get_width(), image.get_height(), 0, image.get_size(), 
//     image);
//
// for (int i = 0; i < image.get_num_mipmaps(); i++)
// {
//     CSurface mipmap = image.get_mipmap(i);
//
//     glCompressedTexImage2DARB(GL_TEXTURE_2D, i+1, image.get_format(), 
//         mipmap.get_width(), mipmap.get_height(), 0, mipmap.get_size(), 
//         mipmap);
// } 
///////////////////////////////////////////////////////////////////////////////
// 
// Loading an uncompressed texture:
//
// CDDSImage image;
// GLuint texobj;
//
// image.load("uncompressed.dds");
//
// glGenTextures(1, &texobj);
// glEnable(GL_TEXTURE_2D);
// glBindTexture(GL_TEXTURE_2D, texobj);
//
// glTexImage2D(GL_TEXTURE_2D, 0, image.get_components(), image.get_width(), 
//     image.get_height(), 0, image.get_format(), GL_UNSIGNED_BYTE, image);
//
// for (int i = 0; i < image.get_num_mipmaps(); i++)
// {
//     glTexImage2D(GL_TEXTURE_2D, i+1, image.get_components(), 
//         image.get_mipmap(i).get_width(), image.get_mipmap(i).get_height(), 
//         0, image.get_format(), GL_UNSIGNED_BYTE, image.get_mipmap(i));
// }
//
///////////////////////////////////////////////////////////////////////////////
// 
// Loading an uncompressed cubemap texture:
//
// CDDSImage image;
// GLuint texobj;
// GLenum target;
// 
// image.load("cubemap.dds");
// 
// glGenTextures(1, &texobj);
// glEnable(GL_TEXTURE_CUBE_MAP_ARB);
// glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, texobj);
// 
// for (int n = 0; n < 6; n++)
// {
//     target = GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB+n;
// 
//     glTexImage2D(target, 0, image.get_components(), image[n].get_width(), 
//         image[n].get_height(), 0, image.get_format(), GL_UNSIGNED_BYTE, 
//         image[n]);
// 
//     for (int i = 0; i < image[n].get_num_mipmaps(); i++)
//     {
//         glTexImage2D(target, i+1, image.get_components(), 
//             image[n].get_mipmap(i).get_width(), 
//             image[n].get_mipmap(i).get_height(), 0,
//             image.get_format(), GL_UNSIGNED_BYTE, image[n].get_mipmap(i));
//     }
// }
//
///////////////////////////////////////////////////////////////////////////////
// 
// Loading a volume texture:
//
// CDDSImage image;
// GLuint texobj;
// 
// image.load("volume.dds");
// 
// glGenTextures(1, &texobj);
// glEnable(GL_TEXTURE_3D);
// glBindTexture(GL_TEXTURE_3D, texobj);
// 
// PFNGLTEXIMAGE3DPROC glTexImage3D;
// glTexImage3D(GL_TEXTURE_3D, 0, image.get_components(), image.get_width(), 
//     image.get_height(), image.get_depth(), 0, image.get_format(), 
//     GL_UNSIGNED_BYTE, image);
// 
// for (int i = 0; i < image.get_num_mipmaps(); i++)
// {
//     glTexImage3D(GL_TEXTURE_3D, i+1, image.get_components(), 
//         image[0].get_mipmap(i).get_width(), 
//         image[0].get_mipmap(i).get_height(), 
//         image[0].get_mipmap(i).get_depth(), 0, image.get_format(), 
//         GL_UNSIGNED_BYTE, image[0].get_mipmap(i));
// }

#include <stdio.h>
#include <string.h>
#include <assert.h>

// spring related
#include "Rendering/GL/myGL.h"
#include "nv_dds.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Platform/byteorder.h"
#include "System/Log/ILog.h"

using namespace std;
using namespace nv_dds;

///////////////////////////////////////////////////////////////////////////////
// CDDSImage public functions

///////////////////////////////////////////////////////////////////////////////
// default constructor
CDDSImage::CDDSImage()
  : m_format(0),
    m_components(0),
    m_type(TextureNone),
    m_valid(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CDDSImage::~CDDSImage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CDDSImage::create_textureFlat(unsigned int format, unsigned int components, const CTexture &baseImage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CDDSImage::create_texture3D(unsigned int format, unsigned int components, const CTexture &baseImage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline bool same_size(const CTexture &a, const CTexture &b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CDDSImage::create_textureCubemap(unsigned int format, unsigned int components,
                                      const CTexture &positiveX, const CTexture &negativeX, 
                                      const CTexture &positiveY, const CTexture &negativeY, 
                                      const CTexture &positiveZ, const CTexture &negativeZ)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// loads DDS image
//
// filename - fully qualified name of DDS image
// flipImage - specifies whether image is flipped on load, default is true
bool CDDSImage::load(string filename, bool flipImage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CDDSImage::write_texture(const CTexture &texture, FILE *fp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CDDSImage::save(std::string filename, bool flipImage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// free image memory
void CDDSImage::clear()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CDDSImage::is_compressed() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifndef BITMAP_NO_OPENGL

///////////////////////////////////////////////////////////////////////////////
// uploads a compressed/uncompressed 1D texture
bool CDDSImage::upload_texture1D()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// uploads a compressed/uncompressed 2D texture
//
// imageIndex - allows you to optionally specify other loaded surfaces for 2D
//              textures such as a face in a cubemap or a slice in a volume
//
//              default: 0
//
// target     - allows you to optionally specify a different texture target for
//              the 2D texture such as a specific face of a cubemap
//
//              default: GL_TEXTURE_2D
bool CDDSImage::upload_texture2D(unsigned int imageIndex, int target)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// uploads a compressed/uncompressed 3D texture
bool CDDSImage::upload_texture3D()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CDDSImage::upload_textureRectangle()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// uploads a compressed/uncompressed cubemap texture
bool CDDSImage::upload_textureCubemap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif // !BITMAP_NO_OPENGL

///////////////////////////////////////////////////////////////////////////////
// clamps input size to [1-size]
inline unsigned int CDDSImage::clamp_size(unsigned int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// CDDSImage private functions
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// calculates size of DXTC texture in bytes
inline unsigned int CDDSImage::size_dxtc(unsigned int width, unsigned int height)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// calculates size of uncompressed RGB texture in bytes
inline unsigned int CDDSImage::size_rgb(unsigned int width, unsigned int height)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// flip image around X axis
void CDDSImage::flip(CSurface &surface)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// swap to sections of memory
void CDDSImage::swap(void *byte1, void *byte2, unsigned int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// flip a DXT1 color block
void CDDSImage::flip_blocks_dxtc1(DXTColBlock *line, unsigned int numBlocks)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// flip a DXT3 color block
void CDDSImage::flip_blocks_dxtc3(DXTColBlock *line, unsigned int numBlocks)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// flip a DXT5 alpha block
void CDDSImage::flip_dxt5_alpha(DXT5AlphaBlock *block)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// flip a DXT5 color block
void CDDSImage::flip_blocks_dxtc5(DXTColBlock *line, unsigned int numBlocks)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// CTexture implementation
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// default constructor
CTexture::CTexture()
  : CSurface()  // initialize base class part
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// creates an empty texture
CTexture::CTexture(unsigned int w, unsigned int h, unsigned int d, unsigned int imgsize, const unsigned char *pixels)
  : CSurface(w, h, d, imgsize, pixels)  // initialize base class part
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CTexture::~CTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// copy constructor
CTexture::CTexture(const CTexture &copy)
  : CSurface(copy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// assignment operator
CTexture &CTexture::operator= (const CTexture &rhs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CTexture::create(unsigned int w, unsigned int h, unsigned int d, unsigned int imgsize, const unsigned char *pixels)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CTexture::clear()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// CSurface implementation
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// default constructor
CSurface::CSurface()
  : m_width(0),
    m_height(0),
    m_depth(0),
    m_size(0),
    m_pixels(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// creates an empty image
CSurface::CSurface(unsigned int w, unsigned int h, unsigned int d, unsigned int imgsize, const unsigned char *pixels)
  : m_width(0),
    m_height(0),
    m_depth(0),
    m_size(0),
    m_pixels(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// copy constructor
CSurface::CSurface(const CSurface &copy)
  : m_width(0),
    m_height(0),
    m_depth(0),
    m_size(0),
    m_pixels(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// assignment operator
CSurface &CSurface::operator= (const CSurface &rhs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// clean up image memory
CSurface::~CSurface()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// returns a pointer to image
CSurface::operator unsigned char*() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// creates an empty image
void CSurface::create(unsigned int w, unsigned int h, unsigned int d, unsigned int imgsize, const unsigned char *pixels)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// free surface memory
void CSurface::clear()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
