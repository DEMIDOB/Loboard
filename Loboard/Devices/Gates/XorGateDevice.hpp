//
// Created by Dan Demidov on 13.11.22.
//

#ifndef LOBOARD_XORGATEDEVICE_HPP
#define LOBOARD_XORGATEDEVICE_HPP

#include "GateDevice.hpp"

class XorGateDevice: public GateDevice
{
public:
    explicit XorGateDevice(uint8_t id);

    bool getNewState(DeviceState in0, DeviceState in1);
};


#endif //LOBOARD_XORGATEDEVICE_HPP
