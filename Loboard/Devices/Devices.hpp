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
#include "Gates/NandGateDevice.hpp"
#include "Gates/OrGateDevice.hpp"
#include "Gates/NorGateDevice.hpp"
#include "Gates/XorGateDevice.hpp"

typedef Device* (*DeviceInitializer)(DeviceID id);

std::map<std::string, DeviceInitializer> DEVICES_BY_NAME = {
    {"power",  [](DeviceID id) -> Device* { return new PowerDevice(id);    } },
    {"ground", [](DeviceID id) -> Device* { return new GroundDevice(id);   } },
    {"and",    [](DeviceID id) -> Device* { return new AndGateDevice(id);  } },
    {"nand",   [](DeviceID id) -> Device* { return new NandGateDevice(id); } },
    {"or",     [](DeviceID id) -> Device* { return new OrGateDevice(id);   } },
    {"nor",    [](DeviceID id) -> Device* { return new NorGateDevice(id);  } },
    {"xor",    [](DeviceID id) -> Device* { return new XorGateDevice(id);  } },
};

#endif /* Devices_hpp */
