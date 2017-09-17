/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SelectMenu.h"

#include <SDL_keycode.h>
#include <boost/bind.hpp>
#include <sstream>
#include <stack>
#include <boost/cstdint.hpp>

#include "SelectionWidget.h"
#include "System/AIScriptHandler.h"
#include "Game/ClientSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/PreGame.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/Input/InputHandler.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/MsgStrings.h"
#include "System/StartScriptGen.h"
#include "aGui/Gui.h"
#include "aGui/VerticalLayout.h"
#include "aGui/HorizontalLayout.h"
#include "aGui/Button.h"
#include "aGui/LineEdit.h"
#include "aGui/TextElement.h"
#include "aGui/Window.h"
#include "aGui/Picture.h"
#include "aGui/List.h"
#include "alphanum.hpp"

using std::string;
using agui::Button;
using agui::HorizontalLayout;

CONFIG(std::string, address).defaultValue("").description("Last Ip/hostname used as direct connect in the menu.");
CONFIG(std::string, LastSelectedSetting).defaultValue("").description("Stores the previously selected setting, when editing settings within the Spring main menu.");
CONFIG(std::string, MenuArchive).defaultValue("Spring Bitmaps").description("Archive name for the default Menu.");

class ConnectWindow : public agui::Window
{
    //stub method
}

SelectMenu::~SelectMenu()
{
    //stub method
}

bool SelectMenu::Draw()
{
    //stub method
}

void SelectMenu::Single()
{
    //stub method
}

void SelectMenu::Quit()
{
    //stub method
}

void SelectMenu::ShowConnectWindow(bool show)
{
    //stub method
}

void SelectMenu::ShowSettingsWindow(bool show, std::string name)
{
    //stub method
}

void SelectMenu::ShowSettingsList()
{
    //stub method
}

void SelectMenu::SelectSetting(std::string setting) {
	size_t p = setting.find(" = ");
	if(p != std::string::npos)
		setting = setting.substr(0, p);
	userSetting = setting;
	configHandler->SetString("LastSelectedSetting", userSetting);
	ShowSettingsWindow(true, userSetting);
}

void SelectMenu::CleanWindow() {
	if (curSelect) {
		ShowSettingsWindow(false, "");
		agui::gui->RmElement(curSelect);
		curSelect = NULL;
	}
}

void SelectMenu::DirectConnect(const std::string& addr)
{
    //stub method
}

bool SelectMenu::HandleEventSelf(const SDL_Event& ev)
{
    //stub method
}
