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

        std::string response;
        if (d->IsBlocked())
        {
            response.append("!"); // prefix indicating that the device is blocked
        }
        response += "[#" + std::to_string(deviceID) + " " + d->GetName() + "]";

        CLI_OUT(response)
    }

    return true;
}
