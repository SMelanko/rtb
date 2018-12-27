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

void ExtContext(const Json::Object& j, Context& c)
{
    Json::ExtReqStr(j, "id", c.id);
    Json::ExtStr(j, "name", c.name);
    Json::ExtStr(j, "domain", c.domain);
    Json::ExtVecStr(j, "cat", c.cat);
    Json::ExtVecStr(j, "sectioncat", c.sectioncat);
    Json::ExtVecStr(j, "pagecat", c.pagecat);
    Json::ExtBool(j, "privacypolicy", c.privacypolicy);
    Detail::ExtObj(j, "publisher", c.publisher);
    Detail::ExtObj(j, "content", c.content);
    Json::ExtStr(j, "keywords", c.keywords);
}

}

Banner JsonWorker<Banner>::Parse(const Json::Object& j)
{
    Banner b;

    Detail::ExtSize(j, "w", b.w);
    Detail::ExtSize(j, "h", b.h);
    Json::ExtInt(j, "wmax", b.wmax);
    Json::ExtInt(j, "hmax", b.hmax);
    Json::ExtInt(j, "wmin", b.wmin);
    Json::ExtInt(j, "hmin", b.hmin);
    Json::ExtStr(j, "id", b.id);
    Json::ExtVecEnum(j, "btype", b.btype);
    Json::ExtVecEnum(j, "battr", b.battr);
    Json::ExtEnum(j, "pos", b.pos);
    Json::ExtVecStr(j, "mimes", b.mimes);
    Json::ExtEnum(j, "topframe", b.topframe);
    Json::ExtVecEnum(j, "expdir", b.expdir);
    Json::ExtVecEnum(j, "api", b.api);

    return b;
}

Video JsonWorker<Video>::Parse(const Json::Object& j)
{
    Video v;

    Json::ExtVecStr(j, "mimes", v.mimes);
    Json::ExtInt(j, "minduration", v.minduration);
    Json::ExtInt(j, "maxduration", v.maxduration);
    Json::ExtEnum(j, "protocol", v.protocol);
    Json::ExtVecEnum(j, "protocols", v.protocols);
    Json::ExtInt(j, "w", v.w);
    Json::ExtInt(j, "h", v.h);
    Json::ExtEnum(j, "startdelay", v.startdelay);
    Json::ExtEnum(j, "linearity", v.linearity);
    Json::ExtInt(j, "sequence", v.sequence);
    Json::ExtVecEnum(j, "battr", v.battr);
    Json::ExtInt(j, "maxextended", v.maxextended);
    Json::ExtInt(j, "minbitrate", v.minbitrate);
    Json::ExtInt(j, "maxbitrate", v.maxbitrate);
    Json::ExtBool(j, "boxingallowed", v.boxingallowed);
    Json::ExtVecEnum(j, "playbackmethod", v.playbackmethod);
    Json::ExtVecEnum(j, "delivery", v.delivery);
    Json::ExtEnum(j, "pos", v.pos);
    Detail::ExtVecObj(j, "companionad", v.companionad);
    Json::ExtVecEnum(j, "api", v.api);
    Json::ExtVecEnum(j, "companiontype", v.companiontype);

    return v;
}

Native JsonWorker<Native>::Parse(const Json::Object& j)
{
    Native n;

    Json::ExtReqStr(j, "request", n.request);
    Json::ExtStr(j, "ver", n.ver);
    Json::ExtVecEnum(j, "api", n.api);
    Json::ExtVecEnum(j, "battr", n.battr);

    return n;
}

Publisher JsonWorker<Publisher>::Parse(const Json::Object& j)
{
    Publisher p;

    Json::ExtStr(j, "id", p.id);
    Json::ExtStr(j, "name", p.name);
    Json::ExtVecStr(j, "cat", p.cat);
    Json::ExtStr(j, "domain", p.domain);

    return p;
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
    Site s;

    Detail::ExtContext(j, s);
    Json::ExtStr(j, "page", s.page);
    Json::ExtStr(j, "ref", s.ref);
    Json::ExtStr(j, "search", s.search);
    Json::ExtBool(j, "mobile", s.mobile);

    return s;
}

App JsonWorker<App>::Parse(const Json::Object& j)
{
    App a;

    Detail::ExtContext(j, a);
    Json::ExtStr(j, "bundle", a.bundle);
    Json::ExtStr(j, "storeurl", a.storeurl);
    Json::ExtStr(j, "ver", a.ver);
    Json::ExtBool(j, "paid", a.paid);

    return a;
}

Deal JsonWorker<Deal>::Parse(const Json::Object& j)
{
    Deal d;

    Json::ExtReqStr(j, "id", d.id);
    Json::ExtDouble(j, "bidfloor", d.bidfloor);
    Json::ExtStr(j, "bidfloorcur", d.bidfloorcur);
    Json::ExtEnum(j, "at", d.at);
    Json::ExtVecStr(j, "wseat", d.wseat);
    Json::ExtVecStr(j, "wadomain", d.wadomain);

    return d;
}

Pmp JsonWorker<Pmp>::Parse(const Json::Object& j)
{
    Pmp p;

    Json::ExtInt(j, "private_auction", p.private_auction);
    Detail::ExtVecObj(j, "deals", p.deals);

    return p;
}

Impression JsonWorker<Impression>::Parse(const Json::Object& j)
{
    Impression i;

    Json::ExtReqStr(j, "id", i.id);
    Detail::ExtObj(j, "banner", i.banner);
    Detail::ExtObj(j, "video", i.video);
    Detail::ExtObj(j, "native", i.native);
    Json::ExtStr(j, "displaymanager", i.displaymanager);
    Json::ExtStr(j, "displaymanagerver", i.displaymanagerver);
    Json::ExtInt(j, "instl", i.instl);
    Json::ExtStr(j, "tagid", i.tagid);
    Json::ExtDouble(j, "bidfloor", i.bidfloor);
    Json::ExtStr(j, "bidfloorcur", i.bidfloorcur);
    Json::ExtInt(j, "secure", i.secure);
    Json::ExtVecStr(j, "iframebuster", i.iframebuster);
    Detail::ExtObj(j, "pmp", i.pmp);

    return i;
}

BidRequest JsonWorker<BidRequest>::Parse(const Json::Object& j)
{
    BidRequest br;

    Json::ExtReqStr(j, "id", br.id);
    Detail::ExtVecObj(j, "imp", br.imp);
    Detail::ExtObj(j, "site", br.site);
    Detail::ExtObj(j, "app", br.app);
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
