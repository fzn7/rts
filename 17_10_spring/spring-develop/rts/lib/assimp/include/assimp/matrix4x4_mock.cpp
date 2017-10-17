// TODO: Substitue Cmatrix4x4 with your actual class name
TReal Cmatrix4x4::operator [](unsigned int p_iIndex){}
q(const).TReal Cmatrix4x4::operator [](unsigned int p_iIndex){}
bool Cmatrix4x4::operator ==(const aiMatrix4x4t & m){}
bool Cmatrix4x4::operator !=(const aiMatrix4x4t & m){}
bool Cmatrix4x4::Equal(const aiMatrix4x4t & m, TReal epsilon){}
bool Cmatrix4x4::Equal(const aiMatrix4x4t & m){}
aiMatrix4x4t Cmatrix4x4::operator *=(const aiMatrix4x4t & m){}
aiMatrix4x4t Cmatrix4x4::operator *(const aiMatrix4x4t & m){}
aiMatrix4x4t Cmatrix4x4::Transpose(){}
aiMatrix4x4t Cmatrix4x4::Inverse(){}
TReal Cmatrix4x4::Determinant(){}
bool Cmatrix4x4::IsIdentity(){}
void Cmatrix4x4::Decompose(aiVector3t<(TReal)> & scaling, aiQuaterniont<(TReal)> & rotation, aiVector3t<(TReal)> & position){}
void Cmatrix4x4::DecomposeNoScaling(aiQuaterniont<(TReal)> & rotation, aiVector3t<(TReal)> & position){}
aiMatrix4x4t Cmatrix4x4::FromEulerAnglesXYZ(TReal x, TReal y, TReal z){}
aiMatrix4x4t Cmatrix4x4::FromEulerAnglesXYZ(const aiVector3t<(TReal)> & blubb){}
aiMatrix4x4t Cmatrix4x4::RotationX(TReal a, aiMatrix4x4t & out){}
aiMatrix4x4t Cmatrix4x4::RotationY(TReal a, aiMatrix4x4t & out){}
aiMatrix4x4t Cmatrix4x4::RotationZ(TReal a, aiMatrix4x4t & out){}
aiMatrix4x4t Cmatrix4x4::Rotation(TReal a, const aiVector3t<(TReal)> & axis, aiMatrix4x4t & out){}
aiMatrix4x4t Cmatrix4x4::Translation(const aiVector3t<(TReal)> & v, aiMatrix4x4t & out){}
aiMatrix4x4t Cmatrix4x4::Scaling(const aiVector3t<(TReal)> & v, aiMatrix4x4t & out){}
aiMatrix4x4t Cmatrix4x4::FromToMatrix(const aiVector3t<(TReal)> & from, const aiVector3t<(TReal)> & to, aiMatrix4x4t & out){}
TReal Cmatrix4x4::a1(){}
TReal Cmatrix4x4::a2(){}
TReal Cmatrix4x4::a3(){}
TReal Cmatrix4x4::a4(){}
TReal Cmatrix4x4::b1(){}
TReal Cmatrix4x4::b2(){}
TReal Cmatrix4x4::b3(){}
TReal Cmatrix4x4::b4(){}
TReal Cmatrix4x4::c1(){}
TReal Cmatrix4x4::c2(){}
TReal Cmatrix4x4::c3(){}
TReal Cmatrix4x4::c4(){}
TReal Cmatrix4x4::d1(){}
TReal Cmatrix4x4::d2(){}
TReal Cmatrix4x4::d3(){}
TReal Cmatrix4x4::d4(){}
aiMatrix4x4t Cmatrix4x4::PACK_STRUCT(){}
aiMatrix4x4t<(ai_real)> Cmatrix4x4::aiMatrix4x4(){}
