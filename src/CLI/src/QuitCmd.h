#ifndef QUIT_CMD_H
#define QUIT_CMD_H

#include "ICommand.h"
#include "IDatabase.h"

class QuitCommand : public ICommand
{
public:
    QuitCommand() = default;
    ~QuitCommand() = default;
    bool Execute(IDatabase& database) const override;
};

#endif  // !QUIT_CMD_H
