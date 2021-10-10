#include <gmock/gmock.h>
#include <gtest/gtest.h>
using ::testing::AtLeast;

class ClassForMocking
{
public:
    int add(int a, int b) const
    {
        return a + b;
    }
};

class Mock : public ClassForMocking
{
public:
    MOCK_METHOD(int, add, (int a, int b), (const override));
};

TEST(CTest_test, test)
{
    using ::testing::NiceMock;
    using ::testing::Return;
    NiceMock<Mock> mock;
    EXPECT_CALL(mock, add(2, 4))
        .Times(1)
        .WillOnce(Return(6));
    ASSERT_EQ(mock.add(2, 4), 6);
}

TEST(CTest_test, test2)
{
    EXPECT_TRUE(true);
}

TEST(CTest_test, test3)
{
    EXPECT_EQ(42, 42);
}

TEST(CTest_test, test4)
{
    ASSERT_FLOAT_EQ(3.14, 3.14);
}