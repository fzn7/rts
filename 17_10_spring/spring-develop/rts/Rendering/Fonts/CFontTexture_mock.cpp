// TODO: Substitue CCFontTexture with your actual class name
FT_FaceRec_ CCFontTexture::FT_Face(){}
float CCFontTexture::x(){}
float CCFontTexture::y(){}
float CCFontTexture::w(){}
float CCFontTexture::h(){}
IGlyphRect CCFontTexture::size(){}
IGlyphRect CCFontTexture::texCord(){}
IGlyphRect CCFontTexture::shadowTexCord(){}
float CCFontTexture::advance(){}
float CCFontTexture::height(){}
float CCFontTexture::descender(){}
unsigned int CCFontTexture::index(){}
char32_t CCFontTexture::utf16(){}
FT_Face CCFontTexture::face(){}
void CCFontTexture::Update(){}
q(const).GlyphInfo CCFontTexture::GetGlyph(char32_t ch){}
float CCFontTexture::GetKerning(const GlyphInfo & lgl, const GlyphInfo & rgl){}
void CCFontTexture::UpdateTexture(){}
void CCFontTexture::CreateTexture(const int width, const int height){}
void CCFontTexture::LoadBlock(char32_t start, char32_t end){}
void CCFontTexture::LoadGlyph(std::shared_ptr<(FontFace)> & f, char32_t ch, unsigned int index){}
spring::unsynced_map<(char32_t,GlyphInfo)> CCFontTexture::glyphs(){}
spring::unsynced_map<(uint32_t,float)> CCFontTexture::kerningDynamic(){}
float CCFontTexture::kerningPrecached(){}
int CCFontTexture::outlineSize(){}
float CCFontTexture::outlineWeight(){}
float CCFontTexture::lineHeight(){}
float CCFontTexture::fontDescender(){}
float CCFontTexture::normScale(){}
int CCFontTexture::fontSize(){}
std::string CCFontTexture::fontFamily(){}
std::string CCFontTexture::fontStyle(){}
int CCFontTexture::texWidth(){}
int CCFontTexture::texHeight(){}
int CCFontTexture::wantedTexWidth(){}
int CCFontTexture::wantedTexHeight(){}
unsigned int CCFontTexture::texture(){}
unsigned int CCFontTexture::textureSpaceMatrix(){}
CBitmap CCFontTexture::atlasUpdate(){}
CBitmap CCFontTexture::atlasUpdateShadow(){}
int CCFontTexture::lastTextureUpdate(){}
FT_Face CCFontTexture::face(){}
int CCFontTexture::curTextureUpdate(){}
std::shared_ptr<(FontFace)> CCFontTexture::shFace(){}
spring::unsynced_set<(std::shared_ptr<(FontFace)>)> CCFontTexture::usedFallbackFonts(){}
CRowAtlasAlloc CCFontTexture::atlasAlloc(){}
