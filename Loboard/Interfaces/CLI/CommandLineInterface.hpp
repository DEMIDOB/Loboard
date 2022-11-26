//
//  CommandLineInterface.hpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#ifndef CommandLineInterface_hpp
#define CommandLineInterface_hpp

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>

#include "Interface.hpp"

#include "Interfaces/CLI/Commands/CommandHandler.hpp"
#include "CLI/Commands/CommandReturn.hpp"
#include "Session/SessionVariables.hpp"

#define MAX_INPUT_SIZE 128

class CommandLineInterface: public Interface
{
private:
    std::map<std::string, CommandHandler*> commandsMap;
    std::stack<CommandReturn> commandReturnStack;

public:
    explicit CommandLineInterface(Board* board);

    bool HandleCommand(char** c_cmd_ptr);
    bool Update() override;

    void PushCommandReturnValue(CommandHandler& cmd, std::string& value);

    SessionVariablesSet variables;
};

// Handlers
//bool h_exit(CLI_HANDLER_ARGS);
//bool h_listd(CLI_HANDLER_ARGS);
//bool h_newd(CLI_HANDLER_ARGS);

#endif /* CommandLineInterface_hpp */
