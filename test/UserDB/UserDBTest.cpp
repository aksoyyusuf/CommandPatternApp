#include "gtest/gtest.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include "UserDB.h"

TEST(UserDBTest, createSingleUser) 
{
    std::unique_ptr<IDatabase> 
        database{ std::make_unique<UserDB>() };

    EXPECT_FALSE(database->IsUserExists("Stephen King"));
    EXPECT_TRUE(database->CreateUser("Stephen King"));
    EXPECT_TRUE(database->IsUserExists("Stephen King"));
}

TEST(UserDBTest, createMultipleUsers)
{
    std::unique_ptr<IDatabase>
        database{ std::make_unique<UserDB>() };

    const std::vector<std::string> users
    {
        "Agatha Christie",
        "Stephen King",
        "J.R.R. Tolkien",
        "Isaac Asimov",
        "Orhan Pamuk",
        "Nazim Hikmet"
    };

    for (auto user : users)
        EXPECT_FALSE(database->IsUserExists(user));

    for (auto user : users)
        EXPECT_TRUE(database->CreateUser(user));

    for (auto user : users)
        EXPECT_TRUE(database->IsUserExists(user));
}

TEST(UserDBTest, createExistingUser)
{
    std::unique_ptr<IDatabase>
        database{ std::make_unique<UserDB>() };

    EXPECT_TRUE(database->CreateUser("Agatha Christie"));
    EXPECT_FALSE(database->CreateUser("Agatha Christie"));
}

TEST(UserDBTest, getMessageCount)
{
    std::unique_ptr<IDatabase>
        database{ std::make_unique<UserDB>() };

    std::string from{ "George R.R. Martin" };
    std::string to{ "Andrzej Sapkowski" };

    EXPECT_TRUE(database->CreateUser(from));
    EXPECT_TRUE(database->CreateUser(to));

    std::string msgContent
    {
        "Lorem ipsum dolor sit amet, "
        "consectetur adipiscing elit."
        "Duis at viverra lacus."
        "Pellentesque eget consectetur ex, "
        "in lobortis augue."
    };

    Message msg
    {
        from,
        to,
        msgContent
    };

    int expected{ 5 };
    int actual{};

    for (int i{}; i < expected; ++i)
    {
        EXPECT_TRUE(database->PushMessage(msg));    
    }
          
    for (; expected >= 0; --expected)
    {        
        EXPECT_TRUE(database->GetMessageCount(to, actual));
        EXPECT_EQ(actual, expected);

        if(expected > 0)
            EXPECT_TRUE(database->PopMessage(to));
    }
}

TEST(UserDBTest, getPushedMessages)
{
    std::unique_ptr<IDatabase>
        database{ std::make_unique<UserDB>() };

    std::vector<Message> msgVect
    {
        { "Agatha Christie",    "Nazim Hikmet",     "First Message" },
        { "J.R.R. Tolkien",     "Orhan Pamuk",      "Second Message" },
        { "Isaac Asimov",       "Stanislaw Lem",    "Third Message" },
        { "Stanislaw Lem",      "Isaac Asimov",     "Fourth Message" },
        { "Orhan Pamuk",        "J.R.R. Tolkien",   "Fifth Message" },
        { "Nazim Hikmet",       "Agatha Christie",  "Sixth Message" }
    };

    for (auto& actual : msgVect)
    {
        EXPECT_TRUE(database->CreateUser(actual.from));
    }

    for (auto& actual : msgVect)
    {
        EXPECT_TRUE(database->PushMessage(actual));
    }

    for (auto& actual : msgVect)
    {
        Message* expected;
        EXPECT_TRUE(database->FrontMessage(actual.to, &expected));

        EXPECT_EQ(actual.from, expected->from);
        EXPECT_EQ(actual.to, expected->to);
        EXPECT_EQ(actual.message, expected->message);
    }
}

TEST(UserDBTest, pushMessageFromNonExistingUser)
{
    std::unique_ptr<IDatabase>
        database{ std::make_unique<UserDB>() };

    std::string from{ "George R.R. Martin" };
    std::string to{ "Andrzej Sapkowski" };

    EXPECT_TRUE(database->CreateUser(to));
    EXPECT_TRUE(database->IsUserExists(to));
    EXPECT_FALSE(database->IsUserExists(from));

    std::string msgContent
    {
        "Lorem ipsum dolor sit amet, "
        "consectetur adipiscing elit."
        "Duis at viverra lacus."
        "Pellentesque eget consectetur ex, "
        "in lobortis augue."
    };

    Message msg
    {
        from,
        to,
        msgContent
    };

    EXPECT_FALSE(database->PushMessage(msg));
}

TEST(UserDBTest, pushMessageToNonExistingUser)
{
    std::unique_ptr<IDatabase>
        database{ std::make_unique<UserDB>() };

    std::string from{ "George R.R. Martin" };
    std::string to{ "Andrzej Sapkowski" };

    EXPECT_TRUE(database->CreateUser(from));
    EXPECT_TRUE(database->IsUserExists(from));
    EXPECT_FALSE(database->IsUserExists(to));

    std::string msgContent
    {
        "Lorem ipsum dolor sit amet, "
        "consectetur adipiscing elit."
        "Duis at viverra lacus."
        "Pellentesque eget consectetur ex, "
        "in lobortis augue."
    };

    Message msg
    {
        from,
        to,
        msgContent
    };

    EXPECT_FALSE(database->PushMessage(msg));
}

TEST(UserDBTest, pushMessageBetweenNonExistingUsers)
{
    std::unique_ptr<IDatabase>
        database{ std::make_unique<UserDB>() };

    std::string from{ "George R.R. Martin" };
    std::string to{ "Andrzej Sapkowski" };

    EXPECT_FALSE(database->IsUserExists(from));
    EXPECT_FALSE(database->IsUserExists(to));

    std::string msgContent
    {
        "Lorem ipsum dolor sit amet, "
        "consectetur adipiscing elit."
        "Duis at viverra lacus."
        "Pellentesque eget consectetur ex, "
        "in lobortis augue."
    };

    Message msg
    {
        from,
        to,
        msgContent
    };

    EXPECT_FALSE(database->PushMessage(msg));
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
