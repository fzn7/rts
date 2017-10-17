// TODO: Substitue CLineDrawer with your actual class name
void CLineDrawer::Configure(bool useColorRestarts, bool useRestartColor, const float * restartColor, float restartAlpha){}
void CLineDrawer::SetupLineStipple(){}
void CLineDrawer::UpdateLineStipple(){}
void CLineDrawer::StartPath(const float3 & pos, const float * color){}
void CLineDrawer::FinishPath(){}
void CLineDrawer::DrawLine(const float3 & endPos, const float * color){}
void CLineDrawer::DrawLineAndIcon(int cmdID, const float3 & endPos, const float * color){}
void CLineDrawer::DrawIconAtLastPos(int cmdID){}
void CLineDrawer::Break(const float3 & endPos, const float * color){}
void CLineDrawer::Restart(){}
void CLineDrawer::RestartSameColor(){}
void CLineDrawer::RestartWithColor(const float * color){}
void CLineDrawer::DrawAll(){}
bool CLineDrawer::lineStipple(){}
bool CLineDrawer::useColorRestarts(){}
bool CLineDrawer::useRestartColor(){}
float CLineDrawer::restartAlpha(){}
q(const).float CLineDrawer::restartColor(){}
float3 CLineDrawer::lastPos(){}
q(const).float CLineDrawer::lastColor(){}
float CLineDrawer::stippleTimer(){}
std::vector<(LinePair)> CLineDrawer::lines(){}
std::vector<(LinePair)> CLineDrawer::stippled(){}
CLineDrawer CLineDrawer::lineDrawer(){}
