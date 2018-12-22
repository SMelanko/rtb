#pragma once

#include <optional>

namespace Core
{

using Bool = bool;
using Double = double;
using Int = int;

template<class T>
using Opt = std::optional<T>;

}
