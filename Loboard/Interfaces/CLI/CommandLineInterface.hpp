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
#include <string>

#include "Interface.hpp"

#include "Interfaces/CLI/Commands/Command.hpp"

#define MAX_INPUT_SIZE 128

class CommandLineInterface: public Interface
{
private:
    std::map<std::string, Command*> commandsMap;
public:
    explicit CommandLineInterface(Board* board);
    bool Update() override;
};

// Handlers
//bool h_exit(CLI_HANDLER_ARGS);
//bool h_listd(CLI_HANDLER_ARGS);
//bool h_newd(CLI_HANDLER_ARGS);

#endif /* CommandLineInterface_hpp */
