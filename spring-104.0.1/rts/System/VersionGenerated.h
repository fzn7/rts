/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/*
 * Do NOT include this file directly, but include the wrapper instead.
 * This prevents wastefull recompiling.
 */

#ifndef VERSION_GENERATED_H
#define VERSION_GENERATED_H

/// examples: "83.0" "83.0.1-13-g1234567 develop"
static const char* SPRING_VERSION_ENGINE            = "104.0.1-390-g4f6cf16 develop";

/// examples: "83"
static const char* SPRING_VERSION_ENGINE_MAJOR      = "104";

/// examples: "0"
static const char* SPRING_VERSION_ENGINE_PATCH_SET  = "0";

/// examples: "13"
static const char* SPRING_VERSION_ENGINE_COMMITS    = "390";

/// examples: "1234567"
static const char* SPRING_VERSION_ENGINE_HASH       = "4f6cf16";

/// examples: "develop"
static const char* SPRING_VERSION_ENGINE_BRANCH     = "develop";

/// examples: "what a splendid day, isn't it?"
static const char* SPRING_VERSION_ENGINE_ADDITIONAL = "what a splendid day, isn't it?";

/// examples: true, false
static bool        SPRING_VERSION_ENGINE_RELEASE    = true;

#endif // VERSION_GENERATED_H

 
 
 
