/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
	\mainpage
	This is the documentation of the Spring RTS Engine.
	https://springrts.com/
*/


#include "System/SpringApp.h"

#include "System/Exceptions.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Platform/errorhandler.h"
#include "System/Platform/Threading.h"
#include "System/Platform/Misc.h"
#include "System/Log/ILog.h"

#ifdef WIN32
	#include "lib/SOP/SOP.hpp" // NvOptimus

	#include <stdlib.h>
	#include <process.h>
	#define setenv(k,v,o) SetEnvironmentVariable(k,v)
#endif



int Run(int argc, char* argv[])
{
    //stub method
}


/**
 * Always run on dedicated GPU
 * @return true when restart is required with new env vars
 */
static bool SetNvOptimusProfile(const std::string& processFileName)
{
    //stub method
}



/**
 * @brief main
 * @return exit code
 * @param argc argument count
 * @param argv array of argument strings
 *
 * Main entry point function
 */
int main(int argc, char* argv[])
{
    //stub method
}



#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstanceIn, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //stub method
}
#endif

