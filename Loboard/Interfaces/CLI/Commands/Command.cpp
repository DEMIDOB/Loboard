//
// Created by Dan Demidov on 06.11.22.
//

#include "Command.hpp"
#include "../CommandLineInterface.hpp"

#include <utility>

const std::string &Command::GetKeyword() const
{
    return keyword;
}

Command::Command(CommandLineInterface *const commandLineInterface, std::string keyword)
    : interface(commandLineInterface), keyword(std::move(keyword)) {}
