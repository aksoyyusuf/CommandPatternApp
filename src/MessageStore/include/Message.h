#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

typedef struct
{
	std::string from{};
	std::string to{};
	std::string message{};
}Message;

#endif	// !MESSAGE_H
