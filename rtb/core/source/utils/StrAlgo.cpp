#include "core/utils/StrAlgo.hpp"

#include <algorithm>

namespace core
{

core::String StrAlgo::RemoveWhitespace(core::String str)
{
    constexpr auto isspace = [](const unsigned char c) { return std::isspace(c); };
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

    return str;
}

}
