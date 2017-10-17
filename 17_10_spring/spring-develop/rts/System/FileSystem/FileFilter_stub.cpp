#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FileFilter.h"

#include <boost/regex.hpp>

#include <ctype.h>
#include <limits.h>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class CFileFilter : public IFileFilter
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/** @brief Add a filtering rule.

A rule can be:
 - An empty line, this is ignored,
 - A line starting with a '#', this serves as a comment and is ignored,
 - A path starting with a path separator ('/' or '\'): this is an absolute
   path and matches only against the entire leading part of the filename
   passed to Match(): '/foo' matches 'foo' and 'foo/bar', but not 'bar/foo'.
 - Any other path is a relative path and is matched less strict: as long as
   there is a consecutive set of path elements matching the rule, there is a
   match: 'b/c/d' matches 'b/c/d', but also 'a/b/c/d/e'.

Note that:
 - Leading and trailing whitespace is ignored.
 - Globbing characters '*' and '?' can be used, both do NOT match path
   separators (like in shell, but unlike fnmatch(), or so I've been told.)
   e.g. 'foo\\*\\baz' matches 'foo/bar/baz' but not 'foo/ba/r/baz'.
 - Any path separator matches any other path separator, so there is no need to
   worry about converting them: 'foo/bar' matches 'foo\\bar' and 'foo:bar' too.
 - A path can be prefixed with an exclamation mark '!', this negates the
   pattern. Because the rules are matched in-order, one can use this to exclude
   a file from a more generic pattern.
 - By default, no file matches. This can be changed using AddRule("*") ofc.
*/
void
CFileFilter::AddRule(const string& rule)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/** @brief Checks whether filename matches this filter. */
bool
CFileFilter::Match(const string& filename) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

string
CFileFilter::glob_to_regex(const string& glob) // FIXME remove; duplicate in
                                               // FileSystem::ConvertGlobToRegex
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
