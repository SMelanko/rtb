#pragma once

#include <core/Type.hpp>
#include <core/stl/String.hpp>

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
    explicit MimeType(const Core::String& type = "")
        : _type{ type }
    {
    }

public:
    Core::String _type;
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