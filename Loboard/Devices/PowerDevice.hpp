//
//  PowerDevice.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef PowerDevice_hpp
#define PowerDevice_hpp

#include "Device.hpp"

class PowerDevice: public Device
{
public:
    explicit PowerDevice(uint8_t id);
    
    void PowerOn();
    void PowerOff();
};

#endif /* PowerDevice_hpp */
