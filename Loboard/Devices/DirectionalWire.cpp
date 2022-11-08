//
//  DirectionalWire.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "DirectionalWire.hpp"
#include "Device.hpp"

DirectionalWire::DirectionalWire(Device* src, Device* dest, uint8_t destPort)
    : src(src)
{
    if (src->GetOutput() != nullptr)
    {
        delete src->output;
    }

    if (dest->IsInputWired(destPort))
    {
        delete dest->getInputDevice(destPort);
    }

    src->output = this;
    dest->inputs[destPort] = this;

    if (dest->AllInputsWired())
    {
        dest->blocked = true;
    }

    this->src = src;
    this->dest = dest;

    this->src->Update();
}

DirectionalWire::~DirectionalWire()
{
    if (IsReady())
    {
        src->output = nullptr;
        dest->inputs[destPort] = nullptr;
        dest->Update();
    }
}

bool DirectionalWire::IsReady()
{
    if (src == nullptr || dest == nullptr)
    {
        return false;
    }

    return src->output == this && dest->DoesInputExist(destPort);
}

bool DirectionalWire::IsBlocked()
{
    if (src == nullptr)
    {
        return false;
    }

    return src->IsBlocked();;
}

Device* DirectionalWire::GetSrc()
{
    return src;
}

void DirectionalWire::Transmit()
{
    DeviceState newInputState = src->GetState();

    if (newInputState == previouslyTransmittedState)
    {
        return;
    }

    previouslyTransmittedState = newInputState;
    dest->Update();
}