#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DummyVideoCapturing.h"

#include "System/Log/ILog.h"

#include <cstdlib> // for NULL

DummyVideoCapturing::DummyVideoCapturing() {}

DummyVideoCapturing::~DummyVideoCapturing() {}

bool
DummyVideoCapturing::IsCapturingSupported() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
DummyVideoCapturing::IsCapturing() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DummyVideoCapturing::StartCapturing()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DummyVideoCapturing::StopCapturing()
{}

void
DummyVideoCapturing::RenderFrame()
{}
