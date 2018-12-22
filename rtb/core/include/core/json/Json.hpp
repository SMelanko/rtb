#pragma once

#include <string_view>

#include <rapidjson/document.h>

namespace Json
{

using Document = ::rapidjson::Document;
using Object = ::rapidjson::Value;

template<class C>
void ExtVecStr(const Json::Object& j, const std::string_view field, C& data)
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
