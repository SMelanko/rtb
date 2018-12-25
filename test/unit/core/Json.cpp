#include <gtest/gtest.h>

#include <core/json/Json.hpp>
#include <core/stl/Vector.hpp>
#include <core/Type.hpp>

TEST(Json, ExtractEnum)
{
    enum class Color { NONE = 0, RED = 1 };
    // Ok.
    auto str = R"({"color":1})";
    auto doc = Json::Str2Json(str);
    Color color;
    Json::ExtEnum(doc, "color", color);
    EXPECT_EQ(color, Color::RED);
}

TEST(Json, ExtractVectorEnum)
{
    enum class Color { RED = 1, GREEN = 2, BLUE = 3 };
    // Ok.
    auto str = R"({"color":[1,2,3]})";
    auto doc = Json::Str2Json(str);
    Core::Vector<Color> color;
    Json::ExtVecEnum(doc, "color", color);
    EXPECT_EQ(color.size(), 3);
    EXPECT_EQ(color[0], Color::RED);
    EXPECT_EQ(color[1], Color::GREEN);
    EXPECT_EQ(color[2], Color::BLUE);
}

TEST(Json, ExtractDouble)
{
    auto str = R"({"double":1.2})";
    auto doc = Json::Str2Json(str);
    // Ok
    Core::Double d;
    Json::ExtDouble(doc, "double", d);
    EXPECT_DOUBLE_EQ(d, 1.2);
    // Error.
    str = R"({"string":"test"})";
    doc = Json::Str2Json(str);
    d = 0.0;
    EXPECT_THROW({
        try {
            Json::ExtDouble(doc, "string", d);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Invalid type of \"string\" field, expect double");
            throw;
        }
    }, std::runtime_error);
}

TEST(Json, ExtractInt)
{
    auto str = R"({"int":1})";
    auto doc = Json::Str2Json(str);
    // Ok
    Core::Int i;
    Json::ExtOptInt(doc, "int", i);
    EXPECT_EQ(i, 1);
    // Error.
    str = R"({"double":2.3})";
    doc = Json::Str2Json(str);
    i = 0;
    EXPECT_THROW({
        try {
            Json::ExtOptInt(doc, "double", i);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Invalid type of \"double\" field, expect int");
            throw;
        }
    }, std::runtime_error);
}

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
            Json::ExtReqStr(doc, "nonexistent", val);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Required \"nonexistent\" field is missing");
            throw;
        }
    }, std::runtime_error);
    // Error.
    str = R"({"int":1})";
    doc = Json::Str2Json(str);
    EXPECT_THROW({
        try {
            Json::ExtReqStr(doc, "int", val);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Invalid type of \"int\" field, expect string");
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
