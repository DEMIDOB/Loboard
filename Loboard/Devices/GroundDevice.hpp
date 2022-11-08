//
//  GroundDevice.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef GroundDevice_hpp
#define GroundDevice_hpp

#include <vector>
#include "Device.hpp"

class GroundDevice: public Device {
public:
    explicit GroundDevice(uint8_t id);
    ~GroundDevice();
    
    void Update();
    
private:
    std::vector<DirectionalWire*> inputs;
};

#endif /* GroundDevice_hpp */
