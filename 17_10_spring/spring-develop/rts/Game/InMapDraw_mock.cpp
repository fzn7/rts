// TODO: Substitue CInMapDraw with your actual class name
void CInMapDraw::MousePress(int x, int y, int button){}
void CInMapDraw::MouseRelease(int x, int y, int button){}
void CInMapDraw::MouseMove(int x, int y, int dx, int dy, int button){}
int CInMapDraw::GotNetMsg(netcode::RawPacket)> & packet){}
void CInMapDraw::SendPoint(const float3 & pos, const std::string & label, bool fromLua){}
void CInMapDraw::SendLine(const float3 & pos1, const float3 & pos2, bool fromLua){}
void CInMapDraw::SendErase(const float3 & pos){}
void CInMapDraw::SendWaitingInput(const std::string & label){}
void CInMapDraw::PromptLabel(const float3 & pos){}
void CInMapDraw::GetPoints(std::vector<(PointMarker)> & points, size_t maxPoints, const std::list<(int)> & teamIDs){}
void CInMapDraw::GetLines(std::vector<(LineMarker)> & lines, size_t maxLines, const std::list<(int)> & teamIDs){}
void CInMapDraw::SetSpecMapDrawingAllowed(bool state){}
void CInMapDraw::SetLuaMapDrawingAllowed(bool state){}
float3 CInMapDraw::GetMouseMapPos(){}
bool CInMapDraw::drawMode(){}
bool CInMapDraw::wantLabel(){}
float CInMapDraw::lastLeftClickTime(){}
float CInMapDraw::lastDrawTime(){}
float3 CInMapDraw::lastPos(){}
float3 CInMapDraw::waitingPoint(){}
bool CInMapDraw::allowSpecMapDrawing(){}
bool CInMapDraw::allowLuaMapDrawing(){}
CNotificationPeeper CInMapDraw::notificationPeeper(){}
CInMapDraw CInMapDraw::inMapDrawer(){}
