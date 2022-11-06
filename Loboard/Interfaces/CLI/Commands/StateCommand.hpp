//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_STATECOMMAND_HPP
#define LOBOARD_STATECOMMAND_HPP


#include "Command.hpp"

class StateCommand: public Command
{
public:
    StateCommand(CommandLineInterface* interface, std::string keyword);

    bool Handle(const std::string &cmd) override;
};


#endif //LOBOARD_STATECOMMAND_HPP
