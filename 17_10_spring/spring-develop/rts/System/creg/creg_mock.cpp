#include <vector>
#include <string>
#include <string.h>

#include "creg_cond.h"
#include "System/UnorderedMap.hpp"
#include "System/StringUtil.h"
#include "System/Sync/HsiehHash.h"


using namespace creg;




Class::Class(const char* _name)
: binder(nullptr)
, size(0)
, alignment(0)
, currentMemberFlags(0)
{
	name = _name;
}



 std::shared_ptr<IType> IType::CreateBasicType(BasicTypeID t, size_t size){};
		 std::shared_ptr<IType> IType::CreateStringType(){};
		 std::shared_ptr<IType> IType::CreateObjInstanceType(Class* objectType){};
	 std::shared_ptr<IType> IType::CreateIgnoredType(size_t size){};






ClassBinder::ClassBinder(const char* className, ClassFlags cf,
		ClassBinder* baseClsBinder, void (*memberRegistrator)(creg::Class*), int instanceSize, int instanceAlignment, bool hasVTable, bool isCregStruct,
		void (*constructorProc)(void* inst), void (*destructorProc)(void* inst), void* (*allocProc)(), void (*freeProc)(void* instance))
	: class_(className)
	, base(baseClsBinder)
	, flags(cf)
	, name(className)
	, size(instanceSize)
	, alignment(instanceAlignment)
	, hasVTable(hasVTable)
	, isCregStruct(isCregStruct)
	, constructor(constructorProc)
	, destructor(destructorProc)
	, poolAlloc(allocProc)
	, poolFree(freeProc)
{
	class_.binder = this;
	class_.size = instanceSize;
	class_.alignment = instanceAlignment;
	System::AddClass(&class_);

/*
	if (base) {
		derivedClasses()[&base->class_].push_back(&class_);
	}
*/
	// Register members
	assert(memberRegistrator);
	memberRegistrator(&class_);
}



// TODO: Substitue Ccreg with your actual class name
/*unsigned int creg::creg::uint(){}
void creg::Serialize(ISerializer * s, void * instance){}
std::string creg::GetName(){}
size_t creg::GetSize(){}
std::shared_ptr<creg::IType> creg::CreateBasicType(creg::BasicTypeID t, size_t size){}
std::shared_ptr<creg::IType> creg::CreateStringType(){}
std::shared_ptr<creg::IType> creg::CreateObjInstanceType(creg::Class * objectType){}
std::shared_ptr<creg::IType> creg::CreateIgnoredType(size_t size){}*/
bool Class::IsSubclassOf(Class * other) const {}
void* Class::CreateInstance(){}
void Class::DeleteInstance(void * inst){}
void Class::CalculateChecksum(unsigned int & checksum){}
void Class::AddMember(const char * name, std::shared_ptr<IType> type, unsigned int offset, int alignment){}
void Class::SetMemberFlag(const char * name, ClassMemberFlag f){}
Class::Member* Class::FindMember(const char * name, const bool inherited){}
void Class::BeginFlag(ClassMemberFlag flag){}
void Class::EndFlag(ClassMemberFlag flag){}
void Class::SetFlag(ClassFlags flag){}
//bool creg::IsAbstract(){}
//creg::Class creg::base(){}
std::vector<Class*> Class::GetImplementations(){}
const std::vector<Class*>& Class::GetDerivedClasses() const{}
/*std::vector<creg::Class::Member> creg::members(){}
creg::ClassBinder creg::binder(){}
std::string creg::name(){}
int creg::size(){}
int creg::alignment(){}
std::function<(f(p.void,p.ISerializer).void)> creg::serializeProc(){}
std::function<(f(p.void).void)> creg::postLoadProc(){}
int creg::currentMemberFlags(){}
creg::Class creg::class_(){}
creg::ClassBinder creg::base(){}
creg::ClassFlags creg::flags(){}
q(const).char creg::name(){}
int creg::size(){}
int creg::alignment(){}
bool creg::hasVTable(){}
bool creg::isCregStruct(){}
void creg::constructor(void * instance){}
void creg::destructor(void * instance){}
void creg::poolAlloc(){}
void creg::poolFree(void * instance){}
std::vector<Class*>& System::GetClasses(){}*/
Class* System::GetClass(const std::string & name){}
void System::AddClass(Class * c){}
