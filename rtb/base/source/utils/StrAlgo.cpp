#include "base/utils/StrAlgo.hpp"

#include <algorithm>

#include <range/v3/view/split.hpp>

namespace base
{

base::String StrAlgo::RemoveWhitespaces(base::String str)
{
    constexpr auto isspace = [](const unsigned char c) { return std::isspace(c); };
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

    return str;
}

base::Vector<base::String> StrAlgo::Split(const base::String& str, const char delimiter)
{
    return ranges::view::split(str, delimiter);
}

} // namespace base
