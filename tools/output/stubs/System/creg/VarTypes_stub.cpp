#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/*
 * creg - Code compoment registration system
 * Classes for serialization of registrated class instances
 */

#include "VarTypes.h"

#include "System/Util.h"

#include <assert.h>

using namespace creg;
using std::string;

// serialization code

// type instance allocators

void
BasicType::Serialize(ISerializer* s, void* inst)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
BasicType::GetName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
BasicType::GetSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<IType>
IType::CreateBasicType(BasicTypeID t, size_t size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
StringType::GetName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
StringType::GetSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

StringType::StringType(boost::shared_ptr<IType> charType)
  : DynamicArrayType<string>(charType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ObjectInstanceType::Serialize(ISerializer* s, void* inst)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
ObjectInstanceType::GetName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
ObjectInstanceType::GetSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<IType>
IType::CreateObjInstanceType(Class* objectType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string
StaticArrayBaseType::GetName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::shared_ptr<IType>
IType::CreateIgnoredType(size_t size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
