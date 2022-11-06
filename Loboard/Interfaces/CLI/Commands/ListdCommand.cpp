//
// Created by Dan Demidov on 06.11.22.
//

#include "ListdCommand.hpp"
#include "Board.hpp"
#include "../CommandLineInterface.hpp"

ListdCommand::ListdCommand(CommandLineInterface *commandLineInterface, std::string keyword) : Command(
    commandLineInterface, std::move(keyword))
{

}

bool ListdCommand::Handle(const std::string &cmd)
{
    Board* board = interface->GetBoard();
    uint8_t dCount = board->GetDevicesCount();

    for (uint8_t deviceID = 0; deviceID < dCount; ++deviceID)
    {
        Device* d = board->GetDevice(deviceID);

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
