#pragma once

#include "proto/OpenRtbRef.hpp"

/*
 * 3.2.3 Object: Banner
 *
 * This object represents the most general type of impression. Although the term “banner” may have very specific meaning
 * in other contexts, here it can be many things including a simple static image, an expandable ad unit, or even
 * in-banner video (refer to the Video object in Section 3.2.4 for the more generalized and full featured video ad units).
 * An array of Banner objects can also appear within the Video to describe Core::Optional companion ads defined in the VAST
 * specification.
 * The presence of a Banner as a subordinate of the Imp object indicates that this impression is offered as a banner
 * type impression. At the publisher’s discretion, that same impression may also be offered as video and/or native by
 * also including as Imp subordinates the Video and/or Native objects, respectively. However, any given bid for
 * the impression must conform to one of the offered types.
 */

struct Banner
{
public:
    /// Width of the impression in pixels. If neither wmin nor wmax are specified,
    /// this value is an exact width requirement. Otherwise it is a preferred width.
    Core::Vector<Core::Int> w;
    /// Height of the impression in pixels. If neither hmin nor hmax are specified,
    /// this value is an exact height requirement. Otherwise it is a preferred height.
    Core::Vector<Core::Int> h;
    /// Maximum width of the impression in pixels. If included along with a w value
    /// then w should be Core::Interpreted as a recommended or preferred width.
    Core::Int wmax;
    /// Maximum height of the impression in pixels. If included along with an h value
    /// then h should be Core::Interpreted as a recommended or preferred height.
    Core::Int hmax;
    /// Minimum width of the impression in pixels. If included along with a w value
    /// then w should be Core::Interpreted as a recommended or preferred width.
    Core::Int wmin;
    /// Minimum height of the impression in pixels. If included along with an h value
    /// then h should be Core::Interpreted as a recommended or preferred height.
    Core::Int hmin;
    /// Unique identifier for this banner object. Recommended when Banner objects are used with a Video object
    /// (Section 3.2.4) to represent an array of companion ads. Values usually start at 1 and increase with each object;
    /// should be unique within an impression.
    Core::String id;
    /// Blocked banner ad types.
    Core::Vector<BannerAdType> btype;
    /// Blocked creative attributes.
    Core::Vector<CreativeAttribute> battr;
    /// Ad position on screen.
    AdPosition pos;
    /// Content MIME types supported. Popular MIME types may include “application/x-shockwave-flash”,
    /// “image/jpg”, and “image/gif”.
    Core::Vector<MimeType> mimes;
    /// Indicates if the banner is in the top frame as opposed to an iframe, where 0 = no, 1 = yes.
    FramePosition topframe;
    /// Directions in which the banner may expand.
    Core::Vector<ExpandableDirection> expdir;
    /// Core::Vector of supported API frameworks for this impression. If an API is not explicitly Core::Vectored,
    /// it is assumed not to be supported.
    Core::Vector<ApiFramework> api;
    /// Placeholder for exchange-specific extensions to OpenRTB.
    Core::Json ext;
};

/*
 * 3.2.18 Object: Deal
 *
 * This object constitutes a specific deal that was struck a priori between a buyer and a seller. Its presence
 * with the Pmp collection indicates that this impression is available under the terms of that deal. Refer to
 * Section 7.2 for more details.
 */

struct Deal
{
    /// A unique identifier for the direct deal.
    Core::String id;
    /// Minimum bid for this impression expressed in CPM.
    Core::Double bidfloor = 0.0;
    /// Currency specified using ISO-4217 alpha codes. This may be different from bid currency returned by bidder
    /// if this is allowed by the exchange.
    Core::String bidfloorcur = "USD";
    /// Core::Optional override of the overall auction type of the bid request, where
    /// 1 = First Price, 2 = Second Price Plus, 3 = the value passed in bidfloor is the agreed upon deal price.
    /// Additional auction types can be defined by the exchange.
    Core::Int at;
    /// WhiteCore::Vector of buyer seats allowed to bid on this deal. Seat IDs must be communicated between bidders and
    /// the exchange a priori. Omission implies no seat restrictions.
    Core::Vector<Core::String> wseat;
    /// Array of advertiser domains (e.g., advertiser.com) allowed to bid on this deal.
    /// Omission implies no advertiser restrictions.
    Core::Vector<Core::String> wadomain;
    /// Placeholder for exchange-specific extensions to OpenRTB.
    Core::Json ext;
};

