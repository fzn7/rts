#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <stdio.h>

#include "KeyBindings.h"
#include "KeyCodes.h"
#include "KeySet.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/Config/ConfigHandler.h"


#define LOG_SECTION_KEY_BINDINGS "KeyBindings"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_KEY_BINDINGS)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_KEY_BINDINGS


CONFIG(int, KeyChainTimeout).defaultValue(750).minimumValue(0).description("Timeout in milliseconds waiting for a key chain shortcut.");


CKeyBindings* keyBindings = NULL;


struct DefaultBinding {
	const char* key;
	const char* action;
};

static const std::vector<DefaultBinding> defaultBindings = {
	{            "esc", "quitmessage" },
	{      "Shift+esc", "quitmenu"    },
	{ "Ctrl+Shift+esc", "quitforce"   },
	{  "Alt+Shift+esc", "reloadforce" },
	{      "Any+pause", "pause"       },

	{ "c", "controlunit"      },
	{ "Any+h", "sharedialog"  },
	{ "Any+i", "gameinfo"     },

	{ "Any+j",         "mouse2" },
	{ "backspace", "mousestate" },
	{ "Shift+backspace", "togglecammode" },
	{  "Ctrl+backspace", "togglecammode" },
	{         "Any+tab", "toggleoverview" },

	{               "Any+enter", "chat"           },
	{     "Ctrl+ctrl,Ctrl+ctrl", "chatswitchall"  },
	{         "Alt+alt,Alt+alt", "chatswitchally" },
	{ "Shift+shift,Shift+shift", "chatswitchspec" },

	{       "Any+tab", "edit_complete"  },
	{ "Any+backspace", "edit_backspace" },
	{    "Any+delete", "edit_delete"    },
	{      "Any+home", "edit_home"      },
	{      "Alt+left", "edit_home"      },
	{       "Any+end", "edit_end"       },
	{     "Alt+right", "edit_end"       },
	{        "Any+up", "edit_prev_line" },
	{      "Any+down", "edit_next_line" },
	{      "Any+left", "edit_prev_char" },
	{     "Any+right", "edit_next_char" },
	{     "Ctrl+left", "edit_prev_word" },
	{    "Ctrl+right", "edit_next_word" },
	{     "Any+enter", "edit_return"    },
	{    "Any+escape", "edit_escape"    },

	{ "Ctrl+v", "pastetext" },

	{ "Any+home", "increaseViewRadius" },
	{ "Any+end",  "decreaseViewRadius" },

	{ "Alt+insert",  "speedup"  },
	{ "Alt+delete",  "slowdown" },
	{ "Alt+=",       "speedup"  },
	{ "Alt++",       "speedup"  },
	{ "Alt+-",       "slowdown" },
	{ "Alt+numpad+", "speedup"  },
	{ "Alt+numpad-", "slowdown" },

	{       ",", "prevmenu" },
	{       ".", "nextmenu" },
	{ "Shift+,", "decguiopacity" },
	{ "Shift+.", "incguiopacity" },

	{      "1", "specteam 0"  },
	{      "2", "specteam 1"  },
	{      "3", "specteam 2"  },
	{      "4", "specteam 3"  },
	{      "5", "specteam 4"  },
	{      "6", "specteam 5"  },
	{      "7", "specteam 6"  },
	{      "8", "specteam 7"  },
	{      "9", "specteam 8"  },
	{      "0", "specteam 9"  },
	{ "Ctrl+1", "specteam 10" },
	{ "Ctrl+2", "specteam 11" },
	{ "Ctrl+3", "specteam 12" },
	{ "Ctrl+4", "specteam 13" },
	{ "Ctrl+5", "specteam 14" },
	{ "Ctrl+6", "specteam 15" },
	{ "Ctrl+7", "specteam 16" },
	{ "Ctrl+8", "specteam 17" },
	{ "Ctrl+9", "specteam 18" },
	{ "Ctrl+0", "specteam 19" },

	{ "Any+0", "group0" },
	{ "Any+1", "group1" },
	{ "Any+2", "group2" },
	{ "Any+3", "group3" },
	{ "Any+4", "group4" },
	{ "Any+5", "group5" },
	{ "Any+6", "group6" },
	{ "Any+7", "group7" },
	{ "Any+8", "group8" },
	{ "Any+9", "group9" },

	{       "[", "buildfacing inc"  },
	{ "Shift+[", "buildfacing inc"  },
	{       "]", "buildfacing dec"  },
	{ "Shift+]", "buildfacing dec"  },
	{   "Any+z", "buildspacing inc" },
	{   "Any+x", "buildspacing dec" },

	{            "a", "attack"       },
	{      "Shift+a", "attack"       },
	{        "Alt+a", "areaattack"   },
	{  "Alt+Shift+a", "areaattack"   },
	{        "Alt+b", "debug"        },
	{        "Alt+v", "debugcolvol"  },
	{        "Alt+p", "debugpath"    },
	{            "d", "manualfire"   },
	{      "Shift+d", "manualfire"   },
	{       "Ctrl+d", "selfd"        },
	{ "Ctrl+Shift+d", "selfd queued" },
	{            "e", "reclaim"      },
	{      "Shift+e", "reclaim"      },
	{            "f", "fight"        },
	{      "Shift+f", "fight"        },
	{        "Alt+f", "forcestart"   },
	{            "g", "guard"        },
	{      "Shift+g", "guard"        },
	{            "k", "cloak"        },
	{      "Shift+k", "cloak"        },
	{            "l", "loadunits"    },
	{      "Shift+l", "loadunits"    },
	{            "m", "move"         },
	{      "Shift+m", "move"         },
	{        "Alt+o", "singlestep"   },
	{            "p", "patrol"       },
	{      "Shift+p", "patrol"       },
	{            "q", "groupselect"  },
	{            "q", "groupadd"     },
	{       "Ctrl+q", "aiselect"     },
	{      "Shift+q", "groupclear"   },
	{            "r", "repair"       },
	{      "Shift+r", "repair"       },
	{            "s", "stop"         },
	{      "Shift+s", "stop"         },
	{            "u", "unloadunits"  },
	{      "Shift+u", "unloadunits"  },
	{            "w", "wait"         },
	{      "Shift+w", "wait queued"  },
	{            "x", "onoff"        },
	{      "Shift+x", "onoff"        },


	{  "Ctrl+t", "trackmode" },
	{   "Any+t", "track" },

	{ "Ctrl+f1", "viewfps"  },
	{ "Ctrl+f2", "viewta"   },
	{ "Ctrl+f3", "viewspring" },
	{ "Ctrl+f4", "viewrot"  },
	{ "Ctrl+f5", "viewfree" },

	{ "Any+f1",  "ShowElevation"         },
	{ "Any+f2",  "ShowPathTraversability"},
	{ "Any+f3",  "LastMsgPos"            },
	{ "Any+f4",  "ShowMetalMap"          },
	{ "Any+f5",  "HideInterface"         },
	{ "Any+f6",  "MuteSound"             },
	{ "Any+f7",  "DynamicSky"            },
	{ "Any+l",   "togglelos"             },

	{ "Ctrl+Shift+f8",  "savegame" },
	{ "Ctrl+Shift+f10", "createvideo" },
	{ "Any+f11", "screenshot"     },
	{ "Any+f12", "screenshot"     },
	{ "Alt+enter", "fullscreen"  },

	// NOTE: Up bindings are currently converted to press bindings
	//       (see KeySet.cpp / DISALLOW_RELEASE_BINDINGS)

	{ "Any+`,Any+`",    "drawlabel" },
	{ "Any+\\,Any+\\",  "drawlabel" },
	{ "Any+~,Any+~",    "drawlabel" },
	{ "Any+§,Any+§",    "drawlabel" },
	{ "Any+^,Any+^",    "drawlabel" },

	{    "Any+`",    "drawinmap"  },
	{ "Up+Any+`",    "drawinmap"  },
	{    "Any+\\",   "drawinmap"  },
	{ "Up+Any+\\",   "drawinmap"  },
	{    "Any+~",    "drawinmap"  },
	{ "Up+Any+~",    "drawinmap"  },
	{    "Any+§",    "drawinmap"  },
	{ "Up+Any+§",    "drawinmap"  },
	{    "Any+^",    "drawinmap"  },
	{ "Up+Any+^",    "drawinmap"  },

	{    "Any+up",       "moveforward"  },
	{ "Up+Any+up",       "moveforward"  },
	{    "Any+down",     "moveback"     },
	{ "Up+Any+down",     "moveback"     },
	{    "Any+right",    "moveright"    },
	{ "Up+Any+right",    "moveright"    },
	{    "Any+left",     "moveleft"     },
	{ "Up+Any+left",     "moveleft"     },
	{    "Any+pageup",   "moveup"       },
	{ "Up+Any+pageup",   "moveup"       },
	{    "Any+pagedown", "movedown"     },
	{ "Up+Any+pagedown", "movedown"     },

	{    "Any+ctrl",     "moveslow"     },
	{ "Up+Any+ctrl",     "moveslow"     },
	{    "Any+shift",    "movefast"     },
	{ "Up+Any+shift",    "movefast"     },

	// selection keys
	{ "Ctrl+a",    "select AllMap++_ClearSelection_SelectAll+"                                         },
	{ "Ctrl+b",    "select AllMap+_Builder_Idle+_ClearSelection_SelectOne+"                            },
	{ "Ctrl+c",    "select AllMap+_ManualFireUnit+_ClearSelection_SelectOne+"                          },
	{ "Ctrl+r",    "select AllMap+_Radar+_ClearSelection_SelectAll+"                                   },
	{ "Ctrl+v",    "select AllMap+_Not_Builder_Not_Commander_InPrevSel_Not_InHotkeyGroup+_SelectAll+"  },
	{ "Ctrl+w",    "select AllMap+_Not_Aircraft_Weapons+_ClearSelection_SelectAll+"                    },
	{ "Ctrl+x",    "select AllMap+_InPrevSel_Not_InHotkeyGroup+_SelectAll+"                            },
	{ "Ctrl+z",    "select AllMap+_InPrevSel+_ClearSelection_SelectAll+"                               }
};


