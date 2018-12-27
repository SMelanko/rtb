#include "Bench.hpp"

#include <core/stl/String.hpp>
#include <data/OpenRtb2Point3Sample.hpp>
#include <proto/Parser2Point3.hpp>

#include <iostream>

#define LOG_TEST_DATA
#undef LOG_TEST_DATA

void Log(Core::StringView str)
{
#ifdef LOG_TEST_DATA
    std::cerr << str << '\n';
#endif
}

void ParseBanner(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetBanner();
    Log(str);
    for (auto _ : state) {
        auto banner = JsonWorker<Banner>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseBanner);

void ParseVideo(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetVideo();
    Log(str);
    for (auto _ : state) {
        auto v = JsonWorker<Video>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseVideo);

void ParseNative(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetNative();
    Log(str);
    for (auto _ : state) {
        auto n = JsonWorker<Native>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseNative);

void ParseApp(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetApp();
    Log(str);
    for (auto _ : state) {
        auto a = JsonWorker<App>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseApp);

void ParseDeal(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetDeal();
    Log(str);
    for (auto _ : state) {
        auto deal = JsonWorker<Deal>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseDeal);

void ParsePmp(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetPmp();
    Log(str);
    for (auto _ : state) {
        auto pmp = JsonWorker<Pmp>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParsePmp);

void ParseImpression(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetImpression();
    Log(str);
    for (auto _ : state) {
        auto imp = JsonWorker<Impression>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseImpression);

void ParseBrandscreenBidRequest(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetBrandscreenBidRequest();
    Log(str);
    for (auto _ : state) {
        auto br = JsonWorker<BidRequest>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseBrandscreenBidRequest);
