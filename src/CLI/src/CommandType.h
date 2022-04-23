#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

enum class CommandType
{
	NONE = 0,
	CREATE_USER = 1,
	SEND_MESSAGE = 2,
	RECEIVE_ALL_MSG_FOR_USER = 3,
	QUIT = 4
};

#endif	// !COMMAND_TYPE_H
