//
//  GateDevice.hpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#ifndef GateDevice_hpp
#define GateDevice_hpp

#include "../Device.hpp"

class GateDevice: public Device
{
public:
    GateDevice(uint8_t id);
    
    void Update();
    
protected:
    // Works as OR by default
    virtual bool getNewState(DeviceState in0, DeviceState in1);
};

#endif /* GateDevice_hpp */
