//
//  Board.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef Board_hpp
#define Board_hpp

#include <vector>

#include "Devices/Device.hpp"
#include "Devices/GroundDevice.hpp"

static const uint8_t protectedDevicesIDs[] = {0}; // these can not be deleted

class Board
{
private:
    uint8_t devicesCount = 0;
    std::vector<Device*> devices;
    
    GroundDevice* ground;

protected:

public:
    Board();
    ~Board();

    uint8_t GetDevicesCount();

    Device* GetDevice(uint8_t);
    uint8_t AddDevice(Device*);
    bool RemoveDevice(uint8_t);

    Wire* Wire(uint8_t src, uint8_t dest, uint8_t destPort);
};

#endif /* Board_hpp */
