// AdderSuite/src/domain/adder.cpp
#include "adder.h"
#include "logger.h"
#include "error.h"
#include <cstdint>

int Adder::add(int a, int b) {
    long long sum = static_cast<long long>(a) + static_cast<long long>(b);
    if (sum > INT32_MAX || sum < INT32_MIN) {
        Logger::error("Overflow detected in Adder::add");
        throw ArithmeticError("Overflow in addition");
    }
    //Logger::info("Adder::add called");
#ifdef _DEBUG
// هذا السطر يطبع فقط في وضع Debug
    Logger::info("Adder::add called");
#endif
    return static_cast<int>(sum);
}

//AdderBenchmarks.exe --benchmark_min_time=1 --benchmark_repetitions=5 --benchmark_display_aggregates_only=true
//AdderBenchmarks.exe --benchmark_min_time=1s --benchmark_repetitions=5 --benchmark_display_aggregates_only=true

