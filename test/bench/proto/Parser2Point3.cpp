#include "Parser2Point3.hpp"

#include <core/stl/String.hpp>
#include <data/OpenRtb2Point3.hpp>
#include <proto/Parser2Point3.hpp>

#include <iostream>

#define LOG_TEST_DATA
#undef LOG_TEST_DATA

void ParseBanner(benchmark::State& state)
{
    auto str = test::data::OpenRtb2Point3::GetBanner();
#ifdef LOG_TEST_DATA
    std::cerr << str << '\n';
#endif
    for (auto _ : state) {
        auto banner = JsonWorker<Banner>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseBanner);

void ParseDeal(benchmark::State& state)
{
    auto str = test::data::OpenRtb2Point3::GetDeal();
#ifdef LOG_TEST_DATA
    std::cerr << str << '\n';
#endif
    for (auto _ : state) {
        auto deal = JsonWorker<Deal>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseDeal);

void ParsePmp(benchmark::State& state)
{
    auto str = test::data::OpenRtb2Point3::GetPmp();
#ifdef LOG_TEST_DATA
    std::cerr << str << '\n';
#endif
    for (auto _ : state) {
        auto pmp = JsonWorker<Pmp>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParsePmp);

void ParseImpression(benchmark::State& state)
{
    auto str = test::data::OpenRtb2Point3::GetImpression();
#ifdef LOG_TEST_DATA
    std::cerr << str << '\n';
#endif
    for (auto _ : state) {
        auto imp = JsonWorker<Impression>::Parse(Json::Str2Json(str));
    }
}
BENCH(ParseImpression);
