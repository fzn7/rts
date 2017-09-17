/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/EventHandler.h"

#include "LuaVFSDownload.h"
#include "System/Util.h"
#include "System/EventHandler.h"
#include "System/Platform/Threading.h"
#include "System/Threading/SpringMutex.h"
#include "System/FileSystem/ArchiveScanner.h"

#include <queue>

#include "LuaInclude.h"
#include "../tools/pr-downloader/src/pr-downloader.h"

/******************************************************************************/
/******************************************************************************/
#define REGISTER_LUA_CFUNC(x) \
        lua_pushstring(L, #x);      \
        lua_pushcfunction(L, x);    \
        lua_rawset(L, -3)

LuaVFSDownload* luavfsdownload = nullptr;

struct dlEvent {
	int ID;
	virtual void processEvent() = 0;
	virtual ~dlEvent(){}
};

struct dlStarted : public dlEvent {
	void processEvent() {
		eventHandler.DownloadStarted(ID);
	}
};
struct dlFinished : public dlEvent {
	void processEvent() {
		eventHandler.DownloadFinished(ID);
	}
};
struct dlFailed : public dlEvent {
	int errorID;
	void processEvent() {
		eventHandler.DownloadFailed(ID, errorID);
	}
};
struct dlProgress : public dlEvent {
	long downloaded;
	long total;
	void processEvent() {
		eventHandler.DownloadProgress(ID, downloaded, total);
	}
};

std::queue<dlEvent*> dlEventQueue;
spring::mutex dlEventQueueMutex;

void AddQueueEvent(dlEvent* ev) {
	dlEventQueueMutex.lock();
	dlEventQueue.push(ev);
	dlEventQueueMutex.unlock();
}

void QueueDownloadStarted(int ID) //queue from other thread download started event
{
    //stub method
}

void QueueDownloadFinished(int ID) //queue from other thread download started event
{
    //stub method
}

void QueueDownloadFailed(int ID, int errorID) //queue from other thread download started event
{
    //stub method
}

void QueueDownloadProgress(int ID, long downloaded, long total) //queue from other thread download started event
{
    //stub method
}


LuaVFSDownload::LuaVFSDownload():
	CEventClient("[LuaVFSDownload]", 314161, false)
{
    //stub method
}

LuaVFSDownload::~LuaVFSDownload()
{
    //stub method
}


bool LuaVFSDownload::PushEntries(lua_State* L)
{
    //stub method
}

struct DownloadItem {
	int ID;
	std::string filename;
	DownloadEnum::Category cat;
	DownloadItem(int ID, const std::string& filename, DownloadEnum::Category& cat) : ID(ID), filename(filename), cat(cat) {
	}
};

static int queueIDCount = -1;
static int currentDownloadID = -1;
static std::list<DownloadItem> queue;
static bool isDownloading = false;
spring::mutex queueMutex;

void StartDownload();

void UpdateProgress(int done, int size) {
	QueueDownloadProgress(currentDownloadID, done, size);
}

__FORCE_ALIGN_STACK__
int Download(int ID, const std::string& filename, DownloadEnum::Category cat)
{
    //stub method
}

void StartDownload() {
	isDownloading = true;
	const DownloadItem downloadItem = queue.front();
	queue.pop_front();
	const std::string& filename = downloadItem.filename;
	DownloadEnum::Category cat = downloadItem.cat;
	int ID = downloadItem.ID;
	if (!filename.empty()) {
		LOG_L(L_DEBUG, "DOWNLOADING: %s", filename.c_str());
	}
	boost::thread {[ID, filename, cat]() {
			const int result = Download(ID, filename, cat);
			if (result == 0) {
				QueueDownloadFinished(ID);
			} else {
				QueueDownloadFailed(ID, result);
			}

			queueMutex.lock();
			if (!queue.empty()) {
				queueMutex.unlock();
				StartDownload();
			} else {
				isDownloading = false;
				queueMutex.unlock();
			}
		}
	}.detach();
}

/******************************************************************************/

int LuaVFSDownload::DownloadArchive(lua_State* L)
{
    //stub method
}

void LuaVFSDownload::Update()
{
    //stub method
}

