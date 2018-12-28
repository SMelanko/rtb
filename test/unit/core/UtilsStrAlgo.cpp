#include <core/utils/StrAlgo.hpp>

#include <gtest/gtest.h>

TEST(UtilsStringAlgoTest, RemoveWhitespace)
{
    EXPECT_EQ(core::StrAlgo::RemoveWhitespace(""), "");
    core::StringView exp = "Hello,World!";
    EXPECT_EQ(core::StrAlgo::RemoveWhitespace(" Hello, World! "), exp);
    EXPECT_EQ(core::StrAlgo::RemoveWhitespace("\tHello,\tWorld!\t"), exp);
    EXPECT_EQ(core::StrAlgo::RemoveWhitespace("\nHello,\nWorld!\n"), exp);
    EXPECT_EQ(core::StrAlgo::RemoveWhitespace(" \t\nHello, \t\nWorld! \t\n"), exp);
}
