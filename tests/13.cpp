#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include "../13/13.hpp"


TEST(GetFirstIndex, NotFound) {
  auto actual = getIndexOfTheFirstMatch([](auto a){ return a % 2 == 0; }, 7,3,1,1,1,5,9);
  ASSERT_TRUE(actual == -1);
}

TEST(GetFirstIndex, Found) {
  auto actual = getIndexOfTheFirstMatch([](auto a){ return a % 2 == 0; }, 1,3,6,4,10,8,6);
  ASSERT_TRUE(actual == 2);
}

TEST(GetFirstIndex, Found1) {

  auto actual = getIndexOfTheFirstMatch([](auto a){ return a % 2 != 0; }, 6,2,6,4,1,8,6);
  ASSERT_TRUE(actual == 4);
}

TEST(GetFirstIndex, NotFound1) {

  auto actual = getIndexOfTheFirstMatch([](auto a){ return a % 2 != 0; }, 6,2,6,4,10,8,6);
  ASSERT_TRUE(actual == -1);
}


class MyInt {
public:
  int val;

  MyInt(int val) : val(val) {}
  MyInt(const MyInt& other) : val(other.val) {
    std::cout << "COPY CTOR!!!!!!!!!" << std::endl;
  }
  MyInt(MyInt&& other) : val(other.val) {
    std::cout << "Move ctor is called!" << std::endl;
  }

  MyInt operator+(const MyInt& other) {
    return MyInt(val + other.val);
  } 
};

TEST(GetFirstIndex, StructPlusOpTest) {
// class with copy & move ctrs --> pass it as rvals (std::move / overloaded op(+)) --> lambda func should take arg as value
// 1. try to call lambda directly => move ctr
// 2. try to call getIndexOfF... => should be the same!
  MyInt i = MyInt(5);
  auto lambda = [](MyInt a){ return a.val % 2 != 0; };
  auto actual = getIndexOfTheFirstMatch(lambda, MyInt(6)+MyInt(4), MyInt(6)+MyInt(2), MyInt(3)+MyInt(2), i);
  lambda(i);

  ASSERT_TRUE(actual == 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}