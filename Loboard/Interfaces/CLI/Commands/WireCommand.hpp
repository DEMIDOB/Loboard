//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_WIRECOMMAND_HPP
#define LOBOARD_WIRECOMMAND_HPP

#include "Command.hpp"

class WireCommand: public Command
{
public:
    WireCommand(CommandLineInterface* interface, std::string keyword);

    bool Handle(const std::string &cmd) override;
};


#endif //LOBOARD_WIRECOMMAND_HPP
