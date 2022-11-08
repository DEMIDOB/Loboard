//
// Created by Dan Demidov on 06.11.22.
//

#include "LsCommand.hpp"
#include "Board.hpp"
#include "../CommandLineInterface.hpp"

LsCommand::LsCommand(CommandLineInterface *commandLineInterface, std::string keyword) : Command(
    commandLineInterface, std::move(keyword))
{

}

bool LsCommand::Handle(const std::string &cmd)
{
    Board* board = interface->GetBoard();
    uint8_t dCount = board->GetDevicesCount();

    for (uint8_t deviceID = 0; deviceID < dCount; ++deviceID)
    {
        Device* d = board->GetDevice(deviceID);

        if (d == nullptr)
        {
            continue;
        }

        CLI_OUT(std::basic_string<char>(*d));
    }

    return true;
}
