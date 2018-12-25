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

    Json::ExtInt(j, "wmax", banner.wmax);
    Json::ExtInt(j, "hmax", banner.hmax);
    Json::ExtInt(j, "wmin", banner.wmin);
    Json::ExtInt(j, "hmin", banner.hmin);
    Json::ExtStr(j, "id", banner.id);
    Json::ExtVecEnum(j, "btype", banner.btype);
    Json::ExtVecEnum(j, "battr", banner.battr);
    Json::ExtEnum(j, "pos", banner.pos);
    Json::ExtVecStr(j, "mimes", banner.mimes);
    Json::ExtEnum(j, "topframe", banner.topframe);
    Json::ExtVecEnum(j, "expdir", banner.expdir);
    Json::ExtVecEnum(j, "api", banner.api);

    return banner;
}

JsonWorker<Deal>::Type JsonWorker<Deal>::Parse(const Json::Object& j)
{
    Deal deal = {};

    Json::ExtReqStr(j, "id", deal.id);
    Json::ExtDouble(j, "bidfloor", deal.bidfloor);
    Json::ExtStr(j, "bidfloorcur", deal.bidfloorcur);
    Json::ExtEnum(j, "at", deal.at);
    Json::ExtVecStr(j, "wseat", deal.wseat);
    Json::ExtVecStr(j, "wadomain", deal.wadomain);

    return deal;
}

JsonWorker<Pmp>::Type JsonWorker<Pmp>::Parse(const Json::Object& j)
{
    Pmp pmp = {};

    Json::ExtInt(j, "private_auction", pmp.private_auction);

    if (j.HasMember("deals")) {
        const auto& deals = j["deals"];
        if (const auto size = deals.Size(); deals.IsArray() && (size > 0)) {
            pmp.deals.reserve(size);
            for (const auto& val : deals.GetArray()) {
                pmp.deals.push_back(JsonWorker<Deal>::Parse(val));
            }
        }
    }

    return pmp;
}

JsonWorker<Impression>::Type JsonWorker<Impression>::Parse(const Json::Object& j)
{
    Impression imp = {};

    Json::ExtReqStr(j, "id", imp.id);

    if (j.HasMember("banner")) {
        imp.banner = JsonWorker<Banner>::Parse(j["banner"]);
    }

    Json::ExtStr(j, "displaymanager", imp.displaymanager);
    Json::ExtStr(j, "displaymanagerver", imp.displaymanagerver);
    Json::ExtInt(j, "instl", imp.instl);
    Json::ExtStr(j, "tagid", imp.tagid);
    Json::ExtDouble(j, "bidfloor", imp.bidfloor);
    Json::ExtStr(j, "bidfloorcur", imp.bidfloorcur);
    Json::ExtInt(j, "secure", imp.secure);
    Json::ExtVecStr(j, "iframebuster", imp.iframebuster);

    if (j.HasMember("pmp")) {
        imp.pmp = JsonWorker<Pmp>::Parse(j["pmp"]);
    }

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
    Json::ExtInt(j, "tmax", br.tmax);
    Json::ExtVecStr(j, "wseat", br.wseat);
    Json::ExtBool(j, "allimps", br.allimps);
    Json::ExtVecStr(j, "cur", br.cur);
    Json::ExtVecStr(j, "bcat", br.bcat);
    Json::ExtVecStr(j, "badv", br.badv);

    return br;
}
