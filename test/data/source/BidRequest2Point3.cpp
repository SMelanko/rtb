#include "test/data/BidRequest2Point3.hpp"

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

    return core::StrAlgo::RemoveWhitespaces(str);
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

    return core::StrAlgo::RemoveWhitespaces(str);
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

    return core::StrAlgo::RemoveWhitespaces(str);
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

    return core::StrAlgo::RemoveWhitespaces(str);
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
            "keywords":"keyword_a,keyword_b,keyword_c",
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

core::String OpenRtb2Point3Sample::GetUser()
{
    auto str = R"({
        "id":"456789876567897654678987656789",
        "buyerid":"545678765467876567898765678987654",
        "data":[
            {
                "id":"6",
                "name":"Data_Provider_1",
                "segment":[
                    {
                        "id":"12341318394918",
                        "name":"auto_intenders"
                    },
                    {
                        "id":"1234131839491234",
                        "name":"auto_enthusiasts"
                    }
                ]
            }
        ]
    })";

    return core::StrAlgo::RemoveWhitespace(str);
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

core::String OpenRtb2Point3Spec::GetSimpleBanner()
{
    auto str = R"({
        "id":"80ce30c53c16e6ede735f123ef6e32361bfc7b22",
        "at":1,
        "cur":[
            "USD"
        ],
        "imp":[
            {
                "id":"1",
                "bidfloor":0.03,
                "banner":{
                    "w":300,
                    "h":250,
                    "pos":0
                }
            }
        ],
        "site":{
            "id":"102855",
            "cat":[
                "IAB3-1"
            ],
            "domain":"www.foobar.com",
            "page":"http://www.foobar.com/1234.html",
            "publisher":{
                "id":"8953",
                "name":"foobar.com",
                "cat":[
                    "IAB3-1"
                ],
                "domain":"foobar.com"
            }
        },
        "device":{
            "ua":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/537.13 (KHTML, like Gecko) Version/5.1.7 Safari/534.57.2",
            "ip":"123.145.167.10"
        },
        "user":{
            "id":"55816b39711f9b5acf3b90e313ed29e51665623f"
        }
    })";

    return str;
}

core::String OpenRtb2Point3Spec::GetExpandableCreative()
{
    auto str = R"({
        "id":"123456789316e6ede735f123ef6e32361bfc7b22",
        "at":2,
        "cur":[
            "USD"
        ],
        "imp":[
            {
                "id":"1",
                "bidfloor":0.003,
                "iframebuster":[
                    "vendor1.com",
                    "vendor2.com"
                ],
                "banner":{
                    "w":300,
                    "h":250,
                    "pos":0,
                    "battr":[
                        13
                    ],
                    "expdir":[
                        2,
                        4
                    ]
                }
            }
        ],
        "site":{
            "id":"102855",
            "cat":[
                "IAB3-1"
            ],
            "domain":"www.foobar.com",
            "page":"http://www.foobar.com/1234.html",
            "publisher":{
                "id":"8953",
                "name":"foobar.com",
                "cat":[
                    "IAB3-1"
                ],
                "domain":"foobar.com"
            }
        },
        "device":{
            "ua":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/537.13 (KHTML, like Gecko) Version/5.1.7 Safari/534.57.2",
            "ip":"123.145.167.10"
        },
        "user":{
            "id":"55816b39711f9b5acf3b90e313ed29e51665623f",
            "buyerid":"545678765467876567898765678987654",
            "data":[
                {
                    "id":"6",
                    "name":"Data Provider 1",
                    "segment":[
                        {
                            "id":"12341318394918",
                            "name":"auto intenders"
                        },
                        {
                            "id":"1234131839491234",
                            "name":"auto enthusiasts"
                        },
                        {
                            "id":"23423424",
                            "name":"data-provider1-age",
                            "value":"30-40"
                        }
                    ]
                }
            ]
        }
    })";

    return str;
}

core::String OpenRtb2Point3Spec::GetMobile()
{
    auto str = R"({
        "id":"IxexyLDIIk",
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
        ],
        "imp":[
            {
                "id":"1",
                "bidfloor":0.5,
                "instl":0,
                "tagid":"agltb3B1Yi1pbmNyDQsSBFNpdGUY7fD0FAw",
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
                }
            }
        ],
        "app":{
            "id":"agltb3B1Yi1pbmNyDAsSA0FwcBiJkfIUDA",
            "name":"Yahoo Weather",
            "cat":[
                "IAB15",
                "IAB15-10"
            ],
            "ver":"1.0.2",
            "bundle":"com.yahoo.wxapp",
            "storeurl":"https://itunes.apple.com/id628677149",
            "publisher":{
                "id":"agltb3B1Yi1pbmNyDAsSA0FwcBiJkfTUCV",
                "name":"yahoo",
                "domain":"www.yahoo.com"
            }
        },
        "device":{
            "dnt":0,
            "ua":"Mozilla/5.0 (iPhone; CPU iPhone OS 6_1 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3",
            "ip":"123.145.167.189",
            "ifa":"AA000DFE74168477C70D291f574D344790E0BB11",
            "carrier":"VERIZON",
            "language":"en",
            "make":"Apple",
            "model":"iPhone",
            "os":"iOS",
            "osv":"6.1",
            "js":1,
            "connectiontype":3,
            "devicetype":1,
            "geo":{
                "lat":35.012345,
                "lon":-115.12345,
                "country":"USA",
                "metro":"803",
                "region":"CA",
                "city":"Los Angeles",
                "zip":"90049"
            }
        },
        "user":{
            "id":"ffffffd5135596709273b3a1a07e466ea2bf4fff",
            "yob":1984,
            "gender":"M"
        }
    })";

    return str;
}

core::String OpenRtb2Point3Spec::GetVideo()
{
    auto str = R"({
        "id":"1234567893",
        "at":2,
        "tmax":120,
        "imp":[
            {
                "id":"1",
                "bidfloor":0.03,
                "video":{
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
                }
            }
        ],
        "site":{
            "id":"1345135123",
            "name":"Site ABCD",
            "domain":"siteabcd.com",
            "cat":[
                "IAB2-1",
                "IAB2-2"
            ],
            "page":"http://siteabcd.com/page.htm",
            "ref":"http://referringsite.com/referringpage.htm",
            "privacypolicy":1,
            "publisher":{
                "id":"pub12345",
                "name":"Publisher A"
            },
            "content":{
                "id":"1234567",
                "series":"All About Cars",
                "season":"2",
                "episode":23,
                "title":"Car Show",
                "cat":[
                    "IAB2-2"
                ],
                "keywords":"keyword-a,keyword-b,keyword-c"
            }
        },
        "device":{
            "ip":"64.124.253.1",
            "ua":"Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10.6; en-US; rv:1.9.2.16) Gecko/20110319 Firefox/3.6.16",
            "os":"OS X",
            "flashver":"10.1",
            "js":1
        },
        "user":{
            "id":"456789876567897654678987656789",
            "buyeruid":"545678765467876567898765678987654",
            "data":[
                {
                    "id":"6",
                    "name":"Data Provider 1",
                    "segment":[
                        {
                            "id":"12341318394918",
                            "name":"auto intenders"
                        },
                        {
                            "id":"1234131839491234",
                            "name":"auto enthusiasts"
                        }
                    ]
                }
            ]
        }
    })";

    return str;
}

core::String OpenRtb2Point3Spec::GetPmpWithDirectDeal()
{
    auto str = R"({
    })";

    return str;
}

core::String OpenRtb2Point3Spec::GetNativeAd()
{
    auto str = R"({
    })";

    return str;
}

}
