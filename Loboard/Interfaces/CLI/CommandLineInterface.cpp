//
//  CommandLineInterface.cpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#include <fstream>

#include "CommandLineInterface.hpp"
#include "Commands/CommandHandler.hpp"
#include "CLI/Commands/LsCommand.hpp"
#include "CLI/Commands/ExitCommand.hpp"
#include "CLI/Commands/NewdCommand.hpp"
#include "CLI/Commands/RemoveCommand.hpp"
#include "CLI/Commands/StateCommand.hpp"
#include "CLI/Commands/WireCommand.hpp"

CommandLineInterface::CommandLineInterface(Board* board)
    : Interface::Interface(board), variables(SessionVariablesSet())
{
    std::vector<CommandHandler*> commands = {
        new LsCommand(this, "ls"),
        new ExitCommand(this, "exit"),
        new NewCommand(this, "new"),
        new RemoveCommand(this, "rm"),
        new StateCommand(this, "state"),
        new WireCommand(this, "wire"),
    };

    for (CommandHandler* cmd : commands)
    {
        commandsMap[cmd->GetKeyword()] = cmd;
    }

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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

    for (std::string currentRawCommand: commands)
    {
        int assignmentSepIdx = currentRawCommand.find('=');
        std::string currentCommand = currentRawCommand.substr(assignmentSepIdx + 1);
        int trimmingIdx = 0;

        while (trimmingIdx < currentCommand.size() && currentCommand[trimmingIdx] == ' ')
        {
            ++trimmingIdx;
        }

        std::string assigmentLeft = currentRawCommand.substr(0, assignmentSepIdx);
        std::vector<std::string> assignmentTargets = {""};

        for (const char c : assigmentLeft)
        {
            if (c != ' ') // sorry for this nested shit, but i thought it would be cleaner this way
            {
                if (c == ',')
                {
                    assignmentTargets.push_back("");
                    continue;
                }

                assignmentTargets[assignmentTargets.size() - 1] += c;
            }
        }

        currentCommand = currentCommand.substr(trimmingIdx);
        std::string keyword = currentCommand.substr(0, currentCommand.find(' '));

        if (commandsMap.count(keyword))
        {
            if (!commandsMap[keyword]->Handle(currentCommand))
            {
                return false;
            }
        }
        else if (variables.Has(currentRawCommand))
        {
            Device* device = board->GetDevice(std::stoi(variables.Get(currentRawCommand)));
            if (device == nullptr)
                CLI_OUT("Unknown command: \"" << currentCommand << "\"")
            else
                CLI_OUT(std::basic_string<char>(*device));
        }
        else
        {
            CLI_OUT("Unknown command: \"" << currentCommand << "\"");
        }

        int targetIdx = assignmentTargets.size();
        while (!commandReturnStack.empty())
        {
            variables.set(assignmentTargets[--targetIdx], commandReturnStack.top().value);
            commandReturnStack.pop();
        }
    }

    return true;
}

void CommandLineInterface::PushCommandReturnValue(CommandHandler &cmd, std::string& value)
{
    this->commandReturnStack.push(CommandReturn{cmd, value});
}
