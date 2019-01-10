#include "Bench.hpp"

#include <base/stl/String.hpp>
#include <base/stl/Vector.hpp>

#include <sstream>

#include <boost/algorithm/string.hpp>

#include <range/v3/view/join.hpp>
#include <range/v3/view/split.hpp>

#include <absl/strings/str_split.h>

namespace detail
{

/// A test string to test split method.
const base::String splitTestStr = "one,two,three,four,five,six,seven,eight,nine,ten";
/// A test list of strings to test join method.
const base::Vector<base::String> joinTestStr = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"
};

base::Vector<base::String> SplitStlVer(const base::String& str, const char delimiter = ',')
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

base::String JoinStlVer(base::Vector<base::String> list, const char delimeter = ',')
{
    std::string str;

    if (list.empty()) {
        return str;
    }

    std::for_each(list.begin(), list.end(), [&](base::StringView s) {
        if (!str.empty()) {
            str += delimeter;
        }
        str += s;
    });

    return str;
}

} // namespace detail

void SplitStrStlVer(bench::State& state)
{
    auto split = []{
        return detail::SplitStlVer(detail::splitTestStr);
    };

    assert(split() == detail::joinTestStr);

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
        boost::split(result, detail::splitTestStr, boost::is_any_of(","));
        return result;
    };

    assert(split() == detail::joinTestStr);

    for (auto _ : state) {
        const auto result = split();
        bench::DoNotOptimize(result);
    }
}
BENCH(SplitStrBoostVer);

void SplitStrRangesV3Ver(bench::State& state)
{
    auto split = []() {
        return ranges::view::split(detail::splitTestStr, ',');
    };

    base::Vector<base::String> list = split();
    assert(list == detail::joinTestStr);

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

void JoinStrStlVer(bench::State& state)
{
    auto join = [] {
        return detail::JoinStlVer(detail::joinTestStr);
    };

    assert(join() == detail::splitTestStr);

    for (auto _ : state) {
        const auto result = join();
        bench::DoNotOptimize(result);
    }
}
BENCH(JoinStrStlVer);

void JoinStrBoostVer(bench::State& state)
{
    auto join = [] {
        return boost::algorithm::join(detail::joinTestStr, ",");
    };

    assert(join() == detail::splitTestStr);

    for (auto _ : state) {
        const auto result = join();
        bench::DoNotOptimize(result);
    }
}
BENCH(JoinStrBoostVer);

void JoinStrRangesV3Ver(bench::State& state)
{
    auto join = [] {
        return ranges::view::join(detail::joinTestStr, ',');
    };

    const base::String str = join();
    assert(str == detail::splitTestStr);

    for (auto _ : state) {
        const auto result = join();
        bench::DoNotOptimize(result);
    }
}
BENCH(JoinStrRangesV3Ver);
