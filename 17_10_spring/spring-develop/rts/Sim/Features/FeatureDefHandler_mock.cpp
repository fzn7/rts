// TODO: Substitue CFeatureDefHandler with your actual class name
void CFeatureDefHandler::LoadFeatureDefsFromMap(){}
q(const).FeatureDef CFeatureDefHandler::GetFeatureDef(std::string name, const bool showError){}
q(const).FeatureDef CFeatureDefHandler::GetFeatureDef(std::string name){}
FeatureDef CFeatureDefHandler::CreateDefaultTreeFeatureDef(const std::string & name){}
FeatureDef CFeatureDefHandler::CreateDefaultGeoFeatureDef(const std::string & name){}
FeatureDef CFeatureDefHandler::CreateFeatureDef(const LuaTable & luaTable, const std::string & name){}
FeatureDef CFeatureDefHandler::GetNewFeatureDef(){}
void CFeatureDefHandler::AddFeatureDef(const std::string & name, FeatureDef * feature, bool isDefaultFeature){}
spring::unordered_map<(std::string,int)> CFeatureDefHandler::featureDefs(){}
std::vector<(FeatureDef)> CFeatureDefHandler::featureDefsVector(){}
CFeatureDefHandler CFeatureDefHandler::featureDefHandler(){}
