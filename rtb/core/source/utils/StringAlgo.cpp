#include "core/utils/StringAlgo.hpp"

#include <algorithm>

namespace core::utils
{

core::String StringAlgo::RemoveWhitespace(core::String str)
{
    str.erase(std::remove_if(str.begin(), str.end(), std::isspace), str.end());

    return str;
}

}
