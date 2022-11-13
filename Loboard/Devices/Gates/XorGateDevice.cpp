//
// Created by Dan Demidov on 13.11.22.
//

#include "XorGateDevice.hpp"

XorGateDevice::XorGateDevice(uint8_t id) : GateDevice(id)
{
    setName("XorGate");
}

bool XorGateDevice::getNewState(DeviceState in0, DeviceState in1)
{
    return (in0 || in1) && !(in0 && in1);
}
