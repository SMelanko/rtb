#include <gtest/gtest.h>

#include <proto/Parser2Point3.hpp>

Core::Json Str2Json(const Core::String& str)
{
    Core::Json j;
    j.Parse(str.c_str(), str.length());
    return j;
}

TEST(BannerTest, Parse) {
    const Core::String str = R"({"h":250,"w":300,"pos":0})";
    JsonWorker<Banner> w;
    auto banner = w.Parse(Str2Json(str));
    EXPECT_EQ(banner.w.size(), 1);
    EXPECT_EQ(banner.w[0], 300);
    EXPECT_EQ(banner.h.size(), 1);
    EXPECT_EQ(banner.h[0], 250);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
