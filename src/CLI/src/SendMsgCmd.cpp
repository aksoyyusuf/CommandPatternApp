#include "SendMsgCmd.h"
#include <iostream>

bool SendMsgCommand::Execute(IDatabase& database) const
{
	Message message;

	std::cout << "From: ";
	std::getline(std::cin, message.from);
	std::cout << std::endl;

	if (database.IsUserExists(message.from))
	{
		std::cout << "To: ";
		std::getline(std::cin, message.to);
		std::cout << std::endl;

		if (database.IsUserExists(message.to))
		{
			std::cout << "Message: ";
			std::getline(std::cin, message.message);
			std::cout << std::endl;

			std::cout << "Message Sent!" << std::endl;

			database.PushMessage(message);
		}
		else
		{
			std::cout << "ERROR: User doesn't exist!" << std::endl;
		}	
	}		
	else 
	{
		std::cout << "ERROR: User doesn't exist!" << std::endl;
	}

	return false;
}
