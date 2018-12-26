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
    static Banner Parse(const Json::Object& j);
};

template<>
class JsonWorker<Video>
{
public:
    static Video Parse(const Json::Object& j);
};

template<>
class JsonWorker<Native>
{
public:
    static Native Parse(const Json::Object& j);
};

template<>
class JsonWorker<Deal>
{
public:
    static Deal Parse(const Json::Object& j);
};

template<>
class JsonWorker<Pmp>
{
public:
    static Pmp Parse(const Json::Object& j);
};

template<>
class JsonWorker<Impression>
{
public:
    static Impression Parse(const Json::Object& j);
};

template<>
class JsonWorker<BidRequest>
{
public:
    static BidRequest Parse(const Json::Object& j);
};