#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CobThread.h"
#include "CobEngine.h"
#include "CobFile.h"
#include "CobInstance.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/GlobalSynced.h"

#include <sstream>

CR_BIND(CCobThread, )

CR_REG_METADATA(CCobThread,
                (CR_MEMBER(owner),
                 CR_MEMBER(wakeTime),
                 CR_MEMBER(PC),
                 CR_MEMBER(paramCount),
                 CR_MEMBER(retCode),
                 CR_MEMBER(cbType),
                 CR_MEMBER(cbParam),
                 CR_MEMBER(waitAxis),
                 CR_MEMBER(waitPiece),
                 CR_MEMBER(state),
                 CR_MEMBER(signalMask),
                 CR_MEMBER(luaArgs),
                 CR_MEMBER(stack),
                 CR_MEMBER(callStack)))

CR_BIND(CCobThread::CallInfo, )

CR_REG_METADATA_SUB(CCobThread,
                    CallInfo,
                    (CR_MEMBER(functionId),
                     CR_MEMBER(returnAddr),
                     CR_MEMBER(stackTop)))

// creg only
CCobThread::CCobThread() {}

CCobThread::CCobThread(CCobInstance* owner)
  : owner(owner)
  , wakeTime(0)
  , PC(0)
  , paramCount(0)
  , retCode(-1)
  , cbType(CCobInstance::CBNone)
  , cbParam(0)
  , waitAxis(-1)
  , waitPiece(-1)
  , state(Init)
  , signalMask(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCobThread::~CCobThread()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobThread::SetCallback(CCobInstance::ThreadCallbackType cb, int cbp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobThread::Start(int functionId, const vector<int>& args, bool schedule)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const string&
CCobThread::GetName()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobThread::CheckStack(unsigned int size, bool warn)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobThread::GetStackVal(int pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobThread::GetWakeTime() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Command documentation from
// http://visualta.tauniverse.com/Downloads/cob-commands.txt And some
// information from basm0.8 source (basm ops.txt)

// Model interaction
const int MOVE = 0x10001000;
const int TURN = 0x10002000;
const int SPIN = 0x10003000;
const int STOP_SPIN = 0x10004000;
const int SHOW = 0x10005000;
const int HIDE = 0x10006000;
const int CACHE = 0x10007000;
const int DONT_CACHE = 0x10008000;
const int MOVE_NOW = 0x1000B000;
const int TURN_NOW = 0x1000C000;
const int SHADE = 0x1000D000;
const int DONT_SHADE = 0x1000E000;
const int EMIT_SFX = 0x1000F000;

// Blocking operations
const int WAIT_TURN = 0x10011000;
const int WAIT_MOVE = 0x10012000;
const int SLEEP = 0x10013000;

// Stack manipulation
const int PUSH_CONSTANT = 0x10021001;
const int PUSH_LOCAL_VAR = 0x10021002;
const int PUSH_STATIC = 0x10021004;
const int CREATE_LOCAL_VAR = 0x10022000;
const int POP_LOCAL_VAR = 0x10023002;
const int POP_STATIC = 0x10023004;
const int POP_STACK = 0x10024000; ///< Not sure what this is supposed to do

// Arithmetic operations
const int ADD = 0x10031000;
const int SUB = 0x10032000;
const int MUL = 0x10033000;
const int DIV = 0x10034000;
const int MOD = 0x10034001; ///< spring specific
const int BITWISE_AND = 0x10035000;
const int BITWISE_OR = 0x10036000;
const int BITWISE_XOR = 0x10037000;
const int BITWISE_NOT = 0x10038000;

// Native function calls
const int RAND = 0x10041000;
const int GET_UNIT_VALUE = 0x10042000;
const int GET = 0x10043000;

// Comparison
const int SET_LESS = 0x10051000;
const int SET_LESS_OR_EQUAL = 0x10052000;
const int SET_GREATER = 0x10053000;
const int SET_GREATER_OR_EQUAL = 0x10054000;
const int SET_EQUAL = 0x10055000;
const int SET_NOT_EQUAL = 0x10056000;
const int LOGICAL_AND = 0x10057000;
const int LOGICAL_OR = 0x10058000;
const int LOGICAL_XOR = 0x10059000;
const int LOGICAL_NOT = 0x1005A000;

// Flow control
const int START = 0x10061000;
const int CALL = 0x10062000;      ///< converted when executed
const int REAL_CALL = 0x10062001; ///< spring custom
const int LUA_CALL = 0x10062002;  ///< spring custom
const int JUMP = 0x10064000;
const int RETURN = 0x10065000;
const int JUMP_NOT_EQUAL = 0x10066000;
const int SIGNAL = 0x10067000;
const int SET_SIGNAL_MASK = 0x10068000;

// Piece destruction
const int EXPLODE = 0x10071000;
const int PLAY_SOUND = 0x10072000;

// Special functions
const int SET = 0x10082000;
const int ATTACH = 0x10083000;
const int DROP = 0x10084000;

// Indices for SET, GET, and GET_UNIT_VALUE for LUA return values
#define LUA0 110 // (LUA0 returns the lua call status, 0 or 1)
#define LUA1 111
#define LUA2 112
#define LUA3 113
#define LUA4 114
#define LUA5 115
#define LUA6 116
#define LUA7 117
#define LUA8 118
#define LUA9 119

// Handy macros
#define GET_LONG_PC() (owner->script->code[PC++])
// #define POP() (stack.size() > 0) ? stack.back(), stack.pop_back(); : 0

int
CCobThread::POP()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCobThread::Tick()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCobThread::ShowError(const string& msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string
CCobThread::GetOpcodeName(int opcode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CCobThread::LuaCall()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CCobThread::AnimFinished(CUnitScript::AnimType type, int piece, int axis)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
