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
    static Type Parse(const Core::Json& j);
};

template<>
class JsonWorker<Deal>
{
public:
    using Type = Deal;

public:
    static Type Parse(const Core::JsonVal& j);
};

template<>
class JsonWorker<Pmp>
{
public:
    using Type = Pmp;

public:
    static Type Parse(const Core::Json& j);
};
