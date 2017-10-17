// TODO: Substitue CEFX with your actual class name
void CEFX::SetPreset(const std::string & name, bool verbose, bool commit){}
void CEFX::SetPreset(const std::string & name, bool verbose){}
void CEFX::SetPreset(const std::string & name){}
void CEFX::CommitEffects(){}
void CEFX::Enable(){}
void CEFX::Disable(){}
void CEFX::SetHeightRolloffModifer(const float & mod){}
void CEFX::ConfigNotify(const std::string & key, const std::string & value){}
void CEFX::SetAirAbsorptionFactor(ALfloat value){}
int CEFX::updates(){}
int CEFX::maxSlots(){}
bool CEFX::enabled(){}
bool CEFX::supported(){}
EAXSfxProps CEFX::sfxProperties(){}
ALuint CEFX::sfxSlot(){}
ALuint CEFX::sfxReverb(){}
ALuint CEFX::sfxFilter(){}
ALuint CEFX::maxSlotsPerSource(){}
ALfloat CEFX::airAbsorptionFactor(){}
float CEFX::heightRolloffModifier(){}
spring::unsynced_map<(ALuint,bool)> CEFX::effectsSupported(){}
spring::unsynced_map<(ALuint,bool)> CEFX::filtersSupported(){}
CEFX CEFX::efx(){}
