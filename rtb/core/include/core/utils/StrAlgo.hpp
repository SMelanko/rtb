#pragma once

#include "core/stl/String.hpp"
#include "core/stl/Vector.hpp"

namespace core
{

class StrAlgo
{
public:
    /**
     * @brief Removes whitespace character(s) as classified by the currently installed C locale.
     * @param str, the original string.
     */
    static core::String RemoveWhitespaces(core::String str);
    /**
     * @brief Splits a string on a delimiter (empty items are excluded).
     * @param str, the original string to split.
     * @param delimiter, the delemiter you want to use.
     */
    static core::Vector<core::String> Split(const core::String& str, const char delimiter = ',');
};

}
