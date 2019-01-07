#pragma once

#include <benchmark/benchmark.h>
namespace bench = benchmark;

#define BENCH(x) BENCHMARK(x)->Iterations(100'000)->Unit(bench::kNanosecond)
