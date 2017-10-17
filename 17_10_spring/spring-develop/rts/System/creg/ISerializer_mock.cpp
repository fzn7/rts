// TODO: Substitue CISerializer with your actual class name
bool CISerializer::IsWriting(){}
void CISerializer::Serialize(void * data, int byteSize){}
void CISerializer::SerializeInt(void * data, int byteSize){}
void CISerializer::SerializeObjectPtr(void ** ptr, creg::Class * objectClass){}
void CISerializer::SerializeObjectInstance(void * inst, creg::Class * objectClass){}
void CISerializer::AddPostLoadCallback(void * cb, void * userdata){}
