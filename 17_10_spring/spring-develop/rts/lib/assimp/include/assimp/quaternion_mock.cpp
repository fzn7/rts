// TODO: Substitue Cquaternion with your actual class name
aiMatrix3x3t<(TReal)> Cquaternion::GetMatrix(){}
bool Cquaternion::operator ==(const aiQuaterniont & o){}
bool Cquaternion::operator !=(const aiQuaterniont & o){}
bool Cquaternion::Equal(const aiQuaterniont & o, TReal epsilon){}
bool Cquaternion::Equal(const aiQuaterniont & o){}
aiQuaterniont Cquaternion::Normalize(){}
aiQuaterniont Cquaternion::Conjugate(){}
aiVector3t<(TReal)> Cquaternion::Rotate(const aiVector3t<(TReal)> & in){}
aiQuaterniont Cquaternion::operator *(const aiQuaterniont & two){}
void Cquaternion::Interpolate(aiQuaterniont & pOut, const aiQuaterniont & pStart, const aiQuaterniont & pEnd, TReal pFactor){}
TReal Cquaternion::w(){}
TReal Cquaternion::x(){}
TReal Cquaternion::y(){}
TReal Cquaternion::z(){}
aiQuaterniont<(ai_real)> Cquaternion::aiQuaternion(){}
