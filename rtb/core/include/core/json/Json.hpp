#pragma once

#include <rapidjson/document.h>

#include "core/stl/String.hpp"

namespace Json
{

using Document = rapidjson::Document;
using Object = rapidjson::Value;

Json::Document Str2Json(Core::StringView str);

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
