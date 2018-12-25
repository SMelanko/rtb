#pragma once

#include "core/stl/String.hpp"
#include "core/Type.hpp"

#include <rapidjson/document.h>

#include <fmt/format.h>

namespace Json
{

using Document = rapidjson::Document;
using Object = rapidjson::Value;

Json::Document Str2Json(Core::StringView str);

template<class T>
void ExtBool(const Json::Object& j, Core::StringView field, T& data)
{
    auto name = field.data();
    if (j.HasMember(name)) {
        if (!j[name].IsInt() || !j[name].IsBool()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expect int", field) };
        }
        data = (j[name].IsInt()) ? static_cast<Core::Bool>(j[name].GetInt()) : j[name].GetBool();
    }
}

template<class T>
void ExtReqStr(const Json::Object& j, Core::StringView field, T& data)
{
    if (!j.HasMember(field.data())) {
        throw std::runtime_error{ fmt::format("Required \"{}\" field is missing", field) };
    }
    if (!j[field.data()].IsString()) {
        throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expect string", field) };
    }
    data = j[field.data()].GetString();
}

template<class T>
void ExtOptStr(const Json::Object& j, Core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        if (!j[field.data()].IsString()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expect string", field) };
        }
        data = j[field.data()].GetString();
    }
}

template<class T>
void ExtOptInt(const Json::Object& j, Core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        if (!j[field.data()].IsInt()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expect int", field) };
        }
        data = j[field.data()].GetInt();
    }
}

template<class T>
void ExtDouble(const Json::Object& j, Core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        if (!j[field.data()].IsDouble()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expect double", field) };
        }
        data = j[field.data()].GetDouble();
    }
}

template<class T>
void ExtEnum(const Json::Object& j, Core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        if (!j[field.data()].IsInt()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expect int", field) };
        }
        // TODO: Validate int value.
        data = static_cast<T>(j[field.data()].GetInt());
    }
}

template<class T>
void ExtVecEnum(const Json::Object& j, Core::StringView field, T& data)
{
    auto name = field.data();
    if (j.HasMember(name) && j[name].IsArray()) {
        data.reserve(j[name].Size());
        for (const auto& val : j[name].GetArray()) {
            data.push_back(static_cast<typename T::value_type>(val.GetInt()));
        }
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
