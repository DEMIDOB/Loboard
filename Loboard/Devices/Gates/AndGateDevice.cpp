//
//  AndGateDevice.cpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#include "AndGateDevice.hpp"

AndGateDevice::AndGateDevice(uint8_t id) : GateDevice(id)
{
    setName("AndGate");
}

DeviceState AndGateDevice::getNewState(DeviceState in0, DeviceState in1)
{
    return in0 && in1;
}
