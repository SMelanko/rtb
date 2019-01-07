#include "Bench.hpp"

#include <base/stl/String.hpp>
#include <base/stl/Vector.hpp>

#include <sstream>

#include <boost/algorithm/string.hpp>

#include <range/v3/view/split.hpp>

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

} // namepsace detail

void SplitStrStlVer(bench::State& state)
{
    for (auto _ : state) {
        [[maybe_unused]] const auto result = detail::SplitStlVer(detail::str, ',');
    }
}
BENCH(SplitStrStlVer);

void SplitStrBoostVer(bench::State& state)
{
    for (auto _ : state) {
        base::Vector<base::String> result;
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
