/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/*
 * creg - Code compoment registration system
 * Classes for serialization of registrated class instances
 */

#include <unordered_map>
#include <vector>
#include <string>
#include <string.h>

#include "creg_cond.h"
#include "System/Util.h"
#include "System/Sync/HsiehHash.h"


using namespace creg;

// -------------------------------------------------------------------
// some local statics, needed cause we work with global static vars
// -------------------------------------------------------------------

static std::unordered_map<const Class*, std::vector<Class*>>& derivedClasses()
{
    //stub method
}

static std::unordered_map<std::string, Class*>& mapNameToClass()
{
    //stub method
}

static std::vector<Class*>& classes()
{
    //stub method
}

// -------------------------------------------------------------------
// Class Binder
// -------------------------------------------------------------------

ClassBinder::ClassBinder(const char* className, ClassFlags cf,
		ClassBinder* baseClsBinder, void (*memberRegistrator)(creg::Class*), int instanceSize, int instanceAlignment, bool hasVTable, bool isCregStruct,
		void (*constructorProc)(void* inst), void (*destructorProc)(void* inst))
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
    //stub method
}


// -------------------------------------------------------------------
// System
// -------------------------------------------------------------------

const std::vector<Class*>& System::GetClasses()
{
    //stub method
}

Class* System::GetClass(const std::string& name)
{
    //stub method
}

void System::AddClass(Class* c)
{
    //stub method
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
    //stub method
}


bool Class::IsSubclassOf(Class* other) const
{
    //stub method
}

std::vector<Class*> Class::GetImplementations()
{
    //stub method
}


const std::vector<Class*>& Class::GetDerivedClasses() const
{
    //stub method
}


void Class::BeginFlag(ClassMemberFlag flag)
{
    //stub method
}

void Class::EndFlag(ClassMemberFlag flag)
{
    //stub method
}

void Class::SetFlag(ClassFlags flag)
{
    //stub method
}

void Class::AddMember(const char* name, boost::shared_ptr<IType> type, unsigned int offset, int alignment)
{
    //stub method
}

Class::Member* Class::FindMember(const char* name, const bool inherited)
{
    //stub method
}

void Class::SetMemberFlag(const char* name, ClassMemberFlag f)
{
    //stub method
}

void* Class::CreateInstance()
{
    //stub method
}

void Class::DeleteInstance(void* inst)
{
    //stub method
}

void Class::CalculateChecksum(unsigned int& checksum)
{
    //stub method
}

