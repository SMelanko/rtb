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
    static Type Parse(const Core::Json& j);
};

template<>
class JsonWorker<Deal>
{
public:
    using Type = Deal;

public:
    /// Parses Deal.
    static Type Parse(const Core::Json& j);
};
