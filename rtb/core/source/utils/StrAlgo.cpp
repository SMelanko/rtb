#include "core/utils/StrAlgo.hpp"

#include <algorithm>

namespace core
{

core::String StrAlgo::RemoveWhitespace(core::String str)
{
    str.erase(std::remove_if(str.begin(), str.end(), std::isspace), str.end());

    return str;
}

}
