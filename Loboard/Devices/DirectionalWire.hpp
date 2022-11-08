//
//  DirectionalWire.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef Wire_hpp
#define Wire_hpp

#include <iostream>

typedef bool DeviceState;
class Device;

class DirectionalWire
{
protected:
    Device* src;
    Device* dest;
    uint8_t destPort;

    DeviceState previouslyTransmittedState;
public:
    DirectionalWire(Device* src, Device* dest, uint8_t destPort);
    ~DirectionalWire();

    bool IsReady();
    bool IsBlocked();

    Device* GetSrc();

    void Transmit();
};

#endif /* Wire_hpp */
