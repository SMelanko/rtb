#include <base/utils/StrAlgo.hpp>

#include <gtest/gtest.h>

TEST(UtilsStrAlgo, RemoveWhitespaces)
{
    EXPECT_EQ(base::StrAlgo::RemoveWhitespaces(""), "");
    base::StringView exp = "Hello,World!";
    EXPECT_EQ(base::StrAlgo::RemoveWhitespaces(" Hello, World! "), exp);
    EXPECT_EQ(base::StrAlgo::RemoveWhitespaces("\tHello,\tWorld!\t"), exp);
    EXPECT_EQ(base::StrAlgo::RemoveWhitespaces("\nHello,\nWorld!\n"), exp);
    EXPECT_EQ(base::StrAlgo::RemoveWhitespaces(" \t\nHello, \t\nWorld! \t\n"), exp);
}

TEST(UtilsStrAlgo, Split)
{
    auto result = base::StrAlgo::Split("");
    EXPECT_EQ(result.size(), 0);
    result = base::StrAlgo::Split("1,2,3");
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "1");
    EXPECT_EQ(result[1], "2");
    EXPECT_EQ(result[2], "3");
    result = base::StrAlgo::Split("red|green|blue", '|');
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "red");
    EXPECT_EQ(result[1], "green");
    EXPECT_EQ(result[2], "blue");
}
