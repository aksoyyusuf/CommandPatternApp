#include "CreateUserCmd.h"
#include <iostream>

bool CreateUserCommand::Execute(IDatabase& database) const
{
	std::cout << "Please enter name: " << std::endl;
	std::string name;

	std::getline(std::cin, name);
	std::cout << std::endl;

	if (database.CreateUser(name))
	{
		std::cout << "User " << name << " added!" << std::endl;
	}
	else 
	{
		std::cout << "ERROR: User already exists!" << std::endl;		
	}

	return false;
}
