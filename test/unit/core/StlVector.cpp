#include <gtest/gtest.h>

#include <core/stl/Vector.hpp>

TEST(StlVectorTest, Creation) {
    Core::Vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
