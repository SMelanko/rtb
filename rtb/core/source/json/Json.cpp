#include "core/json/Json.hpp"

namespace json
{

json::Document Str2Json(core::StringView str)
{
    json::Document j;
    j.Parse(str.data(), str.length());
    return j;
}

} // namespace json
