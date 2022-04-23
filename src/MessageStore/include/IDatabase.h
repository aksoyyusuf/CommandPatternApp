#ifndef IDATABASE_H
#define IDATABASE_H

#include "Message.h"

class IDatabase
{
public:
	/**
	* Virtual destructor of base class
	*/
	virtual ~IDatabase() = default;


	/**
	* Checks if user exists in the database
	* 
	* @param	userName  Name of the user
	* 
	* @return	false	: User already exists
	* @return	true	: User doesn't exist
	*/
	virtual bool IsUserExists(const std::string& userName) const = 0;


	/**
	* Creates the user in the database
	* 
	* @param	userName  Name of the user
	* 
	* @return	false	: User already exists
	* @return	true	: User created
	*/
	virtual bool CreateUser(const std::string& userName) = 0;


	/**
	* Adds message to the database. 
	* Pushing a message means that a user sent message to another user.
	* Note that self messaging is allowed.
	*
	* @param	message  Message content which includes "from", "to" and "message text"
	*
	* @return	false	: Operation failed, users are invalid
	* @return	true	: Operation succeed
	*/
	virtual bool PushMessage(const Message& message) = 0;


	/**
	* Gives an oldest message that pushed for given user.
	*
	* @param	userName  Name of the user
	* @param	message   Message pointer that message in the database will be copied
	* 
	* @return	false	: Operation failed, user doesn't exist or there is no message
	* @return	true	: Operation succeed
	*/
	virtual bool FrontMessage(const std::string& userName, Message** message) = 0;


	/**
	* Deletes the oldest message that pushed for given user.
	*
	* @param	userName  Name of the user
	* 
	* @return	false	: Operation failed, user doesn't exist or there is no message
	* @return	true	: Operation succeed
	*/
	virtual bool PopMessage(const std::string& userName) = 0;


	/**
	* Deletes the oldest message that pushed for given user.
	*
	* @param	userName  Name of the user
	* @param	count	  Message count which will be returned
	*
	* @return	false	: Operation failed, user doesn't exist
	* @return	true	: Operation succeed
	*/
	virtual bool GetMessageCount(const std::string& userName, int& count) = 0;
};

#endif	// !IDATABASE_H
