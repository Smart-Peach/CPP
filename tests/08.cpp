#include "../08/StringRW.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(StringReaderWriterTest, TestOpen) {
    StringReaderWriter srw = StringReaderWriter("abc");
    ASSERT_TRUE(srw.is_source_open());
    srw.close();
    ASSERT_FALSE(srw.is_source_open());
}

TEST(StringReaderWriterTest, TestWriteChar) {
    StringReaderWriter srw = StringReaderWriter("abc");
    srw.write_char('f');
    ASSERT_EQ("abcf", srw.get_source());
}

TEST(StringReaderWriterTest, TestReadChar) {
    StringReaderWriter srw = StringReaderWriter("abc");
    ASSERT_EQ('a', srw.read_char());
    ASSERT_EQ('b', srw.read_char());
    ASSERT_EQ('c', srw.read_char());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}