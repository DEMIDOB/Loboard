//
// Created by Dan Demidov on 06.11.22.
//

#include "WireCommand.hpp"
#include "../CommandLineInterface.hpp"

WireCommand::WireCommand(CommandLineInterface *interface, std::string keyword) : CommandHandler(interface,
                                                                                                std::move(keyword))
{

}

bool WireCommand::Handle(const std::string &cmd)
{
    CommandArgs args;
    CommandHandler::decompose(cmd, &args);

    if (args.argc < 3)
    {
        CLI_OUT("Not enough arguments!");
        return true;
    }

    uint8_t srcId    = std::stoi(args.argv[1]);
    uint8_t destId   = std::stoi(args.argv[2]);

    Device* requestedDestDevice = interface->GetBoard()->GetDevice(destId);
    if (requestedDestDevice == nullptr)
    {
        CLI_OUT("Could not find device with id #" << destId);
        return true;
    }

    uint8_t destPort = requestedDestDevice->GetNextInputID();

    if (args.argc > 3)
    {
        destPort = std::stoi(args.argv[3]);
    }
    else if (destPort < 0)
    {
        CLI_OUT("Could not wire requested devices: all the inputs are already wired");
        return false;
    }

    if (interface->GetBoard()->Wire(srcId, destId, destPort) == nullptr)
    {
        CLI_OUT("Could not wire requested devices: check the correctness of the ids and/or the destination port");
        return true;
    }

    CLI_OUT("OK: " << (int) srcId << " -> " << (int) destId << "[" << (int) destPort << "]");
    return true;
}


