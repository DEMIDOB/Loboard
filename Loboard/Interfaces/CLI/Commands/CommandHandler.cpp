//
// Created by Dan Demidov on 06.11.22.
//

#include "CommandHandler.hpp"
#include "../CommandLineInterface.hpp"

#include <utility>

const std::string &CommandHandler::GetKeyword() const
{
    return keyword;
}

CommandHandler::CommandHandler(CommandLineInterface *const commandLineInterface, std::string keyword)
    : interface(commandLineInterface), keyword(std::move(keyword)) {}

void CommandHandler::decompose(const std::string& cmd, CommandArgs* args)
{
    std::string currentString;
    *args = CommandArgs{0, {}};

    for (const char c: cmd)
    {
        if (c == ' ' && !currentString.empty())
        {
            if (interface->variables.Has(currentString))
            {
                currentString = interface->variables.Get(currentString);
            }

            args->argv.push_back(currentString);
            (args->argc)++;
            currentString = "";
            continue;
        }

        currentString += c;
    }

    if (!currentString.empty())
    {
        if (interface->variables.Has(currentString))
        {
            currentString = interface->variables.Get(currentString);
        }

        args->argv.push_back(currentString);
        (args->argc)++;
    }
}
