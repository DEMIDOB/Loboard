//
// Created by Dan Demidov on 06.11.22.
//

#include "NewdCommand.hpp"
#include "../CommandLineInterface.hpp"
#include "Devices.hpp"

NewCommand::NewCommand(CommandLineInterface *interface, std::string keyword) : Command(interface,
                                                                                       std::move(keyword))
{

}

bool NewCommand::Handle(const std::string &cmd)
{
    if (cmd.size() <= keyword.size() + 1)
    {
        CLI_OUT("No device type specified")
        return true;
    }
    std::string deviceType = cmd.substr(keyword.size() + 1, cmd.size());

    if (!DEVICES_BY_NAME.count(deviceType))
    {
        CLI_OUT("No such device type is available")
        return true;
    }

    DeviceInitializer deviceInitializer = DEVICES_BY_NAME.at(deviceType);

    uint8_t newDeviceId = interface->GetBoard()->AddDevice(deviceInitializer(0));
    Device* newDevice = interface->GetBoard()->GetDevice(newDeviceId);
    newDevice->Update();

    return true;
}
