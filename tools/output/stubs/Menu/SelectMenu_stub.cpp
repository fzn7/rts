#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SelectMenu.h"

#include <SDL_keycode.h>
#include <boost/bind.hpp>
#include <boost/cstdint.hpp>
#include <sstream>
#include <stack>

#include "Game/ClientSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/PreGame.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "SelectionWidget.h"
#include "System/AIScriptHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Input/InputHandler.h"
#include "System/Log/ILog.h"
#include "System/MsgStrings.h"
#include "System/StartScriptGen.h"
#include "System/Util.h"
#include "aGui/Button.h"
#include "aGui/Gui.h"
#include "aGui/HorizontalLayout.h"
#include "aGui/LineEdit.h"
#include "aGui/List.h"
#include "aGui/Picture.h"
#include "aGui/TextElement.h"
#include "aGui/VerticalLayout.h"
#include "aGui/Window.h"
#include "alphanum.hpp"

using agui::Button;
using agui::HorizontalLayout;
using std::string;

CONFIG(std::string, address)
  .defaultValue("")
  .description("Last Ip/hostname used as direct connect in the menu.");
CONFIG(std::string, LastSelectedSetting)
  .defaultValue("")
  .description("Stores the previously selected setting, when editing settings "
               "within the Spring main menu.");
CONFIG(std::string, MenuArchive)
  .defaultValue("Spring Bitmaps")
  .description("Archive name for the default Menu.");

class ConnectWindow : public agui::Window
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SelectMenu::~SelectMenu()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
SelectMenu::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SelectMenu::Single()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SelectMenu::Quit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SelectMenu::ShowConnectWindow(bool show)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SelectMenu::ShowSettingsWindow(bool show, std::string name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SelectMenu::ShowSettingsList()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SelectMenu::SelectSetting(std::string setting)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SelectMenu::CleanWindow()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SelectMenu::DirectConnect(const std::string& addr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
SelectMenu::HandleEventSelf(const SDL_Event& ev)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
