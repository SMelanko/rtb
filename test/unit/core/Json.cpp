#include <gtest/gtest.h>

#include <core/json/Json.hpp>

TEST(Json, ExtractRequiredString)
{
    auto str = R"({"field":"test"})";
    auto doc = Json::Str2Json(str);
    // Ok.
    Core::String val;
    Json::ExtReqStr(doc, "field", val);
    EXPECT_EQ(val, "test");
    // Error.
    EXPECT_THROW({
        try {
            Json::ExtReqStr(doc, "field_", val);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Required \"field_\" field is missing");
            throw;
        }
    }, std::runtime_error);
}

TEST(Json, ExtractOptionalString)
{
    auto str = R"({"field":"test"})";
    auto doc = Json::Str2Json(str);
    // Ok.
    Core::String val1;
    Json::ExtOptStr(doc, "field", val1);
    EXPECT_EQ(val1, "test");
    // Must be ok as well.
    Core::String val2;
    Json::ExtOptStr(doc, "field_", val2);
    EXPECT_EQ(val2, "");
}

TEST(Json, ExtractEnum)
{
    enum class Color { NONE = 0, RED = 1 };
    // Ok.
    auto str = R"({"color":1})";
    auto doc = Json::Str2Json(str);
    Color color;
    Json::ExtEnum(doc, "color", color);
    EXPECT_EQ(color, Color::RED);
    // Error.
    // TODO: Need to validate integer value.
}
