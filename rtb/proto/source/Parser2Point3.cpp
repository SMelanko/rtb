#include "proto/Parser2Point3.hpp"

namespace Detail
{

template<class T>
void ExtObj(const Json::Object& j, Core::StringView field, T& data)
{
    const auto fieldName = field.data();
    if (j.HasMember(fieldName)) {
        data = JsonWorker<T>::Parse(j[fieldName]);
    }
}

template<class T>
void ExtObj(const Json::Object& j, Core::StringView field, Core::Optional<T>& data)
{
    const auto fieldName = field.data();
    if (j.HasMember(fieldName)) {
        data = JsonWorker<T>::Parse(j[fieldName]);
    }
}

template<class T>
void ExtSize(const Json::Object& j, Core::StringView field, T& data)
{
    const auto fieldName = field.data();
    if (j.HasMember(fieldName)) {
        if (j[fieldName].IsArray()) {
            data.reserve(j[fieldName].Size());
            for (const auto& val : j[fieldName].GetArray()) {
                data.push_back(val.GetInt());
            }
        } else {
            data.push_back(j[fieldName].GetInt());
        }
    }
}

template<class T>
void ExtVecObj(const Json::Object& j, Core::StringView field, T& data)
{
    const auto fieldName = field.data();
    if (j.HasMember(fieldName)) {
        const auto& deals = j[fieldName];
        if (const auto size = deals.Size(); (size > 0)) {
            data.reserve(size);
            for (const auto& val : deals.GetArray()) {
                data.push_back(JsonWorker<typename T::value_type>::Parse(val));
            }
        }
    }
}

}

Banner JsonWorker<Banner>::Parse(const Json::Object& j)
{
    Banner banner = {};

    Detail::ExtSize(j, "w", banner.w);
    Detail::ExtSize(j, "h", banner.h);
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

Video JsonWorker<Video>::Parse(const Json::Object& j)
{
    Video video = {};

    Json::ExtVecStr(j, "mimes", video.mimes);
    Json::ExtInt(j, "minduration", video.minduration);
    Json::ExtInt(j, "maxduration", video.maxduration);
    Json::ExtEnum(j, "protocol", video.protocol);
    Json::ExtVecEnum(j, "protocols", video.protocols);
    Json::ExtInt(j, "w", video.w);
    Json::ExtInt(j, "h", video.h);
    Json::ExtEnum(j, "startdelay", video.startdelay);
    Json::ExtEnum(j, "linearity", video.linearity);
    Json::ExtInt(j, "sequence", video.sequence);
    Json::ExtVecEnum(j, "battr", video.battr);
    Json::ExtInt(j, "maxextended", video.maxextended);
    Json::ExtInt(j, "minbitrate", video.minbitrate);
    Json::ExtInt(j, "maxbitrate", video.maxbitrate);
    Json::ExtBool(j, "boxingallowed", video.boxingallowed);
    Json::ExtVecEnum(j, "playbackmethod", video.playbackmethod);
    Json::ExtVecEnum(j, "delivery", video.delivery);
    Json::ExtEnum(j, "pos", video.pos);
    Detail::ExtVecObj(j, "companionad", video.companionad);
    Json::ExtVecEnum(j, "api", video.api);
    Json::ExtVecEnum(j, "companiontype", video.companiontype);

    return video;
}

Native JsonWorker<Native>::Parse(const Json::Object& j)
{
    Native native;

    Json::ExtReqStr(j, "request", native.request);
    Json::ExtStr(j, "ver", native.ver);
    Json::ExtVecEnum(j, "api", native.api);
    Json::ExtVecEnum(j, "battr", native.battr);

    return native;
}

Publisher JsonWorker<Publisher>::Parse(const Json::Object& j)
{
    Publisher pub;

    Json::ExtStr(j, "id", pub.id);
    Json::ExtStr(j, "name", pub.name);
    Json::ExtVecStr(j, "cat", pub.cat);
    Json::ExtStr(j, "domain", pub.domain);

    return pub;
}

Content JsonWorker<Content>::Parse(const Json::Object& j)
{
    Content c;

    Json::ExtStr(j, "id", c.id);
    Json::ExtInt(j, "episode", c.episode);
    Json::ExtStr(j, "title", c.title);
    Json::ExtStr(j, "series", c.series);
    Json::ExtStr(j, "season", c.season);
    Detail::ExtObj(j, "producer", c.producer);
    Json::ExtStr(j, "url", c.url);
    Json::ExtVecStr(j, "cat", c.cat);
    Json::ExtEnum(j, "videoquality", c.videoquality);
    Json::ExtEnum(j, "context", c.context);
    Json::ExtStr(j, "contentrating", c.contentrating);
    Json::ExtStr(j, "userrating", c.userrating);
    Json::ExtEnum(j, "qagmediarating", c.qagmediarating);
    Json::ExtVecStr(j, "keywords", c.keywords);
    Json::ExtBool(j, "livestream", c.livestream);
    Json::ExtEnum(j, "sourcerelationship", c.sourcerelationship);
    Json::ExtInt(j, "len", c.len);
    Json::ExtStr(j, "language", c.language);
    Json::ExtBool(j, "embeddable", c.embeddable);

    return c;
}

Site JsonWorker<Site>::Parse(const Json::Object& j)
{
    Site site;

    Json::ExtReqStr(j, "id", site.id);
    Json::ExtStr(j, "name", site.name);
    Json::ExtStr(j, "domain", site.domain);
    Json::ExtVecStr(j, "cat", site.cat);
    Json::ExtVecStr(j, "sectioncat", site.sectioncat);
    Json::ExtVecStr(j, "pagecat", site.pagecat);
    Json::ExtStr(j, "page", site.page);
    Json::ExtStr(j, "ref", site.ref);
    Json::ExtStr(j, "search", site.search);
    Json::ExtBool(j, "mobile", site.mobile);
    Json::ExtBool(j, "privacypolicy", site.privacypolicy);
    Detail::ExtObj(j, "publisher", site.publisher);
    Detail::ExtObj(j, "content", site.content);
    Json::ExtStr(j, "keywords", site.keywords);

    return site;
}

Deal JsonWorker<Deal>::Parse(const Json::Object& j)
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

Pmp JsonWorker<Pmp>::Parse(const Json::Object& j)
{
    Pmp pmp = {};

    Json::ExtInt(j, "private_auction", pmp.private_auction);
    Detail::ExtVecObj(j, "deals", pmp.deals);

    return pmp;
}

Impression JsonWorker<Impression>::Parse(const Json::Object& j)
{
    Impression imp = {};

    Json::ExtReqStr(j, "id", imp.id);
    Detail::ExtObj(j, "banner", *imp.banner);
    Detail::ExtObj(j, "video", *imp.video);
    Json::ExtStr(j, "displaymanager", imp.displaymanager);
    Json::ExtStr(j, "displaymanagerver", imp.displaymanagerver);
    Json::ExtInt(j, "instl", imp.instl);
    Json::ExtStr(j, "tagid", imp.tagid);
    Json::ExtDouble(j, "bidfloor", imp.bidfloor);
    Json::ExtStr(j, "bidfloorcur", imp.bidfloorcur);
    Json::ExtInt(j, "secure", imp.secure);
    Json::ExtVecStr(j, "iframebuster", imp.iframebuster);
    Detail::ExtObj(j, "pmp", imp.pmp);

    return imp;
}

BidRequest JsonWorker<BidRequest>::Parse(const Json::Object& j)
{
    BidRequest br = {};

    Json::ExtReqStr(j, "id", br.id);
    Detail::ExtVecObj(j, "imp", br.imp);
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
