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

JsonWorker<Impression>::Type JsonWorker<Impression>::Parse(const Json::Object& j)
{
    Impression imp = {};

    imp.id = j["id"].GetString();

    if (j.HasMember("banner")) {
        imp.banner = JsonWorker<Banner>::Parse(j["banner"]);
    }

    if (j.HasMember("displaymanager")) {
        imp.displaymanager = j["displaymanager"].GetString();
    }

    if (j.HasMember("displaymanagerver")) {
        imp.displaymanagerver = j["displaymanagerver"].GetString();
    }

    if (j.HasMember("instl")) {
        imp.instl = j["instl"].GetInt();
    }

    if (j.HasMember("tagid")) {
        imp.tagid = j["tagid"].GetString();
    }

    if (j.HasMember("bidfloor")) {
        imp.bidfloor = j["bidfloor"].GetDouble();
    }

    if (j.HasMember("bidfloorcur")) {
        imp.bidfloorcur = j["bidfloorcur"].GetString();
    }

    if (j.HasMember("secure")) {
        imp.secure = j["secure"].GetInt();
    }

    Json::ExtVecStr(j, "iframebuster", imp.iframebuster);

    if (j.HasMember("pmp")) {
        imp.pmp = JsonWorker<Pmp>::Parse(j["pmp"]);
    }

#if 0
    if (j.HasMember("ext")) {
        imp.ext = j["ext"].GetObject();
    }
#endif

    return imp;
}

JsonWorker<BidRequest>::Type JsonWorker<BidRequest>::Parse(const Json::Object& j)
{
    BidRequest br = {};

    br.id = j["id"].GetString();

    const auto& imp = j["imp"];
    if (const auto size = imp.Size(); imp.IsArray() && (size > 0)) {
        br.imp.reserve(size);
        for (const auto& val : imp.GetArray()) {
            br.imp.push_back(JsonWorker<Impression>::Parse(val));
        }
    }

    if (j.HasMember("test")) {
        br.test = static_cast<bool>(j["test"].GetInt());
    }

    if (j.HasMember("at")) {
        br.at = static_cast<AuctionPrice>(j["at"].GetInt());
    }

    if (j.HasMember("tmax")) {
        br.tmax = j["tmax"].GetInt();
    }

    Json::ExtVecStr(j, "wseat", br.wseat);

    if (j.HasMember("allimps")) {
        br.allimps = static_cast<bool>(j["allimps"].GetInt());
    }

    Json::ExtVecStr(j, "cur", br.cur);
    Json::ExtVecStr(j, "bcat", br.bcat);
    Json::ExtVecStr(j, "badv", br.badv);

#if 0
    if (j.HasMember("regs")) {
        br.regs = j["regs"].GetObject();
    }

    if (j.HasMember("ext")) {
        br.ext = j["ext"].GetObject();
    }
#endif

    return br;
}