/******************************************************************************/
//
// CKeyBindings
//

CKeyBindings::CKeyBindings()
	: fakeMetaKey(1)
	, buildHotkeyMap(true)
	, debugEnabled(false)
	, keyChainTimeout(750)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CKeyBindings::~CKeyBindings()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

const CKeyBindings::ActionList& CKeyBindings::GetActionList(const CKeySet& ks) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const CKeyBindings::ActionList& CKeyBindings::GetActionList(const CKeyChain& kc) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const CKeyBindings::HotkeyList& CKeyBindings::GetHotkeys(const std::string& action) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static bool ParseSingleChain(const std::string& keystr, CKeyChain* kc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool ParseKeyChain(std::string keystr, CKeyChain* kc, const size_t pos = std::string::npos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::Bind(const std::string& keystr, const std::string& line)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::UnBind(const std::string& keystr, const std::string& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::UnBindKeyset(const std::string& keystr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::UnBindAction(const std::string& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::SetFakeMetaKey(const std::string& keystr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::AddKeySymbol(const std::string& keysym, const std::string& code)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::RemoveCommandFromList(ActionList& al, const std::string& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CKeyBindings::ConfigNotify(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CKeyBindings::LoadDefaults()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CKeyBindings::PushAction(const Action& action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CKeyBindings::ExecuteCommand(const std::string& line)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::Load(const std::string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CKeyBindings::BuildHotkeyMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CKeyBindings::Print() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::Save(const std::string& filename) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CKeyBindings::FileSave(FILE* out) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

