// TODO: Substitue CBitmap with your actual class name
CBitmap CBitmap::operator =(const CBitmap & bmp){}
CBitmap CBitmap::operator =(CBitmap bmp){}
void CBitmap::Alloc(int w, int h, int c){}
void CBitmap::Alloc(int w, int h){}
void CBitmap::AllocDummy(const SColor fill){}
void CBitmap::AllocDummy(){}
bool CBitmap::Load(const std::string & filename, unsigned char defaultAlpha){}
bool CBitmap::Load(const std::string & filename){}
bool CBitmap::LoadGrayscale(const std::string & filename){}
bool CBitmap::Save(const std::string & filename, bool opaque, bool logged){}
bool CBitmap::Save(const std::string & filename, bool opaque){}
bool CBitmap::Save(const std::string & filename){}
bool CBitmap::SaveFloat(const std::string & filename){}
unsigned int CBitmap::CreateTexture(float aniso, bool mipmaps){}
unsigned int CBitmap::CreateTexture(float aniso){}
unsigned int CBitmap::CreateTexture(){}
unsigned int CBitmap::CreateDDSTexture(unsigned int texID, float aniso, bool mipmaps){}
unsigned int CBitmap::CreateDDSTexture(unsigned int texID, float aniso){}
unsigned int CBitmap::CreateDDSTexture(unsigned int texID){}
unsigned int CBitmap::CreateDDSTexture(){}
void CBitmap::CreateAlpha(unsigned char red, unsigned char green, unsigned char blue){}
void CBitmap::SetTransparent(const SColor & c, const SColor trans){}
void CBitmap::SetTransparent(const SColor & c){}
void CBitmap::Renormalize(float3 newCol){}
void CBitmap::Blur(int iterations, float weight){}
void CBitmap::Blur(int iterations){}
void CBitmap::Blur(){}
void CBitmap::CopySubImage(const CBitmap & src, int x, int y){}
SDL_Surface CBitmap::CreateSDLSurface(){}
std::vector<(unsigned char)> CBitmap::mem(){}
int CBitmap::xsize(){}
int CBitmap::ysize(){}
int CBitmap::channels(){}
bool CBitmap::compressed(){}
int CBitmap::textype(){}
nv_dds::CDDSImage CBitmap::ddsimage(){}
CBitmap CBitmap::CanvasResize(const int newx, const int newy, const bool center){}
CBitmap CBitmap::CanvasResize(const int newx, const int newy){}
CBitmap CBitmap::CreateRescaled(int newx, int newy){}
void CBitmap::ReverseYAxis(){}
void CBitmap::InvertColors(){}
void CBitmap::InvertAlpha(){}
void CBitmap::MakeGrayScale(){}
void CBitmap::Tint(const float tint){}
