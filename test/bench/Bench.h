#pragma once

#include <benchmark/benchmark.h>
namespace bench = benchmark;

#define BENCH(x) BENCHMARK(x)->Iterations(1'000'000)->Unit(bench::kNanosecond)
