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

void Command::decompose(const std::string& cmd, CommandArgs* args)
{
    std::string currentString;
    *args = CommandArgs{0, {}};

    for (const char c: cmd)
    {
        if (c == ' ' && !currentString.empty())
        {
            args->argv.push_back(currentString);
            (args->argc)++;
            currentString = "";
            continue;
        }

        currentString += c;
    }

    if (!currentString.empty())
    {
        args->argv.push_back(currentString);
        (args->argc)++;
    }
}
