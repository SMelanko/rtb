#include "core/utils/StrAlgo.hpp"

#include <algorithm>
#include <sstream>

#include <range/v3/view/split.hpp>

namespace core
{

core::String StrAlgo::RemoveWhitespaces(core::String str)
{
    constexpr auto isspace = [](const unsigned char c) { return std::isspace(c); };
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

    return str;
}

core::Vector<core::String> StrAlgo::Split(const core::String& str, const char delimiter)
{
    return ranges::view::split(str, delimiter);
}

}
