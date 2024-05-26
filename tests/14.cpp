#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include "../14/14.hpp"


TEST(AllocatorTest, First) {
    int i = 0;
    double d = 9.0;
    char c = 'A';

    constexpr int size = sizeof(int) + sizeof(double) + sizeof(char);
    char buff[size];
    allocate<size>(buff, i, d, c);

    int* i_ptr =(int*) (buff);
    double* d_ptr = (double*) (buff + sizeof(int));
    char* c_ptr = (char*) (buff + sizeof(int) + sizeof(double));

    assert(*i_ptr == 0); 
    assert(*d_ptr == 9.0);  
    assert(*c_ptr == 'A');
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}