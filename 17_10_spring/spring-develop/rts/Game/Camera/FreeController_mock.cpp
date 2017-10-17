// TODO: Substitue CFreeController with your actual class name
void CFreeController::Move(const float3 & move, bool tilt, bool strafe, bool upDown){}
void CFreeController::KeyMove(float3 move){}
void CFreeController::MouseMove(float3 move){}
void CFreeController::ScreenEdgeMove(float3 move){}
void CFreeController::MouseWheelMove(float move){}
void CFreeController::Update(){}
float3 CFreeController::GetDir(){}
void CFreeController::SetPos(const float3 & newPos){}
void CFreeController::SetTrackingInfo(const float3 & pos, float radius){}
float3 CFreeController::SwitchFrom(){}
void CFreeController::SwitchTo(const int oldCam, const bool showText){}
void CFreeController::GetState(StateMap & sm){}
bool CFreeController::SetState(const StateMap & sm){}
float3 CFreeController::vel(){}
float3 CFreeController::avel(){}
float3 CFreeController::prevVel(){}
float3 CFreeController::prevAvel(){}
float3 CFreeController::rot(){}
float3 CFreeController::trackPos(){}
float CFreeController::trackRadius(){}
float CFreeController::tiltSpeed(){}
float CFreeController::velTime(){}
float CFreeController::avelTime(){}
float CFreeController::gndOffset(){}
float CFreeController::gravity(){}
float CFreeController::autoTilt(){}
float CFreeController::slide(){}
bool CFreeController::tracking(){}
bool CFreeController::gndLock(){}
bool CFreeController::invertAlt(){}
bool CFreeController::goForward(){}
