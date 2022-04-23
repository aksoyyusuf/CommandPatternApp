#ifndef IPERIPHERAL_H
#define IPERIPHERAL_H

#include <memory>
#include "ICommand.h"

class IPeripheral
{
public:

	/**
	* Virtual destructor of base class
	*/
	virtual ~IPeripheral() = default;

	/**
	* It is a state machine call of the peripheral.
	* Peripheral may initilizes and configures the resources or reset internal data structures.
	* It should be called before receiving the command. @see IPeripheral#ReceiveCommand().
	*/
	virtual void OnEntry() = 0;


	/**
	* It is a state machine call of the peripheral.	 
	* Peripheral may release the resources and completes its operations.
	* It should be called after receiving the command. @see IPeripheral#ReceiveCommand().
	*/
	virtual void OnExit() = 0;


	/**
	* Receives the command from the user.
	* 
	* @return	Returns the received command. @see ICommand
	* 
	*/
	virtual std::unique_ptr<ICommand> ReceiveCommand() = 0;
};

#endif	// !IPERIPHERAL_H
