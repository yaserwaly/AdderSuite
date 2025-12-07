// AdderSuite/benchmarks/bench_adder.cpp
#define BENCHMARK_STATIC_DEFINE
#include <benchmark/benchmark.h>
#include "adder_factory.h"

static void BM_AdderReal(benchmark::State& state) {
    auto adder = AdderFactory::create(AdderType::Real);
    int a = 123456, b = 654321;
    for (auto _ : state) {
        benchmark::DoNotOptimize(adder->add(a, b));
    }
}
BENCHMARK(BM_AdderReal);

static void BM_AdderStub(benchmark::State& state) {
    auto adder = AdderFactory::create(AdderType::Stub);
    int a = 1, b = 2;
    for (auto _ : state) {
        benchmark::DoNotOptimize(adder->add(a, b));
    }
}
BENCHMARK(BM_AdderStub);

BENCHMARK_MAIN();
