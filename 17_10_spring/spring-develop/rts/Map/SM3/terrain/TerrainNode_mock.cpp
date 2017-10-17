// TODO: Substitue CTerrainNode with your actual class name
int CTerrainNode::x(){}
int CTerrainNode::y(){}
q(const).int CTerrainNode::terrain::QUAD_W(){}
q(const).int CTerrainNode::terrain::VERTC(){}
q(const).int CTerrainNode::terrain::MAX_INDICES(){}
q(const).int CTerrainNode::terrain::NUM_VERTICES(){}
q(const).float CTerrainNode::terrain::SquareSize(){}
q(const).float CTerrainNode::terrain::VBufMinDetail(){}
q(const).float CTerrainNode::terrain::AREA_TEST_RANGE(){}
void CTerrainNode::Build(terrain::Heightmap * hm, terrain::int2 sqStart, terrain::int2 hmStart, terrain::int2 quadPos, int w, int depth){}
void CTerrainNode::Draw(terrain::IndexTable * indexTable, bool onlyPositions, int lodState){}
bool CTerrainNode::InFrustum(Frustum * f){}
float CTerrainNode::CalcLod(const Vector3 & campos){}
void CTerrainNode::CollectNodes(terrain::TQuad)> & quads){}
void CTerrainNode::FreeCachedTexture(){}
terrain::TQuad CTerrainNode::FindSmallestContainingQuad2D(const Vector3 & pos, float range, int maxlevel){}
int CTerrainNode::GetVertexSize(){}
std::vector<(p.Sm3VisibilityNode)> CTerrainNode::nodeLinks(){}
terrain::TQuad CTerrainNode::parent(){}
terrain::TQuad CTerrainNode::children(){}
Vector3 CTerrainNode::start(){}
Vector3 CTerrainNode::end(){}
terrain::int2 CTerrainNode::qmPos(){}
terrain::int2 CTerrainNode::hmPos(){}
terrain::int2 CTerrainNode::sqPos(){}
int CTerrainNode::depth(){}
int CTerrainNode::width(){}
terrain::RenderSetupCollection CTerrainNode::textureSetup(){}
GLuint CTerrainNode::cacheTexture(){}
float CTerrainNode::maxLodValue(){}
enum terrain::TQuad::DrawState CTerrainNode::drawState(){}
terrain::QuadNormals CTerrainNode::normalData(){}
terrain::QuadRenderData CTerrainNode::renderData(){}
int CTerrainNode::lodState(){}
terrain::TQuad CTerrainNode::quad(){}
terrain::Camera CTerrainNode::cam(){}
bool CTerrainNode::needsTexturing(){}
bool CTerrainNode::needsNormalMap(){}
std::vector<(terrain::QuadRenderInfo)> CTerrainNode::quads(){}
uint CTerrainNode::GetDataSize(){}
GLuint CTerrainNode::normalMap(){}
uint CTerrainNode::normalMapW(){}
uint CTerrainNode::normalMapTexWidth(){}
VertexBuffer CTerrainNode::vertexBuffer(){}
int CTerrainNode::vertexSize(){}
int CTerrainNode::index(){}
bool CTerrainNode::used(){}
terrain::TQuad CTerrainNode::quad(){}
void CTerrainNode::Free(terrain::QuadRenderData * qrd){}
void CTerrainNode::FreeUnused(){}
void CTerrainNode::PruneFreeList(int maxFreeRD){}
void CTerrainNode::PruneFreeList(){}
void CTerrainNode::InitializeNode(terrain::TQuad * q){}
void CTerrainNode::InitializeNodeNormalMap(terrain::TQuad * q, int cfgNormalMapLevel){}
void CTerrainNode::UpdateRect(int sx, int sy, int w, int h){}
int CTerrainNode::normalDataAllocates(){}
int CTerrainNode::renderDataAllocates(){}
terrain::QuadRenderData CTerrainNode::Allocate(){}
std::vector<(p.terrain::QuadRenderData)> CTerrainNode::qrd(){}
std::vector<(p.terrain::QuadRenderData)> CTerrainNode::freeRD(){}
terrain::Heightmap CTerrainNode::roothm(){}
terrain::QuadMap CTerrainNode::rootQMap(){}
void CTerrainNode::Alloc(int W, int H){}
void CTerrainNode::LodScaleDown(terrain::Heightmap * dst){}
void CTerrainNode::FindMinMax(terrain::int2 st, terrain::int2 size, float & minHgt, float & maxHgt, bool synced){}
void CTerrainNode::FindMinMax(terrain::int2 st, terrain::int2 size, float & minHgt, float & maxHgt){}
terrain::Heightmap CTerrainNode::CreateLowDetailHM(){}
void CTerrainNode::GenerateNormals(){}
void CTerrainNode::UpdateLowerUnsynced(int sx, int sy, int w, int h){}
q(const).terrain::Heightmap CTerrainNode::GetLevel(int level){}
int CTerrainNode::w(){}
int CTerrainNode::h(){}
std::vector<(float)> CTerrainNode::dataSynced(){}
std::vector<(float)> CTerrainNode::dataUnsynced(){}
float CTerrainNode::squareSize(){}
uchar CTerrainNode::normalData(){}
terrain::Heightmap CTerrainNode::lowDetail(){}
terrain::Heightmap CTerrainNode::highDetail(){}
void CTerrainNode::Alloc(int W){}
void CTerrainNode::Fill(terrain::TQuad * root){}
int CTerrainNode::w(){}
terrain::TQuad CTerrainNode::map(){}
terrain::QuadMap CTerrainNode::highDetail(){}
terrain::QuadMap CTerrainNode::lowDetail(){}
unsigned short CTerrainNode::index_t(){}
void CTerrainNode::Calculate(int sides){}
int CTerrainNode::size(){}
IndexBuffer CTerrainNode::buffers(){}
