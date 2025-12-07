// AdderSuite/tests/test_c_api.cpp
#include <gtest/gtest.h>
#include "c_api.h"
#include <cstdint>

TEST(CAPI, AddNumbers) {
    EXPECT_EQ(add_numbers(7, 8), 15);
}

TEST(CAPI, AddOverflowHandled) {
    EXPECT_EQ(add_numbers(INT32_MAX, 1), 0);
}
