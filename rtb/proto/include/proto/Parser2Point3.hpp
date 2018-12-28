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
    static Banner Parse(const json::Object& j);
};

template<>
class JsonWorker<Video>
{
public:
    static Video Parse(const json::Object& j);
};

template<>
class JsonWorker<Native>
{
public:
    static Native Parse(const json::Object& j);
};

template<>
class JsonWorker<Publisher>
{
public:
    static Publisher Parse(const json::Object& j);
};

template<>
class JsonWorker<Content>
{
public:
    static Content Parse(const json::Object& j);
};

template<>
class JsonWorker<Site>
{
public:
    static Site Parse(const json::Object& j);
};

template<>
class JsonWorker<App>
{
public:
    static App Parse(const json::Object& j);
};

template<>
class JsonWorker<Deal>
{
public:
    static Deal Parse(const json::Object& j);
};

template<>
class JsonWorker<Pmp>
{
public:
    static Pmp Parse(const json::Object& j);
};

template<>
class JsonWorker<Impression>
{
public:
    static Impression Parse(const json::Object& j);
};

template<>
class JsonWorker<BidRequest>
{
public:
    static BidRequest Parse(const json::Object& j);
};