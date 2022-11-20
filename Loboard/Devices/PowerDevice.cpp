//
//  PowerDevice.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "PowerDevice.hpp"
#include "Exceptions/StringOutputIssued.hpp"

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

void PowerDevice::SendMessage(const std::string &message)
{
    Device::SendMessage(message);


    if (message == "on")
    {
        setState(DEVICE_ON);
    }
    else if (message == "off")
    {
        setState(DEVICE_OFF);
    }
    else
    {
        return;
    }

    std::string currentOutput = "#";
    currentOutput += std::to_string(GetID());
    currentOutput += " is ";
    currentOutput += message;

    throw DeviceExceptions::StringOutputIssued(currentOutput);
}
