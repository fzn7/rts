// TODO: Substitue CTextures with your actual class name
float CTextures::x(){}
float CTextures::y(){}
void CTextures::Alloc(int w, int h){}
bool CTextures::CopyFromBitmap(CBitmap & bm){}
terrain::AlphaImage CTextures::CreateMipmap(){}
void CTextures::Blit(terrain::AlphaImage * dst, int x, int y, int dstx, int dsty, int w, int h){}
bool CTextures::Save(const char * fn){}
terrain::AlphaImage::AreaTestResult CTextures::TestArea(int xstart, int ystart, int xend, int yend, float epsilon){}
int CTextures::w(){}
int CTextures::h(){}
float CTextures::data(){}
terrain::AlphaImage CTextures::lowDetail(){}
terrain::AlphaImage CTextures::highDetail(){}
void CTextures::CalcTexGenVector(float * v4){}
void CTextures::SetupTexGen(){}
std::string CTextures::name(){}
GLuint CTextures::id(){}
terrain::float2 CTextures::tilesize(){}
void CTextures::Load(const std::string & name, const std::string & section, terrain::ILoadCallback * cb, const TdfParser * tdf, bool isBumpmap){}
terrain::TiledTexture CTextures::CreateFlatBumpmap(){}
void CTextures::Generate(terrain::Heightmap * rootHm, int lodLevel, float hmscale, float hmoffset){}
void CTextures::Load(const std::string & name, const std::string & section, terrain::Heightmap * heightmap, terrain::ILoadCallback * cb, const TdfParser * tdf){}
terrain::Blendmap::GeneratorInfo CTextures::generatorInfo(){}
terrain::AlphaImage CTextures::image(){}
terrain::AlphaImage::AreaTestResult CTextures::curAreaResult(){}
void CTextures::CalcTexGenVector(float * v4){}
terrain::TQuad CTextures::node(){}
GLuint CTextures::terrain::LoadTexture(const std::string & fn, bool isBumpmap){}
GLuint CTextures::terrain::LoadTexture(const std::string & fn){}
void CTextures::terrain::SaveImage(const char * fn, int components, GLenum type, int w, int h, void * data){}
void CTextures::terrain::SetTexCoordGen(float * tgv){}
