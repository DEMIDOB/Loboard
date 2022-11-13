//
// Created by Dan Demidov on 11.11.22.
//

#ifndef LOBOARD_COMMANDRETURN_HPP
#define LOBOARD_COMMANDRETURN_HPP

#include <string>

class CommandHandler;

typedef struct {
    CommandHandler& producer;
    std::string value;
} CommandReturn;

#endif //LOBOARD_COMMANDRETURN_HPP
