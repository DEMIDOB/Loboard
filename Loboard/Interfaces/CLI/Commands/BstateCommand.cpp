//
// Created by Dan Demidov on 26.11.22.
//

#include "BstateCommand.hpp"
#include "../CommandLineInterface.hpp"
#include "../../../Devices/Device.hpp"

BstateCommand::BstateCommand(CommandLineInterface* commandLineInterface)
	: CommandHandler(commandLineInterface, "bstate")
{

}

bool BstateCommand::Handle(const std::string &cmd)
{
	CommandArgs args;
	CommandHandler::decompose(cmd, &args);

	if (args.argc < 2)
	{
		CLI_OUT("Not enough arguments!");
		return true;
	}

	char response[args.argc];
	response[args.argc - 1] = 0;

	for (int i = 1; i < args.argc; ++i)
	{
		uint8_t id = std::stoi(args[i]);
		Device* requestedDevice = interface->GetBoard()->GetDevice(id);

		if (requestedDevice == nullptr)
		{
			response[i - 1] = '-';
			continue;
		}

		response[i - 1] = static_cast<char>(requestedDevice->GetState()) + 0x30;
	}

	CLI_OUT(std::string(response));
	return true;
}
