#pragma once

#include "core/stl/String.hpp"

#include <rapidjson/document.h>

#include <fmt/format.h>

namespace Json
{

using Document = rapidjson::Document;
using Object = rapidjson::Value;

Json::Document Str2Json(Core::StringView str);

template<class T>
void ExtReqStr(const Json::Object& j, Core::StringView field, T& data)
{
    if (!j.HasMember(field.data())) {
        throw std::runtime_error{ fmt::format("Required \"{}\" field is missing", field) };
    }

    data = j[field.data()].GetString();
}

template<class T>
void ExtOptStr(const Json::Object& j, Core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        data = j[field.data()].GetString();
    }
}

template<class T>
void ExtOptInt(const Json::Object& j, Core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        data = j[field.data()].GetInt();
    }
}

template<class T>
void ExtDouble(const Json::Object& j, Core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        data = j[field.data()].GetDouble();
    }
}

template<class T>
void ExtEnum(const Json::Object& j, Core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        data = static_cast<T>(j[field.data()].GetInt());
    }
}

template<class C>
void ExtVecStr(const Json::Object& j, Core::StringView field, C& data)
{
    if (j.HasMember(field.data())) {
        const auto& arr = j[field.data()];
        if (const auto size = arr.Size(); arr.IsArray() && (size > 0)) {
            data.reserve(size);
            for (const auto& val : arr.GetArray()) {
                data.emplace_back(val.GetString());
            }
        }
    }
};

}
