#include "proto/Parser2Point3.hpp"

JsonWorker<Banner>::Type JsonWorker<Banner>::Parse(const Core::Json& j)
{
    Type banner = {};

    if (j.HasMember("w")) {
        if (j["w"].IsArray()) {
            banner.w.reserve(j["w"].Size());
            for (auto it = j.Begin(); it != j.End(); ++it) {
                banner.w.push_back(it->GetInt());
            }
        } else {
            banner.w.push_back(j["w"].GetInt());
        }
    }
    if (j.HasMember("h")) {
        if (j["w"].IsArray()) {
            banner.h.reserve(j["h"].Size());
            for (auto it = j.Begin(); it != j.End(); ++it) {
                banner.h.push_back(j["h"].GetInt());
            }
        } else {
            banner.h.push_back(j["h"].GetInt());
        }
    }

    return banner;
}