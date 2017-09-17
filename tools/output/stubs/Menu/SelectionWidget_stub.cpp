/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SelectionWidget.h"

#include <set>

#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Exceptions.h"
#include "System/Config/ConfigHandler.h"
#include "System/AIScriptHandler.h"
#include "ExternalAI/LuaAIImplHandler.h"
#include "ExternalAI/Interface/SSkirmishAILibrary.h"
#include "System/Info.h"
#include "alphanum.hpp"

const std::string SelectionWidget::NoModSelect = "No game selected";
const std::string SelectionWidget::NoMapSelect = "No map selected";
const std::string SelectionWidget::NoScriptSelect = "No script selected";
const std::string SelectionWidget::SandboxAI = "Player Only: Testing Sandbox";

CONFIG(std::string, LastSelectedMod).defaultValue(SelectionWidget::NoModSelect).description("Stores the previously played game.");
CONFIG(std::string, LastSelectedMap).defaultValue(SelectionWidget::NoMapSelect).description("Stores the previously played map.");
CONFIG(std::string, LastSelectedScript).defaultValue(SelectionWidget::NoScriptSelect).description("Stores the previously played AI.");

// returns absolute filename for given archive name, empty if not found
static const std::string GetFileName(const std::string& name){
	if (name.empty())
		return name;
	const std::string& filename = archiveScanner->ArchiveFromName(name);
	if (filename == name)
		return "";
	const std::string& path = archiveScanner->GetArchivePath(filename);
	return path + filename;
}

SelectionWidget::SelectionWidget(agui::GuiElement* parent) : agui::GuiElement(parent)
{
    //stub method
}

SelectionWidget::~SelectionWidget()
{
    //stub method
}

void SelectionWidget::ShowModList()
{
    //stub method
}

void SelectionWidget::ShowMapList()
{
    //stub method
}


static void AddArchive(const std::string& name) {
	const std::string& filename = GetFileName(name);
	if (filename.empty())
		return;
	vfsHandler->AddArchive(filename, true);
}

static void RemoveArchive(const std::string& name) {
	const std::string& filename = GetFileName(name);
	if (filename.empty())
		return;
	vfsHandler->RemoveArchive(filename);
}

void SelectionWidget::UpdateAvailableScripts()
{
    //stub method
}

void SelectionWidget::ShowScriptList()
{
    //stub method
}

void SelectionWidget::SelectMod(const std::string& mod)
{
    //stub method
}

void SelectionWidget::SelectScript(const std::string& script)
{
    //stub method
}

void SelectionWidget::SelectMap(const std::string& map)
{
    //stub method
}

void SelectionWidget::CleanWindow()
{
    //stub method
}
