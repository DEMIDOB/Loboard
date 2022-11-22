//
// Created by Dan Demidov on 22.11.22.
//

#include "NandGateDevice.hpp"

NandGateDevice::NandGateDevice(DeviceID id) : AndGateDevice(id)
{
    setName("NandGate");
}

DeviceState NandGateDevice::getNewState(DeviceState in0, DeviceState in1)
{
    return !AndGateDevice::getNewState(in0, in1);
}
