//
// Created by Dan Demidov on 06.11.22.
//

#include "NewdCommand.hpp"
#include "../CommandLineInterface.hpp"
#include "Devices.hpp"

NewCommand::NewCommand(CommandLineInterface *interface, std::string keyword) : CommandHandler(interface,
                                                                                              std::move(keyword))
{

}

bool NewCommand::Handle(const std::string &cmd)
{
    CommandArgs args;
    CommandHandler::decompose(cmd, &args);

    if (args.argc < 2)
    {
        CLI_OUT("No device type specified")
        return true;
    }

    std::string deviceType = args[1];
    uint8_t amountToAdd = 1;

    if (args.argc > 2)
    {
        amountToAdd = std::stoi(args[2]);
    }

    if (!DEVICES_BY_NAME.count(deviceType))
    {
        CLI_OUT("No such device type is available")
        return true;
    }

    for (size_t i = 0; i < amountToAdd; ++i)
    {
        DeviceInitializer deviceInitializer = DEVICES_BY_NAME.at(deviceType);

        uint8_t newDeviceId = interface->GetBoard()->AddDevice(deviceInitializer(0));
        Device* newDevice = interface->GetBoard()->GetDevice(newDeviceId);
        newDevice->Update();

        std::string newDeviceID_s = std::to_string((int) newDeviceId);
        interface->PushCommandReturnValue(*this, newDeviceID_s);

        CLI_OUT("Created: " << std::basic_string<char>(*newDevice));
    }

    return true;
}
