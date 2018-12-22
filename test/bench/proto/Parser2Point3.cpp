#include "Parser2Point3.hpp"

#include <proto/Parser2Point3.hpp>

auto Str2Json(const Core::String& str)
{
    Json::Document j;
    j.Parse(str.c_str(), str.length());
    return j;
}

void ParseBanner(benchmark::State& state)
{
    for (auto _ : state) {
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
    }
}
BENCH(ParseBanner);

void ParseDeal(benchmark::State& state)
{
    for (auto _ : state) {
        const Core::String str = R"({
            "id":"1452f.eadb4.7aaa","bidfloor":5.3,"at":1,"wseats":[],
            "ext":{"priority":1,"wadvs":[]}
        })";
        auto deal = JsonWorker<Deal>::Parse(Str2Json(str));
    }
}
BENCH(ParseDeal);

void ParsePmp(benchmark::State& state)
{
    for (auto _ : state) {
        const Core::String str = R"({
            "private_auction": 1,
            "deals": [{"id": "DX-1985-010A","bidfloor": 2.5,"at": 2}]
        })";
        auto pmp = JsonWorker<Pmp>::Parse(Str2Json(str));
    }
}
BENCH(ParsePmp);

void ParseImpression(benchmark::State& state)
{
    for (auto _ : state) {
        const Core::String str = R"({
            "id":"1",
            "banner":{"w":728,"h":90,"pos":1,"btype":[4],"battr":[14],"api":[3]},
            "instl":0,"tagid":"agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw","bidfloor":0.5
        })";
        auto imp = JsonWorker<Impression>::Parse(Str2Json(str));
    }
}
BENCH(ParseImpression);
