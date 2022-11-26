//
//  Interface.cpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#include "Interface.hpp"

Interface::Interface(Board* board) : board(board)
{
    
}

Interface::~Interface()
{
    delete board;
}

void Interface::addCommandToSessionHistory(std::string cmd)
{
    // TODO: check for redundancy
    currentSessionHistory.push_back(cmd);
}

Board* Interface::GetBoard() const
{
    return board;
}
