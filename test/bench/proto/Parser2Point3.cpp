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

void ParseBanner(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetBanner();
    Log(str);
    for (auto _ : state) {
        auto b = proto::JsonWorker<proto::Banner>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseBanner);

void ParseVideo(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetVideo();
    Log(str);
    for (auto _ : state) {
        auto v = proto::JsonWorker<proto::Video>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseVideo);

void ParseNative(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetNative();
    Log(str);
    for (auto _ : state) {
        auto n = proto::JsonWorker<proto::Native>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseNative);

void ParseApp(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetApp();
    Log(str);
    for (auto _ : state) {
        auto a = proto::JsonWorker<proto::App>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseApp);

void ParseSite(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetSite();
    Log(str);
    for (auto _ : state) {
        auto s = proto::JsonWorker<proto::Site>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseSite);

void ParseGeo(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetGeo();
    Log(str);
    for (auto _ : state) {
        auto g = proto::JsonWorker<proto::Geo>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseGeo);

void ParseDevice(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetDevice();
    Log(str);
    for (auto _ : state) {
        auto d = proto::JsonWorker<proto::Device>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseDevice);

void ParseUser(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetUser();
    Log(str);
    for (auto _ : state) {
        auto d = proto::JsonWorker<proto::User>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseUser);

void ParseDeal(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetDeal();
    Log(str);
    for (auto _ : state) {
        auto deal = proto::JsonWorker<proto::Deal>::Parse(json::Str2Json(str));
    }
}
BENCH(ParseDeal);

void ParsePmp(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetPmp();
    Log(str);
    for (auto _ : state) {
        auto pmp = proto::JsonWorker<proto::Pmp>::Parse(json::Str2Json(str));
    }
}
BENCH(ParsePmp);

void ParseImpression(bench::State& state)
{
    auto str = test::data::OpenRtb2Point3Sample::GetImpression();
    Log(str);
    for (auto _ : state) {
        auto imp = proto::JsonWorker<proto::Impression>::Parse(json::Str2Json(str));
    }
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
