#pragma once

#include "core/stl/String.hpp"

namespace core
{

class StrAlgo
{
public:
    /// Removes whitespace character(s) as classified by the currently installed C locale.
    static core::String RemoveWhitespace(core::String str);
};

}
