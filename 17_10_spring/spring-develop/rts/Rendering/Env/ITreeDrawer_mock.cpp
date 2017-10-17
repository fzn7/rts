// TODO: Substitue CITreeDrawer with your actual class name
q(const).int CITreeDrawer::TREE_SQUARE_SIZE(){}
q(const).float CITreeDrawer::MID_TREE_DIST_FACTOR(){}
q(const).float CITreeDrawer::FADE_TREE_DIST_FACTOR(){}
q(const).float CITreeDrawer::FAR_TREE_DIST_FACTOR(){}
ITreeDrawer CITreeDrawer::GetTreeDrawer(){}
void CITreeDrawer::SetupState(){}
void CITreeDrawer::ResetState(){}
void CITreeDrawer::Draw(){}
void CITreeDrawer::Draw(float treeDistance){}
void CITreeDrawer::Update(){}
void CITreeDrawer::ResetPos(const float3 & pos){}
void CITreeDrawer::AddTree(int treeID, int treeType, const float3 & pos, float size){}
void CITreeDrawer::DeleteTree(int treeID, const float3 & pos){}
void CITreeDrawer::RenderFeatureCreated(const CFeature * feature){}
void CITreeDrawer::FeatureMoved(const CFeature * feature, const float3 & oldpos){}
void CITreeDrawer::RenderFeatureDestroyed(const CFeature * feature){}
std::vector<(ITreeDrawer::TreeSquareStruct)> CITreeDrawer::treeSquares(){}
std::vector<(GLuint)> CITreeDrawer::delDispLists(){}
void CITreeDrawer::AddTrees(){}
float CITreeDrawer::baseTreeDistance(){}
int CITreeDrawer::treesX(){}
int CITreeDrawer::treesY(){}
int CITreeDrawer::nTrees(){}
bool CITreeDrawer::drawTrees(){}
bool CITreeDrawer::wireFrameMode(){}
ITreeDrawer CITreeDrawer::treeDrawer(){}
