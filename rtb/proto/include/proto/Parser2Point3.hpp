#pragma once

#include "proto/OpenRtb.hpp"

template<class T>
class JsonWorker
{
};

template<>
class JsonWorker<Banner>
{
public:
    using Type = Banner;

public:
    /// Parses Banner.
    Type Parse(const Core::Json& j);
};