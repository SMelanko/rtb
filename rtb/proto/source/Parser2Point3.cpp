#include "proto/Parser2Point3.hpp"

#include <core/utils/StrAlgo.hpp>

namespace proto
{

namespace detail
{

template<class T>
void ExtObj(const json::Object& j, core::StringView field, T& data)
{
    const auto fieldName = field.data();
    if (j.HasMember(fieldName)) {
        data = JsonWorker<T>::Parse(j[fieldName]);
    }
}

template<class T>
void ExtObj(const json::Object& j, core::StringView field, core::Optional<T>& data)
{
    const auto fieldName = field.data();
    if (j.HasMember(fieldName) && j[fieldName].IsObject()) {
        data = JsonWorker<T>::Parse(j[fieldName]);
    }
}

template<class T>
void ExtSize(const json::Object& j, core::StringView field, T& data)
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
void ExtVecObj(const json::Object& j, core::StringView field, T& data)
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

template<class T>
void ExtKeywords(const json::Object& j, T& unit)
{
    core::String keywords;
    json::ExtStr(j, "keywords", keywords);
    unit.keywords = core::StrAlgo::Split(keywords);
}

void ExtContext(const json::Object& j, Context& c)
{
    json::ExtReqStr(j, "id", c.id);
    json::ExtStr(j, "name", c.name);
    json::ExtStr(j, "domain", c.domain);
    json::ExtVecStr(j, "cat", c.cat);
    json::ExtVecStr(j, "sectioncat", c.sectioncat);
    json::ExtVecStr(j, "pagecat", c.pagecat);
    json::ExtBool(j, "privacypolicy", c.privacypolicy);
    detail::ExtObj(j, "publisher", c.publisher);
    detail::ExtObj(j, "content", c.content);
    ExtKeywords(j, c);
}

}

Banner JsonWorker<Banner>::Parse(const json::Object& j)
{
    Banner b;

    detail::ExtSize(j, "w", b.w);
    detail::ExtSize(j, "h", b.h);
    json::ExtInt(j, "wmax", b.wmax);
    json::ExtInt(j, "hmax", b.hmax);
    json::ExtInt(j, "wmin", b.wmin);
    json::ExtInt(j, "hmin", b.hmin);
    json::ExtStr(j, "id", b.id);
    json::ExtVecEnum(j, "btype", b.btype);
    json::ExtVecEnum(j, "battr", b.battr);
    json::ExtEnum(j, "pos", b.pos);
    json::ExtVecStr(j, "mimes", b.mimes);
    json::ExtEnum(j, "topframe", b.topframe);
    json::ExtVecEnum(j, "expdir", b.expdir);
    json::ExtVecEnum(j, "api", b.api);

    return b;
}

Video JsonWorker<Video>::Parse(const json::Object& j)
{
    Video v;

    json::ExtVecStr(j, "mimes", v.mimes);
    json::ExtInt(j, "minduration", v.minduration);
    json::ExtInt(j, "maxduration", v.maxduration);
    json::ExtEnum(j, "protocol", v.protocol);
    json::ExtVecEnum(j, "protocols", v.protocols);
    json::ExtInt(j, "w", v.w);
    json::ExtInt(j, "h", v.h);
    json::ExtEnum(j, "startdelay", v.startdelay);
    json::ExtEnum(j, "linearity", v.linearity);
    json::ExtInt(j, "sequence", v.sequence);
    json::ExtVecEnum(j, "battr", v.battr);
    json::ExtInt(j, "maxextended", v.maxextended);
    json::ExtInt(j, "minbitrate", v.minbitrate);
    json::ExtInt(j, "maxbitrate", v.maxbitrate);
    json::ExtBool(j, "boxingallowed", v.boxingallowed);
    json::ExtVecEnum(j, "playbackmethod", v.playbackmethod);
    json::ExtVecEnum(j, "delivery", v.delivery);
    json::ExtEnum(j, "pos", v.pos);
    detail::ExtVecObj(j, "companionad", v.companionad);
    json::ExtVecEnum(j, "api", v.api);
    json::ExtVecEnum(j, "companiontype", v.companiontype);

    return v;
}

Native JsonWorker<Native>::Parse(const json::Object& j)
{
    Native n;

    json::ExtReqStr(j, "request", n.request);
    json::ExtStr(j, "ver", n.ver);
    json::ExtVecEnum(j, "api", n.api);
    json::ExtVecEnum(j, "battr", n.battr);

    return n;
}

Publisher JsonWorker<Publisher>::Parse(const json::Object& j)
{
    Publisher p;

    json::ExtStr(j, "id", p.id);
    json::ExtStr(j, "name", p.name);
    json::ExtVecStr(j, "cat", p.cat);
    json::ExtStr(j, "domain", p.domain);

    return p;
}

Content JsonWorker<Content>::Parse(const json::Object& j)
{
    Content c;

    json::ExtStr(j, "id", c.id);
    json::ExtInt(j, "episode", c.episode);
    json::ExtStr(j, "title", c.title);
    json::ExtStr(j, "series", c.series);
    json::ExtStr(j, "season", c.season);
    detail::ExtObj(j, "producer", c.producer);
    json::ExtStr(j, "url", c.url);
    json::ExtVecStr(j, "cat", c.cat);
    json::ExtEnum(j, "videoquality", c.videoquality);
    json::ExtEnum(j, "context", c.context);
    json::ExtStr(j, "contentrating", c.contentrating);
    json::ExtStr(j, "userrating", c.userrating);
    json::ExtEnum(j, "qagmediarating", c.qagmediarating);
    detail::ExtKeywords(j, c);
    json::ExtBool(j, "livestream", c.livestream);
    json::ExtEnum(j, "sourcerelationship", c.sourcerelationship);
    json::ExtInt(j, "len", c.len);
    json::ExtStr(j, "language", c.language);
    json::ExtBool(j, "embeddable", c.embeddable);

    return c;
}

Site JsonWorker<Site>::Parse(const json::Object& j)
{
    Site s;

    detail::ExtContext(j, s);
    json::ExtStr(j, "page", s.page);
    json::ExtStr(j, "ref", s.ref);
    json::ExtStr(j, "search", s.search);
    json::ExtBool(j, "mobile", s.mobile);

    return s;
}

App JsonWorker<App>::Parse(const json::Object& j)
{
    App a;

    detail::ExtContext(j, a);
    json::ExtStr(j, "bundle", a.bundle);
    json::ExtStr(j, "storeurl", a.storeurl);
    json::ExtStr(j, "ver", a.ver);
    json::ExtBool(j, "paid", a.paid);

    return a;
}

Geo JsonWorker<Geo>::Parse(const json::Object& j)
{
    Geo g;

    json::ExtDouble(j, "lat", g.lat);
    json::ExtDouble(j, "lon", g.lon);
    json::ExtEnum(j, "type", g.type);
    json::ExtStr(j, "country", g.country);
    json::ExtStr(j, "region", g.region);
    json::ExtStr(j, "regionfips104", g.regionfips104);
    json::ExtStr(j, "metro", g.metro);
    json::ExtStr(j, "city", g.city);
    json::ExtStr(j, "zip", g.zip);
    json::ExtInt(j, "utcoffset", g.utcoffset);

    return g;
}

Device JsonWorker<Device>::Parse(const json::Object& j)
{
    Device d;

    json::ExtStr(j, "ua", d.ua);
    detail::ExtObj(j, "geo", d.geo);
    json::ExtBool(j, "dnt", d.dnt);
    json::ExtBool(j, "lmt", d.lmt);
    json::ExtStr(j, "ip", d.ip);
    json::ExtStr(j, "ipv6", d.ipv6);
    json::ExtEnum(j, "devicetype", d.devicetype);
    json::ExtStr(j, "make", d.make);
    json::ExtStr(j, "model", d.model);
    json::ExtStr(j, "os", d.os);
    json::ExtStr(j, "osv", d.osv);
    json::ExtStr(j, "hwv", d.hwv);
    json::ExtInt(j, "h", d.h);
    json::ExtInt(j, "w", d.w);
    json::ExtInt(j, "ppi", d.ppi);
    json::ExtDouble(j, "pxratio", d.pxratio);
    json::ExtBool(j, "js", d.js);
    json::ExtStr(j, "flashver", d.flashver);
    json::ExtStr(j, "language", d.language);
    json::ExtStr(j, "carrier", d.carrier);
    json::ExtEnum(j, "connectiontype", d.connectiontype);
    json::ExtStr(j, "ifa", d.ifa);
    json::ExtStr(j, "didsha1", d.didsha1);
    json::ExtStr(j, "didmd5", d.didmd5);
    json::ExtStr(j, "dpidsha1", d.dpidsha1);
    json::ExtStr(j, "dpidmd5", d.dpidmd5);
    json::ExtStr(j, "macsha1", d.macsha1);
    json::ExtStr(j, "macmd5", d.macmd5);

    return d;
}

Segment JsonWorker<Segment>::Parse(const json::Object& j)
{
    Segment s;

    json::ExtStr(j, "id", s.id);
    json::ExtStr(j, "name", s.name);
    json::ExtStr(j, "value", s.value);

    return s;
}

Data JsonWorker<Data>::Parse(const json::Object& j)
{
    Data d;

    json::ExtStr(j, "id", d.id);
    json::ExtStr(j, "name", d.name);
    detail::ExtVecObj(j, "segment", d.segment);

    return d;
}

User JsonWorker<User>::Parse(const json::Object& j)
{
    User u;

    json::ExtStr(j, "id", u.id);
    json::ExtStr(j, "buyerid", u.buyerid);
    json::ExtInt(j, "yob", u.yob);
    json::ExtStr(j, "gender", u.gender);
    detail::ExtKeywords(j, u);
    json::ExtStr(j, "customdata", u.customdata);
    detail::ExtObj(j, "geo", u.geo);
    detail::ExtVecObj(j, "data", u.data);

    return u;
}

Deal JsonWorker<Deal>::Parse(const json::Object& j)
{
    Deal d;

    json::ExtReqStr(j, "id", d.id);
    json::ExtDouble(j, "bidfloor", d.bidfloor);
    json::ExtStr(j, "bidfloorcur", d.bidfloorcur);
    json::ExtEnum(j, "at", d.at);
    json::ExtVecStr(j, "wseat", d.wseat);
    json::ExtVecStr(j, "wadomain", d.wadomain);

    return d;
}

Pmp JsonWorker<Pmp>::Parse(const json::Object& j)
{
    Pmp p;

    json::ExtBool(j, "private_auction", p.private_auction);
    detail::ExtVecObj(j, "deals", p.deals);

    return p;
}

Impression JsonWorker<Impression>::Parse(const json::Object& j)
{
    Impression i;

    json::ExtReqStr(j, "id", i.id);
    detail::ExtObj(j, "banner", i.banner);
    detail::ExtObj(j, "video", i.video);
    detail::ExtObj(j, "native", i.native);
    json::ExtStr(j, "displaymanager", i.displaymanager);
    json::ExtStr(j, "displaymanagerver", i.displaymanagerver);
    json::ExtBool(j, "instl", i.instl);
    json::ExtStr(j, "tagid", i.tagid);
    json::ExtDouble(j, "bidfloor", i.bidfloor);
    json::ExtStr(j, "bidfloorcur", i.bidfloorcur);
    json::ExtInt(j, "secure", i.secure);
    json::ExtVecStr(j, "iframebuster", i.iframebuster);
    detail::ExtObj(j, "pmp", i.pmp);

    return i;
}

BidRequest JsonWorker<BidRequest>::Parse(const json::Object& j)
{
    BidRequest br;

    json::ExtReqStr(j, "id", br.id);
    detail::ExtVecObj(j, "imp", br.imp);
    detail::ExtObj(j, "site", br.site);
    detail::ExtObj(j, "app", br.app);
    detail::ExtObj(j, "device", br.device);
    detail::ExtObj(j, "user", br.user);
    json::ExtBool(j, "test", br.test);
    json::ExtEnum(j, "at", br.at);
    json::ExtInt(j, "tmax", br.tmax);
    json::ExtVecStr(j, "wseat", br.wseat);
    json::ExtBool(j, "allimps", br.allimps);
    json::ExtVecStr(j, "cur", br.cur);
    json::ExtVecStr(j, "bcat", br.bcat);
    json::ExtVecStr(j, "badv", br.badv);

    return br;
}

}
