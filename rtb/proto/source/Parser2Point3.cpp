#include "proto/Parser2Point3.hpp"

JsonWorker<Banner>::Type JsonWorker<Banner>::Parse(const Json::Object& j)
{
    Type banner = {};

    if (j.HasMember("w")) {
        if (j["w"].IsArray()) {
            banner.w.reserve(j["w"].Size());
            for (const auto& val : j["w"].GetArray()) {
                banner.w.push_back(val.GetInt());
            }
        } else {
            banner.w.push_back(j["w"].GetInt());
        }
    }
    if (j.HasMember("h")) {
        if (j["w"].IsArray()) {
            banner.h.reserve(j["h"].Size());
            for (const auto& val : j["h"].GetArray()) {
                banner.h.push_back(val.GetInt());
            }
        } else {
            banner.h.push_back(j["h"].GetInt());
        }
    }

    if (j.HasMember("wmax")) {
        banner.wmax = j["wmax"].GetInt();
    }
    if (j.HasMember("hmax")) {
        banner.hmax = j["hmax"].GetInt();
    }

    if (j.HasMember("wmin")) {
        banner.wmin = j["wmin"].GetInt();
    }
    if (j.HasMember("hmin")) {
        banner.hmin = j["hmin"].GetInt();
    }

    if (j.HasMember("id")) {
        banner.id = j["id"].GetString();
    }

    if (j.HasMember("btype") && j["btype"].IsArray()) {
        banner.btype.reserve(j["btype"].Size());
        for (const auto& val : j["btype"].GetArray()) {
            banner.btype.push_back(static_cast<BannerAdType>(val.GetInt()));
        }
    }

    if (j.HasMember("battr") && j["battr"].IsArray()) {
        banner.battr.reserve(j["battr"].Size());
        for (const auto& val : j["battr"].GetArray()) {
            banner.battr.push_back(static_cast<CreativeAttribute>(val.GetInt()));
        }
    }

    if (j.HasMember("pos")) {
        banner.pos = static_cast<AdPosition>(j["pos"].GetInt());
    }

    if (j.HasMember("mimes") && j["mimes"].IsArray()) {
        banner.mimes.reserve(j["mimes"].Size());
        for (const auto& val : j["mimes"].GetArray()) {
            banner.mimes.emplace_back(val.GetString());
        }
    }

    if (j.HasMember("topframe")) {
        banner.topframe = static_cast<FramePosition>(j["topframe"].GetInt());
    }

    if (j.HasMember("expdir") && j["expdir"].IsArray()) {
        banner.expdir.reserve(j["expdir"].Size());
        for (const auto& val : j["expdir"].GetArray()) {
            banner.expdir.push_back(static_cast<ExpandableDirection>(val.GetInt()));
        }
    }

    if (j.HasMember("api") && j["api"].IsArray()) {
        banner.api.reserve(j["api"].Size());
        for (const auto& val : j["api"].GetArray()) {
            banner.api.push_back(static_cast<ApiFramework>(val.GetInt()));
        }
    }
#if 0
    if (j.HasMember("ext")) {
        banner.ext = j["ext"].GetObject();
    }
#endif
    return banner;
}

JsonWorker<Deal>::Type JsonWorker<Deal>::Parse(const Json::Object& j)
{
    Deal deal = {};

    deal.id = j["id"].GetString();

    if (j.HasMember("bidfloor")) {
        deal.bidfloor = j["bidfloor"].GetDouble();
    }

    if (j.HasMember("bidfloorcur")) {
        deal.bidfloorcur = j["bidfloorcur"].GetString();
    }

    if (j.HasMember("at")) {
        deal.at = static_cast<AuctionPrice>(j["at"].GetInt());
    }

    Json::ExtVecStr(j, "wseat", deal.wseat);
    Json::ExtVecStr(j, "wadomain", deal.wadomain);

#if 0
    if (j.HasMember("ext")) {
        deal.ext = j["ext"].GetObject();
    }
#endif
    return deal;
}

JsonWorker<Pmp>::Type JsonWorker<Pmp>::Parse(const Json::Object& j)
{
    Pmp pmp = {};

    if (j.HasMember("private_auction")) {
        pmp.private_auction = j["private_auction"].GetInt();
    }

    if (j.HasMember("deals")) {
        const auto& deals = j["deals"];
        if (const auto size = deals.Size(); deals.IsArray() && (size > 0)) {
            pmp.deals.reserve(size);
            for (const auto& val : deals.GetArray()) {
                pmp.deals.push_back(JsonWorker<Deal>::Parse(val));
            }
        }
    }
#if 0
    if (j.HasMember("ext")) {
        pmp.ext = j["ext"].GetObject();
    }
#endif
    return pmp;
}