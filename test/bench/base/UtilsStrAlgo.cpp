#include "Bench.hpp"

#include <base/stl/String.hpp>
#include <base/stl/Vector.hpp>

#include <sstream>

#include <boost/algorithm/string.hpp>

#include <range/v3/view/split.hpp>

#include <absl/strings/str_split.h>

namespace detail
{

const base::String str = "one,two,three,four,five,six,seven,eight,nine,ten";

base::Vector<base::String> SplitStlVer(const base::String& str, const char delimiter)
{
    base::Vector<base::String> result;
    std::stringstream input{ str };
    base::String item;

    while (std::getline(input, item, delimiter)) {
        if (item.size()) {
            result.emplace_back(std::move(item));
        }
    }

    if (std::getline(input, item, static_cast<char>(EOF)) && item.size()) {
        result.emplace_back(std::move(item));
    }

    return result;
}

bool Assert(const base::Vector<base::String>& reality)
{
    const base::Vector<base::String> expect = {
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"
    };

    return reality == expect;
}

} // namespace detail

void SplitStrStlVer(bench::State& state)
{
    auto split = []{
        return detail::SplitStlVer(detail::str, ',');
    };

    assert(detail::Assert(split()));

    for (auto _ : state) {
        const auto result = split();
        bench::DoNotOptimize(result);
    }
}
BENCH(SplitStrStlVer);

void SplitStrBoostVer(bench::State& state)
{
    auto split = []{
        base::Vector<base::String> result;
        boost::split(result, detail::str, boost::is_any_of(","));
        return result;
    };

    assert(detail::Assert(split()));

    for (auto _ : state) {
        const auto result = split();
        bench::DoNotOptimize(result);
    }
}
BENCH(SplitStrBoostVer);

void SplitStrRangesV3Ver(bench::State& state)
{
    auto split = []{
        return ranges::view::split(detail::str, ',');
    };

    assert(detail::Assert(split()));

    for (auto _ : state) {
        const auto result = split();
        bench::DoNotOptimize(result);
    }
}
BENCH(SplitStrRangesV3Ver);

#if 0
void SplitStrAbseilVer(bench::State& state)
{
    auto split = []{
        return absl::StrSplit(detail::str, ',');
    };

    assert(detail::Assert(split()));

    for (auto _ : state) {
        const auto result = split();
        bench::DoNotOptimize(result);
    }
}
BENCH(SplitStrAbseilVer);
#endif
