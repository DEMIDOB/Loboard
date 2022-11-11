//
//  GroundDevice.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "GroundDevice.hpp"

GroundDevice::GroundDevice(uint8_t id) : Device(id, GROUND_INPUTS_COUNT)
{
    setState(DEVICE_OFF);
    block();
    setName("Ground");
}

GroundDevice::~GroundDevice()
= default;

void GroundDevice::Update()
{
    return;
}
