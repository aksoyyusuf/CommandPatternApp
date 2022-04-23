#ifndef RECEIVE_MSG_CMD_H
#define RECEIVE_MSG_CMD_H

#include "ICommand.h"
#include "IDatabase.h"

class ReceiveMsgCommand : public ICommand
{
public:
    ReceiveMsgCommand() = default;
    ~ReceiveMsgCommand() = default;
    bool Execute(IDatabase& database) const override;
};

#endif  // !RECEIVE_MSG_CMD_H
