#include "core/json/Json.hpp"

namespace json
{

json::Document Str2Json(Core::StringView str)
{
    json::Document j;
    j.Parse(str.data(), str.length());
    return j;
}

}
