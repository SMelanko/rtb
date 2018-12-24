#include "data/OpenRtb2Point3.hpp"

#include <core/utils/StringAlgo.hpp>

namespace test::data
{

Core::String OpenRtb2Point3::GetBanner()
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
        "btype":[4],
        "battr":[14],
        "mimes":["image/jpg","image/png"],
        "expdir":[2,4],
        "api":[3]
    })";

    return Core::Utils::StringAlgo::RemoveWhitespace(str);
}

Core::String OpenRtb2Point3::GetDeal()
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

    return Core::Utils::StringAlgo::RemoveWhitespace(str);
}

Core::String OpenRtb2Point3::GetPmp()
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

    return Core::Utils::StringAlgo::RemoveWhitespace(str);
}

Core::String OpenRtb2Point3::GetImpression()
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

    return Core::Utils::StringAlgo::RemoveWhitespace(str);
}

Core::String OpenRtb2Point3::GetBrandscreenBidRequest()
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
        },
        "device":{
        },
        "user":{
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

    return Core::Utils::StringAlgo::RemoveWhitespace(str);
}

}
