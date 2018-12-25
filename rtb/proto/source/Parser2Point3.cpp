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

    Json::ExtOptInt(j, "wmax", banner.wmax);
    Json::ExtOptInt(j, "hmax", banner.hmax);
    Json::ExtOptInt(j, "wmin", banner.wmin);
    Json::ExtOptInt(j, "hmin", banner.hmin);
    Json::ExtOptStr(j, "id", banner.id);
    Json::ExtVecEnum(j, "btype", banner.btype);
    Json::ExtVecEnum(j, "battr", banner.battr);
    Json::ExtEnum(j, "pos", banner.pos);
    Json::ExtVecStr(j, "mimes", banner.mimes);
    Json::ExtEnum(j, "topframe", banner.topframe);
    Json::ExtVecEnum(j, "expdir", banner.expdir);
    Json::ExtVecEnum(j, "api", banner.api);
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

    Json::ExtReqStr(j, "id", deal.id);
    Json::ExtDouble(j, "bidfloor", deal.bidfloor);
    Json::ExtOptStr(j, "bidfloorcur", deal.bidfloorcur);
    Json::ExtEnum(j, "at", deal.at);
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

    Json::ExtOptInt(j, "private_auction", pmp.private_auction);

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

    Json::ExtReqStr(j, "id", imp.id);

    if (j.HasMember("banner")) {
        imp.banner = JsonWorker<Banner>::Parse(j["banner"]);
    }

    Json::ExtOptStr(j, "displaymanager", imp.displaymanager);
    Json::ExtOptStr(j, "displaymanagerver", imp.displaymanagerver);
    Json::ExtOptInt(j, "instl", imp.instl);
    Json::ExtOptStr(j, "tagid", imp.tagid);
    Json::ExtDouble(j, "bidfloor", imp.bidfloor);
    Json::ExtOptStr(j, "bidfloorcur", imp.bidfloorcur);
    Json::ExtOptInt(j, "secure", imp.secure);
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

    Json::ExtReqStr(j, "id", br.id);

    const auto& imp = j["imp"];
    if (const auto size = imp.Size(); imp.IsArray() && (size > 0)) {
        br.imp.reserve(size);
        for (const auto& val : imp.GetArray()) {
            br.imp.push_back(JsonWorker<Impression>::Parse(val));
        }
    }

    Json::ExtBool(j, "test", br.test);
    Json::ExtEnum(j, "at", br.at);
    Json::ExtOptInt(j, "tmax", br.tmax);
    Json::ExtVecStr(j, "wseat", br.wseat);
    Json::ExtBool(j, "allimps", br.allimps);
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
