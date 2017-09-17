#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <algorithm>
#include <cassert>
#include <cctype>

#include "CategoryHandler.h"

#include "System/creg/STL_Map.h"
#include "System/Util.h"
#include "System/Log/ILog.h"

CR_BIND(CCategoryHandler, )

CR_REG_METADATA(CCategoryHandler, (
	CR_MEMBER(categories),
	CR_MEMBER(firstUnused)
))

CCategoryHandler* CCategoryHandler::instance = NULL;

CCategoryHandler* CCategoryHandler::Instance() {
	assert(instance != NULL);
	return instance;
}


void CCategoryHandler::CreateInstance() {
	if (instance == NULL) {
		instance = new CCategoryHandler();
	}
}

void CCategoryHandler::RemoveInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned int CCategoryHandler::GetCategory(std::string name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned int CCategoryHandler::GetCategories(std::string names)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::vector<std::string> CCategoryHandler::GetCategoryNames(unsigned int bits) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

