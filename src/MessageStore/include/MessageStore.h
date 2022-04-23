#ifndef MESSAGE_STORE_H
#define MESSAGE_STORE_H

#include <memory>
#include "IPeripheral.h"
#include "IDatabase.h"

enum class MessageStoreState
{
	IN_PROGRESS,
	COMPLETED
};

class MessageStore 
{
public:
	/**
	* Message Store constructor
	*/
	MessageStore();

	/**
	* Message Store destructor
	*/
	~MessageStore();

	/**
	* Executes the MessageStore's synchronous routine.
	*
	* @return  IN_PROGRESS   : If the routine is in progress
	* @return  COMPLETED     : If the routine is completed
	*/
	MessageStoreState Process();

private:
	std::unique_ptr<IPeripheral> m_peripheral;
	std::unique_ptr<IDatabase> m_database;
};

#endif	// !MESSAGE_STORE_H
