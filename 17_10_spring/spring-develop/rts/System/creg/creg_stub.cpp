#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/*
 * creg - Code compoment registration system
 * Classes for serialization of registrated class instances
 */

#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "System/Sync/HsiehHash.h"
#include "System/Util.h"
#include "creg_cond.h"

using namespace creg;

// -------------------------------------------------------------------
// some local statics, needed cause we work with global static vars
// -------------------------------------------------------------------

//=======================================================================


/*
void IType::Serialize(ISerializer* s, void* instance)
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string IType::GetName() const
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
}

size_t IType::GetSize() const
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
}

boost::shared_ptr<IType> IType::CreateBasicType(BasicTypeID t, size_t size)
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
}

boost::shared_ptr<IType> IType::CreateStringType()
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
}

boost::shared_ptr<IType> IType::CreateObjInstanceType(Class* objectType)
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;	
}

boost::shared_ptr<IType> IType::CreateIgnoredType(size_t size)
{
	//stub method
    std::cout << __FUNCTION__ << std::endl;
}
*/
//========================================================================
static std::unordered_map<const Class*, std::vector<Class*>>&
derivedClasses()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
	static std::unordered_map<const Class*, std::vector<Class*>> m;
	return m;
}

static std::unordered_map<std::string, Class*>&
mapNameToClass()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static std::vector<Class*>&
classes()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// -------------------------------------------------------------------
// Class Binder
// -------------------------------------------------------------------

ClassBinder::ClassBinder(const char* className,
                         ClassFlags cf,
                         ClassBinder* baseClsBinder,
                         void (*memberRegistrator)(creg::Class*),
                         int instanceSize,
                         int instanceAlignment,
                         bool hasVTable,
                         bool isCregStruct,
                         void (*constructorProc)(void* inst),
                         void (*destructorProc)(void* inst))
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
{
	class_.binder = this;
	class_.size = instanceSize;
	class_.alignment = instanceAlignment;
	System::AddClass(&class_);

	if (base) {
		derivedClasses()[&base->class_].push_back(&class_);
	}

	// Register members
	assert(memberRegistrator);
	memberRegistrator(&class_);
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// -------------------------------------------------------------------
// System
// -------------------------------------------------------------------

const std::vector<Class*>&
System::GetClasses()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Class*
System::GetClass(const std::string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
System::AddClass(Class* c)
{
	classes().push_back(c);
	mapNameToClass()[c->name] = c;
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// ------------------------------------------------------------------
// creg::Class: Class description
// ------------------------------------------------------------------

Class::Class(const char* _name)
  : binder(nullptr)
  , size(0)
  , alignment(0)
  , currentMemberFlags(0)
{
	name = _name;
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
Class::IsSubclassOf(Class* other) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<Class*>
Class::GetImplementations()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::vector<Class*>&
Class::GetDerivedClasses() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Class::BeginFlag(ClassMemberFlag flag)
{
	currentMemberFlags |= (int)flag;
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Class::EndFlag(ClassMemberFlag flag)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Class::SetFlag(ClassFlags flag)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Class::AddMember(const char* name,
                 boost::shared_ptr<IType> type,
                 unsigned int offset,
                 int alignment)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Class::Member*
Class::FindMember(const char* name, const bool inherited)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Class::SetMemberFlag(const char* name, ClassMemberFlag f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void*
Class::CreateInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Class::DeleteInstance(void* inst)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Class::CalculateChecksum(unsigned int& checksum)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
