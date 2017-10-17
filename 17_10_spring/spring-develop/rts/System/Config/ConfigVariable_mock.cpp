// TODO: Substitue CConfigVariable with your actual class name
TypedStringConvertibleOptionalValue<(std::string)> CConfigVariable::OptionalString(){}
TypedStringConvertibleOptionalValue<(int)> CConfigVariable::OptionalInt(){}
q(const).StringConvertibleOptionalValue CConfigVariable::GetDefaultValue(){}
q(const).StringConvertibleOptionalValue CConfigVariable::GetMinimumValue(){}
q(const).StringConvertibleOptionalValue CConfigVariable::GetMaximumValue(){}
q(const).StringConvertibleOptionalValue CConfigVariable::GetSafemodeValue(){}
q(const).StringConvertibleOptionalValue CConfigVariable::GetHeadlessValue(){}
q(const).StringConvertibleOptionalValue CConfigVariable::GetDedicatedValue(){}
std::string CConfigVariable::Clamp(const std::string & value){}
q(const).char CConfigVariable::key(){}
q(const).char CConfigVariable::type(){}
ConfigVariableMetaData::OptionalString CConfigVariable::declarationFile(){}
ConfigVariableMetaData::OptionalInt CConfigVariable::declarationLine(){}
ConfigVariableMetaData::OptionalString CConfigVariable::description(){}
ConfigVariableMetaData::OptionalInt CConfigVariable::readOnly(){}
TypedStringConvertibleOptionalValue<(T)> CConfigVariable::defaultValue(){}
TypedStringConvertibleOptionalValue<(T)> CConfigVariable::minimumValue(){}
TypedStringConvertibleOptionalValue<(T)> CConfigVariable::maximumValue(){}
TypedStringConvertibleOptionalValue<(T)> CConfigVariable::safemodeValue(){}
TypedStringConvertibleOptionalValue<(T)> CConfigVariable::headlessValue(){}
TypedStringConvertibleOptionalValue<(T)> CConfigVariable::dedicatedValue(){}
ConfigVariableTypedMetaData<(T)> CConfigVariable::data(){}
std::map<(std::string,p.q(const).ConfigVariableMetaData)> CConfigVariable::MetaDataMap(){}
q(const).ConfigVariable::MetaDataMap CConfigVariable::GetMetaDataMap(){}
q(const).ConfigVariableMetaData CConfigVariable::GetMetaData(const std::string & key){}
void CConfigVariable::OutputMetaDataMap(){}
ConfigVariable::MetaDataMap CConfigVariable::GetMutableMetaDataMap(){}
void CConfigVariable::AddMetaData(const ConfigVariableMetaData * data){}
