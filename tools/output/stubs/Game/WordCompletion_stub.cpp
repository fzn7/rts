/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

//  TODO: replace 'WordProperties' with regex/glob expressions
//        ex: '/give [0-9]* [_0-9a-zA-Z]+'
//        or even create a domain specific language
//        ex: '/give <ammount> {unitname} <team-ID>'
//        user-input: '/give 10 armcom 1'


#include "WordCompletion.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <stdexcept>
#include <algorithm>

CWordCompletion* CWordCompletion::singleton = NULL;

void CWordCompletion::CreateInstance() {
	if (singleton == NULL) {
		singleton = new CWordCompletion();
	} else {
		throw std::logic_error("WordCompletion singleton is already initialized");
	}
}

void CWordCompletion::DestroyInstance() {
	if (singleton != NULL) {
		SafeDelete(singleton);
	} else {
		throw std::logic_error("WordCompletion singleton was not initialized or is already destroyed");
	}
}



CWordCompletion::CWordCompletion()
{
    //stub method
}

void CWordCompletion::Reset()
{
    //stub method
}


void CWordCompletion::AddWord(const std::string& word, bool startOfLine,
		bool unitName, bool miniMap)
{
    //stub method
}

void CWordCompletion::RemoveWord(const std::string& word)
{
    //stub method
}


std::vector<std::string> CWordCompletion::Complete(std::string& msg) const
{
    //stub method
}
