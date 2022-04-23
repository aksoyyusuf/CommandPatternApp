#include "UserDB.h"

bool UserDB::IsUserExists(const std::string& userName) const
{
	if (userMsgMap.find(userName) == userMsgMap.end())
	{
		return false;
	}

	return true;
}

bool UserDB::CreateUser(const std::string& userName)
{
	if (IsUserExists(userName))
		return false;	

	userMsgMap[userName] = {};

	return true;
}

bool UserDB::PushMessage(const Message& message)
{
	if (!IsUserExists(message.from) || !IsUserExists(message.to))
		return false;

	userMsgMap[message.to].push_back(message);

	return true;
}

bool UserDB::FrontMessage(const std::string& userName, Message** message)
{
	if (!IsUserExists(userName))
		return false;

	if (userMsgMap[userName].size() <= 0)
		return false;

	*message = &(userMsgMap[userName].front());

	return true;
}

bool UserDB::PopMessage(const std::string& userName)
{
	if (!IsUserExists(userName))
		return false;

	if (userMsgMap[userName].size() <= 0)
		return false;

	userMsgMap[userName].pop_front();

	return true;
}

bool UserDB::GetMessageCount(const std::string& userName, int& count)
{
	if (!IsUserExists(userName))
		return false;

	count = 
		static_cast<int>(userMsgMap[userName].size());

	return true;
}
