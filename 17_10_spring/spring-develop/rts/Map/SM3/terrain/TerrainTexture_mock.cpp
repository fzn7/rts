// TODO: Substitue CTerrainTexture with your actual class name
std::vector<(p.BaseTexture)> CTerrainTexture::texUnits(){}
std::vector<(p.BaseTexture)> CTerrainTexture::coordUnits(){}
int CTerrainTexture::AddTextureCoordRead(int maxCoords, BaseTexture * texture){}
int CTerrainTexture::AddTextureRead(int maxUnits, BaseTexture * texture){}
void CTerrainTexture::Parse(const TdfParser & tdf, bool needNormalMap){}
void CTerrainTexture::Optimize(terrain::ShaderDef * dst){}
void CTerrainTexture::Output(){}
void CTerrainTexture::GetTextureUsage(terrain::TextureUsage * tu){}
std::vector<(terrain::ShaderDef::Stage)> CTerrainTexture::normalMapStages(){}
std::vector<(terrain::ShaderDef::Stage)> CTerrainTexture::stages(){}
bool CTerrainTexture::hasLighting(){}
bool CTerrainTexture::useShadowMapping(){}
float CTerrainTexture::specularExponent(){}
void CTerrainTexture::OptimizeStages(std::vector<(terrain::ShaderDef::Stage)> & src, std::vector<(terrain::ShaderDef::Stage)> & dst){}
void CTerrainTexture::LoadStages(int numStages, const char * stagename, const TdfParser & tdf, std::vector<(terrain::ShaderDef::Stage)> & stages){}
q(const).std::vector<(p.Blendmap)> CTerrainTexture::blendmaps(){}
q(const).std::vector<(p.TiledTexture)> CTerrainTexture::textures(){}
q(const).Vector3 CTerrainTexture::wsLightDir(){}
q(const).Vector3 CTerrainTexture::wsEyePos(){}
int CTerrainTexture::pass(){}
terrain::ShadowMapParams CTerrainTexture::shadowMapParams(){}
terrain::IShaderSetup CTerrainTexture::shaderSetup(){}
terrain::PassBlendop CTerrainTexture::operation(){}
bool CTerrainTexture::depthWrite(){}
bool CTerrainTexture::invertAlpha(){}
void CTerrainTexture::Clear(){}
void CTerrainTexture::DebugOutput(){}
std::vector<(terrain::RenderPass)> CTerrainTexture::passes(){}
terrain::ShaderDef CTerrainTexture::shaderDef(){}
std::vector<(p.terrain::RenderSetup)> CTerrainTexture::renderSetup(){}
uint CTerrainTexture::sortkey(){}
uint CTerrainTexture::vertexDataReq(){}
terrain::IShaderSetup CTerrainTexture::currentShaderSetup(){}
bool CTerrainTexture::SetupShader(terrain::IShaderSetup * shader, terrain::NodeSetupParams & params){}
void CTerrainTexture::BeginPass(const Blendmap)> & blendmaps, const TiledTexture)> & textures, int pass){}
void CTerrainTexture::EndPass(){}
int CTerrainTexture::MaxTextureUnits(){}
int CTerrainTexture::MaxTextureCoords(){}
void CTerrainTexture::BuildNodeSetup(terrain::ShaderDef * shaderDef, terrain::RenderSetup * rs){}
void CTerrainTexture::Load(const TdfParser * parser, terrain::Heightmap * heightmap, terrain::TQuad * quadTree, const terrain::QuadMap)> & qmaps, terrain::Config * cfg, terrain::ILoadCallback * cb, terrain::LightingInfo * li){}
void CTerrainTexture::ReloadShaders(terrain::TQuad * quadtree, terrain::Config * cfg){}
int CTerrainTexture::NumPasses(){}
void CTerrainTexture::BeginTexturing(){}
void CTerrainTexture::EndTexturing(){}
void CTerrainTexture::BeginPass(int p){}
void CTerrainTexture::EndPass(){}
bool CTerrainTexture::SetupNode(terrain::TQuad * q, int pass){}
void CTerrainTexture::DebugPrint(terrain::IFontRenderer * fr){}
void CTerrainTexture::DebugEvent(const std::string & event){}
void CTerrainTexture::SetShaderParams(const Vector3 & lv, const Vector3 & eyePos){}
void CTerrainTexture::SetShadowMapParams(const terrain::ShadowMapParams * smp){}
int CTerrainTexture::debugShader(){}
void CTerrainTexture::GenerateBlendmap(Blendmap * bm, terrain::Heightmap * heightmap, int level){}
void CTerrainTexture::InstantiateShaders(terrain::Config * cfg, terrain::ILoadCallback * cb){}
BaseTexture CTerrainTexture::LoadImageSource(const std::string & texName, const std::string & basepath, terrain::Heightmap * heightmap, terrain::ILoadCallback * cb, terrain::Config * cfg, bool isBumpmap){}
BaseTexture CTerrainTexture::LoadImageSource(const std::string & texName, const std::string & basepath, terrain::Heightmap * heightmap, terrain::ILoadCallback * cb, terrain::Config * cfg){}
bool CTerrainTexture::SetupShading(terrain::RenderPass * p, int passIndex){}
void CTerrainTexture::CreateTexProg(terrain::TQuad * node, terrain::TerrainTexture::GenerateInfo * gi){}
void CTerrainTexture::ReloadTexProg(terrain::TQuad * node, terrain::TerrainTexture::GenerateInfo * gi){}
uint CTerrainTexture::CalcBlendmapSortKey(){}
int CTerrainTexture::heightmapW(){}
int CTerrainTexture::blendmapLOD(){}
bool CTerrainTexture::useBumpMaps(){}
float CTerrainTexture::optimizeEpsilon(){}
DetailBumpmap CTerrainTexture::detailBumpmap(){}
terrain::TerrainTexture::ShaderDesc CTerrainTexture::unlitShader(){}
terrain::TerrainTexture::ShaderDesc CTerrainTexture::farShader(){}
terrain::TerrainTexture::ShaderDesc CTerrainTexture::nearShader(){}
std::vector<(p.terrain::TerrainTexture::ShaderDesc)> CTerrainTexture::shaders(){}
terrain::RenderSetup CTerrainTexture::currentRenderSetup(){}
terrain::ITexShaderHandler CTerrainTexture::shaderHandler(){}
Vector3 CTerrainTexture::wsLightDir(){}
Vector3 CTerrainTexture::wsEyePos(){}
std::vector<(p.Blendmap)> CTerrainTexture::blendMaps(){}
std::vector<(p.TiledTexture)> CTerrainTexture::textures(){}
std::vector<(p.terrain::RenderSetupCollection)> CTerrainTexture::texNodeSetup(){}
int CTerrainTexture::maxPasses(){}
q(const).TdfParser CTerrainTexture::tdfParser(){}
terrain::Lightmap CTerrainTexture::lightmap(){}
terrain::ShaderDef CTerrainTexture::shaderDef(){}
TiledTexture CTerrainTexture::flatBumpmap(){}
terrain::ShadowMapParams CTerrainTexture::shadowMapParams(){}
void CTerrainTexture::terrain::SetTexGen(float scale){}
