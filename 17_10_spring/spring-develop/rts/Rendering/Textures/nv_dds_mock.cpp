// TODO: Substitue Cnv_dds with your actual class name
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CAPS(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_HEIGHT(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_WIDTH(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_PITCH(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_PIXELFORMAT(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_MIPMAPCOUNT(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_LINEARSIZE(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_DEPTH(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_ALPHAPIXELS(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_FOURCC(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_RGB(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_RGBA(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_COMPLEX(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_TEXTURE(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_MIPMAP(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CUBEMAP(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CUBEMAP_POSITIVEX(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CUBEMAP_NEGATIVEX(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CUBEMAP_POSITIVEY(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CUBEMAP_NEGATIVEY(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CUBEMAP_POSITIVEZ(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CUBEMAP_NEGATIVEZ(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_CUBEMAP_ALL_FACES(){}
q(const).unsigned int Cnv_dds::nv_dds::DDSF_VOLUME(){}
q(const).unsigned int Cnv_dds::nv_dds::FOURCC_DXT1(){}
q(const).unsigned int Cnv_dds::nv_dds::FOURCC_DXT3(){}
q(const).unsigned int Cnv_dds::nv_dds::FOURCC_DXT5(){}
unsigned short Cnv_dds::col0(){}
unsigned short Cnv_dds::col1(){}
unsigned char Cnv_dds::row(){}
unsigned short Cnv_dds::row(){}
unsigned char Cnv_dds::alpha0(){}
unsigned char Cnv_dds::alpha1(){}
unsigned char Cnv_dds::row(){}
unsigned int Cnv_dds::dwSize(){}
unsigned int Cnv_dds::dwFlags(){}
unsigned int Cnv_dds::dwFourCC(){}
unsigned int Cnv_dds::dwRGBBitCount(){}
unsigned int Cnv_dds::dwRBitMask(){}
unsigned int Cnv_dds::dwGBitMask(){}
unsigned int Cnv_dds::dwBBitMask(){}
unsigned int Cnv_dds::dwABitMask(){}
unsigned int Cnv_dds::dwSize(){}
unsigned int Cnv_dds::dwFlags(){}
unsigned int Cnv_dds::dwHeight(){}
unsigned int Cnv_dds::dwWidth(){}
unsigned int Cnv_dds::dwPitchOrLinearSize(){}
unsigned int Cnv_dds::dwDepth(){}
unsigned int Cnv_dds::dwMipMapCount(){}
unsigned int Cnv_dds::dwReserved1(){}
nv_dds::DDS_PIXELFORMAT Cnv_dds::ddspf(){}
unsigned int Cnv_dds::dwCaps1(){}
unsigned int Cnv_dds::dwCaps2(){}
unsigned int Cnv_dds::dwReserved2(){}
nv_dds::CSurface Cnv_dds::operator =(const nv_dds::CSurface & rhs){}
nv_dds::CSurface Cnv_dds::operator =(nv_dds::CSurface rhs){}
unsigned char Cnv_dds::operator unsigned char*(){}
void Cnv_dds::create(unsigned int w, unsigned int h, unsigned int d, unsigned int imgsize, const unsigned char * pixels){}
void Cnv_dds::clear(){}
unsigned int Cnv_dds::m_width(){}
unsigned int Cnv_dds::m_height(){}
unsigned int Cnv_dds::m_depth(){}
unsigned int Cnv_dds::m_size(){}
unsigned char Cnv_dds::m_pixels(){}
nv_dds::CTexture Cnv_dds::operator =(const nv_dds::CTexture & rhs){}
nv_dds::CTexture Cnv_dds::operator =(nv_dds::CTexture rhs){}
void Cnv_dds::create(unsigned int w, unsigned int h, unsigned int d, unsigned int imgsize, const unsigned char * pixels){}
void Cnv_dds::clear(){}
std::deque<(nv_dds::CSurface)> Cnv_dds::m_mipmaps(){}
void Cnv_dds::create_textureFlat(unsigned int format, unsigned int components, const nv_dds::CTexture & baseImage){}
void Cnv_dds::create_texture3D(unsigned int format, unsigned int components, const nv_dds::CTexture & baseImage){}
void Cnv_dds::create_textureCubemap(unsigned int format, unsigned int components, const nv_dds::CTexture & positiveX, const nv_dds::CTexture & negativeX, const nv_dds::CTexture & positiveY, const nv_dds::CTexture & negativeY, const nv_dds::CTexture & positiveZ, const nv_dds::CTexture & negativeZ){}
void Cnv_dds::clear(){}
bool Cnv_dds::load(std::string filename, bool flipImage){}
bool Cnv_dds::load(std::string filename){}
bool Cnv_dds::save(std::string filename, bool flipImage){}
bool Cnv_dds::save(std::string filename){}
bool Cnv_dds::upload_texture1D(){}
bool Cnv_dds::upload_texture2D(unsigned int imageIndex, int target){}
bool Cnv_dds::upload_texture3D(){}
bool Cnv_dds::upload_textureRectangle(){}
bool Cnv_dds::upload_textureCubemap(){}
unsigned char Cnv_dds::operator unsigned char*(){}
bool Cnv_dds::is_compressed(){}
unsigned int Cnv_dds::clamp_size(unsigned int size){}
unsigned int Cnv_dds::size_dxtc(unsigned int width, unsigned int height){}
unsigned int Cnv_dds::size_rgb(unsigned int width, unsigned int height){}
void Cnv_dds::swap_endian(void * val){}
void Cnv_dds::flip(nv_dds::CSurface & surface){}
void Cnv_dds::flip_texture(nv_dds::CTexture & texture){}
void Cnv_dds::swap(void * byte1, void * byte2, unsigned int size){}
void Cnv_dds::flip_blocks_dxtc1(nv_dds::DXTColBlock * line, unsigned int numBlocks){}
void Cnv_dds::flip_blocks_dxtc3(nv_dds::DXTColBlock * line, unsigned int numBlocks){}
void Cnv_dds::flip_blocks_dxtc5(nv_dds::DXTColBlock * line, unsigned int numBlocks){}
void Cnv_dds::flip_dxt5_alpha(nv_dds::DXT5AlphaBlock * block){}
bool Cnv_dds::write_texture(const nv_dds::CTexture & texture, FILE * fp){}
unsigned int Cnv_dds::m_format(){}
unsigned int Cnv_dds::m_components(){}
nv_dds::TextureType Cnv_dds::m_type(){}
bool Cnv_dds::m_valid(){}
std::deque<(nv_dds::CTexture)> Cnv_dds::m_images(){}
