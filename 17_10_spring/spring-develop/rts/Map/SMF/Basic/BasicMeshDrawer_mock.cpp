// TODO: Substitue CBasicMeshDrawer with your actual class name
int32_t CBasicMeshDrawer::PATCH_SIZE(){}
int32_t CBasicMeshDrawer::LOD_LEVELS(){}
void CBasicMeshDrawer::Update(){}
void CBasicMeshDrawer::UnsyncedHeightMapUpdate(const SRectangle & rect){}
void CBasicMeshDrawer::DrawMesh(const DrawPass::e & drawPass){}
void CBasicMeshDrawer::DrawBorderMesh(const DrawPass::e & drawPass){}
void CBasicMeshDrawer::UploadPatchSquareGeometry(uint32_t n, uint32_t px, uint32_t py, const float * chm, const float3 * cnm){}
void CBasicMeshDrawer::UploadPatchBorderGeometry(uint32_t n, uint32_t px, uint32_t py, const float * chm, const float3 * cnm){}
void CBasicMeshDrawer::UploadPatchBorderNormals(VBO & nrmlBuffer, const float3 & nrmlVector, uint32_t lodVerts){}
void CBasicMeshDrawer::UploadPatchIndices(uint32_t n){}
void CBasicMeshDrawer::DrawSquareMeshPatch(const CBasicMeshDrawer::MeshPatch & meshPatch, const VBO & indexBuffer, const CCamera * activeCam){}
void CBasicMeshDrawer::DrawBorderMeshPatch(const CBasicMeshDrawer::MeshPatch & meshPatch, const VBO & indexBuffer, const CCamera * activeCam, uint32_t borderSide){}
uint32_t CBasicMeshDrawer::CalcDrawPassLOD(const CCamera * cam, const DrawPass::e & drawPass){}
uint32_t CBasicMeshDrawer::numPatchesX(){}
uint32_t CBasicMeshDrawer::numPatchesY(){}
uint32_t CBasicMeshDrawer::drawPassLOD(){}
std::vector<(CBasicMeshDrawer::MeshPatch)> CBasicMeshDrawer::meshPatches(){}
std::array<(float,8)> CBasicMeshDrawer::lodDistTable(){}
std::array<(VBO,8)> CBasicMeshDrawer::lodSquareIndexBuffers(){}
std::array<(VBO,8)> CBasicMeshDrawer::lodBorderIndexBuffers(){}
CSMFGroundDrawer CBasicMeshDrawer::smfGroundDrawer(){}
