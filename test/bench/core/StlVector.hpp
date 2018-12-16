#pragma once

#include "Bench.hpp"

/// Benchmarks std::vector::push_back(int) with STL allocator.
void PushBackIntStlAllocator(benchmark::State& state);
/// Benchmarks std::vector::push_back(int) with boost::pool_allocator.
void PushBackIntBoostPoolAllocator(benchmark::State& state);
/// Benchmarks std::vector::push_back(std::string) with STL allocator.
void PushBackStrStlAllocator(benchmark::State& state);
/// Benchmarks std::vector::push_back(std::string) with boost::pool_allocator.
void PushBackStrBoostPoolAllocator(benchmark::State& state);
