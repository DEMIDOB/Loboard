//
//  DirectionalWire.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "DirectionalWire.hpp"
#include "Device.hpp"

DirectionalWire::DirectionalWire(Device* src, Device* dest, uint8_t destPort)
    : src(src), dest(dest)
{
    if (src->HasOutputToDevice(dest))
    {
        // TODO: encapsulate
        src->deleteOutput(dest->id);
    }

    if (dest->IsInputWired(destPort))
    {
        delete dest->getInputDevice(destPort);
    }

    src->addOutput(this);
    dest->inputs[destPort] = this;

    // TODO: wtf this does?
    if (!dest->AllInputsWired())
    {
        dest->ready = false;
    }

    this->src->Update();
}

DirectionalWire::~DirectionalWire()
{
    dest->unwireInputAtPort(destPort);
    src->deleteOutput(this->dest->id);
}

bool DirectionalWire::IsReady()
{
    if (src == nullptr || dest == nullptr)
    {
        return false;
    }

    return src->HasOutputToDevice(dest) && dest->DoesInputExist(destPort);
}

bool DirectionalWire::IsBlocked()
{
    if (src == nullptr)
    {
        return false;
    }

    return src->IsBlocked();;
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