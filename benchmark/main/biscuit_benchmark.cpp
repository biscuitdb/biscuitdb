#include "benchmark/benchmark.h"
#include "main/biscuit.h"

// NOLINTNEXTLINE
static void BenchmarkRadd(benchmark::State &state) {
  // NOLINTNEXTLINE
  for (auto _ : state) {
    biscuit::Radd(0, 1000000);
  }
}

BENCHMARK(BenchmarkRadd);
