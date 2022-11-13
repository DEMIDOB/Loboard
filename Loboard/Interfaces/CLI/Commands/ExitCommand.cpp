//
// Created by Dan Demidov on 06.11.22.
//

#include "ExitCommand.hpp"

ExitCommand::ExitCommand(CommandLineInterface *interface, std::string keyword) : CommandHandler(interface,
                                                                                                std::move(keyword))
{

}

bool ExitCommand::Handle(const std::string &cmd)
{
    CLI_OUT("See ya soon! :)")
    return false;
}


