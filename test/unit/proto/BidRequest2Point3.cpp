#include <core/json/Json.hpp>
#include <core/stl/String.hpp>
#include <core/stl/Vector.hpp>
#include <core/Type.hpp>
#include <proto/Parser2Point3.hpp>
#include <test/data/BidRequest2Point3.hpp>

#include <gtest/gtest.h>

namespace detail
{

using SampleMock = test::data::OpenRtb2Point3Sample;
using SpecMock = test::data::OpenRtb2Point3Spec;

template<class T>
[[nodiscard]] constexpr T PrepareUnit(const core::String& str)
{
    return proto::JsonWorker<T>::Parse(json::Str2Json(str));
}

}

TEST(BannerTest, Parse)
{
    const auto banner = detail::PrepareUnit<proto::Banner>(detail::SampleMock::GetBanner());
    EXPECT_EQ(banner.w.size(), 1);
    EXPECT_EQ(banner.w[0], 300);
    EXPECT_EQ(banner.h.size(), 1);
    EXPECT_EQ(banner.h[0], 250);
    EXPECT_EQ(banner.wmax, 640);
    EXPECT_EQ(banner.hmax, 320);
    EXPECT_EQ(banner.wmin, 240);
    EXPECT_EQ(banner.hmin, 200);
    EXPECT_EQ(banner.id, "p7mwtup3aep7c0io");
    EXPECT_EQ(banner.pos, proto::AdPosition::UNKNOWN);
    EXPECT_EQ(banner.btype.size(), 1);
    EXPECT_EQ(banner.btype[0], proto::BannerAdType::IFRAME);
    EXPECT_EQ(banner.battr.size(), 1);
    EXPECT_EQ(banner.battr[0], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    EXPECT_EQ(banner.mimes.size(), 2);
    EXPECT_EQ(banner.mimes[0].type, "image/jpg");
    EXPECT_EQ(banner.mimes[1].type, "image/png");
    EXPECT_EQ(banner.topframe, proto::FramePosition::IFRAME);
    EXPECT_EQ(banner.expdir.size(), 2);
    EXPECT_EQ(banner.expdir[0], proto::ExpandableDirection::RIGHT);
    EXPECT_EQ(banner.expdir[1], proto::ExpandableDirection::DOWN);
    EXPECT_EQ(banner.api.size(), 1);
    EXPECT_EQ(banner.api[0], proto::ApiFramework::MRAID);
}

TEST(VideoTest, Parse)
{
    const auto video = detail::PrepareUnit<proto::Video>(detail::SampleMock::GetVideo());
    EXPECT_EQ(video.w, 640);
    EXPECT_EQ(video.h, 480);
    EXPECT_EQ(video.pos, proto::AdPosition::ABOVE);
    EXPECT_EQ(video.startdelay, proto::VideoStartDelay::PRE_ROLL);
    EXPECT_EQ(video.minduration, 5);
    EXPECT_EQ(video.maxduration, 30);
    EXPECT_EQ(video.maxextended, 30);
    EXPECT_EQ(video.minbitrate, 300);
    EXPECT_EQ(video.maxbitrate, 1500);
    EXPECT_EQ(video.api.size(), 2);
    EXPECT_EQ(video.api[0], proto::ApiFramework::VPAID_1);
    EXPECT_EQ(video.api[1], proto::ApiFramework::VPAID_2);
    EXPECT_EQ(video.protocols.size(), 2);
    EXPECT_EQ(video.protocols[0], proto::VideoBidResponseProtocol::VAST2);
    EXPECT_EQ(video.protocols[1], proto::VideoBidResponseProtocol::VAST3);
    EXPECT_EQ(video.mimes.size(), 4);
    EXPECT_EQ(video.mimes[0].type, "video/x-flv");
    EXPECT_EQ(video.mimes[1].type, "video/mp4");
    EXPECT_EQ(video.mimes[2].type, "application/x-shockwave-flash");
    EXPECT_EQ(video.mimes[3].type, "application/javascript");
    EXPECT_EQ(video.linearity, proto::VideoLinearity::IN_STREAM);
    EXPECT_TRUE(video.boxingallowed);
    EXPECT_EQ(video.playbackmethod.size(), 2);
    EXPECT_EQ(video.playbackmethod[0], proto::VideoPlaybackMethod::AUTO_PLAY_SOUND_ON);
    EXPECT_EQ(video.playbackmethod[1], proto::VideoPlaybackMethod::CLICK_TO_PLAY);
    EXPECT_EQ(video.delivery.size(), 1);
    EXPECT_EQ(video.delivery[0], proto::ContentDeliveryMethod::PROGRESSIVE);
    EXPECT_EQ(video.battr.size(), 2);
    EXPECT_EQ(video.battr[0], proto::CreativeAttribute::USER_INTERACTIVE);
    EXPECT_EQ(video.battr[1], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    EXPECT_EQ(video.companionad.size(), 2);
    {
        EXPECT_EQ(video.companionad[0].id, "1234567893-1");
        EXPECT_EQ(video.companionad[0].w[0], 300);
        EXPECT_EQ(video.companionad[0].h[0], 250);
        EXPECT_EQ(video.companionad[0].pos, proto::AdPosition::ABOVE);
        EXPECT_EQ(video.companionad[0].battr.size(), 2);
        EXPECT_EQ(video.companionad[0].battr[0], proto::CreativeAttribute::USER_INTERACTIVE);
        EXPECT_EQ(video.companionad[0].battr[1], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
        EXPECT_EQ(video.companionad[0].expdir.size(), 2);
        EXPECT_EQ(video.companionad[0].expdir[0], proto::ExpandableDirection::RIGHT);
        EXPECT_EQ(video.companionad[0].expdir[1], proto::ExpandableDirection::DOWN);
    }
    {
        EXPECT_EQ(video.companionad[1].id, "1234567893-2");
        EXPECT_EQ(video.companionad[1].w[0], 728);
        EXPECT_EQ(video.companionad[1].h[0], 90);
        EXPECT_EQ(video.companionad[1].pos, proto::AdPosition::ABOVE);
        EXPECT_EQ(video.companionad[1].battr.size(), 2);
        EXPECT_EQ(video.companionad[1].battr[0], proto::CreativeAttribute::USER_INTERACTIVE);
        EXPECT_EQ(video.companionad[1].battr[1], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    }
    EXPECT_EQ(video.companiontype.size(), 2);
    EXPECT_EQ(video.companiontype[0], proto::VastCompanionType::STATIC_RESOURCE);
    EXPECT_EQ(video.companiontype[1], proto::VastCompanionType::HTML_RESOURCE);
}

TEST(NativeTest, Parse)
{
    const auto native = detail::PrepareUnit<proto::Native>(detail::SampleMock::GetNative());
    EXPECT_EQ(native.request, "...Native_spec_request_as_an_encoded_string...");
    EXPECT_EQ(native.ver, "1.0");
    EXPECT_EQ(native.api.size(), 1);
    EXPECT_EQ(native.api[0], proto::ApiFramework::MRAID);
    EXPECT_EQ(native.battr.size(), 2);
    EXPECT_EQ(native.battr[0], proto::CreativeAttribute::USER_INTERACTIVE);
    EXPECT_EQ(native.battr[1], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
}

TEST(AppTest, Parse)
{
    const auto app = detail::PrepareUnit<proto::App>(detail::SampleMock::GetApp());
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
        const auto& pub = *app.publisher;
        EXPECT_EQ(pub.id, "agltb3B1Yi1pbmNyDAsSA0FwcBiJkfTUCV");
        EXPECT_EQ(pub.name, "yahoo");
        EXPECT_EQ(pub.domain, "www.yahoo.com");
    }
    EXPECT_EQ(app.storeurl, "https://itunes.apple.com/id628677149");
}

TEST(SiteTest, Parse)
{
    const auto site = detail::PrepareUnit<proto::Site>(detail::SampleMock::GetSite());
    EXPECT_EQ(site.id, "1345135123");
    EXPECT_EQ(site.name, "Site_ABCD");
    EXPECT_EQ(site.domain, "siteabcd.com");
    EXPECT_EQ(site.cat.size(), 2);
    EXPECT_EQ(site.cat[0], "IAB2-1");
    EXPECT_EQ(site.cat[1], "IAB2-2");
    EXPECT_EQ(site.page, "http://siteabcd.com/page.htm");
    EXPECT_EQ(site.ref, "http://referringsite.com/referringpage.htm");
    EXPECT_TRUE(site.privacypolicy);
    {
        EXPECT_TRUE(site.publisher.has_value());
        const auto& pub = *site.publisher;
        EXPECT_EQ(pub.id, "pub12345");
        EXPECT_EQ(pub.name, "Publisher_A");
    }
    {
        EXPECT_TRUE(site.content.has_value());
        const auto& content = *site.content;
        EXPECT_EQ(content.cat.size(), 1);
        EXPECT_EQ(content.cat[0], "IAB2-2");
        EXPECT_EQ(content.episode, 23);
        EXPECT_EQ(content.id, "1234567");
        EXPECT_EQ(content.keywords.size(), 3);
        EXPECT_EQ(content.keywords[0], "keyword_a");
        EXPECT_EQ(content.keywords[1], "keyword_b");
        EXPECT_EQ(content.keywords[2], "keyword_c");
        EXPECT_EQ(content.season, "2");
        EXPECT_EQ(content.series, "All_About_Cars");
        EXPECT_EQ(content.title, "Car_Show");
    }
}

TEST(GeoTest, Parse)
{
    const auto geo = detail::PrepareUnit<proto::Geo>(detail::SampleMock::GetGeo());
    EXPECT_EQ(geo.country, "USA");
    EXPECT_DOUBLE_EQ(geo.lat, 35.012345);
    EXPECT_DOUBLE_EQ(geo.lon, -115.12345);
    EXPECT_EQ(geo.city, "Los Angeles");
    EXPECT_EQ(geo.metro, "803");
    EXPECT_EQ(geo.region, "CA");
    EXPECT_EQ(geo.zip, "90049");
}

TEST(DeviceTest, Parse)
{
    const auto device = detail::PrepareUnit<proto::Device>(detail::SampleMock::GetDevice());
    EXPECT_FALSE(device.dnt);
    EXPECT_EQ(device.ip, "64.124.253.1");
    EXPECT_EQ(device.ua, "Mozilla/5.0 (Mac; U; Intel Mac OS X 10.6; en-US; rv:1.9.2.16) Gecko/20140420 Firefox/3.6.16");
    EXPECT_EQ(device.flashver, "10.1");
    {
        EXPECT_TRUE(device.geo.has_value());
        const auto& geo = *device.geo;
        EXPECT_EQ(geo.country, "USA");
        EXPECT_DOUBLE_EQ(geo.lat, 35.012345);
        EXPECT_DOUBLE_EQ(geo.lon, -115.12345);
        EXPECT_EQ(geo.city, "Los Angeles");
        EXPECT_EQ(geo.metro, "803");
        EXPECT_EQ(geo.region, "CA");
        EXPECT_EQ(geo.zip, "90049");
    }
    EXPECT_EQ(device.dpidsha1, "AA000DFE74168477C70D291f574D344790E0BB11");
    EXPECT_EQ(device.dpidmd5, "AA003EABFB29E6F759F3BDAB34E50BB11");
    EXPECT_EQ(device.carrier, "310-410");
    EXPECT_EQ(device.language, "en");
    EXPECT_EQ(device.make, "Apple");
    EXPECT_EQ(device.model, "iPhone");
    EXPECT_EQ(device.os, "iOS");
    EXPECT_EQ(device.osv, "6.1");
    EXPECT_TRUE(device.js);
    EXPECT_EQ(device.connectiontype, proto::ConnectionType::CELLULAR_UNKNOWN);
    EXPECT_EQ(device.devicetype, proto::DeviceType::MOBILE_OR_TABLET);
}

TEST(UserTest, Parse)
{
    const auto user = detail::PrepareUnit<proto::User>(detail::SampleMock::GetUser());
    EXPECT_EQ(user.id, "456789876567897654678987656789");
    EXPECT_EQ(user.buyerid, "545678765467876567898765678987654");
    {
        EXPECT_EQ(user.data.size(), 1);
        const auto& data = user.data[0];
        EXPECT_EQ(data.id, "6");
        EXPECT_EQ(data.name, "Data_Provider_1");
        {
            EXPECT_EQ(data.segment.size(), 2);
            const auto& seg0 = data.segment[0];
            EXPECT_EQ(seg0.id, "12341318394918");
            EXPECT_EQ(seg0.name, "auto_intenders");
            const auto& seg1 = data.segment[1];
            EXPECT_EQ(seg1.id, "1234131839491234");
            EXPECT_EQ(seg1.name, "auto_enthusiasts");
        }
    }
}

TEST(DealTest, Parse)
{
    const auto deal = detail::PrepareUnit<proto::Deal>(detail::SampleMock::GetDeal());
    EXPECT_EQ(deal.id, "1452f.eadb4.7aaa");
    EXPECT_DOUBLE_EQ(deal.bidfloor, 5.3);
    EXPECT_EQ(deal.bidfloorcur, "USD");
    EXPECT_EQ(deal.at, proto::AuctionPrice::FIRST_PRICE);
    EXPECT_EQ(deal.wseat.size(), 0);
    EXPECT_EQ(deal.wadomain.size(), 0);
}

TEST(PmpTest, Parse)
{
    const auto pmp = detail::PrepareUnit<proto::Pmp>(detail::SampleMock::GetPmp());
    EXPECT_TRUE(pmp.private_auction);
    EXPECT_EQ(pmp.deals.size(), 1);
    EXPECT_EQ(pmp.deals[0].id, "DX-1985-010A");
    EXPECT_DOUBLE_EQ(pmp.deals[0].bidfloor, 2.5);
    EXPECT_EQ(pmp.deals[0].bidfloorcur, "USD");
    EXPECT_EQ(pmp.deals[0].at, proto::AuctionPrice::SECOND_PRICE_PLUS);
}

TEST(ImpressionTest, Parse)
{
    const auto imp = detail::PrepareUnit<proto::Impression>(detail::SampleMock::GetImpression());
    EXPECT_EQ(imp.id, "1");
    EXPECT_TRUE(imp.banner.has_value());
    EXPECT_EQ(imp.banner->w.size(), 1);
    EXPECT_EQ(imp.banner->w[0], 728);
    EXPECT_EQ(imp.banner->h.size(), 1);
    EXPECT_EQ(imp.banner->h[0], 90);
    EXPECT_EQ(imp.banner->pos, proto::AdPosition::ABOVE);
    EXPECT_EQ(imp.banner->btype.size(), 1);
    EXPECT_EQ(imp.banner->btype[0], proto::BannerAdType::IFRAME);
    EXPECT_EQ(imp.banner->battr.size(), 1);
    EXPECT_EQ(imp.banner->battr[0], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
    EXPECT_EQ(imp.banner->api.size(), 1);
    EXPECT_EQ(imp.banner->api[0], proto::ApiFramework::MRAID);
    EXPECT_FALSE(imp.instl);
    EXPECT_EQ(imp.tagid, "agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw");
    EXPECT_DOUBLE_EQ(imp.bidfloor, 0.5);
    EXPECT_EQ(imp.bidfloorcur, "USD");
}

TEST(BidRequestTest, Parse)
{
    const auto br = detail::PrepareUnit<proto::BidRequest>(detail::SampleMock::GetBrandscreenBidRequest());
    EXPECT_EQ(br.id, "IxexyLDIIk");
    {
        EXPECT_EQ(br.imp.size(), 1);
        const auto& imp = br.imp[0];
        EXPECT_EQ(imp.id, "1");
        EXPECT_FALSE(imp.instl);
        EXPECT_EQ(imp.tagid, "agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw");
        EXPECT_DOUBLE_EQ(imp.bidfloor, 0.5);
        {
            EXPECT_TRUE(imp.banner.has_value());
            const auto& banner = *imp.banner;
            EXPECT_EQ(banner.w.size(), 1);
            EXPECT_EQ(banner.w[0], 728);
            EXPECT_EQ(banner.h.size(), 1);
            EXPECT_EQ(banner.h[0], 90);
            EXPECT_EQ(banner.pos, proto::AdPosition::ABOVE);
            EXPECT_EQ(banner.btype.size(), 1);
            EXPECT_EQ(banner.btype[0], proto::BannerAdType::IFRAME);
            EXPECT_EQ(banner.battr.size(), 1);
            EXPECT_EQ(banner.battr[0], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
            EXPECT_EQ(banner.api.size(), 1);
            EXPECT_EQ(banner.api[0], proto::ApiFramework::MRAID);
        }
    }
    {
        EXPECT_TRUE(br.app.has_value());
        const auto& app = *br.app;
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
            const auto& pub = *app.publisher;
            EXPECT_EQ(pub.id, "agltb3B1Yi1pbmNyDAsSA0FwcBiJkfTUCV");
            EXPECT_EQ(pub.name, "yahoo");
            EXPECT_EQ(pub.domain, "www.yahoo.com");
        }
        EXPECT_EQ(app.storeurl, "https://itunes.apple.com/id628677149");
    }
    {
        EXPECT_TRUE(br.device.has_value());
        const auto& device = *br.device;
        EXPECT_FALSE(device.dnt);
        EXPECT_EQ(device.ua, "Mozilla/5.0 (iPhone; CPU iPhone OS 6_1 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3");
        EXPECT_EQ(device.ip, "123.145.167.189");
        {
            EXPECT_TRUE(device.geo.has_value());
            const auto& geo = *device.geo;
            EXPECT_EQ(geo.country, "USA");
            EXPECT_DOUBLE_EQ(geo.lat, 35.012345);
            EXPECT_DOUBLE_EQ(geo.lon, -115.12345);
            EXPECT_EQ(geo.city, "Los Angeles");
            EXPECT_EQ(geo.metro, "803");
            EXPECT_EQ(geo.region, "CA");
            EXPECT_EQ(geo.zip, "90049");
        }
        EXPECT_EQ(device.dpidsha1, "AA000DFE74168477C70D291f574D344790E0BB11");
        EXPECT_EQ(device.dpidmd5, "AA003EABFB29E6F759F3BDAB34E50BB11");
        EXPECT_EQ(device.carrier, "310-410");
        EXPECT_EQ(device.language, "en");
        EXPECT_EQ(device.make, "Apple");
        EXPECT_EQ(device.model, "iPhone");
        EXPECT_EQ(device.os, "iOS");
        EXPECT_EQ(device.osv, "6.1");
        EXPECT_TRUE(device.js);
        EXPECT_EQ(device.connectiontype, proto::ConnectionType::CELLULAR_UNKNOWN);
        EXPECT_EQ(device.devicetype, proto::DeviceType::MOBILE_OR_TABLET);
    }
    {
        EXPECT_TRUE(br.user.has_value());
        const auto& user = *br.user;
        EXPECT_EQ(user.id, "ffffffd5135596709273b3a1a07e466ea2bf4fff");
        EXPECT_EQ(user.yob, 1984);
        EXPECT_EQ(user.gender, "M");
    }
    EXPECT_EQ(br.at, proto::AuctionPrice::SECOND_PRICE_PLUS);
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

TEST(OpenRtb2Point3Spec, SimpleBanner)
{
    const auto br = detail::PrepareUnit<proto::BidRequest>(detail::SpecMock::GetSimpleBanner());
    EXPECT_EQ(br.id, "80ce30c53c16e6ede735f123ef6e32361bfc7b22");
    EXPECT_EQ(br.at, proto::AuctionPrice::FIRST_PRICE);
    EXPECT_EQ(br.cur.size(), 1);
    EXPECT_EQ(br.cur[0], "USD");
    {
        EXPECT_EQ(br.imp.size(), 1);
        const auto& imp = br.imp[0];
        EXPECT_EQ(imp.id, "1");
        EXPECT_DOUBLE_EQ(imp.bidfloor, 0.03);
        {
            EXPECT_TRUE(imp.banner.has_value());
            const auto& banner = *imp.banner;
            EXPECT_EQ(banner.w.size(), 1);
            EXPECT_EQ(banner.w[0], 300);
            EXPECT_EQ(banner.h.size(), 1);
            EXPECT_EQ(banner.h[0], 250);
            EXPECT_EQ(banner.pos, proto::AdPosition::UNKNOWN);
        }
    }
    {
        EXPECT_TRUE(br.site.has_value());
        const auto& site = *br.site;
        EXPECT_EQ(site.id, "102855");
        EXPECT_EQ(site.cat.size(), 1);
        EXPECT_EQ(site.cat[0], "IAB3-1");
        EXPECT_EQ(site.domain, "www.foobar.com");
        EXPECT_EQ(site.page, "http://www.foobar.com/1234.html");
        {
            EXPECT_TRUE(site.publisher.has_value());
            const auto& pub = *site.publisher;
            EXPECT_EQ(pub.id, "8953");
            EXPECT_EQ(pub.name, "foobar.com");
            EXPECT_EQ(pub.cat.size(), 1);
            EXPECT_EQ(pub.cat[0], "IAB3-1");
            EXPECT_EQ(pub.domain, "foobar.com");
        }
    }
    {
        EXPECT_TRUE(br.device.has_value());
        const auto& device = *br.device;
        EXPECT_EQ(device.ua, "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/537.13 (KHTML, like Gecko) Version/5.1.7 Safari/534.57.2");
        EXPECT_EQ(device.ip, "123.145.167.10");
    }
    {
        EXPECT_TRUE(br.user.has_value());
        const auto& user = *br.user;
        EXPECT_EQ(user.id, "55816b39711f9b5acf3b90e313ed29e51665623f");
    }
}

TEST(OpenRtb2Point3Spec, ExpandableCreative)
{
    const auto br = detail::PrepareUnit<proto::BidRequest>(
        detail::SpecMock::GetExpandableCreative());
    EXPECT_EQ(br.id, "123456789316e6ede735f123ef6e32361bfc7b22");
    EXPECT_EQ(br.at, proto::AuctionPrice::SECOND_PRICE_PLUS);
    EXPECT_EQ(br.cur.size(), 1);
    EXPECT_EQ(br.cur[0], "USD");
    {
        EXPECT_EQ(br.imp.size(), 1);
        const auto& imp = br.imp[0];
        EXPECT_EQ(imp.id, "1");
        EXPECT_DOUBLE_EQ(imp.bidfloor, 0.003);
        EXPECT_EQ(imp.iframebuster.size(), 2);
        EXPECT_EQ(imp.iframebuster[0], "vendor1.com");
        EXPECT_EQ(imp.iframebuster[1], "vendor2.com");
        {
            EXPECT_TRUE(imp.banner.has_value());
            const auto& banner = *imp.banner;
            EXPECT_EQ(banner.w.size(), 1);
            EXPECT_EQ(banner.w[0], 300);
            EXPECT_EQ(banner.h.size(), 1);
            EXPECT_EQ(banner.h[0], 250);
            EXPECT_EQ(banner.pos, proto::AdPosition::UNKNOWN);
            EXPECT_EQ(banner.battr.size(), 1);
            EXPECT_EQ(banner.battr[0], proto::CreativeAttribute::USER_INTERACTIVE);
            EXPECT_EQ(banner.expdir.size(), 2);
            EXPECT_EQ(banner.expdir[0], proto::ExpandableDirection::RIGHT);
            EXPECT_EQ(banner.expdir[1], proto::ExpandableDirection::DOWN);
        }
    }
    {
        EXPECT_TRUE(br.site.has_value());
        const auto& site = *br.site;
        EXPECT_EQ(site.id, "102855");
        EXPECT_EQ(site.cat.size(), 1);
        EXPECT_EQ(site.cat[0], "IAB3-1");
        EXPECT_EQ(site.domain, "www.foobar.com");
        EXPECT_EQ(site.page, "http://www.foobar.com/1234.html");
        {
            EXPECT_TRUE(site.publisher.has_value());
            const auto& pub = *site.publisher;
            EXPECT_EQ(pub.id, "8953");
            EXPECT_EQ(pub.name, "foobar.com");
            EXPECT_EQ(pub.cat.size(), 1);
            EXPECT_EQ(pub.cat[0], "IAB3-1");
            EXPECT_EQ(pub.domain, "foobar.com");
        }
    }
    {
        EXPECT_TRUE(br.device.has_value());
        const auto& device = *br.device;
        EXPECT_EQ(device.ua, "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/537.13 (KHTML, like Gecko) Version/5.1.7 Safari/534.57.2");
        EXPECT_EQ(device.ip, "123.145.167.10");
    }
    {
        EXPECT_TRUE(br.user.has_value());
        const auto& user = *br.user;
        EXPECT_EQ(user.id, "55816b39711f9b5acf3b90e313ed29e51665623f");
        EXPECT_EQ(user.buyerid, "545678765467876567898765678987654");
        {
            EXPECT_EQ(user.data.size(), 1);
            const auto& data = user.data[0];
            EXPECT_EQ(data.id, "6");
            EXPECT_EQ(data.name, "Data Provider 1");
            {
                EXPECT_EQ(data.segment.size(), 3);
                const auto& seg0 = data.segment[0];
                EXPECT_EQ(seg0.id, "12341318394918");
                EXPECT_EQ(seg0.name, "auto intenders");
                const auto& seg1 = data.segment[1];
                EXPECT_EQ(seg1.id, "1234131839491234");
                EXPECT_EQ(seg1.name, "auto enthusiasts");
                const auto& seg2 = data.segment[2];
                EXPECT_EQ(seg2.id, "23423424");
                EXPECT_EQ(seg2.name, "data-provider1-age");
                EXPECT_EQ(seg2.value, "30-40");
            }
        }
    }
}

TEST(OpenRtb2Point3Spec, Mobile)
{
    const auto br = detail::PrepareUnit<proto::BidRequest>(detail::SpecMock::GetMobile());
    EXPECT_EQ(br.id, "IxexyLDIIk");
    EXPECT_EQ(br.at, proto::AuctionPrice::SECOND_PRICE_PLUS);
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
    {
        EXPECT_EQ(br.imp.size(), 1);
        const auto& imp = br.imp[0];
        EXPECT_EQ(imp.id, "1");
        EXPECT_DOUBLE_EQ(imp.bidfloor, 0.5);
        EXPECT_FALSE(imp.instl);
        EXPECT_EQ(imp.tagid, "agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw");
        {
            EXPECT_TRUE(imp.banner.has_value());
            const auto& banner = *imp.banner;
            EXPECT_EQ(banner.w.size(), 1);
            EXPECT_EQ(banner.w[0], 728);
            EXPECT_EQ(banner.h.size(), 1);
            EXPECT_EQ(banner.h[0], 90);
            EXPECT_EQ(banner.pos, proto::AdPosition::ABOVE);
            EXPECT_EQ(banner.btype.size(), 1);
            EXPECT_EQ(banner.btype[0], proto::BannerAdType::IFRAME);
            EXPECT_EQ(banner.battr.size(), 1);
            EXPECT_EQ(banner.battr[0], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
            EXPECT_EQ(banner.api.size(), 1);
            EXPECT_EQ(banner.api[0], proto::ApiFramework::MRAID);
        }
    }
    {
        EXPECT_TRUE(br.app.has_value());
        const auto& app = *br.app;
        EXPECT_EQ(app.id, "agltb3B1Yi1pbmNyDAsSA0FwcBiJkfIUDA");
        EXPECT_EQ(app.name, "Yahoo Weather");
        EXPECT_EQ(app.cat.size(), 2);
        EXPECT_EQ(app.cat[0], "IAB15");
        EXPECT_EQ(app.cat[1], "IAB15-10");
        EXPECT_EQ(app.ver, "1.0.2");
        EXPECT_EQ(app.bundle, "com.yahoo.wxapp");
        EXPECT_EQ(app.storeurl, "https://itunes.apple.com/id628677149");
        {
            EXPECT_TRUE(app.publisher.has_value());
            const auto& pub = *app.publisher;
            EXPECT_EQ(pub.id, "agltb3B1Yi1pbmNyDAsSA0FwcBiJkfTUCV");
            EXPECT_EQ(pub.name, "yahoo");
            EXPECT_EQ(pub.domain, "www.yahoo.com");
        }
    }
    {
        EXPECT_TRUE(br.device.has_value());
        const auto& device = *br.device;
        EXPECT_FALSE(device.dnt);
        EXPECT_EQ(device.ua, "Mozilla/5.0 (iPhone; CPU iPhone OS 6_1 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3");
        EXPECT_EQ(device.ip, "123.145.167.189");
        EXPECT_EQ(device.ifa, "AA000DFE74168477C70D291f574D344790E0BB11");
        EXPECT_EQ(device.carrier, "VERIZON");
        EXPECT_EQ(device.language, "en");
        EXPECT_EQ(device.make, "Apple");
        EXPECT_EQ(device.model, "iPhone");
        EXPECT_EQ(device.os, "iOS");
        EXPECT_EQ(device.osv, "6.1");
        EXPECT_TRUE(device.js);
        EXPECT_EQ(device.connectiontype, proto::ConnectionType::CELLULAR_UNKNOWN);
        EXPECT_EQ(device.devicetype, proto::DeviceType::MOBILE_OR_TABLET);
        {
            EXPECT_TRUE(device.geo.has_value());
            const auto& geo = *device.geo;
            EXPECT_DOUBLE_EQ(geo.lat, 35.012345);
            EXPECT_DOUBLE_EQ(geo.lon, -115.12345);
            EXPECT_EQ(geo.country, "USA");
            EXPECT_EQ(geo.metro, "803");
            EXPECT_EQ(geo.region, "CA");
            EXPECT_EQ(geo.city, "Los Angeles");
            EXPECT_EQ(geo.zip, "90049");
        }
    }
    {
        EXPECT_TRUE(br.user.has_value());
        const auto& user = *br.user;
        EXPECT_EQ(user.id, "ffffffd5135596709273b3a1a07e466ea2bf4fff");
        EXPECT_EQ(user.yob, 1984);
        EXPECT_EQ(user.gender, "M");
    }
}

TEST(OpenRtb2Point3Spec, Video)
{
    const auto br = detail::PrepareUnit<proto::BidRequest>(detail::SpecMock::GetVideo());
    EXPECT_EQ(br.id, "1234567893");
    EXPECT_EQ(br.at, proto::AuctionPrice::SECOND_PRICE_PLUS);
    EXPECT_EQ(br.tmax, 120);
    {
        EXPECT_EQ(br.imp.size(), 1);
        const auto& imp = br.imp[0];
        EXPECT_EQ(imp.id, "1");
        EXPECT_DOUBLE_EQ(imp.bidfloor, 0.03);
        {
            EXPECT_TRUE(imp.video.has_value());
            const auto& video = *imp.video;
            EXPECT_EQ(video.w, 640);
            EXPECT_EQ(video.h, 480);
            EXPECT_EQ(video.pos, proto::AdPosition::ABOVE);
            EXPECT_EQ(video.startdelay, proto::VideoStartDelay::PRE_ROLL);
            EXPECT_EQ(video.minduration, 5);
            EXPECT_EQ(video.maxduration, 30);
            EXPECT_EQ(video.maxextended, 30);
            EXPECT_EQ(video.minbitrate, 300);
            EXPECT_EQ(video.maxbitrate, 1500);
            EXPECT_EQ(video.api.size(), 2);
            EXPECT_EQ(video.api[0], proto::ApiFramework::VPAID_1);
            EXPECT_EQ(video.api[1], proto::ApiFramework::VPAID_2);
            EXPECT_EQ(video.protocols.size(), 2);
            EXPECT_EQ(video.protocols[0], proto::VideoBidResponseProtocol::VAST2);
            EXPECT_EQ(video.protocols[1], proto::VideoBidResponseProtocol::VAST3);
            EXPECT_EQ(video.mimes.size(), 4);
            EXPECT_EQ(video.mimes[0].type, "video/x-flv");
            EXPECT_EQ(video.mimes[1].type, "video/mp4");
            EXPECT_EQ(video.mimes[2].type, "application/x-shockwave-flash");
            EXPECT_EQ(video.mimes[3].type, "application/javascript");
            EXPECT_EQ(video.linearity, proto::VideoLinearity::IN_STREAM);
            EXPECT_TRUE(video.boxingallowed);
            EXPECT_EQ(video.playbackmethod.size(), 2);
            EXPECT_EQ(video.playbackmethod[0], proto::VideoPlaybackMethod::AUTO_PLAY_SOUND_ON);
            EXPECT_EQ(video.playbackmethod[1], proto::VideoPlaybackMethod::CLICK_TO_PLAY);
            EXPECT_EQ(video.delivery.size(), 1);
            EXPECT_EQ(video.delivery[0], proto::ContentDeliveryMethod::PROGRESSIVE);
            EXPECT_EQ(video.battr.size(), 2);
            EXPECT_EQ(video.battr[0], proto::CreativeAttribute::USER_INTERACTIVE);
            EXPECT_EQ(video.battr[1], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
            EXPECT_EQ(video.companionad.size(), 2);
            const auto& comp0 = video.companionad[0];
            EXPECT_EQ(comp0.id, "1234567893-1");
            EXPECT_EQ(comp0.w[0], 300);
            EXPECT_EQ(comp0.h[0], 250);
            EXPECT_EQ(comp0.pos, proto::AdPosition::ABOVE);
            EXPECT_EQ(comp0.battr.size(), 2);
            EXPECT_EQ(comp0.battr[0], proto::CreativeAttribute::USER_INTERACTIVE);
            EXPECT_EQ(comp0.battr[1], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
            EXPECT_EQ(comp0.expdir.size(), 2);
            EXPECT_EQ(comp0.expdir[0], proto::ExpandableDirection::RIGHT);
            EXPECT_EQ(comp0.expdir[1], proto::ExpandableDirection::DOWN);
            const auto& comp1 = video.companionad[1];
            EXPECT_EQ(comp1.id, "1234567893-2");
            EXPECT_EQ(comp1.w[0], 728);
            EXPECT_EQ(comp1.h[0], 90);
            EXPECT_EQ(comp1.pos, proto::AdPosition::ABOVE);
            EXPECT_EQ(comp1.battr.size(), 2);
            EXPECT_EQ(comp1.battr[0], proto::CreativeAttribute::USER_INTERACTIVE);
            EXPECT_EQ(comp1.battr[1], proto::CreativeAttribute::WINDOWS_DIALOG_OR_ALERT_STYLE);
            EXPECT_EQ(video.companiontype.size(), 2);
            EXPECT_EQ(video.companiontype[0], proto::VastCompanionType::STATIC_RESOURCE);
            EXPECT_EQ(video.companiontype[1], proto::VastCompanionType::HTML_RESOURCE);
        }
        {
            EXPECT_TRUE(br.site.has_value());
            const auto& site = *br.site;
            EXPECT_EQ(site.id, "1345135123");
            EXPECT_EQ(site.name, "Site ABCD");
            EXPECT_EQ(site.domain, "siteabcd.com");
            EXPECT_EQ(site.cat.size(), 2);
            EXPECT_EQ(site.cat[0], "IAB2-1");
            EXPECT_EQ(site.cat[1], "IAB2-2");
            EXPECT_EQ(site.page, "http://siteabcd.com/page.htm");
            EXPECT_EQ(site.ref, "http://referringsite.com/referringpage.htm");
            EXPECT_TRUE(site.privacypolicy);
            {
                EXPECT_TRUE(site.publisher.has_value());
                const auto& pub = *site.publisher;
                EXPECT_EQ(pub.id, "pub12345");
                EXPECT_EQ(pub.name, "Publisher A");
            }
            {
                EXPECT_TRUE(site.content.has_value());
                const auto& content = *site.content;
                EXPECT_EQ(content.id, "1234567");
                EXPECT_EQ(content.series, "All About Cars");
                EXPECT_EQ(content.season, "2");
                EXPECT_EQ(content.episode, 23);
                EXPECT_EQ(content.cat.size(), 1);
                EXPECT_EQ(content.title, "Car Show");
                EXPECT_EQ(content.cat.size(), 1);
                EXPECT_EQ(content.cat[0], "IAB2-2");
                EXPECT_EQ(content.keywords.size(), 3);
                EXPECT_EQ(content.keywords[0], "keyword-a");
                EXPECT_EQ(content.keywords[1], "keyword-b");
                EXPECT_EQ(content.keywords[2], "keyword-c");
            }
        }
        {
            EXPECT_TRUE(br.device.has_value());
            const auto& device = *br.device;
            EXPECT_FALSE(device.dnt);
            EXPECT_EQ(device.ip, "64.124.253.1");
            EXPECT_EQ(device.ua, "Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10.6; en-US; rv:1.9.2.16) Gecko/20110319 Firefox/3.6.16");
            EXPECT_EQ(device.os, "OS X");
            EXPECT_EQ(device.flashver, "10.1");
            EXPECT_TRUE(device.js);
        }
        {
            EXPECT_TRUE(br.user.has_value());
            const auto& user = *br.user;
            EXPECT_EQ(user.id, "456789876567897654678987656789");
            EXPECT_EQ(user.buyerid, "545678765467876567898765678987654");
            {
                EXPECT_EQ(user.data.size(), 1);
                const auto& data = user.data[0];
                EXPECT_EQ(data.id, "6");
                EXPECT_EQ(data.name, "Data Provider 1");
                {
                    EXPECT_EQ(data.segment.size(), 2);
                    const auto& seg0 = data.segment[0];
                    EXPECT_EQ(seg0.id, "12341318394918");
                    EXPECT_EQ(seg0.name, "auto intenders");
                    const auto& seg1 = data.segment[1];
                    EXPECT_EQ(seg1.id, "1234131839491234");
                    EXPECT_EQ(seg1.name, "auto enthusiasts");
                }
            }
        }
    }
}

TEST(OpenRtb2Point3Spec, PmpWithDirectDeal)
{
    const auto br = detail::PrepareUnit<proto::BidRequest>(detail::SpecMock::GetPmpWithDirectDeal());
    EXPECT_EQ(br.id, "80ce30c53c16e6ede735f123ef6e32361bfc7b22");
    EXPECT_EQ(br.at, proto::AuctionPrice::FIRST_PRICE);
    EXPECT_EQ(br.cur.size(), 1);
    EXPECT_EQ(br.cur[0], "USD");
    EXPECT_EQ(br.imp.size(), 1);
    {
        const auto& imp = br.imp[0];
        EXPECT_EQ(imp.id, "1");
        EXPECT_EQ(imp.bidfloor, 0.03);
        {
            EXPECT_TRUE(imp.banner.has_value());
            const auto& banner = *imp.banner;
            EXPECT_EQ(banner.w.size(), 1);
            EXPECT_EQ(banner.w[0], 300);
            EXPECT_EQ(banner.h.size(), 1);
            EXPECT_EQ(banner.h[0], 250);
            EXPECT_EQ(banner.pos, proto::AdPosition::UNKNOWN);
        }
        {
            EXPECT_TRUE(imp.pmp.has_value());
            const auto& pmp = *imp.pmp;
            EXPECT_TRUE(pmp.private_auction);
            EXPECT_EQ(pmp.deals.size(), 2);
            {
                const auto& deal = pmp.deals[0];
                EXPECT_EQ(deal.id, "AB-Agency1-0001");
                EXPECT_EQ(deal.at, proto::AuctionPrice::FIRST_PRICE);
                EXPECT_DOUBLE_EQ(deal.bidfloor, 2.5);
                EXPECT_EQ(deal.bidfloorcur, "USD");
                EXPECT_EQ(deal.wseat.size(), 1);
                EXPECT_EQ(deal.wseat[0], "Agency1");
            }
            {
                const auto& deal = pmp.deals[1];
                EXPECT_EQ(deal.id, "XY-Agency2-0001");
                EXPECT_EQ(deal.at, proto::AuctionPrice::SECOND_PRICE_PLUS);
                EXPECT_DOUBLE_EQ(deal.bidfloor, 2);
                EXPECT_EQ(deal.bidfloorcur, "USD");
                EXPECT_EQ(deal.wseat.size(), 1);
                EXPECT_EQ(deal.wseat[0], "Agency2");
            }
        }
    }
    {
        EXPECT_TRUE(br.site.has_value());
        const auto& site = *br.site;
        EXPECT_EQ(site.id, "102855");
        EXPECT_EQ(site.domain, "www.foobar.com");
        EXPECT_EQ(site.cat.size(), 1);
        EXPECT_EQ(site.cat[0], "IAB3-1");
        EXPECT_EQ(site.page, "http://www.foobar.com/1234.html");
        {
            EXPECT_TRUE(site.publisher.has_value());
            const auto& pub = *site.publisher;
            EXPECT_EQ(pub.id, "8953");
            EXPECT_EQ(pub.name, "foobar.com");
            EXPECT_EQ(pub.cat.size(), 1);
            EXPECT_EQ(pub.cat[0], "IAB3-1");
            EXPECT_EQ(pub.domain, "foobar.com");
        }
    }
    {
        EXPECT_TRUE(br.device.has_value());
        const auto& device = *br.device;
        EXPECT_EQ(device.ua, "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/537.13 (KHTML, like Gecko) Version/5.1.7 Safari/534.57.2");
        EXPECT_EQ(device.ip, "123.145.167.10");
    }
    {
        EXPECT_TRUE(br.user.has_value());
        const auto& user = *br.user;
        EXPECT_EQ(user.id, "55816b39711f9b5acf3b90e313ed29e51665623f");
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
