#pragma once

#include "core/stl/String.hpp"

namespace Core::Utils
{

class StringAlgo
{
public:
    /// Removes whitespace character(s) as classified by the currently installed C locale.
    static Core::String RemoveWhitespace(Core::String str);
};

}
