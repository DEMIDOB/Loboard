//
//  GateDevice.cpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#include "GateDevice.hpp"

GateDevice::GateDevice(uint8_t id)
    : Device::Device(id, 2)
{
    
}

void GateDevice::Update()
{
    if (AllInputsWired())
    {
        DeviceState in0 = getInputDevice(0)->GetState();
        DeviceState in1 = getInputDevice(1)->GetState();
        
        setState(getNewState(in0, in1));
        Device::Update();
    }
    else
    {
        block();
    }
        
}

bool GateDevice::getNewState(DeviceState in0, DeviceState in1)
{
    return in0 || in1;
}
