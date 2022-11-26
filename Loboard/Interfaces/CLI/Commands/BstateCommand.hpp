//
// Created by Dan Demidov on 26.11.22.
//

#ifndef LOBOARD_BSTATECOMMAND_HPP
#define LOBOARD_BSTATECOMMAND_HPP

#include "CommandHandler.hpp"

class BstateCommand: public CommandHandler
{
public:
    BstateCommand(CommandLineInterface* commandLineInterface);
    bool Handle(const std::string &cmd) override;
};


#endif //LOBOARD_BSTATECOMMAND_HPP
