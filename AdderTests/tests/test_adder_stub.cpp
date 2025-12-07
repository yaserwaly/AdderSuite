// AdderSuite/tests/test_adder_stub.cpp
#include <gtest/gtest.h>
#include "adder_factory.h"

TEST(AdderStub, Always42) {
    auto adder = AdderFactory::create(AdderType::Stub);
    EXPECT_EQ(adder->add(123, 456), 42);
    EXPECT_EQ(adder->add(-10, 9999), 42);
}
