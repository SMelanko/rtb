#include "Bench.hpp"

#include <core/utils/StrAlgo.hpp>

#include <boost/algorithm/string.hpp>

#include <range/v3/view/split.hpp>

namespace detail
{

const core::String str = "one,two,three,four,five,six,seven,eight,nine,ten";

core::Vector<core::String> SplitStlVer(const core::String& str, const char delimiter)
{
    core::Vector<core::String> result;
    std::stringstream input{ str };
    core::String item;

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

} // namepsace detail

void SplitStrStlVer(bench::State& state)
{
    for (auto _ : state) {
        [[maybe_unused]] const auto result = core::StrAlgo::Split(detail::str, ',');
    }
}
BENCH(SplitStrStlVer);

void SplitStrBoostVer(bench::State& state)
{
    for (auto _ : state) {
        core::Vector<core::String> result;
        boost::split(result, detail::str, boost::is_any_of(","));
    }
}
BENCH(SplitStrBoostVer);

void SplitStrRangesV3Ver(bench::State& state)
{
    for (auto _ : state) {
        [[maybe_unused]] const auto result = ranges::view::split(detail::str, ',');
    }
}
BENCH(SplitStrRangesV3Ver);
