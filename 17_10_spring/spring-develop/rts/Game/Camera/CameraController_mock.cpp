// TODO: Substitue CCameraController with your actual class name
std::map<(std::string,float)> CCameraController::StateMap(){}
q(const).std::string CCameraController::GetName(){}
void CCameraController::KeyMove(float3 move){}
void CCameraController::MouseMove(float3 move){}
void CCameraController::ScreenEdgeMove(float3 move){}
void CCameraController::MouseWheelMove(float move){}
float3 CCameraController::SwitchFrom(){}
void CCameraController::SwitchTo(const int oldCam, const bool showText){}
void CCameraController::SwitchTo(const int oldCam){}
void CCameraController::GetState(CCameraController::StateMap & sm){}
bool CCameraController::SetState(const CCameraController::StateMap & sm){}
bool CCameraController::GetUseDistToGroundForIcons(){}
bool CCameraController::enabled(){}
bool CCameraController::SetStateBool(const CCameraController::StateMap & sm, const std::string & name, bool & var){}
bool CCameraController::SetStateFloat(const CCameraController::StateMap & sm, const std::string & name, float & var){}
float CCameraController::fov(){}
float3 CCameraController::pos(){}
float3 CCameraController::dir(){}
float CCameraController::scrollSpeed(){}
float CCameraController::switchVal(){}
float CCameraController::pixelSize(){}
