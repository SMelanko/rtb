#include "proto/Parser2Point3.hpp"

namespace Detail
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
    if (j.HasMember(fieldName)) {
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

void ExtContext(const json::Object& j, Context& c)
{
    json::ExtReqStr(j, "id", c.id);
    json::ExtStr(j, "name", c.name);
    json::ExtStr(j, "domain", c.domain);
    json::ExtVecStr(j, "cat", c.cat);
    json::ExtVecStr(j, "sectioncat", c.sectioncat);
    json::ExtVecStr(j, "pagecat", c.pagecat);
    json::ExtBool(j, "privacypolicy", c.privacypolicy);
    Detail::ExtObj(j, "publisher", c.publisher);
    Detail::ExtObj(j, "content", c.content);
    json::ExtStr(j, "keywords", c.keywords);
}

}

Banner JsonWorker<Banner>::Parse(const json::Object& j)
{
    Banner b;

    Detail::ExtSize(j, "w", b.w);
    Detail::ExtSize(j, "h", b.h);
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
    Detail::ExtVecObj(j, "companionad", v.companionad);
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
    Detail::ExtObj(j, "producer", c.producer);
    json::ExtStr(j, "url", c.url);
    json::ExtVecStr(j, "cat", c.cat);
    json::ExtEnum(j, "videoquality", c.videoquality);
    json::ExtEnum(j, "context", c.context);
    json::ExtStr(j, "contentrating", c.contentrating);
    json::ExtStr(j, "userrating", c.userrating);
    json::ExtEnum(j, "qagmediarating", c.qagmediarating);
    json::ExtVecStr(j, "keywords", c.keywords);
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

    Detail::ExtContext(j, s);
    json::ExtStr(j, "page", s.page);
    json::ExtStr(j, "ref", s.ref);
    json::ExtStr(j, "search", s.search);
    json::ExtBool(j, "mobile", s.mobile);

    return s;
}

App JsonWorker<App>::Parse(const json::Object& j)
{
    App a;

    Detail::ExtContext(j, a);
    json::ExtStr(j, "bundle", a.bundle);
    json::ExtStr(j, "storeurl", a.storeurl);
    json::ExtStr(j, "ver", a.ver);
    json::ExtBool(j, "paid", a.paid);

    return a;
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

    json::ExtInt(j, "private_auction", p.private_auction);
    Detail::ExtVecObj(j, "deals", p.deals);

    return p;
}

Impression JsonWorker<Impression>::Parse(const json::Object& j)
{
    Impression i;

    json::ExtReqStr(j, "id", i.id);
    Detail::ExtObj(j, "banner", i.banner);
    Detail::ExtObj(j, "video", i.video);
    Detail::ExtObj(j, "native", i.native);
    json::ExtStr(j, "displaymanager", i.displaymanager);
    json::ExtStr(j, "displaymanagerver", i.displaymanagerver);
    json::ExtInt(j, "instl", i.instl);
    json::ExtStr(j, "tagid", i.tagid);
    json::ExtDouble(j, "bidfloor", i.bidfloor);
    json::ExtStr(j, "bidfloorcur", i.bidfloorcur);
    json::ExtInt(j, "secure", i.secure);
    json::ExtVecStr(j, "iframebuster", i.iframebuster);
    Detail::ExtObj(j, "pmp", i.pmp);

    return i;
}

BidRequest JsonWorker<BidRequest>::Parse(const json::Object& j)
{
    BidRequest br;

    json::ExtReqStr(j, "id", br.id);
    Detail::ExtVecObj(j, "imp", br.imp);
    Detail::ExtObj(j, "site", br.site);
    Detail::ExtObj(j, "app", br.app);
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
