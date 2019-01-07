#pragma once

#include "base/stl/String.hpp"
#include "base/stl/Vector.hpp"

namespace base
{

class StrAlgo
{
public:
    /**
     * @brief Removes whitespace character(s) as classified by the currently installed C locale.
     * @param str, the original string.
     */
    static base::String RemoveWhitespaces(base::String str);
    /**
     * @brief Splits a string on a delimiter (empty items are excluded).
     * @param str, the original string to split.
     * @param delimiter, the delemiter you want to use.
     */
    static base::Vector<base::String> Split(const base::String& str, const char delimiter = ',');
};

} // namespace base
