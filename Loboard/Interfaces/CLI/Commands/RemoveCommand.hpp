//
// Created by Dan Demidov on 07.11.22.
//

#ifndef LOBOARD_REMOVECOMMAND_HPP
#define LOBOARD_REMOVECOMMAND_HPP

#include "CommandHandler.hpp"

class RemoveCommand: public CommandHandler
{
public:
    RemoveCommand(CommandLineInterface* interface, std::string keyword);

    bool Handle(const std::string &cmd) override;
};


#endif //LOBOARD_REMOVECOMMAND_HPP
