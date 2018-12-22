#include <gtest/gtest.h>

#include <optional>
#include <string>

#include <rapidjson/document.h>

#include <core/json/Json.hpp>
#include <core/stl/String.hpp>
#include <core/stl/Vector.hpp>
#include <core/Type.hpp>
#include <proto/Parser2Point3.hpp>

auto Str2Json(const Core::String& str)
{
    Json::Document j;
    j.Parse(str.c_str(), str.length());
    return j;
}

TEST(BannerTest, Parse)
{
    const Core::String str = R"({
        "h":250,"w":300,
        "wmax":640,"hmax":320,
        "wmin":240,"hmin":200,
        "id":"p7mwtup3aep7c0io",
        "pos":0,"topframe":0,
        "btype":[4],"battr":[14],
        "mimes":["image/jpg","image/png"],
        "expdir":[2,4],"api":[3]
    })";
    auto banner = JsonWorker<Banner>::Parse(Str2Json(str));
    EXPECT_EQ(banner.w.size(), 1);
    EXPECT_EQ(banner.w[0], 300);
    EXPECT_EQ(banner.h.size(), 1);
    EXPECT_EQ(banner.h[0], 250);
    EXPECT_EQ(banner.wmax, 640);
    EXPECT_EQ(banner.hmax, 320);
    EXPECT_EQ(banner.wmin, 240);
    EXPECT_EQ(banner.hmin, 200);
    EXPECT_EQ(banner.id, "p7mwtup3aep7c0io");
    EXPECT_EQ(banner.pos, AdPosition::UNKNOWN);
    EXPECT_EQ(banner.btype.size(), 1);
    EXPECT_EQ(banner.btype[0], BannerAdType::IFRAME);
    EXPECT_EQ(banner.battr.size(), 1);
    EXPECT_EQ(banner.battr[0], CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    EXPECT_EQ(banner.mimes.size(), 2);
    EXPECT_EQ(banner.mimes[0].type, "image/jpg");
    EXPECT_EQ(banner.mimes[1].type, "image/png");
    EXPECT_EQ(banner.topframe, FramePosition::IFRAME);
    EXPECT_EQ(banner.expdir.size(), 2);
    EXPECT_EQ(banner.expdir[0], ExpandableDirection::RIGHT);
    EXPECT_EQ(banner.expdir[1], ExpandableDirection::DOWN);
    EXPECT_EQ(banner.api.size(), 1);
    EXPECT_EQ(banner.api[0], ApiFramework::MRAID);
}

TEST(DealTest, Parse)
{
    const Core::String str = R"({
        "id":"1452f.eadb4.7aaa","bidfloor":5.3,"at":1,"wseats":[],
        "ext":{"priority":1,"wadvs":[]}
    })";
    auto deal = JsonWorker<Deal>::Parse(Str2Json(str));
    EXPECT_EQ(deal.id, "1452f.eadb4.7aaa");
    EXPECT_DOUBLE_EQ(deal.bidfloor, 5.3);
    EXPECT_EQ(deal.bidfloorcur, "USD"); // Default value.
    EXPECT_EQ(deal.at, AuctionPrice::FIRST_PRICE);
    EXPECT_EQ(deal.wseat.size(), 0);
    EXPECT_EQ(deal.wadomain.size(), 0);
}

TEST(PmpTest, Parse)
{
    const Core::String str = R"({
        "private_auction": 1,
        "deals": [{"id": "DX-1985-010A","bidfloor": 2.5,"at": 2}]
    })";
    auto pmp = JsonWorker<Pmp>::Parse(Str2Json(str));
    EXPECT_EQ(pmp.private_auction, 1);
    EXPECT_EQ(pmp.deals.size(), 1);
    EXPECT_EQ(pmp.deals[0].id, "DX-1985-010A");
    EXPECT_DOUBLE_EQ(pmp.deals[0].bidfloor, 2.5);
    EXPECT_EQ(pmp.deals[0].bidfloorcur, "USD"); // Default value.
    EXPECT_EQ(pmp.deals[0].at, AuctionPrice::SECOND_PRICE_PLUS);
}

TEST(ImpressionTest, Parse)
{
    const Core::String str = R"({
        "id":"1",
        "banner":{"w":728,"h":90,"pos":1,"btype":[4],"battr":[14],"api":[3]},
        "instl":0,"tagid":"agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw","bidfloor":0.5
    })";
    auto imp = JsonWorker<Impression>::Parse(Str2Json(str));
    EXPECT_EQ(imp.id, "1");
    EXPECT_TRUE(imp.banner.has_value());
    EXPECT_EQ(imp.banner->w.size(), 1);
    EXPECT_EQ(imp.banner->w[0], 728);
    EXPECT_EQ(imp.banner->h.size(), 1);
    EXPECT_EQ(imp.banner->h[0], 90);
    EXPECT_EQ(imp.banner->pos, AdPosition::ABOVE);
    EXPECT_EQ(imp.banner->btype.size(), 1);
    EXPECT_EQ(imp.banner->btype[0], BannerAdType::IFRAME);
    EXPECT_EQ(imp.banner->battr.size(), 1);
    EXPECT_EQ(imp.banner->battr[0], CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    EXPECT_EQ(imp.banner->api.size(), 1);
    EXPECT_EQ(imp.banner->api[0], ApiFramework::MRAID);
    EXPECT_EQ(imp.instl, 0);
    EXPECT_EQ(imp.tagid, "agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw");
    EXPECT_DOUBLE_EQ(imp.bidfloor, 0.5);
    EXPECT_EQ(imp.bidfloorcur, "USD");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
