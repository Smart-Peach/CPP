#include "../08/StringRW.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(StringRWTest, TestBasicFunctions) {
    // StringReaderWriter srw = StringReaderWriter();
    // ASSERT_TRUE(srw.is_source_open());
    // srw.close();
    // ASSERT_FALSE(srw.is_source_open());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}