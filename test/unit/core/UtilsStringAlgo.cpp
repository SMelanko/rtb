#include <gtest/gtest.h>

#include <core/utils/StringAlgo.hpp>

TEST(UtilsStringAlgoTest, RemoveWhitespace)
{
    EXPECT_EQ(Core::Utils::StringAlgo::RemoveWhitespace(""), "");
    EXPECT_EQ(Core::Utils::StringAlgo::RemoveWhitespace(" Hello, World! "), "Hello,World!");
    EXPECT_EQ(Core::Utils::StringAlgo::RemoveWhitespace("\tHello,\tWorld!\t"), "Hello,World!");
    EXPECT_EQ(Core::Utils::StringAlgo::RemoveWhitespace("\nHello,\nWorld!\n"), "Hello,World!");
    EXPECT_EQ(Core::Utils::StringAlgo::RemoveWhitespace(" \t\nHello, \t\nWorld! \t\n"), "Hello,World!");
}
