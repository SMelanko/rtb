#include "Parser2Point3.hpp"

#include <proto/Parser2Point3.hpp>

Core::Json Str2Json(const Core::String& str)
{
    Core::Json j;
    j.Parse(str.c_str(), str.length());
    return j;
}

void ParseBanner(benchmark::State& state)
{
    for (auto _ : state) {
        const Core::String str = R"({
            "h":250,
            "w":300,
            "wmax":640,
            "hmax":320,
            "wmin":240,
            "hmin":200,
            "id":"p7mwtup3aep7c0io",
            "pos":0,
            "btype":[4],
            "battr":[14],
            "mimes":["image/jpg","image/png"],
            "topframe":0,
            "expdir":[2,4],
            "api":[3]
        })";
        auto banner = JsonWorker<Banner>::Parse(Str2Json(str));
    }
}
BENCH(ParseBanner);
