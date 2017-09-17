#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <cctype>
#include <limits.h>
#include <stdexcept>
#include <sstream>

#include <boost/scoped_array.hpp>

#include "tdf_grammar.h"
#include "System/TdfParser.h"
#include "System/Util.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"

TdfParser::parse_error::parse_error(size_t l, size_t c, std::string const& f) throw()
	: content_error("Parse error in " + f + " at line " + IntToString(l) + " column " + IntToString(c) + ".")
	, line(l)
	, column(c)
	, filename(f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TdfParser::TdfSection* TdfParser::TdfSection::construct_subsection(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool TdfParser::TdfSection::remove(const std::string& key, bool caseSensitive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void TdfParser::TdfSection::add_name_value(const std::string& name, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TdfParser::TdfSection::~TdfSection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



TdfParser::TdfParser(char const* buf, size_t size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TdfParser::TdfParser(std::string const& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TdfParser::~TdfParser()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void TdfParser::print(std::ostream & out) const {
	root_section.print(out);
}


void TdfParser::parse_buffer(char const* buf, size_t size) {

	std::list<std::string> junk_data;
	tdf_grammar grammar(&root_section, &junk_data);
	parse_info<char const*> info;
	std::string message;
	typedef position_iterator2<char const*> iterator_t;
	iterator_t error_it(buf, buf + size);

	try {
		info = parse(
			buf
			, buf + size
			, grammar
			, space_p
				| comment_p("/*", "*/") // rule for C-comments
				| comment_p("//")
			);
	} catch (const parser_error<tdf_grammar::Errors, char const*>& ex) { // thrown by assertion parsers in tdf_grammar

		switch(ex.descriptor) {
			case tdf_grammar::semicolon_expected: message = "semicolon expected"; break;
			case tdf_grammar::equals_sign_expected: message = "equals sign in name value pair expected"; break;
			case tdf_grammar::square_bracket_expected: message = "square bracket to close section name expected"; break;
			case tdf_grammar::brace_expected: message = "brace or further name value pairs expected"; break;
			default: message = "unknown boost::spirit::parser_error exception"; break;
		};

		std::ptrdiff_t target_pos = ex.where - buf;
		for (int i = 1; i < target_pos; ++i) {
			++error_it;
			if (error_it != (iterator_t(buf + i, buf + size))) {
				++i;
			}
		}
	}

	for (std::list<std::string>::const_iterator it = junk_data.begin(), e = junk_data.end(); it !=e ; ++it) {
		std::string temp = StringTrim(*it);
		if (!temp.empty()) {
			LOG_L(L_WARNING, "TdfParser: Junk in %s: %s",
					filename.c_str(), temp.c_str());
		}
	}

	if (!message.empty()) {
		throw parse_error(message, error_it.get_currentline(), error_it.get_position().line, error_it.get_position().column, filename);
	}

	// a different error might have happened:
	if (!info.full) {
		std::ptrdiff_t target_pos = info.stop - buf;
		for (int i = 1; i < target_pos; ++i) {
			++error_it;
			if (error_it != (iterator_t(buf + i, buf + size))) {
				++i;
			}
		}

		throw parse_error(error_it.get_currentline(), error_it.get_position().line, error_it.get_position().column, filename);
	}
}

void TdfParser::LoadBuffer(char const* buf, size_t size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void TdfParser::LoadFile(std::string const& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string TdfParser::SGetValueDef(std::string const& defaultValue, std::string const& location) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool TdfParser::SGetValue(std::string &value, std::string const& location) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool TdfParser::GetValue(bool& val, const std::string& location) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const TdfParser::valueMap_t& TdfParser::GetAllValues(std::string const& location) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<std::string> TdfParser::GetSectionList(std::string const& location) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool TdfParser::SectionExist(std::string const& location) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<std::string> TdfParser::GetLocationVector(std::string const& location) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 TdfParser::GetFloat3(float3 def, std::string const& location) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
