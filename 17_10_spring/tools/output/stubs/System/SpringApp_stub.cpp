/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Input/InputHandler.h"

#include <SDL.h>

#include <iostream>

#ifdef WIN32
// windows workarrounds
#undef KeyPress
#undef KeyRelease
#endif

#include "Rendering/GL/myGL.h"
#include "System/SpringApp.h"

#include "ExternalAI/IAILibraryManager.h"
#include "Game/Benchmark.h"
#include "Game/ClientSetup.h"
#include "Game/Game.h"
#include "Game/GameController.h"
#include "Game/GameSetup.h"
#include "Game/GameVersion.h"
#include "Game/GlobalUnsynced.h"
#include "Game/LoadScreen.h"
#include "Game/PreGame.h"
#include "Game/UI/KeyBindings.h"
#include "Game/UI/MouseHandler.h"
#include "Lua/LuaOpenGL.h"
#include "Lua/LuaVFSDownload.h"
#include "Menu/SelectMenu.h"
#include "Net/GameServer.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GLContext.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "Rendering/VerticalSync.h"
#include "Sim/Misc/DefinitionTag.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/DataDirLocater.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/FileSystemInitializer.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/GlobalConfig.h"
#include "System/Input/Joystick.h"
#include "System/Input/KeyInput.h"
#include "System/Input/MouseInput.h"
#include "System/Log/ConsoleSink.h"
#include "System/Log/DefaultFilter.h"
#include "System/Log/ILog.h"
#include "System/LogOutput.h"
#include "System/MsgStrings.h"
#include "System/Platform/Battery.h"
#include "System/Platform/CmdLineParams.h"
#include "System/Platform/CrashHandler.h"
#include "System/Platform/Misc.h"
#include "System/Platform/Threading.h"
#include "System/Platform/Watchdog.h"
#include "System/Platform/WindowManagerHelper.h"
#include "System/Platform/errorhandler.h"
#include "System/Sound/ISound.h"
#include "System/StartScriptGen.h"
#include "System/Sync/FPUCheck.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"
#include "System/UriParser.h"
#include "System/Util.h"
#include "System/bitops.h"
#include "System/creg/creg_runtime_tests.h"
#include "System/myMath.h"
#include "aGui/Gui.h"
#include "lib/luasocket/src/restrictions.h"

#ifdef WIN32
#include "System/Platform/Win/WinVersion.h"
#endif

CONFIG(unsigned, SetCoreAffinity)
  .defaultValue(0)
  .safemodeValue(1)
  .description(
    "Defines a bitmask indicating which CPU cores the main-thread should use.");
CONFIG(unsigned, SetCoreAffinitySim)
  .defaultValue(0)
  .safemodeValue(1)
  .description(
    "Defines a bitmask indicating which CPU cores the sim-thread should use.");
CONFIG(bool, UseHighResTimer)
  .defaultValue(false)
  .description("On Windows, sets whether Spring will use low- or "
               "high-resolution timer functions for tasks like graphical "
               "interpolation between game frames.");
CONFIG(int, PathingThreadCount)
  .defaultValue(0)
  .safemodeValue(1)
  .minimumValue(0);

CONFIG(int, FSAALevel)
  .defaultValue(0)
  .minimumValue(0)
  .maximumValue(8)
  .description("If >0 enables FullScreen AntiAliasing.");
CONFIG(int, SmoothLines)
  .defaultValue(2)
  .headlessValue(0)
  .safemodeValue(0)
  .minimumValue(0)
  .maximumValue(3)
  .description(
    "Smooth lines.\n 0 := off\n 1 := fastest\n 2 := don't care\n 3 := nicest");
CONFIG(int, SmoothPoints)
  .defaultValue(2)
  .headlessValue(0)
  .safemodeValue(0)
  .minimumValue(0)
  .maximumValue(3)
  .description(
    "Smooth points.\n 0 := off\n 1 := fastest\n 2 := don't care\n 3 := nicest");
CONFIG(float, TextureLODBias)
  .defaultValue(0.0f)
  .minimumValue(-4.0f)
  .maximumValue(4.0f);
CONFIG(bool, FixAltTab).defaultValue(false);

CONFIG(std::string, FontFile)
  .defaultValue("fonts/FreeSansBold.otf")
  .description("Sets the font of Spring engine text.");
CONFIG(std::string, SmallFontFile)
  .defaultValue("fonts/FreeSansBold.otf")
  .description("Sets the font of Spring engine small text.");
CONFIG(int, FontSize)
  .defaultValue(23)
  .description("Sets the font size (in pixels) of the MainMenu and more.");
CONFIG(int, SmallFontSize)
  .defaultValue(14)
  .description("Sets the font size (in pixels) of the engine GUIs and more.");
CONFIG(int, FontOutlineWidth)
  .defaultValue(3)
  .description("Sets the width of the black outline around Spring engine text, "
               "such as the title screen version number, clock, and basic UI. "
               "Does not affect LuaUI elements.");
CONFIG(float, FontOutlineWeight)
  .defaultValue(25.0f)
  .description("Sets the opacity of Spring engine text, such as the title "
               "screen version number, clock, and basic UI. Does not affect "
               "LuaUI elements.");
