// TODO: Substitue CFrustum with your actual class name
void CFrustum::CalcCameraPlanes(Vector3 * base, Vector3 * right, Vector3 * up, Vector3 * front, float tanHalfFov, float aspect){}
void CFrustum::InversePlanes(){}
Frustum::VisType CFrustum::IsBoxVisible(const Vector3 & min, const Vector3 & max){}
Frustum::VisType CFrustum::IsPointVisible(const Vector3 & pt){}
void CFrustum::Draw(){}
std::vector<(Plane)> CFrustum::planes(){}
Vector3 CFrustum::base(){}
Vector3 CFrustum::pos(){}
Vector3 CFrustum::front(){}
Vector3 CFrustum::right(){}
Vector3 CFrustum::up(){}
