#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <cctype>
#include <limits.h>
#include <sstream>
#include <stdexcept>

#include <boost/scoped_array.hpp>

#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/TdfParser.h"
#include "System/Util.h"
#include "tdf_grammar.h"

TdfParser::parse_error::parse_error(size_t l,
                                    size_t c,
                                    std::string const& f) throw()
  : content_error("Parse error in " + f + " at line " + IntToString(l) +
                  " column " + IntToString(c) + ".")
  , line(l)
  , column(c)
  , filename(f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
size_t
TdfParser::parse_error::get_column() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
std::string const&
TdfParser::parse_error::get_filename() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TdfParser::TdfSection::print(std::ostream& out) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

TdfParser::TdfSection*
TdfParser::TdfSection::construct_subsection(const std::string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
TdfParser::TdfSection::remove(const std::string& key, bool caseSensitive)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TdfParser::TdfSection::add_name_value(const std::string& name,
                                      const std::string& value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

TdfParser::TdfSection::~TdfSection()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

TdfParser::TdfParser(char const* buf, size_t size)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

TdfParser::TdfParser(std::string const& filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

TdfParser::~TdfParser() {}

void
TdfParser::print(std::ostream& out) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TdfParser::parse_buffer(char const* buf, size_t size)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TdfParser::LoadBuffer(char const* buf, size_t size)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TdfParser::LoadFile(std::string const& filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
TdfParser::SGetValueDef(std::string const& defaultValue,
                        std::string const& location) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
TdfParser::SGetValue(std::string& value, std::string const& location) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
TdfParser::GetValue(bool& val, const std::string& location) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const TdfParser::valueMap_t&
TdfParser::GetAllValues(std::string const& location) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
TdfParser::GetSectionList(std::string const& location) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
TdfParser::SectionExist(std::string const& location) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
TdfParser::GetLocationVector(std::string const& location) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
TdfParser::GetFloat3(float3 def, std::string const& location) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
