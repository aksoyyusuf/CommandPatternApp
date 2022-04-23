#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <memory>
#include "IDatabase.h"

class ICommand 
{
public:
	/**
	* Command ID to distinguish the commands if necessary
	*/
	int commandID;

	/**
	* Virtual destructor of base class
	*/
	virtual ~ICommand() = default;

	/**
	* Executes the command.
	* @return	false	: If execution of the command doesn't require quit
	* @return	true	: If execution of the command requires quit
	* Please see the {@link https://en.wikipedia.org/wiki/Command_pattern} for Command Pattern
	*/
	virtual bool Execute(IDatabase& database) const = 0;
};

#endif	// !ICOMMAND_H
