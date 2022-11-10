//
//  CommandLineInterface.cpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#include <fstream>

#include "CommandLineInterface.hpp"
#include "Commands/Command.hpp"
#include "CLI/Commands/LsCommand.hpp"
#include "CLI/Commands/ExitCommand.hpp"
#include "CLI/Commands/NewdCommand.hpp"
#include "CLI/Commands/RemoveCommand.hpp"
#include "CLI/Commands/StateCommand.hpp"
#include "CLI/Commands/WireCommand.hpp"

CommandLineInterface::CommandLineInterface(Board* board)
    : Interface::Interface(board)
{
    std::vector<Command*> commands = {
        new LsCommand(this, "ls"),
        new ExitCommand(this, "exit"),
        new NewCommand(this, "new"),
        new RemoveCommand(this, "rm"),
        new StateCommand(this, "state"),
        new WireCommand(this, "wire"),
    };

    for (Command* cmd : commands)
    {
        commandsMap[cmd->GetKeyword()] = cmd;
    }
}

bool CommandLineInterface::Update()
{
    std::cout << std::endl << " >> ";

    char *c_cmd = new char[MAX_INPUT_SIZE];
    std::cin.getline(c_cmd, MAX_INPUT_SIZE);

    bool cmdHandleResult = HandleCommand(&c_cmd);
    delete[] c_cmd;

    return cmdHandleResult;
}

bool CommandLineInterface::HandleCommand(char **c_cmd_ptr)
{
    std::string cmd = std::string(*c_cmd_ptr);

    std::vector<std::string> commands;
    size_t currentStart = 0, currentEnd = 0;

    while (++currentEnd < cmd.size())
    {
        if (cmd[currentEnd] == ';' || cmd[currentEnd] == '\n')
        {
            std::string sbstr = cmd.substr(currentStart, currentEnd - currentStart);
            commands.push_back(sbstr);
            currentStart = currentEnd;

            while (cmd[currentStart] == ';' || cmd[currentStart] == ' ' || cmd[currentStart] == '\n')
            {
                currentStart = ++currentEnd;
            }
        }
    }

    commands.push_back(cmd.substr(currentStart, currentEnd));

    for (std::string currentCommand: commands)
    {
        std::string keyword = currentCommand.substr(0, currentCommand.find(' '));

        if (commandsMap.count(keyword))
        {
            if (!commandsMap[keyword]->Handle(currentCommand))
            {
                return false;
            }
        }
        else
        {
            CLI_OUT("Unknown command: \"" << currentCommand << "\"");
        }
    }

    return true;
}
