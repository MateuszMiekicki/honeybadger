#include <calculator.hh>
#include <gtest/gtest.h>

TEST (calculator, add) {
    calculator cal;
    EXPECT_EQ (cal.add(4,5), 9);
    EXPECT_EQ (cal.add(-4,5), 1);
    EXPECT_EQ (cal.add(4,-5), -1);
}

TEST (calculator, div) {
    calculator cal;
    EXPECT_EQ (cal.div(10,5), 2);
    EXPECT_EQ (cal.div(11,5), 2);
    EXPECT_EQ (cal.div(9,3), 3);
    EXPECT_EQ (cal.div(9,0), -1);

}

TEST (calculator, mp) {
    calculator cal;
    EXPECT_EQ (cal.multiple(10,5), 50);
    EXPECT_EQ (cal.multiple(11,5), 55);
    EXPECT_EQ (cal.multiple(9,3), 27);
    EXPECT_EQ (cal.multiple(9,0), 0);
    EXPECT_EQ (cal.multiple(0,0), 0);
    EXPECT_EQ (cal.multiple(0,9), 0);
    EXPECT_EQ (cal.multiple(-1,9), -9);
    EXPECT_EQ (cal.multiple(9,-1), -9);
    EXPECT_EQ (cal.multiple(-9,-1), 9);
}