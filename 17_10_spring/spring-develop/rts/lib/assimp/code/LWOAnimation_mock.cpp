// TODO: Substitue CLWOAnimation with your actual class name
float CLWOAnimation::time(){}
float CLWOAnimation::value(){}
Assimp::LWO::InterpolationType CLWOAnimation::inter(){}
float CLWOAnimation::params(){}
float CLWOAnimation::operator float(){}
unsigned int CLWOAnimation::index(){}
Assimp::LWO::EnvelopeType CLWOAnimation::type(){}
Assimp::LWO::PrePostBehaviour CLWOAnimation::pre(){}
Assimp::LWO::PrePostBehaviour CLWOAnimation::post(){}
std::vector<(Assimp::LWO::Key)> CLWOAnimation::keys(){}
size_t CLWOAnimation::old_first(){}
size_t CLWOAnimation::old_last(){}
void CLWOAnimation::ExtractBindPose(aiMatrix4x4 & out){}
void CLWOAnimation::ExtractAnimChannel(aiNodeAnim ** out, unsigned int flags){}
void CLWOAnimation::ExtractAnimChannel(aiNodeAnim ** out){}
void CLWOAnimation::GetKeys(std::vector<(aiVectorKey)> & out, Assimp::LWO::Envelope * envl_x, Assimp::LWO::Envelope * envl_y, Assimp::LWO::Envelope * envl_z, unsigned int flags){}
void CLWOAnimation::DoInterpolation(std::vector<(Assimp::LWO::Key)>::const_iterator cur, Assimp::LWO::Envelope * envl, float time, float & fill){}
void CLWOAnimation::DoInterpolation2(std::vector<(Assimp::LWO::Key)>::const_iterator beg, std::vector<(Assimp::LWO::Key)>::const_iterator end, float time, float & fill){}
void CLWOAnimation::InterpolateTrack(std::vector<(aiVectorKey)> & out, aiVectorKey & key_out, float time){}
void CLWOAnimation::SubsampleAnimTrack(std::vector<(aiVectorKey)> & out, float time, float sample_delta){}
void CLWOAnimation::ClearAnimRangeSetup(){}
void CLWOAnimation::UpdateAnimRangeSetup(){}
std::list<(Assimp::LWO::Envelope)> CLWOAnimation::envelopes(){}
float CLWOAnimation::sample_rate(){}
Assimp::LWO::Envelope CLWOAnimation::trans_x(){}
Assimp::LWO::Envelope CLWOAnimation::trans_y(){}
Assimp::LWO::Envelope CLWOAnimation::trans_z(){}
Assimp::LWO::Envelope CLWOAnimation::rotat_x(){}
Assimp::LWO::Envelope CLWOAnimation::rotat_y(){}
Assimp::LWO::Envelope CLWOAnimation::rotat_z(){}
Assimp::LWO::Envelope CLWOAnimation::scale_x(){}
Assimp::LWO::Envelope CLWOAnimation::scale_y(){}
Assimp::LWO::Envelope CLWOAnimation::scale_z(){}
float CLWOAnimation::first(){}
float CLWOAnimation::last(){}
bool CLWOAnimation::need_to_setup(){}
Assimp::LWO::Envelope CLWOAnimation::envl_x(){}
Assimp::LWO::Envelope CLWOAnimation::envl_y(){}
Assimp::LWO::Envelope CLWOAnimation::envl_z(){}
std::vector<(Assimp::LWO::Key)>::const_iterator CLWOAnimation::cur_x(){}
std::vector<(Assimp::LWO::Key)>::const_iterator CLWOAnimation::cur_y(){}
std::vector<(Assimp::LWO::Key)>::const_iterator CLWOAnimation::cur_z(){}
bool CLWOAnimation::end_x(){}
bool CLWOAnimation::end_y(){}
bool CLWOAnimation::end_z(){}
unsigned int CLWOAnimation::flags(){}
float CLWOAnimation::sample_delta(){}
