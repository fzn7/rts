#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/EventClient.h"
#include "System/EventHandler.h"

/******************************************************************************/
/******************************************************************************/

CEventClient::CEventClient(const std::string& _name, int _order, bool _synced)
  : name(_name)
  , order(_order)
  , synced_(_synced)
  , autoLinkEvents(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CEventClient::~CEventClient()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::WantsEvent(const std::string& eventName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Synced
//

bool
CEventClient::CommandFallback(const CUnit* unit, const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowCommand(const CUnit* unit,
                           const Command& cmd,
                           bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::AllowUnitCreation(const UnitDef* unitDef,
                                const CUnit* builder,
                                const BuildInfo* buildInfo)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowUnitTransfer(const CUnit* unit, int newTeam, bool capture)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowUnitBuildStep(const CUnit* builder,
                                 const CUnit* unit,
                                 float part)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowFeatureCreation(const FeatureDef* featureDef,
                                   int allyTeamID,
                                   const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowFeatureBuildStep(const CUnit* builder,
                                    const CFeature* feature,
                                    float part)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowResourceLevel(int teamID, const string& type, float level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowResourceTransfer(int oldTeam,
                                    int newTeam,
                                    const string& type,
                                    float amount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowDirectUnitControl(int playerID, const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowBuilderHoldFire(const CUnit* unit, int action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowStartPosition(int playerID,
                                 unsigned char readyState,
                                 const float3& clampedPos,
                                 const float3& rawPickPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::TerraformComplete(const CUnit* unit, const CUnit* build)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::MoveCtrlNotify(const CUnit* unit, int data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CEventClient::AllowWeaponTargetCheck(unsigned int attackerID,
                                     unsigned int attackerWeaponNum,
                                     unsigned int attackerWeaponDefID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowWeaponTarget(unsigned int attackerID,
                                unsigned int targetID,
                                unsigned int attackerWeaponNum,
                                unsigned int attackerWeaponDefID,
                                float* targetPriority)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::AllowWeaponInterceptTarget(const CUnit* interceptorUnit,
                                         const CWeapon* interceptorWeapon,
                                         const CProjectile* interceptorTarget)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::UnitPreDamaged(const CUnit* unit,
                             const CUnit* attacker,
                             float damage,
                             int weaponDefID,
                             int projectileID,
                             bool paralyzer,
                             float* newDamage,
                             float* impulseMult)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::FeaturePreDamaged(const CFeature* feature,
                                const CUnit* attacker,
                                float damage,
                                int weaponDefID,
                                int projectileID,
                                float* newDamage,
                                float* impulseMult)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::ShieldPreDamaged(const CProjectile* projectile,
                               const CWeapon* shieldEmitter,
                               const CUnit* shieldCarrier,
                               bool bounceProjectile,
                               const CWeapon* beamEmitter,
                               const CUnit* beamCarrier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::SyncedActionFallback(const string& line, int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Unsynced
//

void
CEventClient::Save(zipFile archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::DrawUnit(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::DrawFeature(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::DrawShield(const CUnit* unit, const CWeapon* weapon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::DrawProjectile(const CProjectile* projectile)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEventClient::GameProgress(int gameFrame)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::KeyRelease(int key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::TextInput(const std::string& utf8)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CEventClient::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CEventClient::JoystickEvent(const std::string& event, int val1, int val2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEventClient::DownloadQueued(int ID,
                             const string& archiveName,
                             const string& archiveType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
std::string
CEventClient::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::CommandNotify(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::AddConsoleLine(const std::string& msg,
                             const std::string& section,
                             int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CEventClient::LastMessagePosition(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::GameSetup(const std::string& state,
                        bool& ready,
                        const map<int, std::string>& playerStates)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CEventClient::WorldTooltip(const CUnit* unit,
                           const CFeature* feature,
                           const float3* groundPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CEventClient::MapDrawCmd(int playerID,
                         int type,
                         const float3* pos0,
                         const float3* pos1,
                         const std::string* label)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
