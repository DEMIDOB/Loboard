//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_LSCOMMAND_HPP
#define LOBOARD_LSCOMMAND_HPP


#include "Command.hpp"

class LsCommand: public Command
{
public:
    LsCommand(CommandLineInterface *commandLineInterface, std::string keyword);
    bool Handle(const std::string &cmd) override;
};


#endif //LOBOARD_LSCOMMAND_HPP
