#include <gtest/gtest.h>

#include <optional>
#include <string>

#include <rapidjson/document.h>

#include <data/OpenRtb2Point3.hpp>
#include <core/json/Json.hpp>
#include <core/stl/String.hpp>
#include <core/stl/Vector.hpp>
#include <core/Type.hpp>
#include <proto/Parser2Point3.hpp>

TEST(BannerTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3::GetBanner();
    const auto banner = JsonWorker<Banner>::Parse(Json::Str2Json(str));
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
    const auto str = test::data::OpenRtb2Point3::GetDeal();
    const auto deal = JsonWorker<Deal>::Parse(Json::Str2Json(str));
    EXPECT_EQ(deal.id, "1452f.eadb4.7aaa");
    EXPECT_DOUBLE_EQ(deal.bidfloor, 5.3);
    EXPECT_EQ(deal.bidfloorcur, "USD");
    EXPECT_EQ(deal.at, AuctionPrice::FIRST_PRICE);
    EXPECT_EQ(deal.wseat.size(), 0);
    EXPECT_EQ(deal.wadomain.size(), 0);
}

TEST(PmpTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3::GetPmp();
    const auto pmp = JsonWorker<Pmp>::Parse(Json::Str2Json(str));
    EXPECT_EQ(pmp.private_auction, 1);
    EXPECT_EQ(pmp.deals.size(), 1);
    EXPECT_EQ(pmp.deals[0].id, "DX-1985-010A");
    EXPECT_DOUBLE_EQ(pmp.deals[0].bidfloor, 2.5);
    EXPECT_EQ(pmp.deals[0].bidfloorcur, "USD");
    EXPECT_EQ(pmp.deals[0].at, AuctionPrice::SECOND_PRICE_PLUS);
}

TEST(ImpressionTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3::GetImpression();
    const auto imp = JsonWorker<Impression>::Parse(Json::Str2Json(str));
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

TEST(BidRequestTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3::GetBidRequestBrandscreen();
    const auto br = JsonWorker<BidRequest>::Parse(Json::Str2Json(str));
    EXPECT_EQ(br.id, "IxexyLDIIk");
    EXPECT_EQ(br.imp.size(), 1);
    auto& imp = br.imp[0];
    EXPECT_EQ(imp.id, "1");
    EXPECT_EQ(imp.instl, 0);
    EXPECT_EQ(imp.tagid, "agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw");
    EXPECT_DOUBLE_EQ(imp.bidfloor, 0.5);
    EXPECT_TRUE(imp.banner.has_value());
    auto& banner = *imp.banner;
    EXPECT_EQ(banner.w.size(), 1);
    EXPECT_EQ(banner.w[0], 728);
    EXPECT_EQ(banner.h.size(), 1);
    EXPECT_EQ(banner.h[0], 90);
    EXPECT_EQ(banner.pos, AdPosition::ABOVE);
    EXPECT_EQ(banner.btype.size(), 1);
    EXPECT_EQ(banner.btype[0], BannerAdType::IFRAME);
    EXPECT_EQ(banner.battr.size(), 1);
    EXPECT_EQ(banner.battr[0], CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    EXPECT_EQ(banner.api.size(), 1);
    EXPECT_EQ(banner.api[0], ApiFramework::MRAID);
    EXPECT_EQ(br.at, AuctionPrice::SECOND_PRICE_PLUS);
    EXPECT_FALSE(br.test);
    EXPECT_FALSE(br.allimps);
    EXPECT_EQ(br.bcat.size(), 5);
    EXPECT_EQ(br.bcat[0], "IAB25");
    EXPECT_EQ(br.bcat[1], "IAB7-39");
    EXPECT_EQ(br.bcat[2], "IAB8-18");
    EXPECT_EQ(br.bcat[3], "IAB8-5");
    EXPECT_EQ(br.bcat[4], "IAB9-9");
    EXPECT_EQ(br.badv.size(), 3);
    EXPECT_EQ(br.badv[0], "apple.com");
    EXPECT_EQ(br.badv[1], "go-text.me");
    EXPECT_EQ(br.badv[2], "heywire.com");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
