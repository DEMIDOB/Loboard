//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_LISTDCOMMAND_HPP
#define LOBOARD_LISTDCOMMAND_HPP


#include "Command.hpp"

class ListdCommand: public Command
{
public:
    ListdCommand(CommandLineInterface *commandLineInterface, std::string keyword);
    bool Handle(const std::string &cmd) override;
};


#endif //LOBOARD_LISTDCOMMAND_HPP
