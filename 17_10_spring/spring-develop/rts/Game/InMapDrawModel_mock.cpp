// TODO: Substitue CInMapDrawModel with your actual class name
q(const).size_t CInMapDrawModel::DRAW_QUAD_SIZE(){}
q(const).float CInMapDrawModel::QUAD_SCALE(){}
void CInMapDrawModel::PostLoad(){}
bool CInMapDrawModel::AddPoint(const float3 & pos, const std::string & label, int playerID){}
bool CInMapDrawModel::AddLine(const float3 & pos1, const float3 & pos2, int playerID){}
void CInMapDrawModel::EraseNear(const float3 & pos, int playerID){}
void CInMapDrawModel::EraseAll(){}
q(const).CInMapDrawModel::DrawQuad CInMapDrawModel::GetDrawQuad(int x, int y){}
bool CInMapDrawModel::AllowedMsg(const CPlayer * sender){}
int CInMapDrawModel::drawQuadsX(){}
int CInMapDrawModel::drawQuadsY(){}
std::vector<(CInMapDrawModel::DrawQuad)> CInMapDrawModel::drawQuads(){}
bool CInMapDrawModel::drawAllMarks(){}
size_t CInMapDrawModel::numPoints(){}
size_t CInMapDrawModel::numLines(){}
CInMapDrawModel CInMapDrawModel::inMapDrawerModel(){}
