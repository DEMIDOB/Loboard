//
//  Devices.hpp
//  Loboard
//
//  Created by Dan Demidov on 05.11.22.
//

#ifndef Devices_hpp
#define Devices_hpp

#include <string>
#include <map>

#include "PowerDevice.hpp"
#include "GroundDevice.hpp"
#include "Gates/AndGateDevice.hpp"
#include "Gates/OrGateDevice.hpp"
#include "Gates/XorGateDevice.hpp"

typedef Device* (*DeviceInitializer)(uint8_t id);

std::map<std::string, DeviceInitializer> DEVICES_BY_NAME = {
    {"power",  [](uint8_t id) -> Device* { return new PowerDevice(id);   } },
    {"ground", [](uint8_t id) -> Device* { return new GroundDevice(id);  } },
    {"and",    [](uint8_t id) -> Device* { return new AndGateDevice(id); } },
    {"or",     [](uint8_t id) -> Device* { return new OrGateDevice(id);  } },
    {"xor",    [](uint8_t id) -> Device* { return new XorGateDevice(id); } },
};

#endif /* Devices_hpp */
