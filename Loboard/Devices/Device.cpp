//
//  Device.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "Device.hpp"

Device::Device()
{
    initEmpty();
}

Device::Device(uint8_t id, uint8_t inputsCount)
{
    this->id = id;
    this->inputsCount = inputsCount;
    
    initEmpty();
}

Device::~Device()
{
    delete output;
    delete[] inputs;
}

void Device::AssignID(uint8_t id)
{
    this->id = id;
}

void Device::Move(LBVector dest)
{
    this->position = dest;
}

void Device::Update()
{
    bool shouldUnblock = AllInputsWired();
    
    for (uint8_t i = 0; i < inputsCount; ++i)
    {
        if (IsInputWired(i))
        {
            if (getInputDevice(i)->IsBlocked())
            {
                shouldUnblock = false;
                block();
                return;
            }
        }
    }
    
    if (shouldUnblock)
    {
        unblock();
    }
    
    PropagateState();
}

void Device::PropagateState()
{
    if (output != nullptr)
    {
        output->Transmit();
    }
}

bool Device::IsBlocked()
{
    return !editable /*|| !id*/;
}

uint8_t Device::GetID()
{
    return this->id;
}

DirectionedWire* Device::GetOutput()
{
    return output;
}

uint8_t Device::GetInputsCount()
{
    return this->inputsCount;
}

bool Device::DoesInputExist(uint8_t inputIdx)
{
    return inputIdx < inputsCount;
}

bool Device::IsInputWired(uint8_t inputIdx)
{
    return DoesInputExist(inputIdx) && inputs[inputIdx] != nullptr;
}

//bool Device::SetInput(uint8_t inputIdx, Device *device)
//{
//    if (inputIdx >= inputsCount)
//    {
//        return false;
//    }
//    
//    inputs[inputIdx] = device;
//    Update();
//    
//    return true;
//}

bool Device::AllInputsWired()
{
    for (uint8_t i = 0; i < inputsCount; ++i)
    {
        if (inputs[i] == nullptr || inputs[i]->IsBlocked())
        {
            return false;
        }
    }
    
    return true;
}

Device* Device::getInputDevice(uint8_t inputIdx)
{
    if (inputIdx >= inputsCount)
    {
        ERR("Trying to acces an unexisting input!")
        return nullptr;
    }
    
    return inputs[inputIdx]->GetSrc();
}

LBVector Device::GetPosition()
{
    return this->position;
}

DeviceState Device::GetState()
{
    return this->state;
}

std::string Device::GetName()
{
    return this->name;
}

void Device::setState(DeviceState newState)
{
    if (IsBlocked())
    {
        ERR("Tried to set state for a blocked device!");
        return;
    }
    
    this->state = newState;
    PropagateState();
}

void Device::toggleState()
{
    setState(!this->state);
}

void Device::block()
{
    editable = false;
    PropagateState();
}

void Device::unblock()
{
    editable = true;
    PropagateState();
}

void Device::setName(std::string name)
{
    this->name = std::move(name);
}

void Device::initEmpty()
{
    this->boxSize = nullLBVector();
    this->position = nullLBVector();
    this->editable = true;
    this->name = "Device";
    this->output = nullptr;
    
    if (this->inputsCount > 0)
    {
        this->inputs = new DirectionedWire*[this->inputsCount];
        for (uint8_t i = 0; i < inputsCount; ++i)
        {
            inputs[i] = nullptr;
        }
    }
}

DirectionedWire::DirectionedWire(Device* src, Device* dest, uint8_t destPort)
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
    
    Transmit();
}

DirectionedWire::~DirectionedWire()
{
    if (IsReady())
    {
        src->output = nullptr;
        dest->inputs[destPort] = nullptr;
        dest->Update();
    }
}

bool DirectionedWire::IsReady()
{
    if (src == nullptr || dest == nullptr)
    {
        return false;
    }
    
    return src->output == this && dest->DoesInputExist(destPort);
}

bool DirectionedWire::IsBlocked()
{
    if (src == nullptr)
    {
        return false;
    }
    
    return src->IsBlocked();
}

Device* DirectionedWire::GetSrc()
{
    return src;
}

void DirectionedWire::Transmit()
{
    DeviceState newInputState = src->GetState();
    
    if (newInputState == previouslyTransmittedState)
    {
        return;
    }
    
    previouslyTransmittedState = newInputState;
    dest->Update();
}
