//
//  Device.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "Device.hpp"
#include "DirectionalWire.hpp"
#include "Exceptions/StringOutputIssued.hpp"

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
    for (auto& output : outputs)
    {
        if (outputs.empty())
        {
            break;
        }

        DirectionalWire* wire_ptr = output.second;
        delete wire_ptr;
    }

    for (size_t i = 0; i < inputsCount; ++i)
    {
        DirectionalWire* input_ptr = *(inputs + i);
        if (input_ptr == nullptr)
        {
            continue;
        }
        delete input_ptr;
    }

    delete[] inputs;
}

void Device::AssignID(uint8_t id)
{
    this->id = id;
}

void Device::Update()
{
    bool shouldUnblock = AllInputsWired() && IsAnyOutputWired();
    
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
    
    if (!ready && shouldUnblock)
    {
        unblock();
    }
    
    PropagateState();
}

void Device::PropagateState()
{
    for (auto& output: outputs)
    {
        output.second->Transmit();
    }
}

bool Device::DoesInputExist(uint8_t inputIdx) const
{
    return inputIdx < inputsCount;
}

bool Device::IsInputWired(uint8_t inputIdx)
{
    return DoesInputExist(inputIdx) && inputs[inputIdx] != nullptr;
}

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
        ERR("Trying to access a non-existing input!")
        return nullptr;
    }
    
    return inputs[inputIdx]->GetSrc();
}

void Device::unwireInputAtPort(uint8_t inputPort)
{
    if (inputPort >= inputsCount)
    {
        ERR("Trying to access a non-existing input!")
        return;
    }

    inputs[inputPort] = nullptr;
    Update();
}

void Device::setState(DeviceState newState)
{
    if (IsBlocked())
    {
//        ERR("Tried to set state for a ready device " << static_cast<int>(GetID()));
        return;
    }
    
    this->state = newState;
    PropagateState();
}

void Device::block(bool req)
{
    ready = false;
    if (req)
    {
        PropagateState();
    }
}

void Device::unblock(bool req)
{
    ready = true;
    if (req)
    {
        PropagateState();
    }
}

void Device::setName(std::string name)
{
    this->name = std::move(name);
}

void Device::initEmpty()
{
    this->ready = true;
    this->name = "Device";

    this->inputs = static_cast<DirectionalWire **>(malloc(inputsCount * sizeof(DirectionalWire *)));

    for (int i = 0; i < inputsCount; ++i)
    {
        this->inputs[i] = nullptr;
    }
}

Device::operator std::basic_string<char>() const
{
    std::string repr;
    std::string prefix = " ";

    if (IsBlocked())
    {
        prefix = "!"; // prefix indicating that the device is ready
    }

    std::string s_id = std::to_string(id);
    std::string stateIndicator = GetState() ? " +" : " -";

    repr += "[#" + s_id + " " + GetName() + stateIndicator + "]";

    std::string s_inputs;
    std::string s_outputs;

    for (size_t i = 0; i < inputsCount; ++i)
    {
        if (inputs[i] != nullptr)
        {
            s_inputs += std::to_string(inputs[i]->GetSrc()->id);
        }

        if (s_inputs[s_inputs.size() - 1] != ' ')
        {
            s_inputs += " ";
        }
    }

    for (auto& output : outputs)
    {
        s_outputs += std::to_string(output.second->GetDest()->id);
        s_outputs += " ";
    }

    if (inputsCount)
    {
        repr += " ( " + s_inputs + ")";
    }

    if (!outputs.empty())
    {
        repr += " -> { " + s_outputs + "}";
    }

    return prefix + repr;
}

int Device::GetNextInputID() const
{
    for (int nextInputID = 0; nextInputID < inputsCount; nextInputID++)
    {
        if (inputs[nextInputID] == nullptr)
        {
            return (int) nextInputID;
        }
    }

    return -1;
}

void Device::addOutput(DirectionalWire* newOutputWire)
{
#ifdef assert
    assert(newOutputWire->GetDest() != this);
#endif
    outputs[newOutputWire->GetDest()->id] = newOutputWire;
}

void Device::deleteOutput(DeviceID destID)
{
    if (!outputs.count(destID))
    {
        return;
    }

    DirectionalWire* outputWire = outputs[destID];
    outputs.erase(destID);

    Update();
}

void Device::SendMessage(const std::string &message)
{
    if (message.empty())
    {
        throw DeviceExceptions::StringOutputIssued(std::basic_string<char>(*this));
    }
}
