//
//  OrGateDevice.hpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#ifndef OrGateDevice_hpp
#define OrGateDevice_hpp

#include "GateDevice.hpp"

class OrGateDevice: public GateDevice
{
public:
    explicit OrGateDevice(uint8_t id);
};

#endif /* OrGateDevice_hpp */
