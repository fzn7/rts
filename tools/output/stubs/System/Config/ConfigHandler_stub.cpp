/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ConfigHandler.h"
#include "ConfigLocater.h"
#include "ConfigSource.h"
#include "System/Util.h"
#include "System/Log/ILog.h"

#ifdef WIN32
	#include <io.h>
#endif
#include <stdio.h>
#include <string.h>

#include <list>
#include <stdexcept>

#include <boost/thread/mutex.hpp>

/******************************************************************************/

using std::list;
using std::map;
using std::string;
using std::vector;

typedef map<string, string> StringMap;

ConfigHandler* configHandler = NULL;


/******************************************************************************/

class ConfigHandlerImpl : public ConfigHandler
{
    //stub method
}

ConfigHandlerImpl::~ConfigHandlerImpl()
{
    //stub method
}

/**
 * @brief Remove config variables that are set to their default value.
 *
 * Algorithm is as follows:
 *
 * 1) Take all defaults from the DefaultConfigSource
 * 2) Go in reverse through the FileConfigSources
 * 3) For each one:
 *  3a) delete setting if equal to the one in `defaults'
 *  3b) add new value to `defaults' if different
 */
void ConfigHandlerImpl::RemoveDefaults()
{
    //stub method
}


StringMap ConfigHandlerImpl::GetDataWithoutDefaults() const
{
    //stub method
}


void ConfigHandlerImpl::Delete(const string& key)
{
    //stub method
}

bool ConfigHandlerImpl::IsSet(const string& key) const
{
    //stub method
}

bool ConfigHandlerImpl::IsReadOnly(const string& key) const
{
    //stub method
}

string ConfigHandlerImpl::GetString(const string& key) const
{
    //stub method
}

/**
 * @brief Sets a config string
 *
 * This does:
 * 1) Lock file.
 * 2) Read file (in case another program modified something)
 * 3) Set data[key] = value.
 * 4) Write file (so we keep the settings in the event of a crash or error)
 * 5) Unlock file.
 *
 * We do not want conflicts when multiple instances are running
 * at the same time (which would cause data loss).
 * This would happen if e.g. unitsync and spring would access
 * the config file at the same time, if we would not lock.
 */
void ConfigHandlerImpl::SetString(const string& key, const string& value, bool useOverlay)
{
    //stub method
}

void ConfigHandlerImpl::Update()
{
    //stub method
}

string ConfigHandlerImpl::GetConfigFile() const {
	return writableSource->GetFilename();
}

const StringMap ConfigHandlerImpl::GetData() const {
	StringMap data;
	for_each_source_const(it) {
		const StringMap& sourceData = (*it)->GetData();
		// insert doesn't overwrite, so this preserves correct overrides
		data.insert(sourceData.begin(), sourceData.end());
	}
	return data;
}

void ConfigHandlerImpl::AddObserver(ConfigNotifyCallback observer, void* holder) {
	boost::mutex::scoped_lock lck(observerMutex);
	observers.emplace_back(observer, holder);
}

void ConfigHandlerImpl::RemoveObserver(void* holder) {
	boost::mutex::scoped_lock lck(observerMutex);
	for (list<NamedConfigNotifyCallback>::iterator it = observers.begin(); it != observers.end(); ++it) {
		if (it->holder == holder) {
			observers.erase(it);
			return;
		}
	}
}


/******************************************************************************/

void ConfigHandler::Instantiate(const std::string configSource, const bool safemode)
{
    //stub method
}

void ConfigHandler::Deallocate()
{
    //stub method
}

/******************************************************************************/
