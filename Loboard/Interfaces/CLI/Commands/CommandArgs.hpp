//
// Created by Dan Demidov on 06.11.22.
//

#ifndef LOBOARD_COMMANDARGS_HPP
#define LOBOARD_COMMANDARGS_HPP

#include <vector>
#include <string>

typedef struct CommandArgs CommandArgs;

struct CommandArgs
{
    uint8_t argc;
    std::vector<std::string> argv;

    std::string operator[](size_t idx)
    {
        return argv[idx];
    }
};

#endif //LOBOARD_COMMANDARGS_HPP
