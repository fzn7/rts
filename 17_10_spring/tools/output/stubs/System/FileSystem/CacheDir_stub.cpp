#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CacheDir.h"

#include "FileSystem.h"

#include <stdio.h>
#include <string>

// as defiend here: http://www.brynosaurus.com/cachedir/spec.html
const std::string CacheDir::tagFile_name = "CACHEDIR.TAG";
const std::string CacheDir::tagFile_content =
  "Signature: 8a477f597d28d172789f06886806bc55";
const size_t CacheDir::tagFile_content_size = 43;
const std::string CacheDir::defaultAdditionalText =
  "# This file is a cache directory tag created by Spring.\n"
  "# For information about cache directory tags, see:\n"
  "# http://www.brynosaurus.com/cachedir/";

bool
CacheDir::IsCacheDir(const std::string& dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CacheDir::SetCacheDir(const std::string& dir,
                      bool wantedCacheState,
                      const std::string& additionalText,
                      bool forceRewrite)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CacheDir::FileContentStartsWith(const std::string& filePath,
                                const std::string& content,
                                size_t content_size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CacheDir::WriteCacheTagFile(const std::string& filePath,
                            const std::string& additionalText)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CacheDir::GetCacheTagFilePath(const std::string& dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
