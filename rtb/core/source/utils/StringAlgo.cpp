#include "core/utils/StringAlgo.hpp"

#include <algorithm>

namespace Core::Utils
{

Core::String StringAlgo::RemoveWhitespace(Core::String str)
{
    str.erase(std::remove_if(str.begin(), str.end(), std::isspace), str.end());

    return str;
}

}
