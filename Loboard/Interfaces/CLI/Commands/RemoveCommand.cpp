//
// Created by Dan Demidov on 07.11.22.
//

#include "RemoveCommand.hpp"
#include "../CommandLineInterface.hpp"

RemoveCommand::RemoveCommand(CommandLineInterface *interface, std::string keyword): CommandHandler(interface,
                                                                                                   std::move(keyword))
{

}

bool RemoveCommand::Handle(const std::string &cmd)
{
    CommandArgs args;
    CommandHandler::decompose(cmd, &args);

    if (args.argc < 2)
    {
        CLI_OUT("Not enough arguments!");
        return true;
    }

    uint8_t id = std::stoi(args.argv[1]);
    if (!interface->GetBoard()->RemoveDevice(id))
    {
        CLI_OUT("Could not delete requested device: check the correctness of provided id");
        return true;
    }

    CLI_OUT("Removed #" << (int) id);
    return true;
}

