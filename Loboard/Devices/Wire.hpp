//
//  Wire.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef Wire_hpp
#define Wire_hpp

#include <iostream>

typedef bool DeviceState;
class Device;

class Wire
{
protected:
    Device* src;
    Device* dest;
    uint8_t destPort;

    DeviceState previouslyTransmittedState;
public:
    Wire(Device* src, Device* dest, uint8_t destPort);
    ~Wire();

    bool IsReady();
    bool IsBlocked();

    Device* GetSrc();

    void Transmit();
};

#endif /* Wire_hpp */
