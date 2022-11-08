//
//  Board.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "Board.hpp"
#include "../DirectionalWire.hpp"

Board::Board()
{
    ground = new GroundDevice(0);
    devices.push_back(ground);
}

Board::~Board()
{
    for (Device* device : devices)
    {
        delete device;
    }
}

uint8_t Board::GetDevicesCount()
{
    return devices.size();
}

Device* Board::GetDevice(uint8_t id)
{
    if (id >= devices.size())
    {
        LOG("Tried to access an unexisting Device!")
        return nullptr;
    }
    
    return devices[id];
}

uint8_t Board::AddDevice(Device* device)
{
    if (device->GetID())
    {
        ERR("Trying to add an already existing device")
        return 0;
    }

    // TODO: fix fragmentation
    uint8_t newDeviceID = 0;
    while (++newDeviceID < devices.size() && devices[newDeviceID] != nullptr);

    while (devices.size() <= newDeviceID)
    {
        devices.push_back(nullptr);
    }

    device->AssignID(newDeviceID);
    devices[newDeviceID] = device;

    return newDeviceID;
}


DirectionalWire* Board::Wire(uint8_t srcId, uint8_t destId, uint8_t destPort)
{
    Device* src  = GetDevice(srcId);
    Device* dest = GetDevice(destId);
    
    if (src == nullptr || dest == nullptr)
    {
        return nullptr;
    }
    
    if (!dest->DoesInputExist(destPort))
    {
        return nullptr;
    }
    
    return new DirectionalWire(src, dest, destPort);
}

bool Board::RemoveDevice(uint8_t id)
{
    for (uint8_t pid : protectedDevicesIDs)
    {
        if (pid == id)
        {
            return false;
        }
    }

    Device* requestedDevice = GetDevice(id);

    if (requestedDevice == nullptr)
    {
        return false;
    }

    devices[id] = nullptr;
    delete requestedDevice;

    return true;
}
