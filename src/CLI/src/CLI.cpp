#include "CLI.h"
#include <iostream>
#include <limits>

#include "CommandType.h"
#include "ReceiveMsgCmd.h"
#include "SendMsgCmd.h"
#include "CreateUserCmd.h"
#include "QuitCmd.h"

static void clearScreen()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

static void showOptions()
{
	std::cout << "Please select an option:" << std::endl;
	std::cout << "1. Create User" << std::endl;
	std::cout << "2. Send Message" << std::endl;
	std::cout << "3. Receive All Messages For User" << std::endl;
	std::cout << "4. Quit" << std::endl;
}

static void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static CommandType readOption()
{
	std::string operation{};
	std::cin >> operation;

	ignoreLine(); // remove any extraneous input

	if (0 == operation.compare("1"))
	{
		return CommandType::CREATE_USER;
	}
	else if (0 == operation.compare("2"))
	{
		return CommandType::SEND_MESSAGE;
	}
	else if (0 == operation.compare("3"))
	{
		return CommandType::RECEIVE_ALL_MSG_FOR_USER;
	}
	else if (0 == operation.compare("4"))
	{
		return CommandType::QUIT;
	}

	std::cerr << "Invalid Option Selected.  Please try again.\n";
	return CommandType::NONE;
}

void CLI::OnEntry()
{
	clearScreen();	
}

void CLI::OnExit()
{
	std::cout << std::endl << 
		"Enter any key and press return to continue.....";
	std::string str;
	std::getline(std::cin, str);
}

std::unique_ptr<ICommand> CLI::ReceiveCommand()
{
	showOptions();

	CommandType commandType{ CommandType::NONE };

	do
	{
		commandType = readOption();
	}
	while (commandType == CommandType::NONE);

	switch (commandType)
	{

	case(CommandType::CREATE_USER): 
	{
		std::unique_ptr<ICommand> cmd{ std::make_unique<CreateUserCommand>() };
		cmd->commandID = static_cast<int>(CommandType::CREATE_USER);

		return cmd;
	}

	case(CommandType::SEND_MESSAGE):
	{
		std::unique_ptr<ICommand> cmd{ std::make_unique<SendMsgCommand>() };
		cmd->commandID = static_cast<int>(CommandType::SEND_MESSAGE);

		return cmd;
	}

	case(CommandType::RECEIVE_ALL_MSG_FOR_USER):
	{
		std::unique_ptr<ICommand> cmd{ std::make_unique<ReceiveMsgCommand>() };
		cmd->commandID = static_cast<int>(CommandType::RECEIVE_ALL_MSG_FOR_USER);

		return cmd;
	}

	case(CommandType::QUIT):
	{
		std::unique_ptr<ICommand> cmd{ std::make_unique<QuitCommand>() };
		cmd->commandID = static_cast<int>(CommandType::QUIT);

		return cmd;
	}

	default:
		std::cerr << "Unexpected error.\n";
		break;	
	}	
	
	throw std::invalid_argument("Invalid Command Type!");
}
