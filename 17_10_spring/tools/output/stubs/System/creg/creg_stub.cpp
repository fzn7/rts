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

static std::unordered_map<const Class*, std::vector<Class*>>&
derivedClasses()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::unordered_map<std::string, Class*>&
mapNameToClass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::vector<Class*>&
classes()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
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
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// -------------------------------------------------------------------
// System
// -------------------------------------------------------------------

const std::vector<Class*>&
System::GetClasses()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Class*
System::GetClass(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
System::AddClass(Class* c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
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
    std::cout << _FUNCTION_ << std::endl;
}

bool
Class::IsSubclassOf(Class* other) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<Class*>
Class::GetImplementations()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::vector<Class*>&
Class::GetDerivedClasses() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Class::BeginFlag(ClassMemberFlag flag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Class::EndFlag(ClassMemberFlag flag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Class::SetFlag(ClassFlags flag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Class::AddMember(const char* name,
                 boost::shared_ptr<IType> type,
                 unsigned int offset,
                 int alignment)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Class::Member*
Class::FindMember(const char* name, const bool inherited)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Class::SetMemberFlag(const char* name, ClassMemberFlag f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void*
Class::CreateInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Class::DeleteInstance(void* inst)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Class::CalculateChecksum(unsigned int& checksum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
