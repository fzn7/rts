// TODO: Substitue CSpringController with your actual class name
void CSpringController::KeyMove(float3 move){}
void CSpringController::MouseMove(float3 move){}
void CSpringController::ScreenEdgeMove(float3 move){}
void CSpringController::MouseWheelMove(float move){}
void CSpringController::Update(){}
float3 CSpringController::GetPos(){}
void CSpringController::SwitchTo(const int oldCam, const bool showText){}
void CSpringController::GetState(StateMap & sm){}
bool CSpringController::SetState(const StateMap & sm){}
float CSpringController::GetAzimuth(){}
float CSpringController::MoveAzimuth(float move){}
float CSpringController::ZoomIn(const float3 & curCamPos, const float2 & zoomParams){}
float CSpringController::ZoomOut(const float3 & curCamPos, const float2 & zoomParams){}
float3 CSpringController::rot(){}
float CSpringController::curDist(){}
float CSpringController::maxDist(){}
float CSpringController::oldDist(){}
bool CSpringController::zoomBack(){}
bool CSpringController::cursorZoomIn(){}
bool CSpringController::cursorZoomOut(){}
