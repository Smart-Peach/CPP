#include "../10/10.cpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>


TEST(LimitTest, Testfirst) {
    Something smth1;
    Something smth2;
    Something smth3;

    EXPECT_THROW(Something smth4, std::out_of_range);
}

TEST(LimitTest, Testsecond) {
    Everything evrth1;
    Everything evrth2;
    Everything evrth3;
    Everything evrth4;
    Everything evrth5;

    EXPECT_THROW(Everything evrth6, std::out_of_range);
}

TEST(LimitTest, TestWithDeletion) {
    Something* smth1 = new Something();

    delete smth1;

    Something smth2;
    Something smth3;
    Something smth4;

    EXPECT_THROW(Something smth5, std::out_of_range);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
