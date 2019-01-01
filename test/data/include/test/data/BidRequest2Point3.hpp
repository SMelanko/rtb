#pragma once

#include <core/stl/String.hpp>

namespace test::data
{

/**
 * \brief OpenRTB 2.3 bid request samples.
 */

class OpenRtb2Point3Sample
{
public:
    static core::String GetBanner();
    static core::String GetVideo();
    static core::String GetNative();
    static core::String GetApp();
    static core::String GetSite();
    static core::String GetGeo();
    static core::String GetDevice();
    static core::String GetUser();
    static core::String GetDeal();
    static core::String GetPmp();
    static core::String GetImpression();
    static core::String GetBrandscreenBidRequest();
    static core::String GetBrandscreenBidRequestBench();
};

/**
 * \brief Bid requests from the OpenRTB 2.3 specification.
 * \link
 * https://www.iab.com/wp-content/uploads/2015/06/OpenRTB-API-Specification-Version-2-3.pdf
 * \endlink
 */

class OpenRtb2Point3Spec
{
public:
    /**
     * \brief Returns an example of Simple Banner bid request.
     *
     * Following is a basic example of a bid request for a banner ad.
     * Some optional parameters are included in this example.
     */
    static core::String GetSimpleBanner();
    /**
     * \brief Returns an example of Expandable Creative bid request.
     *
     * This example builds the first and adds parameters to describe support for
     * an expandable creative, and passes data about the user from “Data Provider 1”.
     */
    static core::String GetExpandableCreative();
    /**
     * \brief Returns an example of Mobile bid request.
     *
     * This example uses a device object to reflect a mobile device, and an app object
     * to reflect a request from a mobile application.
     */
    static core::String GetMobile();
    /**
     * \brief Returns an example of Video bid request.
     *
     * The following example illustrates a bid request for a video impression with
     * two companion ad slots (1 expandable). Additionally, the video content itself
     * is described in the "content" object. A few notes about specific fields in the example:\n
     * - protocol: Only VAST 2.0 and 3.0 are allowed.
     *   \note Note that a wrapper response is not allowed in this example.
     * - sequence: It is not explicitly included so the default of “1” should be assumed.
     * - battr: User interactive and alert type ads (value “13” and “14”, respectively)
     *   are explicitly being blocked for both the video and its companions.
     * - pos: Indicates this opportunity is “above the fold”.
     * - api: Indicates that VPAID 1.0 containers are explicitly supported. As such,
     *   the mime types supported for VPAID are only “application/x-shockwave-flash”
     *   and “application/javascript”.
     *   \note Note that there is an implicit restriction as to which protocol is allowed in
     *   which mime type. JavaScript support was not specified until VPAID 2.0, while
     *   Flash supports both VPAID 1.0 and 2.0.
     * - companiontype: Indicates only static or HTML resources are allowed.
     */
    static core::String GetVideo();
    /**
     * \brief Returns an example of PMP with a direct deal bid request.
     *
     * Following is a basic example of a bid request for a banner ad with a direct deal.
     * Some optional parameters are included in this example.
     */
    static core::String GetPmpWithDirectDeal();
    /**
     * \brief Returns an example of Native bid request.
     *
     * Following is a basic example of a bid request for a Native ad; similar otherwise to
     * the simple banner examplein Section 6.3.1. Notice the request attribute in the Native object
     * contains an encoded string of a native ad request that conforms to the Native Specification,
     * specifically version 1.0 as indicated by the ver attribute.
     */
    static core::String GetNativeAd();
};

}
