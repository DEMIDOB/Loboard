//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_EXITCOMMAND_HPP
#define LOBOARD_EXITCOMMAND_HPP


#include "Command.hpp"

class ExitCommand: public Command
{
public:
    ExitCommand(CommandLineInterface *interface, std::string keyword);

    bool Handle(const std::string& cmd) override;
};


#endif //LOBOARD_EXITCOMMAND_HPP
