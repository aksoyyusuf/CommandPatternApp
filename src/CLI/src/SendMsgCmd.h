#ifndef SEND_MSG_CMD_H
#define SEND_MSG_CMD_H

#include "ICommand.h"
#include "IDatabase.h"

class SendMsgCommand : public ICommand 
{
public:
    SendMsgCommand() = default;
    ~SendMsgCommand() = default;
    bool Execute(IDatabase& database) const override;
};

#endif  // !SEND_MSG_CMD_H
