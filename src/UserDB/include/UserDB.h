#ifndef USERDB_H
#define USERDB_H

#include "IDatabase.h"
#include <unordered_map>
#include <deque>
#include <iostream>

class UserDB : public IDatabase
{
public:
	UserDB() = default;
	~UserDB() = default;

	bool IsUserExists(const std::string& userName) const override;
	bool CreateUser(const std::string& userName) override;

	bool PushMessage(const Message& message) override;
	bool FrontMessage(const std::string& userName, Message** message) override;
	bool PopMessage(const std::string& userName) override;
	bool GetMessageCount(const std::string& userName, int& count) override;

private:
	std::unordered_map<std::string, std::deque<Message>> userMsgMap;
};

#endif	// !USERDB_H
