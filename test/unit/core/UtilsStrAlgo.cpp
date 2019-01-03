#include <core/utils/StrAlgo.hpp>

#include <gtest/gtest.h>

TEST(UtilsStrAlgo, RemoveWhitespaces)
{
    EXPECT_EQ(core::StrAlgo::RemoveWhitespaces(""), "");
    core::StringView exp = "Hello,World!";
    EXPECT_EQ(core::StrAlgo::RemoveWhitespaces(" Hello, World! "), exp);
    EXPECT_EQ(core::StrAlgo::RemoveWhitespaces("\tHello,\tWorld!\t"), exp);
    EXPECT_EQ(core::StrAlgo::RemoveWhitespaces("\nHello,\nWorld!\n"), exp);
    EXPECT_EQ(core::StrAlgo::RemoveWhitespaces(" \t\nHello, \t\nWorld! \t\n"), exp);
}

TEST(UtilsStrAlgo, Split)
{
    auto result = core::StrAlgo::Split("");
    EXPECT_EQ(result.size(), 0);
    result = core::StrAlgo::Split("1,2,3");
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "1");
    EXPECT_EQ(result[1], "2");
    EXPECT_EQ(result[2], "3");
    result = core::StrAlgo::Split("red|green|blue", '|');
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "red");
    EXPECT_EQ(result[1], "green");
    EXPECT_EQ(result[2], "blue");
}
