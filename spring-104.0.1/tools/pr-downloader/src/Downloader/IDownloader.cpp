/* This file is part of pr-downloader (GPL v2 or later), see the LICENSE file */

#include "IDownloader.h"
#include "Download.h"
#include "Http/HttpDownloader.h"
#include "Rapid/RapidDownloader.h"
#include "Util.h"
#include "Logger.h"
#include "Mirror.h"
#include <curl/curl.h>

class IDownloader;

IDownloader* IDownloader::httpdl=NULL;
IDownloader* IDownloader::rapiddl=NULL;
IDownloaderProcessUpdateListener IDownloader::listener = nullptr;

void IDownloader::Initialize()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

void IDownloader::Shutdown()
{
	delete(httpdl);
	httpdl = NULL;
	delete(rapiddl);
	rapiddl = NULL;
	curl_global_cleanup();
}

IDownloader* IDownloader::GetHttpInstance()
{
	if (httpdl==NULL)
		httpdl=new CHttpDownloader();
	return httpdl;
}
IDownloader* IDownloader::GetRapidInstance()
{
	if (rapiddl==NULL)
		rapiddl=new CRapidDownloader();
	return rapiddl;
}

bool IDownloader::download(std::list<IDownload*>& download, int max_parallel)
{
	if (download.empty()) {
		LOG_ERROR("download list empty");
		return false;
	}
	bool res=true;
	for (IDownload* dl: download) {
		if (dl->state == IDownload::STATE_FINISHED) //don't download twice
			continue;

		if (!this->download(dl,max_parallel))
			res = false;
	}
	return res;
}

bool IDownloader::download(IDownload* dl, int max_parallel)
{
	std::list<IDownload*> dls;
	dls.push_back(dl);
	return download(dls,max_parallel);
}

void IDownloader::freeResult(std::list<IDownload*>& list)
{
	std::list<IDownload*>::iterator it;
	for(it=list.begin(); it!=list.end(); ++it) {
		delete *it;
	}
	list.clear();
}

bool IDownloader::setOption(const std::string& key, const std::string& value)
{
	LOG_ERROR("Invalid option: %s=%s", key.c_str(), value.c_str());
	return false;
}

void IDownloader::setProcessUpdateListener(IDownloaderProcessUpdateListener l) {
	IDownloader::listener = l;
}

