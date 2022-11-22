//
//  AndGateDevice.hpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#ifndef AndGateDevice_hpp
#define AndGateDevice_hpp

#include "GateDevice.hpp"

class AndGateDevice: public GateDevice
{
public:
    explicit AndGateDevice(uint8_t id);
protected:
    DeviceState getNewState(DeviceState in0, DeviceState in1) override;
};

#endif /* AndGateDevice_hpp */
