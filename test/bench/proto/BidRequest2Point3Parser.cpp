#include "Bench.hpp"

#include <proto/Parser2Point3.hpp>
#include <test/data/BidRequest2Point3.hpp>

#include <iostream>

#define LOG_TEST_DATA
#undef LOG_TEST_DATA

namespace detail
{

void Log(core::StringView str)
{
#ifdef LOG_TEST_DATA
    std::cerr << str << '\n';
#endif
}

}

#define PERFORM_BENCH(unit) \
    const auto str = test::data::OpenRtb2Point3Sample::Get ## unit(); \
    detail::Log(str); \
    for (auto _ : state) { \
        auto dummy = proto::JsonWorker<proto::unit>::Parse(json::Str2Json(str)); \
    }

void BannerSample(bench::State& state)
{
    PERFORM_BENCH(Banner)
}
BENCH(BannerSample);

void VideoSample(bench::State& state)
{
    PERFORM_BENCH(Video)
}
BENCH(VideoSample);

void NativeSample(bench::State& state)
{
    PERFORM_BENCH(Native)
}
BENCH(NativeSample);

void AppSample(bench::State& state)
{
    PERFORM_BENCH(App)
}
BENCH(AppSample);

void SiteSample(bench::State& state)
{
    PERFORM_BENCH(Site)
}
BENCH(SiteSample);

void GeoSample(bench::State& state)
{
    PERFORM_BENCH(Geo)
}
BENCH(GeoSample);

void DeviceSample(bench::State& state)
{
    PERFORM_BENCH(Device)
}
BENCH(DeviceSample);

void UserSample(bench::State& state)
{
    PERFORM_BENCH(User)
}
BENCH(UserSample);

void DealSample(bench::State& state)
{
    PERFORM_BENCH(Deal)
}
BENCH(DealSample);

void PmpSample(bench::State& state)
{
    PERFORM_BENCH(Pmp)
}
BENCH(PmpSample);

void ImpressionSample(bench::State& state)
{
    PERFORM_BENCH(Impression)
}
BENCH(ImpressionSample);

void BrandscreenBidRequest(bench::State& state)
{
    const auto str = test::data::OpenRtb2Point3Sample::GetBrandscreenBidRequestBench();
    detail::Log(str);
    for (auto _ : state) {
        auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    }
}
BENCH(BrandscreenBidRequest);

void BannerSpec(bench::State& state)
{
    const auto str = test::data::OpenRtb2Point3Spec::GetSimpleBanner();
    detail::Log(str);
    for (auto _ : state) {
        auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    }
}
BENCH(BannerSpec);

void ExpandableCreativeSpec(bench::State& state)
{
    const auto str = test::data::OpenRtb2Point3Spec::GetExpandableCreative();
    detail::Log(str);
    for (auto _ : state) {
        auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    }
}
BENCH(ExpandableCreativeSpec);

void MobileSpec(bench::State& state)
{
    const auto str = test::data::OpenRtb2Point3Spec::GetMobile();
    detail::Log(str);
    for (auto _ : state) {
        auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    }
}
BENCH(MobileSpec);

void VideoSpec(bench::State& state)
{
    const auto str = test::data::OpenRtb2Point3Spec::GetVideo();
    detail::Log(str);
    for (auto _ : state) {
        auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    }
}
BENCH(VideoSpec);

void PmpWithDirectDealSpec(bench::State& state)
{
    const auto str = test::data::OpenRtb2Point3Spec::GetPmpWithDirectDeal();
    detail::Log(str);
    for (auto _ : state) {
        auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    }
}
BENCH(PmpWithDirectDealSpec);

void NativeAdSpec(bench::State& state)
{
    const auto str = test::data::OpenRtb2Point3Spec::GetNativeAd();
    detail::Log(str);
    for (auto _ : state) {
        auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    }
}
BENCH(NativeAdSpec);