/*
 * 3.2.17 Object: Pmp
 *
 * This object is the private marketplace container for direct deals between buyers and sellers that may
 * pertain to this impression. The actual deals are represented as a collection of Deal objects. Refer to
 * Section 7.2 for more details.
 */

struct Pmp
{
    /// Indicator of auction eligibility to seats named in the Direct Deals object,
    /// where 0 = all bids are accepted, 1 = bids are restricted to the deals specified and the terms thereof.
    Core::Int private_auction;
    /// Array of Deal (Section 3.2.18) objects that convey the specific deals applicable to this impression.
    Core::Vector<Deal> deals;
    /// Placeholder for exchange-specific extensions to OpenRTB.
    Core::Json ext;
};

/*
 * 3.2.2 Object: Imp
 *
 * This object describes an ad placement or impression being auctioned. A single bid request can include
 * multiple Imp objects, a use case for which might be an exchange that supports selling all ad positions on
 * a given page. Each Imp object has a required ID so that bids can reference them individually.
 * The presence of Banner (Section 3.2.3), Video (Section 3.2.4), and/or Native (Section 3.2.5) objects
 * subordinate to the Imp object indicates the type of impression being offered. The publisher can choose
 * one such type which is the typical case or mix them at their discretion. However, any given bid for the
 * impression must conform to one of the offered types.
 */

struct Impression
{
    /// A unique identifier for this impression within the context of the bid request.
    Core::String id;
    /// A Banner object (Section 3.2.3); required if this impression is offered as a banner ad opportunity.
    Core::Opt<Banner> banner;
#if 0
    /// A Video object (Section 3.2.4); required if this impression is offered as a video ad opportunity.
    Core::Opt<Video> video;
    /// A Native object (Section 3.2.5); required if this impression is offered as a native ad opportunity.
    Core::Opt<Native> native;
#endif
    /// Name of ad mediation partner, SDK technology, or player responsible for rendering ad (typically video or mobile).
    /// Used by some ad servers to customize ad code by partner. Recommended for video and/or apps.
    Core::String displaymanager;
    /// Version of ad mediation partner, SDK technology, or player responsible for rendering ad (typically video or mobile).
    /// Used by some ad servers to customize ad code by partner. Recommended for video and/or apps.
    Core::String displaymanagerver;
    /// 1 = the ad is Core::Interstitial or full screen, 0 = not Core::Interstitial.
    Core::Int instl = 0;
    /// Identifier for specific ad placement or ad tag that was used to initiate the auction.
    /// This can be useful for debugging of any issues, or for Core::Optimization by the buyer.
    Core::String tagid;
    /// Minimum bid for this impression expressed in CPM.
    Core::Double bidfloor = 0.0;
    /// Currency specified using ISO-4217 alpha codes. This may be different from bid currency returned by bidder
    /// if this is allowed by the exchange.
    Core::String bidfloorcur = "USD";
    /// Flag to indicate if the impression requires secure HTTPS URL creative assets and markup,
    /// where 0 = non-secure, 1 = secure. If omitted, the secure state is unknown,
    /// but non-secure HTTP support can be assumed.
    Core::Int secure;
    /// Array of exchange-specific names of supported iframe busters.
    Core::Vector<Core::String> iframebuster;
    /// A Pmp object (Section 3.2.17) containing any private marketplace deals in effect for this impression.
    Core::Opt<Pmp> pmp;
    /// Placeholder for exchange-specific extensions to OpenRTB.
    Core::Json ext;
};
