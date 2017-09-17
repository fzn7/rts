/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GlobalSynced.h"

#include <assert.h>
#include <cstring>

#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/GameSetup.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Util.h"
#include "System/Log/FramePrefixer.h"


/**
 * @brief global synced
 *
 * Global instance of CGlobalSynced
 */
CGlobalSynced* gs = NULL;
CGlobalSynced::SyncedRNG CGlobalSynced::rng;


CR_BIND(CGlobalSynced, )

CR_REG_METADATA(CGlobalSynced, (
	CR_MEMBER(frameNum),
	CR_MEMBER(tempNum),

	CR_MEMBER(speedFactor),
	CR_MEMBER(wantedSpeedFactor),

	CR_MEMBER(paused),
	CR_MEMBER(godMode),
	CR_MEMBER(cheatEnabled),
	CR_MEMBER(noHelperAIs),
	CR_MEMBER(editDefsEnabled),
	CR_MEMBER(useLuaGaia),

	CR_MEMBER(randSeed),
	CR_MEMBER(initRandSeed)
))


/**
 * Initializes variables in CGlobalSynced
 */
CGlobalSynced::CGlobalSynced()
{
    //stub method
}


CGlobalSynced::~CGlobalSynced()
{
    //stub method
}


void CGlobalSynced::ResetState() {
	frameNum = -1; // first real frame is 0
	tempNum  =  1;

	speedFactor       = 1.0f;
	wantedSpeedFactor = 1.0f;

	paused  = false;
	godMode = false;

	cheatEnabled    = false;
	noHelperAIs     = false;
	editDefsEnabled = false;
	useLuaGaia      = true;

	log_framePrefixer_setFrameNumReference(&frameNum);

	if (teamHandler == NULL) {
		// needs to be available as early as PreGame
		teamHandler = new CTeamHandler();
	} else {
		// less cavemanly than delete + new
		teamHandler->ResetState();
		skirmishAIHandler.ResetState();
	}
}

void CGlobalSynced::LoadFromSetup(const CGameSetup* setup)
{
    //stub method
}

/**
 * @return synced random integer
 *
 * returns a synced random integer
 */
int CGlobalSynced::randInt()
{
    //stub method
}

/**
 * @return synced random float
 *
 * returns a synced random float
 */
float CGlobalSynced::randFloat()
{
    //stub method
}

/**
 * @return synced random vector
 *
 * returns a synced random vector
 */
float3 CGlobalSynced::randVector()
{
    //stub method
}
