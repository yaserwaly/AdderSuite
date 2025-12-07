// AdderSuite/tests/test_adder_real.cpp
#include <gtest/gtest.h>
#include "adder_factory.h"
#include "logger.h"
#include "error.h"
#include <cstdint>

TEST(AdderReal, Positive) {
    Logger::set_level(LogLevel::Error);
    auto adder = AdderFactory::create(AdderType::Real);
    EXPECT_EQ(adder->add(2, 3), 5);
}

TEST(AdderReal, Negative) {
    auto adder = AdderFactory::create(AdderType::Real);
    EXPECT_EQ(adder->add(-2, -3), -5);
}

TEST(AdderReal, OverflowThrows) {
    auto adder = AdderFactory::create(AdderType::Real);
    EXPECT_THROW(adder->add(INT32_MAX, 1), ArithmeticError);
}
