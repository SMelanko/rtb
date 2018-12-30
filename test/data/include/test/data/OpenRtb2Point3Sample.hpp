#pragma once

#include <core/stl/String.hpp>

namespace test::data
{

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

}