CONFIG(int, SmallFontOutlineWidth)
  .defaultValue(2)
  .description("see FontOutlineWidth");
CONFIG(float, SmallFontOutlineWeight)
  .defaultValue(10.0f)
  .description("see FontOutlineWeight");

CONFIG(bool, Fullscreen)
  .defaultValue(true)
  .headlessValue(false)
  .description("Sets whether the game will run in fullscreen, as opposed to a "
               "window. For Windowed Fullscreen of Borderless Window, set this "
               "to 0, WindowBorderless to 1, and WindowPosX and WindowPosY to "
               "0.");
CONFIG(int, XResolution)
  .defaultValue(0)
  .headlessValue(8)
  .minimumValue(0)
  .description("Sets the width of the game screen. If set to 0 Spring will "
               "autodetect the current resolution of your desktop.");
CONFIG(int, YResolution)
  .defaultValue(0)
  .headlessValue(8)
  .minimumValue(0)
  .description("Sets the height of the game screen. If set to 0 Spring will "
               "autodetect the current resolution of your desktop.");
CONFIG(int, XResolutionWindowed)
  .defaultValue(0)
  .headlessValue(8)
  .minimumValue(0)
  .description("See XResolution, just for windowed.");
CONFIG(int, YResolutionWindowed)
  .defaultValue(0)
  .headlessValue(8)
  .minimumValue(0)
  .description("See YResolution, just for windowed.");
CONFIG(int, WindowPosX)
  .defaultValue(32)
  .description("Sets the horizontal position of the game window, if Fullscreen "
               "is 0. When WindowBorderless is set, this should usually be 0.");
CONFIG(int, WindowPosY)
  .defaultValue(32)
  .description("Sets the vertical position of the game window, if Fullscreen "
               "is 0. When WindowBorderless is set, this should usually be 0.");
CONFIG(int, WindowState).defaultValue(CGlobalRendering::WINSTATE_MAXIMIZED);
CONFIG(bool, WindowBorderless)
  .defaultValue(false)
  .description("When set and Fullscreen is 0, will put the game in Borderless "
               "Window mode, also known as Windowed Fullscreen. When using "
               "this, it is generally best to also set WindowPosX and "
               "WindowPosY to 0");
CONFIG(bool, BlockCompositing)
  .defaultValue(false)
  .safemodeValue(true)
  .description("Disables kwin compositing to fix tearing, possible fixes low "
               "FPS in windowed mode, too.");

CONFIG(std::string, name)
  .defaultValue(UnnamedPlayerName)
  .description("Sets your name in the game. Since this is overridden by "
               "lobbies with your lobby username when playing, it usually only "
               "comes up when viewing replays or starting the engine directly "
               "for testing purposes.");
CONFIG(std::string, DefaultStartScript)
  .defaultValue("")
  .description("filename of script.txt to use when no command line parameters "
               "are specified.");

static SDL_GLContext sdlGlCtx;
static SDL_Window* window;

/**
 * @brief multisample verify
 * @return whether verification passed
 *
 * Tests whether FSAA was actually enabled
 */
static bool
MultisampleVerify()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Initializes SpringApp variables
 *
 * @param argc argument count
 * @param argv array of argument strings
 */
SpringApp::SpringApp(int argc, char** argv)
  : cmdline(new CmdLineParams(argc, argv))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Destroys SpringApp variables
 */
SpringApp::~SpringApp()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Initializes the SpringApp instance
 * @return whether initialization was successful
 */
bool
SpringApp::Initialize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @return whether window initialization succeeded
 * @param title char* string with window title
 *
 * Initializes the game window
 */
bool
SpringApp::InitWindow(const char* title)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @return whether setting the video mode was successful
 *
 * Sets SDL video mode options/settings
 */
bool
SpringApp::CreateSDLWindow(const char* title)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// origin for our coordinates is the bottom left corner
void
SpringApp::GetDisplayGeometry()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Saves position of the window, if we are not in full-screen mode
 */
void
SpringApp::SaveWindowPosition()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SpringApp::SetupViewportGeometry()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Initializes OpenGL
 */
void
SpringApp::InitOpenGL()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SpringApp::LoadFonts()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// initialize basic systems for command line help / output
static void
ConsolePrintInitialize(const std::string& configSource, bool safemode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @return whether commandline parsing was successful
 *
 * Parse command line arguments
 */
void
SpringApp::ParseCmdLine(const std::string& binaryName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameController*
SpringApp::LoadSaveFile(const std::string& saveFile)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGameController*
SpringApp::RunScript(const std::string& buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SpringApp::StartScript(const std::string& inputFile)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SpringApp::LoadSpringMenu()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Initializes instance of GameSetup
 */
void
SpringApp::Startup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SpringApp::Reload(const std::string& script)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @return return code of activecontroller draw function
 *
 * Draw function repeatedly called, it calls all the
 * other draw functions
 */
int
SpringApp::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Executes the application
 * (contains main game loop)
 */
int
SpringApp::Run()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Deallocates and shuts down game
 */
void
SpringApp::ShutDown()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
SpringApp::MainEventHandler(const SDL_Event& event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
