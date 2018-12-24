#include "core/json/Json.hpp"

namespace Json
{

Json::Document Str2Json(Core::StringView str)
{
    Json::Document j;
    j.Parse(str.data(), str.length());
    return j;
}

}
