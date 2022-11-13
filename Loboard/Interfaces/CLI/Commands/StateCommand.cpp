//
// Created by Dan Demidov on 06.11.22.
//

#include "StateCommand.hpp"
#include "Device.hpp"
#include "../CommandLineInterface.hpp"

StateCommand::StateCommand(CommandLineInterface *interface, std::string keyword)
    : CommandHandler(interface,
                     std::move(keyword))
{

}

bool StateCommand::Handle(const std::string &cmd)
{
    CommandArgs args;
    CommandHandler::decompose(cmd, &args);

    if (args.argc < 2)
    {
        CLI_OUT("Not enough arguments!");
        return true;
    }

    uint8_t id = std::stoi(args.argv[1]);
    Device* requestedDevice = interface->GetBoard()->GetDevice(id);

    if (requestedDevice == nullptr)
    {
        CLI_OUT("Could not find device with id " << id);
        return true;
    }

    static const std::string STATE[] = {"LOW", "HIGH"};
    CLI_OUT(STATE[requestedDevice->GetState()]);

    return true;
}
