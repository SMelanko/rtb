#include "Bench.hpp"

#include <proto/Parser2Point3.hpp>
#include <test/data/OpenRtb2Point3Sample.hpp>

#include <iostream>

#define LOG_TEST_DATA
#undef LOG_TEST_DATA

void Log(core::StringView str)
{
#ifdef LOG_TEST_DATA
    std::cerr << str << '\n';
#endif
}

#define PERFORM_BENCH(unit) \
    const auto str = test::data::OpenRtb2Point3Sample::Get ## unit(); \
    Log(str); \
    for (auto _ : state) { \
        auto dummy = proto::JsonWorker<proto::unit>::Parse(json::Str2Json(str)); \
    }

void ParseBanner(bench::State& state)
{
    PERFORM_BENCH(Banner)
}
BENCH(ParseBanner);

void ParseVideo(bench::State& state)
{
    PERFORM_BENCH(Video)
}
BENCH(ParseVideo);

void ParseNative(bench::State& state)
{
    PERFORM_BENCH(Native)
}
BENCH(ParseNative);

void ParseApp(bench::State& state)
{
    PERFORM_BENCH(App)
}
BENCH(ParseApp);

void ParseSite(bench::State& state)
{
    PERFORM_BENCH(Site)
}
BENCH(ParseSite);

void ParseGeo(bench::State& state)
{
    PERFORM_BENCH(Geo)
}
BENCH(ParseGeo);

void ParseDevice(bench::State& state)
{
    PERFORM_BENCH(Device)
}
BENCH(ParseDevice);

void ParseUser(bench::State& state)
{
    PERFORM_BENCH(User)
}
BENCH(ParseUser);

void ParseDeal(bench::State& state)
{
    PERFORM_BENCH(Deal)
}
BENCH(ParseDeal);

void ParsePmp(bench::State& state)
{
    PERFORM_BENCH(Pmp)
}
BENCH(ParsePmp);

void ParseImpression(bench::State& state)
{
    PERFORM_BENCH(Impression)
}
BENCH(ParseImpression);

void ParseBrandscreenBidRequest(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetBrandscreenBidRequestBench();
    Log(str);
    for (auto _ : state) {
        auto br = proto::JsonWorker<proto::BidRequest>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseBrandscreenBidRequest);
