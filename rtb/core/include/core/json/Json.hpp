#pragma once

#include "core/stl/String.hpp"
#include "core/Type.hpp"

#include <rapidjson/document.h>

#include <fmt/format.h>

namespace json
{

using Document = rapidjson::Document;
using Object = rapidjson::Value;

json::Document Str2Json(core::StringView str);

template<class T>
void ExtBool(const json::Object& j, core::StringView field, T& data)
{
    auto name = field.data();
    if (j.HasMember(name)) {
        if (!j[name].IsInt() && !j[name].IsBool()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expected int/bool", field) };
        }
        data = (j[name].IsInt()) ? static_cast<core::Bool>(j[name].GetInt()) : j[name].GetBool();
    }
}

template<class T>
void ExtDouble(const json::Object& j, core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        if (!j[field.data()].IsNumber()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expected number", field) };
        }
        data = j[field.data()].GetDouble();
    }
}

template<class T>
void ExtEnum(const json::Object& j, core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        if (!j[field.data()].IsInt()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expected int", field) };
        }
        // TODO: Validate int value.
        data = static_cast<T>(j[field.data()].GetInt());
    }
}

template<class T>
void ExtInt(const json::Object& j, core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        if (!j[field.data()].IsInt()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expected int", field) };
        }
        data = j[field.data()].GetInt();
    }
}

template<class T>
void ExtReqStr(const json::Object& j, core::StringView field, T& data)
{
    if (!j.HasMember(field.data())) {
        throw std::runtime_error{ fmt::format("Required \"{}\" field is missing", field) };
    }
    if (!j[field.data()].IsString()) {
        throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expected string", field) };
    }
    data = j[field.data()].GetString();
}

template<class T>
void ExtStr(const json::Object& j, core::StringView field, T& data)
{
    if (j.HasMember(field.data())) {
        if (!j[field.data()].IsString()) {
            throw std::runtime_error{ fmt::format("Invalid type of \"{}\" field, expected string", field) };
        }
        data = j[field.data()].GetString();
    }
}

template<class T>
void ExtVecEnum(const json::Object& j, core::StringView field, T& data)
{
    auto name = field.data();
    if (j.HasMember(name) && j[name].IsArray()) {
        const auto& arr = j[name];
        if (const auto size = arr.Size(); (size > 0)) {
            data.reserve(size);
            for (const auto& val : arr.GetArray()) {
                data.push_back(static_cast<typename T::value_type>(val.GetInt()));
            }
        }
    }
}

template<class C>
void ExtVecStr(const json::Object& j, core::StringView field, C& data)
{
    auto name = field.data();
    if (j.HasMember(name) && j[name].IsArray()) {
        const auto& arr = j[name];
        if (const auto size = arr.Size(); (size > 0)) {
            data.reserve(size);
            for (const auto& val : arr.GetArray()) {
                data.emplace_back(val.GetString());
            }
        }
    }
}

} // namespace json
