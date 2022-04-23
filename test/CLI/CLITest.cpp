#include "gtest/gtest.h"
#include <stdlib.h>
#include <memory>
#include <iostream>
#include "CLI.h"


TEST(CLITest, testCreateUserCommand) 
{
    std::unique_ptr<IPeripheral> peripheral{ std::make_unique<CLI>() };

    peripheral->OnEntry();

    std::cout << std::endl <<
        "======== Google Test: Please select <1. Create User> option ========"
            << std::endl;

    std::unique_ptr<ICommand> command{ peripheral->ReceiveCommand() };

    EXPECT_EQ(command->commandID, 1);

    peripheral->OnExit();
}

TEST(CLITest, testSendMessageCommand) 
{
    std::unique_ptr<IPeripheral> peripheral{ std::make_unique<CLI>() };

    peripheral->OnEntry();

    std::cout << std::endl <<
        "======== Google Test: Please select <2. Send Message> option ========"
            << std::endl;

    std::unique_ptr<ICommand> command{ peripheral->ReceiveCommand() };

    EXPECT_EQ(command->commandID, 2);

    peripheral->OnExit();
}

TEST(CLITest,testReceiveMessageCommand)
{
    std::unique_ptr<IPeripheral> peripheral{ std::make_unique<CLI>() };

    peripheral->OnEntry();

    std::cout << std::endl <<
        "======== Google Test: Please select <3. Receive All Messages For User> option ========"
        << std::endl;

    std::unique_ptr<ICommand> command{ peripheral->ReceiveCommand() };

    EXPECT_EQ(command->commandID, 3);

    peripheral->OnExit();
}

TEST(CLITest, testQuitCommand)
{
    std::unique_ptr<IPeripheral> peripheral{ std::make_unique<CLI>() };

    peripheral->OnEntry();

    std::cout << std::endl <<
        "======== Google Test: Please select <4. Quit> option ========"
        << std::endl;

    std::unique_ptr<ICommand> command{ peripheral->ReceiveCommand() };

    EXPECT_EQ(command->commandID, 4);

    peripheral->OnExit();
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
