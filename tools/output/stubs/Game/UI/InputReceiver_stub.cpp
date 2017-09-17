/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "InputReceiver.h"
#include "Rendering/GL/myGL.h"


float CInputReceiver::guiAlpha = 0.8f;

CInputReceiver* CInputReceiver::activeReceiver = NULL;


std::list<CInputReceiver*>& GetInputReceivers()
{
    //stub method
}

CInputReceiver::CInputReceiver(Where w)
{
    //stub method
}

CInputReceiver::~CInputReceiver()
{
    //stub method
}

void CInputReceiver::CollectGarbage()
{
    //stub method
}

CInputReceiver* CInputReceiver::GetReceiverAt(int x,int y)
{
    //stub method
}

bool CInputReceiver::InBox(float x, float y, const ContainerBox& box) const
{
    //stub method
}

void CInputReceiver::DrawBox(const ContainerBox& box, int how)
{
    //stub method
}

CInputReceiver::ContainerBox::ContainerBox()
	: x1(0.0f)
	, y1(0.0f)
	, x2(0.0f)
	, y2(0.0f)
{
    //stub method
}

CInputReceiver::ContainerBox CInputReceiver::ContainerBox::operator+(CInputReceiver::ContainerBox other) const
{
    //stub method
}
