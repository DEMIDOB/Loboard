//
// Created by Dan Demidov on 06.11.22.
//

#include "WireCommand.hpp"
#include "../CommandLineInterface.hpp"

WireCommand::WireCommand(CommandLineInterface *interface, std::string keyword) : Command(interface,
                                                                                         std::move(keyword))
{

}

bool WireCommand::Handle(const std::string &cmd)
{
    CommandArgs args;
    Command::decompose(cmd, &args);

    if (args.argc < 4)
    {
        CLI_OUT("Not enough arguments!");
        return true;
    }

    uint8_t srcId    = std::stoi(args.argv[1]);
    uint8_t destId   = std::stoi(args.argv[2]);
    uint8_t destPort = std::stoi(args.argv[3]);

    DirectionedWire* newWire = interface->GetBoard()->Wire(srcId, destId, destPort);

    if (newWire == nullptr)
    {
        CLI_OUT("Could not wire requested devices: check the correctness of the ids and/or the destination port");
        return true;
    }

    CLI_OUT("OK: " << (int) srcId << " -> " << (int) destId << "[" << (int) destPort << "]");
    return true;
}


