#include "MessageStore.h"
#include "CLI.h"
#include "UserDB.h"

#include <stdlib.h>
#include <iostream>

MessageStore::MessageStore()
{
	m_peripheral = std::make_unique<CLI>();
	m_database = std::make_unique<UserDB>();
}

MessageStore::~MessageStore()
{
}

MessageStoreState MessageStore::Process()
{
	m_peripheral->OnEntry();

	std::unique_ptr<ICommand> command { m_peripheral->ReceiveCommand() };
	bool shouldQuit{ command->Execute( *m_database.get()) };

	m_peripheral->OnExit();

	if(shouldQuit)
		return MessageStoreState::COMPLETED;

	return MessageStoreState::IN_PROGRESS;
}
