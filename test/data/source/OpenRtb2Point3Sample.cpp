#include "test/data/OpenRtb2Point3Sample.hpp"

#include <core/utils/StrAlgo.hpp>

namespace test::data
{

core::String OpenRtb2Point3Sample::GetBanner()
{
    auto str = R"({
        "h":250,
        "w":300,
        "wmax":640,
        "hmax":320,
        "wmin":240,
        "hmin":200,
        "id":"p7mwtup3aep7c0io",
        "pos":0,
        "topframe":0,
        "btype":[
            4
        ],
        "battr":[
            14
        ],
        "mimes":[
            "image/jpg",
            "image/png"
        ],
        "expdir":[
            2,
            4
        ],
        "api":[
            3
        ]
    })";

    return core::StrAlgo::RemoveWhitespace(str);
}

core::String OpenRtb2Point3Sample::GetVideo()
{
    auto str = R"({
        "w":640,
        "h":480,
        "pos":1,
        "startdelay":0,
        "minduration":5,
        "maxduration":30,
        "maxextended":30,
        "minbitrate":300,
        "maxbitrate":1500,
        "api":[
            1,
            2
        ],
        "protocols":[
            2,
            3
        ],
        "mimes":[
            "video/x-flv",
            "video/mp4",
            "application/x-shockwave-flash",
            "application/javascript"
        ],
        "linearity":1,
        "boxingallowed":1,
        "playbackmethod":[
            1,
            3
        ],
        "delivery":[
            2
        ],
        "battr":[
            13,
            14
        ],
        "companionad":[
            {
                "id":"1234567893-1",
                "w":300,
                "h":250,
                "pos":1,
                "battr":[
                    13,
                    14
                ],
                "expdir":[
                    2,
                    4
                ]
            },
            {
                "id":"1234567893-2",
                "w":728,
                "h":90,
                "pos":1,
                "battr":[
                    13,
                    14
                ]
            }
        ],
        "companiontype":[
            1,
            2
        ]
    })";

    return core::StrAlgo::RemoveWhitespace(str);
}

core::String OpenRtb2Point3Sample::GetNative()
{
    auto str = R"({
        "request":"...Native_spec_request_as_an_encoded_string...",
        "ver":"1.0",
        "api":[
            3
        ],
        "battr":[
            13,
            14
        ]
    })";

    return core::StrAlgo::RemoveWhitespace(str);
}

core::String OpenRtb2Point3Sample::GetApp()
{
    auto str = R"({
        "id":"agltb3B1Yi1pbmNyDAsSA0FwcBiJkfIUDA",
        "name":"Yahoo_Weather",
        "cat":[
            "weather",
            "IAB15",
            "IAB15-10"
        ],
        "ver":"1.0.2",
        "bundle":"628677149",
        "publisher":{
            "id":"agltb3B1Yi1pbmNyDAsSA0FwcBiJkfTUCV",
            "name":"yahoo",
            "domain":"www.yahoo.com"
        },
        "storeurl":"https://itunes.apple.com/id628677149"
    })";

    return core::StrAlgo::RemoveWhitespace(str);
}

core::String OpenRtb2Point3Sample::GetSite()
{
    auto str = R"({
        "id":"1345135123",
        "name":"Site_ABCD",
        "domain":"siteabcd.com",
        "cat":[
            "IAB2-1",
            "IAB2-2"
        ],
        "page":"http://siteabcd.com/page.htm",
        "ref":"http://referringsite.com/referringpage.htm",
        "privacypolicy":true,
        "publisher":{
            "id":"pub12345",
            "name":"Publisher_A"
        },
        "content":{
            "cat":[
                "IAB2-2"
            ],
            "episode":23,
            "id":"1234567",
            "keywords":[
                "keyword_a",
                "keyword_b",
                "keyword_c"
            ],
            "season":"2",
            "series":"All_About_Cars",
            "title":"Car_Show"
        }
    })";

    return core::StrAlgo::RemoveWhitespace(str);
}

core::String OpenRtb2Point3Sample::GetGeo()
{
    auto str = R"({
        "country":"USA",
        "lat":35.012345,
        "lon":-115.12345,
        "city":"Los Angeles",
        "metro":"803",
        "region":"CA",
        "zip":"90049"
    })";

    return str;
}

