//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_NEWDCOMMAND_HPP
#define LOBOARD_NEWDCOMMAND_HPP


#include "Command.hpp"

class NewCommand: public Command
{
public:
    NewCommand(CommandLineInterface* interface, std::string keyword);
    bool Handle(const std::string& cmd) override;
};


#endif //LOBOARD_NEWDCOMMAND_HPP
