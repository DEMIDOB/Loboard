//
// Created by Dan Demidov on 22.11.22.
//

#ifndef LOBOARD_NANDGATEDEVICE_HPP
#define LOBOARD_NANDGATEDEVICE_HPP

#include "AndGateDevice.hpp"

class NandGateDevice: public AndGateDevice
{
public:
    explicit NandGateDevice(DeviceID id);
protected:
    DeviceState getNewState(DeviceState in0, DeviceState in1) override;
};


#endif //LOBOARD_NANDGATEDEVICE_HPP
