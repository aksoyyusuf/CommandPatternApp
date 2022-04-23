#include "ReceiveMsgCmd.h"
#include <iostream>

bool ReceiveMsgCommand::Execute(IDatabase& database) const
{
	std::cout << "Enter name of user to receive all messages for: " << std::endl;
	std::string userName;
	std::getline(std::cin, userName);
	std::cout << std::endl;

	if (database.IsUserExists(userName))
	{
		std::cout << std::endl << "===== BEGIN MESSAGES =====" << std::endl;

		int messageCount{};
		database.GetMessageCount(userName, messageCount);
		
		for (int i{}; i < messageCount; ++i)
		{
			Message* message;

			database.FrontMessage(userName, &message);

			std::cout << "Message " << i << std::endl;
			std::cout << "From: " << message->from << std::endl;
			std::cout << "Content: " << message->message << std::endl << std::endl;

			database.PopMessage(userName);
		}

		std::cout << std::endl << "===== END MESSAGES =====" << std::endl;
	}
	else
	{
		std::cout << "ERROR: User doesn't exist!" << std::endl;
	}
		
	return false;
}
