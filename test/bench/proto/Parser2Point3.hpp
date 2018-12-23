#pragma once

#include "Bench.hpp"

/// Parses banner.
void ParseBanner(benchmark::State& state);
/// Parses deal.
void ParseDeal(benchmark::State& state);
/// Parses pmp.
void ParsePmp(benchmark::State& state);
/// Parses impression.
void ParseImpression(benchmark::State& state);
/// Parses bid request.
void ParseBrandscreenBidRequest(benchmark::State& state);
