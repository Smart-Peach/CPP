#include "../09/09.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>


TEST(TreapTest, TestTemplateInt) {
    Treap<int> A;
    A.insert(5, 1);
    A.insert(17, 2);
    A.insert(99, 2);
    A.insert(2, 3);
    A.insert(24, 2);
    A.insert(13, 3);
    A.insert(42, 3);

    ASSERT_EQ(A.summa(1, 7), 5 + 24 + 42 + 13 + 99 + 2 + 17);
}

TEST(TreapTest, TestTemplateDouble) {
    Treap<double> A;
    A.insert(5.5, 1);
    A.insert(17.1, 2);
    A.insert(99.9, 2);

    ASSERT_EQ(A.summa(1,3), 5.5 + 17.1 + 99.9);
}

TEST(TreapTest, TestTemplateBool) {
    Treap<bool> A;
    A.insert(true, 1);
    A.insert(true, 2);
    A.insert(false, 2);

    ASSERT_EQ(A.summa(1,3), true);
}

TEST(TreapTest, TestTemplateString) {
    Treap<std::string> A;
    A.insert("abc", 1);
    A.insert("rrr", 2);
    A.insert("yyy", 2);

    ASSERT_EQ(A.summa(1,3), "abcyyyrrr");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
