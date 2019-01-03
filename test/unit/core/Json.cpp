#include <core/json/Json.hpp>
#include <core/stl/Vector.hpp>
#include <core/Type.hpp>

#include <gtest/gtest.h>

TEST(Json, ExtractBool)
{
    auto str = R"({"bool":1})";
    auto doc = json::Str2Json(str);
    core::Bool b;
    json::ExtBool(doc, "bool", b);
    EXPECT_TRUE(b);
    str = R"({"bool":false})";
    doc = json::Str2Json(str);
    json::ExtBool(doc, "bool", b);
    EXPECT_FALSE(b);
}

TEST(Json, ExtractEnum)
{
    enum class Color { NONE = 0, RED = 1 };
    auto str = R"({"color":1})";
    auto doc = json::Str2Json(str);
    Color color;
    json::ExtEnum(doc, "color", color);
    EXPECT_EQ(color, Color::RED);
}

TEST(Json, ExtractVectorEnum)
{
    enum class Color { RED = 1, GREEN = 2, BLUE = 3 };
    auto str = R"({"color":[1,2,3]})";
    auto doc = json::Str2Json(str);
    core::Vector<Color> color;
    json::ExtVecEnum(doc, "color", color);
    EXPECT_EQ(color.size(), 3);
    EXPECT_EQ(color[0], Color::RED);
    EXPECT_EQ(color[1], Color::GREEN);
    EXPECT_EQ(color[2], Color::BLUE);
}

TEST(Json, ExtractDouble)
{
    auto str = R"({"double":1.2})";
    auto doc = json::Str2Json(str);
    // Ok
    core::Double d;
    json::ExtDouble(doc, "double", d);
    EXPECT_DOUBLE_EQ(d, 1.2);
    // Error.
    str = R"({"string":"test"})";
    doc = json::Str2Json(str);
    d = 0.0;
    EXPECT_THROW({
        try {
            json::ExtDouble(doc, "string", d);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Invalid type of \"string\" field, expected number");
            throw;
        }
    }, std::runtime_error);
}

TEST(Json, ExtractInt)
{
    auto str = R"({"int":1})";
    auto doc = json::Str2Json(str);
    // Ok
    core::Int i;
    json::ExtInt(doc, "int", i);
    EXPECT_EQ(i, 1);
    // Error.
    str = R"({"double":2.3})";
    doc = json::Str2Json(str);
    i = 0;
    EXPECT_THROW({
        try {
            json::ExtInt(doc, "double", i);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Invalid type of \"double\" field, expected int");
            throw;
        }
    }, std::runtime_error);
}

TEST(Json, ExtractRequiredString)
{
    auto str = R"({"field":"test"})";
    auto doc = json::Str2Json(str);
    // Ok.
    core::String val;
    json::ExtReqStr(doc, "field", val);
    EXPECT_EQ(val, "test");
    // Error.
    EXPECT_THROW({
        try {
            json::ExtReqStr(doc, "nonexistent", val);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Required \"nonexistent\" field is missing");
            throw;
        }
    }, std::runtime_error);
    // Error.
    str = R"({"int":1})";
    doc = json::Str2Json(str);
    EXPECT_THROW({
        try {
            json::ExtReqStr(doc, "int", val);
        } catch (const std::exception& e) {
            EXPECT_STREQ(e.what(), "Invalid type of \"int\" field, expected string");
            throw;
        }
    }, std::runtime_error);
}

TEST(Json, ExtractOptionalString)
{
    auto str = R"({"field":"test"})";
    auto doc = json::Str2Json(str);
    // Ok.
    core::String val1;
    json::ExtStr(doc, "field", val1);
    EXPECT_EQ(val1, "test");
    // Must be ok as well.
    core::String val2;
    json::ExtStr(doc, "field_", val2);
    EXPECT_EQ(val2, "");
}
