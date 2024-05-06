#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../11/11.hpp"

TEST(PrimesTest, first) {
    ASSERT_TRUE( 2 == NthPrime<1>::value);
}

TEST(PrimesTest, second) {
    ASSERT_TRUE( 3 == NthPrime<2>::value);
}

TEST(PrimesTest, third) {
    ASSERT_TRUE( 5 == NthPrime<3>::value);
}

TEST(PrimesTest, fourth) {
    ASSERT_TRUE(7 == NthPrime<4>::value);
}

TEST(PrimesTest, fifth) {
    ASSERT_TRUE( 11 == NthPrime<5>::value);
}

TEST(PrimesTest, sixth) {
    ASSERT_TRUE(13 == NthPrime<6>::value);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}