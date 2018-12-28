#include <data/OpenRtb2Point3Sample.hpp>
#include <core/json/Json.hpp>
#include <core/stl/String.hpp>
#include <core/stl/Vector.hpp>
#include <core/Type.hpp>
#include <proto/Parser2Point3.hpp>

#include <gtest/gtest.h>

TEST(BannerTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3Sample::GetBanner();
    const auto banner = proto::JsonWorker<proto::Banner>::Parse(json::Str2Json(str));
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

TEST(VideoTest, Parse) {
    const auto str = test::data::OpenRtb2Point3Sample::GetVideo();
    const auto v = proto::JsonWorker<proto::Video>::Parse(json::Str2Json(str));
    EXPECT_EQ(v.w, 640);
    EXPECT_EQ(v.h, 480);
    EXPECT_EQ(v.pos, AdPosition::ABOVE);
    EXPECT_EQ(v.startdelay, VideoStartDelay::PRE_ROLL);
    EXPECT_EQ(v.minduration, 5);
    EXPECT_EQ(v.maxduration, 30);
    EXPECT_EQ(v.maxextended, 30);
    EXPECT_EQ(v.minbitrate, 300);
    EXPECT_EQ(v.maxbitrate, 1500);
    EXPECT_EQ(v.api.size(), 2);
    EXPECT_EQ(v.api[0], ApiFramework::VPAID_1);
    EXPECT_EQ(v.api[1], ApiFramework::VPAID_2);
    EXPECT_EQ(v.protocols.size(), 2);
    EXPECT_EQ(v.protocols[0], VideoBidResponseProtocol::VAST2);
    EXPECT_EQ(v.protocols[1], VideoBidResponseProtocol::VAST3);
    EXPECT_EQ(v.mimes.size(), 4);
    EXPECT_EQ(v.mimes[0].type, "video/x-flv");
    EXPECT_EQ(v.mimes[1].type, "video/mp4");
    EXPECT_EQ(v.mimes[2].type, "application/x-shockwave-flash");
    EXPECT_EQ(v.mimes[3].type, "application/javascript");
    EXPECT_EQ(v.linearity, VideoLinearity::IN_STREAM);
    EXPECT_TRUE(v.boxingallowed);
    EXPECT_EQ(v.playbackmethod.size(), 2);
    EXPECT_EQ(v.playbackmethod[0], VideoPlaybackMethod::AUTO_PLAY_SOUND_ON);
    EXPECT_EQ(v.playbackmethod[1], VideoPlaybackMethod::CLICK_TO_PLAY);
    EXPECT_EQ(v.delivery.size(), 1);
    EXPECT_EQ(v.delivery[0], ContentDeliveryMethod::PROGRESSIVE);
    EXPECT_EQ(v.battr.size(), 2);
    EXPECT_EQ(v.battr[0], CreativeAttribute::USER_INTERACTIVE);
    EXPECT_EQ(v.battr[1], CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    EXPECT_EQ(v.companionad.size(), 2);
    {
        EXPECT_EQ(v.companionad[0].id, "1234567893-1");
        EXPECT_EQ(v.companionad[0].w[0], 300);
        EXPECT_EQ(v.companionad[0].h[0], 250);
        EXPECT_EQ(v.companionad[0].pos, AdPosition::ABOVE);
        EXPECT_EQ(v.companionad[0].battr.size(), 2);
        EXPECT_EQ(v.companionad[0].battr[0], CreativeAttribute::USER_INTERACTIVE);
        EXPECT_EQ(v.companionad[0].battr[1], CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
        EXPECT_EQ(v.companionad[0].expdir.size(), 2);
        EXPECT_EQ(v.companionad[0].expdir[0], ExpandableDirection::RIGHT);
        EXPECT_EQ(v.companionad[0].expdir[1], ExpandableDirection::DOWN);
    }
    {
        EXPECT_EQ(v.companionad[1].id, "1234567893-2");
        EXPECT_EQ(v.companionad[1].w[0], 728);
        EXPECT_EQ(v.companionad[1].h[0], 90);
        EXPECT_EQ(v.companionad[1].pos, AdPosition::ABOVE);
        EXPECT_EQ(v.companionad[1].battr.size(), 2);
        EXPECT_EQ(v.companionad[1].battr[0], CreativeAttribute::USER_INTERACTIVE);
        EXPECT_EQ(v.companionad[1].battr[1], CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    }
    EXPECT_EQ(v.companiontype.size(), 2);
    EXPECT_EQ(v.companiontype[0], VastCompanionType::STATIC_RESOURCE);
    EXPECT_EQ(v.companiontype[1], VastCompanionType::HTML_RESOURCE);
}

TEST(NativeTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3Sample::GetNative();
    const auto n = proto::JsonWorker<proto::Native>::Parse(json::Str2Json(str));
    EXPECT_EQ(n.request, "...Native_spec_request_as_an_encoded_string...");
    EXPECT_EQ(n.ver, "1.0");
    EXPECT_EQ(n.api.size(), 1);
    EXPECT_EQ(n.api[0], ApiFramework::MRAID);
    EXPECT_EQ(n.battr.size(), 2);
    EXPECT_EQ(n.battr[0], CreativeAttribute::USER_INTERACTIVE);
    EXPECT_EQ(n.battr[1], CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
}

TEST(AppTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3Sample::GetApp();
    const auto app = proto::JsonWorker<proto::App>::Parse(json::Str2Json(str));
    EXPECT_EQ(app.id, "agltb3B1Yi1pbmNyDAsSA0FwcBiJkfIUDA");
    EXPECT_EQ(app.name, "Yahoo_Weather");
    EXPECT_EQ(app.cat.size(), 3);
    EXPECT_EQ(app.cat[0], "weather"); // Wrong IAB.
    EXPECT_EQ(app.cat[1], "IAB15");
    EXPECT_EQ(app.cat[2], "IAB15-10");
    EXPECT_EQ(app.ver, "1.0.2");
    EXPECT_EQ(app.bundle, "628677149");
    {
        EXPECT_TRUE(app.publisher.has_value());
        auto& p = *app.publisher;
        EXPECT_EQ(p.id, "agltb3B1Yi1pbmNyDAsSA0FwcBiJkfTUCV");
        EXPECT_EQ(p.name, "yahoo");
        EXPECT_EQ(p.domain, "www.yahoo.com");
    }
    EXPECT_EQ(app.storeurl, "https://itunes.apple.com/id628677149");
}

TEST(SiteTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3Sample::GetSite();
    const auto s = proto::JsonWorker<proto::Site>::Parse(json::Str2Json(str));
    EXPECT_EQ(s.id, "1345135123");
    EXPECT_EQ(s.name, "Site_ABCD");
    EXPECT_EQ(s.domain, "siteabcd.com");
    EXPECT_EQ(s.cat.size(), 2);
    EXPECT_EQ(s.cat[0], "IAB2-1");
    EXPECT_EQ(s.cat[1], "IAB2-2");
    EXPECT_EQ(s.page, "http://siteabcd.com/page.htm");
    EXPECT_EQ(s.ref, "http://referringsite.com/referringpage.htm");
    EXPECT_TRUE(s.privacypolicy);
    {
        EXPECT_TRUE(s.publisher.has_value());
        auto& p = *s.publisher;
        EXPECT_EQ(p.id, "pub12345");
        EXPECT_EQ(p.name, "Publisher_A");
    }
    {
        EXPECT_TRUE(s.content.has_value());
        auto& c = *s.content;
        EXPECT_EQ(c.cat.size(), 1);
        EXPECT_EQ(c.cat[0], "IAB2-2");
        EXPECT_EQ(c.episode, 23);
        EXPECT_EQ(c.id, "1234567");
        EXPECT_EQ(c.keywords.size(), 3);
        EXPECT_EQ(c.keywords[0], "keyword_a");
        EXPECT_EQ(c.keywords[1], "keyword_b");
        EXPECT_EQ(c.keywords[2], "keyword_c");
        EXPECT_EQ(c.season, "2");
        EXPECT_EQ(c.series, "All_About_Cars");
        EXPECT_EQ(c.title, "Car_Show");
    }
}

TEST(DealTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3Sample::GetDeal();
    const auto deal = proto::JsonWorker<proto::Deal>::Parse(json::Str2Json(str));
    EXPECT_EQ(deal.id, "1452f.eadb4.7aaa");
    EXPECT_DOUBLE_EQ(deal.bidfloor, 5.3);
    EXPECT_EQ(deal.bidfloorcur, "USD");
    EXPECT_EQ(deal.at, AuctionPrice::FIRST_PRICE);
    EXPECT_EQ(deal.wseat.size(), 0);
    EXPECT_EQ(deal.wadomain.size(), 0);
}

TEST(PmpTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3Sample::GetPmp();
    const auto pmp = proto::JsonWorker<proto::Pmp>::Parse(json::Str2Json(str));
    EXPECT_EQ(pmp.private_auction, 1);
    EXPECT_EQ(pmp.deals.size(), 1);
    EXPECT_EQ(pmp.deals[0].id, "DX-1985-010A");
    EXPECT_DOUBLE_EQ(pmp.deals[0].bidfloor, 2.5);
    EXPECT_EQ(pmp.deals[0].bidfloorcur, "USD");
    EXPECT_EQ(pmp.deals[0].at, AuctionPrice::SECOND_PRICE_PLUS);
}

TEST(ImpressionTest, Parse)
{
    const auto str = test::data::OpenRtb2Point3Sample::GetImpression();
    const auto imp = proto::JsonWorker<proto::Impression>::Parse(json::Str2Json(str));
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
    const auto str = test::data::OpenRtb2Point3Sample::GetBrandscreenBidRequest();
    const auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    EXPECT_EQ(br.id, "IxexyLDIIk");
    {
        EXPECT_EQ(br.imp.size(), 1);
        auto& imp = br.imp[0];
        EXPECT_EQ(imp.id, "1");
        EXPECT_EQ(imp.instl, 0);
        EXPECT_EQ(imp.tagid, "agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw");
        EXPECT_DOUBLE_EQ(imp.bidfloor, 0.5);
        {
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
        }
    }
    {
        EXPECT_TRUE(br.app.has_value());
        auto& app = *br.app;
        EXPECT_EQ(app.id, "agltb3B1Yi1pbmNyDAsSA0FwcBiJkfIUDA");
        EXPECT_EQ(app.name, "Yahoo_Weather");
        EXPECT_EQ(app.cat.size(), 3);
        EXPECT_EQ(app.cat[0], "weather"); // Wrong IAB.
        EXPECT_EQ(app.cat[1], "IAB15");
        EXPECT_EQ(app.cat[2], "IAB15-10");
        EXPECT_EQ(app.ver, "1.0.2");
        EXPECT_EQ(app.bundle, "628677149");
        {
            EXPECT_TRUE(app.publisher.has_value());
            auto& pub = *app.publisher;
            EXPECT_EQ(pub.id, "agltb3B1Yi1pbmNyDAsSA0FwcBiJkfTUCV");
            EXPECT_EQ(pub.name, "yahoo");
            EXPECT_EQ(pub.domain, "www.yahoo.com");
        }
        EXPECT_EQ(app.storeurl, "https://itunes.apple.com/id628677149");
    }
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
