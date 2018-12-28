#pragma once

#include <core/json/Json.hpp>
#include <core/stl/Optional.hpp>
#include <core/stl/String.hpp>
#include <core/stl/Vector.hpp>

namespace proto
{

/*
 * 5.2 Banner Ad Types
 *
 * The following table indicates the types of ads that can be accepted by the exchange unless restricted
 * by publisher site settings.
 */

enum class BannerAdType
{
    /// Not explicitly specified.
    NONE = -1,
    /// XHTML Text Ad (usually mobile).
    XHTML_TEXT = 1,
    /// XHTML Banner Ad (usually mobile).
    XHTML_BANNER = 2,
    /// JavaScript Ad; must be valid XHTML (i.e., Script Tags Included).
    JAVASCRIPT = 3,
    /// Iframe.
    IFRAME = 4
};

/*
 * 5.3 Creative Attributes
 *
 * The following table specifies a standard list of creative attributes that can describe an ad being served
 * or serve as restrictions of thereof.
 */

enum class CreativeAttribute
{
    /// Not explicitly specified.
    NONE = -1,
    /// Audio Ad (Auto-Play).
    AUDIO_AD_AUTO_PLAY = 1,
    /// Audio Ad (User Initiated).
    AUDIO_AD_USER_INITIATED = 2,
    /// Expandable (Automatic).
    EXPANDABLE_AUTOMATIC = 3,
    /// Expandable (User Initiated - Click).
    EXPANDABLE_USER_INITIATED_CLICK = 4,
    /// Expandable (User Initiated - Rollover).
    EXPANDABLE_USER_INITIATED_ROLLOVER = 5,
    /// In-Banner Video Ad (Auto-Play).
    IN_BANNER_VIDEO_AD_AUTO_PLAY = 6,
    /// In-Banner Video Ad (User Initiated).
    IN_BANNER_VIDEO_AD_USER_INITIATED = 7,
    /// Pop (e.g., Over, Under, or Upon Exit).
    POP = 8,
    /// Provocative or Suggestive Imagery.
    PROVOCATIVE_OR_SUGGESTIVE_IMAGERY = 9,
    /// Shaky, Flashing, Flickering, Extreme Animation, Smileys.
    SHAKY_FLASHING_FLICKERING_EXTREME_ANIMATION_SMILEYS = 10,
    /// Surveys.
    SURVEYS = 11,
    /// Text Only.
    TEXT_ONLY = 12,
    /// User Interactive (e.g., Embedded Games).
    USER_INTERACTIVE = 13,
    /// Windows Dialog or Alert Style.
    WINDOWS_DIALOG_OR_ALERT_STYLE = 14,
    /// Has Audio On/Off Button.
    HAS_AUDIO_ON_OFF_BUTTON = 15,
    /// Ad Can be Skipped (e.g., Skip Button on Pre-Roll Video).
    AD_CAN_BE_SKIPPED = 16
};

/*
 * 5.4 Ad Position
 *
 * The following table specifies the position of the ad as a relative measure of visibility or prominence.
 * This OpenRTB table has values derived from the IAB Quality Assurance Guidelines (QAG). Practitioners
 * should keep in sync with updates to the QAG values as published on IAB.net. Values “3” – “6” apply to
 * apps per the mobile addendum to QAG version 1.5.
 */

enum class AdPosition
{
    /// Not explicitly specified.
    NONE = -1,
    /// Unknown.
    UNKNOWN = 0,
    /// Above the Fold.
    ABOVE = 1,
    /// DEPRECATED - May or may not be initially visible depending on screen size/resolution.
    BETWEEN_DEPRECATED = 2,
    /// Below the Fold.
    BELOW = 3,
    /// Header.
    HEADER = 4,
    /// Footer.
    FOOTER = 5,
    /// Sidebar.
    SIDEBAR = 6,
    /// Full Screen.
    FULLSCREEN = 7
};

/*
 * A media type (formerly known as MIME type) is a two-part identifier for file formats and format contents
 * transmitted on the Internet. For example, application/javascript.
 */

struct MimeType
{
public:
    explicit MimeType(core::String type = "")
        : type{ std::move(type) }
    {
    }

public:
    core::String type;
};

/*
 * Frame Position
 *
 * Indicates if the banner is in the top frame as opposed to an iframe, where 0 = no, 1 = yes.
 */

enum class FramePosition
{
    /// Not explicitly specified.
    NONE = -1,
    /// Iframe.
    IFRAME = 0,
    /// Top frame.
    TOP_FRAME = 1
};

/*
 * 5.5 Expandable Direction
 *
 * The following table lists the directions in which an expandable ad may expand, given the positioning of
 * the ad unit on the page and constraints imposed by the content.
 */

enum class ExpandableDirection
{
    /// Not explicitly specified.
    NONE = -1,
    /// Left.
    LEFT = 1,
    /// Right.
    RIGHT = 2,
    /// Up.
    UP = 3,
    /// Down.
    DOWN = 4,
    /// Full screen.
    FULLSCREEN = 5
};

/*
 * 5.6 API Frameworks
 *
 * The following table is a list of API frameworks supported by the publisher. Note that MRAID-1 is
 * a subset of MRAID-2. In OpenRTB 2.1 and prior, value “3” was “MRAID”. However, not all MRAID capable
 * APIs understand MRAID-2 features and as such the only safe interpretation of value “3” is MRAID-1.
 * In OpenRTB 2.2, this was made explicit and MRAID-2 has been added as value “5”.
 */

enum class ApiFramework
{
    /// Not explicitly specified.
    NONE = -1,
    /// IAB Video Player-Ad Interface Definitions V1.
    VPAID_1 = 1,
    /// IAB Video Player-Ad Interface Definitions V2.
    VPAID_2 = 2,
    /// IAB Mobile Rich Media Ad Interface Definitions.
    MRAID = 3,
    /// Google Open Rich Media Mobile Advertising.
    ORMMA = 4,
    /// IAB Mobile Rich Media Ad Interface Definitions V2.
    MRAID2 = 5
};

/*
 * 5.7 Video Linearity
 *
 * The following table indicates the options for video linearity. “In-stream” or “linear” video
 * refers to pre-roll, post-roll, or mid-roll video ads where the user is forced to watch ad
 * in order to see the video content. “Overlay” or “non-linear” refer to ads that are shown
 * on top of the video content.
 * This field is optional. The following is the interpretation of the bidder based upon the presence
 * or absence of the field in the bid request:
 *  - If no value is set, any ad (linear or not) can be present in the response.
 *  - If a value is set, only ads of the corresponding type can be present in the response.
 * Note to the reader: This OpenRTB table has values derived from the IAB Quality Assurance Guidelines
 * (QAG). Practitioners should keep in sync with updates to the QAG values as published on IAB.net.
 */

enum class VideoLinearity
{
    /// Not explicitly specified.
    NONE = -1,
    /// Linear / In-Stream.
    IN_STREAM = 1,
    /// Non-Linear / Overlay.
    OVERLAY = 2
};

/*
 * 5.8 Video Bid Response Protocols
 *
 * The following table lists the options for video bid response protocols that
 * could be supported by an exchange.
 */

enum class VideoBidResponseProtocol
{
    /// Not explicitly specified.
    NONE = -1,
    /// VAST 1.0.
    VAST1 = 1,
    /// VAST 2.0.
    VAST2 = 2,
    /// VAST 3.0.
    VAST3 = 3,
    /// VAST 1.0 Wrapper.
    VAST1_WRAPPER = 4,
    /// VAST 2.0 Wrapper.
    VAST2_WRAPPER = 5,
    /// VAST 3.0 Wrapper.
    VAST3_WRAPPER = 6
};

/*
 * 5.9 Video Playback Methods
 *
 * The following table lists the various video playback methods.
 */

enum class VideoPlaybackMethod
{
    /// Not explicitly specified.
    NONE = -1,
    /// Auto-Play Sound On.
    AUTO_PLAY_SOUND_ON = 1,
    /// Auto-Play Sound Off.
    AUTO_PLAY_SOUND_OFF = 2,
    /// Click-to-Play.
    CLICK_TO_PLAY = 3,
    /// Mouse-Over.
    MOUSE_OVER = 4
};

/*
 * 5.10 Video Start Delay
 *
 * The following table lists the various options for the video start delay. If the start delay value
 * is greater than 0, then the position is mid-roll and the value indicates the start delay.
 */

enum class VideoStartDelay
{
    /// Not explicitly specified.
    NONE = -3,
    /// Generic Post-Roll.
    GENERIC_POST_ROLL = -2,
    /// Generic Mid-Roll.
    GENERIC_MID_ROLL = -1,
    /// Pre-Roll.
    PRE_ROLL = 0
    /// > 0, Mid-Roll (value indicates start delay in second).
};

/*
 * 5.11 Video Quality
 *
 * The following table lists the options for the video quality.
 * These values are defined by the IAB – http://www.iab.net/media/file/long-form-video-final.pdf.
 */

enum class VideoQuality
{
    /// Not explicitly specified.
    NONE = -1,
    /// Unknown.
    UNKNOWN = 0,
    /// Professionally Produced.
    PROFESSIONAL = 1,
    /// Prosumer.
    PROSUMER = 2,
    /// User Generated (UGC).
    USER_GENERATED = 3
};

/*
 * 5.12 VAST Companion Types
 *
 * The following table lists the options to indicate markup types allowed for video companion ads.
 * This table is derived from IAB VAST 2.0+. Refer to www.iab.net/vast/ for more information.
 */

enum class VastCompanionType
{
    /// Not explicitly specified.
    NONE = -1,
    /// Static Resource.
    STATIC_RESOURCE = 1,
    /// HTML Resource.
    HTML_RESOURCE = 2,
    /// Iframe Resource.
    IFRAME_RESOURCE = 3
};

/*
 * 5.13 Content Delivery Methods
 *
 * The following table lists the various options for the delivery of video content.
 */

enum class ContentDeliveryMethod
{
    /// Not explicitly specified.
    NONE = -1,
    /// Streaming.
    STREAMING = 1,
    /// Progressive.
    PROGRESSIVE = 2
};

/*
 * 5.14 Content Context
 *
 * The following table lists the various options for indicating the type of content
 * in which the impression will appear.
 * This OpenRTB table has values derived from the IAB Quality Assurance Guidelines (QAG).
 * Practitioners should keep in sync with updates to the QAG values as published on IAB.net.
 */

enum class ContentContext
{
    /// Not explicitly specified.
    NONE = -1,
    /// Video (a video file or stream that is being watched by the user,
    /// including (Internet) television broadcasts).
    VIDEO = 1,
    /// Game (an interactive software game that is being played by the user).
    GAME = 2,
    /// Music (an audio file or stream that is being listened to by the user,
    /// including (Internet) radio broadcasts)
    MUSIC = 3,
    /// Application (an interactive software application that is being used by the user).
    APPLICATION = 4,
    /// Text (a document that is primarily textual in nature that is being read or viewed
    /// by the user, including web page, eBook, or news article).
    TEXT = 5,
    /// Other (content type unknown or the user is consuming content which does not fit
    /// into one of the categories above).
    OTHER = 6,
    /// Unknown.
    UNKNOWN = 7
};

/*
 * 5.15 QAG Media Ratings
 *
 * The following table lists the media ratings used in describing content based on
 * the QAG categorization. Refer to http://www.iab.net/ne_guidelines for more information.
 */

enum class MediaRating
{
    /// Not explicitly specified.
    NONE = -1,
    /// All audiences.
    ALL = 1,
    /// Everyone over 12.
    OVER_12 = 2,
    /// Mature audiences.
    MATURE = 3
};

/*
 * 5.16 Location Type
 *
 * The following table lists the options to indicate how the geographic information was determined.
 */

enum class LocationType
{
    /// Not explicitly specified.
    NONE = -1,
    /// GPS/Location Services.
    GPS = 1,
    /// IP Address.
    IP_ADDRESS = 2,
    /// User provided (e.g., registration data).
    USER = 3 
};

/*
 * Auction Price
 *
 * Optional override of the overall auction type of the bid request, where
 * 1 = First Price, 2 = Second Price Plus, 3 = the value passed in bidfloor is the agreed
 * upon deal price. Additional auction types can be defined by the exchange.
 */

enum class AuctionPrice
{
    /// Not explicitly specified.
    NONE = -1,
    /// First Price.
    FIRST_PRICE = 1,
    /// Second Price Plus.
    SECOND_PRICE_PLUS = 2,
    /// Agreed upon deal price.
    DEAL_PRICE = 3
};

/*
 * SourceRelationship
 */

enum class SourceRelationship
{
    /// Not explicitly specified.
    NONE = -1,
    /// Indirect
    INDIRECT = 0,
    /// Direct.
    DIRECT = 1
};

/*
 * 3.2.3 Object: Banner
 *
 * This object represents the most general type of impression. Although the term “banner” may have very specific meaning
 * in other contexts, here it can be many things including a simple static image, an expandable ad unit, or even
 * in-banner video (refer to the Video object in Section 3.2.4 for the more generalized and full featured video ad units).
 * An array of Banner objects can also appear within the Video to describe optional companion ads defined in the VAST
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
    core::Vector<core::Int> w;
    /// Height of the impression in pixels. If neither hmin nor hmax are specified,
    /// this value is an exact height requirement. Otherwise it is a preferred height.
    core::Vector<core::Int> h;
    /// Maximum width of the impression in pixels. If included along with a w value
    /// then w should be interpreted as a recommended or preferred width.
    core::Int wmax;
    /// Maximum height of the impression in pixels. If included along with an h value
    /// then h should be interpreted as a recommended or preferred height.
    core::Int hmax;
    /// Minimum width of the impression in pixels. If included along with a w value
    /// then w should be interpreted as a recommended or preferred width.
    core::Int wmin;
    /// Minimum height of the impression in pixels. If included along with an h value
    /// then h should be interpreted as a recommended or preferred height.
    core::Int hmin;
    /// Unique identifier for this banner object. Recommended when Banner objects are used with a Video object
    /// (Section 3.2.4) to represent an array of companion ads. Values usually start at 1 and increase with each object;
    /// should be unique within an impression.
    core::String id;
    /// Blocked banner ad types.
    core::Vector<BannerAdType> btype;
    /// Blocked creative attributes.
    core::Vector<CreativeAttribute> battr;
    /// Ad position on screen.
    AdPosition pos;
    /// Content MIME types supported. Popular MIME types may include “application/x-shockwave-flash”,
    /// “image/jpg”, and “image/gif”.
    core::Vector<MimeType> mimes;
    /// Indicates if the banner is in the top frame as opposed to an iframe, where 0 = no, 1 = yes.
    FramePosition topframe;
    /// Directions in which the banner may expand.
    core::Vector<ExpandableDirection> expdir;
    /// Core::Vector of supported API frameworks for this impression. If an API is not explicitly Core::Vectored,
    /// it is assumed not to be supported.
    core::Vector<ApiFramework> api;
};

/*
 * 3.2.4 Object: Video
 *
 * This object represents an in-stream video impression. Many of the fields are non-essential
 * for minimally viable transactions, but are included to offer fine control when needed.
 * Video in OpenRTB generally assumes compliance with the VAST standard. As such,
 * the notion of companion ads is supported by optionally including an array of Banner objects
 * (refer to the Banner object in Section 3.2.3) that define these companion ads.
 * The presence of a Video as a subordinate of the Imp object indicates that this impression is
 * offered as a video type impression. At the publisher’s discretion, that same impression may
 * also be offered as banner and/or native by also including as Imp subordinates the Banner and/or
 * Native objects, respectively. However, any given bid for the impression must conform to
 * one of the offered types.
 */

struct Video
{
public:
    /// Content MIME types supported. Popular MIME types may include “video/x-ms-wmv” for
    /// Windows Media and “video/x-flv” for Flash Video.
    core::Vector<MimeType> mimes;
    /// Minimum video ad duration in seconds.
    core::Int minduration;
    /// Maximum video ad duration in seconds.
    core::Int maxduration;
    /// Supported video bid response protocol. Refer to List 5.8. At least one supported protocol
    /// must be specified in either the protocol or protocols attribute.
    VideoBidResponseProtocol protocol;
    /// Array of supported video bid response protocols. Refer to List 5.8. At least one
    /// supported protocol must be specified in either the protocol or protocols attribute.
    core::Vector<VideoBidResponseProtocol> protocols;
    /// Width of the video player in pixels.
    core::Int w;
    /// Height of the video player in pixels.
    core::Int h;
    /// Indicates the start delay in seconds for pre-roll, mid-roll, or post-roll ad placements.
    /// Refer to List 5.10 for additional generic values.
    VideoStartDelay startdelay;
    /// Indicates if the impression must be linear, nonlinear, etc.
    /// If none specified, assume all are allowed. Refer to List 5.7.
    VideoLinearity linearity;
    /// If multiple ad impressions are offered in the same bid request, the sequence number
    /// will allow for the coordinated delivery of multiple creatives.
    core::Int sequence;
    /// Blocked creative attributes. Refer to List 5.3.
    core::Vector<CreativeAttribute> battr;
    /// Maximum extended video ad duration if extension is allowed.
    /// If blank or 0, extension is not allowed. If -1, extension is allowed, and there is no
    /// time limit imposed. If greater than 0, then the value represents the number of seconds
    /// of extended play supported beyond the maxduration value.
    core::Int maxextended = 0;
    /// Minimum bit rate in Kbps. Exchange may set this dynamically or universally
    /// across their set of publishers.
    core::Int minbitrate;
    /// Maximum bit rate in Kbps. Exchange may set this dynamically or universally
    /// across their set of publishers.
    core::Int maxbitrate;
    /// Indicates if letter-boxing of 4:3 content into a 16:9 window is allowed, where 0 = no, 1 = yes.
    core::Bool boxingallowed = true;
    /// Allowed playback methods. If none specified, assume all are allowed. Refer to List 5.9.
    core::Vector<VideoPlaybackMethod> playbackmethod;
    /// Supported delivery methods (e.g., streaming, progressive).
    /// If none specified, assume all are supported. Refer to List 5.13.
    core::Vector<ContentDeliveryMethod> delivery;
    /// Ad position on screen. Refer to List 5.4.
    AdPosition pos;
    /// Array of Banner objects (Section 3.2.3) if companion ads are available.
    core::Vector<Banner> companionad;
    /// List of supported API frameworks for this impression. Refer to List 5.6.
    /// If an API is not explicitly listed, it is assumed not to be supported.
    core::Vector<ApiFramework> api;
    /// Supported VAST companion ad types. Refer to List 5.12. Recommended
    /// if companion Banner objects are included via the companionad array.
    core::Vector<VastCompanionType> companiontype;
};

/*
 * 3.2.5 Object: Native
 *
 * This object represents a native type impression. Native ad units are intended to blend seamlessly
 * into the surrounding content (e.g., a sponsored Twitter or Facebook post). As such, the response
 * must be well-structured to afford the publisher fine-grained control over rendering.
 * The Native Subcommittee has developed a companion specification to OpenRTB called
 * the Native Ad Specification. It defines the request parameters and response markup
 * structure of native ad units. This object provides the means of transporting request parameters
 * as an opaque string so that the specific parameters can evolve separately under the auspices of
 * the Native Ad Specification. Similarly, the ad markup served will be structured according
 * to that specification.
 * The presence of a Native as a subordinate of the Imp object indicates that this impression is
 * offered as a native type impression. At the publisher’s discretion, that same impression
 * may also be offered as banner and/or video by also including as Imp subordinates the Banner
 * and/or Video objects, respectively. However, any given bid for the impression must conform to
 * one of the offered types.
 */

struct Native
{
public:
    /// Request payload complying with the Native Ad Specification.
    core::String request;
    /// Version of the Native Ad Specification to which request complies;
    /// highly recommended for efficient parsing.
    core::String ver;
    /// List of supported API frameworks for this impression. Refer to List 5.6.
    /// If an API is not explicitly listed, it is assumed not to be supported.
    core::Vector<ApiFramework> api;
    /// Blocked creative attributes. Refer to List 5.3.
    core::Vector<CreativeAttribute> battr;
};

/*
 * 3.2.8 Object: Publisher
 *
 * This object describes the publisher of the media in which the ad will be displayed.
 * The publisher is typically the seller in an OpenRTB transaction.
 */

struct Publisher
{
public:
    /// Exchange-specific publisher ID.
    core::String id;
    /// Publisher name (may be aliased at the publisher’s request).
    core::String name;
    /// Array of IAB content categories that describe the publisher. Refer to List 5.1.
    core::Vector<core::String> cat;
    /// Highest level domain of the publisher (e.g., “publisher.com”).
    core::String domain;
};

/*
 * 3.2.10 Object: Producer
 *
 * This object defines the producer of the content in which the ad will be shown.
 * This is particularly useful when the content is syndicated and may be distributed through
 * different publishers and thus when the producer and publisher are not necessarily the same entity.
 */

using Producer = Publisher;

/*
 * 3.2.9 Object: Content
 *
 * This object describes the content in which the impression will appear, which may be syndicated
 * or non-syndicated content. This object may be useful when syndicated content contains impressions
 * and does not necessarily match the publisher’s general content. The exchange might or might not
 * have knowledge of the page where the content is running, as a result of the syndication method.
 * For example might be a video impression embedded in an iframe on an unknown web property or device.
 */

struct Content
{
public:
    /// ID uniquely identifying the content.
    core::String id;
    /// Episode number (typically applies to video content).
    core::Int episode;
    /// Content title.
    /// Video Examples: “Search Committee” (TV), “A New Hope” (movie), or “Endgame” (made for web).
    /// Non-Video Example: “Why an Antarctic Glacier Is Melting So Quickly” (Time magazine article).
    core::String title;
    /// Content series.
    /// Video Examples: “The Office” (TV), “Star Wars” (movie), or “Arby ‘N’ The Chief” (made for web).
    /// Non-Video Example: “Ecocentric” (Time Magazine blog).
    core::String series;
    /// Content season; typically for video content (e.g., “Season 3”).
    core::String season;
    /// Details about the content Producer (Section 3.2.10).
    core::Optional<Producer> producer;
    /// URL of the content, for buy-side contextualization or review.
    core::String url; // TODO: URL
    /// Array of IAB content categories that describe the content producer. Refer to List 5.1.
    core::Vector<core::String> cat;
    /// Video quality per IAB’s classification. Refer to List 5.11.
    VideoQuality videoquality;
    /// Type of content (game, video, text, etc.). Refer to List 5.14.
    ContentContext context;
    /// Content rating (e.g., MPAA).
    core::String contentrating;
    /// User rating of the content (e.g., number of stars, likes, etc.).
    core::String userrating;
    /// Media rating per QAG guidelines. Refer to List 5.15.
    MediaRating qagmediarating;
    /// Comma separated list of keywords describing the content.
    core::Vector<core::String> keywords;
    /// 0 = not live, 1 = content is live (e.g., stream, live blog).
    core::Bool livestream;
    /// 0 = indirect, 1 = direct.
    SourceRelationship sourcerelationship;
    /// Length of content in seconds; appropriate for video or audio.
    core::Int len;
    /// Content language using ISO-639-1-alpha-2.
    core::String language;
    /// Indicator of whether or not the content is embeddable (e.g., an embeddable video player),
    /// where 0 = no, 1 = yes.
    core::Bool embeddable;
};

/*
 * Common data between a Site and App.
 */

struct Context
{
public:
    /// Exchange-specific site/app ID.
    core::String id;
    /// Site name (may be aliased at the publisher’s request).
    core::String name;
    /// Domain of the site/app (e.g., “mysite.foo.com”).
    core::String domain;
    /// Array of IAB content categories of the site/app. Refer to List 5.1.
    core::Vector<core::String> cat;
    /// Array of IAB content categories that describe the current section of the site/app.
    core::Vector<core::String> sectioncat;
    /// Array of IAB content categories that describe the current page or view of the site/app.
    core::Vector<core::String> pagecat;
    /// Indicates if the site/app has a privacy policy, where 0 = no, 1 = yes.
    core::Bool privacypolicy;
    /// Details about the Publisher (Section 3.2.8) of the site/app.
    core::Optional<Publisher> publisher;
    /// Details about the Content (Section 3.2.9) within the site/app.
    core::Optional<Content> content;
    /// Comma separated list of keywords about the site/app.
    core::String keywords;
};

/*
 * 3.2.6 Object: Site
 *
 * This object should be included if the ad supported content is a website as opposed to
 * a non-browser application. A bid request must not contain botha Site and an App object.
 * Ataminimum,itisuseful to provide a site ID or page URL, but this is not strictly required.
 */

struct Site : public Context
{
public:
    /// URL of the page where the impression will be shown.
    core::String page;
    /// Referrer URL that caused navigation to the current page.
    core::String ref;
    /// Search string that caused navigation to the current page.
    core::String search;
    /// Mobile-optimized signal, where 0 = no, 1 = yes.
    core::Bool mobile;
};

/*
 * 3.2.7 Object: App
 *
 * This object should be included if the ad supported content is a non-browser application
 * (typically in mobile) as opposed to a website. A bid request must not contain both
 * an App and a Site object. At a minimum, it is useful to provide an App ID or bundle,
 * but this is not strictly required.
 */

struct App : public Context
{
public:
    /// Application bundle or package name (e.g., com.foo.mygame);
    /// intended to be a unique ID across exchanges.
    core::String bundle;
    /// Application store URL for an installed app; for QAG 1.5 compliance.
    core::String storeurl;
    /// Application version.
    core::String ver;
    /// True if the application is a paid version, else - free.
    core::Bool paid;
};

/*
 * 3.3.11 Geo Object
 *
 * This object encapsulates various methods for specifying a geographic location.
 * When subordinate to a Device object, it indicates the location of the device which
 * can also be interpreted as the user’s current location. When subordinate to a User object,
 * it indicates the location of the user’s home base (i.e., not necessarily their current location).
 * The lat/lon attributes should only be passed if they conform to the accuracy depicted
 * in the type attribute. For example, the centroid of a geographic region such as postal code
 * should not be passed.
 */

struct Geo
{
public:
    /// Latitude from -90.0 to +90.0, where negative is south.
    core::Double lat;
    /// Longitude from -180.0 to +180.0, where negative is west.
    core::Double lon;
    /// Source of location data; recommended when passing lat/lon. Refer to List 5.16.
    LocationType type;
    /// Country code using ISO-3166-1-alpha-3.
    core::String country;
    /// Region code using ISO-3166-2; 2-letter state code if USA.
    core::String region;
    /// Region of a country using FIPS 10-4 notation. While OpenRTB supports this attribute,
    /// it has been withdrawn by NIST in 2008.
    core::String regionfips104;
    /// Google metro code; similar to but not exactly Nielsen DMAs.
    /// http://code.google.com/apis/adwords/docs/appendix/metrocodes.html
    core::String metro;
    /// City using United Nations Code for Trade & Transport Locations.
    /// http://code.google.com/apis/adwords/docs/appendix/metrocodes.html
    core::String metro;
    /// Zip or postal code.
    core::String zip;
    /// Local time as the number +/- of minutes from UTC.
    core::Int utcoffset;
};

/*
 * 3.2.18 Object: Deal
 *
 * This object constitutes a specific deal that was struck a priori between a buyer and a seller.
 * Its presence with the Pmp collection indicates that this impression is available under
 * the terms of that deal. Refer to Section 7.2 for more details.
 */

struct Deal
{
public:
    /// A unique identifier for the direct deal.
    core::String id;
    /// Minimum bid for this impression expressed in CPM.
    core::Double bidfloor = 0.0;
    /// Currency specified using ISO-4217 alpha codes. This may be different from bid currency returned by bidder
    /// if this is allowed by the exchange.
    core::String bidfloorcur = "USD";
    /// Optional override of the overall auction type of the bid request, where
    /// 1 = First Price, 2 = Second Price Plus, 3 = the value passed in bidfloor is the agreed upon deal price.
    /// Additional auction types can be defined by the exchange.
    AuctionPrice at;
    /// WhiteCore::Vector of buyer seats allowed to bid on this deal. Seat IDs must be communicated between bidders and
    /// the exchange a priori. Omission implies no seat restrictions.
    core::Vector<core::String> wseat;
    /// Array of advertiser domains (e.g., advertiser.com) allowed to bid on this deal.
    /// Omission implies no advertiser restrictions.
    core::Vector<core::String> wadomain;
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
public:
    /// Indicator of auction eligibility to seats named in the Direct Deals object,
    /// where 0 = all bids are accepted, 1 = bids are restricted to the deals specified and the terms thereof.
    core::Int private_auction;
    /// Array of Deal (Section 3.2.18) objects that convey the specific deals applicable to this impression.
    core::Vector<Deal> deals;
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
public:
    /// A unique identifier for this impression within the context of the bid request.
    core::String id;
    /// A Banner object (Section 3.2.3); required if this impression is offered as a banner ad opportunity.
    core::Optional<Banner> banner;
    /// A Video object (Section 3.2.4); required if this impression is offered as a video ad opportunity.
    core::Optional<Video> video;
    /// A Native object (Section 3.2.5); required if this impression is offered as a native ad opportunity.
    core::Optional<Native> native;
    /// Name of ad mediation partner, SDK technology, or player responsible for rendering ad (typically video or mobile).
    /// Used by some ad servers to customize ad code by partner. Recommended for video and/or apps.
    core::String displaymanager;
    /// Version of ad mediation partner, SDK technology or player responsible for rendering ad (typically video or mobile).
    /// Used by some ad servers to customize ad code by partner. Recommended for video and/or apps.
    core::String displaymanagerver;
    /// 1 = the ad is interstitial or full screen, 0 = not interstitial.
    core::Int instl = 0;
    /// Identifier for specific ad placement or ad tag that was used to initiate the auction.
    /// This can be useful for debugging of any issues, or for Core::Optimization by the buyer.
    core::String tagid;
    /// Minimum bid for this impression expressed in CPM.
    core::Double bidfloor = 0.0;
    /// Currency specified using ISO-4217 alpha codes. This may be different from bid currency returned by bidder
    /// if this is allowed by the exchange.
    core::String bidfloorcur = "USD";
    /// Flag to indicate if the impression requires secure HTTPS URL creative assets and markup, where
    /// 0 = non-secure, 1 = secure. If omitted, the secure state is unknown, but non-secure HTTP support can be assumed.
    core::Int secure;
    /// Array of exchange-specific names of supported iframe busters.
    core::Vector<core::String> iframebuster;
    /// A Pmp object (Section 3.2.17) containing any private marketplace deals in effect for this impression.
    core::Optional<Pmp> pmp;
};

/*
 * 3.2.1 Object: BidRequest
 *
 * The top-level bid request object contains a globally unique bid request or auction ID. This id attribute
 * is required as is at least one impression object (Section 3.2.2). Other attributes in this top-level object
 * establish rules and restrictions that apply to all impressions being offered.
 * There are also several subordinate objects that provide detailed data to potential buyers. Among these are
 * the Site and App objects, which describe the type of published media in which the impression(s) appear.
 * These objects are highly recommended, but only one applies to a given bid request depending on
 * whether the media is browser-based web content or a non-browser application, respectively.
 */

struct BidRequest
{
public:
    /// Unique ID of the bid request, provided by the exchange.
    core::String id;
    /// Array of Imp objects (Section 3.2.2) representing the impressions offered. At least 1 Imp object is required.
    core::Vector<Impression> imp;
    /// Details via a Site object (Section 3.2.6) about the publisher’s website.
    /// Only applicable and recommended for websites.
    core::Optional<Site> site;
    /// Details via an App object (Section 3.2.7) about the publisher’s app (i.e., non-browser applications).
    /// Only applicable and recommended for apps.
    core::Optional<App> app;
#if 0
    /// Details via a Device object (Section 3.2.11) about the user’s device to which the impression will be delivered.
    core::Optional<Device> device;
    /// Details via a User object (Section 3.2.13) about the human user of the device; the advertising audience.
    core::Optional<User> user;
#endif
    /// Indicator of test mode in which auctions are not billable, where 0 (false) = live mode, 1 (true) = test mode.
    core::Bool test = false;
    /// Auction type, where 1 = First Price, 2 = Second Price Plus.
    /// Exchange-specific auction types can be defined using values greater than 500.
    AuctionPrice at = AuctionPrice::SECOND_PRICE_PLUS;
    /// Maximum time in milliseconds to submit a bid to avoid timeout. This value is commonly communicated offline.
    core::Int tmax;
    /// Whitelist of buyer seats allowed to bid on this impression.
    /// Seat IDs must be communicated between bidders and the exchange a priori. Omission implies no seat restrictions.
    core::Vector<core::String> wseat;
    /// Flag to indicate if Exchange can verify that the impressions offered represent all of the impressions available
    /// in context (e.g., all on the web page, all video spots such as pre/mid/post roll) to support road-blocking.
    /// 0 = no or unknown, 1 = yes, the impressions offered represent all that are available.
    core::Bool allimps = false;
    /// Array of allowed currencies for bids on this bid request using ISO-4217 alpha codes.
    /// Recommended only if the exchange accepts multiple currencies.
    core::Vector<core::String> cur;
    /// Blocked advertiser categories using the IAB content categories. Refer to List 5.1.
    core::Vector<core::String> bcat;
    /// Block list of advertisers by their domains (e.g., “ford.com”).
    core::Vector<core::String> badv;
    /// A Regs object (Section 3.2.16) that specifies any industry, legal,
    /// or governmental regulations in force for this request.
    core::Optional<json::Document> regs;
    /// Unparseable fields get put here.
    json::Document unparseable;
};

}
