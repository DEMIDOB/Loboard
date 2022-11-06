//
//  CommandLineInterface.cpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#include "CommandLineInterface.hpp"
#include "Commands/Command.hpp"
#include "CLI/Commands/ListdCommand.hpp"
#include "CLI/Commands/ExitCommand.hpp"
#include "CLI/Commands/NewdCommand.hpp"
#include "CLI/Commands/StateCommand.hpp"

CommandLineInterface::CommandLineInterface(Board* board)
    : Interface::Interface(board)
{
    std::vector<Command*> commands = {
        new ListdCommand(this, "ls"),
        new ExitCommand(this, "exit"),
        new NewdCommand(this, "new"),
        new StateCommand(this, "state"),
    };

    for (Command* cmd : commands)
    {
        commandsMap[cmd->GetKeyword()] = cmd;
    }
}

bool CommandLineInterface::Update()
{
    std::cout << std::endl << " >> ";

    std::string cmd;
    char *c_cmd = new char[MAX_INPUT_SIZE];
    std::cin.getline(c_cmd, MAX_INPUT_SIZE);

    cmd = std::string(c_cmd);
    delete[] c_cmd;

    std::string keyword = cmd.substr(0, cmd.find(' '));
    
    if (commandsMap.count(keyword))
    {
        return commandsMap[keyword]->Handle(cmd);
    }
    else
    {
        std::cout << "Unknown command!" << std::endl;
    }
    
    return true;
}
