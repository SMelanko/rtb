#include <core/stl/Vector.hpp>

#include <gtest/gtest.h>

TEST(StlVectorTest, Creation)
{
    core::Vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}
