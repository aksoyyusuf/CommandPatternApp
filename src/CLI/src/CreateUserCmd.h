#ifndef CREATE_USER_CMD_H
#define CREATE_USER_CMD_H

#include "ICommand.h"
#include "IDatabase.h"
#include <iostream>

class CreateUserCommand : public ICommand
{
public:
    CreateUserCommand() = default;
    ~CreateUserCommand() = default;
    bool Execute(IDatabase& database) const override;
};

#endif  // !CREATE_USER_CMD_H
