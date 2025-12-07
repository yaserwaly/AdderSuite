// AdderSuite/tests/test_adder_mock.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "iadder.h"

class MockAdder : public IAdder {
public:
    MOCK_METHOD(int, add, (int a, int b), (override));
};

using ::testing::Return;
using ::testing::_;

TEST(AdderMock, VerifyCallAndReturn) {
    MockAdder mock;
    EXPECT_CALL(mock, add(2, 3)).Times(1).WillOnce(Return(5));
    EXPECT_EQ(mock.add(2, 3), 5);
}

TEST(AdderMock, AnyParamsTwice) {
    MockAdder mock;
    EXPECT_CALL(mock, add(_, _)).Times(2).WillRepeatedly(Return(42));
    EXPECT_EQ(mock.add(10, 20), 42);
    EXPECT_EQ(mock.add(-1, -2), 42);
}
