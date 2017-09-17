#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/cstdint.hpp>
#include <SDL_keycode.h>

#include "SpringController.h"
#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Game/UI/MouseHandler.h"
#include "Rendering/GlobalRendering.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Input/KeyInput.h"


CONFIG(bool,  CamSpringEnabled).defaultValue(true).headlessValue(false);
CONFIG(int,   CamSpringScrollSpeed).defaultValue(10);
CONFIG(float, CamSpringFOV).defaultValue(45.0f);
CONFIG(bool,  CamSpringLockCardinalDirections).defaultValue(true).description("Whether cardinal directions should be `locked` for a short time when rotating.");
CONFIG(bool,  CamSpringZoomInToMousePos).defaultValue(true);
CONFIG(bool,  CamSpringZoomOutFromMousePos).defaultValue(false);
CONFIG(bool,  CamSpringEdgeRotate).defaultValue(false).description("Rotate camera when cursor touches screen borders.");


CSpringController::CSpringController()
: rot(2.677f, 0.f, 0.f)
, curDist(float3(mapDims.mapx * 0.5f, 0.0f, mapDims.mapy * 0.55f).Length2D() * 1.5f * SQUARE_SIZE)
, maxDist(std::max(mapDims.mapx, mapDims.mapy) * SQUARE_SIZE * 1.333f)
, oldDist(0.f)
, zoomBack(false)
, cursorZoomIn(configHandler->GetBool("CamSpringZoomInToMousePos"))
, cursorZoomOut(configHandler->GetBool("CamSpringZoomOutFromMousePos"))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSpringController::KeyMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSpringController::MouseMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSpringController::ScreenEdgeMove(float3 move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSpringController::MouseWheelMove(float move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CSpringController::ZoomIn(
	const float3& curCamPos,
	const float2& zoomParams
) {
	if (KeyInput::GetKeyModState(KMOD_ALT) && zoomBack) {
		// instazoom in to standard view
		curDist = oldDist;
		zoomBack = false;

		return 0.5f;
	}

	if (!cursorZoomIn)
		return 0.25f;

	const float zoomInDist = CGround::LineGroundCol(curCamPos, curCamPos + mouse->dir * 150000.f, false);

	if (zoomInDist <= 0.0f)
		return 0.25f;

	// zoom in to cursor, then back out (along same dir) based on scaledMove
	// to find where we want to place camera, but make sure the wanted point
	// is always in front of curCamPos
	const float3 zoomedCamPos =    curCamPos + mouse->dir * zoomInDist;
	const float3 wantedCamPos = zoomedCamPos - mouse->dir * zoomInDist * zoomParams.y;

	// figure out how far we will end up from the ground at new wanted point
	const float newDist = CGround::LineGroundCol(wantedCamPos, wantedCamPos + dir * 150000.f, false);

	if (newDist > 0.0f)
		pos = wantedCamPos + dir * (curDist = newDist);

	return 0.25f;
}

float CSpringController::ZoomOut(
	const float3& curCamPos,
	const float2& zoomParams
) {
	if (KeyInput::GetKeyModState(KMOD_ALT)) {
		// instazoom out to maximum height
		if (!zoomBack) {
			oldDist = zoomParams.x;
			zoomBack = true;
		}

		rot = float3(2.677f, rot.y, 0.f);
		pos.x = mapDims.mapx * SQUARE_SIZE * 0.5f;
		pos.z = mapDims.mapy * SQUARE_SIZE * 0.55f; // somewhat longer toward bottom
		curDist = pos.Length2D() * 1.5f;

		return 1.0f;
	}

	zoomBack = false;

	if (!cursorZoomOut)
		return 0.25f;

	const float zoomInDist = CGround::LineGroundCol(curCamPos, curCamPos + mouse->dir * 150000.f, false);

	if (zoomInDist <= 0.0f)
		return 0.25f;

	// same logic as ZoomIn, but in opposite direction
	const float3 zoomedCamPos =    curCamPos + mouse->dir * zoomInDist;
	const float3 wantedCamPos = zoomedCamPos - mouse->dir * zoomInDist * zoomParams.y;

	const float newDist = CGround::LineGroundCol(wantedCamPos, wantedCamPos + dir * 150000.f, false);

	if (newDist > 0.0f)
		pos = wantedCamPos + dir * (curDist = newDist);

	return 0.25f;
}



void CSpringController::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static float GetRotationWithCardinalLock(float rot)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CSpringController::MoveAzimuth(float move)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CSpringController::GetAzimuth() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 CSpringController::GetPos() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSpringController::SwitchTo(const int oldCam, const bool showText)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSpringController::GetState(StateMap& sm) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSpringController::SetState(const StateMap& sm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
