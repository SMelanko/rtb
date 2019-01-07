#include <base/stl/Vector.hpp>

#include <gtest/gtest.h>

TEST(StlVectorTest, Creation)
{
    base::Vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}