core::String OpenRtb2Point3Sample::GetDevice()
{
    auto str = R"({
        "dnt": 0,
        "ip":"64.124.253.1",
        "ua":"Mozilla/5.0 (Mac; U; Intel Mac OS X 10.6; en-US; rv:1.9.2.16) Gecko/20140420 Firefox/3.6.16",
        "flashver":"10.1",
        "geo":{
            "country":"USA",
            "lat":35.012345,
            "lon":-115.12345,
            "city":"Los Angeles",
            "metro":"803",
            "region":"CA",
            "zip":"90049"
        },
        "dpidsha1":"AA000DFE74168477C70D291f574D344790E0BB11",
        "dpidmd5":"AA003EABFB29E6F759F3BDAB34E50BB11",
        "carrier":"310-410",
        "language":"en",
        "make":"Apple",
        "model":"iPhone",
        "os":"iOS",
        "osv":"6.1",
        "js":1,
        "connectiontype":3,
        "devicetype":1
    })";

    return str;
}

core::String OpenRtb2Point3Sample::GetDeal()
{
    auto str = R"({
        "id":"1452f.eadb4.7aaa",
        "bidfloor":5.3,
        "at":1,
        "wseats":[],
        "ext":{
            "priority":1,
            "wadvs":[]
        }
    })";

    return core::StrAlgo::RemoveWhitespace(str);
}

core::String OpenRtb2Point3Sample::GetPmp()
{
    auto str = R"({
        "private_auction":1,
        "deals":[
            {
                "id":"DX-1985-010A",
                "bidfloor":2.5,
                "at":2
            }
        ]
    })";

    return core::StrAlgo::RemoveWhitespace(str);
}

core::String OpenRtb2Point3Sample::GetImpression()
{
    auto str = R"({
        "id":"1",
        "banner":{
            "w":728,
            "h":90,
            "pos":1,
            "btype":[4],
            "battr":[14],
            "api":[3]
        },
        "instl":0,
        "tagid":"agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw",
        "bidfloor":0.5
    })";

    return core::StrAlgo::RemoveWhitespace(str);
}

core::String OpenRtb2Point3Sample::GetBrandscreenBidRequest()
{
    // https://github.com/openrtb/examples/blob/master/brandscreen/example-request-mobile.json
    auto str = R"({
        "id":"IxexyLDIIk",
        "imp":[
            {
                "id":"1",
                "banner":{
                    "w":728,
                    "h":90,
                    "pos":1,
                    "btype":[
                        4
                    ],
                    "battr":[
                        14
                    ],
                    "api":[
                        3
                    ]
                },
                "instl":0,
                "tagid":"agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw",
                "bidfloor":0.5
            }
        ],
        "app":{
            "id":"agltb3B1Yi1pbmNyDAsSA0FwcBiJkfIUDA",
            "name":"Yahoo_Weather",
            "cat":[
                "weather",
                "IAB15",
                "IAB15-10"
            ],
            "ver":"1.0.2",
            "bundle":"628677149",
            "publisher":{
                "id":"agltb3B1Yi1pbmNyDAsSA0FwcBiJkfTUCV",
                "name":"yahoo",
                "domain":"www.yahoo.com"
            },
            "storeurl":"https://itunes.apple.com/id628677149"
        },
        "device":{
            "dnt":0,
            "ua":"Mozilla/5.0 (iPhone; CPU iPhone OS 6_1 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3",
            "ip":"123.145.167.189",
            "geo":{
                "country":"USA",
                "lat":35.012345,
                "lon":-115.12345,
                "city":"Los Angeles",
                "metro":"803",
                "region":"CA",
                "zip":"90049"
            },
            "dpidsha1":"AA000DFE74168477C70D291f574D344790E0BB11",
            "dpidmd5":"AA003EABFB29E6F759F3BDAB34E50BB11",
            "carrier":"310-410",
            "language":"en",
            "make":"Apple",
            "model":"iPhone",
            "os":"iOS",
            "osv":"6.1",
            "js":1,
            "connectiontype":3,
            "devicetype":1
        },
        "user":{
            "id":"ffffffd5135596709273b3a1a07e466ea2bf4fff",
            "yob":1984,
            "gender":"M"
        },
        "at":2,
        "bcat":[
            "IAB25",
            "IAB7-39",
            "IAB8-18",
            "IAB8-5",
            "IAB9-9"
        ],
        "badv":[
            "apple.com",
            "go-text.me",
            "heywire.com"
        ]
    })";

    return str;
}

core::String OpenRtb2Point3Sample::GetBrandscreenBidRequestBench()
{
    return core::StrAlgo::RemoveWhitespace(OpenRtb2Point3Sample::GetBrandscreenBidRequest());
}

}
