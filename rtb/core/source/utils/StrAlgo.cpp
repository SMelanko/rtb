#include "core/utils/StrAlgo.hpp"

#include <algorithm>
#include <sstream>

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

}
