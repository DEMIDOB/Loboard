//
// Created by Dan Demidov on 22.11.22.
//

#ifndef LOBOARD_NORGATEDEVICE_HPP
#define LOBOARD_NORGATEDEVICE_HPP

#include "OrGateDevice.hpp"

class NorGateDevice: public OrGateDevice
{
public:
    explicit NorGateDevice(DeviceID id);
protected:
    DeviceState getNewState(DeviceState in0, DeviceState in1) override;
};


#endif //LOBOARD_NORGATEDEVICE_HPP
