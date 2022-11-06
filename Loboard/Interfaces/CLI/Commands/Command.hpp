//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_COMMAND_HPP
#define LOBOARD_COMMAND_HPP

class CommandLineInterface;

#include <iostream>
#include <string>

#include "CommandArgs.hpp"

#define CLI_OUT(x) std::cout << " -- " << x << std::endl;
#define CLI_HANDLER_ARGS CommandLineInterface& interface, const std::string& cmd

class CommandLineInterface;

class Command
{
protected:
    std::string keyword;
    CommandLineInterface *const interface;

    static void decompose(const std::string&, CommandArgs*);
public:
    const std::string &GetKeyword() const;

    Command(CommandLineInterface *commandLineInterface, std::string keyword);
    virtual bool Handle(const std::string& cmd) = 0;
};


#endif //LOBOARD_COMMAND_HPP
