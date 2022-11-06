//
//  PowerDevice.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "PowerDevice.hpp"

PowerDevice::PowerDevice(uint8_t id) : Device(id, 0)
{
    PowerOn();
    setName("Power");
}

void PowerDevice::PowerOn()
{
    setState(DEVICE_ON);
}

void PowerDevice::PowerOff()
{
    setState(DEVICE_OFF);
}
