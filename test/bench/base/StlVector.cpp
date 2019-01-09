#include "Bench.hpp"

#include <base/stl/Vector.hpp>

#include <boost/pool/pool_alloc.hpp>

static constexpr size_t Size = 1000;

void PushBackIntStlAllocator(benchmark::State& state)
{
    for (auto _ : state) {
        base::Vector<int> v;
        v.reserve(Size);
        for (size_t i = 0; i < Size; ++i) {
            v.push_back(i);
        }
    }
}
BENCH(PushBackIntStlAllocator);

void PushBackIntBoostPoolAllocator(benchmark::State& state)
{
    for (auto _ : state) {
        std::vector<int, boost::pool_allocator<int>> v;
        v.reserve(Size);
        for (size_t i = 0; i < Size; ++i) {
            v.push_back(i);
        }
    }
}
BENCH(PushBackIntBoostPoolAllocator);

#if 0
void PushBackStrStlAllocator(benchmark::State& state)
{
    for (auto _ : state) {
        std::vector<std::string, boost::pool_allocator<std::string>> v;
        v.reserve(Size);
        for (size_t i = 0; i < Size; ++i) {
            v.push_back("BXemaQJJz8qivwzuLmq3HphsIYVD7plzJH1vDxwm6PDA8yUFHJvuxO1RVhuFdE2T");
        }
    }
}
BENCH(PushBackStrStlAllocator);

void PushBackStrBoostPoolAllocator(benchmark::State& state)
{
    for (auto _ : state) {
        std::vector<std::string, boost::pool_allocator<std::string>> v;
        v.reserve(Size);
        for (size_t i = 0; i < Size; ++i) {
            v.push_back("BXemaQJJz8qivwzuLmq3HphsIYVD7plzJH1vDxwm6PDA8yUFHJvuxO1RVhuFdE2T");
        }
    }
}
BENCH(PushBackStrBoostPoolAllocator);
#endif
