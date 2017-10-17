// TODO: Substitue CRoamMeshDrawer with your actual class name
void CRoamMeshDrawer::UnsyncedHeightMapUpdate(const SRectangle & rect){}
void CRoamMeshDrawer::DrawInMiniMap(){}
void CRoamMeshDrawer::Update(){}
void CRoamMeshDrawer::DrawMesh(const DrawPass::e & drawPass){}
void CRoamMeshDrawer::DrawBorderMesh(const DrawPass::e & drawPass){}
void CRoamMeshDrawer::Reset(bool shadowPass){}
bool CRoamMeshDrawer::Tessellate(std::vector<(Patch)> & patches, const CCamera * cam, int viewRadius, bool shadowPass){}
CSMFGroundDrawer CRoamMeshDrawer::smfGroundDrawer(){}
int CRoamMeshDrawer::numPatchesX(){}
int CRoamMeshDrawer::numPatchesY(){}
int CRoamMeshDrawer::lastGroundDetail(){}
float3 CRoamMeshDrawer::lastCamPos(){}
std::vector<(Patch)> CRoamMeshDrawer::patchMeshGrid(){}
std::vector<(p.Patch)> CRoamMeshDrawer::borderPatches(){}
std::vector<(uint8_t)> CRoamMeshDrawer::patchVisFlags(){}
bool CRoamMeshDrawer::forceTessellate(){}
