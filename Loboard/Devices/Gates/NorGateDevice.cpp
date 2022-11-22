//
// Created by Dan Demidov on 22.11.22.
//

#include "NorGateDevice.hpp"

NorGateDevice::NorGateDevice(DeviceID id) : OrGateDevice(id)
{
    setName("NorGate");
}

DeviceState NorGateDevice::getNewState(DeviceState in0, DeviceState in1)
{
    return !OrGateDevice::getNewState(in0, in1);
}


