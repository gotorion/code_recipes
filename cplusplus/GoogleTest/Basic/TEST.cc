#include <gmock/gmock.h>
#include <gtest/gtest.h>

int add(int a, int b) { return a + b; }

bool isNegetive(int num) {
    return num < 0;
}

TEST(testAdd, Positive) {
    EXPECT_EQ(3, add(1, 2)) << "FAILED: EXPECT 3, but given 3";
}

TEST(testAdd, Negetive) {
    EXPECT_EQ(-3, add(-1, -2));
}

TEST(testAdd, Zero) {
    EXPECT_EQ(-1, add(0, 0)) << "FAILED: EXPECT 0, but given -1";
}

int main(int argc, char **argv) {
    ::printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}