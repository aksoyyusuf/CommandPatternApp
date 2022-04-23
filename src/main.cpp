#include "MessageStore.h"

int main(int, const char* [])
{	
	MessageStore handle;

	while (true)
	{
		if (MessageStoreState::COMPLETED == handle.Process())
		{
			break;
		}

		// Other tasks can be done here
	}
	
	return 0;
}
