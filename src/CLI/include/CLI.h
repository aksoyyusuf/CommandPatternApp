#ifndef CLI_H
#define CLI_H

#include "IPeripheral.h"
#include "ICommand.h"
#include <memory>

class CLI : public IPeripheral
{
public:
	CLI() = default;
	~CLI() = default;

	void OnEntry();
	void OnExit();
	std::unique_ptr<ICommand> ReceiveCommand();
};

#endif	// !CLI_H
