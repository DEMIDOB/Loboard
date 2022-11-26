//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_LSCOMMAND_HPP
#define LOBOARD_LSCOMMAND_HPP


#include "CommandHandler.hpp"

class LsCommand: public CommandHandler
{
public:
    LsCommand(CommandLineInterface *commandLineInterface);
    bool Handle(const std::string &cmd) override;
};


#endif //LOBOARD_LSCOMMAND_HPP
