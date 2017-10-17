// TODO: Substitue Cmatrix3x3 with your actual class name
aiMatrix3x3t Cmatrix3x3::operator *=(const aiMatrix3x3t & m){}
aiMatrix3x3t Cmatrix3x3::operator *(const aiMatrix3x3t & m){}
TReal Cmatrix3x3::operator [](unsigned int p_iIndex){}
q(const).TReal Cmatrix3x3::operator [](unsigned int p_iIndex){}
bool Cmatrix3x3::operator ==(const aiMatrix4x4t<(TReal)> & m){}
bool Cmatrix3x3::operator !=(const aiMatrix4x4t<(TReal)> & m){}
bool Cmatrix3x3::Equal(const aiMatrix4x4t<(TReal)> & m, TReal epsilon){}
bool Cmatrix3x3::Equal(const aiMatrix4x4t<(TReal)> & m){}
aiMatrix3x3t Cmatrix3x3::Transpose(){}
aiMatrix3x3t Cmatrix3x3::Inverse(){}
TReal Cmatrix3x3::Determinant(){}
aiMatrix3x3t Cmatrix3x3::RotationZ(TReal a, aiMatrix3x3t & out){}
aiMatrix3x3t Cmatrix3x3::Rotation(TReal a, const aiVector3t<(TReal)> & axis, aiMatrix3x3t & out){}
aiMatrix3x3t Cmatrix3x3::Translation(const aiVector2t<(TReal)> & v, aiMatrix3x3t & out){}
aiMatrix3x3t Cmatrix3x3::FromToMatrix(const aiVector3t<(TReal)> & from, const aiVector3t<(TReal)> & to, aiMatrix3x3t & out){}
TReal Cmatrix3x3::a1(){}
TReal Cmatrix3x3::a2(){}
TReal Cmatrix3x3::a3(){}
TReal Cmatrix3x3::b1(){}
TReal Cmatrix3x3::b2(){}
TReal Cmatrix3x3::b3(){}
TReal Cmatrix3x3::c1(){}
TReal Cmatrix3x3::c2(){}
TReal Cmatrix3x3::c3(){}
aiMatrix3x3t Cmatrix3x3::PACK_STRUCT(){}
aiMatrix3x3t<(ai_real)> Cmatrix3x3::aiMatrix3x3(){}
